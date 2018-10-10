#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header/ganttchart.h"
#include"header/process_entity.h"
#include"header/sort.h"
#include"header/queue.h"

#define TQ 2

void main() {
  int n,current_time,dindex = 0,pindex = 0,index = 0,wt_sum = 0,tt_sum = 0,front = -1,rear = -1,idle = 0;
  float avg_tt = 0.0,avg_wt = 0.0;
  printf("Number of process : ");
  scanf("%d",&n);
  Process process[n];
  Done done[20];
  int queue[n];

  for (int i = 0; i < n; i++) {
    printf("Process name : ");
    scanf("%s",process[i].name);
    printf("Arrival time : ");
    scanf("%d",&process[i].at);
    printf("Burst time : ");
    scanf("%d",&process[i].bt);
    process[i].status = 0;
    process[i].left = process[i].bt;
  }

  while (index < n) {
    for (int i = 0; i < n; i++) {
      if (process[i].at <= current_time && process[i].status == 0) {
        enqueue(queue,&front,&rear,i);
        process[i].status = 1;
      }
    }

    if (front == -1 && idle == 0) {
      strcpy(done[dindex].name,"idle");
      done[dindex].st = current_time;
      idle = 1;
      current_time++;
    } else if (front != -1) {
      if (idle == 1) {
        done[dindex].ct = current_time;
        idle = 0;
        dindex++;
      }
      pindex = dequeue(queue,&front,&rear);
      strcpy(done[dindex].name,process[pindex].name);
      done[dindex].st = current_time;
      if (process[pindex].left <= TQ) {
        done[dindex].ct = current_time + process[pindex].left;
        process[pindex].tt = done[dindex].ct - process[pindex].at;
        process[pindex].wt = process[pindex].tt - process[pindex].bt;
        current_time = done[dindex].ct;
        process[pindex].status = 2;
        dindex++;
        index++;
      } else {
        done[dindex].ct = current_time + TQ;
        process[pindex].left = process[pindex].left - TQ;
        current_time = done[dindex].ct;
        dindex++;
        for (int j = 0; j < n; j++) {
          if (process[j].status == 0 && process[j].at <= current_time) {
            enqueue(queue,&front,&rear,j);
            process[j].status = 1;
          }
        }
        enqueue(queue,&front,&rear,pindex);
      }
    } else {
      current_time++;
    }
  }
  strcpy(done[dindex].name,"null");

  printf("name\tat\tbt\twt\ttt\n");
  for (pindex = 0; pindex < n; pindex++) {
    printf("%s\t%d\t%d\t%d\t%d\n", process[pindex].name,process[pindex].at,process[pindex].bt,process[pindex].wt,
  process[pindex].tt);
  wt_sum += process[pindex].wt;
  tt_sum += process[pindex].tt;
  }

  avg_wt = (float) wt_sum / n;
  avg_tt = (float) tt_sum / n;
  printf("Avg. waiting time = %.3f & Avg. turnaround time = %.3f\n",avg_wt,avg_tt);

  print(done);
}
