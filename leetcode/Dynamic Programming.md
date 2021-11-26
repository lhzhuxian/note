# 基本问题：

(1) 动态规划更准确的说是一种数学思想，而不是一种算法。学习曲线相对于前面的算法会比较陡峭，如果是有天赋的大佬，可能可以很快领悟。但是对于大部分平均水平的同学，可能需要前后间隔几个礼拜甚至几个月，反复思考两三遍才能顿悟并运用。所以作为初学者，一时半会想不明白没关系，隔几天回来再多看几次就能渐渐理解了。

(2) 不过针对目前的面试，除了少数那几家公司之外，动态规划的出现频率其实没有那么高，而且主要也都是中等难度的题目。所以如果准备时间有限，建议优先把时间放在前面的算法上，动态规划可以先看几道中等难度经典题，其他的题目后面有时间再看。

(3) 关于一道题是用动态规划还是用贪心法，一般来说时间复杂度类似的时候优先用动态规划，因为通用性、可解释性都比较强。而自己凭空想出来的贪心法，不但不容易解释，而且很容易是错的，面试风险相对比较高。不过有一些题目确实是贪心法最优，作者在后面也列出了几题，如果碰到原题或者类似题，可以参考。

(4) 对于新手而言，在学习动态规划的时候，看懂题目在问什么之后就可以在网上找答案了，别自己瞎折腾。网上各种大佬的博客有详细的图文解释，慢慢揣摩理解。

(5) 动态规划的一般思路是数学归纳法，就是用递推的方式把大问题（最终问题）分解为小问题（前置问题），然后一路倒推到边界；在边界附近计算出初始状态后，再原路反向往回计算，最后得到所求解。所以对于绝大部分题目，都需要遵循：分解子问题，写出转移方程，描述边界条件，计算出最终解这几个步骤。

(6) 有些动态规划问题，可以通过滚动数组的方式优化空间复杂度，一般可以降一个维度。但是要注意运算的方向，需要避免前序的结果在被用到之前就被覆盖掉的情况。

(7)大部分动态规划都是求解“可行性”，“最值”问题，如果有些题目要求输出结果，也可以考虑用“打印路径”的方式。

(8) 很多问题，通过细微的改一些条件，就会变成另外一道题，解法思路会产生明显差异，所以审题要小心。比如背包类问题，是否可以重复选同一个物品，是否有重复物品，求解最大重量还是最大价值， 背后的原理可能会产生变化。有时候是组合问题，有时候是排列问题，还叠加了是否可以重复的情况，需要透彻的理解。另外在解法上，比如说，正着走一遍循环和倒着走一遍循环可能代表的是两种不同的思考方式，这些往往需要反复细致的理解才能完善自己的思维体系。

(9) 有些问题需要求“所有可行解”，这时候往往会使用搜索（DFS，BFS）的方法。但为了进行时空优化，记忆化搜索也会常常被用到。其实DFS记忆化搜索和常规动态规划写法常常是一个思维的两种实现方式，在不同的题目中各有优劣。

(10) 在面试动态规划的时候，重点在于能够比较清晰地画图描述并解释清楚所写的动态方程，让面试官理解你的思路，注意初始化以及for循环的起始条件。至于代码本身，往往是for循环为主，一般也不长。





# Backpack



https://zhuanlan.zhihu.com/p/93857890





Lint-92. Backpack
https://www.lintcode.com/problem/backpack/description

Lint-125. Backpack II
https://www.lintcode.com/problem/backpack-ii/description

Lint-440. Backpack III
https://www.lintcode.com/problem/backpack-iii/description

Lint-562. Backpack IV
https://www.lintcode.com/problem/backpack-iv/description

Lint-563. Backpack V
https://www.lintcode.com/problem/backpack-v/description

Lint-564. Backpack VI (Combination Sum IV)
https://www.lintcode.com/problem/combination-sum-iv/description

Lint-971. Surplus Value Backpack
https://www.lintcode.com/problem ... ackpack/description

474. Ones and Zeroes
https://leetcode.com/problems/ones-and-zeroes/

# Single Sequence

139. Word Break
https://leetcode.com/problems/word-break/

121. Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

122. Best Time to Buy and Sell Stock II
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

123. Best Time to Buy and Sell Stock III
https://leetcode.com/problems/be ... and-sell-stock-iii/

188. Best Time to Buy and Sell Stock IV
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

256. Paint House
https://leetcode.com/problems/paint-house/

265. Paint House II
https://leetcode.com/problems/paint-house-ii/

Lint-843. Digital Flip
https://www.lintcode.com/problem/digital-flip/description



## 691 Stickers to Spell Word

We are given `n` different types of `stickers`. Each sticker has a lowercase English word on it.

You would like to spell out the given string `target` by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

Return *the minimum number of stickers that you need to spell out* `target`. If the task is impossible, return `-1`.

