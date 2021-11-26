# MAX Stack

## Brute Force

Two Stack, one is for storing typical data, another is for storing max data [2,1,5,3,9] and [2,2,5,5,9]. O(N)

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
        
        while (top() != max) 
            buffer.push(pop());
        // This time pop the max
        pop();
        while (!buffer.isEmpty()) 
            push(buffer.pop());
        return max;
    }
}
```

## Using heap

Using a max heap for storing data, using a global id to identify repeat number. And a lazy pop, only pop when we found there is a deleted element. Use a wrapper to enclose this project.

```java
class MaxStack {
    private Queue<Node> pq;
    private Stack<Node> st;
    private Set<Node> popped;
    private int id;

    /** initialize your data structure here. */
    public MaxStack() {
        id = 0;
        pq = new PriorityQueue<>((a, b) -> {
            if (a.val == b.val) {
                return Integer.compare(b.id, a.id);
            }
            
            return Integer.compare(b.val, a.val);
        });
        
        st = new Stack<>();
        popped = new HashSet<>();
    }
    
    public void push(int x) {
        Node cur = new Node(x, id++);
        st.push(cur);
        pq.offer(cur);
    }
    
    public int pop() {
        clear(true);
        Node cur = st.pop();
        popped.add(cur);
        return cur.val;
    }
    
    public int top() {
        clear(true);
        return st.peek().val;
    }
    
    public int peekMax() {
        clear(false);
        return pq.peek().val;
    }
    
    public int popMax() {
        clear(false);
        Node cur = pq.poll();
        popped.add(cur);
        return cur.val;
    }
    
    public void clear (boolean isStack) {
        if (isStack) {
            while (!st.isEmpty() && popped.contains(st.peek())) {
                st.pop();
            }
        } else {
            while (!pq.isEmpty() && popped.contains(pq.peek())) {
                pq.poll();
            }
        }
    }
    
    class Node {
        private int val;
        private int id;
        
        public Node (int val, int id) {
            this.val = val;
            this.id = id;
        }
    }
}
```

# Minimum One Bit Operations to Make Integers Zero

By listing some example we can find regular pattern that 2 ^ k takes 2 ^ (k + 1) - 1 operations like 1 -> 1, 2 -> 3, 4 -> 7 , idea is find 1xxxxx (n) -> 110000 -> 10000 (1 step) -> 0 (2 ^ (k +1) - 1) where k stand for number of bits - 1.

```java
class Solution {
    public int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        
        int k = 1;
        
        // 3, 0b11 yield k = 0b10
        // next 0b11xxx pattern is 0b1
        // k - 1 is the number to
        // get result of 0b1
        while ((k << 1) <= n) {
            k <<= 1;
        } 
        
        // Same example k = 0b10
        // after this operation become 0b11
        // it takes one step to 0b1
        int target = k ^ (k >> 1);
        
        return minimumOneBitOperations(n ^ target) + 1 + k - 1;
    }
}
```

# Count Different Palindromic Subsequences

```java
class Solution {
    final int MOD = (int)Math.pow(10, 9) + 7;
    
    public int countPalindromicSubsequences(String s) {
        int n = s.length();
        int[][][] dp = new int[4][n][n];

        // Initialization for substring length 1
        for (int k = 0;k < 4;k++) {
            char c = (char)('a' + k);
            for (int i = 0;i < n;i++) {
                if (s.charAt(i) == c) {
                    dp[k][i][i] = 1;
                }
            }
        }
        
        // Initialization for substring length 2
        for (int k = 0;k < 4;k++) {
            char c = (char)('a' + k);
            for (int i = 0;i + 1 < n;i++) {
                if (s.charAt(i) == c && s.charAt(i + 1) == c) {
                    dp[k][i][i + 1] = 2;
                } else if (s.charAt(i) == c || s.charAt(i + 1) == c) {
                    dp[k][i][i + 1] = 1;
                }
            }
        }

        for (int l = 3; l <= n; l++) {
            for (int i = 0; i + l <= n; i++) {
                int j = i + l - 1;
                for (int k = 0; k < 4; k++) {
                    char c = (char) ('a' + k);
                    
                    if (s.charAt(i) == c && s.charAt(j) == c) {
                        dp[k][i][j] = 2 + sumAll(dp, i + 1, j - 1);
                    } else if (s.charAt(i) == c) {
                        dp[k][i][j] = dp[k][i][j - 1];
                    } else if (s.charAt(j) == c) {
                        dp[k][i][j] = dp[k][i + 1][j];
                    } else {
                        dp[k][i][j] = dp[k][i + 1][j - 1];
                    }
                }
            }
        }

        return sumAll(dp, 0, n - 1);
    }

