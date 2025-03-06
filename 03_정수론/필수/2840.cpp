#include <iostream>
#include <vector>

using namespace std;

struct wheelData {
    int num;
    char c;
};

bool isDuplicated(const vector<char>& used, char item){
    for(int j=0; j<used.size(); j++){
        if(used[j] == item){
            return true;
        }
    }
    return false;
}

void findAlphabet(int n, const vector<wheelData>& d){
    vector<char> wheel(n, '?');
    vector<char> used;
    int index = 0;
    for(int i=0; i<d.size(); i++){
        index = (index + d[i].num) % n;
       
        if(wheel[index] != '?' && wheel[index] != d[i].c){
            cout << '!'; 
            return;
        }
        if(isDuplicated(used, d[i].c) && wheel[index] != d[i].c){
            cout << '!'; 
            return;
        }
        else{
            wheel[index] = d[i].c;
            used.push_back(d[i].c);
        }
    }

    for(int i=index; i>index-n; i--){
        int temp_index = i;
        if(temp_index < 0) temp_index += n;
        cout << wheel[temp_index];
    }
}

int main(){
    
    int n,k;
    cin >> n >> k;

    vector<wheelData> wheel_datas(k);
    for(int i=0; i<k; i++){
      cin >> wheel_datas[i].num >> wheel_datas[i].c;   
    }

    findAlphabet(n, wheel_datas);

    return 0;
}