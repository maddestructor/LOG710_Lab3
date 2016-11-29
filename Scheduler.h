
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Process.h"

typedef enum
{
	INVALID_PROC
} Sched_Err;



/**
Initialyze Scheduler
*/
int initScheduler();

/**
had new process to schedule
*/
int submitProcess(Process* p);

/**
iterate over each submitted processes and run them only if process has not ended
*/
int runScheduler();

/** finalyze scheduler */
int destroyScheduler();


#endif
