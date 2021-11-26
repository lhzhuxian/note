# Factor Combinations 把数字分解成所有可能的乘积组合

```java
class Solution {
    public List<List<Integer>> getFactors(int n) {
        List<List<Integer>> res = new LinkedList<>();
        
        dfs(res, new LinkedList<>(), 2, n);
        
        return res;
    }
    
    public void dfs(List<List<Integer>> res, List<Integer> curPath, int start, int n) {
        for (int i = start;i <= Math.sqrt(n);i++) {
            if (n % i == 0) {
                curPath.add(i);
                curPath.add(n / i);
                res.add(new LinkedList<>(curPath));
                curPath.remove(curPath.size() - 1);
                // This step is fine because we've already calculate all the smaller possible cases
                // Like 4 as next start, then n should be greater than 16 then we can get result
                dfs(res, curPath, i, n / i);
                curPath.remove(curPath.size() - 1);
            }
        }
    }
}
```

# Bomb Enemy

每次搜的时候更新行和列的值

```java
class Solution {
    public int maxKilledEnemies(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        int rowNum = 0;
        int[] colNum = new int[n];
        int res = 0;
        
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                // Scan for starting point or there is wall behind for rowNum
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowNum = 0;
                    
                    for (int k = j;k < n;k++) {
                        char symbol = grid[i][k];
                        
                        if (symbol == 'E') {
                            rowNum++;
                        } else if (symbol == 'W') {
                            break;
                        }
                    }
                }
                
                // Scan for starting point or there is wall behind for colNum
                if (i == 0 || grid[i - 1][j] == 'W') {
                    colNum[j] = 0;
                    
                    for (int k = i;k < m;k++) {
                        char symbol = grid[k][j];
                        
                        if (symbol == 'E') {
                            colNum[j]++;
                        } else if (symbol == 'W') {
                            break;
                        }
                    }
                }
                
                if (grid[i][j] == '0') {
                    res = Math.max(res, rowNum + colNum[j]);
                }
            }
        }
        
        return res;
    }
}
```

# Delete Node In a BST

若有左和则赋值其与左边的最大值然后删左边最大的，若有右则删右边最小的。

```java
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        // First found the node
        if (root == null) return null;
        
        if (root.val > key) {
            root.left = deleteNode(root.left, key);
        } else if (root.val < key) {
            root.right = deleteNode(root.right, key);
        } else {
            if (root.left == null && root.right == null) {
                root = null;
            } else if (root.left != null) {
                root.val = leftMax(root);
                root.left = deleteNode(root.left, root.val);
            } else {
                root.val = rightMin(root);
                root.right = deleteNode(root.right, root.val);
            }
        }
        
        return root;
       
    }
    
    private int leftMax(TreeNode root) {
        root = root.left;
        while (root.right != null) {
            root = root.right;
        }
        return root.val;
    }
    
    private int rightMin(TreeNode root) {
        root = root.right;
        while (root.left != null) {
            root = root.left;
        }
        return root.val;
    }
}
```

# Find K Pairs with Smallest Sums 两组数组找二者元素组成的最小k对pair

类似merge sort，但是先固定某一组（nums2）为0然后把所有nums1[i] + nums[0] 放入heap同时维护一个nums2的index，0.每次取出最小的后把这个index++更新到heap中。

```java
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        // Min heap add [nums1[i], nums2[0]] for all i in nums1 gurantee that first is the smallest
        // Every time pop one into res, say [i, j], then add [i, j + 1] if its length is valid
        List<List<Integer>> res = new ArrayList<>();
        if (nums1 == null || nums2 == null || nums1.length == 0 || nums2.length == 0 || k == 0) return res;
        
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] + a[1] - b[0] - b[1]);
        
        for (int i = 0; i < nums1.length && i < k; i++) {
            pq.add(new int[] {nums1[i], nums2[0], 0});
        }
        
        while (k-- > 0 && pq.size() > 0) {
            int[] now = pq.poll();
            res.add(List.of(now[0], now[1]));
            int indexIn2 = now[2] + 1;
            
            if (indexIn2 < nums2.length) {
                now[2] = indexIn2;
                now[1] = nums2[indexIn2];
                pq.offer(now);
            }
        }
        
        return res;
    }
}
```

