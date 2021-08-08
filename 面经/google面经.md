## BQ

deadline如何处理，组员关系，没什么followup





------

在南極有多個企鵝觀測站，每個觀測站都有鄰居，像一個graph, 每個觀測站有自己的local count, 給定某個節點發出get_count request 要回傳total count。可以想像每個觀測站都是透過network call溝通，network call is already implemented，假設已給定station object, send() is implemented, 要求實現receive() method and main function

個人覺得這題很有趣，如果是有全局觀的一般leetcode題目，就dfs 秒殺。但這題是寫要在單機運行的程式做dfs。



基本上就是實現iterator
You have 2 trees(any kind of tree, the 2 tree has nothing alike), each tree has leaves,

1. I'd like you to write a function where it returns the first different leave node between the two trees.
2. Extension: thinking if you want to run your function on ‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌a machine with limit memory, and the trees are really large to fit into the memory.[it is too wide to fit into the memory but depth is ok.]

可以实现一个iterator 然后慢慢对比两个树

**可能类似的题目： Binary Search Tree Iterator， Merge Two Binary Trees**

------

https://www.1point3acres.com/bbs/thread-775176-1-1.html

找两个相连且相同的字母

aa return 1
aac return 1
aaa return 2
aabb return 2
找到连续切相同的字母 返回找到的个数

按照版本序列号，找到相匹配的app

第四轮 图论

第五轮 Bitwis‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌e operation

------

https://www.1point3acres.com/bbs/thread-775095-1-1.html

第一轮:
给出一个text，输出一个模型.
比如 it was the best of times and it was the worst of times.
it: {was:2}
was: {the:2}
the: {best:1, worst:1}
...
key 是前面的单词
value 是后面单词出现的次数

follow up:
类似吴尔巴
给一个word，然后输出一个新的text
比如：
the: {cat:1}, {dog:2}, {horse:10}
输入the 随机输出一个单词cat
lz 一开始理解错了题意 以为是生成所有的单词，比如
the cat the dog the horse the dog the horse the horse 这些....
然后钻到死胡同想了半天拓扑排序，dfs啥的，最后和面试官交流才明白了要用weight random的思路来做。
没时间就写了写伪代码了。



第三轮：
先定义了学生传递纸条被抓住的概率
因为老师站在第一排，所以被抓的概率会不同
规律如下：
a --- 0.9 --- b --- 0.9 ----c
|
0.5
|
d ---0.45 -- e -----...
|
.25
|
f

然后给一段学生的关系图，返回被抓住的概率
follow up:
学生发动技能：sneakness  (0-100)
比如第一排横着传递 被抓到的概率就是:  0.9 * (100 - sneakness)

第四轮：
刷题网一巴而无


总体感觉面的不难，面的比ng时候强一点，但太紧张了，发挥的不是太好。