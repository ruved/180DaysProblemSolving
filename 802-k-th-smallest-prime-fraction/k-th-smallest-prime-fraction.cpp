class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float, pair<int, int>>> q;

        int n=arr.size();

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
               q.push({(float)arr[i]/arr[j],{arr[i], arr[j]}});
                if(q.size() > k)q.pop();
            }
        }

        return {q.top().second.first, q.top().second.second};
    }
};