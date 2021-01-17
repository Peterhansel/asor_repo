#include <stdlib.h>
#include <stdio.h>
#include <sched.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char **argv){
	struct sched_param sched;
	int proceso = sched_getscheduler(getpid());

	switch(proceso){
		case SCHED_OTHER: 
			printf("Scheduler: OTHER ");
			break;
		case SCHED_FIFO: 
                        printf("Scheduler: FIFO ");
			break;
		case SCHED_BATCH: 
                        printf("Scheduler: BATCH ");
			break;
                case SCHED_IDLE: 
                        printf("Scheduler: IDLE ");
			break;
                case SCHED_RR: 
                        printf("Scheduler: RR ");
			break;
		default:
			printf("Scheduler: ERROR ");
			break;
	}
	sched_getparam(getpid(),&sched);
	printf("Prio: %i ",sched.sched_priority);
	int max = sched_get_priority_max(proceso);
	int min = sched_get_priority_min(proceso);
	printf("Max: %i Min: %i \n",max,min);
	
	return 0;
}
