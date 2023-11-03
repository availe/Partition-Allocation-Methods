#include "startInfo.h"

/*void inputValues(superStruct sp) {
    int numOfPartitions, sizeOfPartitions, numofProcesses;
    std::cout << "Insert numOfMemoryPartitions: ";
    std::cin >> numOfPartitions;

    for (int i = 0; i < numOfPartitions; i++) {

    }


    std::cout << "\nInsert sizeOfMemoryPartitions: ";
    std::cin >> sizeOfPartitions;
    std::cout << "\nInsert numofProcesses";
    std::cin >> numofProcesses;

    int processId;
    for (int i = 0; i < numofProcesses; i++) {
        processId = i;
        std::cout << "Which partition does job belong to?";
    }
}*/

void inputValuesFixed(SuperStruct &sp) {
    Partition p0, p1, p2, p3;
    std::vector<Partition> partitionList;
    partitionList.emplace_back(p0);
    partitionList.emplace_back(p1);
    partitionList.emplace_back(p2);
    partitionList.emplace_back(p3);

    Job j0, j1, j2, j3;
    std::vector<Job> jobList;
    jobList.emplace_back(j0);
    jobList.emplace_back(j1);
    jobList.emplace_back(j2);
    jobList.emplace_back(j3);

    for (int i = 0; i < partitionList.size(); i++) {
        sp.partitionList[i].partitionId = i;
        sp.jobList[i].jobId = i;
    }
}
