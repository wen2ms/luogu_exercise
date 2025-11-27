#include <algorithm>
#include <iostream>
#include <vector>

struct Student {
    int id;
    int score;
};

bool sort_students(const Student& left, const Student& right) {
    if (left.score == right.score) {
        return left.id < right.id;
    }
    return left.score > right.score;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_of_students;
    int num_of_pass;
    std::cin >> num_of_students >> num_of_pass;
    std::vector<Student> students(num_of_students);
    for (auto& [id, score] : students) {
        std::cin >> id >> score;
    }
    std::sort(students.begin(), students.end(), sort_students);
    int score_line = students[static_cast<int>(num_of_pass * 1.5) - 1].score;
    std::vector<Student> passed_students;
    for (const Student& student : students) {
        if (student.score < score_line) {
            break;
        }
        passed_students.push_back(student);
    }
    std::cout << score_line << ' ' << passed_students.size() << '\n';
    for (const auto& student : passed_students) {
        std::cout << student.id << ' ' << student.score << '\n';
    }

    return 0;
}