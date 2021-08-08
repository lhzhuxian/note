Java 基础知识

Concurrency and multi-threading 基础知识

Process vs Thread，Context switch in thread and process，What is thread safe，Inter-process communication，Final vs finally vs finalize， semaphore vs mutex

transaction

mutex 和semaphore的区别，virtual memory & page,  difference between C++ template and virtual function.

------

BQ

提高团队效率啊，怎么优化组里的架构

proud project and what you will improve you could do it again





------



## Nested List Weight Sum

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists.

The **depth** of an integer is the number of lists that it is inside of. For example, the nested list `[1,[2,2],[[3],2],1]` has each integer's value set to its **depth**.

Return *the sum of each integer in* `nestedList` *multiplied by its **depth***.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/14/nestedlistweightsumex1.png)

```
Input: nestedList = [[1,1],2,[1,1]]
Output: 10
Explanation: Four 1's at depth 2, one 2 at depth 1. 1*2 + 1*2 + 2*1 + 1*2 + 1*2 = 10.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/14/nestedlistweightsumex2.png)

```
Input: nestedList = [1,[4,[6]]]
Output: 27
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3. 1*1 + 4*2 + 6*3 = 27.
```

**Example 3:**

```
Input: nestedList = [0]
Output: 0
```



**Solution**

一个标准的**dfs** **bfs** 题目

```java
// dfs
class Solution {
    public int depthSum(List<NestedInteger> nestedList) {
       return dfs(nestedList, 1);
    }
    
    private int dfs(List<NestedInteger> list, int depth) {
        int total = 0;
        for(NestedInteger nested : list) {
            if(nested.isInteger()) {
                total += nested.getInteger() * depth;
            } else {
                total += dfs(nested.getList(), depth + 1);
            }
        }
        return total;
    }
}
// bfs
class Solution {
    public int depthSum(List<NestedInteger> nestedList) {
        Queue<NestedInteger> queue = new LinkedList<>();
        queue.addAll(nestedList);

        int depth = 1;
        int total = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                NestedInteger nested = queue.poll();
                if (nested.isInteger()) {
                    total += nested.getInteger() * depth;
                } else {
                    queue.addAll(nested.getList());
                }
            }
            depth++;
        }
        return total;
    }
}
```



------



## Nested List Weight Sum II

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists.

The **depth** of an integer is the number of lists that it is inside of. For example, the nested list `[1,[2,2],[[3],2],1]` has each integer's value set to its **depth**. Let `maxDepth` be the **maximum depth** of any integer.

The **weight** of an integer is `maxDepth - (the depth of the integer) + 1`.

Return *the sum of each integer in* `nestedList` *multiplied by its **weight***.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/27/nestedlistweightsumiiex1.png)

```
Input: nestedList = [[1,1],2,[1,1]]
Output: 8
Explanation: Four 1's with a weight of 1, one 2 with a weight of 2.
1*1 + 1*1 + 2*2 + 1*1 + 1*1 = 8
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/27/nestedlistweightsumiiex2.png)

```
Input: nestedList = [1,[4,[6]]]
Output: 17
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1.
1*3 + 4*2 + 6*1 = 17
```



**Solution**

**DFS** 把每个integer 的depth记录下来，并记录最大的depth，然后计算depthsuminterverse

```java
class Solution {
    int maxDepth;
    public int depthSumInverse(List<NestedInteger> nestedList) {
        Map<Integer, List<Integer> > depth = new HashMap<>();
        maxDepth = 0;
        for(NestedInteger i : nestedList) {
            dfs(i, depth, 1);
        }
        int result = 0;
        for(int d : depth.keySet()) {
            for(int i : depth.get(d)) {
                result += (maxDepth - d + 1) * i;
            }
        }
        return result;
    }
    
    public void dfs(NestedInteger nested, Map<Integer, List<Integer> > depth, int cur) {
        if(nested.isInteger()) {
            maxDepth = Math.max(maxDepth, cur);
            int i = nested.getInteger();
            if(!depth.containsKey(cur)) {
                depth.put(cur, new ArrayList<>());
            }
            depth.get(cur).add(i);
            return ;
        }
        for(NestedInteger n : nested.getList()) {
            dfs(n, depth, cur + 1);
        }
    }
}
```



------



## Retain Best Cache 

**重点** 时间够可能都会考multi threading

follow up:

1. 如果这个cache是个singleton，很多pod同时访问会发生什么，答加锁，然后要求现场写加锁
2. 如果从原来的DataSource拿到值很慢，如何做到non-blocking，又该怎么加锁，答了多加几个pod不行，然后把DataSource拿值变为异步也不行，后来就到时间了
最后5分钟问了下问题，问他followup2该怎么做，他说叫我自己去查
3. priority是变动的，怎么做，变动的方式可以是LRU也可以是其他的方式，需要追问‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌，不止一种。
4. 你这个实现是不是assume了balabala?(其实就是关于获取rank的method是否对应immutable field).
2. 那你咋改啊？这能咋改啊，反正都不存在一个order了，直接loop‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌一遍好了...
3. 假如有个background thread在更新rank, 怎么办啊？上锁呀...

https://www.1point3acres.com/bbs/interview/linkedin-software-engineer-587131.html

```java
public class RetainBestCache<K, T extends Rankable> {
    Map<K, T> map;
    int size;
    PriorityQueue<Node> pq;
    DataSource<K,T> ds;
    Lock lock;
    /* Constructor with a data source (assumed to be slow) and a cache size */
    public RetainBestCache(DataSource<K,T> ds, int entriesToRetain) {
        // Implementation here
        this.map = new HashMap<>();
        this.size = entriesToRetain;
        this.pq = new PriorityQueue<>((a, b) -> {return a.t.getRank() - b.t.getRank()});
        this.ds = ds;
    }

    /* Gets some data. If possible, retrieves it from cache to be fast. If the data is not cached,
     * retrieves it from the data source. If the cache is full, attempt to cache the returned data,
     * evicting the T with lowest rank among the ones that it has available
     * If there is a tie, the cache may choose any T with lowest rank to evict.
     */
    public T get(K key) {
        // Implementation here
        // DS -> 1, 2, 3, 4, 5, 6
        // check cache, limit size = 3, (4, 5, 6)

        // get from cache
        sychronize(lock) {
        if (map.contains(key)) {
                    return map.get(key);
                }
        lock.notifyAll();
        }


        T t = ds.get(key);
        // put in cache?
        if (map.size() < size) {
            map.put(key, t);
            pq.offer(new Node(key, t));
        } else {
            T head = pq.peek();
            if (head.getRank() < t.getRank()) { // new value is higher ranked, update cache
                pq.poll();
                map.remove(head.key);

                map.put(key, t);
                pq.offer(new Node(key, t));
            }
        }

        return t;
    }
}

class Node {
    K key;
    T t;
    public Node(K k, T t) {
        this.key = k;
        this.t = t;
    }
}

/*
1. map, 1) get() O(1); 2) updateCache(), O(cachesize)
2. map, 1) get() O(1); 2) PrioriQueue, O(log(cachesize))
3. map,  1) get() O(1); 2) map<rank, list<Entry>>

*/

/*
 * For reference, here are the Rankable and DataSource interfaces.
 * You do not need to implement them, and should not make assumptions
 * about their implementations.
 */

public interface Rankable {
    /**
     * Returns the Rank of this object, using some algorithm and potentially
     * the internal state of the Rankable.
     */
    long getRank();
}

public interface DataSource<K, T extends Rankable> {
    T get (K key);
}
```



