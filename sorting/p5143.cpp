#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
    int z;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_of_points;
    std::cin >> num_of_points;
    std::vector<Point> points(num_of_points);
    for (Point& point : points) {
        std::cin >> point.x >> point.y >> point.z;
    }
    std::sort(points.begin(), points.end(), [](const Point& left, const Point& right) { return left.z < right.z; });
    double total_distance = 0;
    for (int i = 1; i < num_of_points; ++i) {
        int diff_x = (points[i].x - points[i - 1].x) * (points[i].x - points[i - 1].x);
        int diff_y = (points[i].y - points[i - 1].y) * (points[i].y - points[i - 1].y);
        int diff_z = (points[i].z - points[i - 1].z) * (points[i].z - points[i - 1].z);
        total_distance += std::sqrt(diff_x + diff_y + diff_z);
    }
    std::cout << std::fixed << std::setprecision(3) << total_distance << '\n';

    return 0;
}