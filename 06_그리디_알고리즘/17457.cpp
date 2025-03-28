#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        int speed;
        cin >> speed;
        v[i] = speed;
    }

    long long final_speed = v[n-1];
    for(int i=n-2; i>=0; i--){
        if(v[i] > final_speed){
            final_speed = v[i];
        } else{
            long long num = (final_speed + v[i] - 1) / v[i];
            final_speed = v[i]*num;
        }
    }

    cout << final_speed;


    return 0;
}