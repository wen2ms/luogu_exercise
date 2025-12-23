#include <algorithm>
#include <iostream>
#include <string>

std::string add(const std::string& num1, const std::string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    int index1 = len1 - 1;
    int index2 = len2 - 1;
    std::string result;
    int carry = 0;
    while (index1 >= 0 || index2 >= 0 || carry > 0) {
        int digit1 = (index1 >= 0 ? num1[index1] - '0' : 0);
        int digit2 = (index2 >= 0 ? num2[index2] - '0' : 0);
        int sum = digit1 + digit2 + carry;
        result += std::to_string(sum % 10);
        carry = sum / 10;
        --index1;
        --index2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_of_stairs;
    std::cin >> num_of_stairs;
    std::string prev = "1";
    std::string curr = "1";
    for (int i = 0; i < num_of_stairs; ++i) {
        std::string temp = prev;
        prev = curr;
        curr = add(curr, temp);
    }
    std::cout << prev << '\n';

    return 0;
}