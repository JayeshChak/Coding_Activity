class Solution {
public:
    int longestPalindrome(string s) {
        
        ios_base::sync_with_stdio(false); // Disable synchronization
        cin.tie(NULL); // Untie cin from cout
        cout.tie(NULL); // Untie cout from cin
        
        int count[128] = {0};
        
        for(char c : s) {
            count[c]++;
        }
        
        int length = 0;
        bool hasOdd = false;
        
        for(int i = 0; i < 128; i++) {
            if(count[i] % 2 == 0) {
                length += count[i];
            } else {
                length += count[i] - 1;
                hasOdd = true;
            }
        }
        
        if(hasOdd) {
            length++;
        }
        
        return length;
    }
};
