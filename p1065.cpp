#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int num_of_machines;
    int num_of_items;
    std::cin >> num_of_machines >> num_of_items;
    std::vector<int> order(num_of_machines * num_of_items);
    for (int& item : order) {
        std::cin >> item;
    }
    std::vector<std::vector<std::pair<int, int>>> table(num_of_items + 1, std::vector<std::pair<int, int>>(num_of_machines + 1));
    for (int i = 1; i <= num_of_items; ++i) {
        for (int j = 1; j <= num_of_machines; ++j) {
            std::cin >> table[i][j].first;
        }
    }
    for (int i = 1; i <= num_of_items; ++i) {
        for (int j = 1; j <= num_of_machines; ++j) {
            std::cin >> table[i][j].second;
        }
    }
    int result = 0;
    std::vector<int> last_times(num_of_items + 1);
    std::vector<int> curr_steps(num_of_items + 1);
    std::vector<std::vector<bool>> occupied(num_of_machines + 1, std::vector<bool>(1000000));
    for (const int item : order) {
        ++curr_steps[item];
        const auto& [machine, cost] = table[item][curr_steps[item]];
        int segment = 0;
        int start = last_times[item] + 1;
        while (segment < cost) {
            if (occupied[machine][start]) {
                segment = 0;
            } else {
                ++segment;
            }
            ++start;
        }
        for (int i = start - cost; i < start; ++i) {
            occupied[machine][i] = true;
        }
        result = std::max(result, start - 1);
        last_times[item] = start - 1;
    }
    std::cout << result << '\n';

    return 0;
}