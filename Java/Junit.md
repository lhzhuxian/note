### Junit4 vs Juni5







### 什么是Runner,@RunWith()到底有什么用？

Runner是Junit的运行器，即运行测试用例的工具。

我们可以在测试类之上，使用@RunWith()注解为这个类指定一个特定的Runner。没有指定的时候会自动使用Junit的默认Runner——BlockJunit4ClassRunner