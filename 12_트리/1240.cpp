#include <iostream>
#include <vector>

using namespace std;

int dfs(const vector<vector<pair<int, int>>>& tree, int current, int target, vector<bool>& visited, int dist){

    if(current == target) return dist;
    visited[current] = true;

    for (const auto& next : tree[current]){
        int node = next.first;
        int node_dist = next.second;

        if (!visited[node]) {
            int result = dfs(tree, node, target, visited, dist + node_dist);
            if (result != -1) return result; 
        }
    }

    return -1;

}

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> tree(n+1);
    for(int i=1; i<n; i++){
        int node_1, node_2, dist;
        cin >> node_1 >> node_2 >> dist;

        tree[node_1].push_back({node_2, dist});
        tree[node_2].push_back({node_1, dist});
    }

    vector<pair<int, int>> test_case(m);
    for(int i=0; i<m; i++){
        int node_1, node_2;
        cin >> node_1 >> node_2;
        test_case[i] = {node_1, node_2};
    }

    for(int i=0; i<m; i++){
        vector<bool> visited(n+1, false);
        cout << dfs(tree, test_case[i].first, test_case[i].second, visited, 0) << '\n';
    }

    

    return 0;
}