    public int sumAll(int[][][] dp, int i, int j) {
        int res = 0;
        
        for (int k = 0;k < 4;k++) {
            res += dp[k][i][j];
            res %= MOD;
        }
        
        return res;
    }
}
```

# Edit Distance

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        
        int[][] dp = new int[l1 + 1][l2 + 1];
        
        for (int i = 1;i <= l1;i++) {
            dp[i][0] = i;
        }
        
        for (int j = 1;j <= l2;j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1;i <= l1;i++) {
            for (int j = 1;j <= l2;j++) {
                char c1 = word1.charAt(i - 1);
                char c2 = word2.charAt(j - 1);
                
                dp[i][j] = dp[i - 1][j - 1];
                
                if (c1 != c2) {
                    dp[i][j] = Math.min(dp[i][j], Math.min(dp[i - 1][j], dp[i][j - 1]));
                    dp[i][j]++;
                }
            }
        }
        
        return dp[l1][l2];
    }
}
```

# Closest Binary Search Tree Value II

```java
class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        Stack<TreeNode> suc = new Stack<>();
        Stack<TreeNode> pre = new Stack<>();
        List<Integer> res = new ArrayList<>();
        
        // Initialize stack for inorder predecessor node of the target
        TreeNode cur = root;
        while (cur != null) {
            if (cur.val >= target) {
                suc.push(cur);
                cur = cur.left;
            } else {
                pre.push(cur);
                cur = cur.right;
            }
        }   
        
        int cnt = k;
        while (cnt > 0) {
            if (suc.isEmpty() && pre.isEmpty()) throw new RuntimeException("Invalid input!");
            
            if (suc.isEmpty()) {
                res.add(getNextPre(pre));
            } else if (pre.isEmpty()) {
                res.add(getNextSuc(suc));
            } else {
                if (compare(suc.peek(), pre.peek(), target) > 0) {
                    res.add(getNextPre(pre));
                } else {
                    res.add(getNextSuc(suc));
                }
            }
            
            cnt--;
        }
        
        return res;
    }
    
    // Iterator to get the next node that is smaller than target
    public int getNextSuc(Stack<TreeNode> suc) {
        TreeNode cur = suc.pop();
        int res = cur.val;
        cur = cur.right;
        while (cur != null) {
            suc.push(cur);
            cur = cur.left;
        }
        
        return res;
    }
    
    // Iterator to get the next node that is larger than target
    public int getNextPre(Stack<TreeNode> pre) {
        TreeNode cur = pre.pop();
        int res = cur.val;
        cur = cur.left;
        while (cur != null) {
            pre.push(cur);
            cur = cur.right;
        }
        
        return res;
    }
    
    // Shortcut function for comparing target
    public int compare(TreeNode a, TreeNode b, double target) {
        return Double.compare(Math.abs(a.val - target), Math.abs(b.val - target));
    }
}
```

# Serialize and De-serialize Binary Tree

