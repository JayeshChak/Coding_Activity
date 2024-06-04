class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> mp; 
        
        for(char c : s) {
            mp[c]++;
        }
        
        int count = 0;
        bool ifSingleCharExist = false;
        
        for(auto it : mp) {
            if(it.second % 2 == 0) {
                count += it.second; 
            } else {
                count += it.second - 1; 
                ifSingleCharExist = true; 
            }
        }
        
        if(ifSingleCharExist) {
            count++; 
        }
        
        return count;
    }
};
