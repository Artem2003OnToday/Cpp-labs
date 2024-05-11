#pragma once

#include <istream>
#include <vector>

namespace lab_3 {

class Exception {
public:
    Exception(const std::string& message);
    virtual std::string what() const;
private:
    std::string message_;
};

class PopWhenEmpty : public Exception {
public:
    PopWhenEmpty(const std::string& message);
};
class SizeMoreCapacity : public Exception {
public:
    SizeMoreCapacity(const std::string& message);
};

class Stack {
public:
    Stack(): cap_(100), stack_() {}
    void add(int x);
    int pop();
    size_t size();
    int back();
private:
    size_t cap_;
    std::vector<int> stack_;
};

std::ostream& operator<< (std::ostream& os, const Stack& stack);
std::istream& operator>> (std::istream& in, const Stack& stack);

}  // namespace lab_3