# Search in Rotated Sorted Array

就当只有两种情况，比右边小代表在右侧mid右边一定有序，反之在左侧，推各种情况就好。若有重复则右侧--。

```java
class Solution {
    public boolean search(int[] nums, int target) {
        // binary search
        int left = 0;
        int right = nums.length - 1;
                
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            }
            
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] > nums[right]) {
                if (nums[mid] > target && nums[left] <= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                right--;
            }
        }
        
        return false;
    }
}
```

# Find First and Last Position of Element in Sorted Array

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[] {-1, -1};
        if (nums.length == 0) return res;
        int n = nums.length;
        
        // Find first
        int l = 0, r = n - 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        if (nums[l] != target) {
            return res;
        }
        
        res[0] = l;
        
        // Find last
        l = 0; 
        r = n - 1;
        
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                l = mid;
            }
        }
        
        if (nums[r] == target) {
            res[1] = r;
        } else {
            res[1] = l;
        }
        
        return res;
    }
}
```

# Random Pick with Weight

想成投球，把概率累加，在某个区间就是谁。

```java
class Solution {
    double[] prefix;
    Random random;
    public Solution(int[] w) {
        random = new Random();
        prefix = new double[w.length];
        int pre = 0;
        int sum = 0;
        
        for (int i : w) {
            sum += i;
        }
        
        for (int i = 0;i < w.length;i++) {
            pre += w[i];
            prefix[i] = (double)pre / sum;
        }
    }
    
    public int pickIndex() {
        double prob = random.nextDouble();
        int l = 0, r = prefix.length - 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            double midVal = prefix[mid];
            
            if (midVal > prob) {
                r = mid;
            } else if (midVal < prob) {
                l = mid + 1;
            } else {
                r = mid;
                break;
            }
        }
        
        return r;
    }
}
```



# Partition to K Equal Sum Subsets 在数组中找K对和一样的组合

```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[] {-1, -1};
        if (nums.length == 0) return res;
        int n = nums.length;
        
        // Find first
        int l = 0, r = n - 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        if (nums[l] != target) {
            return res;
        }
        
        res[0] = l;
        
        // Find last
        l = 0; 
        r = n - 1;
        
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                l = mid;
            }
        }
        
        if (nums[r] == target) {
            res[1] = r;
        } else {
            res[1] = l;
        }
        
        return res;
    }
}
```

要点就是找到cur == target sum后用当前状态继续找下一个可能的组合。注意还是要sort这样不会重复找，比如2233中只有两对23.

```java
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = getSum(nums);
        if (sum % k != 0 && nums.length > k) return false;
        int target = sum / k;
        Arrays.sort(nums);
        
        boolean[] visited = new boolean[nums.length];
        
        boolean res = dfs(nums, 0, target, 0, k, 0, new boolean[nums.length]);
        
        return res;
    }
    
    public boolean dfs(int[] nums, int curSum, int targetSum, int curCnt, int targetCnt, int index, boolean[] visited) {
        if (curCnt == targetCnt) return true;
        
        for (int i = index;i < nums.length;i++) {
            if (visited[i] || i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            
            int sum = curSum + nums[i];
            
            if (sum > targetSum) break;
            
            visited[i] = true;
            if (sum == targetSum && dfs(nums, 0, targetSum, curCnt + 1, targetCnt, 0, visited)) return true;
            if (dfs(nums, sum, targetSum, curCnt, targetCnt, i + 1, visited)) return true;
            visited[i] = false;
        }
        
        return false;
    }
    
    public int getSum(int[] nums) {
        int res = 0;
        
        for (int i : nums) {
            res += i;
        }
        
        return res;
    }
}
```

# Lowest Common Ancestor of a Binary Tree

若是n叉树可用dfs搜索到某一个节点的路径，同时记录深度，再搜另一个节点的路径，取交集中深度最深的节点即可。

```java
class Solution {
    TreeNode lca;
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        findLCA(root, p, q);
        
