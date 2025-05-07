#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

bool is_lighted(int height, vector<int>& lights){
    
    int prev_right = 0;

    for(int i=0; i<m; i++){
        int left = lights[i] - height;
        int right = lights[i] + height;

        if(prev_right < left){
            return false;
        }
        prev_right = right;
    }

    return prev_right >= n;
}

int binarySearch(int left, int right, vector<int>& lights){
    
    int answer = n;

    while(left <= right){
        int mid = (left + right) / 2;
        if(is_lighted(mid, lights)){
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

int main(){


    cin >> n >> m;

    vector<int> lights(m,0);
    for(int i=0; i<m; i++){
        cin >> lights[i];
    }

    sort(lights.begin(), lights.end());

    cout << binarySearch(1, n, lights);

    return 0;
}