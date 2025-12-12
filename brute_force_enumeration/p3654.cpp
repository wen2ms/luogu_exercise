#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int rows_count;
    int cols_count;
    int num_of_people;
    std::cin >> rows_count >> cols_count >> num_of_people;
    std::vector<std::vector<char>> grid(rows_count, std::vector<char>(cols_count));
    for (std::vector<char>& row : grid) {
        for (char& letter : row) {
            std::cin >> letter;
        }
    }
    int permutations_count = 0;
    for (int i = 0; i < rows_count; ++i) {
        for (int j = 0; j < cols_count; ++j) {
            bool valid = true;
            for (int k = 0; k < num_of_people; ++k) {
                if (j + k >= cols_count || grid[i][j + k] == '#') {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ++permutations_count;
            }
            valid = true;
            for (int k = 0; k < num_of_people; ++k) {
                if (i + k >= rows_count || grid[i + k][j] == '#') {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ++permutations_count;
            }
        }
    }
    std::cout << (num_of_people == 1 ? permutations_count / 2 : permutations_count) << '\n';

    return 0;
}