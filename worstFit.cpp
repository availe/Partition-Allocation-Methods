#include "worstFit.h"

void executeWorstFit(SuperStruct &sp) {
    autoLoop(sp);
    std::cout << "---\nResults for worst fit:";
    sp.results();
}

// used to sort partition vector from largest to smallest
bool cmpPartSize (std::pair<int, Partition>& a, std::pair<int, Partition>& b) {
    return a.second.size >= b.second.size;
}

void static autoLoop(SuperStruct &sp) {
    // we cannot sort a hashmap, so we're unloading into a vector
    std::vector<std::pair<int, Partition>> partitionList;
    partitionList.reserve(sp.partitionMap.size());
    for (auto& part: sp.partitionMap) {
        partitionList.emplace_back(part);
    }
    std::sort(partitionList.begin(), partitionList.end(), cmpPartSize);

    for (auto &[jobId, job]: sp.jobMap) {
        if (job.status) continue;
        for (auto &[partId, part]: partitionList) {
            if (part.status || job.size > part.size) continue;
            part.assignedJob = jobId;
            part.status = true;
            job.assignedPart = partId;
            job.status = true;
            part.updateMemoryWaste(job.size);
            sp.partitionMap[partId] = part;
            break;
        }
    }
}