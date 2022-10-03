//
// Created by Luyi Xiao on 9/28/22.
//

#ifndef CS5600_JOB_H
#define CS5600_JOB_H


#include <string>

class Job {
private:
    int id;
    int time;
    int countdownTime;
public:
    Job(int i, int t, int c);
    bool reduceTime(int t);
    bool reduceCountdownTime(int t);
    int getId() {return id;};
    int getTime() {return time;};
    int getCountDowntime() {return countdownTime;};
    std::string toString() ;
};


#endif //CS5600_JOB_H
