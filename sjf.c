#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"header/ganttchart.h"
#include"header/process_entity.h"
#include"header/sort.h"

int isValid(char *argv[], int argc) {
  if (argc != 2) return 0;
  for (int i = 1; i < argc; i++) {
    for (int j = 0; j != '\0'; j++) {
        if (!isalpha((int) *argv[j])) return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {
  // check argument validity
  if (!isValid(argv,argc)) {
    printf("Invalid arguments\n");
    exit(1);
  }

  // initialize variables
  int n,init = 0,current_time = 0,pindex = 0,dindex = 0,minbt = 0,idle = 0,wt_sum = 0,tt_sum = 0;
  float avg_wt = 0.0, avg_tt = 0.0;
  printf("Number of process : ");
  scanf("%d", &n);
  Process process[n];
  Done done[10];

  // accept input from user
  for (int i = 0; i < n; i++) {
    fflush(stdin);
    printf("Process name : ");
    scanf("%s",process[i].name);
    printf("Arrival time : ");
    scanf("%d",&process[i].at);
    printf("Burst time : ");
    scanf("%d",&process[i].bt);
    process[i].status = 0;
  }

  // process processing
  while (pindex < n) {
    if (strcmp(argv[1],"non-premptive") == 0) {
      sort(process,n,"bt"); // sort based on burst time
      strcpy(done[dindex].name,process[pindex].name);
      done[dindex].st = current_time;
      done[dindex].ct = current_time + process[pindex].bt;
      process[pindex].tt = done[dindex].ct - process[pindex].at;
      process[pindex].wt = process[pindex].tt - process[pindex].bt;
      current_time = done[dindex].ct;
      process[pindex].status = 1;
      pindex++;
      dindex++;
    }
  }
  strcpy(done[dindex].name,"null");

  // display the process details in table format
  printf("name\tat\tbt\twt\ttt\n");
  for (pindex = 0; pindex < n; pindex++) {
    printf("%s\t%d\t%d\t%d\t%d\n", process[pindex].name,process[pindex].at,process[pindex].bt,process[pindex].wt,
  process[pindex].tt);
  wt_sum += process[pindex].wt;
  tt_sum += process[pindex].tt;
  }

  // display avg. waiting and turnaround time
  avg_wt = (float) wt_sum / n;
  avg_tt = (float) tt_sum / n;
  printf("Avg. waiting time = %.3f & Avg. turnaround time = %.3f\n",avg_wt,avg_tt);

  // display ganttchart
  print(done);

  return 0;
}
