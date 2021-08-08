整个流程可以按照下面这个文章来

https://www.1point3acres.com/bbs/thread-586264-1-1.html

## 理解需求





## 资源估算

- [ ] 列出资源计算的小技巧
- [ ] 熟悉资源单位



1. 注意整个过程中Interviewee在主导这个需求探索的过程，interviewer对interviewee给出的需求和数字做确认并少量给出受试者不知道的关键信息（比如DAU 800M)。不要让面试官做过多的单方面灌输信息。
2. 关于数字的计算少数情况下因为时间关系，面试官会让你跳过。如果算得不利索的话，建议跟面试官确认一下。相信这个小学数学对大家都不难，我的小技巧是365*24就算作10000就好，数量级对就行。

## High-level Diagram

![121820t85jmzc8z5wi3wbz](https://oss.1point3acres.cn/forum/202001/21/121820t85jmzc8z5wi3wbz.png)

- [ ] push vs pull
- [ ] 

在上图中，我们并没有过多考虑Scalability，而是提出一个小流量下可行的方案。在画图过程中，我们需要考虑的核心问题是Push vs Pull. 上图中提出的是Push的方案。我们一边画图，一边就可以跟面试官提出这个Trade-off. 我们提出我们意识到这是一个Read-heavy application.

- Push好处是Latency低，符合之前定义的Latency < 0.5s的要求。
- Push坏处是Fanout过程中耗时更长（因为一个人可以被很多人follow，比如celebrity)，能保证数据的eventual consistency，但不能保证最新照片及时进Feed. 当然这里可以提专门为celebrity的优化， 后面核心子服务会提到。

可以跟面试官确认Push的坏处是不是可以接受。

## 数据结构与存储

### 数据库

- [ ] sql vs nosql

### Cache

数据库缓存

- [ ] redis
- [ ] MemCached

文件系统缓存

- [ ] CDN

### 文件系统（file system）

- [ ] HDFS 
- [ ] Amazon S3

## 核心子服务设计

## 接口设计

## 扩展性 (Scalability)，容错性，延迟要求

## 专题 deep dive

### Sharding

 Instagram的Feed Table数据量单机无法承受的时候，你会怎样Scale up?
最直接的想法是，对于每个user id做hashing，分别放在不同的机器上。这样说答对了一半，面试官会跟进，问这样会不会造成有的机器很满，有的很空，如果某些机器又满了怎么办？
要解决这个问题的机制比较复杂，Cassandra的设计给我们提供了很好的设计思路，我们可以使用 Consistent Hashing 的 Hash Ring 来解决 node redistrubtion 的问题。