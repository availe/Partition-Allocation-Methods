#include "firstFit.h"

void execute(SuperStruct &sp) {
    autoLoop(sp);
}

void autoLoop(SuperStruct &sp) {
    int i = 0;
    for (auto j: sp.jobList) {
        for (auto p: sp.partitionList) {
            if (j.second.size <= sp.partitionList.size()) {
                sp.partitionList.at(i).jobId = j.second.jobId;
                sp.partitionList.at(i).status = true;
            }
            i++;
        }
    }
}