#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxLength(const vector<int>& nums, int N, int K) {
    vector<int> count(100001, 0);
    int left = 0, right = 0;
    int max_length = 0;

    while (right < N) {
        count[nums[right]]++;

        while (count[nums[right]] > K) {
            count[nums[left]]--;
            left++;
        }

        max_length = max(max_length, right - left + 1);
        right++;
    }

    return max_length;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int result = findMaxLength(nums, N, K);
    cout << result;

    return 0;
}
