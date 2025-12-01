#include <iostream>
#include <vector>

int nums_count;
int num_of_selection;

bool is_prime(int num) {
    if (num == 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void backtrack(int index, int count, int sum, int& total_combinations, const std::vector<int>& nums) {
    if (count == num_of_selection) {
        if (is_prime(sum)) {
            ++total_combinations;
        }
        return;
    }
    for (int i = index; i < nums_count; ++i) {
        backtrack(i + 1, count + 1, sum + nums[i], total_combinations, nums);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> nums_count >> num_of_selection;
    std::vector<int> nums(nums_count);
    for (int& num : nums) {
        std::cin >> num;
    }
    int total_combinations = 0;
    backtrack(0, 0, 0, total_combinations, nums);
    std::cout << total_combinations << '\n';

    return 0;
}