class Solution {
public:
    int minCost(string clr, vector<int>& nt) {
        int total=0;
        
        for(int i=0;i<clr.size();){
            
            char ch=clr[i];
            int maxi=nt[i];
            i++;
            
            while(i<clr.size()&&ch==clr[i]){
                
                if(nt[i]>maxi){
                    total+=maxi;
                    maxi=nt[i];
                }
                
                else total+=nt[i];
                
                i++;
            }
            
        }
        
        return total;
    }
};