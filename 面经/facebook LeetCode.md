

### Prefix Sum

\560 Subarray Sum Equals K



------



### Linked List

19 Remove Nth Node From End of List

用快慢指针，快指针先走n + 1 次，这样快指针和慢指针之间就有n 个node，这样快指针走到底的时候，slow的next就指向我们要删除的node





------



### DFS BFS

dfs 可以用iterate的方法来做

721 Accounts Merge

Draw an edge between two emails if they occur in the same account. The problem comes down to finding connected components of this graph. **dfs**

133 Clone Graph

很标准的bfs题目 visited 用hashmap来存老node 和新node

1197 Minimum Knight Moves

bfs 实现起来还是有难度的，要试一试

Set<int[]> 这样不行，`Set<Pair<>>` 这个可以来记录坐标

\129 Sum Root to Leaf Numbers

可以用bfs， 



785 Is Graph Bipartite?

用颜色来分，对每一个node都做dfs，如果这个点没有颜色就给它一个颜色，它的所有邻居的颜色都要和它相反，如果发现邻居的颜色和自己一样，那说明false



\515 Find Largest Value in Each Tree Row

简单bfs 每一层扫一遍就行了

\1161 Maximum Level Sum of a Binary Tree

普通bfs level traversal



\529. Minesweeper

地雷游戏好麻烦的感觉 等会儿在看



\419. Battleships in a Board

因为ship只能横放或者竖放，我们只要count ship的头就行了，碰到x的时候，检查一下它的上面和左边是不是x，不是就说明是头，count++



\1091 Shortest Path in Binary Matrix

就是找到最短路径，用bfs 

有空看一看A* search

------

139 Word Break

**dfs + memorization** 

140 Word Break II

和word break 相比，需要返回所有的break组合， 只要把meorization 要记的东西变成组合就行了





983 Minimum Cost For Tickets

DP

把整个年的天数拿来用 dp[i] = max(dp[i - 1] + 1 pass, dp[i - 7] + 7 pass, dp[i - 30] + 30 pass)

304 Range Sum Query 2D - Immutable

cache `dp[i][j] 代表从最左上角到这个点的rangesum` 

935 Knight Dialer

DP 

https://medium.com/hackernoon/google-interview-questions-deconstructed-the-knights-dialer-f780d516f029

https://leetcode.com/problems/knight-dialer/discuss/189287/O(n)-time-O(1)-space-DP-solution-%2B-Google-interview-question-writeup



\1027 Longest Arithmetic Subsequence

```
dp[i][diff] 代表 end在i的string diff的sequence 长度
dp[i][diff] = dp[j][diff] (nums[i] - nums[j] == diff)
先定下j， 然后i 从0到j 这样来循环
```





------

### Binary Tree

1382 Balance a Binary Search Tree

先用inorder traversal 变成一个sorted array， 然后把recontruct to blanced binary search tree就可以了

173 Binary Search Tree Iterator

最简单的方法是flattern tree as an array, 但space 更好的方法是用stack， 只需要O(h) h is the height of tree

只把最左边的node 放进stack 里， 当拿出一个node的时候就把它第一个右node 的全部最左放进stack里

270 Closest Binary Search Tree Value

1522 Diameter of N-Ary Tree

和Diameter of binary Tree 没啥区别，只要找到子树的最大两个depth 就行

1361 Validate Binary Tree Nodes

先列出indegree，必须要只有一个node的indegree是0， 另外的indegree是1， 然后检查从root出发能不能visit所有的点a

114 Flatten Binary Tree to Linked List

要从后往前来build这个list，那么需要post order traversal 

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share

\1305 All Elements in Two Binary Search Trees

用stack来实现inorder traversal的iterative做法， 将root的一直向左的node放入stack 中，然后从stack中拿出node的时候把root设为拿出来node的右node



Path Sum 1, 2, 3

```
Path Sum 能不能找到一条从root到leaf的path sum等于target， 简单的dfs
path Sum 2 返回所有的等于target的path， 和1差不多的code，只要把path给记录下来就好了, 记录path的时候要记得把node pop出来
paht Sum 3 不需要从root开始，从leaf结束，只要downwards就行了（fron paretn to child）这题要用到prefix sum的思路， 每一条从root到leaf的path都可以当作一个字问题，subarray sum equals k
paht Sum 4 
```



\98 Validate Binary Search Tree

dfs 在recursion的时候把upper_bound 和lower_bound传进入

------

1539 Kth Missing Positive Number

周末找个时间重新看一下**binary search** 的模版

\1060. Missing Element in Sorted Array

**这两题有点像的，到时候一起看看**

\1891. Cutting Ribbons

https://leetcode.com/problems/cutting-ribbons/discuss/1263437/Java-Simple-Binary-Search-%2B-Explanation

非常好的答案，总结一下binary serach



\162. Find Peak Element

到时候一起看吧

\875. Koko Eating Bananas

------

708 Insert into a Sorted Circular Linked List

不难理解，但是corner case 很多，有空在看一遍



146 LRU Cache

**HashMap + DoubledLinkedList** 难点在写一个DoubleedLinkedList



------

986 Interval List Intersections

```java
// interval merge的方法 
int lo = Math.max(A[i][0], B[j][0]);
 int hi = Math.min(A[i][1], B[j][1]);
 if (lo <= hi)
    ans.add(new int[]{lo, hi});
```



------

670 Maximum Swap

用一个size 9的array来记录每个digit最后出现的位置，然后从loop through 这个数字，每个digit看一下是不是有比它更大的在后面的数字，如果有就换过来 **math**

1344 Angle Between Hands of a Clock

```java
class Solution {
  public double angleClock(int hour, int minutes) {
    int oneMinAngle = 6;
    int oneHourAngle = 30;

    double minutesAngle = oneMinAngle * minutes;
    double hourAngle = (hour % 12 + minutes / 60.0) * oneHourAngle;

    double diff = Math.abs(hourAngle - minutesAngle);
    return Math.min(diff, 360 - diff);
  }
}
```



------

1209 Remove All Adjacent Duplicates in String II

**stack** 用一个stack来存char 和它的count， count 大于k就pop出来，最后连到一起



------

443 String Compression

**two pointer** 可以解决



**回文串**

\647. Palindromic Substrings

start from each index and try to extend palindrome for both odd and even length

\5. Longest Palindromic Substring

这个题目也是用同样的方法 来extend palindrome

------

\498 Diagonal Traverse

**matrix， simulation** 可以先把它当成普通的diagonal traverse 不去考虑zigzag的情况，然后根据diagonal的even odd来翻转中间量



\1424 Diagonal Traverse II

一个规律是`nums[i][j]` i + j 一样的数是在同一条diagonal上， 我们可以loop整个matrix，然后把这些数分别放入对应的diagonal上面，最后在组合到一起就好了



\825 Friends Of Appropriate Ages

不知道考了点啥，把所有年纪人group到一起，然后两个for loop 循环把所有条件满足的给乘一起，同个group a * (a -1 )





------



Trie的题目还有点多， 放到一起明天看

\1233. Remove Sub-Folders from the Filesystem

------

**Simulation**

\794. Valid Tic-Tac-Toe State

\641 Design Circular Deque

等会儿回来在看

