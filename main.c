#include <stdio.h>
#include <stdlib.h>
#include "Scheduler.h"
#include "Process.h"


#define TRUE 1
#define FALSE 0

#define OK 0
#define KO 1

int wait1_3 = TRUE;
int iteration_3 = 3;

int initMemoryManager(){

	return OK;
}



int ProcessTask_p1(Process* _this){


	printf("I'm p1, my pid is %d\n", _this->id);
    if(wait1_3){
        printf("p1: I'm waiting for p3\n");
        return 0;
    }


	_this->terminate(_this);
	return 0;
}

int ProcessTask_p3(Process* _this){

	printf("I'm p3, my pid is %d\n", _this->id);

    if(iteration_3 !=0){

        printf("p3: %d iteration(s) remaining\n", iteration_3);
         --iteration_3;
        return 0;
    }

    wait1_3 = OK;

    _this->terminate(_this);
    return 0;
}


int initProcs(){


	Process* p1 = newProcess();
	p1->run_task = ProcessTask_p1;

	/** process with default Task */
	Process* p2 = newProcess();

	Process* p3 = newProcess();
	p3->run_task =  ProcessTask_p3;

	submitProcess(p1);
	submitProcess(p2);
	submitProcess(p3);

	return OK;
}

int runTests(){

	runScheduler();

	//runScheduler();


	return OK;
}

int destroyAll(){

    destroyScheduler();
    destroyProcesses();

    return OK;
}


int main(int argc, char* argv[]){

	printf("init MemoryManager\n");
	int initMem = initMemoryManager();
	if(initMem == KO) return 1;

	printf("init processes\n");
	int initProc = initProcs();
	if(initProc == KO) return 2;
	printf("run tests\n");
	int testsrun = runTests();
	if(testsrun == KO) return 3;


	destroyAll();

	return OK;
}
