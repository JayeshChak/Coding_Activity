// Disjoint Set - Union Find Implementation Question

class DSU{

    public: 
        int components; 
        vector<int>parent, rank;
    
        DSU(int v){
            this->components = v; 
            parent.resize(v+1);
            rank.resize(v+1); 

            for(int i=0; i<=v; i++){
                parent[i] = i;
                rank[i] = 0;
            } // khud hi parent he initially
        }

        int findPar(int x){
            if(parent[x]==x) return x; 

            return parent[x] = findPar(parent[x]);
        }

        void unionSet(int x, int y){

            int parX = findPar(x); 
            int parY = findPar(y);

            if(parX==parY) return;

            if(rank[parX] > rank[parY]){
                parent[parY] = parX;
            }
            else if(rank[parY] > rank[parX]){
                parent[parX] = parY; 
            }
            else{
                parent[parY] = parX;
                rank[parX]++;
            }
            components--; 
            return; 
        }

};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        
        sort(begin(e), end(e), greater<vector<int>>());

        // pehle 3 vali type ko bitha denge dono k liye.. taki fir agr same nodes k bich type 1 ya 2 aaye to vo eliminate honi chahiye

        DSU alice(n); 
        DSU bob(n); 

        int connects = 0;
        for(auto edge : e){
            int type = edge[0]; 
            int u = edge[1];
            int v = edge[2];

            if(type==3){
                // find if there is already edge between u and v => if they are of same class
                int pu = alice.findPar(u); 
                int pv = alice.findPar(v);

                if(pu==pv) continue; 

                alice.unionSet(u, v);
                bob.unionSet(u, v);
                connects++;

            }
            else if(type==1){
                int pu = alice.findPar(u); 
                int pv = alice.findPar(v); 
                if(pu==pv) continue; 

                alice.unionSet(u, v);
                connects++;
            }
            else{
                int pu = bob.findPar(u); 
                int pv = bob.findPar(v); 
                if(pu==pv) continue; 

                bob.unionSet(u, v);
                connects++;
            }
        }


        if(alice.components!=1 || bob.components!=1) return -1; 
        return size(e) - connects; 

    }
};