**Note:** In all test cases, all words were chosen randomly from the `1000` most common US English words, and `target` was chosen as a concatenation of two random words.

 

**Example 1:**

```
Input: stickers = ["with","example","science"], target = "thehat"
Output: 3
Explanation:
We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.
```

**Example 2:**

```
Input: stickers = ["notice","possible"], target = "basicbasic"
Output: -1
Explanation:
We cannot form the target "basicbasic" from cutting letters from the given stickers.
```

**Solution**

There are potentially a lot of overlapping sub problems, but meanwhile we don't exactly know what those sub problems are. DP with memoization works pretty well in such cases. The workflow is like backtracking, but with memoization. Here I simply use a sorted string of target as the key for the unordered_map DP. A sorted target results in a unique sub problem for possibly different strings.

```
dp[s] is the minimum stickers required for string s (-1 if impossible). Note s is sorted.
clearly, dp[""] = 0, and the problem asks for dp[target].
```

The DP formula is:

```
dp[s] = min(1+dp[reduced_s]) for all stickers, 
here reduced_s is a new string after certain sticker applied
```



Optimization: If the target can be spelled out by a group of stickers, at least one of them has to contain character target[0]. So I explicitly require next sticker containing target[0], which significantly reduced the search space.

```java
class Solution {
    public int minStickers(String[] stickers, String target) {
        int m = stickers.length;
        int[][] mp = new int[m][26];
        Map<String, Integer> dp = new HashMap<>();
        for (int i = 0; i < m; i++) 
            for (char c:stickers[i].toCharArray()) mp[i][c-'a']++;
        dp.put("", 0);
        return helper(dp, mp, target);
    }
    
    private int helper(Map<String, Integer> dp, int[][] mp, String target) {
        if (dp.containsKey(target)) return dp.get(target);
        int ans = Integer.MAX_VALUE, n = mp.length;
        int[] tar = new int[26];
        for (char c:target.toCharArray()) tar[c-'a']++;
        // try every sticker
        for (int i = 0; i < n; i++) {
            // optimization
            // If this sticker didn't contains first character but contains the character after it and it is unique, it will be picked in the future anyway (when that character become the first character). So we won't miss case in such a optimization.
            if (mp[i][target.charAt(0)-'a'] == 0) continue;
            StringBuilder sb = new StringBuilder();
            // apply a sticker on every character a-z
            for (int j = 0; j < 26; j++) {
                if (tar[j] > 0 ) 
                    for (int k = 0; k < Math.max(0, tar[j]-mp[i][j]); k++)
                        sb.append((char)('a'+j));
            }
            String s = sb.toString();
            int tmp = helper(dp, mp, s);
            if (tmp != -1) ans = Math.min(ans, 1+tmp);
        }
        dp.put(target, ans == Integer.MAX_VALUE? -1:ans);
        return dp.get(target);
    }
}
```



------



## Maximum Subarray

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return *its sum*. 

**Example 1:**

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

**Example 2:**

```
Input: nums = [1]
Output: 1
```

**Example 3:**

```
Input: nums = [5,4,-1,7,8]
Output: 23
```

**Follow up:** If you have figured out the `O(n)` solution, try coding another solution using the **divide and conquer** approach, which is more subtle.

**Solution**

简单的dp问题 dp[i] 代表从0到i这段subarray的sum，当我们build这个dp的过程中,我们可以track前面最小的sum，然后减一下就是以当前结尾的subarray最大的sum

```java
class Solution {
    public int maxSubArray(int[] nums) {
        // Initialize our variables using the first element.
        int currentSubarray = nums[0];
        int maxSubarray = nums[0];
        
        // Start with the 2nd element since we already used the first one.
        for (int i = 1; i < nums.length; i++) {
            int num = nums[i];
            // If current_subarray is negative, throw it away. Otherwise, keep adding to it.
            currentSubarray = Math.max(num, currentSubarray + num);
            maxSubarray = Math.max(maxSubarray, currentSubarray);
        }
        
        return maxSubarray;
    }
}
```

------

## Maximum Product Subarray

Given an integer array `nums`, find a contiguous non-empty subarray within the array that has the largest product, and return *the product*.

It is **guaranteed** that the answer will fit in a **32-bit** integer.

A **subarray** is a contiguous subsequence of the array.

**Example 1:**

```
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

**Example 2:**

```
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

**Solution**

**DP**

```java
class Solution {
    public int maxProduct(int[] nums) {
        if (nums.length == 0) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.length; i++) {
            int curr = nums[i];
            int temp_max = Math.max(curr, Math.max(max_so_far * curr, min_so_far * curr));
            min_so_far = Math.min(curr, Math.min(max_so_far * curr, min_so_far * curr));

            max_so_far = temp_max;

            result = Math.max(max_so_far, result);
        }

        return result;
    }
}
```



# Double Sequences



## 10 Regular Expression Matching

Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:

- `'.'` Matches any single character.
- `'*'` Matches zero or more of the preceding element.

