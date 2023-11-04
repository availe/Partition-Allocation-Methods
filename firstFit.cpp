#include "firstFit.h"

void executeFirstFit(SuperStruct &sp) {
    autoLoop(sp);
}

void autoLoop(SuperStruct &sp) {
    for (auto &[jobId, job]: sp.jobList) {
        if (job.status) continue;
        for (auto &[partId, part]: sp.partitionList) {
            if (part.status || job.size > part.size) continue;
             part.assignedJob = jobId;
             part.status = true;
             job.assignedPart = partId;
             job.status = true;
             part.updateMemoryWaste(job.size);
             break;
        }
    }
}

void results(SuperStruct &sp) {
    int width = 20;
    std::cout <<
    std::setw(width) << std::left << "\nJob ID" <<
    std::setw(width) << std::left << "Partition ID" <<
    std::setw(width) << std::left << "Partition Size" <<
    std::setw(width) << std::left << "Job Size" <<
    std::setw(width) << std::left << "Partition Waste" <<
    std::setw(width) << std::left << "Job Status" << "\n";

    for (auto [jobId, job] : sp.jobList) {
        if (job.assignedPart == -1) {
            std::cout << "Warning: Job " << jobId << " could not be allocated\n";
            continue;
        }

        std::cout <<
        std::setw(width) << std::left << jobId <<
        std::setw(width) << std::left << job.assignedPart <<
        std::setw(width) << std::left << sp.partitionList.at(job.assignedPart).size <<
        std::setw(width) << std::left << job.size <<
        std::setw(width) << std::left << sp.partitionList.at(job.assignedPart).memoryWaste <<
        std::setw(width) << std::left << job.status << "\n";
    }
}