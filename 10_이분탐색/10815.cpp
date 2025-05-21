#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int binarySearch(int left, int right, vector<int>& cards, int target){
    
    while (left <= right)
    {
        int mid_index = (left + right)/2;
        int mid = cards[mid_index];
        if(mid == target){ return 1; }
        else if(mid > target) { right = mid_index - 1; }
        else { left = mid_index + 1; }
    }

    return 0;
    
}

int main(){

    cin >> n;
    vector<int> cards(n);
    for(int i=0; i<n; i++){
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());

    cin >> m;
    vector<int> q(m);
    for(int i=0; i<m; i++){
        cin >> q[i];
    }

    for(int i=0; i<m; i++){
        cout << binarySearch(0, n-1, cards, q[i]) << " ";
    }


    return 0;
}