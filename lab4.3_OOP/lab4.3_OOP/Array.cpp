#include "Array.h"

Array::Array(int s) {
    size = s;

    for (int i = 0; i < 100; i++)
        data[i] = 0;
}