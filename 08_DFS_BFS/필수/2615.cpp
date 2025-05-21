#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> omok(19, vector<int>(19));
vector<int> dx = {0,1,1,-1};
vector<int> dy = {1,0,1,1};

bool isLocationValid(int x, int y){
    return x>=0 && x<19 && y>=0 && y<19;
}

bool checkOmok(int x, int y, int d){
    int num = omok[x][y];
    int count = 1;
    int next_x = x + dx[d];
    int next_y = y + dy[d];

    while(isLocationValid(next_x, next_y) && omok[next_x][next_y] == num){
        count++;
        next_x += dx[d];
        next_y += dy[d];
    }

    if(count != 5) return false;

    int previous_x = x - dx[d];
    int previous_y = y - dy[d];
    if(isLocationValid(previous_x, previous_y) && omok[previous_x][previous_y] == num){
        return false;
    }
    if (isLocationValid(next_x, next_y) && omok[next_x][next_y] == num) {
        return false;
    }

    return true;
}

int judgeResult(const vector<vector<int>>& omok, pair<int, int>& location){
    
    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            if(omok[i][j] != 0){
                for(int d=0; d<4; d++){
                    if(checkOmok(i,j,d)){
                        location.first = i+1;
                        location.second = j+1;
                        return omok[i][j];
                    }
                }
            }
        }
    }

    return 0;
}

int main(){

    pair<int, int> location;

    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            cin >> omok[i][j];
        }
    }

    int result = judgeResult(omok, location);
    cout << result << '\n';
    if(result != 0){
        cout << location.first << ' ' << location.second;
    }

    return 0;
}