        return lca;
    }
    
    public boolean[] findLCA(TreeNode root, TreeNode p, TreeNode q) {
        boolean[] res = new boolean[]{false, false};
        
        if (lca != null || root == null) return res;
        
        boolean[] left = findLCA(root.left, p, q);
        boolean[] right = findLCA(root.right, p, q);
        
        res[0] = left[0] || right[0] || root.val == p.val;
        res[1] = left[1] || right[1] || root.val == q.val;
        
        if (res[0] && res[1] && lca == null) lca = root;
        
        return res;
    }
}
```

# Integer to Roman

```java
class Solution {
    private static final int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};    
    private static final String[] symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        // Loop through each symbol, stopping if num becomes 0.
        for (int i = 0; i < values.length && num > 0; i++) {
            // Repeat while the current symbol still fits into num.
            while (values[i] <= num) {
                num -= values[i];
                sb.append(symbols[i]);
            }
        }
        return sb.toString();
    }
}
```

```java
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> mp = new HashMap<>();
        mp.put('I', 1);
        mp.put('V', 5);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);
        
        int res = 0;
        
        for (int i = 0;i < s.length();i++) {
            int cur = mp.get(s.charAt(i));
            if (i > 0 && mp.get(s.charAt(i - 1)) < cur) {
                res += cur - 2 * mp.get(s.charAt(i - 1));
            } else {
                res += cur;
            }
        }
        
        return res;
    }
}
```

# Exclusive Time of Functions

用stack来记录和改变前一个任务的起始时间，每次遇到start代表前面任务要终止一下，时间加上cur - prev，每次遇到stop要把前个任务的timestamp更新成结束人物的time stamp。

```java
class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] res = new int[n];
        Stack<Node> st = new Stack<>();
        
        for (String log : logs) {
            String[] sections = log.split(":");
            int id = Integer.parseInt(sections[0]);
            int timestamp = Integer.parseInt(sections[2]);
            
            if (sections[1].equals("start")) {
                if (!st.isEmpty()) {
                    res[st.peek().key] += timestamp - st.peek().val;
                }
                
                st.push(new Node(id, timestamp));
            } else {
                Node prev = st.pop();
                res[id] += timestamp - prev.val + 1;
                
                if (!st.isEmpty()) {
                    st.peek().val = timestamp + 1;
                }
            }
        }
        
        return res;
    }
    
    class Node {
        private int key;
        private int val;
        
        public Node (int key, int val) {
            this.key = key;
            this.val = val;
        }
    }
}
```

# Maximum Product Subarray

```java
class Solution {
    public int maxProduct(int[] nums) {
        if (nums.length == 1) return nums[0];
        
        int pre = 1;
        int posMin = 1;
        int minMax = Integer.MIN_VALUE;
        
        int res = Integer.MIN_VALUE;
        
        for (int num : nums) {
            if (num == 0) {
                pre = 1;
                posMin = 1;
                minMax = Integer.MIN_VALUE;
                res = Math.max(res, 0);
                continue;
            }
            
            pre *= num;
            
            if (pre > 0) {
                res = Math.max(res, pre / posMin);
                posMin = Math.min(posMin, pre);
            } else {
                if (minMax == Integer.MIN_VALUE) {
                    minMax = pre;
                } else {
                    res = Math.max(res, pre / minMax);
                    minMax = Math.max(minMax, pre);
                }
            }
        }
        
        return res;
    }
}
```

# Factor Combination

找到i代表也找到了n / i, 同时n / i / i也可以，那么下一层就找i和n / i。

```java
class Solution {
    public List<List<Integer>> getFactors(int n) {
        List<List<Integer>> res = new LinkedList<>();
        
        dfs(res, new LinkedList<>(), 2, n);
        
        return res;
    }
    