The matching should cover the **entire** input string (not partial).

**Example 1:**

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

**Example 3:**

```
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

**Example 4:**

```
Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
```

**Example 5:**

```
Input: s = "mississippi", p = "mis*is*p*."
Output: false
```

**Solution**

```java
enum Result {
    TRUE, FALSE
}

class Solution {
    Result[][] memo;

    public boolean isMatch(String text, String pattern) {
        memo = new Result[text.length() + 1][pattern.length() + 1];
        return dp(0, 0, text, pattern);
    }

    public boolean dp(int i, int j, String text, String pattern) {
        if (memo[i][j] != null) {
            return memo[i][j] == Result.TRUE;
        }
        boolean ans;
        if (j == pattern.length()){
            ans = i == text.length();
        } else{
            boolean first_match = (i < text.length() &&
                                   (pattern.charAt(j) == text.charAt(i) ||
                                    pattern.charAt(j) == '.'));
						// case 1 j后面不是*， 那只要比较当前i,j 是否相同，然后dp[i + 1][j + 1]
          // case 2 j后面是*, 第一种情况可以不要当前的j，dp[i][j + 2]就行 或者 要j， 比较dp[i + 1][j]
            if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
                ans = (dp(i, j+2, text, pattern) ||
                       first_match && dp(i+1, j, text, pattern));
            } else {
                ans = first_match && dp(i+1, j+1, text, pattern);
            }
        }
        memo[i][j] = ans ? Result.TRUE : Result.FALSE;
        return ans;
    }
}
```



## 44 Wildcard Matching

Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'` where:

- `'?'` Matches any single character.
- `'*'` Matches any sequence of characters (including the empty sequence).

The matching should cover the **entire** input string (not partial).

 

**Example 1:**

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
```

**Example 3:**

```
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
```

**Example 4:**

```
Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
```

**Example 5:**

```
Input: s = "acdcb", p = "a*c?b"
Output: false
```

**Solution**

The original post has DP 2d array index from high to low, which is not quite intuitive.

Below is another 2D dp solution. Ideal is identical.

dp[i][j] denotes whether s[0....i-1] matches p[0.....j-1],

First, we need to initialize dp[i][0], i= [1,m]. All the dp[i][0] should be false because p has nothing in it.

Then, initialize dp[0][j], j = [1, n]. In this case, s has nothing, to get dp[0][j] = true, p must be '*', '**', '***',etc. Once p.charAt(j-1) != '*', all the dp[0][j] afterwards will be false.

Then start the typical DP loop.

Though this solution is clear and easy to understand. It is not good enough in the interview. it takes O(mn) time and O(mn) space.

Improvement: 1) optimize 2d dp to 1d dp, this will save space, reduce space complexity to O(N). 2) use iterative 2-pointer.

```java

class Solution {
    public boolean isMatch(String s, String p) {
        int m=s.length(), n=p.length();
	boolean[][] dp = new boolean[m+1][n+1];
	dp[0][0] = true;
	for (int i=1; i<=m; i++) {
		dp[i][0] = false;
	}
	
	for(int j=1; j<=n; j++) {
		if(p.charAt(j-1)=='*'){
			dp[0][j] = true;
		} else {
			break;
		}
	}
	
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if (p.charAt(j-1)!='*') {
				dp[i][j] = dp[i-1][j-1] && (s.charAt(i-1)==p.charAt(j-1) || p.charAt(j-1)=='?');
			} else {
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}
		}
	}
	return dp[m][n];
    }
}

```







## 718 Maximum Length of Repeated Subarray

Given two integer arrays `nums1` and `nums2`, return *the maximum length of a subarray that appears in **both** arrays*.

 

**Example 1:**

```
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
```

**Example 2:**

```
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
```

 

**Solution**

```java
class Solution {
    public int findLength(int[] A, int[] B) {
        if(A == null||B == null) return 0;
        int m = A.length;
        int n = B.length;
        int max = 0;
        //dp[i][j] is the length of longest common subarray ending with nums[i] and nums[j]
        int[][] dp = new int[m + 1][n + 1];
        for(int i = 0;i <= m;i++){
            for(int j = 0;j <= n;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    if(A[i - 1] == B[j - 1]){
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        max = Math.max(max,dp[i][j]);
                    }
                }
            }
        }
        return max;
    }
}
```



## Edit Distance

Given two strings `word1` and `word2`, return *the minimum number of operations required to convert `word1` to `word2`*.

You have the following three operations permitted on a word:

- Insert a character
- Delete a character
- Replace a character 

**Example 1:**

```
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

**Example 2:**

```
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```

**Solution**

`D[i][j]` which is an edit distance between the substring of `word1` ends in i and substring of `word2` ends in j.

If the last character is the same, *i.e.* `word1[i] = word2[j]` then

```
D[i][j] = 1 + min(D[i - 1][j], D[i][j - 1], D[i - 1][j - 1] - 1)
```

