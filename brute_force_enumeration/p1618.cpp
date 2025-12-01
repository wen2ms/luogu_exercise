#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int first;
    int second;
    int third;
    std::cin >> first >> second >> third;
    bool has_answers = false;
    for (int i = 1; i <= 1000 / third; ++i) {
        std::vector<int> digits(10);
        int num1 = i * first;
        int num2 = i * second;
        int num3 = i * third;
        if (num2 >= 1000 || num3 >= 1000) {
            break;
        }
        for (int j = 0; j < 3; ++j) {
            ++digits[num1 % 10];
            num1 /= 10;
        }
        for (int j = 0; j < 3; ++j) {
            ++digits[num2 % 10];
            num2 /= 10;
        }
        for (int j = 0; j < 3; ++j) {
            ++digits[num3 % 10];
            num3 /= 10;
        }
        bool is_valid = true;
        for (int i = 1; i < 10; ++i) {
            if (digits[i] != 1) {
                is_valid = false;
                break;
            }
        }
        if (is_valid) {
            has_answers = true;
            std::cout << i * first << ' ' << i * second << ' ' << i * third << '\n';
        }
    }
    if (!has_answers) {
        std::cout << "No!!!" << '\n';
    }

    return 0;
}