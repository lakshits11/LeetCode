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
Youtube: Striver video