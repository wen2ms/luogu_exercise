#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string num1;
    std::string num2;
    std::cin >> num1 >> num2;
    std::string result;
    int len1 = num1.length();
    int len2 = num2.length();
    int carry = 0;
    int index1 = len1 - 1;
    int index2 = len2 - 1;
    while (index1 >= 0 || index2 >= 0 || carry > 0) {
        int digit1 = (index1 >= 0 ? num1[index1] - '0' : 0);
        int digit2 = (index2 >= 0 ? num2[index2] - '0' : 0);
        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;
        carry = sum / 10;
        result += std::to_string(digit);

        --index1;
        --index2;
    }
    std::reverse(result.begin(), result.end());

    std::cout << result << '\n';

    return 0;
}