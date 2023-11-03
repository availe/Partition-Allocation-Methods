#include "firstFit.h"

void execute(SuperStruct &sp) {
    autoLoop(sp);
}

void autoLoop(SuperStruct &sp) {
    int i = 0;
    for (auto j: sp.jobList) {
        for (auto p: sp.partitionList) {
            if (j.second.size <= sp.partitionList.size() || !p.second.status) {
                std::cout << "\n" << i << "\n";
                sp.partitionList.at(i).jobId = j.second.jobId;
                sp.partitionList.at(i).status = true;
                //sp.partitionList.at(i).status = true;
            }
            std::cout << "Index: " << i << " jID: " << j.second.jobId << " pID: " << p.second.partitionId;
            i++;
        }
    }
}