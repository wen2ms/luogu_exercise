#include <cctype>
#include <iostream>
#include <string>

std::string decode(int& pos, const std::string& encoded) {
    std::string result;
    int len = encoded.length();
    while (pos < len && encoded[pos] != ']') {
        if (encoded[pos] == '[') {
            int num = 0;
            ++pos;
            while (pos < len && std::isdigit(encoded[pos]) != 0) {
                num = num * 10 + encoded[pos] - '0';
                ++pos;
            }
            std::string temp = decode(pos, encoded);
            ++pos;
            while (num > 0) {
                result += temp;
                --num;
            }
        } else {
            result += encoded[pos];
            ++pos;
        }
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string encoded;
    std::cin >> encoded;

    int pos = 0;
    std::cout << decode(pos, encoded) << '\n';

    return 0;
}