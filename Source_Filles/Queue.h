//
// Created by Luyi Xiao on 9/28/22.
//

#ifndef CS5600_QUEUE_H
#define CS5600_QUEUE_H

#include <vector>
#include "Job.h"
using std::vector;

class Queue {
private:
    vector<Job> queue;
    int priority;
public:
    Queue(int pri);
    void addJob(Job j);
    int getJobIdx(int jID);
    Job getJobFromIdx(int idx) {return queue[idx];};
    Job getJobFromJobID(int JID);
    int removeJobWithIdx(int idx);
    int removeJobWithJobId(int idx);
    int getLength(){return queue.size();};
    bool isEmpty(){return queue.empty();};
    int groupReduceCountdownTime(int time);
    int executeQueue(int time);
    std::string toString();
};


#endif //CS5600_QUEUE_H
