#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int total;
    std::cin >> total;
    std::vector<int> digit_counts{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    std::vector<int> num_counts(2000);
    num_counts[0] = digit_counts[0];
    for (int i = 1; i < 2000; ++i) {
        int num = i;
        while (num > 0) {
            num_counts[i] += digit_counts[num % 10];
            num /= 10;
        }
    }
    int num_of_combinations = 0;
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            if (num_counts[i] + num_counts[j] + num_counts[i + j] + 4 == total) {
                ++num_of_combinations;
            }
        }
    }
    std::cout << num_of_combinations << '\n';

    return 0;
}