```java
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) return "";
        StringBuilder sb = new StringBuilder();
        
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        
        // Use a set to store the null node
        Set<TreeNode> nullNodeSet = new HashSet<>();
        
        while (q.size() > 0) {
            TreeNode now = q.poll();
            
            // Null Case
            if (nullNodeSet.contains(now)) {
               sb.append("#,");
                continue;
            }
            
            sb.append(now.val);
            sb.append(',');
            
            if (now.left == null) {
                TreeNode leftNull = new TreeNode(0);
                nullNodeSet.add(leftNull);
                q.offer(leftNull);
            } else {
                q.offer(now.left);
            }
            
            if (now.right == null) {
                TreeNode rightNull = new TreeNode(0);
                nullNodeSet.add(rightNull);
                q.offer(rightNull);
            } else {
                q.offer(now.right);
            }
        }
        
        int end = sb.length() - 1;
        
        while (sb.charAt(end) == '#' || sb.charAt(end) == ',') {
            end--;
        }
        
        return sb.delete(end + 1, sb.length()).toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.isEmpty()) return null;
        
        System.out.println(data);
        
        System.out.print(data);
        
        String[] vals = data.split(",");
        int cur = 1;
        
        Queue<TreeNode> q = new LinkedList<>();
        TreeNode root = new TreeNode(Integer.valueOf(vals[0]));
        q.offer(root);
        
        while (q.size() > 0) {
            TreeNode now = q.poll();
            
            if (cur == vals.length) break;
            String lval = vals[cur++];
            
            if (!lval.equals("#")) {
                TreeNode left = new TreeNode(Integer.valueOf(lval));
                now.left = left;
                q.offer(left);
            }
            
            if (cur == vals.length) break;
            String rval = vals[cur++];
            
            if (!rval.equals("#")) {
                TreeNode right = new TreeNode(Integer.valueOf(rval));
                now.right = right;
                q.offer(right);
            }
        }
        
        return root;
    }
}
```

# Maximum Profit in Job Scheduling

```java
class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        
        Node[] jobs = new Node[n];
        
        for (int i = 0;i < n;i++) {
            jobs[i] = new Node(startTime[i], endTime[i], profit[i]);
        }
        
        Arrays.sort(jobs, (a, b) -> Integer.compare(a.end, b.end));
        
        int[] dp = new int[n + 1];
        
        for (int i = 1;i <= n;i++) {
            dp[i] = Math.max(dp[i - 1], jobs[i - 1].profit);
            
            for (int j = i - 1;j > 0;j--) {
                if (jobs[j - 1].end <= jobs[i - 1].start) {
                    dp[i] = Math.max(dp[i], jobs[i - 1].profit + dp[j]);
                    break;
                }
            }
        }
        
        return dp[n];
    }
    
    class Node {
        int start;
        int end;
        int profit;
        
        public Node(int start, int end, int profit) {
            this.start = start;
            this.end = end;
            this.profit = profit;
        }
    }
}
```

# Paint House II

```java
class Solution {
    public int minCostII(int[][] costs) {
        int n = costs.length, k = costs[0].length;
        int[][] dp = new int[n][k];
        
        // [value, index] to capture the minimum two element
        Queue<int[]> maxHeap = new PriorityQueue<>((a, b) -> Integer.compare(b[0], a[0]));
        
        // Initialization so that we know the dp first and top 2 minimum value
        for (int j = 0;j < k;j++) {
            dp[0][j] = costs[0][j];
            
            if (maxHeap.size() == 2 && maxHeap.peek()[0] > costs[0][j])
                maxHeap.poll();
            
            if (maxHeap.size() < 2)
                maxHeap.offer(new int[] {costs[0][j], j});
        }
        
        for (int i = 1;i < n;i++) {
            int[] secondMin = maxHeap.poll(), firstMin = maxHeap.poll();
            
            for (int j = 0;j < k;j++) {
                // Only when current column is as same as previous minimum column
                // we need to update answer with secondMin
                if (j == firstMin[1]) {
                    dp[i][j] = costs[i][j] + secondMin[0];
                } else {
                    dp[i][j] = costs[i][j] + firstMin[0];
                }
                
                // Update the top 2 smallest element
                if (maxHeap.size() == 2 && maxHeap.peek()[0] > dp[i][j])
                    maxHeap.poll();
            
                if (maxHeap.size() < 2)
                    maxHeap.offer(new int[] {dp[i][j], j});
            }
        }
        
        int res = Integer.MAX_VALUE;
        
        for (int j = 0;j < k;j++) {
            res = Math.min(res, dp[n - 1][j]);
        }
        
        return res;
    }
}
```

