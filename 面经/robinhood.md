

challenging project，conflict，why robinhood，could do things differently





house trades

https://leetcode.com/playground/QhdXFrFc

margin call

https://leetcode.com/playground/74RoPVu4

初始balance 1000 买卖股票 打印出balance和手上的股票
followi up:
bal‍‌‌‌‌‍‌‌‍‍‌‌‍‌‌‍‌‍‌ance变负数 需要卖最高的股票 直到balance变正

margin call那道题，给起始资金，给一个list of trades，[["STOCK1", "B", 100, 5], ["STOCK2", "S", 120, 5] .. ]。每一个trade给了股票的symbol，买/卖，价钱，买卖的数量。求做完这些trades之后手里的现金和每支股票的数量，可以假设买的时候有足够的钱买，卖的时候有足够数量的股票可以卖。第二问是，买入的时候可能手里的现金不够，但是规则是不管怎样先买入，现金不够的话就变成负数，但是一旦现金是负数的话就要卖出手里的一些股票，直到现金为非负，卖出的时候挑选price最高的优先卖出。有第三问，但是没让做。







问的是计算ad campaign那题，面经里看过。给了个lambda architecutre思想解决方案，fast 和 slow path。



中间休息了30分钟，最后一轮。问的是类似于设计top k，trending topic。按说没什么难度，但是烙印面试官老是问问题，没有一气呵成的感觉，不爽。
后来shadow的先走了，我们多聊了10分钟，他说这‍‌‌‌‍‍‍‍‌‍‍‌‌‍‌‌‍‌‌题他第一次问，也不知道应该怎么推进。这个也是类似fast path的处理方法，但是我也提了可以
有一条slow path来跑MR，提高精确度。



design是设计robinhood交易系统，支持让用户延迟下单，主要问了在不同的出错的情况下系统怎么handle‍‌‌‌‍‍‍‍‌‍‍‌‌‍‌‌‍‌‌，transaction是怎么work的

https://www.1point3acres.com/bbs/thread-793803-1-1.html



job scheduler 

设计轮是 job scheduler， 老哥问的很细， 各种failure scenario， 再就是data model 问的很细， 区别是加了SLA， 比如 3个小时 这个task 如果没有运行结束，需要kill 掉， 问怎么在db 里search 最方便

重点问了db schema，怎么处理failure

我记得因为是要支持periodical 的job，所以有一个job template的table，相当于用户在这里定义job，里面放cron pattern和job command，还有一个是job instance的table，就是每一个要执行的job，里面放instance的start time和status之类信息。每一个template可以对应多个instance。

Job id, Job name, user id, job start time, recurring/non recurring, frequency, status.

Statuss could be new, queued, running, success, failure.

有SLA，避免重复执行，同时进行的job数量很大，发通知

https://leetcode.com/discuss/general-discussion/1082786/system-design-designing-a-distributed-job-scheduler-many-interesting-concepts-to-learn

Airflow:

https://www.qubole.com/tech-blog/understand-apache-airflows-modular-architecture/

https://airflow.apache.org/docs/apache-airflow/stable/concepts/overview.html



Dropbox https://dropbox.tech/infrastructure/asynchronous-task-scheduling-at-dropbox







Job scheduler

https://leetcode.com/discuss/general-discussion/1082786/system-design-designing-a-distributed-job-scheduler-many-interesting-concepts-to-learn

是的，关键元素就是db存job status，send job到MQ，worker pool pick-up job

题目很简单，就两行描述，给你一个cron的输入例子，让你设计一个支持这种形式输入的任务调度器。单机还是分布式应该取决于面试官吧，题目本身是没说的。

没有给任何应用场景，感觉不是这个题的重点。自己想还是能想到挺多例子的吧，比如我要每周五晚上跑一个job，根据我过去一周的数据重新训练一下模型。

你的downstream指的是shadow machine吗？如果machine down了它就不能发msg了啊。和面试官商量的用个healthcheck system，如果检测到machine down就recreate msg到queue里面，其实kafka zookeeper本身就可以解决这个问题



設計股票交易系統，限定買賣limit order。比較注重data modeling, 如何預防concu‍‌‌‌‍‍‍‍‌‍‍‌‌‍‌‌‍‌‌rrent orders, insufficient balance, 如何failure recovery
