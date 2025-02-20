#include <iostream>
#include <set>

using namespace std;

int countSubString(const string& s){
    set<string> substrings;

    for(int i=0; i<s.length(); i++){
        for(int j=i; j<s.length(); j++){
            substrings.insert(s.substr(i,j-i+1));
        }
    }

    return substrings.size();
}

int main(){
    string s;
    cin >> s;

    int num = countSubString(s);
    cout << num;

}