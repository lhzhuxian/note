## 791 Custom Sort String

You are given two strings order and s. All the words of `order` are **unique** and were sorted in some custom order previously.

Permute the characters of `s` so that they match the order that `order` was sorted. More specifically, if a character `x` occurs before a character `y` in `order`, then `x` should occur before `y` in the permuted string.

Return *any permutation of* `s` *that satisfies this property*.

 

**Example 1:**

```
Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
```

**Example 2:**

```
Input: order = "cbafg", s = "abcd"
Output: "cbad"
```

**Solution**

```java
class Solution {
    public String customSortString(String order, String s) {
        int[] charMap = new int[26];
        StringBuilder sb = new StringBuilder();
        for(char c : s.toCharArray()) {
            charMap[c - 'a']++;
        }
        for(char c : order.toCharArray()) {
            while(charMap[c - 'a'] > 0) {
                sb.append(c);
                charMap[c - 'a']--;
            }
        }
        
        for(int i = 0; i < 26; ++i) {
            while(charMap[i] > 0) {
              // 这个需要转化成char，要不然会变成100
                sb.append((char)(i + 'a'));
                charMap[i]--;
            }
        }
        return sb.toString();
    }
}
```



## 41 First Missing Positive

Given an unsorted integer array `nums`, return the smallest missing positive integer.

You must implement an algorithm that runs in `O(n)` time and uses constant extra space.

**Example 1:**

```
Input: nums = [1,2,0]
Output: 3
```

**Example 2:**

```
Input: nums = [3,4,-1,1]
Output: 2
```

**Example 3:**

```
Input: nums = [7,8,9,11,12]
Output: 1
```

**Solution**

我们是不需要考虑小于0 和大于n的数，我们只要把1到n之间的数放到它对应的位置就行了，然后loop一遍，最早发先的不再位置上的数就是答案

```java
public class Solution {
public int firstMissingPositive(int[] nums) {
   int len = nums.length;
    for(int i = 0; i < len; ++i) {
        while(nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i])  {
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }
    
    for(int i = 0; i < len; ++i) {
        if(nums[i] != i + 1) {
            return i + 1;
        }
    }
    return len + 1;
}
}
```

