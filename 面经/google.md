## Guess the Word

This is an ***interactive problem\***.

You are given an array of **unique** strings `wordlist` where `wordlist[i]` is `6` letters long, and one word in this list is chosen as `secret`.

You may call `Master.guess(word)` to guess a word. The guessed word should have type `string` and must be from the original list with `6` lowercase letters.

This function returns an `integer` type, representing the number of exact matches (value and position) of your guess to the `secret` word. Also, if your guess is not in the given wordlist, it will return `-1` instead.

For each test case, you have exactly `10` guesses to guess the word. At the end of any number of calls, if you have made `10` or fewer calls to `Master.guess` and at least one of these guesses was `secret`, then you pass the test case.

**Example 1:**

```
Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"], numguesses = 10
Output: You guessed the secret word correctly.
Explanation:
master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
We made 5 calls to master.guess and one of them was the secret, so we pass the test case.
```

**Example 2:**

```
Input: secret = "hamada", wordlist = ["hamada","khaled"], numguesses = 10
Output: You guessed the secret word correctly.
```

**TAG**

array

**Solution**

没有特殊的算法

1. pick one word and guess it
2. get the mathes of this word
3. only keep the words with same matches to our guess

难点主要在如何选词

https://leetcode.com/problems/guess-the-word/discuss/133862/Random-Guess-and-Minimax-Guess-with-Comparison

```java
class Solution {
     public int match(String a, String b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i) {
            
            if (a.charAt(i) == b.charAt(i))
                matches ++;
        }
        return matches;
    }
   public void findSecretWord(String[] wordlist, Master master) {
        for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
            String guess = wordlist[new Random().nextInt(wordlist.length)];
            x = master.guess(guess);
            List<String> wordlist2 = new ArrayList<>();
            for (String w : wordlist)
                if (match(guess, w) == x)
                    wordlist2.add(w);
            wordlist = wordlist2.toArray(new String[wordlist2.size()]);
        }
    }
}
```



## Minimum Difference Between Largest and Smallest Value in Three Moves

Given an array `nums`, you are allowed to choose one element of `nums` and change it by any value in one move.

Return the minimum difference between the largest and smallest value of `nums` after perfoming at most 3 moves.

**Example 1:**

```
Input: nums = [5,3,2,4]
Output: 0
Explanation: Change the array [5,3,2,4] to [2,2,2,2].
The difference between the maximum and minimum is 2-2 = 0.
```

**Example 2:**

```
Input: nums = [1,5,0,10,14]
Output: 1
Explanation: Change the array [1,5,0,10,14] to [1,1,0,1,1]. 
The difference between the maximum and minimum is 1-0 = 1.
```

**Example 3:**

```
Input: nums = [6,6,0,1,1,4,6]
Output: 2
```

**Example 4:**

```
Input: nums = [1,5,6,14,15]
Output: 1
```

**Solution**

If we can do 0 move, return max(A) - min(A)
If we can do 1 move, return min(the second max(A) - min(A), the max(A) - second min(A))

So for this problem, we have four plans:

1. kill 3 biggest elements
2. kill 2 biggest elements + 1 smallest elements
3. kill 1 biggest elements + 2 smallest elements
4. kill 3 smallest elements

All three biggest elements can be replaced with 14
[1,5,6,13,14,`15,16,17`] -> [1,5,6,13,14,`14,14,14`] == can be written as `A[n-4] - A[0] == (14-1 = 13)`

Case 2: kill 2 biggest elements + 1 smallest elements

[`1`,5,6,13,14,15,`16,17`] -> [`5`,5,6,13,14,15,`15,15`] == can be written as `A[n-3] - A[1] == (15-5 = 10)`

Case 3: kill 1 biggest elements + 2 smallest elements

[`1,5`,6,13,14,15,16,`17`] -> [`6,6`,6,13,14,15,16,`16`] == can be written as `A[n-2] - A[2] == (16-6 = 10)`

Case 4: kill 3 smallest elements

[`1,5,6`,13,14,15,16,17] -> [`13,13,13`,13,14,15,16,17] == can be written as `A[n-1] - A[3] == (17-13 = 4)`

这个方法需要**sort**, 或者可以用**PriorityQueue** 来找出max4 and min4 这样有更低的时间复杂度 

```java
// sort
public int minDifference(int[] A) {
  int n = A.length, res = Integer.MAX_VALUE;
  if (n < 5) return 0;
  Arrays.sort(A);
  for (int i = 0; i < 4; ++i) {
    res = Math.min(res, A[n - 4 + i] - A[i]);
  }
  return res;
 }
// pq
public int minDifference(int[] nums) {
        int len = nums.length;
        if(len<5){
            return 0;
        }
        PriorityQueue<Integer> max = new  PriorityQueue<Integer>();
        PriorityQueue<Integer> min = new  PriorityQueue<Integer>(Collections.reverseOrder());
        
        for(int i= 0; i<len; i++){
            max.add(nums[i]);
            min.add(nums[i]);
            
            if(max.size()>4){
                max.poll();
                min.poll();
            }
        }
        //input : [20, 75 ,81, 82 ,95 ,100, 200 ,300]
        int[] minA = new int[4]; //[82,81,75,20]
        int[] maxA = new int[4]; //[300,200,100,95]
        for(int i=0,k=3; i<4; i++,k--){
            minA[i] = min.poll();
            maxA[k] = max.poll();
        }
        
        int ans = Integer.MAX_VALUE;
        for(int i=0; i<4; i++){
            ans = Math.min(ans, maxA[i] - minA[i]);
        }
        return ans;
    }
```



## Maximum Points You Can Obtain from Cards

There are several cards **arranged in a row**, and each card has an associated number of points. The points are given in the integer array `cardPoints`.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly `k` cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array `cardPoints` and the integer `k`, return the *maximum score* you can obtain.

**Example 1:**

```
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
```

**Example 2:**

```
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
```

**Example 3:**

```
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
```

**Example 4:**

```
Input: cardPoints = [1,1000,1], k = 1
Output: 1
Explanation: You cannot take the card in the middle. Your best score is 1. 
```

**Example 5:**

```
Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
Output: 202
```

**Solution**

本质就是从左边选x个数，然后右边选y个数。 x + y = k

可以用DB, 用两个array来代表左边的和和右边的和 dpl[i] = sum(0 to i) dpr[i] = sum(i to end)

接下来可以优化space， 并不需要两个array来存，只需要frontScore 和 rearScore 

这样本质就是**sliding windows**

Time: O(n), Space:O(1)

