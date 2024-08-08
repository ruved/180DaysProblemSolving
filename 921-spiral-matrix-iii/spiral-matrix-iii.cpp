class Solution {
public:
inline bool check(vector<int> &cur, int R, int C){
	if(cur[0] >= 0 && cur[1] >= 0 && cur[0] < R && cur[1] < C)
		return true;
	return false;
}
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        vector<int> cur = {r0, c0};
        ans.push_back(cur);
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int totsteps = 2*max(R, C); totsteps*=totsteps;
		int stepi = 0, d = 0;                   
        int linelen = 1;
        while(stepi <= totsteps){
            for(int a = 1; a <=2; ++a){          
                int k = 1;                       
                while(k <= linelen){
                    cur[0] += dir[d][0];
                    cur[1] += dir[d][1];
                    if(check(cur, R, C)) ans.push_back(cur);
                    k++; stepi++;
                }
                d = (d+1)%4;
            }
            linelen++;
        }
        return ans;
    }
};