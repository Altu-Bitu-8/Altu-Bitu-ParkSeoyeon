#include <iostream>
#include <vector>

using namespace std;

int N, M;
int cleaned = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void cleanRoom(int r, int c, int d, vector<vector<int>>& room) {
    while (true) {

        if (room[r][c] == 0) {
            room[r][c] = 2; 
            cleaned++;
        }

        bool unclean = false;

        for (int i = 0; i < 4; ++i) {
            d = (d + 3) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];

            if (room[nx][ny] == 0) {
                r = nx;
                c = ny;
                unclean = true;
                break;
            }
        }

        if (unclean) continue;

        int back = (d + 2) % 4;
        int bx = r + dx[back];
        int by = c + dy[back];

        if (room[bx][by] == 1) break; 
        r = bx;
        c = by;
    }
}

int main() {
    int r, c, d;
    cin >> N >> M;
    cin >> r >> c >> d;

    vector<vector<int>> room(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> room[i][j];

    cleanRoom(r, c, d, room);

    cout << cleaned;
    return 0;
}

