#include <iostream>

void traverse(int num) {
    int bitlen = 0;
    int temp = num;
    while (temp > 0) {
        ++bitlen;
        temp >>= 1;
    }
    for (int i = bitlen - 1; i >= 0; --i) {
        if ((num & (1 << i)) > 0) {
            if (i < bitlen - 1) {
                std::cout << "+";
            }
            if (i == 1) {
                std::cout << 2;
            } else if (i == 0) {
                std::cout << "2(0)";
            } else {
                std::cout << "2(";
                traverse(i);
                std::cout << ")";
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num;
    std::cin >> num;
    traverse(num);

    return 0;
}