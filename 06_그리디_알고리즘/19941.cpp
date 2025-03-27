#include <iostream>
#include <vector>

using namespace std;

int findMaxPeople(int n, int k, string& s){
    int count = 0;
    vector<bool> hambugee(n, true);

    for(int i=0; i<n; i++){
        if(s[i] == 'P'){
            for(int j=-k; j<=k; j++){
                if((i+j >= 0 || i+j < n ) && hambugee[i+j] == true && s[i+j] == 'H'){
                    count++;
                    hambugee[i+j] = false;
                    break;
                }
            }
        } else {
            continue;
        }
    }

    return count;
}

int main(){

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int count = findMaxPeople(n, k, s);

    cout << count;

    return 0;
}