------

## Symmetric Tree

Given the `root` of a binary tree, *check whether it is a mirror of itself* (i.e., symmetric around its center).

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)

```
Input: root = [1,2,2,3,4,4,3]
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg)

```
Input: root = [1,2,2,null,3,null,3]
Output: false
```

 **Solution**

简单的backtracking 对称那等于 左子树 和 右子树对称

```java
class Solution {
    public boolean isSymmetric(TreeNode root) {
      if(root == null) {
          return true;
      }
      return isSymmetricHelper(root.left, root.right);
    }
    
    public boolean isSymmetricHelper(TreeNode left, TreeNode right) {
       if(left == null && right == null) {
           return true;
       } else if(left != null && right == null) {
           return false;
       } else if(right != null && left == null) {
           return false;
       } else if(left.val != right.val) {
           return false;
       }
       return isSymmetricHelper(left.left, right.right) && isSymmetricHelper(left.right, right.left);
    }
}
```



------



## Evaluate Reverse Polish Notation

**重点 回头要自己再写一遍考虑edge case的** **throw exception**

Evaluate the value of an arithmetic expression in [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Valid operators are `+`, `-`, `*`, and `/`. Each operand may be an integer or another expression.

**Note** that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 Follow up:

如何处理edge cases 

1）divide by zero  2）stack is empty 3. 字母和非法字符 4. 不能evaluate

**Example 1:**

```
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

**Example 2:**

```
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```

**Example 3:**

```
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

**Solution**

后缀表达式的计算方法：遍历整个表达式，如果为数字则入栈，如果为符号则将前面两个数字出栈，先出栈的在右边后出栈的在左边符号放中间算出来结果再扔到栈中即可。（loop through the whole expression, if number then push, if operator then pop two numbers, calc the result with the operator, push res back to stack）

**Stack**

```java
public class Solution {
    public int evalRPN(String[] tokens) {
        int a,b;
		Stack<Integer> S = new Stack<Integer>();
		for (String s : tokens) {
			if(s.equals("+")) {
				S.add(S.pop()+S.pop());
			}
			else if(s.equals("/")) {
				b = S.pop();
				a = S.pop();
				S.add(a / b);
			}
			else if(s.equals("*")) {
				S.add(S.pop() * S.pop());
			}
			else if(s.equals("-")) {
				b = S.pop();
				a = S.pop();
				S.add(a - b);
			}
			else {
				S.add(Integer.parseInt(s));
			}
		}	
		return S.pop();
	}
}
```



------



## Max Stack

Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the `MaxStack` class:

- `MaxStack()` Initializes the stack object.
- `void push(int x)` Pushes element `x` onto the stack.
- `int pop()` Removes the element on top of the stack and returns it.
- `int top()` Gets the element on the top of the stack without removing it.
- `int peekMax()` Retrieves the maximum element in the stack without removing it.
- `int popMax()` Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the **top-most** one.

**Example 1:**

```
Input
["MaxStack", "push", "push", "push", "top", "popMax", "top", "peekMax", "pop", "top"]
[[], [5], [1], [5], [], [], [], [], [], []]
Output
[null, null, null, null, 5, 5, 1, 5, 1, 5]

Explanation
MaxStack stk = new MaxStack();
stk.push(5);   // [5] the top of the stack and the maximum number is 5.
stk.push(1);   // [5, 1] the top of the stack is 1, but the maximum is 5.
stk.push(5);   // [5, 1, 5] the top of the stack is 5, which is also the maximum, because it is the top most one.
stk.top();     // return 5, [5, 1, 5] the stack did not change.
stk.popMax();  // return 5, [5, 1] the stack is changed now, and the top is different from the max.
stk.top();     // return 1, [5, 1] the stack did not change.
stk.peekMax(); // return 5, [5, 1] the stack did not change.
stk.pop();     // return 1, [5] the top of the stack and the max element is now 5.
stk.top();     // return 5, [5] the stack did not change.
```

**Solution**

stack的经典题目

two stack

用一个maxStack来track当前最大的值 

```
比如 stack 是 [2, 1, 5, 3, 9]
则 maxstack 是 [2, 2, 5, 5, 9]
```

popMax 则是将最大的值全部pop出来，找到stack中等于max的那个element，然后把pop出来的element 全部push 回去

timecomplexity: O(n) popMax 其余的都是O(1) 

也可以用linkedlist + PriorityQueue的方法来做

```java
class MaxStack {
    Stack<Integer> stack;
    Stack<Integer> maxStack;

    public MaxStack() {
        stack = new Stack();
        maxStack = new Stack();
    }

    public void push(int x) {
        int max = maxStack.isEmpty() ? x : maxStack.peek();
        maxStack.push(max > x ? max : x);
        stack.push(x);
    }

    public int pop() {
        maxStack.pop();
        return stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int peekMax() {
        return maxStack.peek();
    }

    public int popMax() {
        int max = peekMax();
        Stack<Integer> buffer = new Stack();
        while (top() != max) buffer.push(pop());
        pop();
        while (!buffer.isEmpty()) push(buffer.pop());
        return max;
    }
}
```



------



## Search in Rotated Sorted Array

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **rotated** at an unknown pivot index `k` (`0 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the rotation and an integer `target`, return *the index of* `target` *if it is in* `nums`*, or* `-1` *if it is not in* `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

 

**Example 1:**

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

**Example 3:**

```
Input: nums = [1], target = 0
Output: -1
```

**Solution**

经典的binary search， 但比较绕，建议多看几遍

```java
class Solution {
  public int search(int[] nums, int target) {
    int start = 0, end = nums.length - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target) 
          return mid;
      // array 可以分成两个ascending order的array， 判断在哪一段上
      else if (nums[mid] >= nums[start]) {
        if (target >= nums[start] && target < nums[mid]) {
            end = mid - 1;
        }
        else 
            start = mid + 1;
      } else {
        if (target <= nums[end] && target > nums[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
      }
    }
    return -1;
  }
}
```



------

## Search in Rotated Sorted Array II

There is an integer array `nums` sorted in non-decreasing order (not necessarily with **distinct** values).

Before being passed to your function, `nums` is **rotated** at an unknown pivot index `k` (`0 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,4,4,5,6,6,7]` might be rotated at pivot index `5` and become `[4,5,6,6,7,0,1,2,4,4]`.

Given the array `nums` **after** the rotation and an integer `target`, return `true` *if* `target` *is in* `nums`*, or* `false` *if it is not in* `nums`*.*

You must decrease the overall operation steps as much as possible.

**Example 1:**

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

**Example 2:**

```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

