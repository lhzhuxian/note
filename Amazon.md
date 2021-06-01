## 面经

### OA

https://aonecode.com/amazon-online-assessment-questions#lsv

https://www.teamblind.com/post/Amazon-OA-question-complilation-xjQosyo3

https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=715940&extra=page=16&filter=lastpost&orderby=lastpost&sortid=311&sortid=311&orderby=lastpost

https://algo.monster/problems/amazon_oa_robot_in_circle

```java
// Transaction logs
// 知识点： hash map， Collections.sort
static List<String> processLogs(List<String> logs, int threshold) {
        Map<String, Integer> map = new HashMap<>();
        for(String line : logs) {
            String[] elements = line.split(" ");
            map.put(elements[0], map.getOrDefault(elements[0], 0) + 1);
            if(elements[0].compareTo(elements[1]) != 0) {
                map.put(elements[1], map.getOrDefault(elements[1], 0) + 1);
            }
        }

        List<String> userIds = new ArrayList<>();
        for(Map.Entry<String, Integer> entry: map.entrySet()) {
            if(entry.getValue() >= threshold) {
                userIds.add(entry.getKey());
            }
        }

        Collections.sort(userIds, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return Integer.parseInt(o1) - Integer.parseInt(o2);
            }
        });
        return userIds;
    }

// Gifts group(friend circles) leetcode 547
// 知识点： dfs
class Solution {
    
    public void dfs(int[][] M, int[] visited, int i) {
        if(visited[i] == 1) {
            return;
        }
        visited[i] = 1;
        for(int j = 0; j< M[i].length; ++j) {
            if(M[i][j] == 1) {
                dfs(M, visited, j);
            }
        }
    }
    public int findCircleNum(int[][] M) {
       int[] visited = new int[M.length];
        int count = 0;
        for(int i = 0; i < M.length; ++i) {
            if(visited[i] == 0) {
                dfs(M, visited, i);
                count += 1;
            }
        }
        return count;
    }
}


```

```java
// Movies on Flight
/*
You are on a flight and wanna watch two movies during this flight.

You are given a list of integers which includes all the movie durations and also given the duration of the flight which is d in minutes.

Now, you need to pick two movies and the total duration of the two movies is less than or equal to (d - 30min).

Find the pair of movies with the longest total duration. If multiple found, return the pair with the longest movie.

Input
The input consists of two arguments:

movie_duration: a list of integers representing the duration of movies

d: an integer representing the duration of the flight

Output
return the movies pair.

Examples
Example 1:
Input:
movie_duration = [90, 85, 75, 60, 120, 150, 125]

d = 250

Output: [90, 125]
Explanation:
90min + 125min = 215 is the maximum number within 220 (250min - 30min)

https://leetcode.com/discuss/interview-question/356960
*/
// 知识点： two pointer
// 本质上是 1099. Two Sum Less Than K

class Solution {
    public int twoSumLessThanK(int[] nums, int k) {
        Arrays.sort(nums);
        int answer = -1;
        int left = 0;
        int right = nums.length - 1;
        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum < k) {
                answer = Math.max(answer, sum);
                left++;
            } else {
                right--;
            }
        }
        return answer;
    }
}
```

```java
// Fill the trunk
// 1710. Maximum Units on a Truck
// 知识点 Arrays.sort

class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a, b) -> b[1] - a[1]);
        int totalUnits = 0;
        for(int[] type : boxTypes) {
            if(truckSize > type[0]) {
                totalUnits += type[0] * type[1];
                truckSize -= type[0];
            } else {
                totalUnits += truckSize * type[1];
                break;
            }
        }
        return totalUnits;
    }
}
```

```java
//Find The Highest Profit
// 1648. Sell Diminishing-Valued Colored Balls
// https://algo.monster/problems/find_the_highest_profit
```

```java
// Fetch Items To Display
// https://algo.monster/problems/fetch_items_to_display
```

```
1. two sum题。给一组array， 和一个target。要求返回array里两数之和等于target-30的index。找不到的返回（-1，-1）。按two sum的hash map方法做test case过了11/13。剩下两个是怎么fail的现在也没想通。
2. Maximum Available Disk Space in Segment Minima. 以下链接第8题
https://www.1point3acres.com/bbs/thread-662181-1-1.html
```

```
分享下OA试题题1 类似 leetcode 992. Subarrays with K Different Integers
题2 在美版leetcode讨论区找到了，应该是hackerrank 上的原题 turnstile
https://leetcode.com/discuss/interview-question/699973/Goldman-Sachs-or-OA-or-Turnstile
```



```
OA 
Transaction logs


In- flight media

item grouping

Items in Containers Amazon https://leetcode.com/discuss/interview-question/1148760/Items-in-Containers-Amazon-OA

關於swap的一道新題，就是地裡最近這兩三週都頻繁出現的新題。

Gifting Groups
Optimizing Box Weights
从leetcode discuss里都能搜到，完成直接进入virtual onsite

1. Music Time.  Two Sum类似题目，要求返回结果时不更改原数组顺序
2. Optimal utilization combination. Sort + Two pointer的解法
两个题都要注意处理duplicate value

1167. Minimum Cost to Connect Sticks
https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=763501&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D5%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26searchoption%5B3109%5D%5Bvalue%5D%3D2%26searchoption%5B3109%5D%5Btype%5D%3Dradio%26sortid%3D311%26orderby%3Ddateline

第一题 In-flight media 利口上可搜
第二题 Gifting Groups 利口武寺漆


110分钟两道题，然后每道题要写出时间复杂度和思路
1  类似力扣 散二散
2. 力扣 邀零丝邀

```

### OA1

```
刷题网 就伞漆
2. 卡车送货的题目， 给一个matrix， 里面有1 (可以进入），0（不可以进入）， 9（目的地）。 卡车从左上出发，问到达目的（9） 的最点路径。 用BFS就可以了。


```



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
2. most challenging project

 

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





