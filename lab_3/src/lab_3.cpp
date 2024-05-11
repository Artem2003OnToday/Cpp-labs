#include "../include/lab_3.hpp"

#include <iostream>

namespace lab_3 {

Exception::Exception(const std::string& message): message_(message) {
}

std::string Exception::what() const {
    return message_;
}

PopWhenEmpty::PopWhenEmpty(const std::string& message): Exception(message) {
}

SizeMoreCapacity::SizeMoreCapacity(const std::string& message): Exception(message) {
}

void Stack::add(int x) {
    if (stack_.size() > cap_) {
        throw SizeMoreCapacity("size cannot be more, than capacity = 100");
    }
    stack_.push_back(x);
}

int Stack::pop() {
    if (stack_.empty()) {
        throw PopWhenEmpty("cannot pop empty stack");
    }

    int x = stack_.back();
    stack_.pop_back();
    return x;
}

size_t Stack::size() {
    return stack_.size();
}

int Stack::back() {
    return stack_.back();
}

std::ostream& operator<< (std::ostream& os, Stack& stack) {
    return os << stack.pop();
}

std::istream& operator>> (std::istream& in, Stack& stack) {
    int x;
    in >> x;
    stack.add(x);

    return in;
}

}  // namespace lab_3
