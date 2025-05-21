#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;

bool is_possible(int target, vector<int>& cookies){
    
    int count = 0;
    for(int i=0; i<n; i++){
        count += cookies[i] / target;
    }
    if(count >= m) { return true; }
    else{ return false; }
}

int binarySearch(int left, int right, vector<int>& cookies){

    int max_length = 0;

    while(left <= right){
        int mid = (left + right) / 2;

        if(is_possible(mid, cookies)){ 
            max_length = mid;
            left = mid + 1; 
        }
        else{ right = mid - 1; }
    }

    return max_length;
}

int main(){

    cin >> m >> n;
    vector<int> cookies(n);

    for(int i=0; i<n; i++){
        cin >> cookies[i];
    }

    sort(cookies.begin(), cookies.end());

    cout << binarySearch(1, cookies[n-1], cookies);

    return 0;
}