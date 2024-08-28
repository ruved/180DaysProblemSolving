class Solution 
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) 
    {
        vector<vector<int>> grid(n, vector<int> (n, 1));

        for(auto mine: mines)
        {
            int x = mine[0];
            int y = mine[1];

            grid[x][y] = 0;
        }

        // Take DP For All 4 Directions

        // Left
        vector<vector<int>> left(n, vector<int> (n, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j == 0)
                {
                    if(grid[i][j])
                    {
                        left[i][j] = 1;
                    }
                }
                else
                {
                    if(grid[i][j])
                    {
                        left[i][j] = left[i][j - 1] + 1;
                    }
                    else
                    {
                        left[i][j] = 0;
                    }
                }
            }
        }

        // Right
        vector<vector<int>> right(n, vector<int> (n, 0));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(j == n - 1)
                {
                    if(grid[i][j])
                    {
                        right[i][j] = 1;
                    }
                }
                else
                {
                    if(grid[i][j])
                    {
                        right[i][j] = right[i][j + 1] + 1;
                    }
                    else
                    {
                        right[i][j] = 0;
                    }
                }
            }
        }
        
        // Top
        vector<vector<int>> top(n, vector<int> (n, 0));
        
        for(int j = 0; j < n; j++)
        {
            for(int i = 0; i < n; i++)
            {
                if(i == 0)
                {
                    if(grid[i][j])
                    {
                        top[i][j] = 1;
                    }
                }
                else
                {
                    if(grid[i][j])
                    {
                        top[i][j] = top[i - 1][j] + 1;
                    }
                    else
                    {
                        top[i][j] = 0;
                    }
                }
            }
        }

        // Bottom
        vector<vector<int>> bottom(n, vector<int> (n, 0));
        
        for(int j = 0; j < n; j++)
        {
            for(int i = n - 1; i >= 0; i--)
            {
                if(i == n - 1)
                {
                    if(grid[i][j])
                    {
                        bottom[i][j] = 1;
                    }
                }
                else
                {
                    if(grid[i][j])
                    {
                        bottom[i][j] = bottom[i + 1][j] + 1;
                    }
                    else
                    {
                        bottom[i][j] = 0;
                    }
                }
            }
        }

        // Calculate Maximum
        
        int maximum = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j])
                {
                    int left_co = left[i][j];
                    
                    int right_co = right[i][j];
                    
                    int top_co = top[i][j];
                    
                    int bottom_co = bottom[i][j];
                
                    int curr = min({top_co, bottom_co, left_co, right_co});
                    
                    maximum = max(maximum, curr);
                }
            }
        }
        
        return maximum;

    }
};