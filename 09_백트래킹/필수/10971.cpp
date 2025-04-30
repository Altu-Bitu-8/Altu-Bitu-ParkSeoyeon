#include <iostream>
#include <vector>

using namespace std;

int n;
int min_cost = 1000000 * 9;

void findMinCost(const vector<vector<int>>& cost, vector<bool> visited, int prev, int cost_now, int visit_count){

    if(visit_count == n){
        if(cost[prev][0] != 0){
            cost_now += cost[prev][0];
        
            if(cost_now < min_cost){
                min_cost = cost_now;
            }
        }
        
        return;
    }

    for(int i=0; i<n; i++){
        if(!visited[i] && cost[prev][i] != 0){
            visited[i] = true;
            findMinCost(cost, visited, i, cost_now + cost[prev][i], visit_count+1);
            visited[i] = false;
        }
        
    }

    return;


}

int main(){

    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    vector<bool> visited(n, false);
    visited[0] = true;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> cost[i][j];
        }
    }

    findMinCost(cost, visited, 0, 0, 1);

    cout << min_cost;

    return 0;
}