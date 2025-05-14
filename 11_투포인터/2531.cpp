#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxSushi(const vector<int>& sushi, int N, int d, int k, int c) {
    vector<int> count(d + 1, 0); 
    int unique = 0;

    for (int i = 0; i < k; ++i) {
        if (count[sushi[i]] == 0) unique++;
        count[sushi[i]]++;
    }

    int max_sushi = unique + (count[c] == 0 ? 1 : 0);

    for (int i = 1; i < N; ++i) {
        int out = sushi[i - 1];
        int in = sushi[(i + k - 1) % N];

        count[out]--;
        if (count[out] == 0) unique--;

        if (count[in] == 0) unique++;
        count[in]++;

        int current_sushi = unique + (count[c] == 0 ? 1 : 0);
        max_sushi = max(max_sushi, current_sushi);
    }

    return max_sushi;
}

int main() {
    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> sushi(N);
    for (int i = 0; i < N; ++i) {
        cin >> sushi[i];
    }

    int result = findMaxSushi(sushi, N, d, k, c);
    cout << result;

    return 0;
}