and if not, *i.e.* `word1[i] != word2[j]` we have to take into account the replacement of the last character during the conversion.

`D[i][j] = 1 + min(D[i - 1][j], D[i][j - 1], D[i - 1][j - 1])`



```java
class Solution {
  public int minDistance(String word1, String word2) {
    int n = word1.length();
    int m = word2.length();

    // if one of the strings is empty
    if (n * m == 0)
      return n + m;

    // array to store the convertion history
    int [][] d = new int[n + 1][m + 1];

    // init boundaries
    for (int i = 0; i < n + 1; i++) {
      d[i][0] = i;
    }
    for (int j = 0; j < m + 1; j++) {
      d[0][j] = j;
    }

    // DP compute 
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        int left = d[i - 1][j] + 1;
        int down = d[i][j - 1] + 1;
        int left_down = d[i - 1][j - 1];
        if (word1.charAt(i - 1) != word2.charAt(j - 1))
          left_down += 1;
        d[i][j] = Math.min(left, Math.min(down, left_down));

      }
    }
    return d[n][m];
  }
}
```





## 403 Frog Jump

A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of `stones`' positions (in units) in sorted **ascending order**, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be `1` unit.

If the frog's last jump was `k` units, its next jump must be either `k - 1`, `k`, or `k + 1` units. The frog can only jump in the forward direction.

 

**Example 1:**

```
Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
```

**Example 2:**

```
Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
```

 **Solution**

```java
public class Solution {
    // 可以用set来减少找到下个点的时间
    public boolean canCross(int[] stones) {
        // dp[i] represent the jump size that frog can make when it is in stone i
        HashMap<Integer, Set<Integer>> dp = new HashMap<>();
        for(int stone : stones) {
            dp.put(stone, new HashSet<>());
        }
        dp.get(stones[0]).add(1);
        for(int stone : stones) {
            Set<Integer> jumpSizes = dp.get(stone);
            for(int jump : jumpSizes) {
                for(int i = -1; i <= 1; ++i) {
                    if(dp.containsKey(jump + stone)) {
                        // cannot jump back
                        dp.get(jump + stone).add(jump + i > 0? jump + i: 0);
                    }
                }
            }
        }
        return dp.get(stones[stones.length - 1]).size() > 0;
    }
}
```



10. Regular Expression Matching
https://leetcode.com/problems/regular-expression-matching/

44. Wildcard Matching
https://leetcode.com/problems/wildcard-matching/

72. Edit Distance
https://leetcode.com/problems/edit-distance/

97. Interleaving String
https://leetcode.com/problems/interleaving-string/

115. Distinct Subsequences
https://leetcode.com/problems/distinct-subsequences/

1143. Longest Common Subsequence
https://leetcode.com/problems/longest-common-subsequence/



## Longest Palindromic Subsequence

Given a string `s`, find *the longest palindromic **subsequence**'s length in* `s`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**

```
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
```

**Example 2:**

```
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
```

**Solution**

**Palindromic**  系列可以总结一下

先把问题分解成 小的部分， 一个长的string的seq可以用小的string的seq来组成

```
dp[i][j] = 从i 到 j 的substring 的最长pseq
case1:
s[i] == s[j]  可以放心把这个两个都加入 dp[i + 1][j - 1]的seq中 
dp[i][j] = dp[i + 1][j - 1]
case2:
s[i] != s[j] 那只有可能把其中一个加进去
dp[i][j] = max(dp[i][j - 1], dp[i + 1][j)
```



```java
class Solution {
    public int longestPalindromeSubseq(String s) {
        int len = s.length();
        int[][] dp = new int[len][len];
      // slen 代表了substring的长度
        for(int slen = 1; slen <= len; ++slen) {
            for(int i = 0; i < len - slen + 1; ++i) {
                int j = i + slen - 1;
                if(i == j) {
                    dp[i][j] = 1;
                } else if(s.charAt(i) == s.charAt(j)) {
                    // dp[0][1] = dp[1][0] + 2
                    // dp[1][0] 是不合法的所以是0， 但默认的initialization已经是0了
                    // 所以不需要特别的init
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][len - 1];
    }
}
```



------



## Paint House

There is a row of `n` houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an `n x 3` cost matrix `costs`.

- For example, `costs[0][0]` is the cost of painting house `0` with the color red; `costs[1][2]` is the cost of painting house 1 with color green, and so on...

Return *the minimum cost to paint all houses*.

 

**Example 1:**

```
Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
Minimum cost: 2 + 5 + 3 = 10.
```

**Example 2:**

```
Input: costs = [[7,6,2]]
Output: 2
```

**Solution**

**dp**

