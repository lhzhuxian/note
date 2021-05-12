[Migrating Spring Boot tests from Junit 4 to Junit 5](https://www.javacodemonk.com/migrating-spring-boot-tests-from-junit-4-to-junit-5-00aa2839)

```groovy
//Spring Boot 2.3.0 includes junit5 as the default library for unit testing. It also includes junit vintage library that allows you to run Junit 4 and Junit 5 in parallel, so that you can slowly and easily migrate existing testcases from Junit 4 to Junit 5 without breaking anything.
plugins {
    id "java"
    id 'org.springframework.boot' version "2.3.0.RELEASE"
    id "io.spring.dependency-management" version "1.0.9.RELEASE"
}
//junit-vintage-engine is included by default to allows easy migration from Junit 4 to Junit 5, by allowing both Junit 4 and Junit 5 based tests to run in parallel. You can exclude junit-vintage-engine if you do not have any Junit 4 based testcase in your application.
testImplementation('org.springframework.boot:spring-boot-starter-test') {
    exclude group: 'org.junit.vintage', module: 'junit-vintage-engine'  
}

test {
    useJUnitPlatform()
}
```

