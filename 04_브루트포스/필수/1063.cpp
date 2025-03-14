#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

pair<char,int> move(pair<char, int> location, string move_data){
    if(move_data.find("R") != string::npos){
        location.first++;
    }
    if(move_data.find("L") != string::npos){
        location.first--;
    }
    if(move_data.find("B") != string::npos){
        location.second--;
    }
    if(move_data.find("T") != string::npos){
        location.second++;
    }

    if(location.first > 72 || location.first < 65){
        location.first = 'Z';
    }
    if(location.second > 8 || location.second < 1){
        location.second = 0;
    }
    return location;
}


void findFinalLocation(pair<char, int>& king_location, pair<char, int>& stone_location, queue<string>& info){

    while(!info.empty()){
        string data = info.front();
        info.pop();
        pair<char, int> king_temp = king_location;
        pair<char, int> stone_temp = stone_location;

        king_temp = move(king_location, data);
        if(king_temp.first == stone_temp.first && king_temp.second == stone_temp.second){
            stone_temp = move(stone_temp, data);
        }

        if(king_temp.first == 'Z' || stone_temp.first == 'Z' || king_temp.second == 0 || stone_temp.second == 0){
            continue;
        }
        king_location = king_temp;
        stone_location = stone_temp;

    }

}

int main(){

    string king, stone;
    int num;
    queue<string> info;

    cin >> king >> stone >> num;

    pair<char, int> king_location(king[0], king[1] - '0');
    pair<char, int> stone_location(stone[0], stone[1] - '0');

    for(int i=0; i<num; i++){
        string data;
        cin >> data;
        info.push(data);
    }

    findFinalLocation(king_location, stone_location, info);

    cout << king_location.first << king_location.second << "\n" << stone_location.first << stone_location.second;

    return 0;
}