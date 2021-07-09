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
we can use priority queue or stack.

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

 