```java
class Solution {
    public int minCost(int[][] costs) {
        int houseNum = costs.length;
        int colorNum = costs[0].length;
        int[][] dp = new int[houseNum][colorNum];
        for(int i = 0; i < houseNum; ++i) {
            for(int j = 0; j < colorNum; ++j) {
                if(i -1 < 0) {
                    dp[i][j] = costs[i][j];
                } else {
                    dp[i][j] = Integer.MAX_VALUE;
                    for(int k = 1; k < colorNum; ++k) {
                        dp[i][j] = Math.min(dp[i - 1][(j + k) % colorNum] + costs[i][j], dp[i][j]);    
                    }    
                }
            }
        }
        int result = Integer.MAX_VALUE;
        for(int j = 0; j < colorNum; ++j) {
            result = Math.min(dp[houseNum - 1][j], result);
        }
        return result;
    }
}
```



------

## Paint House II

There are a row of `n` houses, each house can be painted with one of the `k` colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an `n x k` cost matrix costs.

- For example, `costs[0][0]` is the cost of painting house `0` with color `0`; `costs[1][2]` is the cost of painting house `1` with color `2`, and so on...

Return *the minimum cost to paint all houses*.

 **Example 1:**

```
Input: costs = [[1,5,3],[2,9,4]]
Output: 5
Explanation:
Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.
```

**Example 2:**

```
Input: costs = [[1,3],[2,4]]
Output: 5
```

**Solution**

和**paint house** 的code一模一样 这个就是把3种颜色变成k种颜色 

我太天真了，方法还可以继续优化，paint house 的方法时间复杂度是O(n*k^2)

This is because calculating the new value for each of the  cells required looking at each of the k cells in the row immediately below. However, we don't need to look at the entire previous row for every cell. Let's look again at the large example from above. When we're calculating the values for the second row, we're adding the **minimum** from the first row onto them. The only cell we can't do this for is the one that was *directly below the minimum*, as this would break the adjacency rule. For this one, it makes sense to add the **second minimum.**

For space, we just need to track 2 values, minimum and second minimum, 

Time: O(nk), Space: O(1)

```java
class Solution {

    public int minCostII(int[][] costs) {

        if (costs.length == 0) return 0;
        int k = costs[0].length;
        int n = costs.length;


        /* Firstly, we need to determine the 2 lowest costs of
         * the first row. We also need to remember the color of
         * the lowest. */
        int prevMin = -1; int prevSecondMin = -1; int prevMinColor = -1;
        for (int color = 0; color < k; color++) {
            int cost = costs[0][color];
            if (prevMin == -1 || cost < prevMin) {
                prevSecondMin = prevMin;
                prevMinColor = color;
                prevMin = cost;
            } else if (prevSecondMin == -1 || cost < prevSecondMin) {
                prevSecondMin = cost;
            }
        }

        // And now, we need to work our way down, keeping track of the minimums.
        for (int house = 1; house < n; house++) {
            int min = -1; int secondMin = -1; int minColor = -1;
            for (int color = 0; color < k; color++) {
                // Determine the cost for this cell (without writing it in).
                int cost = costs[house][color];
                if (color == prevMinColor) {
                    cost += prevSecondMin;
                } else {
                    cost += prevMin;
                }
                // Determine whether or not this current cost is also a minimum.
                if (min == -1 || cost < min) {
                    secondMin = min;
                    minColor = color;
                    min = cost;
                } else if (secondMin == -1 || cost < secondMin) {
                    secondMin = cost;
                }
            }
            // Transfer current mins to be previous mins.
            prevMin = min;
            prevSecondMin = secondMin;
            prevMinColor = minColor;
        }

        return prevMin;
    }
}
```







# 

# \Sections

312. Burst Balloons
https://leetcode.com/problems/burst-balloons/

516. Longest Palindromic Subsequence
https://leetcode.com/problems/longest-palindromic-subsequence/

87. Scramble String
https://leetcode.com/problems/scramble-string/

# Matrix

## 221 Maximal Square

Given an `m x n` binary `matrix` filled with `0`'s and `1`'s, *find the largest square containing only* `1`'s *and return its area*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg)

```
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg)

```
Input: matrix = [["0","1"],["1","0"]]
Output: 1
```

**Example 3:**

```
Input: matrix = [["0"]]
Output: 0
```

**Solution**

```java
public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int[][] dp = new int[rows + 1][cols + 1];
        int maxsqlen = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = Math.min(Math.min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    maxsqlen = Math.max(maxsqlen, dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
}
```



62. Unique Paths
https://leetcode.com/problems/unique-paths/

63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/

64. Minimum Path Sum
https://leetcode.com/problems/minimum-path-sum/

85. Maximal Rectangle
https://leetcode.com/problems/maximal-rectangle/

221. Maximal Square
https://leetcode.com/problems/maximal-square/

361. Bomb Enemy
https://leetcode.com/problems/bomb-enemy/

## Bomb Enemy

Given an `m x n` matrix `grid` where each cell is either a wall `'W'`, an enemy `'E'` or empty `'0'`, return *the maximum enemies you can kill using one bomb*. You can only place the bomb in an empty cell.

The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/27/bomb1-grid.jpg)

```
Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/27/bomb2-grid.jpg)

