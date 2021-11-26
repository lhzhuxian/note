

目前到2021 - 4- 7这部分



系统设计和technical communication建议搞个ipad画图，直观方便。两天后收到结果



基础知识

1. java中finally, finalized, final的区别；谁会call finalized这个函数？
2. 解释virtual memory （个人觉得从vm的整体架构答比较好）；
3. Thread和process的区别



比如mongodb，db indexing, restful api, state



------



### Behavior

如果你是一个Tech Leader要propose一个new feature你该怎么去和PM沟通，怎么调度队伍，怎么按时发布之类的。要想一个具体的feature出来。



为什么离开现在的公司

我说就算我不背layoff也会被分到一个不大喜欢的组接触不到更challenge的工作。这好像踩中HM的红线了，他直接说你的答案不convince me，所有new hire都是从小task做起的，像你这样频繁job hoping的人没有哪个HM会喜欢的，建议你之后面试其他公司的时候好好准备一下你的理由



比較注重在collaboration或是testing方面的BQ，一樣講的口乾舌燥。



challenge project,impact,proudest project



新进一个组要开始做新project的话，首先要做什么让自己可以ramp up. 找team要document.



在implementation过程中，你发现一些planning时没考虑到的问题。导致如果按照计划时间内写出来的程序是不完美的。但如果想要fix这些问题，需要更长的时间，你会怎么做。（有可能就要聊一下如何跟senior eng, manager and pm沟通）



比如如何解决凌鹰页面上申请某工作后就进入其他网站的问题。我一听就有些懵，经理就会给一些hints，我就顺着他的hints往下走，比如可以跟其它网站合作，调取他们的api，集成到凌鹰网站上等等。



设计一个API让用户去upload videos



如何处理技术上的挑战等常规bq

### non-tag

代码轮1）decode encode二叉树，一开始用层序遍历,面试官说,好我知道你的意思了，但你这个要用另外的space complexity, 如果不用层序遍历怎么搞，我说试试inorder+preorder?好像也不是他要的他一直说我用了space反正最后没明白他到底什么意思，肯定挂了
代码2）问了一题怎么写开根号，呵呵，我不会，我也不太明白面试问这种问题是想干嘛。但我还是照想到的思路写了，但后来面试官说有float怎么办，嗯… 我就也挂了

https://www.1point3acres.com/bbs/thread-753550-1-1.html



coding1：
中国小哥，年龄相仿，交谈甚欢
1. #of connected components in a graph   用的并查集
2.  divide array into K equal part


coding2:
1. 第一个很简单实在‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌是忘记了
2. max path sum for a tree



best retain cache



两个linkedlist是否intersect. follow up: 有环怎么办



resursion 题 given a set of numbers, find subset equal to given target, followup, wh‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌at is given set contains negative.



Factor Combinations



简化版的combination sum，只需要返回满足target的个数



实现一个API里面addInterval(int start, int end)和getCoveredLength()，跟mergeInterval和insertInterval很像，说了几种方法，讨论了一下，最后确认了一种方法开始写



coding1是90度反转一颗树 permutation

就是树之后如果是右节点就只是叶子
然后把每个点左结点变成父结点 右节点变成他同一层隔壁右边的节点 最后返回新的root 递归就好了



coding2是算最多 多少点在一条线上



\701 Insert into a Binary Search Tree



第二题是把一个binary tree每个垂直的点都加在一个list里然后返回一个list of list那题，顺序有要求  leetcode 987



有一个class WordFiner，里边有2个function。原题是java写的interface，我这里用cpp大概写一下。
class WordFinder {
public:
  WordFinder(set<string> words) {}
  set<string> find(set<char> chars) {}
};
关于constructor，输入是set of string。find这个function输入是一堆character，然后问在给定的words里哪些word包含所有的char？找到并返回。
这题我第一种解法是hash，后来阿三说他不喜欢。我说行吧，那咱用trie，这回他才让我过了。

对于输入的words建trie，然后在find里用dfs找…



实现HashMap，然后面试官要求加了个一个bucket有超过十个立刻rehash直到没有这样的bucket为止，我的办法就是把当时的时间戳加进去一起hash同时记录这个时间戳。