```java
class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int frontScore = 0;
        int rearScore = 0;
        int n = cardPoints.length;

        for (int i = 0; i < k; i++) {
            frontScore += cardPoints[i];
        }

        // take all k cards from the beginning
        int maxScore = frontScore;

        // take i from the beginning and k - i from the end
        for (int i = k - 1; i >= 0; i--) {
            rearScore += cardPoints[n - (k - i)];
            frontScore -= cardPoints[i];
            int currentScore = rearScore + frontScore;
            maxScore = Math.max(maxScore, currentScore);
        }

        return maxScore;
    }
}
```



## Logger Rate Limiter

Design a logger system that receives a stream of messages along with their timestamps. Each **unique** message should only be printed **at most every 10 seconds** (i.e. a message printed at timestamp `t` will prevent other identical messages from being printed until timestamp `t + 10`).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the `Logger` class:

- `Logger()` Initializes the `logger` object.
- `bool shouldPrintMessage(int timestamp, string message)` Returns `true` if the `message` should be printed in the given `timestamp`, otherwise returns `false`.

 

**Example 1:**

```
Input
["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
Output
[null, true, true, false, false, false, true]

Explanation
Logger logger = new Logger();
logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is
                                      // 11 + 10 = 21
```

**Solution**

**OOD**题目

这种题目主要是不同implementation的trade off

最简单的map solution  Time: O(1), Space:O(N) N is number of unique logs 

The disadvantage to this solution is that the memory usage never stops growing.

Use two map  it takes care of keeping memory usage low, and only requires swapping two HashMaps around.

- `O(m)` where `m` is the maximum number of unique message that will be received in a 20 second period.

还可以考虑一下thread safe

```java
class Logger {
 // mapNew keeps the messages of [timeNew, timeNew +10);
// mapOld keeps messages at most 20 seconds before.


    private Map<String, Integer> cacheOld;
    private Map<String, Integer> cacheNew;
    private int latest;

    /** Initialize your data structure here. */
    public Logger() {
        this.cacheOld = new HashMap<String, Integer>();
        this.cacheNew = new HashMap<String, Integer>();
        
        this.latest = 0;
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if(timestamp >= latest + 20){
            cacheOld.clear();
            cacheNew.clear();
            latest = timestamp;
        }else if(timestamp >= latest + 10){
            cacheOld = new HashMap<>(cacheNew);
            cacheNew.clear();
            latest = timestamp;
        }
        
        if(cacheNew.containsKey(message)) return false;
        
        if(cacheOld.containsKey(message)){
            int last = cacheOld.get(message);
            if(last + 10 > timestamp) return false;
        }
        
        cacheNew.put(message, timestamp);
        return true;
    }
}

public class Logger {
    private final HashMap<String, Integer> msgMap;
    private final Object lock;
	
    /** Initialize your data structure here. */
    public Logger() {
    	msgMap = new HashMap<String, Integer>();
    	lock = new Object();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message) {
        Integer ts = msgMap.get(message);
        if (ts == null || timestamp - ts >= 10) {
        	synchronized (lock) {
        		Integer ts2 = msgMap.get(message);
        		if (ts == null || timestamp - ts2 >= 10) {
		            msgMap.put(message, timestamp);
        			return true;
        		}
        	}
         } 

        return false;
    }
}
```



## Max Value of Equation

You are given an array `points` containing the coordinates of points on a 2D plane, sorted by the x-values, where `points[i] = [xi, yi]` such that `xi < xj` for all `1 <= i < j <= points.length`. You are also given an integer `k`.

Return *the maximum value of the equation* `yi + yj + |xi - xj|` where `|xi - xj| <= k` and `1 <= i < j <= points.length`.

It is guaranteed that there exists at least one pair of points that satisfy the constraint `|xi - xj| <= k`.

**Example 1:**

```java
Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
Output: 4
Explanation: The first two points satisfy the condition |xi - xj| <= 1 and if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and fourth points also satisfy the condition and give a value of 10 + -10 + |5 - 6| = 1.
No other pairs satisfy the condition, so we return the max of 4 and 1.
```

**Example 2:**

```java
Input: points = [[0,0],[3,0],[9,2]], k = 3
Output: 3
Explanation: Only the first two points have an absolute difference of 3 or less in the x-values, and give the value of 0 + 0 + |0 - 3| = 3.
```

**Solution**

Because `xi < xj`,
`yi + yj + |xi - xj| = (yi - xi) + (yj + xj)`

So for each pair of `(xj, yj)`,
we have `xj + yj`, and we only need to find out the maximum `yi - xi`.
本质就是**To find out the maximum element in a sliding window**
we can use priority queue or **monotonic stack**

```java
// priority queue
class Solution {
    public int findMaxValueOfEquation(int[][] points, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - b[0] - a[1] + a[0]);
        int res = Integer.MIN_VALUE;
        for (int[] point : points) {
            while (!pq.isEmpty() && point[0] - pq.peek()[0] > k) {
                pq.poll();
            }
            if (!pq.isEmpty()) {
                int[] nodei =  pq.peek();
                res = Math.max(res, nodei[1] - nodei[0] + point[0] + point[1]);
            }
            pq.offer(new int[]{point[0], point[1]});
        }
        return res;
    }
}

//
class Solution {
    public int findMaxValueOfEquation(int[][] points, int k) {
        Deque<int[]> dq = new LinkedList<>();
        int res = Integer.MIN_VALUE;
        for (int[] point : points) {
            while(!dq.isEmpty() && point[0] - dq.peekFirst()[0] > k) {
                dq.pollFirst();
            }
            if(!dq.isEmpty()) {
                int[] i = dq.peekFirst();
                res = Math.max(res, i[1] - i[0] + point[0] + point[1]);
            }
               
            while (!dq.isEmpty() && dq.peekLast()[1] -  dq.peekLast()[0] <= point[1] - point[0]) {
                dq.pollLast();
            }
            dq.addLast(new int[]{point[0], point[1]});
        }
        return res;
    }
}
```





## Maximum Number of Visible Points

You are given an array `points`, an integer `angle`, and your `location`, where `location = [posx, posy]` and `points[i] = [xi, yi]` both denote **integral coordinates** on the X-Y plane.

Initially, you are facing directly east from your position. You **cannot move** from your position, but you can **rotate**. In other words, `posx` and `posy` cannot be changed. Your field of view in **degrees** is represented by `angle`, determining how wide you can see from any given view direction. Let `d` be the amount in degrees that you rotate counterclockwise. Then, your field of view is the **inclusive** range of angles `[d - angle/2, d + angle/2]`.

You can **see** some set of points if, for each point, the **angle** formed by the point, your position, and the immediate east direction from your position is **in your field of view**.

