#include <iostream>

#include "include/lab_1.hpp"

namespace lab_1 {

int main() {
    int a, b;
    std::cin >> a >> b;

    std::cout << "Input variables: a = " << a << ", b = " << b << std::endl;
    swap(a, b);

    std::cout << a << ", " << b << std::endl;
    return 0;
}

}  // namespace lab_1
