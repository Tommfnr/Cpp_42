#include "easyfind.hpp"
#include <algorithm>


template <typename T>
typename T::const_iterator easyfind(const T& container, int i){
    typename T::const_iterator it = std::find(container.begin(), container.end(), i);
    if (it == container.end())
        throw std::exception();
    return it; 
}
