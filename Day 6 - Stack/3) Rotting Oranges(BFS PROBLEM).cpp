//https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        if(grid.size()==0 || grid[0].size()==0)
            return 0;
        queue<pair<int, int>> q;
        int i, j, n=grid.size(), m=grid[0].size(), fresh=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    fresh++;
        q.push({-1,-1});
        int X[]={0,0,1,-1};
        int Y[]={1,-1,0,0};
        int c=0;
        while(!q.empty())
        {
            int x=q.front().first, y=q.front().second, newX, newY;
            q.pop();
            if(x==-1 && y==-1)
            {
                if(q.size()!=0)
                {
                    q.push({-1,-1});
                    c++;
                }
            }
            else
            {
                for(i=0;i<4;i++)
                {
                    newX = x + X[i];
                    newY = y + Y[i];
                    if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1)
                    {
                        grid[newX][newY]=2;
                        q.push({newX,newY});
                        fresh--;
                    }
                }
            }
        }
        if(fresh!=0)
            return -1;
        return c;
    }
};
