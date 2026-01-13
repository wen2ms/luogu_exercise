#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num;
    std::cin >> num;
    std::vector<int> total(num + 1);
    std::vector<int> gap(num + 1);
    const int mod = 10000;
    total[0] = 1;
    total[1] = 1;
    gap[1] = 1;
    for (int i = 2; i <= num; ++i) {
        total[i] = ((total[i - 1] + total[i - 2]) % mod + 2 * gap[i - 2] % mod) % mod;
        gap[i] = (gap[i - 1] + total[i - 1]) % mod;
    }
    std::cout << total[num] << '\n';

    return 0;
}