    public void dfs(List<List<Integer>> res, List<Integer> curPath, int start, int n) {
        for (int i = start;i <= Math.sqrt(n);i++) {
            if (n % i == 0) {
                curPath.add(i);
                curPath.add(n / i);
                res.add(new LinkedList<>(curPath));
                curPath.remove(curPath.size() - 1);
                // This step is fine because we've already calculate all the smaller possible cases
                // Like 4 as next start, then n should be greater than 16 then we can get result
                dfs(res, curPath, i, n / i);
                curPath.remove(curPath.size() - 1);
            }
        }
    }
}
```

# Insert Delete GetRandom O(1)

```java
class RandomizedSet {
    private Random rand;
    private List<Integer> list;
    private Map<Integer, Integer> val2ind;

    /** Initialize your data structure here. */
    public RandomizedSet() {
        rand = new Random();
        list = new ArrayList<>();
        val2ind = new HashMap<>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (val2ind.containsKey(val)) {
            return false;
        }
        
        list.add(val);
        val2ind.put(val, list.size() - 1);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!val2ind.containsKey(val)) {
            return false;
        }
        
        // get the index of the val to be deleted and the last element val
        int indexOfVal = val2ind.get(val);
        int lastVal = list.get(list.size() - 1);
        // set the last element to this index and update map
        list.set(indexOfVal, list.get(list.size() - 1));
        val2ind.put(lastVal, indexOfVal);
        // delete the last element and update map
        list.remove(list.size() - 1);
        val2ind.remove(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        return list.get(rand.nextInt(list.size()));
    }
}
```



# Insert Delete GetRandom O(1) - Duplicates allowed

```java
class RandomizedCollection {
    private List<Integer> list;
    private Map<Integer, Set<Integer>> mp;
    private Random rand;

    /** Initialize your data structure here. */
    public RandomizedCollection() {
        list = new ArrayList<>();
        mp = new HashMap<>();
        rand = new Random();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        boolean contains = mp.containsKey(val);
        if (!contains) mp.put(val, new HashSet<Integer>());
        mp.get(val).add(list.size());
        list.add(val);
        return !contains;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        if (!mp.containsKey(val)) return false;
        
        int indexOfDeleteVal = mp.get(val).iterator().next();
        mp.get(val).remove(indexOfDeleteVal);
        if (mp.get(val).size() == 0) mp.remove(val);
        
        if (indexOfDeleteVal < list.size() - 1) {
            int lastVal = list.get(list.size() - 1);
            list.set(indexOfDeleteVal, lastVal);
            
            mp.get(lastVal).remove(list.size() - 1);
            mp.get(lastVal).add(indexOfDeleteVal);
        }
        
        list.remove(list.size() - 1);
        
        return true;
    }
    
    /** Get a random element from the collection. */
    public int getRandom() {
        return list.get(rand.nextInt(list.size()));
    }
}
```

#  Find Smallest Letter Greater Than Target

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int l = 0, r = letters.length - 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        if (l == letters.length - 1 && letters[l] <= target) return letters[0];
        
        return letters[l];
    }
}
```

# Second Minimum Node In a Binary Tree

```java
class Solution {
    private TreeNode res;
    
    public int findSecondMinimumValue(TreeNode root) {
        findNode(root, root.val);
        
        return res == null? -1 : res.val;
    }
    
    public void findNode(TreeNode root, int min) {
        if (root == null) return;
        
        if (res != null && root.val > res.val) return;
        
        if (root.val > min) {
            if (res == null || res.val > root.val) {
                res = root;
            }
        } else {
            findNode(root.left, min);
            findNode(root.right, min);
        }
    }
}
```

# SQRT(x)

```java
class Solution {
    public int mySqrt(int x) {
        if (x == 0) return 0;
        long l = 1, r = x / 2 + 1;
        
        while (l + 1 < r) {
            long mid = l + (r - l) / 2;
            long squre = mid * mid;
            
            if (squre < x) {
                l = mid;
            } else if (squre > x) {
                r = mid - 1;
            } else {
                return (int)mid;
            }
        }
        
        if (r * r <= x) return (int)r;
        
        return (int)l;
    }
}
```

