# C / C++ 学习与练习

这个仓库用于保存 C / C++ 练习、算法教程和数据结构学习资料。完整资料索引见 [文档目录](docs/README.md)。

## 目录

- `practice/`：C / C++ 练习源码，每个文件通常是一个独立程序。
- `docs/README.md`：文档与学习资料索引。
- `docs/tutorials/`：算法、结构体、Flood Fill、角谷猜想的交互 HTML 教程，浏览器打开即可。
- `docs/data-structures/`：数据结构的 XMind 导图、交互 HTML、课程目录与预览图。
- `docs/g++-setup.md`：本机编译器的安装与排障记录。
- `build/`：编译生成的程序和临时产物，已被 Git 忽略。
- `.vscode/`：本地编辑器设置，已被 Git 忽略。

## 常用入口

- [数据结构交互导图](docs/data-structures/data-structures-mindmap.html)
- [数据结构 XMind 导图](docs/data-structures/data-structures-mindmap.xmind)
- [算法与 C++ 交互教程索引](docs/README.md#算法与-c-交互教程)
- [编译器安装与排障](docs/g++-setup.md)

## 编译与运行

在项目根目录打开终端。一次编译一个练习文件，不要把多个包含 `main` 的文件一起编译。

PowerShell（使用本机已配置的 LLVM-MinGW）：

```powershell
New-Item -ItemType Directory -Path build -Force | Out-Null
& 'D:\mingw64\bin\g++.exe' practice/hello.cpp -o build/hello.exe
if ($LASTEXITCODE -eq 0) { & .\build\hello.exe }
```

Git Bash：

```bash
export PATH="/d/mingw64/bin:$PATH"
mkdir -p build
g++ practice/hello.cpp -o build/hello.exe && ./build/hello.exe
```

练习其他文件时，把 `hello` 换成对应文件名。`build/` 不会提交到 Git，重新获取项目后按上面的命令创建即可。

## 浏览器预览

HTML 教程可以直接离线打开。在 GitHub 上查看时，需要先下载 HTML 文件再用浏览器打开。

如果已安装 Python，也可以在项目根目录启动本地静态服务器：

```bash
python -m http.server 8765 --bind 127.0.0.1
```

随后打开数据结构导图：

```text
http://127.0.0.1:8765/docs/data-structures/data-structures-mindmap.html
```

## 新增资料的约定

练习源码放在 `practice/`；交互教程放在 `docs/tutorials/`；数据结构相关资料放在 `docs/data-structures/`。新增文档后更新 [文档目录](docs/README.md)，编译结果统一输出到 `build/`。
