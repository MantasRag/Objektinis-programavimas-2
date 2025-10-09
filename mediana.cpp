#include "mediana.h"
#include <algorithm>


float sk_mediana(std::vector<int> paz) {
    std::sort(paz.begin(), paz.end());
    int n = paz.size();
    if (n % 2 == 0) {
        return (paz[n/2 - 1] + paz[n/2]) / 2.0;
    } else {
        return paz[n/2];
    }
}