There can be multiple points at one coordinate. There may be points at your location, and you can always see these points regardless of your rotation. Points do not obstruct your vision to other points.

Return *the maximum number of points you can see*.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/30/89a07e9b-00ab-4967-976a-c723b2aa8656.png)

```
Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
Output: 3
Explanation: The shaded region represents your field of view. All points can be made visible in your field of view, including [3,3] even though [2,2] is in front and in the same line of sight.
```

**Example 2:**

```
Input: points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
Output: 4
Explanation: All points can be made visible in your field of view, including the one at your location.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2020/09/30/5010bfd3-86e6-465f-ac64-e9df941d2e49.png)

```
Input: points = [[1,0],[2,1]], angle = 13, location = [1,1]
Output: 1
Explanation: You can only see one of the two points, as shown above.
```

 **Solution**

本质就是 **一个固定好的sliding windows 里面最多能有几个点** 

谷歌非常喜欢故弄玄虚， 先把所有的点转换成角度，然后sort一下

另外一个tricky的点就是circular array， 需要duplicate这个array，不能用mod来模拟，duplicate这部分的需要加360度，因为转了一圈

```java
class Solution {
    public int visiblePoints(List<List<Integer>> points, int angle, List<Integer> location) {
        List<Double> angles = new ArrayList<>();
        int count = 0;
        // transfer point to polar angle with original position
        for(List<Integer> point : points) {
            int dx = point.get(0) - location.get(0);
            int dy = point.get(1) - location.get(1);
            if(dx == 0 && dy == 0) { // edge case of same point
                count++;
                continue;
            }
          // java 求角度
            angles.add(Math.toDegrees(Math.atan2(dy, dx)));
        }
        Collections.sort(angles);
        // it is a circular array, solution is to duplicate the array
        List<Double> tmp = new ArrayList<>(angles);
        for(double d : angles) {
            tmp.add(d + 360);
        }
        int res = 0;
        // sliding windows
        for(int i = 0, j = 0; i < tmp.size() / 2; i++) {
            while(j < tmp.size() && tmp.get(j) - tmp.get(i) <= angle) {
                j++;
            }
            res = Math.max(res, j - i);
            
        }
        return res + count;
    }
}
```



Number of Good Ways to Split a String

You are given a string `s`, a split is called *good* if you can split `s` into 2 non-empty strings `p` and `q` where its concatenation is equal to `s` and the number of distinct letters in `p` and `q` are the same.

Return the number of *good* splits you can make in `s`.

 

**Example 1:**

```
Input: s = "aacaba"
Output: 2
Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
```

**Example 2:**

```
Input: s = "abcd"
Output: 1
Explanation: Split the string as follows ("ab", "cd").
```

**Example 3:**

```
Input: s = "aaaaa"
Output: 4
Explanation: All possible splits are good.
```

**Example 4:**

```
Input: s = "acbadbaada"
Output: 2
```

**Solution**

1, use a arrays or map, rc and lc, to cache counts for each unique charater on right and left subarrays.
2, use l and r to count unique chars on right and left subarrays.
3, init rc with first loop, then update lc and rcwith second loop.
4, in the second loop, if (lc == rc) res++;

```java
class Solution {
    public int numSplits(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for(char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        int count = map.size();
        int result = 0;
        Set<Character> set = new HashSet<>();
        for(int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            set.add(c);
            map.put(c, map.get(c) - 1);
            if(map.get(c) == 0) {
                count--;
            }
            if(count == set.size()) {
                result++;
            }
        }
        return result;   
    }
}
// 更节省空间的办法，本质是一样的
  public int numSplits(String s) {
        int rc[] = new int[26], lc[] = new int[26], l = 0, r = 0, res = 0;
        for (char c : s.toCharArray()) if (rc[c - 'a']++ == 0) r++;
        for (char c : s.toCharArray()) {
            if (lc[c - 'a']++ == 0) l++;
            if (--rc[c - 'a'] == 0) r--;
            if (l == r) res++;
        }
        return res;
    }
```



## Employee Importance

You have a data structure of employee information, which includes the employee's unique id, their importance value, and their direct subordinates' id.

You are given an array of employees `employees` where:

- `employees[i].id` is the ID of the `ith` employee.
- `employees[i].importance` is the importance value of the `ith` employee.
- `employees[i].subordinates` is a list of the IDs of the subordinates of the `ith` employee.

Given an integer `id` that represents the ID of an employee, return *the total importance value of this employee and all their subordinates*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/05/31/emp1-tree.jpg)

```
Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
Output: 11
Explanation: Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3.
They both have importance value 3.
So the total importance value of employee 1 is 5 + 3 + 3 = 11.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/05/31/emp2-tree.jpg)

```
Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
Output: -3
```

**Solution**

一个简单的**dfs or bfs**题目

```java
class Solution {
    Map<Integer, Employee> emap;
    public int getImportance(List<Employee> employees, int queryid) {
        emap = new HashMap();
        for (Employee e: employees) emap.put(e.id, e);
        return dfs(queryid);
    }
    public int dfs(int eid) {
        Employee employee = emap.get(eid);
        int ans = employee.importance;
        for (Integer subid: employee.subordinates)
            ans += dfs(subid);
        return ans;
    }
}
```



## Optimal Account Balancing

You are given an array of transactions `transactions` where `transactions[i] = [fromi, toi, amounti]` indicates that the person with `ID = fromi` gave `amounti $` to the person with `ID = toi`.

Return *the minimum number of transactions required to settle the debt*.

**Example 1:**

```
Input: transactions = [[0,1,10],[2,0,5]]
Output: 2
Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.
Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
```

**Example 2:**

```java
Input: transactions = [[0,1,10],[1,0,1],[1,2,5],[2,0,5]]
Output: 1
Explanation:
Person #0 gave person #1 $10.
Person #1 gave person #0 $1.
Person #1 gave person #2 $5.
Person #2 gave person #0 $5.
Therefore, person #1 only need to give person #0 $4, and all debt is settled.
```



**Solution**

先统计每个人总的debt,debet大于0意味着需要收回钱，debt小于0意味着要给出钱

接下来的问题就是**backtracking or dfs** 这个list 来得到一个全局最优解，最小的交易次数

pruning: 如果一个人的debet 和另外一个人的debet相加正好为0， 这个是最优解，可以提前结束backtracking

Time: 每次backtracking 能缩小一个， O(n!)

