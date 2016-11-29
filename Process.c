#include <stdlib.h>
#include <stdio.h>
#include "Process.h"


#define TRUE 1
#define FALSE 0

#define OK TRUE
#define KO FALSE


#define INITIAL_MAX_PROCESSES_SIZE 10
static ProcessList *processes;

int initProcesses(){
	//printf("enter in initProcesses");
	if(!processes)
	{
	    processes = malloc(sizeof(ProcessList));

		//printf("procs is null: initialize it");
		processes->procs = malloc(INITIAL_MAX_PROCESSES_SIZE * sizeof(Process*));
		processes->size = INITIAL_MAX_PROCESSES_SIZE;
		processes->count = 0;
	}

	if(processes->count+1 >= processes->size)
	{
		//printf("reallocting processes\n");
		int new_size = (INITIAL_MAX_PROCESSES_SIZE + processes->size);
		processes->procs = realloc(processes->procs,new_size * sizeof(Process*));
		processes->size = new_size;
	}

	return OK;
}

int run_emptyTask(Process* _this){

	if(!_this)
		return 6;

	printf("Process(pid=%d) : Run default Task\n", _this->id);

	_this->terminate(_this);

	return 0;
}

int terminate_emptyTask(Process *_this){

        if(!_this)
                return 6;
        _this->state = ENDED;

		return 0;
}

Process* newProcess(){
	//printf("Process: initProcesses");
	int ret_initProc = initProcesses();
	if(ret_initProc != OK)
			printf("error when init proc(errno: %d)\n", ret_initProc);
	int new_pid = processes->count + 1;

	Process* p = malloc(sizeof(Process));
	p->id = new_pid;
	p->state = NEW;
	p->memory_needed = 0;
	p->run_task = run_emptyTask;
	p->terminate = terminate_emptyTask;

	processes->procs[processes->count] = p;
	processes->count = processes->count + 1;

	return p;
}


int destroyProcesses(){
    int i;
    for(i=0; i<processes->count; ++i){
        free(processes->procs[i]);
        --(processes->count);
    }
    free(processes);
    return OK;
}

