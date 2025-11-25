#include <iostream>
#include <vector>

int main() {
    int nums_count;
    std::cin >> nums_count;
    std::vector<int> counts(1001);
    int num_of_uniques = 0;
    for (int i = 0; i < nums_count; ++i) {
        int num;
        std::cin >> num;
        ++counts[num];
        if (counts[num] == 1) {
            ++num_of_uniques;
        }
    }
    std::cout << num_of_uniques << '\n';
    for (int i = 1; i < 1001; ++i) {
        if (counts[i] > 0) {
            std::cout << i << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}