```java
class Solution {
      public int minTransfers(int[][] transactions) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int [] t : transactions) {
            map.put(t[0], map.getOrDefault(t[0], 0) + t[2]);
            map.put(t[1], map.getOrDefault(t[1], 0) - t[2]);
        }
        List<Integer> debts = new ArrayList<>();
        for(int v : map.values()) {
            if(v != 0) {
                debts.add(v);
            }
        }

        return dfs(0, debts);
    }

    private int dfs(int start, List<Integer> debts) {
        // base case
        // 到达list的end
        if(start == debts.size()) {
            return 0;
        }
        // 当前的人已经settled down了
        int cur = debts.get(start);
        if(cur == 0) {
            return dfs(start + 1, debts);
        }
        int result = Integer.MAX_VALUE;
        for(int i = start + 1; i < debts.size(); ++i) {
            int next = debts.get(i);
            if(cur * next < 0) {
                // 两个人之间settled down
                debts.set(i, cur + next);
                result = Math.min(result, 1 + dfs(start + 1, debts));
                // reverse
                debts.set(i, next);
                // 减枝
                if(cur + next == 0) {
                    break;
                }
            }
        }
        return result;
     }
}
```



## Unique Paths

A robot is located at the top-left corner of a `m x n` grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

```
Input: m = 3, n = 7
Output: 28
```

**Example 2:**

```
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

**Example 3:**

```
Input: m = 7, n = 3
Output: 28
```

**Example 4:**

```
Input: m = 3, n = 3
Output: 6
```

**Solution**

最典型的**dynamic programming**

从上到下走就行

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] d = new int[m][n];
        for(int [] arr : d) {
            Arrays.fill(arr, 1);
        }
        for(int col = 1; col < m; ++col) {
            for(int row = 1; row < n; ++row) {
                d[col][row] = d[col - 1][row] + d[col][row - 1];
            }
        }
        return d[m - 1][n - 1];
    }
}
```



## The Maze

There is a ball in a `maze` with empty spaces (represented as `0`) and walls (represented as `1`). The ball can go through the empty spaces by rolling **up, down, left or right**, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the `m x n` `maze`, the ball's `start` position and the `destination`, where `start = [startrow, startcol]` and `destination = [destinationrow, destinationcol]`, return `true` if the ball can stop at the destination, otherwise return `false`.

You may assume that **the borders of the maze are all walls** (see examples).

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/31/maze1-1-grid.jpg)

```
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/31/maze1-2-grid.jpg)

```
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
```

**Example 3:**

```
Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false
```

**Solution**

1. 走迷宫的题目，唯一trick的地方就是不是一步一步走，而是走到头为止
2. Time complexity : O(mn)*O*(*m**n*). Complete traversal of maze will be done in the worst case. Here, m*m* and n*n* refers to the number of rows and coloumns of the maze.
3. Space complexity : O(mn)*O*(*m**n*). visited*v**i**s**i**t**e**d* array of size m*n*m*∗*n* is used and queue*q**u**e**u**e* size can grow upto m*n*m*∗*n* in worst case.

```java
class Solution {
    boolean[][] visited;
    int rows;
    int cols;
    int[][] directions = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        rows = maze.length;
        cols = maze[0].length;
        visited = new boolean[rows][cols];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(start);
        while(queue.size() > 0) {
            int[] pos = queue.poll();
            int row = pos[0];
            int col = pos[1];
            if(row == destination[0] && col == destination[1]) {
                return true;
            }
            if(!visited[row][col]) {
                for(int[] direction : directions) {
                    // rolling the ball
                    int nRow = row;
                    int nCol = col;
                    while(nRow + direction[0] < rows && nRow + direction[0] >= 0 && nCol + direction[1] < cols && nCol + direction[1] >= 0 
                            && maze[nRow + direction[0]][nCol + direction[1]] == 0) {
                        nRow += direction[0];
                        nCol += direction[1];
                    }
                    queue.add(new int[]{nRow, nCol});

                }
            }
            visited[row][col] = true;
        }
        return false;
    }
}
```



## Longest Increasing Path in a Matrix

Given an `m x n` integers `matrix`, return *the length of the longest increasing path in* `matrix`.

From each cell, you can either move in four directions: left, right, up, or down. You **may not** move **diagonally** or move **outside the boundary** (i.e., wrap-around is not allowed).

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg)

```
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg)

```
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
```

**Example 3:**

```
Input: matrix = [[1]]
Output: 1
```



**Solution**

**DFS + Memoization**

- Time complexity : O(mn) Each vertex/cell will be calculated once and only once, and each edge will be visited once and only once. 
- Space complexity : O(mn) The cache dominates the space complexity.

```java
class Solution {
    int[][] dp;
    int[][] directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int rows;
    int cols;
    public int longestIncreasingPath(int[][] matrix) {
        rows = matrix.length;
        cols = matrix[0].length;
        // longest increasing path starting in int[i][j]
        dp = new int[rows][cols];
        int result = 1;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                result = Math.max(result, dfs(i, j, matrix));
            }
        }
        return result;
    }
    
    private int dfs(int row, int col, int[][] matrix) {
        if(dp[row][col] != 0) {
            return dp[row][col];
        }
        int result = 1;
        for(int[] d : directions) {
            int r = row + d[0];
            int c = col + d[1];
            if(r < rows && c < cols && r >= 0 && c >=0 && matrix[r][c] > matrix[row][col]) {
                result = Math.max(result, 1 + dfs(r, c, matrix));
            }
        }
        dp[row][col] = result;
        return result;
    }
}
```





##  Finding MK Average

You are given two integers, `m` and `k`, and a stream of integers. You are tasked to implement a data structure that calculates the **MKAverage** for the stream.

The **MKAverage** can be calculated using these steps:

1. If the number of the elements in the stream is less than `m` you should consider the **MKAverage** to be `-1`. Otherwise, copy the last `m` elements of the stream to a separate container.
2. Remove the smallest `k` elements and the largest `k` elements from the container.
3. Calculate the average value for the rest of the elements **rounded down to the nearest integer**.

Implement the `MKAverage` class:

- `MKAverage(int m, int k)` Initializes the **MKAverage** object with an empty stream and the two integers `m` and `k`.
- `void addElement(int num)` Inserts a new element `num` into the stream.
- `int calculateMKAverage()` Calculates and returns the **MKAverage** for the current stream **rounded down to the nearest integer**.

 

**Example 1:**

