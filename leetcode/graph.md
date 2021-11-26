## Dijkstra's Algorithm

find the shortest path in a weighted graph 

### 743 Network Delay Time

You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges `times[i] = (ui, vi, wi)`, where `ui` is the source node, `vi` is the target node, and `wi` is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return the time it takes for all the `n` nodes to receive the signal. If it is impossible for all the `n` nodes to receive the signal, return `-1`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png)

```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
```

**Example 2:**

```
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
```

**Example 3:**

```
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
```

**Solution**

```java
// Djikstra - shortest Path
// 其实就是bfs + minHeap, 每次都优先选最短的边来遍历
// E(edges) V(node)
// max E = v^2
// O(ElogV^2) = O(ElogV)

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        // build graph
        Map<Integer, List<int[]>> graph = new HashMap();
        for(int[] edge : times) {
            if(!graph.containsKey(edge[0])) {
                graph.put(edge[0], new ArrayList<>());
            }
            graph.get(edge[0]).add(new int[]{edge[1], edge[2]});
        }
        // [path length, node]
        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        heap.offer(new int[]{0, k});
        Map<Integer, Integer> dist = new HashMap();
        while(!heap.isEmpty()) {
            int[] info = heap.poll();
            int d = info[0], node = info[1];
            if(dist.containsKey(node)) continue;
            dist.put(node, d);
            if(graph.containsKey(node)) {
                for(int[] edge : graph.get(node)) {
                    int nei = edge[0], d2 = edge[1];
                    if(!dist.containsKey(nei)) {
                        heap.offer(new int[]{d + d2, nei});
                    }
                }
            }
        }
        
        if(dist.size() != n) return -1;
        int ans = 0;
        for(int cand : dist.values()) {
            ans = Math.max(ans, cand);
        }
        return ans;
    }
}
```





### 778 Swim in Rising Water

You are given an `n x n` integer matrix `grid` where each value `grid[i][j]` represents the elevation at that point `(i, j)`.

The rain starts to fall. At time `t`, the depth of the water everywhere is `t`. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most `t`. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return *the least time until you can reach the bottom right square* `(n - 1, n - 1)` *if you start at the top left square* `(0, 0)`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/06/29/swim1-grid.jpg)

```
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg)

```
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
```

**Solution**



```java
class Solution {
    int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int ans = 0;
        
        boolean[][] visited = new boolean[n][n];
        visited[0][0] = true;
        
        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> grid[a[0]][a[1]] - grid[b[0]][b[1]]);
        heap.offer(new int[]{0, 0});
        
        while (!heap.isEmpty()) {
            int[] cur = heap.poll();
            int row = cur[0], col = cur[1];
            ans = Math.max(ans, grid[row][col]);
            if (row == n - 1 && col == n - 1) {
                return ans;
            }
            
            for (int[] dir : dirs) {
                int r = cur[0] + dir[0], c = cur[1] + dir[1];
                if (r >= 0 && r < n && c >= 0 && c < n && 
                    !visited[r][c]) {
                    visited[r][c] = true;
                    heap.offer(new int[]{r, c});
                }
            }
        }
        
        throw null;
    }
}
```







### 1631 Path With Minimum Effort

You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e., **0-indexed**). You can move **up**, **down**, **left**, or **right**, and you wish to find a route that requires the minimum **effort**.

A route's **effort** is the **maximum absolute difference** in heights between two consecutive cells of the route.

Return *the minimum **effort** required to travel from the top-left cell to the bottom-right cell.*

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/04/ex1.png)

```
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/10/04/ex2.png)

