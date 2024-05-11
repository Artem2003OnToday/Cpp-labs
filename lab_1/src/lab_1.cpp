#include "../include/lab_1.hpp"

namespace lab_1 {

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

}  // namespace lab_1
