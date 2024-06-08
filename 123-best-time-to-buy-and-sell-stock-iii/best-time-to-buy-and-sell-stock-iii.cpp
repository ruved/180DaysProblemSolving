class Solution {
public:
int help(vector<int>&prices,int k,int i,bool canbuy,vector<vector<vector<int>>>&mp){
    
	if(i>=prices.size()||k<=0) return 0;
	int profitA=0,profitB=0,profitC=0;
	
	if(mp[i][k][canbuy]!=-1) return mp[i][k][canbuy];
	
	if(canbuy)
        profitC=-prices[i]+help(prices,k,i+1,!canbuy,mp);
    else
        profitA=prices[i]+help(prices,k-1,i+1,!canbuy,mp);
    
	profitB=help(prices,k,i+1,canbuy,mp);
	return mp[i][k][canbuy]=max(profitC,max(profitA,profitB));
}
    int maxProfit(vector<int>& prices) {
        int k=2;
        vector<vector<vector<int>>>mp(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
	return help(prices,k,0,true,mp);
    }
};