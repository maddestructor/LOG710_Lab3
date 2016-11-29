
#include <stdio.h>
#include <stdlib.h>

#include "Scheduler.h"
#include "Process.h"

#define TRUE 1
#define FALSE 0

#define OK 0
#define KO 1


#define MAX_REMAINNING_INACTIVITY_LOOP 20

#define INITIAL_MAX_PROCESSES_SIZE 10
static ProcessList *processes;

int initInternalProcessList(){

    if(!processes)
	{
	    processes = malloc(sizeof(ProcessList));

		printf("procs is null: initialize it");
		processes->procs = malloc(INITIAL_MAX_PROCESSES_SIZE * sizeof(Process*));
		processes->size = INITIAL_MAX_PROCESSES_SIZE;
		processes->count = 0;
	}

	if(processes->count+1 >= processes->size)
	{
		int new_size = (INITIAL_MAX_PROCESSES_SIZE + processes->size);
		processes->procs = realloc(processes->procs,new_size * sizeof(Process*));
		processes->size = new_size;
	}

	return OK;
}


int initScheduler(){
	initInternalProcessList();
	return OK;
}

int submitProcess(Process* p){
	initScheduler();

	if(!p) return 4;
	if(!(p->id)
			|| !(p->run_task)
			|| !(p->terminate))
		{
			return INVALID_PROC;
		}


	processes->procs[processes->count] = p;
	processes->count = processes->count + 1;

	return OK;

}

int runScheduler(){
	initScheduler();

	int scheduler_loop = 0;
	int inactivityLoop = 0;

	int last_running_Procs = 0;
	int running_Procs = 0;

	int i;
	Process *curr_p;

	//initialyze running Procs with procs which has not Ended
	for(i=0; i<processes->count; ++i){
        curr_p = (processes->procs[i]);
        if(curr_p->state != ENDED )
        {
            ++running_Procs;
        }
    }

	//run scheduler
	while(TRUE)
	{
		last_running_Procs = running_Procs;

		for(i=0; i<processes->count; ++i){
			curr_p = (processes->procs[i]);
			if(curr_p->state == NEW || curr_p->state == WAITING )
			{
				curr_p->state = RUNNING;
				curr_p->run_task(curr_p);
				if(curr_p->state != ENDED)
					curr_p->state = WAITING;
				else
					--running_Procs;
			}
		}

		++ scheduler_loop;
		if(running_Procs == 0) return 0;
		if(running_Procs == last_running_Procs ){
            ++inactivityLoop;
            if(inactivityLoop >= MAX_REMAINNING_INACTIVITY_LOOP){
                printf("not all process has ended but nothing Change\nforce terminated remaining processes\n");
                for(i=0; i<processes->count; ++i){
                    curr_p = (processes->procs[i]);
                    if(curr_p->state != ENDED)
                    {
                        curr_p->terminate(curr_p);
                    }
                }

                return 5;
            }
        }else{
            inactivityLoop = 0;
        }
	}

	return OK;
}

int destroyScheduler(){
    free(processes);
    return OK;
}




