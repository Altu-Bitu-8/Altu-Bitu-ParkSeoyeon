#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSum(const string& s){
    int sum = 0;
    for(char c : s) {
        if(isdigit(c)){
            sum += c - '0';
        }
    }
    return sum;
}

bool cmp(const string& s1, const string& s2){
    if(s1.length() != s2.length()){
        return s1.length() < s2.length();
    }

    int sum1 = getSum(s1);
    int sum2 = getSum(s2);

    if(sum1 != sum2){
        return sum1 < sum2;
    }

    return s1<s2;

    
}

int main () {

    int N;
    cin >> N;

    vector <string> serial_number(N);
    for(int i=0; i<N; i++){
        cin >> serial_number[i];
    }

    sort(serial_number.begin(), serial_number.end(), cmp);

    for (const string& str : serial_number){
        cout << str << '\n';
    }

    return 0;
}