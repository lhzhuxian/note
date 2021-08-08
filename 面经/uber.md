

------

给一个长度为n的数组A，返回一个数组 B，长度为n-2，其中B 等于A, A[i+1], A[i+2] 是不是递增或递减



一个数组，i, i + 1, i + 2的元素各不相同算一个tuple, 问这个数组里面一共有几个tuple



给一个数组，一个diff，找最长subarray，任意相邻两个数之间的差<=diff, 返回下标.  [4,‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌3,2,5,6] , dif=1 -> [0,2]

简单的sliding windows



很简单的数字操作。直接举例子，123,返回每一位sum-prod，（1+2+3）- （1*2*3）



有一个List里面元素各不相同，找到它的local peak（就是比i - 1， i + 1大就算local peak）, 然后从list里面移除这个local peak。重复这个操作。记录移除顺序

loop 这个array，当发现peak的时候就放入result，然后把左边的数覆盖当前的数



给一个数组，按照下面的规则
(1) 找到第一个不为零的数X，下标idx， 把X加到result
(2) 从idx开始把剩余的数字减去X, 如果该数字小于X,从(1)开始知道所有数都为0
[3,3,2,4] -> [0,0,2,4] -> [0,0,0,2] -> [0,0,0] result=3+2+2 = 7



给一个数组，返回数字长度是偶数的个数， [1,23,456] -> 1



reverse sum, 123-->321, 1200-->2100, 再相加

把integer变成string 加起来然后变回来，也可以直接翻转数字加起来

```
String.valueOf()
 Integer.toString()
 Integer.parseInt()
```



 "W" "D" "L"那道

------

地里常见的矩阵传送门

------

\945 Minimum Increment to Make Array Unique

```java
class Solution {
    public int minIncrementForUnique(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        Arrays.sort(nums);
        int result = 0;
        for(int i = 1; i < nums.length; ++i) {
            if(nums[i] <= nums[i - 1]) {
                result += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        return result;
    }
}
```



------

给一个matrix，求菱形borderline上值的和，返回最大的前三个distinct sum值



```java
1, 1, 1, 1, 1
2, 2, 2, 2, 2
3, 3, 3, 3, 3
4, 4, 4, 4, 4
就比如上面这个例子，红色的2是菱形的中心，绿色的数字是一个radius为2的菱形边界，此时和为 1+2+2+3.

同理这个菱形还可以表示为：
1, 1, 1, 1, 1
2, 2, 2, 2, 2
3, 3, 3, 3, 3
4, 4, 4, 4, 4
这个和就是 2+3+3+4

题目给的是一个matrix和radius，要求所有可能的菱形边界之和的最大三个。
```



给一个矩形，对每一圈‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌进行排序。类似利口的旋转矩阵

可能是一个题目？



给一个matrix，从每一行的第一个元素开始出发（每一行都是重复这个操作），往右上，到了顶之后变成方向变成往右下，每一行的这个操作算sum，然后按照这个sum来对每一行来排序



打印带星号的矩阵

------

手机键盘的每个数字对应几个字母，给一个digits array和word array，问每一个word能不能被拼出来。之前帖子有详细

------

最长的连续房子那道题。之前帖子出现过很多次，不详细说了。

------

类似于网站的题号要柒视山， 有一个pair，`pair里面是[j][j + 1]或者[j + 1][j]`，根据这个pair恢复原来‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌的array，可以参考刷题网站这个题目，基本上是一样的。

------

You are given an array of positive integers `numbers`, and a positive integer `x`. Your task is to find the number of ways that `x` can be obtained by writing ‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌pairs of integers in the array `numbers` next to each other. In other words, find the number of pairs `(i, j)`, such that `i != j` and `x` is the concatenation of `numbers` and `numbers[j]`.

如果只需要用两个数来拼成x的话，可以把数组弄成一个HashMap。然后把原始x在不同index分成两截，看两截是否存在在HashMap中

------

給一個數組array，問有幾個子array（長度最小可以是1）符合奇偶奇或偶奇偶這樣的排序。這題我只想得到暴力解法‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌，但過不了隱藏測試只拿了100/300，求解。

dp[i] = length of dp[i - 1] + dp[i - 1]

------

BFS的題，除了給你矩陣長和寬以外，還多了障礙和傳送門，還有限制先走右邊，右邊不能走才走下面（只能往右或往下走）。問能不能從左上角走到右下角。題目就是那種BFS但多了邊邊角角等限制要注意，代碼不難但比其他三題都長。

