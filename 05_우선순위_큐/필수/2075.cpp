#include <iostream>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    cin >> n;

    for(int i=0; i<n; i++){
        for(int k=0; k<n; k++){
            int num;
            cin >> num;

            min_heap.push(num);
            if(min_heap.size() > n){
                min_heap.pop();
            }
        }
    }

    cout << min_heap.top();


    return 0;
}