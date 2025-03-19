#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int add(int set, int num){
    set = set | (1 << num);
    return set;
}

int remove(int set, int num){
    set = set & ~(1 << num);
    return set;
}

void check(int set, int num){
    if((set & (1<<num)) > 0){
        cout << 1 << '\n';
    }
    else{
        cout << 0 << '\n';
    }
}

int toggle(int set, int num){
    if((set & (1<<num)) > 0){
        set = remove(set, num);
    }
    else{
        set = add(set, num);
    }

    return set;
}


int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int M;
    cin >> M;

    int set = 0;

    for(int i=0; i<M; i++){
        string calc;
        int num;
        cin >> calc;

        if(calc == "add"){
            cin >> num;
            set = add(set, num-1);
        }
        else if(calc == "remove"){
            cin >> num;
            set = remove(set, num-1);
        }
        else if(calc == "check"){
            cin >> num;
            check(set, num-1);
        }
        else if(calc == "toggle"){
            cin >> num;
            set = toggle(set, num-1);
        }
        else if(calc == "all"){
            set = 1048575; // 2의 20승 - 1
        }
        else if(calc == "empty"){
            set = 0;
        }
    }

    return 0;
}