```
Input
["MKAverage", "addElement", "addElement", "calculateMKAverage", "addElement", "calculateMKAverage", "addElement", "addElement", "addElement", "calculateMKAverage"]
[[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
Output
[null, null, null, -1, null, 3, null, null, null, 5]

Explanation
MKAverage obj = new MKAverage(3, 1); 
obj.addElement(3);        // current elements are [3]
obj.addElement(1);        // current elements are [3,1]
obj.calculateMKAverage(); // return -1, because m = 3 and only 2 elements exist.
obj.addElement(10);       // current elements are [3,1,10]
obj.calculateMKAverage(); // The last 3 elements are [3,1,10].
                          // After removing smallest and largest 1 element the container will be [3].
                          // The average of [3] equals 3/1 = 3, return 3
obj.addElement(5);        // current elements are [3,1,10,5]
obj.addElement(5);        // current elements are [3,1,10,5,5]
obj.addElement(5);        // current elements are [3,1,10,5,5,5]
obj.calculateMKAverage(); // The last 3 elements are [5,5,5].
                          // After removing smallest and largest 1 element the container will be [5].
                          // The average of [5] equals 5/1 = 5, return 5
```

**Solution**

**TreeMap**

维护三个treeMap, top, middle, bottom, 每次插入都要让他们三者保持平衡，或者将平衡的逻辑放到calculateMKAverage() 里可以，取决于哪个method用的多

```java
class MKAverage {
    TreeMap<Integer, Integer> top = new TreeMap<>(), middle = new TreeMap<>(), bottom = new TreeMap<>();
    Queue<Integer> q = new LinkedList<>();
    long middleSum;
    int m, k;
    int countTop, countBottom;
    public MKAverage(int m, int k) {
        this.m = m;
        this.k = k;
    }
    
    public void addElement(int num) {
        if (q.size() == m) {
            int pop = q.poll();
            if (top.containsKey(pop)) { // delete item in top, if present
                remove(top, pop); 
                countTop--;
            } else if (middle.containsKey(pop)) { // delete item in bottom, if present
                remove(middle, pop);
                middleSum -= pop;
            } else { // delete item in bottom, if present
                remove(bottom, pop); 
                countBottom--;
            }
        } 
        // insert to middle first
      // 其实先加入哪个都行
        add(middle, num);
        q.offer(num);
        middleSum += num;
        // move item from middle to top, to fill k slots
        while (countTop < k && !middle.isEmpty()) {
            countTop++;
            middleSum -= middle.lastKey();
            add(top, remove(middle, middle.lastKey()));
        }
        // rebalance middle and top
        while (!middle.isEmpty() && !top.isEmpty() && top.firstKey() < middle.lastKey()) {
            middleSum += top.firstKey();
            add(middle, remove(top, top.firstKey()));
            middleSum -= middle.lastKey();
            add(top, remove(middle, middle.lastKey()));
        }
        // move item from middle to bottom, to fill k slots
        while (countBottom < k && !middle.isEmpty()) {
            countBottom++;
            middleSum -= middle.firstKey();
            add(bottom, remove(middle, middle.firstKey()));
        }
        // rebalance middle and bottom
        while (!middle.isEmpty() && !bottom.isEmpty() && bottom.lastKey() > middle.firstKey()) {
            middleSum += bottom.lastKey();
            add(middle, remove(bottom, bottom.lastKey()));
            middleSum -= middle.firstKey();
            add(bottom, remove(middle, middle.firstKey()));
        }
    }
    
    
    private int remove(TreeMap<Integer, Integer> tm, int num) {
        tm.put(num, tm.get(num) - 1);
        if (tm.get(num) == 0) tm.remove(num); 
        return num;
    }
    
    private void add(TreeMap<Integer, Integer> tm, int num) {
        tm.put(num, tm.getOrDefault(num, 0) + 1);
    }
    
    public int calculateMKAverage() {
        return q.size() == m ? (int)(middleSum / (m - 2 * k)) : -1;
    }
}

```



## Car Fleet

`N` cars are going to the same destination along a one lane road. The destination is `target` miles away.

Each car `i` has a constant speed `speed[i]` (in miles per hour), and initial position `position[i]` miles towards the target along the road.

A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.

The distance between these two cars is ignored - they are assumed to have the same position.

A *car fleet* is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.


How many car fleets will arrive at the destination?

**Example 1:**

```
Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 and 8 become a fleet, meeting each other at 12.
The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
The cars starting at 5 and 3 become a fleet, meeting each other at 6.
Note that no other cars meet these fleets before the destination, so the answer is 3.
```

**Solution**

首先按照合并成一个**array**， 然后按照position的大小来**sort**

接下来从后往前检查当前的车能否追上它后面的车，如果能则舍弃当前的车，不能则将后面的车替换成它

```java
class Solution {
      public int carFleet(int target, int[] position, int[] speed) {
        if(position.length == 0) return 0;
        List<double[]> list = new ArrayList<>();
        for(int i = 0; i < position.length; ++i) {
            list.add(new double[]{position[i], speed[i]});
        }
        // 不能用 a[0] - b[0] 来当comparator 因为要返回int
        Collections.sort(list, (a, b) -> Double.compare(a[0], b[0]));
        double[] lastCar = list.get(list.size() - 1);
        int result = 1;
        for(int i = list.size() - 2; i >= 0; --i) {
            double[] currentCar = list.get(i);
            double meetPoint = (lastCar[0] - currentCar[0]) / (currentCar[1] - lastCar[1]) * lastCar[1] + lastCar[0];
            if(currentCar[1] <= lastCar[1] || meetPoint  > target) {
                    lastCar = currentCar;
                    result++;
            }
        }
        return result;
    }
}
```



## Car Fleet II

There are `n` cars traveling at different speeds in the same direction along a one-lane road. You are given an array `cars` of length `n`, where `cars[i] = [positioni, speedi]` represents:

- `positioni` is the distance between the `ith` car and the beginning of the road in meters. It is guaranteed that `positioni < positioni+1`.
- `speedi` is the initial speed of the `ith` car in meters per second.

For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the **slowest** car in the fleet.

Return an array `answer`, where `answer[i]` is the time, in seconds, at which the `ith` car collides with the next car, or `-1` if the car does not collide with the next car. Answers within `10-5` of the actual answers are accepted.

 

**Example 1:**

```
Input: cars = [[1,2],[2,1],[4,3],[7,2]]
Output: [1.00000,-1.00000,3.00000,-1.00000]
Explanation: After exactly one second, the first car will collide with the second car, and form a car fleet with speed 1 m/s. After exactly 3 seconds, the third car will collide with the fourth car, and form a car fleet with speed 2 m/s.
```

**Example 2:**

```
Input: cars = [[3,4],[5,4],[6,3],[9,1]]
Output: [2.00000,1.00000,1.50000,-1.00000]
```

**Solution**

**Monotonic stack**

