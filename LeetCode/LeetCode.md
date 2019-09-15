## LeetCode 刷题笔记

1. 二叉树的遍历问题

   问题描述：

   ```
   Given the root of a binary search tree with distinct values, modify it so that every node has a new value equal to the sum of the values of the original tree that are greater than or equal to node.val.
   ```

   掌握二叉树的三种不同顺序的遍历方式：先序、中序、后序

   ```
   1）用递归的方式实现较为简单和自然，但是时间复杂度较高
   2）数据结构课上讲过的不使用递归方式的求解：
   ```

2. Moving Stones Until Consecutive

   问题描述：

   ```
   On an infinite number line, the position of the i-th stone is given by stones[i].  Call a stone an endpoint stone if it has the smallest or largest position.
   Each turn, you pick up an endpoint stone and move it to an unoccupied position so that it is no longer an endpoint stone.
   In particular, if the stones are at say, stones = [1,2,5], you cannot move the endpoint stone at position 5, since moving it to any position (such as 0, or 3) will still keep that stone as an endpoint stone.
   The game ends when you cannot make any more moves, ie. the stones are in consecutive positions.
   When the game ends, what is the minimum and maximum number of moves that you could have made?  Return the answer as an length 2 array: answer = [minimum_moves, maximum_moves]
   ```

   关键是对于这个问题的理解以及掌握滑动窗口遍历这一方法应用于区间问题：

   ```C++
   vector<int> numMovesStonesII(vector<int>& A) {
   	sort(A.begin(), A.end());
   	int n = A.size(), low = n;
   	for (int i = 0, j = 0; j < n; ++ j) {
   		while (A[j]-A[i]+1 > n) ++ i;
   		int already_store = (j-i+1);
   		if (already_store == n - 1 &&  A[j] - A[i] + 1 == n-1) {
   			low = min(low, 2);
   		} else {
   			low = min(low, n - already_store);
   		}
   	}
   	return  {low, max(A[n-1]-A[1]-n+2, A[n-2]-A[0]-n+2)};
   }
   ```

3. 判断三点共线：$$(a_x-c_x)*(b_y-c_y) == (b_x-c_x)*(a_y-c_y)$$

4. 用栈处理带表达式的问题，尤其是存在括号的情况

5. 动态规划的思想和题型：

   问题描述：

   ```
   We have a sequence of books: the i-th book has thickness books[i][0] and height books[i]
   We want to place these books in order onto bookcase shelves that have total width shelf_width.
   We choose some of the books to place on this shelf (such that the sum of their thickness is <= shelf_width), then build another level of shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down.  We repeat this process until there are no more books to place.
   Note again that at each step of the above process, the order of the books we place is the same order as the given sequence of books.  For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
   Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.
   ```

   动态规划分为线性模型（过桥问题）、区间模型（最小回文串问题）和背包模型（01背包问题）

   代码：

   ```C++
   class Solution {
   public:
       int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
           int dp[books.size()+1] = {0};
           dp[0] = 0;
           for(int i=1; i<=books.size(); ++i){
               int w = books[i-1][0];
               int h = books[i-1][1];
               dp[i] = dp[i-1] + books[i-1][1];
               for(int j=i-1; j>0; --j){
                   w += books[j-1][0];
                   h = max(h, books[j-1][1]);
                   if(w > shelf_width) break;
                   dp[i] = min(dp[i], dp[j-1] + h);
               }
           }
           return dp[books.size()];
       }
   };
   ```

6. 最长重复字串求解

   round-karp 算法：把字符串看作是字符集长度进制的数，由数值的比较结果得出字符串的比较结果。

   后缀数组完成字符串匹配：