```
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2020/10/04/ex3.png)

```
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
```

**Solution**

如果这个题只能走下和右，不能回头，那就是一道简单的dp题。

有两种方法 第一种是 bfs + binary search 我们先给丁一个答案的范围，对这个范围进行二分搜索， 用bfs check 这个effort能不能到达目的地

Time Complexity O(logF * MN) F is the maximum effort

第二种方法是用union find, 把所有的边都放进priority queue里面，从小的拿出来，最后看什么时候start 和target union到了一起

Union find 这个更加简单一点

```java
class Solution {
    public int minimumEffortPath(int[][] heights) {
        int left = 0;
        int right = 1000000;
        int result = right;
        while (left < right) {
            int mid = (left + right) / 2;
            if (canReachDestinaton(heights, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // use bfs to check if we can reach destination with max absolute difference k
    boolean canReachDestinaton(int[][] heights, int k) {
        int row = heights.length;
        int col = heights[0].length;
        Deque<Cell> queue = new ArrayDeque<>();
        boolean[][] visited = new boolean[heights.length][heights[0].length];
        queue.addLast(new Cell(0, 0));
        visited[0][0] = true;
        while (!queue.isEmpty()) {
            Cell curr = queue.removeFirst();
            if(curr.x == row - 1 && curr.y == col - 1) {
                return true;
            }
            for (int[] direction : directions) {
                int adjacentX = curr.x + direction[0];
                int adjacentY = curr.y + direction[1];
                if (isValidCell(adjacentX, adjacentY, row, col) && !visited[adjacentX][adjacentY]) {
                    int currentDifference = Math.abs(heights[adjacentX][adjacentY] - heights[curr.x][curr.y]);
                    if (currentDifference <= k) {
                        visited[adjacentX][adjacentY] = true;
                        queue.addLast(new Cell(adjacentX, adjacentY));
                    }
                }
            }
        }
        return false;
    }

    boolean isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }
}

class Cell {
    int x;
    int y;

    Cell(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
```







## Minium Spamming Tree



## Union Find

https://blog.csdn.net/u013325815/article/details/103905032



```java
private class UnionFind{
	private int[] father;
  private int count;
  public UnionFind(int n) {
    this.father = new int[n + 1];
    for(int i = 0; i <= n; i++) {
      father[i] = i;
    }
    this.count = n;
  }
  
  public int find(int x) {
    int j = x;
    while(father[j] != i) {
      j = father[j];
    }
    //path compression
    while(x != j) {
      int fx = father[x];
      father[x] = j;
      x = fx;
    }
    return j;
  }
  
  public void union(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
    if(root_a != root_b) {
      father[root_a] = root_b;
      this.count--;
    }
  }
  public int getCount() {
    return this.count;
  }
}
```





##  

### 1631 Path With Minimum Effort

You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e., **0-indexed**). You can move **up**, **down**, **left**, or **right**, and you wish to find a route that requires the minimum **effort**.

A route's **effort** is the **maximum absolute difference** in heights between two consecutive cells of the route.

Return *the minimum **effort** required to travel from the top-left cell to the bottom-right cell.*

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/04/ex1.png)

```
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/10/04/ex2.png)

```
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2020/10/04/ex3.png)

```
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
```

**Solution**

如果这个题只能走下和右，不能回头，那就是一道简单的dp题。

有两种方法 第一种是 bfs + binary search 我们先给丁一个答案的范围，对这个范围进行二分搜索， 用bfs check 这个effort能不能到达目的地

Time Complexity O(logF * MN) F is the maximum effort

第二种方法是用union find, 把所有的边都放进priority queue里面，从小的拿出来，最后看什么时候start 和target union到了一起

Union find 这个更加简单一点

```java
class Solution {
    public int minimumEffortPath(int[][] heights) {
        int left = 0;
        int right = 1000000;
        int result = right;
        while (left < right) {
            int mid = (left + right) / 2;
            if (canReachDestinaton(heights, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // use bfs to check if we can reach destination with max absolute difference k
    boolean canReachDestinaton(int[][] heights, int k) {
        int row = heights.length;
        int col = heights[0].length;
        Deque<Cell> queue = new ArrayDeque<>();
        boolean[][] visited = new boolean[heights.length][heights[0].length];
        queue.addLast(new Cell(0, 0));
        visited[0][0] = true;
        while (!queue.isEmpty()) {
            Cell curr = queue.removeFirst();
            if(curr.x == row - 1 && curr.y == col - 1) {
                return true;
            }
            for (int[] direction : directions) {
                int adjacentX = curr.x + direction[0];
                int adjacentY = curr.y + direction[1];
                if (isValidCell(adjacentX, adjacentY, row, col) && !visited[adjacentX][adjacentY]) {
                    int currentDifference = Math.abs(heights[adjacentX][adjacentY] - heights[curr.x][curr.y]);
                    if (currentDifference <= k) {
                        visited[adjacentX][adjacentY] = true;
                        queue.addLast(new Cell(adjacentX, adjacentY));
                    }
                }
            }
        }
        return false;
    }

    boolean isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }
}

class Cell {
    int x;
    int y;

    Cell(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
// union find
class Solution {
    public int minimumEffortPath(int[][] heights) {
        int row = heights.length;
        int col = heights[0].length;
        if (row == 1 && col == 1) return 0;
        UnionFind unionFind = new UnionFind(heights);
        List<Edge> edgeList = unionFind.edgeList;
        Collections.sort(edgeList, (e1, e2) -> e1.difference - e2.difference);

        for (int i = 0; i < edgeList.size(); i++) {
            int x = edgeList.get(i).x;
            int y = edgeList.get(i).y;
            unionFind.union(x, y);
            if (unionFind.find(0) == unionFind.find(row * col - 1)) return edgeList.get(i).difference;
        }
        return -1;
    }
}

class UnionFind {
    int[] parent;
    int[] rank;
    List<Edge> edgeList;

    public UnionFind(int[][] heights) {
        int row = heights.length;
        int col = heights[0].length;
        parent = new int[row * col];
        edgeList = new ArrayList<>();
        rank = new int[row * col];
        for (int currentRow = 0; currentRow < row; currentRow++) {
            for (int currentCol = 0; currentCol < col; currentCol++) {
                if (currentRow > 0) {
                    edgeList.add(new Edge(currentRow * col + currentCol,
                            (currentRow - 1) * col + currentCol,
                            Math.abs(heights[currentRow][currentCol] - heights[currentRow - 1][currentCol]))
                    );
                }
                if (currentCol > 0) {
                    edgeList.add(new Edge(currentRow * col + currentCol,
                            currentRow * col + currentCol - 1,
                            Math.abs(heights[currentRow][currentCol] - heights[currentRow][currentCol - 1]))
                    );
                }
                parent[currentRow * col + currentCol] = currentRow * col + currentCol;
            }
        }
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void union(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        if (parentX != parentY) {
            if (rank[parentX] > rank[parentY]) parent[parentY] = parentX;
            else if (rank[parentX] < rank[parentY]) parent[parentX] = parentY;
            else {
                parent[parentY] = parentX;
                rank[parentX] += 1;
            }
        }
    }
}

class Edge {
    int x;
    int y;
    int difference;

    Edge(int x, int y, int difference) {
        this.x = x;
        this.y = y;
        this.difference = difference;
    }
}
```



