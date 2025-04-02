#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLongestSeq(int n, vector<int>& seq){
    vector<int> dp(n, 1);
    int max_length = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(seq[i] > seq[j]){
               dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
        max_length = max(dp[i], max_length);
        
    }

    return max_length;

}

int main(){

    int n;
    cin >> n;
    
    vector<int> seq(n);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        seq[i]=num;
    }

    int res = findLongestSeq(n, seq);
    cout << res;

    return 0;
}