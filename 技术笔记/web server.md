## web server, application server and web container

[**Web container**](https://en.wikipedia.org/wiki/Web_container), specially in java, should be refer to servlet container. A servlet container is the component of a web server that interacts with java servlets. A web container is responsible for managing the life-cycle of servlets, mapping a URL to a particular servlet and ensuring that the URL requester has the correct access rights and many more such services. Basically, putting together all above facts, **servlet container is the runtime environment where your servlet run** and it’s life cycle is maintained.



### servlet

是一个java接口interface

```java
public interface Servlet {

    public void init(ServletConfig config) throws ServletException;

    public ServletConfig getServletConfig();

    public void service(ServletRequest req, ServletResponse res)
            throws ServletException, IOException;

    public String getServletInfo();

    public void destroy();
}
```

这其中的`service(ServletRequest req,ServletResponse res)`方法，是Servlet的关键所在，是我们甚至可以说，其他方法”并不重要“，可以不进行实现。

**这个方法的作用，是把Tomcat（Servlet容器）传入的请求进行处理，并让Tomcat知道向客户端发送怎样的回应。**

那么客户端通过 Socket 传来的请求是如何变成`ServletRequest`类的呢？这就是容器 （如：Tomcat）的作用了，容器把客户端的消息解析，封装成`ServletRequest`，交给Servlet处理。

**Servlet容器怎么实现？HOW?**

**回调（callback）**

**为什么要有Servlet？WHY？**

**为java程序提供一个统一的web应用的规范**。



### jsp 

java server pages