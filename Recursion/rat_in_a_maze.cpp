class Solution {
private:
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m) {
        if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1) {
            return true;
        } else {
            return false;
        }
    }

    void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
        // Base case
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = 1;

        // Define the possible moves
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        char direction[] = {'D', 'U', 'L', 'R'};

        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (isSafe(newx, newy, n, visited, m)) {
                path.push_back(direction[i]);
                solve(m, n, ans, newx, newy, visited, path);
                path.pop_back();
            }
        }

        // Mark the current cell as unvisited (backtrack)
        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;

        // Check if the start cell is blocked
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0) {
            return ans;
        }

        int srcx = 0;
        int srcy = 0;

        // Create a visited matrix and initialize it to 0
        vector<vector<int>> visited(n, vector<int>(n, 0));

        string path = "";
        solve(m, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
