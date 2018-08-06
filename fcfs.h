#ifndef FCFS
#define FCFS

typedef struct process {
	char name[50];
	int tt, wt, bt, at, status;
}Process;

typedef struct done {
	char name[50];
	int st, ct;
}Done;

#endif
