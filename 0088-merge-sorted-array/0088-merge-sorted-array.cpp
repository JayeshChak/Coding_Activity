class Solution {
public:
    void insertElement(vector<int>& arr, int k) {
        int index = arr.size(); 
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= k) {
                index = i;
                break;
            }
        }
        
        arr.push_back(0);
        for (int i = arr.size() - 1; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = k;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        nums1.resize(m);
        for (int i = 0; i < n; i++) {
            insertElement(nums1, nums2[i]);
        }
    }
};