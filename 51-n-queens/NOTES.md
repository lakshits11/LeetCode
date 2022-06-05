Use backtracking.
​
on board, for each col, check if a queen can be placed here and if it can be, place it and call the recursive function to check for the next column. then remove the placed queen because we will have to backtrack.
​
to check if it is safe to place a queen on any [row,col] ew call isSafe function.
​
it checks in these 3 drxns:
1. <- (left cols)
2. \  (upper left diagonal)
3. /  (lower left diagonal)
​
The above approach for for isSafe function is inefficient.
Efficient approach would be to maintain hashing for left cols, upr diag, lower diag.
​
for left col, we would simply maintain a row hash.whenever we place a queen, we mark that row number as 1 in our hash. So next time whne we want to check the left cols in same row, we would easily know if theres a queen in that same row or not.
i.e. check hash(row)==1
​
for lower left diagonal, make a 1d vector matrix and mark its index number (row+col) to be 1 whenever we place a queen.
i.e. check hash(row+col)==1
​
![Lower left diagonal](https://lh6.googleusercontent.com/UZm_6j1v5WQYlA0Y7wMo4LObyB2TdWcWGeZegccZ9VxeDkgf3en9IG9-gnSKtZLAH3b0auF75tyc0oNWC6J1_MFgeqKOGsvQTny6nBD2padF6sISb0LWv16wj9Acy3-Q-4gU_FlB)
​
for upper left diagonal, use (n-1)+(row-col) formula.
i.e. check if hash(n-1+row-col)==1  ,then it measn queen is there in some left upper diagonal.
​
So in total we would have to maintain 3 hash vectors each with space of O(n).
​
Total Space Complexity: O(N)
Total Time Complexity: O(N! * N)
​
Youtube: Striver video
​