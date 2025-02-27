#include <iostream>
#include <stack>
#include <string>

using namespace std;

void checkHarmony(string sentence){
    stack<char> s;

    for(int i=0; i<sentence.length(); i++){
        if(sentence[i] == '('){
            s.push(sentence[i]);
        }else if(sentence[i] == ')'){
            if(!s.empty() && s.top() == '('){
                s.pop();
            }else{
                cout << "no\n";
                return;
            }
        }else if(sentence[i] == '['){
            s.push(sentence[i]);
        }else if(sentence[i] == ']'){
            if(!s.empty() && s.top() == '['){
                s.pop();
            }else{
                cout << "no\n";
                return;
            }
        }else if(sentence[i] == '.'){
            break;
        }
    }
    if(!s.empty()){
        cout << "no\n";
    }else{
        cout << "yes\n";
    }

}

int main(){


    string sentence;

    while(getline(cin, sentence) && sentence != "."){
        if (sentence.empty()) continue; // 빈 문자열 예외 처리
        checkHarmony(sentence);
    }


    return 0;
}