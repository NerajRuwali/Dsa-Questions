class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        // store all indices of same value
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> visited(n, 0);

        q.push(0);
        visited[0] = 1;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int idx = q.front();
                q.pop();

                // reached end
                if (idx == n - 1) {
                    return steps;
                }

                // i - 1
                if (idx - 1 >= 0 && !visited[idx - 1]) {
                    visited[idx - 1] = 1;
                    q.push(idx - 1);
                }

                // i + 1
                if (idx + 1 < n && !visited[idx + 1]) {
                    visited[idx + 1] = 1;
                    q.push(idx + 1);
                }

                // same value jumps
                for (int nextIdx : mp[arr[idx]]) {

                    if (!visited[nextIdx]) {
                        visited[nextIdx] = 1;
                        q.push(nextIdx);
                    }
                }

                // IMPORTANT optimization
                mp[arr[idx]].clear();
            }

            steps++;
        }

        return -1;
    }
};