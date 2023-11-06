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
        sp.partitionMap[p.id] = p;
    }

    std::cout << "\nInsert num of jobs: ";
    std::cin >> numOfJobs;

    for (int i = 0; i < numOfJobs; i++) {
        Job j;
        std::cout << "\nInsert size for job " << i << ": ";
        std::cin >> j.size;
        j.id = i;
        sp.jobMap[j.id] = j;
    }
}

void inputValuesFixed(SuperStruct &sp) {
    std::vector<int> partitionSizeList = {100, 300, 200, 450};
    std::vector<int> jobSizeList = {200, 100, 300, 300, 200};

    for (int i = 0; i < jobSizeList.size(); i++) {
        Partition p;
        p.id = i;
        p.size = partitionSizeList[i];
        sp.partitionMap[p.id] = p;

        Job j;
        j.id = i;
        j.size = jobSizeList[i];
        sp.jobMap[j.id] = j;
    }
}

void SuperStruct::results() {
    int width = 20;
    std::cout <<
              std::setw(width) << std::left << "\nJob ID" <<
              std::setw(width) << std::left << "Partition ID" <<
              std::setw(width) << std::left << "Partition Size" <<
              std::setw(width) << std::left << "Job Size" <<
              std::setw(width) << std::left << "Partition Waste" <<
              std::setw(width) << std::left << "Job Status" << "\n";

    for (auto [jobId, job]: jobMap) {
        if (job.assignedPart == -1) {
            std::cout << "Warning: Job " << jobId + 1 << " could not be allocated -- Job Status: " << job.status << "\n";
            continue;
        }

        // we increased jobId and assignedPart by +1 to start at 1 and not 0
        std::cout <<
                  std::setw(width) << std::left << jobId + 1 <<
                  std::setw(width) << std::left << job.assignedPart + 1 <<
                  std::setw(width) << std::left << partitionMap.at(job.assignedPart).size <<
                  std::setw(width) << std::left << job.size <<
                  std::setw(width) << std::left << partitionMap.at(job.assignedPart).memoryWaste <<
                  std::setw(width) << std::left << job.status << "\n";
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
