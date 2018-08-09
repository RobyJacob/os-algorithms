#ifndef GANTTCHART
#define GANTTCHART

#include "fcfs.h"
#include<stdio.h>
#include<string.h>

void print(Done *dprocess){
  int size = 0;
  for (int i = 0; ; i++) {
    if (strcmp(dprocess[i].name,"null") != 0) {
      size += 1;
    } else {
      break;
    }
  }
  // for (int i = 0; i < size; i++) {
  //   printf("---\t\t");
  // }
  printf("\n");
  printf("|");
  for (int i = 0; i < size; i++) {
    printf("%s\t|\t", dprocess[i].name);
  }
  printf("\n");
  printf("%d\t",dprocess[0].st);
  for (int i = 1; i < size; i++) {
    printf("%d\t\t", dprocess[i].st);
  }
  printf("%d",dprocess[size-1].ct);
  printf("\n");
}

#endif
