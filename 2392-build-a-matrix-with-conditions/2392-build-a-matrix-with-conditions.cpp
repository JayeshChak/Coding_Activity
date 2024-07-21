class Solution {
public:
    void topoSortUtil(stack<int>& stk, vector<int>& vis, int curr, vector<vector<int>>& adjMat, bool& cycle){
        if(cycle) return;

        vis[curr] = 1;

        for(int i=0; i<adjMat[curr].size(); i++){
            int neighbour = adjMat[curr][i];
            if(vis[neighbour]==0){
                topoSortUtil(stk, vis, neighbour, adjMat, cycle);
            }else if(vis[neighbour]==1) {
                cycle = true;
                return;
            }
        }
        
        vis[curr] = 2;
        stk.push(curr);
    }

    vector<int> topoSort(vector<vector<int>>& conditions, int k){
        vector<vector<int>> adjMat(k);

        stack<int> stk;
        vector<int> vis(k, 0);
        vector<int> order;

        //matrix adjacency
        for(int i=0; i<conditions.size(); i++){  
            int src = conditions[i][0];
            int dest = conditions[i][1];
            adjMat[src-1].push_back(dest-1);
        }
        
        bool cycle = false;
        for(int i=0; i<k;i++){
            if(vis[i]==0){
                topoSortUtil(stk, vis, i, adjMat, cycle);  
                if(cycle==true) return {};             
            }
        }

        while(!stk.empty()){
            order.push_back(stk.top()+1);
            stk.pop();
        }

        return order;
        
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
       

        vector<int> orderForRowCond = topoSort(rowConditions, k); // for topoSort Algo
        vector<int> orderForColCond = topoSort(colConditions, k);


        if(orderForRowCond.size()==0 || orderForColCond.size()==0) return {};  //check for cycle
        

        vector<vector<int>> finalMat(k, vector<int> (k, 0));  //initalizing final matrix

        unordered_map<int,int> colIdx;   //storing positions of numbers from 1-k

        for(int i=0; i<orderForColCond.size(); i++){
            colIdx[orderForColCond[i]] = i;
        }

        for(int i=0; i<orderForRowCond.size(); i++){  //making final matrix
            int idx = colIdx[orderForRowCond[i]];
            finalMat[i][idx] = orderForRowCond[i];

        }


        return finalMat;
    }
};