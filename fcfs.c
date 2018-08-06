#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "fcfs.h"

void sort(Process *p, int size) {
	Process tproc;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (p[j].at > p[j+1].at) {
				tproc = p[j];
				p[j] = p[j+1];
				p[j+1] = tproc;
			}
		}
	}
}

int main(int argc, char** argv) {
<<<<<<< HEAD
	int n,current_time = 0,pindex = 0,dindex = 0,idle = 0;
	float avg_turnaround_time = 0.0;
||||||| merged common ancestors
	int n,current_time = 0,pindex = 0,dindex = 0,idle = 0;
=======
	int n,current_time = 0,pindex = 0,dindex = 0,idle = 0,wt_sum = 0,tt_sum = 0;
	float avg_wt, avg_tt;
>>>>>>> fcfs-edit
	printf("Number of processes : ");
	scanf("%d",&n);
	Process p[n];
	Done d[10];
	for (int i = 0; i < n; i++) {
		printf("Process name = ");
		scanf("%s",p[i].name);
		printf("Process arrival time = ");
		scanf("%d",&p[i].at);
		printf("Process burst time = ");
		scanf("%d",&p[i].bt);
		p[i].status = 0;
		fflush(stdin);
	}
	sort(p,n);
	while (pindex < n) {
		if (p[pindex].status == 0 && p[pindex].at <= current_time) {
			if (idle == 1) {
				d[dindex].ct = current_time;
				idle = 0;
				dindex++;
			}
			strcpy(d[dindex].name,p[pindex].name);
			d[dindex].st = current_time;
			d[dindex].ct = current_time + p[pindex].bt;
			p[pindex].tt = d[dindex].ct - p[pindex].at;
			p[pindex].wt = p[pindex].tt - p[pindex].bt;
			p[pindex].status = 1;
			current_time = d[dindex].ct;
			dindex++;
			pindex++;
		} else if (idle == 0) {
			strcpy(d[dindex].name,"idle");
			d[dindex].st = current_time;
			idle = 1;
		} else {
			current_time++;
		}
	}
	// strcpy(d[dindex].name,"null");
	/*
	 * Process name  startTime completeTime
	 */
	// printf("\tProcessName\tAT\tBT\tST\tCT\tTT\tWT\n");
	// for (pindex = 0, dindex = 0; pindex < n; pindex++, dindex++) {
	// 	printf("\t%s\t%d\t%d\t%d\t%d\t%d\t%d",p[pindex].name,p[pindex].at,p[pindex].bt,d[dindex].st,
	// d[dindex].ct,p[pindex].tt,p[pindex].wt);
	// 	printf("\n");
	// }
<<<<<<< HEAD
	for (dindex = 0;; dindex++) {
		if (strcmp(d[dindex].name,"null") != 0) {
			printf("%s %d %d\n", d[dindex].name, d[dindex].st, d[dindex].ct);
			avg_turnaround_time += d[dindex].st;
		} else {
			break;
		}
||||||| merged common ancestors
	for (dindex = 0;; dindex++) {
		if (strcmp(d[dindex],name,"null") != 0) {
			printf("%s %d %d\n", d[dindex].name, d[dindex].st, d[dindex].ct);
		} else {
			break;
		}
=======
	printf("Name\tat\tbt\twt\ttt\n");
	for (pindex = 0; pindex < n; pindex++) {
		printf("%s\t%d\t%d\t%d\t%d\n", p[pindex].name, p[pindex].at, p[pindex].bt, p[pindex].wt, p[pindex].tt);
		wt_sum += p[pindex].wt;
		tt_sum += p[pindex].tt;
>>>>>>> fcfs-edit
	}
<<<<<<< HEAD
	printf("Avg turnaround time = %f\n", avg_turnaround_time);
	// for (pindex = 0; pindex < n; pindex++) {
	// 	printf("%s %d\n", p[pindex].name, p[pindex].wt);
	// }
||||||| merged common ancestors
=======
	avg_wt = (float)wt_sum / n;
	avg_tt = (float)tt_sum / n;
	printf("avg wt = %.3f\tavg tt = %.3f\n", avg_wt, avg_tt);
>>>>>>> fcfs-edit
	return 0;
}
