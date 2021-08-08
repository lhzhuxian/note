## 953 Verifying an Alien Dictionary

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different `order`. The `order` of the alphabet is some permutation of lowercase letters.

Given a sequence of `words` written in the alien language, and the `order` of the alphabet, return `true` if and only if the given `words` are sorted lexicographicaly in this alien language. 

**Example 1:**

```
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
```

**Example 2:**

```
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
```

**Example 3:**

```
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
```

**Solution**

**Hash Table**

```java
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
      // 有限key的时候用array 做hash table
        int[] orderMap = new int[26];
        for (int i = 0; i < order.length(); i++){
            orderMap[order.charAt(i) - 'a'] = i;
        }
			
        for (int i = 0; i < words.length - 1; i++) {

            for (int j = 0; j < words[i].length(); j++) {
                // If we do not find a mismatch letter between words[i] and words[i + 1],
                // we need to examine the case when words are like ("apple", "app").
                if (j >= words[i + 1].length()) return false;

                if (words[i].charAt(j) != words[i + 1].charAt(j)) {
int currentWordChar = words[i].charAt(j) - 'a';
int nextWordChar = words[i + 1].charAt(j) - 'a';
                    if (orderMap[currentWordChar] > orderMap[nextWordChar]) return false;
                    // if we find the first different letter and they are sorted,
                    // then there's no need to check remaining letters
                    else break;
                }
            }
        }

        return true;
    }
}
```

 

------



## 1428 Leftmost Column with at Least a One

*(This problem is an **interactive problem**.)*

A **row-sorted binary matrix** means that all elements are `0` or `1` and each row of the matrix is sorted in non-decreasing order.

Given a **row-sorted binary matrix** `binaryMatrix`, return *the index (0-indexed) of the **leftmost column** with a 1 in it*. If such an index does not exist, return `-1`.

**You can't access the Binary Matrix directly.** You may only access the matrix using a `BinaryMatrix` interface:

- `BinaryMatrix.get(row, col)` returns the element of the matrix at index `(row, col)` (0-indexed).
- `BinaryMatrix.dimensions()` returns the dimensions of the matrix as a list of 2 elements `[rows, cols]`, which means the matrix is `rows x cols`.

Submissions making more than `1000` calls to `BinaryMatrix.get` will be judged *Wrong Answer*. Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes, the input will be the entire binary matrix `mat`. You will not have access to the binary matrix directly.

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-5.jpg)**

```
Input: mat = [[0,0],[1,1]]
Output: 0
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-4.jpg)**

```
Input: mat = [[0,0],[0,1]]
Output: 1
```

**Example 3:**

**![img](https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-3.jpg)**

```
Input: mat = [[0,0],[0,0]]
Output: -1
```

**Example 4:**

**![img](https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-6.jpg)**

```
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
```

**Solution**

先找到第一行的最左边的1，然后一路往下，如果发现是0就继续下，如果是1就往左走找到这一行的最左边的1

也可以对每一行都做一次binary search

```java
class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        int rows = binaryMatrix.dimensions().get(0);
        int cols = binaryMatrix.dimensions().get(1);

        // Set pointers to the top-right corner.
        int currentRow = 0;
        int currentCol = cols - 1;
    
        // Repeat the search until it goes off the grid.
        while (currentRow < rows && currentCol >= 0) {
            if (binaryMatrix.get(currentRow, currentCol) == 0) {
                currentRow++;
            } else {
                currentCol--; 
            }
        }
    
        // If we never left the last column, this is because it was all 0's.
        return (currentCol == cols - 1) ? -1 : currentCol + 1;
    }
}
```



------



1570 Dot Product of Two Sparse Vectors

Given two sparse vectors, compute their dot product.

Implement class `SparseVector`:

- `SparseVector(nums)` Initializes the object with the vector `nums`
- `dotProduct(vec)` Compute the dot product between the instance of *SparseVector* and `vec`

A **sparse vector** is a vector that has mostly zero values, you should store the sparse vector **efficiently** and compute the dot product between two *SparseVector*.

**Follow up:** What if only one of the vectors is sparse?

 

**Example 1:**

```
Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
```

**Example 2:**

```
Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
Output: 0
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
```

**Example 3:**

```
Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
Output: 6
```

**Solution**

**Hash Table**

- Time complexity: O(n)*O*(*n*) for creating the Hash Map; O(L)*O*(*L*) for calculating the dot product.
- Space complexity: O(L)*O*(*L*) for creating the Hash Map, as we only store elements that are non-zero. O(1)*O*(1) for calculating the dot product.

```java
class SparseVector {
    // Map the index to value for all non-zero values in the vector
    Map<Integer, Integer> mapping;      

