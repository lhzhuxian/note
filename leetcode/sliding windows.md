## 992 Subarrays with K Different Integers

Given an array `nums` of positive integers, call a (contiguous, not necessarily distinct) subarray of `nums` *good* if the number of different integers in that subarray is exactly `k`.

(For example, `[1,2,3,1,2]` has `3` different integers: `1`, `2`, and `3`.)

Return the number of good subarrays of `nums`.

**Example 1:**

```
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
```

**Example 2:**

```
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
```

**Solution**

很难理解，需要多看几遍

```java
// https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/235235/C%2B%2BJava-with-picture-prefixed-sliding-window

public int subarraysWithKDistinct(int[] A, int K) {
  int res = 0, prefix = 0;
  int[] m = new int[A.length + 1];
  for (int i = 0, j = 0, cnt = 0; i < A.length; ++i) {
    if (m[A[i]]++ == 0) ++cnt;
    if (cnt > K) {
      --m[A[j++]]; --cnt; prefix = 0; 
    }
    while (m[A[j]] > 1) {
      ++prefix; --m[A[j++]]; 
    }
    if (cnt == K) res += prefix + 1;
  }
  return res;
} 

// https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/523136/JavaC%2B%2BPython-Sliding-Window
public class SubarraysWithKDifferentIntegers {
    public int subarraysWithKDistinct(int[] nums, int k) {
        return subarraysWithAtMostK(nums, k) - subarraysWithAtMostK(nums, k - 1);
    }

    int subarraysWithAtMostK(int[] nums, int k) {
        int i = 0, res = 0;
        Map<Integer, Integer> count = new HashMap<>();
        for(int j = 0; j < nums.length; ++j) {
            if(count.getOrDefault(nums[j], 0) == 0) {
                k--;
            }
            count.put(nums[j], count.getOrDefault(nums[j], 0) + 1);
            while(k < 0) {
                count.put(nums[i], count.get(nums[i]) - 1);
                if(count.get(nums[i]) == 0) {
                    k++;
                }
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }

}


```



## 128 Longest Consecutive Sequence

Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence.*

You must write an algorithm that runs in `O(n)` time.

**Example 1:**

```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

**Example 2:**

```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

 **Solution**

tricky的地方在这个会有duplicate element，需要用一个count来记录重复的数字

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        Arrays.sort(nums);
        int i = 0, j = 1;
        int result = 1;
        int count = 0;
        while(j < nums.length) {
            if(nums[j] - nums[j - 1] == 1) {
                result = Math.max(j - i + 1 - count, result);
            } else if(nums[j] == nums[j - 1]){
                count++;
            } else {
                i = j;
                count = 0;
            }
            j++;
        }
        return result;
    }
}
```



3. Longest Substring Without Repeating Characters
   https://leetcode.com/problems/lo ... peating-characters/

4. Container With Most Water
   https://leetcode.com/problems/container-with-most-water/

5. Minimum Window Substring
   https://leetcode.com/problems/minimum-window-substring/

6. Minimum Size Subarray Sum
   https://leetcode.com/problems/minimum-size-subarray-sum/

7. Sliding Window Maximum
   https://leetcode.com/problems/sliding-window-maximum/

8. Subarray Product Less Than K
   https://leetcode.com/problems/subarray-product-less-than-k/

9. Longest Substring with At Least K Repeating Characters
   https://leetcode.com/problems/lo ... peating-characters/

10. Sliding Window Median
    https://leetcode.com/problems/sliding-window-median/

11. Permutation in String
    https://leetcode.com/problems/permutation-in-string/

12. Minimum Window Subsequence
    https://leetcode.com/problems/minimum-window-subsequence/

Lint-604. Window Sum
https://www.lintcode.com/problem/window-sum/description

## 1004 Max Consecutive Ones III

Given a binary array `nums` and an integer `k`, return *the maximum number of consecutive* `1`*'s in the array if you can flip at most* `k` `0`'s.

**Example 1:**

```
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

**Example 2:**

```
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

**Solution**

左指针怎么移动是这个的关键，当我们用完flip的时候，我们移动左指针直到找到第一个0

```java
class Solution {
  public int longestOnes(int[] A, int K) {
        int zeroCount=0,start=0,res=0;
        for(int end=0;end<A.length;end++){
            if(A[end] == 0) zeroCount++;
            while(zeroCount > K){
                if(A[start] == 0) zeroCount--;
                start++;
            }
            res=Math.max(res,end-start+1);
        }
        return res;
    }
}
```

