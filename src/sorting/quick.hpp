#include "stlmp.h"
#include <utility>
using namespace stlmp::Sorting;

template<class T>
int QuickSort<T>::_partition(T v[], int left, int right) {
    int pivot = v[right];
    int i = left - 1;
    for (int j = left; j < right - 1; j++) {
        if (v[j] <= pivot) {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    i++;
    std::swap(v[i], v[right]);
    return i;
}

template<class T>
void QuickSort<T>::_quick(T v[], int left, int right) {
    if (left < right) {
        int partition_index = _partition(v, left, right);
        _quick(v, left, partition_index - 1);
        _quick(v, partition_index + 1, right);
    }
}

template<class T>
void QuickSort<T>::sort(int length, T v[]) {
    _quick(v, 0, length - 1);
}