

第一轮，一个越南小哥，一位亚裔，考Text Justification，给的题意很不清晰，说是你要出版一本书，给你一堆字如何出版，我说万一这个字超过一行该怎么办，他说好问题，这是一个corner case，然后我就自己把自己绕进去了，这个case没写出来，gg了
第二轮， host manager，一个看起来就很精明的manager，整场面试他讲得多我讲的少，讲他们在track user learning completion score的时候出现了一些数据错误，之后改正了，提高了多少，赚了多少钱，有多少商业价值，他们还做了很多的tool，准备推广给全公司用，说这些数据都是engineer retro上搞出来看的，感觉是一个非常会说的manager。
第三轮， 印度小哥，word ladder， 一开始是打印出路径那个题，之后说先搞出来step，在我弄出step之后就没问打印最短路径，就问了binary search tree，最靠近target的k个点的题，15min写完
第四轮， system design， 如何ban掉一些 malicious ip address， 问了很多data partition， table design，sql no sql的问题，staff问的，完全凉凉
第五轮： technical dive， 讲述一个你之前做过的service或者东西的架构以及整个的开发流程， 对架构会很详细地问你为什么这样设计

------







------

zoom 和 coderpad setup应该都很习惯了，但今天这个code editor好难用 一换行就跳到页面中间，代码及其难看而且不好调整， 有洁癖的自行研究下codepad的editor砸搞。
现在学乖了，每次面试自行开两个屏幕， 一个屏幕写代码， 一个屏幕观察面试官的表情。单屏面试只能在面试官和写代码之间不停切换的同胞们可以考虑一下。



https://www.1point3acres.com/bbs/thread-766938-1-1.html

BQ

前二十分钟BQ，都是比较常见的题目，比如提高团队效率啊，怎么优化组里的架构啊之类的。

proud project and what you will improve you could do it again

多线程的概念，什么时候用多线程，多进程，之间怎么通信，semaphore，mutex的概念，区别，另外还问了JMV里面有什么，什么是virtual memory, exception, 什么时候用exception, c++ 和 Java 和 python的区别

------

基础知识

process vs thread， transaction， db 的 transcation 是怎么支持的

mutex 和semaphore的区别，virtual memory & page,  difference between C++ template and virtual function.

java 基础知识 java final finally finalized

又问了十分钟进程和线程，有什么区别，怎么通信

问了工作中的technical challenge和如何解决。然后问问题，问了process vs thread，write-thru cache vs write-back cache，java如何handle exception。

multithread vs multiprocess
stack memory, heap
C++, Java memory allocation 發生在compile or runtime

virtual memory有关的知识

Java finally final finalize, mutex vs semaphore 还有 binary semaphore

------

[ Nested List Weight Sum](https://leetcode.com/problems/nested-list-weight-sum)

sort color2

Shortest word distance  follow up -> 如果有很多words 怎么办

maximum depth of binary tree

RetainBestCache - 

https://www.1point3acres.com/bbs/interview/linkedin-software-engineer-484962.html

写cache。

只有get方法，没有set/put。
会给一个capacity，给一个datastore function的API，就是后台拉数据。然后给一个根据value返回权重值的API，要根据value，注意是value不是key，根据value的权重值来决定evict cache的先后顺序。

有一点triky 的地方是，根据value，然后就是如果满了，最好是先把目前get的放进去，然后再evict，因为有可能目前要放的，value的权重值最低，其实就是不用放了。也可以先做判断再决定evict还是放当前的key valu‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌e。

之后问了LRU，LFU等的实现，如何实现，就是口头讲了。之后问了LRU，LFU等的实现，如何实现，就是口头讲了。

folllow up1: 如何保证thread safe, 加锁了之后也讨论了如何提高性能，感觉答的不好。
follow up2: rank 会改变，使用越多rank越高，给了类似LFU的解法，来不及写代码了。

怎么支持多线程.... 一开始想用 synchronized 关键字，但是 performance 肯定不行，后来在面试官提醒下，用了 reentrantLock， 可能这边会挂。 (三哥面试官一直说 you did perfect.... 感觉会不会是笑面虎...)



Permutations 1, 2

101 symmetric tree

[Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation)

maxstack - 还要掌握 hashmap+双向链表+heap 的做法

[ Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) recursive

[Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array)

[Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target)

[Maximum Subarray](https://leetcode.com/problems/maximum-subarray)

364 [Nested List Weight Sum II](https://leetcode.com/problems/nested-list-weight-sum-ii)  

339 [Nested List Weight Sum](https://leetcode.com/problems/nested-list-weight-sum)  

[Can Place Flowers](https://leetcode.com/problems/can-place-flowers)

103 Binary Tree Zigzag Level Order Traversal  - 要用deque才能实现打印，还好会deque的做法

244 Shortest Word Distance II 

[Maximum Subarray](https://leetcode.com/problems/maximum-subarray)

[Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray)

671 [Second Minimum Node In a Binary Tree](https://leetcode.com/problems/second-minimum-node-in-a-binary-tree)

[ Valid Parentheses](https://leetcode.com/problems/valid-parentheses)

[Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1)

951 Flip Equivalent Binary Trees

[ 360. Sort Transformed Array](https://leetcode.com/problems/sort-transformed-array)

[68 Text Justification](https://leetcode.com/problems/text-justification)

671 [Second Minimum Node In a Binary Tree](https://leetcode.com/problems/second-minimum-node-in-a-binary-tree)

323 [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph)

297 [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree)

215 [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array)

254 [Factor Combinations](https://leetcode.com/problems/factor-combinations)

528 [Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight)

150 [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation) -- 处理 exceptions，testcase

367 [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square)

215 [Kth Largest Element in an Arra](https://leetcode.com/problems/kth-largest-element-in-an-array)

706 [Design HashMap](https://leetcode.com/problems/design-hashmap)

464 Can I Win

65 [ Valid Number](https://leetcode.com/problems/valid-number)

23 [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists)

61 Rotate List

149 max points on a line

​	



整数转化为二进制字符串 写了数学计算的法 讨论了bit manipulation,  int转二进制