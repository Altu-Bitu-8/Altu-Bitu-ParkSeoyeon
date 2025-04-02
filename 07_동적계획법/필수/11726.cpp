#include <iostream>
#include <vector>

using namespace std;

int findWays(int col){
    vector<int> dp(col+1, 0);

    if(col == 1){
        return 1;
    }

    dp[1] = 1;
    dp[2] = 2;


    for(int i=3; i<col+1; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    return dp[col];
}

int main(){

    int col;
    cin >> col;

    int res = findWays(col);
    cout << res;

    return 0;
}