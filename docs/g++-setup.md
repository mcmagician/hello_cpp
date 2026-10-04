# 修复 Git Bash 里 `g++` 不可用

当前目录约定：以下日常编译命令在项目根目录执行，源码位于 `practice/`，编译结果放在 `build/`。前面的故障现象保留了当时的命令。

在 Windows 的 Git Bash 里执行 `g++ pointer.cpp` 时，先后遇到两类问题。下面是原因和最终可用的做法。

## 现象

```bash
$ g++ pointer.cpp -o pointer.exe
bash: g++: command not found
```

加上 `PATH` 之后，命令能找到了，但还是立刻失败，**没有任何报错**，退出码是 `1`，也不生成 `pointer.exe`。

## 原因 1：机器上本来没有编译器

Git Bash 提示符里的 `MINGW64` **不是** MinGW 编译器。那只是 Git for Windows 自带的运行环境，里面没有 `g++`。

当时系统里也没有 Visual Studio、MSYS2、LLVM 等其它 C++ 工具链，所以 `g++` 会直接报 `command not found`。

## 原因 2：第一套 GCC 能启动，但一编译就崩

用 winget 装过 WinLibs 的 MinGW-w64 GCC 16.1.0，并把工具链拷到 `D:\mingw64`，让当前终端能找到 `g++`：

```bash
export PATH="/d/mingw64/bin:$PATH"
```

`g++ --version` 正常，但真正编译时会去调前端 `cc1plus.exe`。这个进程会**静默退出**，所以看起来像“命令跑完了、什么也没说、但失败了”。

因此 WinLibs 这套 GCC 16 在这台机器上不能用，不能靠它编译。

## 真正有效的修复

改用 **LLVM-MinGW**。它提供的 `g++` 其实是 Clang 的包装，不走坏掉的 `cc1plus`。

1. 安装（winget 已执行过，不必再装一遍）：

   ```powershell
   winget install --id MartinStorsjo.LLVM-MinGW.UCRT --accept-package-agreements --accept-source-agreements
   ```

2. 把工具链放到短路径 `D:\mingw64`（覆盖掉之前坏掉的 GCC），这样原来的 `PATH` 不用改：

   ```text
   D:\mingw64\bin\g++.exe
   ```

3. 验证：

   ```bash
   export PATH="/d/mingw64/bin:$PATH"
   g++ --version
   mkdir -p build
   g++ practice/pointer.cpp -o build/pointer.exe && ./build/pointer.exe
   ```

   `g++ --version` 应显示 `clang version ...`。编译成功、能跑起来，才算修好。

## 平时怎么编译

每次打开 **新的** Git Bash，如果仍然提示找不到 `g++`，先加 PATH 再编译：

```bash
export PATH="/d/mingw64/bin:$PATH"
mkdir -p build
g++ practice/pointer.cpp -o build/pointer.exe && ./build/pointer.exe
```

新开的终端一般会带上 winget 写入的用户 PATH。若 `g++` 又变成坏掉的旧 GCC（`g++ --version` 显示 `gcc version 16.1.0` 且编译无报错失败），用上面这行把 `D:\mingw64\bin` 放到 PATH **最前面**。

## 不要和这些搞混

| 看到的东西 | 实际含义 |
|---|---|
| 提示符里的 `MINGW64` | 只是 Git Bash 环境，不等于已安装 `g++` |
| `g++: command not found` | PATH 里没有编译器 |
| `g++` 无输出、退出码 1、没有 `.exe` | 编译器前端崩溃（旧 GCC 16） |
| `g++ --version` 显示 clang | 当前用的是能工作的 LLVM-MinGW |
