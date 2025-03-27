#include <iostream>
#include <vector>

using namespace std;

void rotateClockwise(vector<int>& wheel){
    int last = wheel[7];
    wheel.pop_back();
    wheel.emplace(wheel.begin(), last);
}

void rotateCounterClockwise(vector<int> &wheel){
    int first = wheel[0];
    wheel.erase(wheel.begin());
    wheel.emplace_back(first);
}

int findWheelDirection(int t, vector<vector<int>>& wheels, int k, vector<pair<int, int>>& info){

    for(int i=0; i<k; i++){
        pair<int, int> turn_info = info[i];
        int standard_wheel = turn_info.first - 1;
        int direction = turn_info.second;

        vector<int> directions(t, 0);
        directions[standard_wheel] = direction;

        //돌아가는 바퀴 찾기
        for(int j=standard_wheel; j>0; j--){
            if(wheels[j][6] != wheels[j-1][2]){
                directions[j-1] = -directions[j];
            }else{
                break;
            }
        }

        for(int j=standard_wheel; j<t-1; j++){
            if(wheels[j][2] != wheels[j+1][6]){
                directions[j+1] = -directions[j];
            }else{
                break;
            }
        }

        

        //바퀴 돌리기
        for(int j=0; j<t; j++){
            if(directions[j] == 1){
                rotateClockwise(wheels[j]);
            }else if(directions[j] == -1){
                rotateCounterClockwise(wheels[j]);
            }
        }

    }

    int count = 0;
    for(int i=0; i<t; i++){
        if(wheels[i][0] == 1){
            count++;
        }
    }

    return count;

}

int main(){

    int t;
    std::cin >> t;

    vector<vector<int>> wheels(t, vector<int>(8));
    for(int i=0; i<t; i++){
        string s;
        std::cin >> s;
        for(int j=0; j<8; j++){
            wheels[i][j] = s[j] - '0';
        }
    }

    int k;
    std::cin >> k;
    vector<pair<int, int>> info(k);
    for(int i=0; i<k; i++){
        int wheel_num, dir;
        std::cin >> wheel_num >> dir;
        info[i].first = wheel_num;
        info[i].second = dir;
    }

    int final_s_num;

    final_s_num = findWheelDirection(t, wheels, k, info);

    std::cout << final_s_num;

    return 0;
}