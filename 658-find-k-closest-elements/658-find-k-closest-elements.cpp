class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<int> ans;
        int s = 0;
        int e = arr.size() - 1;
        
        // excluding elements which are not closer
        while(e - s  >= k) {
            if(abs(arr[s] - x) > abs(arr[e] - x)) s++;
            else e--;
        }
        
        // pushing rest of the k elements
        for(int i = s; i <= e; i++) {
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};