#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nums_count;
    int money;
    std::cin >> nums_count >> money;
    std::vector<int> nums(nums_count);
    for (int& num : nums) {
        std::cin >> num;
    }
    std::vector<int> methods(money + 1);
    methods[0] = 1;
    for (int num : nums) {
        for (int i = money; i >= num; --i) {
            methods[i] += methods[i - num];
        }
    }
    std::cout << methods[money] << '\n';

    return 0;
}