**Solution**

到时候放在一起看吧

```Java
class Solution {
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        if (n == 0) return false;
        int end = n - 1;
        int start = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (!isBinarySearchHelpful(nums, start, nums[mid])) {
                start++;
                continue;
            }
            // which array does pivot belong to.
            boolean pivotArray = existsInFirst(nums, start, nums[mid]);

            // which array does target belong to.
            boolean targetArray = existsInFirst(nums, start, target);
            if (pivotArray ^ targetArray) { // If pivot and target exist in different sorted arrays, recall that xor is true when both operands are distinct
                if (pivotArray) {
                    start = mid + 1; // pivot in the first, target in the second
                } else {
                    end = mid - 1; // target in the first, pivot in the second
                }
            } else { // If pivot and target exist in same sorted array
                if (nums[mid] < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }

    // returns true if we can reduce the search space in current binary search space
    private boolean isBinarySearchHelpful(int[] arr, int start, int element) {
        return arr[start] != element;
    }

    // returns true if element exists in first array, false if it exists in second
    private boolean existsInFirst(int[] arr, int start, int element) {
        return arr[start] <= element;
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
        if(nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        int maxSum = dp[0];
        for(int i = 1; i < nums.length; ++i) {
            dp[i] = Math.max(dp[i - 1], 0) + nums[i];
            maxSum = Math.max(dp[i], maxSum);
        }
        return maxSum;
    }
}
```



------



## Can Place Flowers

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in **adjacent** plots.

Given an integer array `flowerbed` containing `0`'s and `1`'s, where `0` means empty and `1` means not empty, and an integer `n`, return *if* `n` new flowers can be planted in the `flowerbed` without violating the no-adjacent-flowers rule.

 

**Example 1:**

```
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
```

**Example 2:**

```
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
```

**Solution**

```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        
        int count = 0;
        for(int i = 0; i < flowerbed.length; ++i) {
            if((i - 1 >= 0 && flowerbed[i - 1] == 1) 
               || (i + 1 < flowerbed.length && flowerbed[i + 1] == 1 ) || flowerbed[i] == 1) {
                continue;
            }
            flowerbed[i] = 1;
            count++;
          // 提早结束
            if(count >= n) {
                return true;
            }
        }
        return count >= n;
    }
}
```



------



## Find Smallest Letter Greater Than Target

Given a characters array `letters` that is sorted in **non-decreasing** order and a character `target`, return *the smallest character in the array that is larger than* `target`.

**Note** that the letters wrap around.

- For example, if `target == 'z'` and `letters == ['a', 'b']`, the answer is `'a'`.

 

**Example 1:**

```
Input: letters = ["c","f","j"], target = "a"
Output: "c"
```

**Example 2:**

```
Input: letters = ["c","f","j"], target = "c"
Output: "f"
```

**Example 3:**

```
Input: letters = ["c","f","j"], target = "d"
Output: "f"
```

**Example 4:**

```
Input: letters = ["c","f","j"], target = "g"
Output: "j"
```

**Example 5:**

```
Input: letters = ["c","f","j"], target = "j"
Output: "c"
```



**Solution**

重温一遍binary search 背诵模板

wrap around的edge case我们可以在开头给解决了，如果target 比所有的letters都大，那最小的那个letters[0] 就是答案

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int len = letters.length;
        if(letters[len - 1] <= target) {
            return letters[0];
        }
        int left = 0;
        int right = len - 1;
        while(left < right) {
            int mid = left  + (right - left) / 2;
            if(target >= letters[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return letters[left];
    }
}
```



------

## Shortest Word Distance

Given an array of strings `wordsDict` and two different strings that already exist in the array `word1` and `word2`, return *the shortest distance between these two words in the list*.

**Example 1:**

```
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "coding", word2 = "practice"
Output: 3
```

**Example 2:**

```
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
```

**Solution**

word可以duplicate， 所以并不能用map的方式来直接找到index解决

**Array** 题没有特定的算法，在loop的过程中我们只要track最近的word1， word2 就行了

```java
class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int i1 = -1, i2 = -1;
        int result = words.length;
        for(int i = 0; i < words.length; ++i) {
            if(word1.equals(words[i])) {
                i1 = i;
            }
            if(word2.equals(words[i])) {
                i2 = i;
            }
            if(i1 != -1 && i2 != -1) {
                result = Math.min(result, Math.abs(i1 - i2));
            }
        }
        return result;
    }
}
```



------

## Shortest Word Distance II

Design a data structure that will be initialized with a string array, and then it should answer queries of the shortest distance between two different strings from the array.

Implement the `WordDistance` class:

- `WordDistance(String[] wordsDict)` initializes the object with the strings array `wordsDict`.
- `int shortest(String word1, String word2)` returns the shortest distance between `word1` and `word2` in the array `wordsDict`.

 **Example 1:**

```
Input
["WordDistance", "shortest", "shortest"]
[[["practice", "makes", "perfect", "coding", "makes"]], ["coding", "practice"], ["makes", "coding"]]
Output
[null, 3, 1]

Explanation
WordDistance wordDistance = new WordDistance(["practice", "makes", "perfect", "coding", "makes"]);
wordDistance.shortest("coding", "practice"); // return 3
wordDistance.shortest("makes", "coding");    // return 1
```

**Solution**

先把相同的词的index全部归类到一起，比较两个word的最短距离就是比较两个list of integer 之间的最小差，**two pointer** 解决

```java
public class WordDistance {

private Map<String, List<Integer>> map;

public WordDistance(String[] words) {
    map = new HashMap<String, List<Integer>>();
    for(int i = 0; i < words.length; i++) {
        String w = words[i];
        if(map.containsKey(w)) {
            map.get(w).add(i);
        } else {
            List<Integer> list = new ArrayList<Integer>();
            list.add(i);
            map.put(w, list);
        }
    }
}

public int shortest(String word1, String word2) {
    List<Integer> list1 = map.get(word1);
    List<Integer> list2 = map.get(word2);
    int ret = Integer.MAX_VALUE;
    for(int i = 0, j = 0; i < list1.size() && j < list2.size(); ) {
        int index1 = list1.get(i), index2 = list2.get(j);
        if(index1 < index2) {
            ret = Math.min(ret, index2 - index1);
            i++;
        } else {
            ret = Math.min(ret, index1 - index2);
            j++;
        }
    }
    return ret;
}
}