```
Input: grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
Output: 1
```

**Solution**

**dp**  但这个不是典型的dp，要多看看 

Time Complexity: O(W * H) W is width and H is height

Space Complexity: O(H)

For the `row_hits` value, it suffices to use one variable for all the cells on the same row, since we iterate over the grid from left to right and we don't need to memorize the `row_hits` value for the previous row.

As to the `col_hits` value, we need to use an ***array*** to keep track of all the `col_hits` values, since we need to go over all the columns for each row.

```Java
class Solution {
    public int maxKilledEnemies(char[][] grid) {
        if (grid.length == 0)
            return 0;

        int rows = grid.length;
        int cols = grid[0].length;

        int maxCount = 0, rowHits = 0;
        int[] colHits = new int[cols];

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {

                // 如果发现左边是堵墙或者尽头，那就重新count一遍右边，直到碰到墙
                if (col == 0 || grid[row][col - 1] == 'W') {
                    rowHits = 0;
                    for (int k = col; k < cols; ++k) {
                        if (grid[row][k] == 'W')
                            // stop the scan when we hit the wall.
                            break;
                        else if (grid[row][k] == 'E')
                            rowHits += 1;
                    }
                }

                // 如果发现下面是堵墙或者尽头，那就重新count一遍下面，直到碰到墙
                if (row == 0 || grid[row - 1][col] == 'W') {
                    colHits[col] = 0;
                    for (int k = row; k < rows; ++k) {
                        if (grid[k][col] == 'W')
                            break;
                        else if (grid[k][col] == 'E')
                            colHits[col] += 1;
                    }
                }

                // run the calculation for the empty cell.
                if (grid[row][col] == '0') {
                    maxCount = Math.max(maxCount, rowHits + colHits[col]);
                }
            }
        }

        return maxCount;
    }
}
```



# DFS + Memorization



## 139 Word Break

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.

 

**Example 1:**

```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

**Example 2:**

```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

**Example 3:**

```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

**Solution**

Time complexity: O(n^3)

Space Complexity: O(n)

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        return dfs(s, new HashSet<>(wordDict), 0, new Boolean[s.length()]);    
    }
    
    private boolean dfs(String s, Set<String> wordDict, int start, Boolean[] memo) {
        if(start == s.length()) {
            return true;
        }
        if(memo[start] != null) {
            return memo[start];
        }
        
        for(int end = start + 1; end <= s.length(); end++) {
            if(wordDict.contains(s.substring(start, end)) && dfs(s, wordDict, end, memo)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
    
    
}
```



## 140 Word Break II

Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in **any order**.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.

 

**Example 1:**

```
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
```

**Example 2:**

```
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
```

**Example 3:**

```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
```

**Solution**

In the worst case the runtime of this algorithm is O(2^n).

Consider the input "aaaaaa", with wordDict = ["a", "aa", "aaa", "aaaa", "aaaaa", "aaaaa"]. Every possible partition is a valid sentence, and there are 2^n-1 such partitions. It should be clear that the algorithm cannot do better than this since it generates all valid sentences. The cost of iterating over cached results will be exponential, as every possible partition will be cached, resulting in the same runtime as regular backtracking. Likewise, the space complexity will also be O(2^n) for the same reason - every partition is stored in memory.

Where this algorithm improves on regular backtracking is in a case like this: "aaaaab", with wordDict = ["a", "aa", "aaa", "aaaa", "aaaaa", "aaaaa"], i.e. the worst case scenario for Word Break I, where no partition is valid due to the last letter 'b'. In this case there are no cached results, and the runtime improves from O(2^n) to O(n^2).

One way to explain O(2^n) is as follows: given an array of length n, there are n+1 ways/intervals to partition it into two parts. Each interval has two choices - split or not. In the worse case, we will have to check all possibilities, which becomes O(2^(n+1)) -> O(2^n). This analysis is similar to palindrome partitioning.

```java
class Solution {
   public List<String> wordBreak(String s, List<String> wordDict) {
    return DFS(s, new HashSet<>(wordDict), new HashMap<String, LinkedList<String>>());
}       

// DFS function returns an array including all substrings derived from s.
List<String> DFS(String s, Set<String> wordDict, HashMap<String, LinkedList<String>>map) {
    if (map.containsKey(s)) 
        return map.get(s);
        
    LinkedList<String>res = new LinkedList<String>();     
    if (s.length() == 0) {
        res.add("");
        return res;
    }               
    for (String word : wordDict) {
        if (s.startsWith(word)) {
            List<String>sublist = DFS(s.substring(word.length()), wordDict, map);
            for (String sub : sublist) 
                res.add(word + (sub.isEmpty() ? "" : " ") + sub);               
        }
    }       
    map.put(s, res);
    return res;
}
}
```







