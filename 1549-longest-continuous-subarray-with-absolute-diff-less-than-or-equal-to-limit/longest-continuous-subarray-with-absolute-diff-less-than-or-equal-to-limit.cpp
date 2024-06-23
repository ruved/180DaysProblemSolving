class Solution {
public:
    int longestSubarray(vector<int>& arr, int l) {
       int i = 0, j = 0, ret = 0;
        deque<int> q1; 
        deque<int> q2; 

        for (; j < arr.size(); j++) {

            while (!q1.empty() && arr[q1.back()] > arr[j])
                q1.pop_back();
            q1.push_back(j);

            while (!q2.empty() && arr[q2.back()] < arr[j])
                q2.pop_back();
            q2.push_back(j);

            while (arr[q2.front()] - arr[q1.front()] > l) {
                if (q2.front() == i) q2.pop_front();
                if (q1.front() == i) q1.pop_front();
                i++;
            }

            ret = max(ret, j - i + 1);
        }
        return ret;
    }
};