class Solution {
public:
// string help(int a, int b, int c,char prev){
//     if(a==0&&b==0&&c==0) return "";
//     string ans="";
//      string temp="";
//      string t="";
//     for(int i=1;i<=2;++i)
//         if(a-i>=0&&prev!='a'){
//             t+="a";
//            temp=t+help(a-i,b,c,'a');
//            if(temp.length()>ans.length())
//             ans=temp;
//         }
//     t="";
//     for(int i=1;i<=2;++i)
//         if(b-i>=0&&prev!='b'){
//             t+="b";
//            temp=t+help(a,b-i,c,'b');
//            if(temp.length()>ans.length())
//             ans=temp;
//         }
//     t="";
//     for(int i=1;i<=2;++i)
//         if(c-i>=0&&prev!='c'){
//             t+="c";
//            temp=t+help(a,b,c-i,'c');
//            if(temp.length()>ans.length())
//             ans=temp;
//         }
//         return ans;

// }
    string longestDiverseString(int a, int b, int c) {
        // return help(a,b,c,'d');
         priority_queue<pair<int,char>> pq;

    if(a > 0) pq.push({a,'a'});
    if(b > 0) pq.push({b,'b'});
    if(c > 0) pq.push({c,'c'});

    string ans = "";

    while(!pq.empty()) {

        auto last1 = pq.top();
        pq.pop();

        int n = ans.size();

        // If adding last1 creates 3 consecutive
        if(n >= 2 && ans[n-1] == last1.second && ans[n-2] == last1.second) {

            if(pq.empty()) break;

            auto last2 = pq.top();
            pq.pop();

            ans += last2.second;
            last2.first--;

            if(last2.first > 0)
                pq.push(last2);

            pq.push(last1);
        }
        else {
            int use = min(2, last1.first);
            ans += string(use, last1.second);
            last1.first -= use;

            if(last1.first > 0)
                pq.push(last1);
        }
    }

    return ans;
    }
};