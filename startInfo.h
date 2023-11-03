#ifndef PARTITION_ALLOCATION_LAB_STARTINFO_H
#define PARTITION_ALLOCATION_LAB_STARTINFO_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct Partition {
    int partitionId;
    int jobId;
    bool status;
    int size;
    int remainingSize;
    Partition() {
        partitionId = 0;
        jobId = 0;
        status = false;
        size = 0;
        remainingSize = 0;
    }
};

struct Job {
    int jobId;
    bool status;
    int assignedPart;
    int size;

    Job() {
        jobId = 0;
        status = false;
        assignedPart = -1;
        size = 0;
    }
};

struct SuperStruct {
    std::unordered_map<int, Partition> partitionList;
    std::unordered_map<int, Job> jobList;

    SuperStruct(): partitionList(), jobList() {}
};

//void inputValues(superStruct sp);

void inputValuesFixed(SuperStruct &sp);

#endif //PARTITION_ALLOCATION_LAB_STARTINFO_H
