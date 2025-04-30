#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, k;
int break_count = 0;
int level_count = 0;


void getOff(deque<pair<int, bool>>& belt_top){
    if(belt_top.back().second){
        belt_top.back().second = false;
    }
}

void moveBelt(deque<pair<int, bool>>& belt_top, deque<pair<int, bool>>& belt_bottom){
    pair<int, bool> last_top_block = belt_top.back();
    belt_top.pop_back();
    belt_bottom.push_front(last_top_block);

    pair<int, bool> last_bottom_block = belt_bottom.back();
    belt_bottom.pop_back();
    belt_top.push_front(last_bottom_block);

    getOff(belt_top);
};

void moveRobot(deque<pair<int, bool>>& belt_top){
    for(int i=n-2; i>=0; i--){
        if(belt_top[i].second && !belt_top[i+1].second && belt_top[i+1].first > 0){
            belt_top[i].second = false;
            belt_top[i+1].second = true;
            belt_top[i+1].first--;
            if(belt_top[i+1].first < 1){
                break_count++;
            }
        }
    }
    getOff(belt_top);
};

void addRobot(deque<pair<int, bool>>& belt_top){
    if(belt_top[0].first > 0){
        belt_top[0].second = true;
        belt_top[0].first--;
        if(belt_top[0].first < 1){
            break_count++;
        }
    }
};


int simulate(deque<pair<int, bool>>& belt_top, deque<pair<int, bool>>& belt_bottom){
    while(true){
        level_count++;
        moveBelt(belt_top, belt_bottom);
        moveRobot(belt_top);
        addRobot(belt_top);
        if(break_count >= k){
            return level_count;
        }
    }
}

int main(){

    cin >> n >> k;

    deque<pair<int, bool>> belt_top;
    deque<pair<int, bool>> belt_bottom;
    
    for(int i=0; i<n; i++){
        int dur;
        cin >> dur;
        belt_top.push_back({dur, false});
    }
    for(int i=0; i<n; i++){
        int dur;
        cin >> dur;
        belt_bottom.push_back({dur, false});
    }

    int res = simulate(belt_top, belt_bottom);
    cout << res;

    return 0;
}