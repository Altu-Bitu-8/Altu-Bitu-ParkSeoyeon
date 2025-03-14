#include <iostream>
#include <vector>

using namespace std;

int getGCD(int a, int b){
    int tmp;
    while(b!=0){
        tmp = a % b;
        a=b;
        b=tmp;
    }

    return a;
}

void getMaxD(const vector<int>& l){
    int result = l[0];
    for(int i=1; i<l.size(); i++){
        result=getGCD(result, l[i]);
    }
    cout << result;
}

int main(){

    int n, s;
    cin >> n >> s;
    
    vector<int> location(n);
    
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        temp -= s;
        if(temp<0) temp = -temp;
        location[i] = temp;
    }

    getMaxD(location);


    return 0;
}