# Minimum Window Substring

```java
class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) return "";
        
        String res = "";
        int minLen = Integer.MAX_VALUE;
        
        int[] hash = new int[256];
        
        for (char c : t.toCharArray()) hash[c]++;
        
        int r = 0, cnt = t.length();
        for (int l = 0;l < s.length();l++) {
            while (r < s.length() && cnt > 0) {
                char c = s.charAt(r);
                
                if (hash[c] >= 1) {
                    cnt--;
                }
                
                hash[c]--;
                r++;
            }
            
            if (cnt == 0 && r - l < minLen) {
                minLen = r - l;
                res = s.substring(l, r);
            }
            
            char c = s.charAt(l);
            
            if (hash[c] == 0) cnt++;
            hash[c]++;
        }
        
        return res;
    }
}
```

# Text Justification

```java
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();

        if (words == null || words.length == 0) return res;

        int i = 0;

        while (i < words.length) {
            int totalLen = 0;
            List<String> line = new ArrayList<>();
            
            while (i < words.length && totalLen + words[i].length() <= maxWidth) {
                line.add(words[i]);
                totalLen += words[i].length() + 1;
                i++;
            }
            
            if (i == words.length) {
                res.add(handleLast(line, totalLen - 1, maxWidth));
            } else if (line.size() == 1) {
                res.add(handleSingle(line, maxWidth));
            } else {
                res.add(handleNormal(line, totalLen - 1, maxWidth));
            }
        }

        return res;
    }

    public String handleNormal(List<String> line, int totalLen, int maxWidth) {
        int extraSpacesNumber = (maxWidth - totalLen + line.size() - 1) / (line.size() - 1);
        int reminder = (maxWidth - totalLen) % (line.size() - 1);
        StringBuilder sb = new StringBuilder();

        for (int i = 0;i < line.size();i++) {
            sb.append(line.get(i));
            if (i == line.size() - 1) break;
            int num = reminder-- > 0 ? extraSpacesNumber + 1 : extraSpacesNumber;
            sb.append(addSpaces(num));
        }

        return sb.toString();
    }

    public String handleSingle(List<String> line, int maxWidth) {
        StringBuilder sb = new StringBuilder();
        sb.append(line.get(0));
        sb.append(addSpaces(maxWidth - sb.length()));

        return sb.toString();
    }

    public String handleLast(List<String> line, int totalLen, int maxWidth) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0;i < line.size();i++) {
            sb.append(line.get(i));
            if (i == line.size() - 1) {
                sb.append(addSpaces(maxWidth - sb.length()));
            } else {
                sb.append(" ");
            }
        }

        return sb.toString();
    }

    public String addSpaces(int num) {
        if (num == 0) return "";

        StringBuilder sb = new StringBuilder();

        for (int i = 0;i < num;i++) {
            sb.append(" ");
        }

        return sb.toString();
    }
}
```

# Valid Number

```java
class Solution {
    public boolean isNumber(String s) {
        if (s == null || s.length() == 0) return false;
        
        boolean hasExponent = false, hasDigit = false, hasDot = false;
        
        for (int i = 0;i < s.length();i++) {
            char c = s.charAt(i);
            
            if (c == '+' || c == '-') {
                if (hasExponent) {
                    if (s.charAt(i - 1) != 'e' && s.charAt(i - 1) != 'E') return false;
                } else {
                    if (i != 0) return false;
                }
            } else if (c == 'e' || c == 'E') {
                if (!hasDigit || hasExponent) return false;
                hasExponent = true;
                hasDigit = false;
            } else if (c == '.') {
                if (hasExponent || hasDot) return false;
                hasDot = true;
            } else {
                if (!Character.isDigit(c)) return false;
                hasDigit = true;
            }
        }
        
        return hasDigit;
    }
}
```