------

 jump number，给定一个list，jump的条件是nums[i] == nums[j] and abs(j-i) <= diff. 可以从任意点开始跳，求最大jump次数

跳的方向固定？

------

两个array a,b，要求支持两种操作, 一种是把a的一个数字加x，另一种是求a,b里面加起来等于x的个数。这一题有四个hidden case一直过不了，我的方法是维护a,b 各一个counter，然后加x的时候就改一下counter a，然后query的时候就对a的counter for loop 然后找到b里面对应元素的个数相乘，这样就‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌是O(a counter 元素个数)，最后试过加一个cache也还是不行，不知道还能怎么优化



------

 fallAndCrash。一个比较有意思的模拟题。一个m x n的board上有 '.' (empty), '#' (box), '*' (obstacle)三种类型，还有一个m x n的matrix表示obstacle的强度。假设board是垂直放置的，box会往下掉落。如果是empty，箱子会继续掉落；如果是obstacle，它的强度如果大于等于它上面累积箱子的数量，则它可以挡住掉落的box，box会在它上面堆积起来；如果强度不够，obstacle被摧毁，箱子继续下落。如果没有足够的obstacle挡住所有的箱子，箱子最后会落在最后一层。需要返回board的最终形态。

每个column处理一次.

处理的时候从上往下.

累计当前一个obstacle之前的box#, 然后判断是否破碎.
破了就继续累积，
不破就归零， 找下一个obstacle.





------

matrixQueries。一个matrix, matrix[x][y] = (x+1) * (y+1)。现在有两个操作，抹除行或者列，返回matrix最小值。求设计这两个API。比如 removeCol(0), removeRow(3), getMin() -> 21 2 3  42 4 6  83 6 9  124 8 12 16之前做了sample questions发现第四题一定要用优化的数据结构和算法，不然过不了全部的case。这个题卖个关子，看大家怎么想。



------

给你两个字符串，string binaryString, string request 长度可到10^5。 binaryString中只有'0'和'1'， request中只有 '-' 和 '?'。现在要求遍历request, 如果发现当前字符是'-'，则binaryString所表示的正整数要减去1, 如果当前字符是'?' 求当前binaryString所表示的正整数的二进制位为1的个数. 最后返回一个数组, 按request中出现？的顺序返回当前binaryString所表示的正整数中二进制位为1的个数。

Solution

```java
vector<int> solve(string &binaryString, string &request)
{
    vector<vector<int>> ones_interval;
    int n = binaryString.size();
    int total_ones = 0;
 
    /*初始化 O(N), ones_interval存的是‘1’的{start index, count}
     for example: 10011
     ones_interval = {{0,1}, {3,2}}
     */
    for (int i = 0; i < n; i++) {
        if (binaryString[i] == '1') {
            if (i == 0 || binaryString[i-1] == '0')
                ones_interval.push_back({i, 0});
            ones_interval.back()[1]++;
 
            total_ones++;
        }   
    }   
 
    vector<int> result;
    for (char c : request) {
        if (c == '?') //'?' 操作 O(1)
            result.push_back(total_ones);
        else { //'-' 操作 O(1)
            if (ones_interval.empty()) { //如果binaryString全是0了，那'-'操作将binaryString全置为1
                ones_interval.push_back({0, n});
                total_ones = n;
                continue;
            }   
            auto &itv = ones_interval.back();
            int idx = itv[0] + itv[1];
            int new_ones = n - idx;
            if (--itv[1] == 0) 
                ones_interval.pop_back();
            if (new_ones > 0)
                ones_interval.push_back({idx, new_ones});
            total_ones = total_ones - 1 + new_ones;
        }   
    }   
 
    return result;
}

```





------

sortChessSubsquares这题input是个二维数组，这个二维数组在图上面展示出来类似于黑白棋，最左上角的点是黑色的，与其相邻的点是白色，以此类推黑色和白色相互交错然后又给了数组类似于[[0,1,2],[0,2,3]]， 意思是其中[0,1,2] 表示最左上角以（0，1）为起点的2*2的矩阵，矩阵中的黑白棋子按照各自的颜色分组进行排序，进行了两次排序后输出得到的数组

