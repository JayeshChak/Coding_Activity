class Solution {
public:
    vector<int> intersect(vector<int>& num1, vector<int>& num2) {
        
        sort(num1.begin(), num1.end());
        sort(num2.begin(), num2.end());
        
        int n = num1.size();
        int m = num2.size();
        
        int i = 0, j = 0;
        vector<int> ans;
        
        while (i < n && j < m) {
            if (num1[i] == num2[j]) {
                ans.push_back(num1[i]);
                i++;
                j++;
            } else if (num1[i] < num2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return ans;        
    }
};
