#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"header/ganttchart.h"
#include"header/process_entity.h"
#include"header/sort.h"

// int isEmpty(Process *p,int size) {
//   for (int i = 0; i < size; i++) {
//     if (p[i] == NULL) return 1;
//   }
//
//   return 0;
// }

int main(int argc, char *argv[]) {
  int n,current_time = 0,pindex = 0,dindex = 0,idle = 0,wt_sum = 0,tt_sum = 0,found = 0,flag = 0,index = 0;
  float avg_tt = 0.0,avg_wt = 0.0;
  printf("Number of process : ");
  scanf("%d",&n);
  Process process[n];
  Done done[20];

  for (int i = 0; i < n; i++) {
    printf("Process name : ");
    scanf("%s",process[i].name);
    printf("Arrival time : ");
    scanf("%d",&process[i].at);
    printf("Burst time : ");
    scanf("%d",&process[i].bt);
    process[i].status = 0;
  }

  for (pindex = 0; pindex < n;) {
    flag = 0;
    found = 0;
    for (int i = 0; i < n; i++) {
      if (process[i].status == 0 && process[i].at <= current_time && found == 0) {
        index = i;
        found++;
        flag++;
      } else if (process[i].status == 0 && process[i].at <= current_time && found > 0) {
        if (process[i].bt < process[index].bt) {
          index = i;
        }
      }
    }

    if (flag == 0 && idle == 0) {
      strcpy(done[dindex].name,"idle");
      done[dindex].st = current_time;
      idle = 1;
    } else if (flag != 0) {
      if (idle == 1) {
        done[dindex].ct = current_time;
        dindex++;
        idle = 0;
      }
      strcpy(done[dindex].name,process[index].name);
      done[dindex].st = current_time;
      done[dindex].ct = current_time + process[index].bt;
      process[index].tt = done[dindex].ct - process[index].at;
      process[index].wt = process[index].tt - process[index].bt;
      current_time = done[dindex].ct;
      dindex++;
      pindex++;
      process[index].status = 1;
    } else {
      current_time++;
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