```



------



## Minimum One Bit Operoations to Make Integers Zero

Given an integer `n`, you must transform it into `0` using the following operations any number of times:

- Change the rightmost (`0th`) bit in the binary representation of `n`.
- Change the `ith` bit in the binary representation of `n` if the `(i-1)th` bit is set to `1` and the `(i-2)th` through `0th` bits are set to `0`.

Return *the minimum number of operations to transform* `n` *into* `0`*.*

**Example 1:**

```
Input: n = 0
Output: 0
```

**Example 2:**

```
Input: n = 3
Output: 2
Explanation: The binary representation of 3 is "11".
"11" -> "01" with the 2nd operation since the 0th bit is 1.
"01" -> "00" with the 1st operation.
```

**Example 3:**

```
Input: n = 6
Output: 4
Explanation: The binary representation of 6 is "110".
"110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th through 0th bits are 0.
"010" -> "011" with the 1st operation.
"011" -> "001" with the 2nd operation since the 0th bit is 1.
"001" -> "000" with the 1st operation.
```

**Example 4:**

```
Input: n = 9
Output: 14
```

**Example 5:**

```
Input: n = 333
Output: 393
```



 **Solution**

```
```



------



## Design HashMap

Design a HashMap without using any built-in hash table libraries.

Implement the `MyHashMap` class:

- `MyHashMap()` initializes the object with an empty map.
- `void put(int key, int value)` inserts a `(key, value)` pair into the HashMap. If the `key` already exists in the map, update the corresponding `value`.
- `int get(int key)` returns the `value` to which the specified `key` is mapped, or `-1` if this map contains no mapping for the `key`.
- `void remove(key)` removes the `key` and its corresponding `value` if the map contains the mapping for the `key`.

 

**Example 1:**

```
Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
```

**clarification**

For simplicity, are the keys integers only?
For collision resolution, can we use chaining?
Do we have to worry about load factors?
Can we assume inputs are valid or do we have to validate them?
Can we assume this fits memory?

**Solution**

hashmap 主要有两点 hash function 的设计和 collision handling 

最简单的方法是 modulo + array, 然后用chaining 的方式来解决collision

用一个比较大的prime number 来做base of modulo

```java
class Pair<U, V> {
  public U first;
  public V second;

  public Pair(U first, V second) {
    this.first = first;
    this.second = second;
  }
}


class Bucket {
  private List<Pair<Integer, Integer>> bucket;

  public Bucket() {
    this.bucket = new LinkedList<Pair<Integer, Integer>>();
  }

  public Integer get(Integer key) {
    for (Pair<Integer, Integer> pair : this.bucket) {
      if (pair.first.equals(key))
        return pair.second;
    }
    return -1;
  }

  public void update(Integer key, Integer value) {
    boolean found = false;
    for (Pair<Integer, Integer> pair : this.bucket) {
      if (pair.first.equals(key)) {
        pair.second = value;
        found = true;
      }
    }
    if (!found)
      this.bucket.add(new Pair<Integer, Integer>(key, value));
  }

  public void remove(Integer key) {
    for (Pair<Integer, Integer> pair : this.bucket) {
      if (pair.first.equals(key)) {
        this.bucket.remove(pair);
        break;
      }
    }
  }
}

class MyHashMap {
  private int key_space;
  private List<Bucket> hash_table;

  /** Initialize your data structure here. */
  public MyHashMap() {
    this.key_space = 2069;
    this.hash_table = new ArrayList<Bucket>();
    for (int i = 0; i < this.key_space; ++i) {
      this.hash_table.add(new Bucket());
    }
  }

  /** value will always be non-negative. */
  public void put(int key, int value) {
    int hash_key = key % this.key_space;
    this.hash_table.get(hash_key).update(key, value);
  }

  /**
   * Returns the value to which the specified key is mapped, or -1 if this map contains no mapping
   * for the key
   */
  public int get(int key) {
    int hash_key = key % this.key_space;
    return this.hash_table.get(hash_key).get(key);
  }

  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  public void remove(int key) {
    int hash_key = key % this.key_space;
    this.hash_table.get(hash_key).remove(key);
  }
}
```



------



## Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```
Input: root = [2,1], p = 2, q = 1
Output: 2
```

**Solution**

**二叉树**

这个题是**lca of a binary tree**的简化版，但用那个solution也能坐

这个多了一个binary search tree的条件 所以只要找到第一个夹在p， q中间的数就是lca

```java
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root.val > p.val && root.val > q.val){
            return lowestCommonAncestor(root.left, p, q);
        }else if(root.val < p.val && root.val < q.val){
            return lowestCommonAncestor(root.right, p, q);
        }else{
            return root;
        }
    }
}
```



------



## Second Minimum Node In a Binary Tree

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly `two` or `zero` sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property `root.val = min(root.left.val, root.right.val)` always holds.

Given such a binary tree, you need to output the **second minimum** value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

  

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/15/smbt1.jpg)

```
Input: root = [2,2,5,null,null,5,7]
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/10/15/smbt2.jpg)

```
Input: root = [2,2,2]
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
```

**Solution**

**Binary Tree** 

这个题目brutal force就直接遍历所有的点，然后找到第二大的点。 这个tree的特性可以帮我们做一些减枝。root的val就是这个tree最小的值，所以只要root的val比当前的最小值大，就没有必要往下看了。

```java
class Solution {
    int min;
    int ans;
    public int findSecondMinimumValue(TreeNode root) {
        if(root == null) {
            return -1;
        }
        min = root.val;
        ans = -1;
        dfs(root);
        return ans;
    }
    
    public void dfs(TreeNode root) {
        if(root == null) {
            return;
        }
        if(ans == -1 && root.val > min) {
            ans = root.val;
        } else if (root.val > min && root.val < ans) {
            ans = root.val;
        } else if(min == root.val) {
            dfs(root.left);
            dfs(root.right);
        }
    }
}
```



------



## Sqrt(x)

Given a non-negative integer `x`, compute and return *the square root of* `x`.

Since the return type is an integer, the decimal digits are **truncated**, and only **the integer part** of the result is returned.

**Note:** You are not allowed to use any built-in exponent function or operator, such as `pow(x, 0.5)` or `x ** 0.5`.