# Word Ladder

```java
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        
        if (!wordSet.contains(endWord)) return 0;
        if (beginWord.equals(endWord)) return 0;
        
        Queue<String> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        
        q.add(beginWord);
        visited.add(beginWord);
        
        int dist = 1;
        
        while (q.size() > 0) {
            int qSize = q.size();
            
            for (int i = 0;i < qSize;i++) {
                String now = q.poll();
                
                for (String s : getNext(now, visited, wordSet)) {
                    if (s.equals(endWord)) return dist + 1;
                    q.add(s);
                    visited.add(s);
                }
            }
            
            dist++;
        }
        
        return 0;
    }
    
    public List<String> getNext(String now, Set<String> visited, Set<String> wordSet) {
        List<String> res = new ArrayList<>();
        
        for (int i = 0;i < now.length();i++) {
            for (int j = 0;j < 26;j++) {
                String next = now.substring(0, i) + String.valueOf((char)('a' + j)) + now.substring(i + 1);
                
                if (wordSet.contains(next) && !visited.contains(next)) {
                    res.add(next);
                    visited.add(next);
                }
            }
        }
        
        return res;
    }
}
```

# Integer to English Words

```java
class Solution {
    Map<Integer, String> mp;
    int[] bigNum;
    
    public Solution() {
        mp = new HashMap<>();
        bigNum = new int[] {1000000000, 1000000, 1000};
        
        mp.put(1000000000, "Billion");
        mp.put(1000000, "Million");
        mp.put(1000, "Thousand");
        mp.put(100, "Hundred");
        mp.put(90, "Ninety");
        mp.put(90, "Ninety");
        mp.put(80, "Eighty");
        mp.put(70, "Seventy");
        mp.put(60, "Sixty");
        mp.put(50, "Fifty");
        mp.put(40, "Forty");
        mp.put(30, "Thirty");
        mp.put(20, "Twenty");
        mp.put(19, "Nineteen");
        mp.put(18, "Eighteen");
        mp.put(17, "Seventeen");
        mp.put(16, "Sixteen");
        mp.put(15, "Fifteen");
        mp.put(14, "Fourteen");
        mp.put(13, "Thirteen");
        mp.put(12, "Twelve");
        mp.put(11, "Eleven");
        mp.put(10, "Ten");
        mp.put(9, "Nine");
        mp.put(8, "Eight");
        mp.put(7, "Seven");
        mp.put(6, "Six");
        mp.put(5, "Five");
        mp.put(4, "Four");
        mp.put(3, "Three");
        mp.put(2, "Two");
        mp.put(1, "One");
    }
    
    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        
        List<String> res = new ArrayList<>();
        int k;
        
        for (int i = 0;i < bigNum.length;i++) {
            k = num / bigNum[i];
            handleKNum(k, bigNum[i], res);
            num -= k * bigNum[i];
        }
        
        handleLessThanThousand(num, res);
        
        String temp = "";
        
        for (String s : res) {
            temp += s + " ";
        }
        
        return temp.substring(0, temp.length() - 1);
    }
    
    public void handleKNum(int k, int num, List<String> res)  {
        if (k == 0) return;
        handleLessThanThousand(k, res);
        res.add(mp.get(num));
    }
    
    public void handleLessThanThousand(int num, List<String> res)  {
        if (num == 0) return;
        
        int k = num / 100;
        
        if (k > 0) {
            res.add(mp.get(k));
            res.add(mp.get(100));
        }
        
        num -= k * 100;
        
        handleTen(num, res);
    }
    
    public void handleTen(int num, List<String> res) {
        if (num == 0) return;
        
        int k = num / 10;
        
        if (k >= 2) {
            res.add(mp.get(k  * 10));
            num -= k * 10;
            if (num == 0) return;
            res.add(mp.get(num));
        } else {
            res.add(mp.get(num));
        }
    }
}
```

# All O`one Data Structure

