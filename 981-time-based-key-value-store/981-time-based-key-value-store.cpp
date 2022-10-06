class TimeMap {
    unordered_map<string, vector<pair<int, string>>> umap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int left = 0, right = umap[key].size()-1, posIdx = -1;
        while(left <= right){
            int mid = (left + right)/2;
            if(umap[key][mid].first <= timestamp ){
                posIdx = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        if (posIdx == -1){
            return "";
        }
        return umap[key][posIdx].second;
    }
};