```java
class Solution {
     public double[] getCollisionTimes(int[][] A) {
        int n = A.length;
        Deque<Integer> stack = new LinkedList<>();
        double[] res = new double[n];
        for (int i = n - 1; i >= 0; --i) {
            res[i] = -1.0;
            int p = A[i][0], s = A[i][1];
            while (stack.size() > 0) {
                int j = stack.peekLast(), p2 = A[j][0], s2 = A[j][1];
                // 两种情况可以不用考虑 p2
                // 当前车速度比p2慢
                // 在追上p2之前， p2已经追上别的车了
                if (s <= s2 || 1.0 * (p2 - p) / (s - s2) >= res[j] && res[j] > 0)
                    stack.pollLast();
                else
                    break;
            }
            if (stack.size() > 0) {
                int j = stack.peekLast(), p2 = A[j][0], s2 = A[j][1];
                res[i] = 1.0 * (p2 - p) / (s - s2);
            }
            stack.add(i);
        }
        return res;
    }
}
```



## The Most Similar Path in a Graph

We have `n` cities and `m` bi-directional `roads` where `roads[i] = [ai, bi]` connects city `ai` with city `bi`. Each city has a name consisting of exactly 3 upper-case English letters given in the string array `names`. Starting at any city `x`, you can reach any city `y` where `y != x` (i.e. the cities and the roads are forming an undirected connected graph).

You will be given a string array `targetPath`. You should find a path in the graph of the **same length** and with the **minimum edit distance** to `targetPath`.

You need to return *the order of the nodes in the path with the minimum edit distance*, The path should be of the same length of `targetPath` and should be valid (i.e. there should be a direct road between `ans[i]` and `ans[i + 1]`). If there are multiple answers return any one of them.

The **edit distance** is defined as follows:

![img](https://assets.leetcode.com/uploads/2020/08/08/edit.jpg)

**Follow-up:** If each node can be visited only once in the path, What should you change in your solution?

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/08/08/e1.jpg)

```
Input: n = 5, roads = [[0,2],[0,3],[1,2],[1,3],[1,4],[2,4]], names = ["ATL","PEK","LAX","DXB","HND"], targetPath = ["ATL","DXB","HND","LAX"]
Output: [0,2,4,2]
Explanation: [0,2,4,2], [0,3,0,2] and [0,3,1,2] are accepted answers.
[0,2,4,2] is equivalent to ["ATL","LAX","HND","LAX"] which has edit distance = 1 with targetPath.
[0,3,0,2] is equivalent to ["ATL","DXB","ATL","LAX"] which has edit distance = 1 with targetPath.
[0,3,1,2] is equivalent to ["ATL","DXB","PEK","LAX"] which has edit distance = 1 with targetPath.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/08/08/e2.jpg)

```
Input: n = 4, roads = [[1,0],[2,0],[3,0],[2,1],[3,1],[3,2]], names = ["ATL","PEK","LAX","DXB"], targetPath = ["ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX"]
Output: [0,1,0,1,0,1,0,1]
Explanation: Any path in this graph has edit distance = 8 with targetPath.
```

**Example 3:**

**![img](https://assets.leetcode.com/uploads/2020/08/09/e3.jpg)**

```
Input: n = 6, roads = [[0,1],[1,2],[2,3],[3,4],[4,5]], names = ["ATL","PEK","LAX","ATL","DXB","HND"], targetPath = ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
Output: [3,4,5,4,3,2,1]
Explanation: [3,4,5,4,3,2,1] is the only path with edit distance = 0 with targetPath.
It's equivalent to ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
```



------



## Sentence Screen Fitting

Given a `rows x cols` screen and a `sentence` represented as a list of strings, return *the number of times the given sentence can be fitted on the screen*.

The order of words in the sentence must remain unchanged, and a word cannot be split into two lines. A single space must separate two consecutive words in a line.

**Example 1:**

```java
Input: sentence = ["hello","world"], rows = 2, cols = 8
Output: 1
Explanation:
hello---
world---
The character '-' signifies an empty space on the screen.
```

**Example 2:**

```java
Input: sentence = ["a", "bcd", "e"], rows = 3, cols = 6
Output: 2
Explanation:
a-bcd- 
e-a---
bcd-e-
The character '-' signifies an empty space on the screen.
```

**Example 3:**

```java
Input: sentence = ["i","had","apple","pie"], rows = 4, cols = 5
Output: 1
Explanation:
i-had
apple
pie-i
had--
The character '-' signifies an empty space on the screen.
```

**Solution**

回头在理解一下这个题目，分类只能说有点**dp**的意思

很难理解这个题的solution 

一个比较好理解的solution：
存下以每个单词开头，这一行能放下几个单词， 然后遍历所有的rows。这样能把time complexity 缩小 O(n)

```java

class Solution {
    public int wordsTyping(String[] sentence, int rows, int cols) {
        int n = sentence.length;
        int[] dp = new int[n];
        // 计算以sentence[i] 开头的，一行，能存多少个word；
        for(int i = 0; i < n; i++) {
            int length = 0, words = 0, index = i;
            while(length + sentence[index % n].length() <= cols) {
                length += sentence[index % n].length();
                length++; // space;
                words++;
                index++;
            }
            dp[i] = words;
        }
        
        // 计算总共能存多少个words，最后除以n, 就是重复的遍数；
        int words = 0;
        for(int i = 0, index = 0; i < rows; i++) {
            words += dp[index];
            index = (dp[index] + index) % n;
        }
        return words / n;
    }
}

```



------



##  Longest String Chain

You are given an array of `words` where each word consists of lowercase English letters.

`wordA` is a **predecessor** of `wordB` if and only if we can insert **exactly one** letter anywhere in `wordA` **without changing the order of the other characters** to make it equal to `wordB`.

- For example, `"abc"` is a **predecessor** of `"abac"`, while `"cba"` is not a **predecessor** of `"bcad"`.

A **word chain** is a sequence of words `[word1, word2, ..., wordk]` with `k >= 1`, where `word1` is a **predecessor** of `word2`, `word2` is a **predecessor** of `word3`, and so on. A single word is trivially a **word chain** with `k == 1`.

Return *the **length** of the **longest possible word chain** with words chosen from the given list of* `words`.

 

**Example 1:**

```
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
```

**Example 2:**

```
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
```

**Example 3:**

```
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
```

**Solution**

**Dynamic Programming**

其实应该是dfs + memorization 

这个题从后往前要简单一点，我们用一个array 来记录以这个单词结尾的最长chain，对每个单词做一个dfs

```java
class Solution {
    Map<String, Integer> dp;
    Set<String> set;
    public int longestStrChain(String[] words) {
        int num = words.length;
        set = new HashSet<>();
        for(String word : words) {
            set.add(word);
        }
        dp = new HashMap<>();
        int result = 0;
        for(String word : words) {
            result = Math.max(result, dfs(word));
        }
        return result;
        
    }
    
