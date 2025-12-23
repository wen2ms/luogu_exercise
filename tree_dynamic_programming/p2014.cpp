#include <algorithm>
#include <iostream>
#include <vector>

void dfs(int curr, std::vector<std::vector<int>>& maximum_scores, const std::vector<std::vector<int>>& adjacent,
         const std::vector<int>& scores, std::vector<int>& counts, const int num_of_selections) {
    maximum_scores[curr][0] = 0;
    maximum_scores[curr][1] = scores[curr];
    counts[curr] = 1;
    int num_of_children = adjacent[curr].size();
    for (int child : adjacent[curr]) {
        dfs(child, maximum_scores, adjacent, scores, counts, num_of_selections);
        for (int j = std::min(counts[curr], num_of_selections + 1); j >= 0; --j) {
            for (int k = std::min(counts[child], num_of_selections + 1 - j); k >= 0; --k) {
                if (k == 0 || j > 0) {
                    maximum_scores[curr][j + k] =
                        std::max(maximum_scores[curr][j + k], maximum_scores[curr][j] + maximum_scores[child][k]);
                }
            }
        }
        counts[curr] += counts[child];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_of_vertex;
    int num_of_selections;
    std::cin >> num_of_vertex >> num_of_selections;
    std::vector<std::vector<int>> adjacent(num_of_vertex + 1);
    std::vector<int> scores(num_of_vertex + 1);
    for (int i = 1; i <= num_of_vertex; ++i) {
        int start;
        std::cin >> start >> scores[i];
        adjacent[start].push_back(i);
    }
    std::vector<std::vector<int>> maximum_scores(num_of_vertex + 1, std::vector<int>(num_of_selections + 2));
    std::vector<int> counts(num_of_vertex + 1);
    dfs(0, maximum_scores, adjacent, scores, counts, num_of_selections);
    std::cout << maximum_scores[0][num_of_selections + 1] << '\n';

    return 0;
}