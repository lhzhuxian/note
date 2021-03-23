#### JavaBean, SpringBean, 对象之间的区别

Bean肯定是对象

JavaBean 所有属性private 需要用getter setter 来调用

SpringBean 有spring管理（包括但不限于生成）的对象

```java
ClassPathXmlApplicationContext applicationContext = new ClassPathXmlApplicationContext("spring.xml");
User user1 = applicationContext.getBean("user", User.class);
```

#### spring 定义bean的方式

```java
//<bean/>
ClassPathXmlApplicationContext applicationContext = new ClassPathXmlApplicationContext("spring.xml");
User user1 = applicationContext.getBean("user", User.class);
//@Component
@ComponentScan("cam.example") 
// 扫描package下面有Component（其他应该也行） 注解
// @Service 之中包含了@Component

//@Bean
AnnotationConfigApplicationContext applicationContext = new AnnotationConfigApplicationContext (Config.class);
applicationContext.register();
// BeanDefinition
AbstractBeanDefinition beanDefinition = BeanDefinitionBuilder.genericBeanDefinition().getBeanDefinition();
beanDefinition.setBeanClass(User.class);
applicationContext.registerBeanDefinition("user", beanDefinition);
```

#### FactoryBean

```java
//用BeanDefinition注册factoryBean的时候， 生成的bean是factory所制造的bean
AbstractBeanDefinition beanDefinition = BeanDefinitionBuilder.genericBeanDefinition().getBeanDefinition();
beanDefinition.setBeanClass(FactoryBean.class); // 生成2个bean 产品bean和工厂bean
applicationContext.registerBeanDefinition("user", beanDefinition);
```