```java
void sortChessSubsquares(vector<vector<int>> &matrix, vector<int> &sub)
{
    int rows = matrix.size(), cols = matrix[0].size();
    int x1 = sub[0], y1 = sub[1], k = sub[2];
    int x2 = x1 + k - 1, y2 = y1 + k - 1;
    x2 = min(x2, rows-1);
    y2 = min(y2, cols-1);
 
    vector<int> black, white;
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            if ((x % 2 == 0 && y % 2 == 0) || ((x % 2) && (y % 2)))
                black.push_back(matrix[x][y]);
            else
                white.push_back(matrix[x][y]);
        }   
    }   
 
    sort(black.begin(), black.end());
    sort(white.begin(), white.end());
    int b = 0, w = 0;  
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            if ((x % 2 == 0 && y % 2 == 0) || ((x % 2) && (y % 2)))
                matrix[x][y] = black[b++];
            else
                matrix[x][y] = white[w++];
        }   
    }   
}
 
void print(vector<vector<int>> &matrix)
{
    for (auto &row : matrix) {
        for (auto num : row)
            cout << num << " ";
        cout << endl;
    }   
}
 
int main()
{
    vector<vector<int>> matrix = {{1,4,3,2}, {8,4,7,1}, {1,5,2,1}};
    vector<int> sub = {0, 1, 3}; 
    print(matrix);
    cout << endl;
    sortChessSubsquares(matrix, sub);
    print(matrix);
    return 0;
}

```



------



给一个 int[][] array, 一个菱形的 radius。返回所有菱形 sum 最大的前三个数

```
        1
     1  1  1    radius = 2
        1
 
         1
      1  1  1
   1  1  1   1   1     radius = 3   
      1  1  1
         1

```





------



moving diagonally。一个 n*m的矩阵，start from（x1，y1）一开始以step（dx=1，dy=1）移动，如果x方向移动出了矩阵，step变成（dx=-dx，dy=dy）并且回到移动出矩阵前的位置以新的step方向继续移动。如果y方向移动出了矩阵，step变成（dx=dx，dy=-dy）并且回到移动出矩阵前的位置以新的step方向继续移动。如果x，y方向同时移动出了矩阵，step变成（dx=-dx，dy=-dy）并且回到移动出矩阵前的位置以新的step方向继续移动。要求输出以这种移动方式需要多少step可以移动到（x2，y2），如果无法到达（x2，y2），输出-1 （感觉是其实最短路径的变种，是不是这样？）用一个4维数组记录是否已经visit 某个位置以及移动



------



拼积木给定一个n*m的矩阵和五个俄罗斯方块的形状，不互相重复的往里放俄罗斯方块，每个放好的方块填满index+1，比如第一个方块就fill 1，第二个fill 2，放了最多五个方块后，返回矩阵  

```java
   public class AlmostTetris {
	public static void main(String[] args) {
		int n = 4;
		int m = 4;
		int[] figures = {4, 2, 1, 3};
		AlmostTetris almostTetris = new AlmostTetris();
		UtilityHelper.printMatrix(almostTetris.almostTetris(n, m, figures));
	}
 
	int[][][] figureDimension = {{{0, 0}}, {{0, 0}, {0, 1}, {0, 2}}, {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, {{0, 0}, {1, 0}, {2, 0}, {1, 1}}, {{0, 1}, {1, 0}, {1, 1}, {1, 2}}};
 
	public int[][] almostTetris(int n, int m, int[] figures) {
		int[][] matrix = new int[n][m];
		int code = 1;
		for (int figure : figures) {
			boolean figurePlaced = false;
			for (int i = 0; i < matrix.length; i++) {
				for (int j = 0; j < matrix[i].length; j++) {
					if (isPossibleAtThisPoint(matrix, figureDimension[figure - 1], i, j, code)) {
						figurePlaced = true;
						code++;
						break;
					}
				}
				if (figurePlaced) {
					break;
				}
			}
		}
		return matrix;
	}
 
	private boolean isPossibleAtThisPoint(int[][] matrix, int[][] fd, int x, int y, int code) {
		for (int i = 0; i < fd.length; i++) {
			int next_x = fd[i][0] + x;
			int next_y = fd[i][1] + y;
			if (next_x >= 0 && next_x < matrix.length && next_y >= 0 && next_y < matrix[0].length) {
				if (matrix[next_x][next_y] != 0) {
					return false;
				}
			} else {
				return false;
			}
		}
		for (int i = 0; i < fd.length; i++) {
			int next_x = fd[i][0] + x;
			int next_y = fd[i][1] + y;
			matrix[next_x][next_y] = code;
		}
		return true;
	}
}

```



------





