#include <stack>

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        stack<char> stk;
        
        for(auto i : s){
            stk.push(i);
        }
        
        s.clear();
        
        while(stk.empty() != true){
            s.push_back(stk.top());
            stk.pop();
        }
        
    }
};