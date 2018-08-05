#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct process {
	char name[50];
	int tt, wt, bt, at, status;
}Process;

typedef struct done {
	char name[50];
	int st, ct;
}Done;

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
	int n,current_time = 0,pindex = 0,dindex = 0,idle = 0;
	float avg_turnaround_time = 0.0;
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
	strcpy(d[dindex].name,"null");
	/*
	 * Process name  startTime completeTime
	 */
	// printf("\tProcessName\tAT\tBT\tST\tCT\tTT\tWT\n");
	// for (pindex = 0, dindex = 0; pindex < n; pindex++, dindex++) {
	// 	printf("\t%s\t%d\t%d\t%d\t%d\t%d\t%d",p[pindex].name,p[pindex].at,p[pindex].bt,d[dindex].st,
	// d[dindex].ct,p[pindex].tt,p[pindex].wt);
	// 	printf("\n");
	// }
	for (dindex = 0;; dindex++) {
		if (strcmp(d[dindex].name,"null") != 0) {
			printf("%s %d %d\n", d[dindex].name, d[dindex].st, d[dindex].ct);
			avg_turnaround_time += d[dindex].st;
		} else {
			break;
		}
	}
	printf("Avg turnaround time = %f\n", avg_turnaround_time);
	// for (pindex = 0; pindex < n; pindex++) {
	// 	printf("%s %d\n", p[pindex].name, p[pindex].wt);
	// }
	return 0;
}
