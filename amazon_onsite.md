Onsite:



1. Sum of all binarysearchtrees in a tree. So, basically the interviewer wanted to create a tree and then if there was a BST, add the value of all the nodes in the tree.
2. OOP/Coding : Design a game where there are multiple players, you can either add a new player, update their score or display Leadership Board
3. System Design : Design Twitter
4. Given a directory, create a method like FIND where you need to find all the files under that directory. Directory can have other directories, so you need to check and retrieve all the files.(https://leetcode.com/discuss/interview-question/369272/Amazon-or-Onsite-or-Linux-Find-Command)

https://leetcode.com/discuss/interview-question/system-design/625918/Amazon-or-System-Design-or-Design-a-real-time-gaming-ranking-system





### Algorithm

1. linux find

2. ```
   Given a family tree for a few generations for the entire population and two people write a routine that will find out if they are blood related. Siblings are blood related since they have the same parents. Cousins are blood related since one of their parents have the same parents etc. Design the data structure first and then write the routine.
   
   https://www.careercup.com/question?id=4812957531766784
   ```

3. [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

4. permutations

5. [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)

6. [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)

7. ```
   然后进入考题，有点ＯＯＰ而不是系统设计，让我设计 locker delivery system 的各种类名，然后各种设计api, 　我讲到了很多code maintainability方面的问题，比如这个以后可以怎么refactor等等。总体来说比较顺，但就是对方没有太多feedback, 一直是我不停地在说。
   https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=764499&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D5%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26searchoption%5B3109%5D%5Bvalue%5D%3D2%26searchoption%5B3109%5D%5Btype%5D%3Dradio%26sortid%3D311%26orderby%3Ddateline
   ```

8. Items in Containers Amazon [OA](https://leetcode.com/discuss/interview-question/1148760/Items-in-Containers-Amazon-OA)

9. ```
   關於swap的一道新題，就是地裡最近這兩三週都頻繁出現的新題。我在algo monster那個網站看到有答案 （要付29刀才能看到答案）
   https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=764458&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D5%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26searchoption%5B3109%5D%5Bvalue%5D%3D2%26searchoption%5B3109%5D%5Btype%5D%3Dradio%26sortid%3D311%26orderby%3Ddateline
   ```

   

10. [pow(x, y)](https://leetcode.com/problems/powx-n/)

11. ```
    OOD + 2 sum: implement an API which takes input PlayList (consist of songs) and a targetDuration, and return all song pairs in the playlist that has sum duration equals to the targetDuration. Need to define the PlayList class and Song class
    
    OOD + BFS: implement a function to fetch the shortest path between two LinkedIn Users (if A & B are friends, then path between A & B will be 1)
    
    https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=764274&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D5%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26searchoption%5B3109%5D%5Bvalue%5D%3D2%26searchoption%5B3109%5D%5Btype%5D%3Dradio%26sortid%3D311%26orderby%3Ddateline
    ```

12. [Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/)

13. [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

14. ```
    OA 
    1，In- flight media
    2,   item grouping
    ```

15. [Stream of Characters](https://leetcode.com/problems/stream-of-characters/)

16. [3sum](https://leetcode.com/problems/3sum/)

    1. (bonus) input is a TreeNode. update all the node values with the sum of its all children

17. ```
     write a function that 50% return 1, 50% return 0
        follow up: utilize the function you just wrote, write another function 75% return 1 and 25% return 0
    ```

18. 

#### System Design

1. prime video
2. ecommerce
   1. request spike, bottle neck
   2. circuit breaker
   3. data roll up

### BQ

1. miss deadline 怎么办 ？
2. 讲一次你的工作超出预期的经历。
3. beyond manager expectation
4. most challenging project

 

#### 面试经验

[亚麻BQ大总结:如何Cracking Leadership Principles](https://www.1point3acres.com/bbs/interview/amazon-software-engineer-679738.html)https://www.1point3acres.com/bbs/interview/amazon-software-engineer-679738.html

```
1. 设计个能同时控制多个repo的git系统
2. https://www.geeksforgeeks.org/taxicab-numbers/

3. https://leetcode.com/discuss/int ... pular-page-sequence

系统设计：类似prime video加广告

然后除了第一轮是个hispanic小哥以外另外三轮都是烙印面的。


个人觉得技术面的没太大问题，从头到尾不需要任何提示就能想出算法写好代码，也没有人让我code enhancement，follow up也能秒答也没被人纠过错。除了有一面写着写着漏了一行被面试官提醒才补上，然后读txt文件的api我忘了，直接和面试官说清楚了这块不记得具体怎么写了，就写的伪代码，就这一行。题目本身也不难，基本上都是各种排列组合的可能性存到hashmap里面就能出最优结果。系统设计题目还是我以前工作内容接触过的东西。而且我听说技术面的不好的会发降级offer是不？

我估计就是behavioral挂的，不过我之前花了挺长时间掏空脑袋想例子，每个都用STAR format写了稿，还搜了好多据说是原题的题找人mock interview来着，面试的时候也确认了基本没押错题。但还是过不了，让我对自己讲故事的能力产生了深深的怀疑……
话说有什么奇技银巧能拿到feedback不，我recruiter嘴咬得很紧不肯给我说，谢谢大家

https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=762446&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D5%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26searchoption%5B3109%5D%5Bvalue%5D%3D2%26searchoption%5B3109%5D%5Btype%5D%3Dradio%26sortid%3D311%26orderby%3Ddateline
```



[疫情下VO视频面试如何出色发挥](https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=637223&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D5%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26searchoption%5B3109%5D%5Bvalue%5D%3D2%26searchoption%5B3109%5D%5Btype%5D%3Dradio%26sortid%3D311%26orderby%3Ddateline)

