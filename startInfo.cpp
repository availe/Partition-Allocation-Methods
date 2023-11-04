#include "startInfo.h"

void inputValues(SuperStruct& sp) {
    int numOfPartitions = 0, numOfJobs = 0;
    std::cout << "Insert num of partitions: ";
    std::cin >> numOfPartitions;

    for (int i = 0; i < numOfPartitions; i++) {
        Partition p;
        std::cout << "\nInsert size for partition  " << i << ": ";
        std::cin >> p.size;
        p.id = i;
        sp.partitionList[p.id] = p;
    }

    std::cout << "\nInsert num of jobs: ";
    std::cin >> numOfJobs;

    for (int i = 0; i < numOfJobs; i++) {
        Job j;
        std::cout << "\nInsert size for job " << i << ": ";
        std::cin >> j.size;
        j.id = i;
        sp.jobList[j.id] = j;
    }
}

void inputValuesFixed(SuperStruct &sp) {
    std::vector<int> partitionSizeList = {100, 300, 200, 450};
    std::vector<int> jobSizeList = {100, 300, 200, 450};

    if (partitionSizeList.size() != jobSizeList.size()) {
        std::cout << "# of jobs and partitions must be equivalent (for now)";
        std::exit(1);
    }

    for (int i = 0; i < jobSizeList.size(); i++) {
        Partition p;
        p.id = i;
        p.size = partitionSizeList[i];
        sp.partitionList[p.id] = p;

        Job j;
        j.id = i;
        j.size = jobSizeList[i];
        sp.jobList[j.id] = j;
    }
}

void Partition::updateMemoryWaste(int jobSize) {
    if(!status) {
        return; // no need to check if partition has no job
    }
    memoryWaste = size - jobSize;
}

Partition::Partition() {
    id = -1;
    assignedJob = -1;
    status = false;
    size = -1;
    memoryWaste = -1;
}

Job::Job() {
    id = -1;
    status = false;
    assignedPart = -1;
    size = -1;
}