```python
"""
Given a list of strings denoting function name, START or END marker, and timestamp. Calls can be nested and one function can call child functions.
For example:

"abc,START,100"
"def,START,150",
"def,END,180",
"abc,END,200"
Inclusive time is defined as all the time spent on a particular function, including time spent on its child calls.
Exclusive time is defined as the time spent on a particular function only, excluding time spent on its child calls.
In the above example, inclusive time for function "abc" is 200-100=100, while exclusive time for function "abc" is (200-100) - (180-150) = 70

Given such list of strings, figure out the inclusive and exclusive time for any given function call.  

Note that the calls can span multiple levels and nested.
Sample Input:
"abc,START,100",
"def,START,150",
"bla",START,160,
"hij,START,170",
"hij,END,200",
"bla",END, 200
"def,END,220",
"job4,START,230",
"job4,END,250",
"abc,END,300"
"""
def parseJobTime(input, jobName, result):
    start_time = -1
    child_name = ""
    child_start = -1
    total_child_time = 0
    result = [0,0]
    for job_str in input:
        job, mark, time = job_str.split(',')
        
        if job == jobName:
            if mark == "START":
                start_time = time
            else:
                # post-process
                result[0] = int(time) - int(start_time)
                result[1] = result[0] - total_child_time
                return result
        
        else:
            if start_time != -1: # this job is within my interest job
                if child_name == "": # this job is also the immediate decendent of my job
                    child_name = job
                    child_start = time
                elif child_name == job:
                    total_child_time += (int(time) - int(child_start))
                    child_name = ""
                    child_start = -1
            
    return result
```



```java
# Write a program which takes an infinite stream of random integers and provides a method to query the top K largest integers encountered so far.
# K = 2, 1,2,3,4
# init(2), addNumber(1), getTopK(), addNumber(2), addNumber(3), getTopK(), addNumber(0), getTopK()

Class KLargest(object):
    def __init__(self, K):
        self.capacity = K # 2
        heap = []
        self.pq = heapq.heapify(heap) # [2, 3]
        self.set = set()

    def addNumber(self, number):
        if len(self.pq) < self.capacity:
            heapq.heappush(self.pq, number)
            return

        min_num = heapq.top(self.pq)  
        if min_num < number:
            heapq.heappop(self.pq)
            heapq.heappush(self.pq, number)

    def getTopK(self):
        return self.pq

```



------





### follow up

共同祖先，不過另外加了一些別的限制，什麼target不在啊，target相同啊，一直問有沒有更好的解。



LC636。除了exclusive time，还加了一个inclusive time，其实就是任务的结束时间减去开始时间而已，对题目的难度没有什么影响。用Stack解决就可以了。

LC Work Ladder的某一道（记不清了。。）。Followup：如果现在是一个class，constructor给定input dict，findLadder(word1, word2)会被call很多次，怎么优化？答可以把一些中间结果保存下来，面试官又引导可以不可以对data做一个pre processing，其实没有太get到，后来明白是可以提前做一个dict，帮助快速找到neighbor words, 比如key是"d*g", value是["dog", "dig"]

利口一六铃，follow up 链表有环



 LCA, InsertRemoveRemoveRandom O(1), follow up Duplicates



刘酒吧 ， 数组有negative咋办

### System Design

SD：Design Calendar，大致的界面，API设计，数据库。从single server开始设计。

问建一个calendar system, like outlook. 没看过这方面的临时解答了，平时工作有做sys design所以还好，但硬度姐姐最后问我你不觉得你这个系统少了点什么吗？ 我说我们再加点新feature? 后来她说我没画front end component...呵呵，绝了，我从没试过设计backend 系统让我画个front end component的。

https://www.learnbay.io/google-calendar-high-level-system-design/



如何ban掉一些 malicious ip address， 问了很多data partition， table design，sql no‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌ sql的问题，staff问的，完全凉凉

design一个feed，刚好是我在fb经常面试别人的题，表现也不错，估计也是个strong hire



logging system

