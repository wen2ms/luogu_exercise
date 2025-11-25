#include <iostream>
#include <vector>

int main() {
    int maximum;
    int nums_count;
    std::cin >> maximum >> nums_count;
    std::vector<int> counts(maximum + 1);
    for (int i = 0; i < nums_count; ++i) {
        int num;
        std::cin >> num;
        ++counts[num];
    }
    for (int i = 1; i <= maximum; ++i) {
        if (counts[i] > 0) {
            for (int j = 0; j < counts[i]; ++j) {
                std::cout << i << ' ';
            }
        }
    }
    std::cout << '\n';

    return 0;
}