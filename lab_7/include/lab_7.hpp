#pragma once

#include <algorithm>

namespace lab_7 {

template<typename T>
class CircularBuffer {
private:
    T* buffer;
    int capacity;
    int size;
    int start;

public:

class Iterator {
private:
    CircularBuffer& buffer;
    int idx;

public:
    Iterator(CircularBuffer& buffer, int idx) : buffer(buffer), idx(idx) {}

    bool IsSameBuffer(CircularBuffer* buffer) {
        return buffer == &this->buffer;
    }

    bool operator==(const Iterator& other) const {
        return &buffer == &other.buffer && idx == other.idx;
    }

    bool operator!=(const Iterator& other) const {
        return !(*this == other);
    }

    int get_idx() const {
        return idx;
    }

    T& operator*() const {
        return buffer[(buffer.start + idx) % buffer.capacity];
    }

    Iterator& operator++() {
        idx++;
        return *this;
    }

    Iterator& operator +(int val) {
        idx += val;
        return *this;
    }
};

CircularBuffer(int capacity) : capacity(capacity), size(0), start(0) {
    buffer = new T[capacity];
}

~CircularBuffer() {
    delete[] buffer;
}

void push_back(const T& value) {
    buffer[(start + size) % capacity] = value;
    if (size < capacity) {
        size++;
    } else {
        start = (start + 1) % capacity;
    }
}

void push_front(const T& value) {
    start = (start - 1 + capacity) % capacity;
    buffer[start] = value;
    if (size < capacity) {
        size++;
    }
}

void insert_at_position(Iterator pos, const T& value) {
    int insertIndex = ((pos.IsSameBuffer(this)) ? (pos.get_idx()) : 0);
    for (int i = size; i > insertIndex; i--) {
        buffer[(start + i) % capacity] = buffer[(start + i - 1) % capacity];
    }
    buffer[(start + insertIndex) % capacity] = value;
    if (size < capacity) {
        size++;
    } else {
        start = (start + 1) % capacity;
    }
}

void pop_back() {
    if (size > 0) size--;
}

void pop_front() {
    if (size > 0) {
        start = (start + 1) % capacity;
        size--;
    }
}

void remove_from_position(Iterator pos) {
    int removeIndex = ((pos.IsSameBuffer(this)) ? (pos.get_idx()) : 0);
    for (int i = removeIndex; i < size - 1; i++) {
        buffer[(start + i) % capacity] = buffer[(start + i + 1) % capacity];
    }
    if (size > 0) size--;
}

T& back() const {
    return buffer[(start + size - 1) % capacity];
}

T& front() const {
    return buffer[start];
}

T& operator[](int index) const {
    return buffer[(start + index) % capacity];
}

Iterator begin() {
    return Iterator(*this, 0);
}

Iterator end() {
    return Iterator(*this, size);
}

void change_capacity(int new_capacity) {
    T* new_buffer = new T[new_capacity];
    int new_size = std::min(new_capacity, size);
    for (int i = 0; i < new_size; i++) {
        new_buffer[i] = buffer[(start + i) % capacity];
    }

    delete[] buffer;
    buffer = new_buffer;
    capacity = new_capacity;
    start = 0;
    size = new_size;
}

};

}  // namespace lab_7
