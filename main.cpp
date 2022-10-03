#include <iostream>
#include "Source_Filles/MLFQ.h"

int main() {
    MLFQ mlfq = MLFQ();
    Job job1 = Job(1, 10, 5);
    mlfq.addJob(job1);
    std::string str = mlfq.toString();
    std::cout << mlfq.toString();

    for(int i = 1; i < 21 ; i ++ ){
        std::cout << "At time " + std::to_string(i) + ": \n";

        if (i == 2) {
            Job job2 = Job(2, 10, 5);
            mlfq.addJob(job2);
        }
        mlfq.execute(1);

        std::cout << mlfq.toString();

    }
    return 1;


}
