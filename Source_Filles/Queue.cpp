//
// Created by Luyi Xiao on 9/28/22.
//

#include "Queue.h"
#include <vector>
#include <iostream>

Queue::Queue(int pri) {
    priority = pri;
}

void Queue::addJob(Job j) {
    queue.push_back(j);
}
int Queue::getJobIdx(int jID) {
    int idx = 0;
    for (Job job: queue) {
        if (job.getId() == jID) {
            return idx;
        }
        else{
            idx += 1;
        }
    }
    return -1;
}

Job Queue::getJobFromJobID(int JID) {
    int idx = getJobIdx(JID);
    return queue[idx];
}

int Queue::removeJobWithIdx(int idx) {
    if (idx >= getLength()) {
        return -1;
    }
    queue.erase((queue.begin() + idx));
    return 1;
}

int Queue::removeJobWithJobId(int jID) {
    int idx = getJobIdx(jID);
    if (idx == -1){
        return -1;
    }
    queue.erase(queue.begin() + idx);
    return 1;
}

int Queue::groupReduceCountdownTime(int time) {
    if (isEmpty()) {
        return -1;
    }
    int idx = 0;
    for(Job &job: queue) {
        job.reduceCountdownTime(time);
        idx += 1;
    }
    return 1;
}
int Queue::executeQueue(int time) {
    if(isEmpty()) {return -1;};
    Job currJob = queue.front();

    queue.erase(queue.begin());
    currJob.reduceTime(time);
    if (currJob.getTime() <= 0) {
        std::cout << "Job " + std::to_string(currJob.getId()) + "Has finished \n" ;
        return 2;
    }
    queue.push_back(currJob);
    return 1;
}

std::string Queue::toString() {
    std::string str;
    str = str + "Queue" + std::to_string(priority) + ":\n";

    for(Job job : queue) {
        str += job.toString();
    }
    str += "\n";
    return str;
}