    SparseVector(int[] nums) {
        mapping = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                mapping.put(i, nums[i]);        
            }
        }
    }

    public int dotProduct(SparseVector vec) {        
        int result = 0;

        // iterate through each non-zero element in this sparse vector
        // update the dot product if the corresponding index has a non-zero value in the other vector
        for (Integer i : this.mapping.keySet()) {
            if (vec.mapping.containsKey(i)) {
                result += this.mapping.get(i) * vec.mapping.get(i);
            }
        }
        return result;
    }
}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);
```



------



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

**recursion** 最经常的case，删左边或者删右边

```java
class Solution {
       public boolean validPalindrome(String s) {
        int l = -1, r = s.length();
        while (++l < --r) 
            if (s.charAt(l) != s.charAt(r)) return isPalindromic(s, l, r+1) || isPalindromic(s, l-1, r);
        return true;
    }

    public boolean isPalindromic(String s, int l, int r) {
        while (++l < --r) 
            if (s.charAt(l) != s.charAt(r)) return false;
        return true;
    }

}
```



------



## 415 Add Strings

Given two non-negative integers, `num1` and `num2` represented as string, return *the sum of* `num1` *and* `num2` *as a string*.

You must solve the problem without using any built-in library for handling large integers (such as `BigInteger`). You must also not convert the inputs to integers directly.

 

**Example 1:**

```
Input: num1 = "11", num2 = "123"
Output: "134"
```

**Example 2:**

```
Input: num1 = "456", num2 = "77"
Output: "533"
```

**Example 3:**

```
Input: num1 = "0", num2 = "0"
Output: "0"
```

 

**Solution**

```java
class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder res = new StringBuilder();

        int carry = 0;
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;
        while (p1 >= 0 || p2 >= 0) {
            int x1 = p1 >= 0 ? num1.charAt(p1) - '0' : 0;
            int x2 = p2 >= 0 ? num2.charAt(p2) - '0' : 0;
            int value = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            res.append(value);
            p1--;
            p2--;    
        }
        
        if (carry != 0)
            res.append(carry);
        // 用StringBuilder最后在翻转的思路非常好
        return res.reverse().toString();
    }
}
```





iuysyjdmuvew

129 Sum Root to Leaf Numbers

简单的bfs

983 Minimum Cost For Tickets

DP

把整个年的天数拿来用 dp[i] = max(dp[i - 1] + 1 pass, dp[i - 7] + 7 pass, dp[i - 30] + 30 pass)

304 Range Sum Query 2D - Immutable

cache `dp[i][j] 代表从最左上角到这个点的rangesum` 

------

716 max Stack

two stack

```
比如 stack 是 [2, 1, 5, 3, 9]
则 maxstack 是 [2, 2, 5, 5, 9]
```

------

1249 [Minimum Remove to Make Valid Parentheses.   +3

921 Minimum Add to Make Parentheses Valid

Remove 要用个stack来记删除的index， add就不用了

------

273 Integer to English Words 真的假的

787 [ Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops)

560 [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k)

199 [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view)

------

46 [Permutations](https://leetcode.com/problems/permutations)

31 Next Permutation



------



56 [ Merge Intervals](https://leetcode.com/problems/merge-intervals)

249 [Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings)

680 [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii) + 2

543 [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree)

953 Verifying an Alien Dictionary + 2

42 trapping rain water

340 Longest Substring with At Most K Distinct Characters

415 add String

938 range Sum of BST

------

695 Max Area of Island

简单的dfs， 把每个island的大小给记录下来就行了

827 Making A large island

前面把所有岛的大小算出来以后，我们对每个0的上下左右的uniqe岛加起来就是新的大岛

------

953 Verifying an Alien Dictionary + 2

注意corner case ("apple", "app")

------

987 Vertical Order Traversal of a Binary Tree



------

844 Backspace String Compare

可以用stack把string给还原出来然后在比较

更好的办法是two pointer， 从后面开始比较，分别找到valid 的char，然后对比

------

215 Kth largest Element in an Array. +2

看一下quick select的方法，起码能说一说

------

426 Convert Binary Search Tree to Sorted Doubly Linked List

用inorder traversal 来build 一个linked list， 最后的tail ，在接回head就行了

```java
class Solution {
    public Node treeToDoublyList(Node root) {
        if(root == null) {
            return null;
        }
        Node dummy = new Node();
        Node cur = dummy;
        Stack<Node> stack = new Stack();
        while(root != null || !stack.isEmpty()) {
            while(root != null) {
                stack.push(root);
                root = root.left;
            }
            root = stack.pop();
            // append node to linked list
            cur.right = root;
            root.left = cur;
            cur = root;
            root = root.right;
        }
        cur.right = dummy.right;
        dummy.right.left = cur;
        return dummy.right;
    }
    
}
```



------

然后又给了我一个新题，没见过的，一个数组里都是sorted的，但是类似是 [4,5,6,0,1,2,3,8,9,10] 这种，然后将这个排序

先用双指针把这些sorted subarray 找出来，然后就是merge k sorted list， 时间复杂度是O(NlogK) K 是sorted subarray的数量

第二题不知道是不是蠡口的，给定一个数组，这个数组里有一部分subarray是排序好的，问如果能用最优的方法sort整个数组。

------

647 Palindromic Substrings

但是不是返回个数，而是找到所有对应的回文，一开始没看清题还以为要递归+回溯。。。说了思路后对方还说可以，然后就噼里啪啦写起来了，写完后跑一下testcase 说了时间复杂度后发现太高了，感觉不对头。。。然后认清是个变体。。。然后赶紧重写双指针。。。然后就过了这个题

------

88 Merge Sorted Array

大概就还是两个sorted array，要求optimized solution，把array b merge to array a in place，a有几个empty slots在a array后面，empty slots的数量就是array b的长度。

从后面开始merge 就行了

------

124 [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum)

给了一个口头follow up就是如果不是二叉树而是n叉树该怎么做，不写code就讲思路‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌。我大概讲了一下，用bfs，在局部，但是不是很确定。

------

[543. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree)

但有Followup： 如果用上了Map Reduce计算左右子树的path怎么处理 ？

我的回答就是加上hashmap记录当前节点和左右的结果，并且记录每个节点的父节点，当map结果出来之后更新hashmap并一直往父节点recursively更新结果。这得到了面试官的‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌肯定。

------

给一个排序的array 和 一个target 求任意两个element的和于target最近的是哪两个
要求一定要做出来O(n)

第一题应该是简化版 易留。 左右指针遍历一遍就可以了， 所以是O(N).

------

算工资税的面经题。
Input:
tax brackets = [[10000.0, 0.05], [20000.0, 0.08], [35000.0, 0.10], [double.MAX_VALUE, 0.12]]
income = 50000   
Output:
tax = 3400.0

```c++
double calculateTax(vector<vector<double>> brackets, double income) {
  double remain = income;
  int i = 0;
  double tax = 0;
  while (remain > 0 && i < brackets.size()) {
    double incomeToTake = i > 0 ? brackets[i][0] - bracket[i - 1][0] : brackets[i][0];
    double incomeToTake = min(remain, incomeToTake);
    res += brackets[i][0] * incomeToTake;
    remain = remain -incomeToTake;
    i++;
  }
  return res;
}
```

------

65 Valid Number

e只能出现一次，e前面必须有数字，后面只能是integer

. 只能出现一次，前面不是能是e

必须有数字，不能有其他除了e的字母

+, - 要不出现在第一位，要不出现在e前面

```java
class Solution {
    public boolean isNumber(String s) {
        boolean seenDigit = false;
        boolean seenExponent = false;
        boolean seenDot = false;
        
        for (int i = 0; i < s.length(); i++) {
            char curr = s.charAt(i);
            if (Character.isDigit(curr)) {
                seenDigit = true;
            } else if (curr == '+' || curr == '-') {
              // 只能在第一个和e后面出现
                if (i > 0 && s.charAt(i - 1) != 'e' && s.charAt(i - 1) != 'E') {
                    return false;
                }
            } else if (curr == 'e' || curr == 'E') {
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false;
            } else if (curr == '.') {
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else {
                return false;
            }
        }
        
        return seenDigit;
    }
}
```

------

給個sorted int array和k，问有没有两个数的diff=k。
two pointer解法就是‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌两个pointers从0开始，right pointer向前移直到right-left >k, 然后left向前移动直到right-left <k, 中间可以check right-left == k.



------

二维地图求最短路径，要求把最短路径整个输出

https://www.1point3acres.com/bbs/thread-777424-2-1.html

------

71 Simplify Path
