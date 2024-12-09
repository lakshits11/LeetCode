/*
so basically thinking of prefix array. store adjacent checks in an array and do a prefix sum.
ex: 3, 4, 1, 2, 6
prefix[0]=1 i.e. element 3

now check 4 and 3 and since they are of opposite parity, store p[1]=1
the xor operation is fast way of checking.
- now do prefix sum
- now suppose given index [1,3] so if all are of opposite parity in that range then the sum of that range should be equal to (3-1)+1.
- sum of that range p[3]-p[1]+1
just compare the two and store in array
*/​
