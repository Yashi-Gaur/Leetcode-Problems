class Solution {
public:
    double dfs(vector<vector<pair<int, double>>> adj, int a, int b) {
        double ans = 1;
        int found = 0;

        vector<int> visited(adj.size());
        stack<pair<int, double>> s;
        s.push({a, ans});
        visited[a] = 1;
        while(!s.empty()) {
            int curr = s.top().first;
            ans = s.top().second;
            if(curr == b) return ans;
            s.pop();
            for(auto i: adj[curr]){
                if(!visited[i.first]) {
                    s.push({i.first, ans*i.second});
                    visited[i.first] = 1;
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> m;
        int x = 0;
        for(int i = 0; i < equations.size(); i++) {
            if(m.find(equations[i][0]) == m.end()) {
                m[equations[i][0]] = x;
                x++;
            }
            if(m.find(equations[i][1]) == m.end()) {
                m[equations[i][1]] = x;
                x++;
            }
        }
        vector<vector<pair<int, double>>> adj(x);
        for(int i = 0; i < equations.size(); i++) {
            adj[m[equations[i][0]]].push_back({m[equations[i][1]], values[i]});
            adj[m[equations[i][1]]].push_back({m[equations[i][0]], (1/values[i])});
        }

        vector<double> ans;
        for(int i = 0; i < queries.size(); i++) {
            if(m.find(queries[i][0]) == m.end() || m.find(queries[i][1]) == m.end()) {
                ans.push_back(-1);
            }
            else {
                int a = m[queries[i][0]];
                int b = m[queries[i][1]];
                ans.push_back(dfs(adj, a, b));
            }
        }
        return ans;
    }
};