# Quick Select

215 Kth Largest Element in an Array



## 973 K Closest Points to Origin

Given an array of `points` where `points[i] = [xi, yi]` represents a point on the **X-Y** plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the **X-Y** plane is the Euclidean distance (i.e., `√(x1 - x2)2 + (y1 - y2)2`).

You may return the answer in **any order**. The answer is **guaranteed** to be **unique** (except for the order that it is in).

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg)

```
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
```

**Example 2:**

```
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
```

**Solution**

```java
class Solution {
    public int[][] kClosest(int[][] points, int K) {
        int len = points.length, l = 0, r = len - 1;
        while(l <= r) {
            int mid = helper(points, l, r);
            if(mid == K) break;
            if(mid < K) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return Arrays.copyOfRange(points, 0, K);
    }
    
    private int helper(int[][] A, int l, int r) {
        int[] pivot = A[l];
        while(l < r) {
            // 从右边找到第一个小于pivot的数
            while(l < r && compare(A[r], pivot) >= 0) {
                r--;
            }
            // l在的位置是指向是一个大于等于pivot的数，可以直接换给它
            A[l] = A[r];
            while(l < r && compare(A[l], pivot) <= 0) {
                l++;
            }
            A[r] = A[l];
        }
        A[l] = pivot;
        return l;
    }
    private int compare(int[] p1, int[] p2) {
    return p1[0] * p1[0] + p1[1] * p1[1] - p2[0] * p2[0] - p2[1] * p2[1];
}
}
```

## 215 Kth Largest Element in an Array

Given an integer array `nums` and an integer `k`, return *the* `kth` *largest element in the array*.

Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

 

**Example 1:**

```
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```

**Example 2:**

```
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```

**Solution**

```java

class Solution {

  public int findKthLargest(int[] nums, int k) {
    int len = nums.length, l = 0, r = len - 1;
    int mid = 0;
    while(l <= r) {
        mid = helper(nums, l, r);
        if(mid == k - 1) break;
        if(mid < k - 1) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return nums[mid];
  }
    
    private int helper(int[] nums, int l, int r) {
        int pivot = nums[l];
        while(l < r) {
            while(l < r && nums[r] <= pivot) {
                r--;
            }
            nums[l] = nums[r];
            while(l < r && nums[l] >= pivot) {
                l++;
            }
            nums[r] = nums[l];
        
        }
        nums[l] = pivot;
        return l;
    }
}
```





# A* search







# Greedy

621 Task Scheduler

Given a characters array `tasks`, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer `n` that represents the cooldown period between two **same tasks** (the same letter in the array), that is that there must be at least `n` units of time between any two same tasks.

Return *the least number of units of times that the CPU will take to finish all the given tasks*.

**Example 1:**

```
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
```

**Example 2:**

```
Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
```

**Example 3:**

```
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
```

**Solution**

为了让cpu 最大限度运行，我们要用round robin， 每种任务执行完一轮在进行下一个

```
["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
A__A__A__A__A__A
ABCADEAFGA__A__A
```



```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
        // frequencies of the tasks
        int[] frequencies = new int[26];
        for (int t : tasks) {
            frequencies[t - 'A']++;
        }

        Arrays.sort(frequencies);

        // max frequency
        int f_max = frequencies[25];
        int idle_time = (f_max - 1) * n;
        
        for (int i = frequencies.length - 2; i >= 0 && idle_time > 0; --i) {
            // 如果最多只能在idle区域放f_max - 1，这样才能保证它能冷却
            idle_time -= Math.min(f_max - 1, frequencies[i]); 
        }
        idle_time = Math.max(0, idle_time);

        return idle_time + tasks.length;
    }
}
```

