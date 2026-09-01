#pragma once

#include <array>

constexpr int STUDENT_COUNT = 6;
constexpr int ASSIGNMENT_COUNT = 5;

double studentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex);

double classAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores);

double assignmentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int assignmentIndex);
