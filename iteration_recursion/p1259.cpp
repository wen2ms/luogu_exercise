#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string str = std::string(n, 'o') + std::string(n, '*') + "--";
    std::cout << str << '\n';
    std::vector<std::string> lasts{"ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};
    std::string suffix;
    for (int i = 0; i < n - 4; ++i) {
        suffix += "o*";
    }
    while (n >= 4) {
        std::swap(str[n - 1], str[2 * n]);
        std::swap(str[n], str[2 * n + 1]);
        std::cout << str << '\n';
        --n;
        if (n == 3) {
            break;
        }
        std::swap(str[n], str[2 * n]);
        std::swap(str[n + 1], str[2 * n + 1]);
        std::cout << str << '\n';
    }
    for (const std::string& last : lasts) {
        std::cout << last << suffix << '\n';
    }

    return 0;
}