```java
class AllOne {
    private Map<String, Node> mp;
    private Node dh;
    private Node dt;

    /** Initialize your data structure here. */
    public AllOne() {
        mp = new HashMap<>();
        dh = new Node(0);
        dt = new Node(0);
        dh.next = dt;
        dt.prev = dh;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void inc(String key) {
        // if mp does not contains that key which means its rank should be 1
        if (!mp.containsKey(key)) {
            // Don't have node with rank 1
            if (dh.next == dt || dh.next.rank != 1) {
                dh.insertAtRight(new Node(1));
            }
            
            // Insert data at rank1 node
            dh.next.data.add(key);
            // update the map
            mp.put(key, dh.next);
        } else {
            Node cur = mp.get(key);
            
            if (cur.next == dt || cur.next.rank != cur.rank + 1) {
                cur.insertAtRight(new Node(cur.rank + 1));
            }
            
            cur.data.remove(key);
            cur.next.data.add(key);
            // Update map
            mp.put(key, cur.next);
            
            if (cur.data.size() == 0) {
                cur.removeItSelf();
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void dec(String key) {
        if (!mp.containsKey(key)) return;
        
        Node cur = mp.get(key);
        
        if (cur.rank == 1) {
            cur.data.remove(key);
            // Update map
            mp.remove(key);
        } else {
            if (cur.prev == dh || cur.prev.rank != cur.rank - 1) {
                cur.prev.insertAtRight(new Node(cur.rank - 1));
            }
            
            cur.data.remove(key);
            cur.prev.data.add(key);
            // Update map
            mp.put(key, cur.prev);
        }
        
        if (cur.data.size() == 0) {
            cur.removeItSelf();
        }
    }
    
    /** Returns one of the keys with maximal value. */
    public String getMaxKey() {
        if (dt.prev == dh) return "";
        return dt.prev.data.iterator().next();
    }
    
    /** Returns one of the keys with Minimal value. */
    public String getMinKey() {
        if (dh.next == dt) return "";
        return dh.next.data.iterator().next();
    }
    
    class Node {
        private Set<String> data;
        private int rank;
        private Node prev;
        private Node next;
        
        public Node(int rank) {
            this.rank = rank;
            this.data = new HashSet<>();
        }
        
        public void insertAtRight(Node node) {
            node.next = this.next;
            node.prev = this;
            this.next = node;
            node.next.prev = node;
        }
        
        public void removeItSelf() {
            this.prev.next = this.next;
            this.next.prev = this.prev;
            this.next = null;
            this.prev = null;
        }
    }
}
```

# Minimum Insertion Steps to Make a String Palindrome

Find the longest palindrome subsequence using dp, then just need to insert `s.length() - dp[0][n - 1];`chars to make it palindrome.

```java
class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        
        for (int i = 0;i < n;i++) {
            dp[i][i] = 1;
        }
        
        for (int l = 2;l <= n;l++) {
            for (int i = 0;i + l <= n;i++) {
                int j = i + l - 1;
                
                dp[i][j] = dp[i + 1][j - 1];
                
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] += 2;
                } else {
                    dp[i][j] = Math.max(dp[i][j], Math.max(dp[i + 1][j], dp[i][j - 1]));
                }
            }
        }
        
        return s.length() - dp[0][n - 1];
    }
}
```

# Max Points on a Line

固定一个点，每次扫描其他点用一个哈希表来记录斜率就好了。

```java
class Solution {
    public int maxPoints(int[][] points) {
        if (points.length <= 2) return points.length;
        int n = points.length, res = 0;
        
        for (int i = 0;i < n;i++) {
            Map<Double, Integer> slope2number = new HashMap<>();
            for (int j = 0;j < n;j++) {
                if (i == j) continue;
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                
                Double slope;
                
                if (x1 == x2) {
                    slope = Double.MAX_VALUE;
                } else {
                    slope = (double)(y2 - y1) / (x2 - x1);
                }
                
                slope2number.put(slope, slope2number.getOrDefault(slope, 0) + 1);
                
                res = Math.max(res, slope2number.get(slope) + 1);
            }
        }
        
        return res;
    }
}
```

