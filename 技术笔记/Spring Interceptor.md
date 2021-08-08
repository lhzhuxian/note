### Interceptor 介绍

**拦截器(Interceptor)同** Filter 过滤器一样，它俩都是面向切面编程——AOP 的具体实现（AOP切面编程只是一种编程思想而已）。

你可以使用 Interceptor 来执行某些任务，例如在 **Controller** 处理请求之前编写日志，添加或更新配置……

在 **Spring中**，当请求发送到 **Controller** 时，在被**Controller**处理之前，它必须经过 **Interceptors**（0或多个）。

**Spring Interceptor**是一个非常类似于**Servlet Filter** 的概念 。

### Interceptor 作用

1. 日志记录：记录请求信息的日志，以便进行信息监控、信息统计、计算 PV（Page View）等；
2. 权限检查：如登录检测，进入处理器检测是否登录；
3. 性能监控：通过拦截器在进入处理器之前记录开始时间，在处理完后记录结束时间，从而得到该请求的处理时间。（反向代理，如 Apache 也可以自动记录）
4. 通用行为：读取 Cookie 得到用户信息并将用户对象放入请求，从而方便后续流程使用，还有如提取 Locale、Theme 信息等，只要是多个处理器都需要的即可使用拦截器实现。