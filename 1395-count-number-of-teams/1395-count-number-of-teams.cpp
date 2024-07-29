class Solution {
    void update(vector<int> &v, int i, const int d) {
        for (; i < v.size(); v[i] += d, i += (i & -i));
    }
    
    int presum(const vector<int> &v, int i) {
        int r = 0;
        for (; i; r += v[i], i -= (i & -i));
        return r;
    }
    
public:
    int numTeams(vector<int>& rating) {
        map<int, int> have;
        for (int x : rating) {
            have[x];
        }
        int n = 0;
        vector<int> after(rating.size() + 1);
        for (auto& t : have) { 
            update(after, t.second = ++n, 1);
        }
        vector<int> before(n + 1);
        int r = 0;
        for (int i = 0; i < n; ++i) {
            const int x = have[rating[i]], t1 = presum(before, x), t2 = presum(after, x);
            r += t1 * (n - i - t2) + (i - t1) * (t2 - 1);
            update(after, x, -1);
            update(before, x, 1);
        }
        return r;
        
    }
};