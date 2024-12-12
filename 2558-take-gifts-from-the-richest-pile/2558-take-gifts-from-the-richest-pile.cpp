static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long int total=0;
        for(int i=0;i<gifts.size();i++)
        {
            pq.push(gifts[i]);
            total+=gifts[i];
        }
        for(int i = 0; i < k; ++i)
        {
            int elem = pq.top();
            pq.pop();
            int es = sqrt(elem);
            cout << "n: " << elem << " ==== sqrt: " << es << "\n";
            total -= (elem-es);
            if(elem>es){
                pq.push(es);
            }
            else pq.push(elem);
        }
        return total;
    }
};