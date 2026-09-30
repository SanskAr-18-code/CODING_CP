#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void bfs(vector<vector<int>> &grid, queue<pair<int, int>> &q, int &time,int &fresh)
    {
        int m = grid.size();
        int n = grid[0].size();
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};

                for (int k = 0; k < 4; k++)
                {
                    int nrow = row + dr[k];
                    int ncol = col + dc[k];
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                        grid[nrow][ncol] == 1)
                    {
                        fresh--;
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                    }
                }
            }
            if (!q.empty())
                time++;
        }
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        int fresh=0;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        bfs(grid, q, time,fresh);
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (grid[i][j] == 1)
        //         {
        //             return -1;
        //         }
        //     }
        // }
        if(fresh>0) return -1;
        
        return time;
    }
};