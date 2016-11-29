

#ifndef PROCESS_H
#define PROCESS_H


typedef enum ProcessState_Enum{
	NEW,
	RUNNING,
	WAITING,
	ENDED
}ProcessState;


typedef struct process_struct{
	int id;
	ProcessState state;
	int (*run_task)(struct process_struct* _this);
	int (*terminate)(struct process_struct* _this) ;
	int memory_needed;
} Process;

typedef struct process_list_struct{
	Process** procs;
	int count;
	int size;
} ProcessList;


Process* newProcess();


int destroyProcesses();



#endif
