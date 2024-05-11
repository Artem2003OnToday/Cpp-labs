#pragma once

#include <string>

namespace lab_5 {

class OutOfBounds {
private:
    std::string message_;
public:
    OutOfBounds(const std::string& message): message_(message) {}
    const std::string what() { return message_; }
};

template<typename T>
const T& FindMinimumFromTwo(const T& a, const T& b) {
    return (b < a) ? b : a;
}

template<int N, typename T>
class Array {
private:
    T values[N];
public:
    T operator [](int index) const {
        if (index < 0 || N <= index) {
            throw OutOfBounds("incorrect index " + std::to_string(index) + 
                              ", should be in [0, " + std::to_string(N) + "]");
        }
        return values[index];
    }
    T& operator [](int index) {
        if (index < 0 || N <= index) {
            throw OutOfBounds("incorrect index " + std::to_string(index) + 
                              ", should be in [0, " + std::to_string(N) + "]");
        }
        return values[index];
    }
};

}  // namespace lab_5
