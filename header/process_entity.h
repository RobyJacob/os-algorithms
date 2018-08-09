#ifndef PROCESS_ENTITY
#define PROCESS_ENTITY

typedef struct process {
  char name[50];
  int at,bt,wt,tt,status;
}Process;

typedef struct done {
  char name[50];
  int st,ct;
}Done;

#endif
