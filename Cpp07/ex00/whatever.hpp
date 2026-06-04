#pragma once

template <typename T>

void swap(T &src1, T &src2) {
    T temp = src1;
    src1 = src2;
    src2 = temp;
}

template <typename T>
T max(const T &src1, const T &src2) {
    return (src1 > src2 ? src1 : src2);
}

template <typename T>
T min(const T &src1, const T &src2) {
    return (src1 < src2 ? src1 : src2);
}