## Minimum Insertion Steps to Make a String Palindrome

Given a string `s`. In one step you can insert any character at any index of the string.

Return *the minimum number of steps* to make `s` palindrome.

A **Palindrome String** is one that reads the same backward as well as forward.

 **Example 1:**

```
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
```

**Example 2:**

```
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
```

**Example 3:**

```
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
```

**Example 4:**

```
Input: s = "g"
Output: 0
```

**Example 5:**

```
Input: s = "no"
Output: 1
```

**Soluition**

**dfs + memorization** 更容易理解 有空看看dp的解答

We use two pointer i, j to math the char of the string like a palidrome.

We may counter two scenarios:

1. the char at i mathes the char at j
2. the chars don't match

in the second case we will have two options:

1. insert a char at j to match i
2. insert a char at i to match j

Space: `O(n^2)` as we can store at max all possible pairs of `i` and `j`.
Time: `O(n^2)` as we calculate all pairs of possible `i` and `j`.

```java
class Solution {
     public int minInsertions(String s) {
         int len = s.length();
         // initialize dp array
         int[][] dp = new int[len][len];
         for(int[] row : dp) {
             Arrays.fill(row, -1);
         }
         
         int i = 0, j = len - 1;
         return findMininInsertionsFrom(i, j, dp, s);
    }
    
    private int findMininInsertionsFrom(int i, int j, int[][] dp, String s) {
        // base case
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(i >= j) {
            dp[i][j] = 0;
            return 0;
        }
        int count = 0;
        if(s.charAt(i) == s.charAt(j)) {
            count = findMininInsertionsFrom(i + 1, j - 1, dp, s);
        } else {
            count = Math.min(findMininInsertionsFrom(i + 1, j, dp, s),
                             findMininInsertionsFrom(i, j - 1, dp, s)) + 1;
        }
        dp[i][j] = count;
        return count;
    }
}
```

****



# Others

91. Decode Ways
https://leetcode.com/problems/decode-ways/

Lint-394. Coins in a Line
https://www.lintcode.com/problem/coins-in-a-line/description

132. Palindrome Partitioning II
https://leetcode.com/problems/palindrome-partitioning-ii/

279. Perfect Squares
https://leetcode.com/problems/perfect-squares/

639. Decode Ways II
https://leetcode.com/problems/decode-ways-ii/

Lint-395. Coins in a Line II
https://www.lintcode.com/problem/coins-in-a-line-ii/description

Lint-396. Coins in a Line III
https://www.lintcode.com/problem/coins-in-a-line-iii/description

## 1218 Longest Arithmetic Subsequence of Given Difference

Given an integer array `arr` and an integer `difference`, return the length of the longest subsequence in `arr` which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals `difference`.

A **subsequence** is a sequence that can be derived from `arr` by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**

```
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
```

**Example 2:**

```
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.
```

**Example 3:**

```
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
```



**Solution**

```java
class Solution {
    public int longestSubsequence(int[] arr, int diff) {
        Map<Integer, Integer> map = new HashMap<>();
        int res = 1;
        for (int num : arr) {
            int prev = map.getOrDefault(num - diff, 0);
            map.put(num, prev + 1);
            res = Math.max(map.get(num), res);
        }
        return res;
    }
}

```



------



## Maximum Profit in Job Scheduling

We have `n` jobs, where every job is scheduled to be done from `startTime[i]` to `endTime[i]`, obtaining a profit of `profit[i]`.

You're given the `startTime`, `endTime` and `profit` arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time `X` you will be able to start another job that starts at time `X`.

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2019/10/10/sample1_1584.png)**

```
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2019/10/10/sample22_1584.png)**

```
Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
```

**Example 3:**

**![img](https://assets.leetcode.com/uploads/2019/10/10/sample3_1584.png)**

```
Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
```

**Solution**

**dp** 下次还要细看的 **TreeMap** 这个还是经常用到，api又比较繁琐，要多看看

Before thinking about this weighted Interval Scheduling problem, let's take a look at Unweighted Interval Scheduling, which is problem 646. Maximum Length of Pair Chain.

For Unweighted Interval Scheduling, we can easily use greedy algorithm. First sort by finish time(ascending order) then decide whether to fit the next interval in or not based on its start time. See the prove here http://www.cs.cornell.edu/courses/cs482/2007su/ahead.pdf.

But Greedy algorithm can fail spectacularly if arbitrary weights are allowed. So that's when DP comes in. From my understanding, greedy is a specific kind of DP, and DP is a general greedy.

For this problem we can still first sort by finish time(ascending order) then use DP to decide whether it is profitable to put in the next interval based on its value. Here is the essence:

Define Job j starts at sj, finishes at fj, and has weight or value vj, and p(j) = largest index i < j such that job i is compatible with j. Then it should be like:
DP[j] = max(vj + DP[p(j)], DP[j-1])

For optimizing we can use binary search to locate p(j).

https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409009/JavaC%2B%2BPython-DP-Solution

```java
class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for(int i = 0; i < n; ++i) {
            jobs[i] = new int[] {startTime[i], endTime[i], profit[i]};
        }
        
        Arrays.sort(jobs, (a, b) -> a[1] - b[1]);
        TreeMap<Integer, Integer> dp = new TreeMap<>();
        dp.put(0, 0);
        for(int [] job : jobs) {
            int cur = dp.floorEntry(job[0]).getValue() + job[2];
            if(cur > dp.lastEntry().getValue()) {
                dp.put(job[1], cur);
            }
        }
        return dp.lastEntry().getValue();
    }
}
```



# Greedy

55. Jump Game
https://leetcode.com/problems/jump-game/
45. Jump Game II
https://leetcode.com/problems/jump-game-ii/
763. Partition Labels
https://leetcode.com/problems/partition-labels/



# Jump Game

## 55 Jump Game

You are given an integer array `nums`. You are initially positioned at the array's **first index**, and each element in the array represents your maximum jump length at that position.

Return `true` *if you can reach the last index, or* `false` *otherwise*.

 

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```