**Example 1:**

```
Input: x = 4
Output: 2
```

**Example 2:**

```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
```

**Solution**

数学题到时候归纳到一起，背一下

最好的办法是newton's method， 比较常规的就用binary search做好了

这套题的边界条件和模板有点不一样，总结的时候想想

```java
class Solution {
  public int mySqrt(int x) {
 
    long num;
    int pivot, left = 0, right = x;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      num = (long)pivot * pivot;
      if (num > x) right = pivot - 1;
      else if (num < x) left = pivot + 1;
      else return pivot;
    }

    return right;
  }
}
```



------

## Pow(x, n)

Implement [pow(x, n)](http://www.cplusplus.com/reference/valarray/pow/), which calculates `x` raised to the power `n` (i.e., `xn`).

**Example 1:**

```
Input: x = 2.00000, n = 10
Output: 1024.00000
```

**Example 2:**

```
Input: x = 2.10000, n = 3
Output: 9.26100
```

**Example 3:**

```
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```

**Solution**

需要注意负数的情况

**math**, **recursion**

```java
class Solution {
   private double fastPow(double x, long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
    public double myPow(double x, int n) {
        // Integer.MIN_VALUE 没法转化为正数，所以需要用long
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }
}
```







------



## Lowest Common Ancestor of a Binary Tree III

Given two nodes of a binary tree `p` and `q`, return *their lowest common ancestor (LCA)*.

Each node will have a reference to its parent node. The definition for `Node` is below:

```
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
```

According to the **[definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor)**: "The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants (where we allow **a node to be a descendant of itself**)."

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5 since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```
Input: root = [1,2], p = 1, q = 2
Output: 1
```



**Solution**

**Set** 从两个点往上走，最先遇到的点就是答案了 

```java
class Solution {
    
    public Node lowestCommonAncestor(Node p, Node q) {
        Set<Node> set = new HashSet<>();
        while(p != null) {
            set.add(p);
            p = p.parent;
        }
        while(q != null) {
            if(set.contains(q)) {
                return q;
            }
            q = q.parent;
        }
        throw new IllegalArgumentException("dont have a valid result");
    }
}
```



------

## Find Leaves of Binary Tree

Given the `root` of a binary tree, collect a tree's nodes as if you were doing this:

- Collect all the leaf nodes.
- Remove all the leaf nodes.
- Repeat until the tree is empty. 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/16/remleaves-tree.jpg)

```
Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
```

**Example 2:**

```
Input: root = [1]
Output: [[1]]
```

**Solution**

**二叉树 recursion dfs** 只要把每个点的depth记录下来，然后组合成答案就可以了 

用bfs记录depth

```java
class Solution {
    public List<List<Integer>> findLeaves(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        Map<TreeNode, Integer> map = new HashMap<>(); 
        int totalDepth = dfs(root, map);
        for(int i = 0; i < totalDepth; ++i) {
            result.add(new ArrayList<>());
        }
        for(TreeNode node : map.keySet()) {
            result.get(map.get(node) - 1).add(node.val);
        }
        return result;
    }
    
    public int dfs(TreeNode root, Map<TreeNode, Integer> map) {
        if(root == null) {
            return 0;
        }
        int depth = Math.max(dfs(root.left, map), dfs(root.right, map)) + 1;
        map.put(root, depth);
        return depth;
    }
}
```



------



## Minimum Remove to Make Valid Parentheses

Given a string s of `'('` , `')'` and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting *parentheses string* is valid and return **any** valid string.

Formally, a *parentheses string* is valid if and only if:

- It is the empty string, contains only lowercase characters, or
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
- It can be written as `(A)`, where `A` is a valid string. 

**Example 1:**

```
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
```

**Example 2:**

```
Input: s = "a)b(c)d"
Output: "ab(c)d"
```

**Example 3:**

```
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
```

**Example 4:**

```
Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
```

**Solution**

**stack** parentheses 也是一个有很多题目的系列了，可以归纳一下

```java
class Solution {
    public String minRemoveToMakeValid(String s) {
        Set<Integer> indexesToRemove = new HashSet<>();
        Deque<Integer> stack = new ArrayDeque<>();
        // 并不用把)也push进去，这样就不用pair来记录了 
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } if (s.charAt(i) == ')') {
                if (stack.isEmpty()) {
                    indexesToRemove.add(i);
                } else {
                    stack.pop();
                }
            }
        }
        // Put any indexes remaining on stack into the set.
        while (!stack.isEmpty()) indexesToRemove.add(stack.pop());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (!indexesToRemove.contains(i)) {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}
```



------



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



## Minimum One Bit Operations to Make Integers Zero

Given an integer `n`, you must transform it into `0` using the following operations any number of times:

- Change the rightmost (`0th`) bit in the binary representation of `n`.
- Change the `ith` bit in the binary representation of `n` if the `(i-1)th` bit is set to `1` and the `(i-2)th` through `0th` bits are set to `0`.

Return *the minimum number of operations to transform* `n` *into* `0`*.*

 **Example 1:**

```
Input: n = 0
Output: 0
```

**Example 2:**

```
Input: n = 3
Output: 2
Explanation: The binary representation of 3 is "11".
"11" -> "01" with the 2nd operation since the 0th bit is 1.
"01" -> "00" with the 1st operation.
```

**Example 3:**

```
Input: n = 6
Output: 4
Explanation: The binary representation of 6 is "110".
"110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th through 0th bits are 0.
"010" -> "011" with the 1st operation.
"011" -> "001" with the 2nd operation since the 0th bit is 1.
"001" -> "000" with the 1st operation.
```

**Example 4:**

```
Input: n = 9
Output: 14
```

**Example 5:**

```
Input: n = 333
Output: 393
```

**Solution**

这题没有完全搞懂意思，但我想和其他**bit operation**的题目放一起做，对整个bit operation做个复习



Note that the number of operations for `n` to become 0 is the same as the number of operations for 0 to become `n`...

Let's see how it can be done for numbers that are powers of 2.
`1 -> 0` => 1
`10 -> 11 -> 01 -> ...` => 2 + 1
`100 -> 101 -> 111 -> 110 -> 010 -> ...` => 4 + 2 + 1
`1000 -> 1001 -> 1011 -> 1010 -> 1110 -> 1111 -> 1101 -> 1100 -> 0100 -> ...` => 8 + 4 + 2 + 1
We can find that for `2^n`, it needs `2^(n+1) - 1` operations to become 0.



