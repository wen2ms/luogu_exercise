#include <cstdlib>
#include <iostream>

int main() {
    int nums_count;
    std::cin >> nums_count;
    for (int i = nums_count; i >= 0; --i) {
        int num;
        std::cin >> num;
        if (num != 0) {
            if (i < nums_count && num > 0) {
                std::cout << '+';
            }
            if (std::abs(num) > 1 || i == 0) {
                std::cout << num;
            }
            if (num == -1 && i > 0) {
                std::cout << '-';
            }
            if (i > 0) {
                std::cout << 'x';
            }
            if (i > 1) {
                std::cout << '^' << i;
            }
        }
    }
    std::cout << '\n';

    return 0;
}