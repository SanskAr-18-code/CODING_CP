#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int start)
    {
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int nrow = sr + dr[k];
            int ncol = sc + dc[k];
            if (nrow >= 0 && nrow < image.size() && ncol >= 0 && ncol < image[0].size() && image[nrow][ncol] == start)
            {
                image[nrow][ncol] = color;
                dfs(image, nrow, ncol, color, start);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int start = image[sr][sc];
        if (start == color)
            return image;

        image[sr][sc] = color;

        dfs(image, sr, sc, color, start);

        return image;
    }
};