Now suppose we want to know the number of operations for `1110` to become `0`. We know it takes 15 operations for 0 to become `1000`, and it takes 4 operations for `1000` to become `1110`. We get the solution by `15 - 4`.
Note that `4` here is the number of operations from `1000` to become `1110`, which is the same as the number of operations from `000` to `110` (ignoring the most significant bit), and it can be computed recursively. The observation gives us: `minimumOneBitOperations(1110) + minimumOneBitOperations(0110) = minimumOneBitOperations(1000)`.



From the above intuition, we can reduce `n` bit by bit, starting from the most significant bit.

```java
int minimumOneBitOperations(int n) {
    if (n <= 1)
        return n;
    int bit = 0;
    while ((1 << bit) <= n)
        bit++;
    return ((1 << bit) - 1) - minimumOneBitOperations(n - (1 << (bit-1)));
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



## Max Points on a Line

Given an array of `points` where `points[i] = [xi, yi]` represents a point on the **X-Y** plane, return *the maximum number of points that lie on the same straight line*.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg)

```
Input: points = [[1,1],[2,2],[3,3]]
Output: 3
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg)

```
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
```

**Solution**

判断三个点是否在同一条线上，需要任两点的slope相同

所以对于每个点，我们只要去计算它与其他点的slope然后将相同的归纳到一起就是一条线上最大的点数

几个edge case 需要处理好

```java
class Solution {
    public int maxPoints(int[][] points) {
        if(points.length == 0) {
            return 0;
        }
        int result = 1;
        for(int i = 0; i < points.length; ++i) {
            Map<Double, Integer> map = new HashMap<>();
            int sameNum = 0;
            for(int j = i + 1; j < points.length; ++j) {
                double slope;
                if(points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                  // 两个点相同
                    sameNum++;
                    continue;
                } else if(points[j][0] == points[i][0]) {
                  // slope 是无限大
                    slope = Double.MAX_VALUE;
                } else if(points[j][1] == points[i][1]){
                    // java 浮点数有正负0
                    slope = 0;
                } else {
                    slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                }
                map.put(slope, map.getOrDefault(slope, 0) + 1);
            }
            for(int count : map.values()) {
                result = Math.max(result, count + sameNum + 1);
            }
           
        }
        return result;
    }
}
```



------

## Integer to Roman

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, `2` is written as `II` in Roman numeral, just two one's added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral.

 

**Example 1:**

```
Input: num = 3
Output: "III"
```

**Example 2:**

```
Input: num = 4
Output: "IV"
```

**Example 3:**

```
Input: num = 9
Output: "IX"
```

**Example 4:**

```
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
```

**Example 5:**

```
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

**Solution**

非常好的solution 背就完事了。 把所有的roman和数字一一对应，然后从最的大开始减，减到比它小后在下一个

有点**greedy**的思想

```java
class Solution {
    public String intToRoman(int num){
	if (num < 1 || num > 3999) return "";
	
	StringBuilder result = new StringBuilder();
	
	String[] roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	
	int i = 0;
            //iterate until the number becomes zero, NO NEED to go until the last element in roman array
	while (num >0) {
		while ( num >= values[i]) {
			num -= values[i];
			result.append(roman[i]);
		}
		i++;
	}
	return result.toString();
}
}
```



------

## Binary Tree Upside Down

Given the `root` of a binary tree, turn the tree upside down and return *the new root*.

You can turn a binary tree upside down with the following steps:

1. The original left child becomes the new root.
2. The original root becomes the new right child.
3. The original right child becomes the new left child.

![img](https://assets.leetcode.com/uploads/2020/08/29/main.jpg)

The mentioned steps are done level by level, it is **guaranteed** that every node in the given tree has either **0 or 2 children**.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/08/29/updown.jpg)

```
Input: root = [1,2,3,4,5]
Output: [4,5,2,null,null,3,1]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [1]
Output: [1]
```

**Solution**

很难理解，下次复习的时候看看能不能想起来

**Binary Tree** 右子树不用去考虑

**Iterative的方法下次看要再做一遍**

```java
class Solution {
    public TreeNode upsideDownBinaryTree(TreeNode root) {
      if(root == null || root.left == null) {
          return root;
      }
      // new root 就是最左边的那个点
      TreeNode newRoot = upsideDownBinaryTree(root.left);
      root.left.left = root.right;   // node 2 left children
      root.left.right = root;         // node 2 right children
      root.left = null;
      root.right = null;
      return newRoot;
  }
}

class Solution {
 public TreeNode upsideDownBinaryTree(TreeNode root) {
    TreeNode curr = root;
    TreeNode next = null;
    TreeNode temp = null;
    TreeNode prev = null;
    
    while(curr != null) {
        next = curr.left;
        
        // swapping nodes now, need temp to keep the previous right child
        curr.left = temp;
        temp = curr.right;
        curr.right = prev;
        
        prev = curr;
        curr = next;
    }
    return prev;
}  
}
```



------



##  Exclusive Time of Functions

On a **single-threaded** CPU, we execute a program containing `n` functions. Each function has a unique ID between `0` and `n-1`.

Function calls are **stored in a [call stack](https://en.wikipedia.org/wiki/Call_stack)**: when a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is **the current function being executed**. Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.

You are given a list `logs`, where `logs[i]` represents the `ith` log message formatted as a string `"{function_id}:{"start" | "end"}:{timestamp}"`. For example, `"0:start:3"` means a function call with function ID `0` **started at the beginning** of timestamp `3`, and `"1:end:2"` means a function call with function ID `1` **ended at the end** of timestamp `2`. Note that a function can be called **multiple times, possibly recursively**.

A function's **exclusive time** is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for `2` time units and another call executing for `1` time unit, the **exclusive time** is `2 + 1 = 3`.

Return *the **exclusive time** of each function in an array, where the value at the* `ith` *index represents the exclusive time for the function with ID* `i`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/04/05/diag1b.png)

```
Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3,4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 for units of time and reaches the end of time 1.
Function 1 starts at the beginning of time 2, executes for 4 units of time, and ends at the end of time 5.
Function 0 resumes execution at the beginning of time 6 and executes for 1 unit of time.
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.
```

**Example 2:**

```
Input: n = 1, logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
Output: [8]
Explanation:
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls itself again.
Function 0 (2nd recursive call) starts at the beginning of time 6 and executes for 1 unit of time.
Function 0 (initial call) resumes execution at the beginning of time 7 and executes for 1 unit of time.
So function 0 spends 2 + 4 + 1 + 1 = 8 units of total time executing.
```

**Example 3:**

```
Input: n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
Output: [7,1]
Explanation:
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls function 1.
Function 1 starts at the beginning of time 6, executes 1 units of time, and ends at the end of time 6.
Function 0 resumes execution at the beginning of time 6 and executes for 2 units of time.
So function 0 spends 2 + 4 + 1 = 7 units of total time executing, and function 1 spends 1 unit of total time executing.
```

**Example 4:**

```
Input: n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"]
Output: [8,1]
```

**Example 5:**

```
Input: n = 1, logs = ["0:start:0","0:end:0"]
Output: [1]
```

**Solution**

用**stack**来实现 每次结束一个function i， 如果发现stack中还有继续在跑的function j，则把i持续的时间从还在跑的function中减去，因为这一段时间是没有在跑j的

```java
class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        Stack<Log> stack = new Stack<>();
        int [] result = new int[n];
        for(String content: logs) {
            Log log = new Log(content);
            if(log.isStart) {
                stack.push(log);
            } else {
                Log start = stack.pop();
                int lastTime = log.time - start.time + 1;
                result[start.id] += lastTime;
                if(!stack.isEmpty()) {
                    result[stack.peek().id] -= lastTime;
                }
            }
        }
        return result;
    }
}
// 非常好的写法
class Log{
    public int id;
    public boolean isStart;
    public int time;
    
