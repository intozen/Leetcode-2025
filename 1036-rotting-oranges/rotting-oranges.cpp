class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*
            where ever this is 2 push it to the queue and do a bfs on the above
           graph all cells with 1 make it 2 if there are getting visited at the
           end of the bfs traversal if nodes which are not visited have 1 in
           them then return -1 else return the number of steps it took to
           complete the bfs bfs by nature will give you the minimum number of
           steps to cover the graph


        */

        queue<pair<int, int>> q;
        vector<vector<int>> visited = grid;
        int numberOfOnes = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    numberOfOnes++;
                }
            }
        }
         if (numberOfOnes == 0){
            return 0;
        }
        if (q.empty() && numberOfOnes>0) {
            return -1;
        }
        
       
        int m = grid.size();
        int n = grid[0].size();
        int ans = -1;
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
        while(!q.empty()) {
            int size =  q.size();
            while(size--) {
                auto [x,y] = q.front();
                q.pop();
                for(auto it: directions) {
                    int i = x + it.first;
                    int j = y + it.second;
                    if(i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                        visited[i][j] = 2;
                        numberOfOnes--;
                        q.push({i,j});
                    }
                }
            }
            ans++;
        }
        if(numberOfOnes == 0){
            return ans;
        }
        return -1;
    }
};