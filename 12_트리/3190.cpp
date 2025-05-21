#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<pair<int, char>> dir;

char switchDirection(char direction, int time) {
    static vector<char> dirs = {'u', 'r', 'd', 'l'};

    for (int i = 0; i < dir.size(); i++) {
        if (time == dir[i].first) { 
            char turn = dir[i].second;
            int idx = 0;

            for (int j = 0; j < 4; j++) {
                if (dirs[j] == direction) {
                    idx = j;
                    break;
                }
            }

            if (turn == 'L') {
                idx = (idx + 3) % 4;
            } else if (turn == 'D') {
                idx = (idx + 1) % 4;
            }

            return dirs[idx];
        }
    }

    return direction;
}

int simulate(queue<pair<int, int>>& snake, char direction, int time) {

    pair<int, int> head = snake.back();
    pair<int, int> next_pos = head;

    switch (direction) {
        case 'u':
            next_pos.second--;
            break;
        case 'd':
            next_pos.second++;
            break;
        case 'r':
            next_pos.first++;
            break;
        case 'l':
            next_pos.first--;
            break;
    }

    if (next_pos.first < 0 || next_pos.first >= board[0].size() ||
        next_pos.second < 0 || next_pos.second >= board.size()) {
        return time + 1;
    }

    int y = next_pos.second;
    int x = next_pos.first;

    switch (board[y][x]) {
        case 0: { // 빈칸
            pair<int, int> tail = snake.front();
            snake.pop();
            board[tail.second][tail.first] = 0;

            snake.push(next_pos);
            board[y][x] = 2;
            break;
        }
        case 1: // 사과
            snake.push(next_pos);
            board[y][x] = 2;
            break;
        case 2: // 뱀
            return time + 1;
    }

    time++;

    char next_dir = switchDirection(direction, time);
    return simulate(snake, next_dir, time);
}

int main() {
    int n, k;
    cin >> n >> k;

    board.resize(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        board[row - 1][col - 1] = 1;
    }
    board[0][0] = 2;

    int l;
    cin >> l;

    dir.resize(l);
    for (int i = 0; i < l; i++) {
        int t;
        char d;
        cin >> t >> d;
        dir[i] = {t, d};
    }

    queue<pair<int, int>> snake;
    snake.push({0, 0});

    int result = simulate(snake, 'r', 0);
    cout << result << "\n";

    return 0;
}
