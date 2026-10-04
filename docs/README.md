# 文档与学习资料

[返回项目首页](../README.md)

## 数据结构

建议先看交互导图中的“线性表”，理解逻辑关系与存储实现，再逐步学习栈、队列、树、图，以及查找和排序。

- [交互思维导图](data-structures/data-structures-mindmap.html)：支持搜索、展开收起、缩放、名词解释，以及顺序表和链表的插入演示。单文件 HTML，可离线打开。
- [XMind 思维导图](data-structures/data-structures-mindmap.xmind)：用 XMind 打开并编辑。包含知识总览、线性表入门、老师的合集目录三张图，保留已在客户端保存的彩虹色主题。
- [课程目录数据](data-structures/data-structures-course.json)：视频标题、作者、合集分组及 68 节课程的视频编号。
- [交互导图预览图](data-structures/data-structures-preview.png)：静态页面截图，便于快速查看布局。

课程参考为蓝不过海呀的[《线性表－顺序表（上）－定义、创建、查找》](https://www.bilibili.com/video/BV1CMQEBnE6o)及其“数据结构（精美动画演示讲解）”合集。课程目录于 2026-10-02 通过 B 站公开接口读取；概念解释按通用数据结构知识整理，未取得视频正文或字幕。栈、队列、串等内容属于常见课程补充。

逻辑结构描述元素之间的关系，存储结构描述这些关系如何在内存中实现。例如，线性表描述元素的先后次序，顺序表与链表是它的两种典型存储实现。

## 算法与 C++ 交互教程

- [结构体入门](tutorials/struct-tutorial.html)
- [四种算法思路](tutorials/algo-four-tutorial.html)
- [插入排序演示](tutorials/insertion-sort.html)
- [Flood Fill 教程](tutorials/floodfill-tutorial.html)
- [角谷猜想演示](tutorials/jiaogu-demo.html)，对应源码为 [practice/jiaogu.cpp](../practice/jiaogu.cpp)。

以上 HTML 文件用浏览器直接打开即可。在 GitHub 上，先下载文件再打开；本地静态服务器的启动方式见[项目首页](../README.md#浏览器预览)。

## 编译环境

- [Git Bash 中 g++ 的配置与排障](g++-setup.md)：记录本机工具链问题和 LLVM-MinGW 的配置过程。
- 日常编译与运行命令见[项目首页](../README.md#编译与运行)。源码统一放在 `practice/`，编译结果输出到 `build/`。

## 维护约定

新增教程或学习资料时，在本页补充入口。移动文件时同步更新相对链接；修改已有 XMind 导图时，保留已保存的主题和布局。课程目录是读取时的快照，如重新获取，应同步更新核对日期。
