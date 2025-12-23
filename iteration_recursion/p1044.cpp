#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nums_count;
    std::cin >> nums_count;
    std::vector<std::vector<int>> methods(nums_count + 1, std::vector<int>(nums_count + 1));
    for (int i = 0; i <= nums_count; ++i) {
        methods[0][i] = 1;
    }
    for (int i = 1; i <= nums_count; ++i) {
        methods[i][0] = methods[i - 1][1];
        for (int j = 1; j <= nums_count; ++j) {
            methods[i][j] = methods[i - 1][j + 1] + methods[i][j - 1];
        }
    }
    std::cout << methods[nums_count][0] << '\n';

    return 0;
}