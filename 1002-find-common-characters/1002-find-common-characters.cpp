class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        vector<int> ans(26, INT_MAX);

        for (int i = 0; i < words.size(); i++) {
            vector<int> arr(26, 0);
            
            for (int j = 0; j < words[i].length(); j++) {
                arr[words[i][j] - 'a']++;
            }
            
            for (int j = 0; j < 26; j++) {
                ans[j] = min(ans[j], arr[j]);
            }
        }
        
        vector<string> seq;
        
        for (int i = 0; i < 26; i++) {
            while (ans[i] > 0) {
                char ch = 'a' + i;
                seq.push_back(string(1, ch));
                ans[i]--;
            }
        }
        
        return seq;
    }
};
