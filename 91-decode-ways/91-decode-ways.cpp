class Solution {
public:
int findans(string s,vector<int> &dp,int st){
    int isvalid,j,n=s.length();
	
    //if string is not valid
    if(n-st<0 || s[st]=='0') return 0;
	
    //if we are on last or come from last position
    if(n-st==1 ||n-st==0) return 1;
	
    //if we already visited this
    if(dp[st]!=-1) return dp[st];
	
    //to calculate if next choise is valid or not
   isvalid=(s[st]-'0')*10+(s[st+1]-'0');
   
   //for the current index
    j=findans(s,dp,st+1);
	
    if(isvalid<=26){
	//if next is valid we need to calculate this also
        j+=findans(s,dp,st+2);
    }
	
    return dp[st]=j;
}

int numDecodings(string s) {
    int n=s.length();
    vector<int> dp(n+1,-1);
    
    return findans(s,dp,0);
}
};