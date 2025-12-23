#include <algorithm>
#include <iostream>
#include <vector>

std::string add(const std::string& str1, const std::string& str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    int index1 = len1 - 1;
    int index2 = len2 - 1;
    std::string result;
    int carry = 0;
    while (index1 >= 0 || index2 >= 0 || carry > 0) {
        int digit1 = (index1 >= 0 ? str1[index1] - '0' : 0);
        int digit2 = (index2 >= 0 ? str2[index2] - '0' : 0);
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

    int start;
    int end;
    std::cin >> start >> end;

    int count = end - start;
    std::vector<std::string> methods(count + 1);
    methods[1] = "1";
    methods[2] = "2";
    for (int i = 3; i <= count; ++i) {
        methods[i] = add(methods[i - 1], methods[i - 2]);
    }
    std::cout << methods[count] << '\n';

    return 0;
}