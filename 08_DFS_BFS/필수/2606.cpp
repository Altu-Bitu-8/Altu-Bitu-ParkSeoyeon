#include <iostream>
#include <vector>

using namespace std;

int n, m;


void findWorms(const vector<vector<int>>& network, vector<bool>& wormed, int from, int& count){

    for(int i = 1; i <= n; ++i){
        if(network[from][i] == 1 && !wormed[i]){
            wormed[i] = true;
            count++;
            findWorms(network, wormed, i, count);
        }
    }

}

int main(){

    cin >> n >> m;

    vector<vector<int>> network(n+1, vector<int>(n+1, 0));
    vector<bool> wormed(n+1, false);
    int count = 0;

    for(int i=0; i<m; i++){
        int com1, com2;
        cin >> com1 >> com2;
        network[com1][com2] = 1;
        network[com2][com1] = 1;
    }

    wormed[1] = true;
    findWorms(network, wormed, 1, count);

    cout << count;

    return 0;
}