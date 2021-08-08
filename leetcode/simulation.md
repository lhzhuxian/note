## Spiral Matrix

Given an `m x n` `matrix`, return *all elements of the* `matrix` *in spiral order*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)

```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

**Solution**

```java
class Solution {
    
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        if(matrix.length == 0) {
            return ans;
        }
        int r1 = 0, r2 = matrix.length - 1;
        int c1 = 0, c2 = matrix[0].length - 1;
        while(r1<= r2 && c1 <= c2) {
            for(int c = c1; c <= c2; c++) {
                ans.add(matrix[r1][c]);
            }
            for(int r = r1 + 1; r <= r2; r++) {
                ans.add(matrix[r][c2]);
            }
            if(c1 < c2 && r1 < r2) {
                for(int c = c2 - 1; c >= c1; c--) {
                    ans.add(matrix[r2][c]);
                }
                for(int r = r2 - 1; r > r1; r--) {
                    ans.add(matrix[r][c1]);
                }
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }
    
}
```

