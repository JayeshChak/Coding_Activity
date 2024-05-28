class Solution {
public:

    int nCr(int n, int r){
        int res = 1;
        for(int i = 0 ; i<r ; i++){
            res = res * (n-i);
            res = res/(i+1);
        }
        return res;
    }

    vector<int> genRow(int k){
        vector<int> ans;

        for(int i = 0 ; i<= k ; i++){
            ans.push_back(nCr(k,i));
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans ;

        for(int i = 0 ; i < numRows ; i++){
            ans.push_back(genRow(i));
        }

        return ans;        
    }
};