#include <iostream>
#include <string>

using namespace std;

void addBigNumber(string s1, string s2){

    int len1 = s1.length();
    int len2 = s2.length();
    int length = max(len1, len2);
    string result(length, '0');

    int carry = 0;
    for(int i=0; i<length; i++){
        int sum = carry;
        if(i<len1) sum += (s1[len1 - 1 - i] - '0');
        if(i<len2) sum += (s2[len2 - 1 - i] - '0');
        result[length -1 -i] = (sum % 10) + '0';
        carry = sum/10;
    }

    if(carry) result = "1" + result;
    
    cout << result;
}

int main(){
    
    string num1, num2;
    cin >> num1;
    cin >> num2;

    addBigNumber(num1, num2);

    return 0;
}