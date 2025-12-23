#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num;
    std::cin >> num;
    std::vector<int> counts(num + 1);
    counts[0] = 1;
    for (int i = 1; i <= num; ++i) {
        for (int j = 0; j <= i / 2; ++j) {
            counts[i] += counts[j];
        }
    }
    std::cout << counts[num] << '\n';

    return 0;
}