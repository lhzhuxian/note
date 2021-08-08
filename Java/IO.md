https://segmentfault.com/a/1190000019814737

### NIO

> Java NIO (New IO)是 Java 的另一个 IO API (来自 java1.4) ，意味着可以替代标准的 Java IO API和 Java Networking API。 提供了一种与标准 IO API 不同的 IO 工作方式。

**注意：Java的NIO只是说IO API，阻塞非阻塞才是IO的模型。**

**对于基础的IO操作API（比如文件IO，FileChannel），还是阻塞的模型。只有对Networking IO API才可以使用非阻塞的模型（`configureBlocking(false)`）。**

### 阻塞 vs 非阻塞

当进行IO读写时，线程是阻塞的状态。此时会让出cpu控制权，不会占用cpu资源。

什么？不占用CPU资源？那是不是代表阻塞模型更好呢？

答案是并不是，虽然阻塞状态不会占用CPU，但是会发生线程的切换，线程切换时会有**上下文保存转换(context switch)**的过程，需要CPU调度，是一个很昂贵的操作。

Java NIO中的基础IO API（非Networking IO API）还是阻塞的方式，只是使用方式从面向流（stream）编程面向块（buffer）了，和BIO本质上并没有什么区别。

非阻塞是指在进行IO操作的时候，如果设备还未准备好（比如socket还没有收到数据），操作会直接返回结果，不会让当前线程进入阻塞状态。

这样的优点是，使用者可以自行决定在数据未准备好时的操作。线程可以在没有数据期间去执行其他操作。
Networking API可以配置为非阻塞模型`Channel.configureBlocking(false)`，配合Selector来实现多路复用功能。**简单的说就是一个Selector监听多个socket io（对于unix系统来说，socket也是一个fd，也属于io），可以在一个线程中支持多个连接**。当然在实际服务器开发时，就算是NIO模型，有些程序也不会只使用一个线程；但相比传统的Blocking IO方式来说，需要的线程数量也会大大减少了。（**redis中就是使用了IO多路复用技术，并且只有一个线程监听socket io**）

 

### AIO(Asynchronous IO)

异步 IO 是基于事件和回调机制实现的，也就是应用操作之后会直接返回，不会堵塞在那里，当后台处理完成，操作系统会执行回调通知相应的线程进行后续的操作。

### IO multiplexing

allowing **the programmer to examine and block on multiple I/O streams**

### Select

检查所有的socket，如果有数据就唤醒进程

dis：

 其一，每次调用select都需要将进程加入到所有监视socket的等待队列，每次唤醒都需要从每个队列中移除。这里涉及了两次遍历，而且每次都要将整个fds列表传递给内核，有一定的开销。正是因为遍历操作开销大，出于效率的考量，才会规定select的最大监视数量，默认只能监视1024个socket。

其二，进程被唤醒后，程序并不知道哪些socket收到数据，还需要遍历一次。



### Epoll



