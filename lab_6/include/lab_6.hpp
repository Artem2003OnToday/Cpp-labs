#pragma once

#include <stdexcept>

namespace lab_6 {

template <typename Iter, typename Pred>
bool all_of(Iter first, Iter last, Pred p) {
    for (; first != last; first++) {
        if (!p(*first)) {
            return false;
        }
    }
    return true;
}

template <typename Iter, typename Pred>
bool any_of(Iter first, Iter last, Pred p) {
    for (; first != last; first++) {
        if (p(*first)) {
            return true;
        }
    }
    return false;
}

template <typename Iter, typename Pred>
bool none_of(Iter first, Iter last, Pred p) {
    for (; first != last; first++) {
        if (p(*first)) {
            return false;
        }
    }
    return true;
}

template <typename Iter, typename Pred>
bool one_of(Iter first, Iter last, Pred p) {
    int cnt = 0;
    for (; first != last; first++) {
        if (p(*first)) {
            cnt++;
        }
    }
    return cnt == 1;
}

template <typename Iter, typename Comp>
bool is_sorted(Iter first, Iter last, Comp comp) {
    Iter next = first;
    while (++next != last) {
        if (!comp(*first, *next))
            return false;
        first = next;
    }
    return true;
}

template <typename Iter, typename Pred>
bool is_partitioned(Iter first, Iter last, Pred p) {
    for (; first != last; first++) {
        if (!p(*first)) {
            break;
        }
    }
    for (; first != last; first++) {
        if (p(*first)) {
            return false;
        }
    }
    return true;
}

template <typename Iter, typename T>
Iter find_not(Iter first, Iter last, T x) {
    for (; first < last; first++) {
        if (*first != x) {
            return first;
        }
    }
    
    throw std::runtime_error("not found");
}

template <typename Iter, typename T>
Iter find_backward(Iter first, Iter last, T x) {
    for (--last; last >= first; last--) {
        if (*last == x) {
            return last;
        }
    }
    
    throw std::runtime_error("not found (backward)");
}

template <typename Iter, typename Pred>
bool is_palindrome(Iter first, Iter last, Pred p) {
    for (--last; first < last;) {
        if (!p(*first, *last)) {
            return false;
        }
        first++;
        last--;
    }
    return true;
}

}  // namespace lab_6
