/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binary1(MountainArray &arr, int target, int l, int r)
    {
        if(l>r) return -1;
        int mid = l + (r-l)/2;
        int x = arr.get(mid);
        if(x==target)
            return mid;
        else if(x<target)
            return binary1(arr, target, mid+1, r);
        return binary1(arr, target, l, mid-1); 
    }
    
    int binary2(MountainArray &arr, int target, int l, int r)
    {
        if(l>r) return -1;
        int mid = l + (r-l)/2;
        int x = arr.get(mid);
        if(x==target)
            return mid;
        else if(x>target)
            return binary2(arr, target, mid+1, r);
        return binary2(arr, target, l, mid-1); 
    }
    
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr.get(mid)<arr.get(mid+1))
                l = mid+1;
            else r = mid-1;;
        }
        
        int x = binary1(arr, target, 0, l);
        if(x!=-1)
            return x;
        int y = binary2(arr, target, l, n-1);
        return y;
            
    }
};