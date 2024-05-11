#include <vector>

#include "include/lab_7.hpp"
#include "doctest.h"

TEST_CASE("mini test") {
    lab_7::CircularBuffer<int> buffer(15);
    std::vector<int> v;
    for (int i = 1; i < 10; i++) {
        buffer.push_back(i);
        v.push_back(i);
    }

    buffer[4] = 12;
    v[4] = 12;
    buffer.change_capacity(10);

    for (int i = 0; i < 9; i++) {
        CHECK(buffer[i] == v[i]);
    }

    buffer[4] = 5;

    buffer.pop_back();
    buffer.pop_back();
    buffer.pop_front();
    buffer.pop_front();

    for (int i = 0; i < 6; i++) {
        CHECK(buffer[i] == i + 3);
    }

    buffer[4] = 8;
    buffer.remove_from_position(buffer.begin() + 4);
    buffer[4] = 9;

    buffer.insert_at_position(buffer.begin() + 4, 8);
    buffer[4] = 8;
}