**Solution**

dp[i] 代表能否从这个跳到终点，从后build这个dp就行了。 一个问题是dp[i] 要遍历一遍整个 i + 1 到end， 其实仔细一想，我们不用去考虑这么多，我们track一个目前最近的点能到终点，对每个i我们检查一下是不是能跳到那儿就行了

```java
class Solution {
    public boolean canJump(int[] nums) {
        int loc = nums.length - 1;
        for(int i = nums.length -2; i >= 0; --i) {
            if(nums[i] + i >= loc) {
                loc = i;
            }
        }
        return loc == 0;
    }
}
```



## 403 Frog Jump

A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of `stones`' positions (in units) in sorted **ascending order**, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be `1` unit.

If the frog's last jump was `k` units, its next jump must be either `k - 1`, `k`, or `k + 1` units. The frog can only jump in the forward direction.

 

**Example 1:**

```
Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
```

**Example 2:**

```
Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
```

 **Solution**

```java
public class Solution {
    // 可以用set来减少找到下个点的时间
    public boolean canCross(int[] stones) {
        // dp[i] represent the jump size that frog can make when it is in stone i
        HashMap<Integer, Set<Integer>> dp = new HashMap<>();
        for(int stone : stones) {
            dp.put(stone, new HashSet<>());
        }
        dp.get(stones[0]).add(1);
        for(int stone : stones) {
            Set<Integer> jumpSizes = dp.get(stone);
            for(int jump : jumpSizes) {
                for(int i = -1; i <= 1; ++i) {
                    if(dp.containsKey(jump + stone)) {
                        // cannot jump back
                        dp.get(jump + stone).add(jump + i > 0? jump + i: 0);
                    }
                }
            }
        }
        return dp.get(stones[stones.length - 1]).size() > 0;
    }
}
```



## 1345 Jump Game IV

Given an array of integers `arr`, you are initially positioned at the first index of the array.

In one step you can jump from index `i` to index:

- `i + 1` where: `i + 1 < arr.length`.
- `i - 1` where: `i - 1 >= 0`.
- `j` where: `arr[i] == arr[j]` and `i != j`.

Return *the minimum number of steps* to reach the **last index** of the array.

Notice that you can not jump outside of the array at any time.

 

**Example 1:**

```
Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
```

**Example 2:**

```
Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You don't need to jump.
```

**Example 3:**

```
Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
```

**Example 4:**

```
Input: arr = [6,1,9]
Output: 2
```

**Example 5:**

```
Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
Output: 3
```

**Solution**

其实是一道bfs

```java
class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;
        if (n <= 1) {
            return 0;
        }

        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.computeIfAbsent(arr[i], v -> new LinkedList<>()).add(i);
        }

        List<Integer> curs = new LinkedList<>(); // store current layer
        curs.add(0);
        Set<Integer> visited = new HashSet<>();
        int step = 0;

        // when current layer exists
        while (!curs.isEmpty()) {
            List<Integer> nex = new LinkedList<>();

            // iterate the layer
            for (int node : curs) {
                // check if reached end
                if (node == n - 1) {
                    return step;
                }

                // check same value
                for (int child : graph.get(arr[node])) {
                    if (!visited.contains(child)) {
                        visited.add(child);
                        nex.add(child);
                    }
                }

                // clear the list to prevent redundant search
                graph.get(arr[node]).clear();

                // check neighbors
                if (node + 1 < n && !visited.contains(node + 1)) {
                    visited.add(node + 1);
                    nex.add(node + 1);
                }
                if (node - 1 >= 0 && !visited.contains(node - 1)) {
                    visited.add(node - 1);
                    nex.add(node - 1);
                }
            }

            curs = nex;
            step++;
        }

        return -1;
    }
}
```

