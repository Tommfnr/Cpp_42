#pragma once

template <typename T, typename K>
void iter(T *array, const int len, K ft)
{
    int i = 0;
    while (i < len)
    {
        ft(array[i]);
        i++;
    }
}