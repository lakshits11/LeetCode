class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int arr[26];
        int temp[26];
        int ans = 0;
        memset(arr, -1, sizeof(arr));

        for (char c : chars) {
            if (arr[c - 'a'] == -1)
                arr[c - 'a'] = 1;
            else
                arr[c - 'a']++;
        }

        for (int i = 0; i < words.size(); i++) {
            memset(temp, -1, sizeof(arr));
            bool canFormWord = true;

            for (int j = 0; j < words[i].size(); j++) {
                if (temp[words[i][j] - 'a'] == -1)
                    temp[words[i][j] - 'a'] = 1;
                else
                    temp[words[i][j] - 'a']++;
            }

            for (int x = 0; x < 26; x++) {
                if (arr[x] < temp[x]) {
                    canFormWord = false;
                    break;
                }
            }

            if (canFormWord) {
                ans += words[i].size();
            }
        }

        return ans;
    }
};