class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        if(arr.size()>=3){
            for(int i = 0 ; i<arr.size()-2 ; i++){

                int a = arr[i];
                int b = arr[i+1];
                int c = arr[i+2];

                if ((a*b*c)%2 != 0){
                    return true;
                }

            }
            return false;
        }
        
            return false;
    }
};