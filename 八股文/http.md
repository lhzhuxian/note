https://zhuanlan.zhihu.com/p/135947893

HTTP 是一种 `超文本传输协议(Hypertext Transfer Protocol)`，**HTTP 是一个在计算机世界里专门在两点之间传输文字、图片、音频、视频等超文本数据的约定和规范**

HTTP 主要内容分为三部分，**超文本（Hypertext）、传输（Transfer）、协议（Protocol）**。

- 超文本就是不单单只是本文，它还可以传输图片、音频、视频，甚至点击文字或图片能够进行`超链接`的跳转。
- 上面这些概念可以统称为数据，传输就是数据需要经过一系列的物理介质从一个端系统传送到另外一个端系统的过程。通常我们把传输数据包的一方称为`请求方`，把接到二进制数据包的一方称为`应答方`。
- 而协议指的就是是网络中(包括互联网)传递、管理信息的一些规范。如同人与人之间相互交流是需要遵循一定的规矩一样，计算机之间的相互通信需要共同遵守一定的规则，这些规则就称为协议，只不过是网络协议。



![v2-a0eeeef2d69e44e1434c01f341660a0f_1440w](https://pic4.zhimg.com/80/v2-a0eeeef2d69e44e1434c01f341660a0f_1440w.jpg)

![v2-c7258ae8be7f1b3fcad3ec1897cc988d_1440w](https://pic2.zhimg.com/80/v2-c7258ae8be7f1b3fcad3ec1897cc988d_1440w.jpg)



而 HTTPS 的全称是 `Hypertext Transfer Protocol Secure`，从名称我们可以看出 HTTPS 要比 HTTPS 多了 secure 安全性这个概念，实际上， HTTPS 并不是一个新的应用层协议，它其实就是 HTTP + TLS/SSL 协议组合而成，而安全性的保证正是 TLS/SSL 所做的工作。


也就是说，**HTTPS 就是身披了一层 SSL 的 HTTP**。