    private int dfs(String s) {
        if(s.length() == 0) {
            return 0;
        }
        if(dp.containsKey(s)) {
            return dp.get(s);
        }
        int res = 1;
        for(int i = 0; i < s.length(); ++i) {
            String next = s.substring(0, i) + s.substring(i + 1);
            if(set.contains(next)) {
                res = Math.max(res, dfs(next) + 1);
            }
        }
        dp.put(s, res);
        return res;
    }
    
}
```



------



## Count Square Submatrices with All Ones

Given a `m * n` matrix of ones and zeros, return how many **square** submatrices have all ones.

**Example 1:**

```java
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
```

**Example 2:**

```java
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
```

**Solution**

这个是个标准的**dp**问题

dp代表了以[i, j]为右下角的matrix的数量

[i, j] = min([i - 1, j], [i, j - 1], [i -1 , j - 1]) + 1

```java
class Solution {
    int[][] directions = {{-1, 0}, {0, -1}, {-1, -1}};
    public int countSquares(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        // 代表以[i, j]为右下角的matrix 有几个
        int[][] dp = new int[rows][cols];
        
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    int count = Integer.MAX_VALUE;
                    for(int[] d : directions) {
                        int row = i + d[0];
                        int col = j + d[1];
                        if(row >=0 && col >=0 && row < rows && col < cols) {
                            count = Math.min(count, dp[row][col]);
                        } else {
                            count = 0;
                            break;
                        }
                    }
                    dp[i][j] = count + 1;
                }
            }
        }
        
        int result = 0;
        for(int[] row : dp) {
            for(int count : row) {
                result += count;
            }
        }
        return result;
    }
}
```



------



## The Most Similar Path in a Graph

We have `n` cities and `m` bi-directional `roads` where `roads[i] = [ai, bi]` connects city `ai` with city `bi`. Each city has a name consisting of exactly 3 upper-case English letters given in the string array `names`. Starting at any city `x`, you can reach any city `y` where `y != x` (i.e. the cities and the roads are forming an undirected connected graph).

You will be given a string array `targetPath`. You should find a path in the graph of the **same length** and with the **minimum edit distance** to `targetPath`.

You need to return *the order of the nodes in the path with the minimum edit distance*, The path should be of the same length of `targetPath` and should be valid (i.e. there should be a direct road between `ans[i]` and `ans[i + 1]`). If there are multiple answers return any one of them.

The **edit distance** is defined as follows:

![img](https://assets.leetcode.com/uploads/2020/08/08/edit.jpg)

**Follow-up:** If each node can be visited only once in the path, What should you change in your solution?

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/08/08/e1.jpg)

```java
Input: n = 5, roads = [[0,2],[0,3],[1,2],[1,3],[1,4],[2,4]], names = ["ATL","PEK","LAX","DXB","HND"], targetPath = ["ATL","DXB","HND","LAX"]
Output: [0,2,4,2]
Explanation: [0,2,4,2], [0,3,0,2] and [0,3,1,2] are accepted answers.
[0,2,4,2] is equivalent to ["ATL","LAX","HND","LAX"] which has edit distance = 1 with targetPath.
[0,3,0,2] is equivalent to ["ATL","DXB","ATL","LAX"] which has edit distance = 1 with targetPath.
[0,3,1,2] is equivalent to ["ATL","DXB","PEK","LAX"] which has edit distance = 1 with targetPath.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/08/08/e2.jpg)

```java
Input: n = 4, roads = [[1,0],[2,0],[3,0],[2,1],[3,1],[3,2]], names = ["ATL","PEK","LAX","DXB"], targetPath = ["ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX"]
Output: [0,1,0,1,0,1,0,1]
Explanation: Any path in this graph has edit distance = 8 with targetPath.
```

**Example 3:**

