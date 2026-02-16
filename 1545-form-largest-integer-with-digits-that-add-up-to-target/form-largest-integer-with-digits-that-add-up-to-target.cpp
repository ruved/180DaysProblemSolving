class Solution {
public:
string help(vector<int>& cost, int target,vector<string>&dp){
    if (target == 0) return "";
        if (target < 0) return "#";

        if (dp[target] != "-1") return dp[target];

        string ans = "#";

        for (int i = 0; i < 9; ++i) {

            if (target >= cost[i]) {

                string next = help(cost, target - cost[i], dp);

                if (next != "#") {

                    string temp = char('1' + i) + next;

                    if (ans == "#" ||
                        temp.length() > ans.length() ||
                        (temp.length() == ans.length() && temp > ans)) {

                        ans = temp;
                    }
                }
            }
        }

        return dp[target] = ans;
}
    string largestNumber(vector<int>& cost, int target) {
        vector<string>dp(target+1,"-1");
        string ans= help(cost,target,dp);
        return (ans=="#")?"0":ans;
    }
};