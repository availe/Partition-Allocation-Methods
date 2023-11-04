#ifndef PARTITION_ALLOCATION_LAB_STARTINFO_H
#define PARTITION_ALLOCATION_LAB_STARTINFO_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip>

struct Partition {
    int id;
    int assignedJob;
    bool status;
    int size;
    int memoryWaste;
    Partition(); // defined in cpp file
    void updateMemoryWaste(int jobSize);
};

struct Job {
    int id;
    bool status;
    int assignedPart;
    int size;
    Job(); // defined in cpp file
};

struct SuperStruct {
    std::unordered_map<int, Partition> partitionList;
    std::unordered_map<int, Job> jobList;
    void results();
};

void inputValues(SuperStruct& sp);

void inputValuesFixed(SuperStruct& sp);

#endif //PARTITION_ALLOCATION_LAB_STARTINFO_H