**![img](https://assets.leetcode.com/uploads/2020/08/09/e3.jpg)**

```java
Input: n = 6, roads = [[0,1],[1,2],[2,3],[3,4],[4,5]], names = ["ATL","PEK","LAX","ATL","DXB","HND"], targetPath = ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
Output: [3,4,5,4,3,2,1]
Explanation: [3,4,5,4,3,2,1] is the only path with edit distance = 0 with targetPath.
It's equivalent to ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
```

**Solution**

```
```







------



## Range Module

A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented as **half-open intervals** and query about them.

A **half-open interval** `[left, right)` denotes all the real numbers `x` where `left <= x < right`.

Implement the `RangeModule` class:

- `RangeModule()` Initializes the object of the data structure.
- `void addRange(int left, int right)` Adds the **half-open interval** `[left, right)`, tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval `[left, right)` that are not already tracked.

- `boolean queryRange(int left, int right)` Returns `true` if every real number in the interval `[left, right)` is currently being tracked, and `false` otherwise.

- `void removeRange(int left, int right)` Stops tracking every real number currently being tracked in the **half-open interval** `[left, right)`.

 

**Example 1:**

```
Input
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
Output
[null, null, null, true, false, true]

Explanation
RangeModule rangeModule = new RangeModule();
rangeModule.addRange(10, 20);
rangeModule.removeRange(14, 16);
rangeModule.queryRange(10, 14); // return True,(Every number in [10, 14) is being tracked)
rangeModule.queryRange(13, 15); // return False,(Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
rangeModule.queryRange(16, 17); // return True, (The number 16 in [16, 17) is still being tracked, despite the remove operation)
```

**Solution**

**TreeMap** 应用的一个例子

需要多重温几遍 

```java
class RangeModule {
    TreeMap<Integer, Integer> intervals = new TreeMap<>();
    
    public void addRange(int left, int right) {
        Integer start = intervals.floorKey(left);
        Integer end = intervals.floorKey(right);
        if(start != null && intervals.get(start) >= left){
            left = start;
        }
        if(end != null && intervals.get(end) > right){
            right = intervals.get(end);
        }
        intervals.put(left, right);
       
        intervals.subMap(left, false, right, true).clear();
    }
    
    public boolean queryRange(int left, int right) {
        Integer start = intervals.floorKey(left);
        if(start == null) return false;
        return intervals.get(start) >= right;
    }
    
    public void removeRange(int left, int right) {
        Integer start = intervals.floorKey(left);
        Integer end = intervals.floorKey(right);

        if(end != null && intervals.get(end) > right){
            intervals.put(right, intervals.get(end));
        }
        if(start != null && intervals.get(start) > left){
            intervals.put(start, left);
        }
        intervals.subMap(left, true, right, false).clear();
    }
}

```



------



## Shortest Path in a Grid with Obstacles Elimination

Given a `m * n` grid, where each cell is either `0` (empty) or `1` (obstacle). In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner `(0, 0)` to the lower right corner `(m-1, n-1)` given that you can eliminate **at most** `k` obstacles. If it is not possible to find such walk return -1.

**Example 1:**

```java
Input: 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]], 
k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10. 
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
```

**Example 2:**

```java
Input: 
grid = 
[[0,1,1],
 [1,1,1],
 [1,0,0]], 
k = 1
Output: -1
Explanation: 
We need to eliminate at least two obstacles to find such a walk.
```

**Solution**

**bfs** 多了一个步数的变量。问题的关键就是如何记录visited过的点

将步数也作为一部分，所以visited 是一个三维数组

```java
class Solution {
    int[] dirs = {0, 1, 0, -1, 0};
    public int shortestPath(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        boolean[][][] visited = new boolean[m][n][Math.min(m * n, k) + 1];
        visited[0][0][0] = true;
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0, 0, 0, 0));
        while (!q.isEmpty()) {
            Node top = q.poll();
            if (top.r == m - 1 && top.c == n - 1) return top.dist; // Found the result
            for (int i = 0; i < 4; i++) {
                int nr = top.r + dirs[i], nc = top.c + dirs[i + 1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nk = top.k + grid[nr][nc]; // Number of the obstacles elimination so far
                    if (nk <= k && !visited[nr][nc][nk]) {
                        visited[nr][nc][nk] = true;
                        q.offer(new Node(nr, nc, nk, top.dist + 1));
                    }
                }
            }
        }
        return -1; // Not found
    }

    class Node {
        int r, c, k, dist;
        Node(int r, int c, int k, int dist) {this.r = r; this.c = c; this.k = k; this.dist = dist;}
    }
}
```



------



## Stone Game III

Alice and Bob continue their games with piles of stones. There are several stones **arranged in a row**, and each stone has an associated value which is an integer given in the array `stoneValue`.

Alice and Bob take turns, with **Alice** starting first. On each player's turn, that player can take **1, 2 or 3 stones** from the **first** remaining stones in the row.

The score of each player is the sum of values of the stones taken. The score of each player is **0** initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob **play optimally**.

Return *"Alice"* if Alice will win, *"Bob"* if Bob will win or *"Tie"* if they end the game with the same score.

 

**Example 1:**

```
Input: values = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
```

**Example 2:**

```
Input: values = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. The next move Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. The next move Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.
```

**Example 3:**

```
Input: values = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.
```

**Example 4:**

```
Input: values = [1,2,3,-1,-2,-3,7]
Output: "Alice"
```

**Example 5:**

```
Input: values = [-1,-2,-3]
Output: "Tie"
```



**Solution**

二维**dp**问题 

```
dp[i][j] 代表了j玩家起手在i的时候的total count
0代表alice， 1代表bob alice拿的score 是正的，bob则对的是负的， 所以大于0是Alice赢，等于0是平局，小于0是bob赢
一共能拿0 - 3个石头，所以我们只要对应的把logic写出来就行了
```



```java
class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int len = stoneValue.length;
        // 0 - Alice, 1 Bob 
        int[][] dp = new int[len][2];
        // initialization
        dp[len - 1][0] += stoneValue[len - 1];
        dp[len - 1][1] -= stoneValue[len - 1];

        for(int i = len - 2; i >= 0; --i) {
            int aliceCount = 0;
            int bobCount = 0;
            dp[i][0] = Integer.MIN_VALUE;
            dp[i][1] = Integer.MAX_VALUE;
            for(int j = 0; j <= 2; ++j) {
                if (i + j < len) {
                    aliceCount += stoneValue[i + j];
                    int nextBob = i + j + 1 < len ? dp[i + j + 1][1] : 0;
                    dp[i][0] = Math.max(aliceCount + nextBob, dp[i][0]);

                    bobCount -= stoneValue[i + j];
                    int nextAlice = i + j + 1 < len ? dp[i + j + 1][0] : 0;
                    dp[i][1] = Math.min(bobCount + nextAlice, dp[i][1]);
                }
            }
        }

        if(dp[0][0] > 0) {
            return "Alice";
        } else if(dp[0][0] == 0) {
            return "Tie";
        } else {
            return "Bob";
        }

    }
}
```



------



## Minimum Number of Increments on Subarrays to Form a Target Array

Given an array of positive integers `target` and an array `initial` of same size with all zeros.

Return the minimum number of operations to form a `target` array from `initial` if you are allowed to do the following operation:

- Choose **any** subarray from `initial` and increment each value by one.

The answer is guaranteed to fit within the range of a 32-bit signed integer.

 

**Example 1:**

```
Input: target = [1,2,3,2,1]
Output: 3
Explanation: We need at least 3 operations to form the target array from the initial array.
[0,0,0,0,0] increment 1 from index 0 to 4 (inclusive).
[1,1,1,1,1] increment 1 from index 1 to 3 (inclusive).
[1,2,2,2,1] increment 1 at index 2.
[1,2,3,2,1] target array is formed.
```

**Example 2:**

```
Input: target = [3,1,1,2]
Output: 4
Explanation: (initial)[0,0,0,0] -> [1,1,1,1] -> [1,1,1,2] -> [2,1,1,2] -> [3,1,1,2] (target).
```

**Example 3:**

```
Input: target = [3,1,5,4,2]
Output: 7
Explanation: (initial)[0,0,0,0,0] -> [1,1,1,1,1] -> [2,1,1,1,1] -> [3,1,1,1,1] 
                                  -> [3,1,2,2,2] -> [3,1,3,3,2] -> [3,1,4,4,2] -> [3,1,5,4,2] (target).
```

**Example 4:**

```
Input: target = [1,1,1,1]
Output: 1
```

**Solution**

**dp** 

```java
class Solution {
    public int minNumberOperations(int[] target) {
        int len = target.length;
        // dp[i] the increaments needs for the array ends in i trasforming to target
        int[] dp = new int[len];
        dp[0] = target[0];
        for(int i = 1; i < len; ++i) {
          // 要是左边的值比右边大，那当前的i可以跟着左边一起走而不消耗额外的步数
          // 比左边小，那就要额外的步数来达到目标值
            if(target[i] > target[i - 1]) {
              
                dp[i] = dp[i - 1] + target[i] - target[i - 1];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[len - 1];
        
    }
}
```