    public Log(String content) {
        String[] strs = content.split(":");
        id = Integer.valueOf(strs[0]);
        isStart = strs[1].equals("start");
        time = Integer.valueOf(strs[2]);
    }
}
```



------



## Permutations II

Given a collection of numbers, `nums`, that might contain duplicates, return *all possible unique permutations **in any order**.*

**Example 1:**

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

**Example 2:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Solution**

Permutations 这个系列的题目放到一起看看

```
```



------

## Sort Transformed Array

Given a **sorted** integer array `nums` and three integers `a`, `b` and `c`, apply a quadratic function of the form `f(x) = ax2 + bx + c` to each element `nums[i]` in the array, and return *the array in a sorted order*.

 

**Example 1:**

```
Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]
```

**Example 2:**

```
Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]
```

**Solution**

**Two pointer** 还考抛物线的知识，完全忘记了都，a > 0 开口向上，a < 0 开头向下  

Always start handling from the two ends of the parabola. The difference is when `a > 0`, they are larger at two ends, when `a < 0`, they are smaller at two ends. So when `a > 0`, we just start to fill out the result array from end to beginning, in other case, we start filling out it from start to the end of result array.

```java
public class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int n = nums.length;
        int[] sorted = new int[n];
        int i = 0, j = n - 1;
      // 向上开口，两边的数就大，所以要从后面开始填起，反之就从前面开始填
        int index = a >= 0 ? n - 1 : 0;
        while (i <= j) {
            if (a >= 0) {
                sorted[index--] = quad(nums[i], a, b, c) >= quad(nums[j], a, b, c) ? quad(nums[i++], a, b, c) : quad(nums[j--], a, b, c);
            } else {
                sorted[index++] = quad(nums[i], a, b, c) >= quad(nums[j], a, b, c) ? quad(nums[j--], a, b, c) : quad(nums[i++], a, b, c);
            }
        }
        return sorted;
    }
    
    private int quad(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
}
```



------

## Merge k Sorted Lists

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it.* 

**Example 1:**

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

**Example 2:**

```
Input: lists = []
Output: []
```

**Example 3:**

```
Input: lists = [[]]
Output: []
```

**Solution**

用pq就可以轻松解决，把每条list的头放进pq里，每pop一个就把它后面的node放进pq里

Time complexity : O(Nlog k) n 是所有的node数，k是linked list数

还可以两两merge，来节省空间

```java
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummyHead = new ListNode();
        ListNode current = dummyHead;
        // init
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        for(int i = 0; i < lists.length; ++i) {
        // edge cases 里面有null的list
            if(lists[i] != null) {
                pq.add(lists[i]);
            }
        }
        while(!pq.isEmpty()) {
            ListNode n = pq.poll();
            current.next = n;
            if(n.next != null) {
                pq.add(n.next);
                n.next = null;
            }
            current = n;
        }
        return dummyHead.next;
        
    }
}
```



------

##  Valid Triangle Number

Given an integer array `nums`, return *the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle*.

**Example 1:**

```
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
```

**Example 2:**

```
Input: nums = [4,2,3,4]
Output: 4
```

**Solution**

two pointer 

三角形 小的两条边之和大于第三边，所以我们先sort， 然后选定前两条边 每次挪动第二条边，第三条边可以往前走

```Java
public class Solution {
    public int triangleNumber(int[] nums) {
        int count = 0;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.length - 1 && nums[i] != 0; j++) {
                while (k < nums.length && nums[i] + nums[j] > nums[k])
                    k++;
                count += k - j - 1;
            }
        }
        return count;
    }
}
```

------



## Factor Combinations

Numbers can be regarded as the product of their factors.

- For example, `8 = 2 x 2 x 2 = 2 x 4`.

Given an integer `n`, return *all possible combinations of its factors*. You may return the answer in **any order**.

**Note** that the factors should be in the range `[2, n - 1]`.

**Example 1:**

```
Input: n = 1
Output: []
```

**Example 2:**

```
Input: n = 12
Output: [[2,6],[3,4],[2,2,3]]
```

**Example 3:**

```
Input: n = 37
Output: []
```

**Example 4:**

```
Input: n = 32
Output: [[2,16],[4,8],[2,2,8],[2,4,4],[2,2,2,4],[2,2,2,2,2]]
```



**Solution**

**dfs**

```java
class Solution {
public List<List<Integer>> getFactors(int n) {
    List<List<Integer>> res = new LinkedList<>();
    backtrack(2, n, new LinkedList<>(), res);
    return res;
}

void backtrack(int start, int n, List<Integer> list, List<List<Integer>> res) {
  // [3, 4] [4, 3] 是重复的，所以不用去看 i > sqrt(n)的那部分
    for(int i = start; i * i <= n; i++) {
        if(n % i == 0) {
            list.add(i);
            list.add(n / i);
            res.add(new LinkedList<>(list));
            list.remove(list.size() - 1);
            backtrack(i, n / i, list, res);
            list.remove(list.size() - 1);
        }
    }
}
}
```



------



## Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.

**Follow up:** Can you solve it with time complexity `O(height of tree)`?

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/04/del_node_1.jpg)

```
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
```

**Example 2:**

```
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
```

**Example 3:**

```
Input: root = [], key = 0
Output: []
```

**Solution**

BST的基本操作，但要写的没毛病还是需要点功夫

```java
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode prev = null, target = root;
        while(target != null && target.val != key) {
            prev = target;
          // 这个地方一定要用if else 要不然很容易下面那个if出 null pointer错误
            if(key < target.val) { 
                target = target.left;
            } else {
                target = target.right;
            }
        }
        
        if(target == null) {
            return root;
        }
        TreeNode next = mergeChildren(target.left, target.right);
        
        if(prev != null) {
            if(prev.val > target.val) prev.left = next;
            if(prev.val < target.val) prev.right = next;
        } else {
            root = next;
        }
        return root;
    }
    
    public TreeNode mergeChildren(TreeNode left, TreeNode right) {
        if(left == null) {
            return right;
        } else if(right == null) {
            return left;
        } else {
            TreeNode cur = right;
            while(cur.left != null) {
                cur = cur.left;
            }
            cur.left = left;
            return right;
        }
    }
}
```



------



##  Bomb Enemy

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



------



## Partition to K Equal Sum Subsets

Given an integer array `nums` and an integer `k`, return `true` if it is possible to divide this array into `k` non-empty subsets whose sums are all equal.

**Example 1:**

```
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
```

**Example 2:**

```
Input: nums = [1,2,3,4], k = 3
Output: false
```

**Solution**

**backtracking** 做的坑坑巴巴的，这个要在看看

TimeComplexity : O(k * 2^n) upper bound

Space complexity: O(n)

```java
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        // calculate total sum
        int totalSum = IntStream.of(nums).sum();
        // handle edge cases
        if(k == 0 || totalSum % k != 0) {
            return false;
        }
        return dfs(0, k, new boolean [nums.length], totalSum / k, 0, nums);
        
    }
    
    public boolean dfs(int start, int k, boolean[] visited, int target, int cur, int[] nums) {
        
        if(k == 1) {
            // 把前面的buckets都fill 完了回后，剩下的自然就成立了 
            return true;
        }
        if(cur == target) {
            // 一轮bucket填完以后要重头开始
            return dfs(0, k - 1, visited, target, 0, nums);
        }
        for(int i = start; i < nums.length; ++i) {
            if(!visited[i] && cur + nums[i] <= target) {
                visited[i] = true;
                if(dfs(i + 1, k, visited, target, cur + nums[i], nums)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
}

```



------

## Graph Valid Tree

You have a graph of `n` nodes labeled from `0` to `n - 1`. You are given an integer n and a list of `edges` where `edges[i] = [ai, bi]` indicates that there is an undirected edge between nodes `ai` and `bi` in the graph.

Return `true` *if the edges of the given graph make up a valid tree, and* `false` *otherwise*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/12/tree1-graph.jpg)

```
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/12/tree2-graph.jpg)

```
Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
```

 

**Solution**

**Binary tree** **dfs**

是否是tree，需要没有环，且每个点都连通

```java
class Solution {
    public boolean validTree(int n, int[][] edges) {
        // build graph
        Map<Integer, List<Integer> > graph = new HashMap<>();
        for(int i = 0; i < n; ++i) {
            graph.put(i, new ArrayList<>());
        }    
        for(int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        
        // dfs to make sure there is no circle
        boolean[] visited = new boolean[n];
        if(isCircleExist(0, -1, graph, visited)) {
            return false;
        }
        
        // 每个点都必须要连着
        for(int i = 0; i < n; ++i) {
            if(visited[i] == false) {
                return false;
            }
        }
        
        return true;
    }
    
    public boolean isCircleExist(int cur, int parent, Map<Integer, List<Integer> > graph, boolean[] visited) {
        // base case
        if(visited[cur] == true) {
            // find circle
            return true;
        }
        visited[cur] = true;
        for(int next : graph.get(cur)) {
            if(next != parent) {
                if(isCircleExist(next, cur, graph, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    
}
```



------

## Find K Pairs with Smallest Sums

You are given two integer arrays `nums1` and `nums2` sorted in **ascending order** and an integer `k`.

Define a pair `(u, v)` which consists of one element from the first array and one element from the second array.

Return *the* `k` *pairs* `(u1, v1), (u2, v2), ..., (uk, vk)` *with the smallest sums*.

**Example 1:**

```
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
```

**Example 2:**

```
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
```

**Example 3:**

```
Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
```

**Solution**

**priority queue**

```java
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<List<Integer>> result = new ArrayList<>();
       
        if(nums1.length == 0 || nums2.length == 0 || k == 0) {
            return result;
        }
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> nums1[a[0]] + nums2[a[1]] - nums1[b[0]] - nums2[b[1]]);
        
        for(int i = 0; i < nums1.length && i < k; ++i) {
            pq.add(new int[]{i, 0});
        }
        
        while(k > 0 && !pq.isEmpty()) {
            int[] cur = pq.poll();
            List<Integer> pair = new ArrayList<>();
            pair.add(nums1[cur[0]]);
            pair.add(nums2[cur[1]]);
            result.add(pair);
            if(cur[1] + 1 < nums2.length) {
                pq.add(new int[]{cur[0], cur[1] + 1});
            }
            k--;
        }
        return result;
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



------

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



------



## Closest Binary Search Tree Value II

Given the `root` of a binary search tree, a `target` value, and an integer `k`, return *the* `k` *values in the BST that are closest to the* `target`. You may return the answer in **any order**.

You are **guaranteed** to have only one unique set of `k` values in the BST that are closest to the `target`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/12/closest1-1-tree.jpg)

```
Input: root = [4,2,5,1,3], target = 3.714286, k = 2
Output: [4,3]
```

**Example 2:**

```
Input: root = [1], target = 0.000000, k = 1
Output: [1]
```

**Solution**

The idea is compare the part that smaller than target and the larger part. We can use two stack to track these two parts. inorder traversal will give us the acending order and the reverse version of inorder traversal will give us the descending order.

```java
class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
          List<Integer> res = new ArrayList<>();

        Stack<Integer> s1 = new Stack<>(); // predecessors
        Stack<Integer> s2 = new Stack<>(); // successors

        inorder(root, target, false, s1);
        inorder(root, target, true, s2);

        while (k-- > 0) {
        if (s1.isEmpty())
          res.add(s2.pop());
        else if (s2.isEmpty())
          res.add(s1.pop());
        else if (Math.abs(s1.peek() - target) < Math.abs(s2.peek() - target))
          res.add(s1.pop());
        else
          res.add(s2.pop());
        }

        return res;
    }
    
    private void inorder (TreeNode root, double target, boolean reverse, Stack<Integer> stack) {
        if(root == null) {
            return;
        }
        inorder(reverse ? root.right:root.left, target, reverse, stack);
        // early terminate, we only need the part that is smaller than target or larger than target
        if((reverse && root.val <= target) || (!reverse && root.val > target)) {
            return;
        }
        stack.push(root.val);
        inorder(reverse ? root.left:root.right, target, reverse, stack);
    }
}
```



------



##  Maximum Profit in Job Scheduling

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



------



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

`D[i][j]` which is an edit distance between the first `i` characters of `word1` and the first `j` characters of `word2`.

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

```
```

