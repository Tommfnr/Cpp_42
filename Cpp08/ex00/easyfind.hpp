#pragma once

#include <iostream>

template <typename T>
typename T::const_iterator easyfind(const T& container, int i);

#include "easyfind.tpp"
