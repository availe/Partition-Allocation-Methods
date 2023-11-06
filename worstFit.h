#ifndef PARTITION_ALLOCATION_LAB_WORSTFIT_H
#define PARTITION_ALLOCATION_LAB_WORSTFIT_H
#include "startInfo.h"
#include <algorithm>

void executeWorstFit(SuperStruct& sp);
void static autoLoop(SuperStruct& sp);
bool cmpTestSize(std::pair<int, Partition>& a, std::pair<int, Partition>& b);

#endif //PARTITION_ALLOCATION_LAB_WORSTFIT_H
