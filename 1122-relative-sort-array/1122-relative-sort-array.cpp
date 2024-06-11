class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        map<int, int> mp;
        
        for (auto i : arr1) {
            mp[i]++;
        }
        
        vector<int> answer;
        
        for (int i = 0; i < arr2.size(); i++) {
            int val = mp[arr2[i]];
            
            while (mp[arr2[i]]--) {
                answer.push_back(arr2[i]);
            }
            mp[arr2[i]] = 0;
        }
        
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            while (it->second > 0) {
                answer.push_back(it->first);
                it->second--;
            }
        }
        
        return answer;
    }
};
