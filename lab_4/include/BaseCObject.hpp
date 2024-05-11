#pragma once

namespace lab_4 {

class BaseCObject {
public:
    virtual const char *classname() = 0;
    virtual unsigned int size() const = 0;
};

}  // namespace lab_4
