## synchronized

synchronized是Java中的关键字

synchronized可以保证方法或者代码块在运行时，同一时刻只有一个方法可以进入到临界区，同时它还可以保证共享变量的内存可见性，Java中每一个对象都可以作为锁，这是synchronized实现同步的基础。

```java
//多个线程访问 同一对象 的同步代码块
public class ThreadSyn implements Runnable{
    private  volatile static int count = 0;
    @Override
    public void run() {
        synchronized(this) {
            for (int i = 0; i < 5; i++) {
                try {
                    System.out.println(Thread.currentThread().getName() + ":" + (count++));
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

```

