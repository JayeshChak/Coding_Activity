class Solution {
public:
    int scoreOfString(string s) {
    
    int score = 0;
        
    for(int i = 0 ; i< s.length()-1 ; i++){
        
        int aciiVal1 = int(s[i]);
        int aciiVal2 = int(s[i+1]);
        
        score = score + abs(aciiVal1-aciiVal2);      
    }
        
    return score;
        
    }
};