logging system一開始啥都沒給，問了問才說，那就當作是L家post / feed這個部分的logging吧。
先是說了哪些可以log的，然後面試官才一步步往下問。
我其實很不懂，就說了什麼post view, popular posts之類的...



设计一个typeahead的系统

------

TopK in 5mins 1hr 1day

design topK shared URL， K is static number, 找过去五分钟，一小时，一天的结果

real time solution, hourly solution

database里面存什么怎么存怎么返回query

应该是挂这轮了，面试官大哥一直和我纠缠单机该如何实现，最后搞得像是在写算法题，不满意priorityQueue做，说时间复杂度高。。distributed问我online怎么搞，应该是kafka+spark，当时只想着mapReduce,他说这是offline

------

Design Blacklist service， 提供一个isMalicious(ip)的API，设计系统防止恶意攻击。主要难点在于sync各个server的blacklist，initialize new added server...

functional/non-functional requirements 假设一天1Billion访问量，5%是malicious ip造成的，估算下QPS和storage，可以跟面试官negotiate.  High level  LB layer, app server layer 然后request manager，ip要是没见过直接调用api，然后存进数据库。后面优化app servers本地存blacklist, 用kafka sync，backup可以让request manager去初始化

------

短链接, followup: 如果要‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌统计hot url怎么办?(TopK).

------

System Design. 设计一个activity/health monitoring system for data center、

------

设计一个activity/health monitoring system for data center

------

设计一个key value存储

------

实现 store document, query words

类似 存储 ebook，再检索

------

设计一个在线游戏系统



------

问了怎么authenticate microservice的call，刚准备介绍，没想到面试官就开始准备一个一个问题的问，照着自己准备的问的，总共7-8个，比如怎么打包自己code成lib，让其他组使用？一脸问号？？Kafka，offline log process，db，pull vs push。。。都尽力‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌答了。



------

design rate limitter

------

 document index. 我说用map reduce 来build index，然后可以存在trie里。他不大想用trie，问我trie和hashmap有啥区别，我说tire节省空间，他表情不同意的样子。后来决定index决定存db里。问了如何scale，我说可以partition data。他说如何sharding，我说可以consistent hashing。他说具体怎么做，我要正要画个圈给他讲consitent hashing，他说不用算法，我们是high level system design，我就给他画了web server，load balancer，db的图（according to recruiter，他说他需要提醒我需要从high level design的方向思考）。中间提到了不同db的优缺点，如果搜集top k的关键字，我讲了memca‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌ched和redis的优缺点，和如何按bucket存频率。



说实话，mapreduce之后放在trie里不多，有也是分开的，基本上咱们说mr就是纯后端，放trie基本上app server logic layer用多一点，而且树结构费内存。具体参见suffix tree和suffix array的空间对比。另外如何partition的问题，你回答的consist hashing的方法是对的，但是可能出发点是讨论是基于用那一个key做partition，时序类用时间，用户类用uid，twitter的老的snowflake id生成可以了解一下。 祝愿马上就有hc！



我想可以用search engine 如elastic search 或 solr存word count，mapreduce算出来的结果存入search engine便于查询，如何产生key应该跟如何保存文件有关，我想文件存入的时候应该会产生数字id，这个id可以用两个id generating machine来完成（两个避免single point of failure), 有了id就容易partitiion了







## design search documents by word

inverted Index

stopwords, synonyms, stemming, 

tokenizers

filters

tf/idf





## key-value store



## Top K system





## logging system

How to log the errors

aggregation metrics ex. count 401 errors







### infra 面经

https://www.1point3acres.com/bbs/thread-779974-1-1.html

https://www.1point3acres.com/bbs/thread-776455-1-1.html

https://www.1point3acres.com/bbs/thread-771698-1-1.html

https://www.1point3acres.com/bbs/thread-766457-1-1.html

https://www.1point3acres.com/bbs/thread-774862-1-1.html

https://www.1point3acres.com/bbs/thread-752567-1-1.html

https://www.1point3acres.com/bbs/thread-753374-1-1.html

https://www.1point3acres.com/bbs/thread-759289-1-1.html