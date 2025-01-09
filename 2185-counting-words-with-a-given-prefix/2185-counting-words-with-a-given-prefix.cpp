static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int preflen=pref.size();
        
        for(auto i:words){
            if(i.substr(0,preflen) == pref)
                count++;                   
        }
        return count;
    }
};