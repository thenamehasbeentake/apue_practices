# 前言
## 一版前言

  本书表述UNIX系统程序设计接口：系统调用接口和标准c库提供的很多函数， 具体接口可以参考《UNIX程序员手册》 第二、三部分，本书主要描述实例和基本原理
本书主要分6部分：
一二章：UNIX初始UNIX
三四五六章：文件系统有关
七八九十章： 进程
十一到十三： 其他IO
十四到十五： IPC，进程间通信
十六到十九： 实例

W.Richard Stevens
1992年4月
## 二版前言
Open Group(X/Open)发布的"Single UNXI specification"基本规范已经合并入POSIX.1
套接字接口也是POSIX.1的一部分
当时比较典型的实例，现在发生了较大的变化。

Stephen A.Rago（一版作者驾鹤西去了）
2005年4月
## 三版前言
POSIX.1-2008弃用STREAMS接口，STREAMS接口为socket接口提供了一个很好的对照。
加入新的接口，异步I/O、自旋锁、屏障和POSIX信号量等接口

Stephen A.Rago
2013年4月

## 译者序
总之就是随着时间的发展多了UNIX POSIX接口多了很多

## 文档说明
目前我已经在ubuntu 18上看到POSIX.2有关的说明，这本书里面是没有POSIX.2有关的，不过我感觉还是很有学习的价值的。
如果需要用到POSIX.2接口时，看到这个文档，建议不要浪费时间看下去而是去有关网站搜索,如 [wiki](https://en.wikipedia.org/wiki/POSIX),[oracle man page](https://docs.oracle.com/cd/E36784_01/html/E36883/posix.2-5.html), [The POSIX/2 Project](http://posix2.sourceforge.net/#announcements)

thenamehasbeentake
2021年6月