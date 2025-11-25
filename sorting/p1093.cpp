#include <algorithm>
#include <iostream>
#include <vector>

struct Student {
    int chinese = 0;
    int math = 0;
    int english = 0;
    int total = 0;
    int id = 0;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_of_students;
    std::cin >> num_of_students;
    std::vector<Student> students(num_of_students);
    for (int i = 0; i < num_of_students; ++i) {
        students[i].id = i + 1;
        std::cin >> students[i].chinese >> students[i].math >> students[i].english;
        students[i].total = students[i].chinese + students[i].math + students[i].english;
    }
    auto student_greater = [](const Student& first, const Student& second) {
        if (first.total == second.total) {
            if (first.chinese == second.chinese) {
                return first.id < second.id;
            }
            return first.chinese > second.chinese;
        }
        return first.total > second.total;
    };
    std::sort(students.begin(), students.end(), student_greater);
    for (int i = 0; i < 5; ++i) {
        std::cout << students[i].id << ' ' << students[i].total << '\n';
    }

    return 0;
}