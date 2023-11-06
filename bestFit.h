#ifndef PARTITION_ALLOCATION_LAB_BESTFIT_H
#define PARTITION_ALLOCATION_LAB_BESTFIT_H
#include "startInfo.h"
#include <algorithm>

void executeBestFit(SuperStruct& sp);
void static autoLoop(SuperStruct& sp);
bool static cmpPartSize(std::pair<int, Partition>& a, std::pair<int, Partition>& b);

#endif //PARTITION_ALLOCATION_LAB_BESTFIT_H
