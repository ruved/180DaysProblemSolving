class Solution {
public:
    public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            // Update heights for the current row
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            // Calculate the max area for this row's histogram
            maxArea = max(maxArea, largestRectangleInHistogram(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleInHistogram(vector<int>& heights) {
        stack<int> s;
        // Add a sentinel 0 at the end to ensure we pop everything from the stack
        heights.push_back(0); 
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            // While the current height is smaller than the stack top, we've found a boundary
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                
                // If stack is empty, width is 'i', else it's distance between i and current top
                int w = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            s.push(i);
        }
        
        // Clean up the heights vector for the next row call
        heights.pop_back(); 
        return maxArea;
    }
};