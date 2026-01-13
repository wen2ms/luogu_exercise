#include <cstdint>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    int64_t pos;
    std::cin >> str >> pos;
    int len = str.length();
    while (len < pos) {
        int64_t curr = len;
        while (curr < pos) {
            curr *= 2;
        }
        curr /= 2;
        pos -= curr + 1;
        if (pos == 0) {
            pos = curr;
        }
    }
    std::cout << str[pos - 1] << '\n';

    return 0;
}