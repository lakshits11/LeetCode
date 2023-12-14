static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int res = 0;
    int n;
    int arr[16];
    void swap(int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    void check(int pos)
    {
        if(pos == n+1){ ++res;return;}
        for(int i = pos; i < n+1; ++i)
        {
            swap(i, pos);
            if(arr[pos]%pos==0 || pos%arr[pos]==0)
                check(pos+1);
            swap(i, pos);
        }
    }
    
    
    int countArrangement(int x) {
        n=x;
        if(n<4) return n;
        for(int i=0;i<16;i++) arr[i]=i;
        check(1);
        return res;
    }
};