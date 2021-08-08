## 680 Valid Palindrome II

Given a string `s`, return `true` *if the* `s` *can be palindrome after deleting **at most one** character from it*. 

**Example 1:**

```
Input: s = "aba"
Output: true
```

**Example 2:**

```
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
```

**Example 3:**

```
Input: s = "abc"
Output: false
```

**Solution**

```java
class Solution {
       public boolean validPalindrome(String s) {
        int l = 0, r = s.length() - 1;
        while (l <= r)  {
            if (s.charAt(l) != s.charAt(r)) {
                return isPalindromic(s, l + 1, r) || isPalindromic(s, l, r - 1);
            } 
            l++;
            r--;
        }
        return true;
    }

    public boolean isPalindromic(String s, int l, int r) {
        while (l <= r) {
            if (s.charAt(l) != s.charAt(r)) {
                return false;
            }
            l++;
            r--;
        } 
        return true;
    }

}
```



## 1216 Valid Palindrome III

Given a string `s` and an integer `k`, return `true` if `s` is a `k`**-palindrome**.

A string is `k`**-palindrome** if it can be transformed into a palindrome by removing at most `k` characters from it.

**Example 1:**

```
Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.
```

**Example 2:**

```
Input: s = "abbababa", k = 1
Output: true
```

**Solution**

和上面的idea 差不多，需要一个memo来记录一些计算过的结果

还能继续优化 space complexity 以后看看

https://leetcode.com/problems/valid-palindrome-iii/solution/

```java
class Solution {
    Integer memo[][];
    int isValidPalindrome(String s, int i, int j) {

        // Base case, only 1 letter remaining.
        if (i == j)
            return 0;

        // Base case 2, only 2 letters remaining.
        if (i == j - 1)
            return s.charAt(i) != s.charAt(j) ? 1 : 0;

        //Return the precomputed value if exists.
        if (memo[i][j] != null)
            return memo[i][j];

        // Case 1: Character at `i` equals character at `j`
        if (s.charAt(i) == s.charAt(j))
            return memo[i][j] = isValidPalindrome(s, i + 1, j - 1);

        // Case 2: Character at `i` does not equal character at `j`.
        // Either delete character at `i` or delete character at `j`
        // and try to match the two pointers using recursion.
        // We need to take the minimum of the two results and add 1
        // representing the cost of deletion.
        return memo[i][j] = 1 + Math.min(isValidPalindrome(s, i + 1, j), isValidPalindrome(s, i, j - 1));
    }
public boolean isValidPalindrome(String s, int k) {
        memo = new Integer[s.length()][s.length()];

        // Return true if the minimum cost to create a palindrome by only deleting the letters
        // is less than or equal to `k`.
        return isValidPalindrome(s, 0, s.length() - 1) <= k;
    }
};
```









## 266 Palindrome Permutation

Given a string `s`, return `true` if a permutation of the string could form a palindrome.

**Example 1:**

```
Input: s = "code"
Output: false
```

**Example 2:**

```
Input: s = "aab"
Output: true
```

**Example 3:**

```
Input: s = "carerac"
Output: true
```

**Solution**

只能右一个单数的char， 其他的必须都是2的倍数

```java
public class Solution {
    public boolean canPermutePalindrome(String s) {
        int[] map = new int[128];
        for (int i = 0; i < s.length(); i++) {
            map[s.charAt(i)]++;
        }
        int count = 0;
        for (int key = 0; key < map.length && count <= 1; key++) {
            count += map[key] % 2;
        }
        return count <= 1;
    }
}
```

