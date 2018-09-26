#include<stdio.h>

int main() {
  int victim = -1,frames[50],ref[50],no_of_pages,no_of_frames,page_fault_count = 0,flag = 0;

  printf("Number of frames : ");
  scanf("%d",&no_of_frames);
  printf("Number of pages : ");
  scanf("%d",&no_of_pages);
  for (int i = 0; i < no_of_pages; i++) {
    printf("Page %d : ",i+1);
    scanf("%d",&ref[i]);
  }
  for (int i = 0; i < no_of_frames; i++) {
    frames[i] = -1;
  }

  printf("\n");
  for (int p = 0; p < no_of_pages; p++) {
    for (int f = 0; f < no_of_frames; f++) {
      if (frames[f] == ref[p]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      page_fault_count++;
      victim++;
      victim = victim % no_of_frames;
      frames[victim] = ref[p];
      for (int f = 0; f < no_of_frames; f++) {
        printf("Frame %d : %d\n",f+1,frames[f]);
      }
    }
    printf("\n");
  }

  printf("Page fault : %d\n",page_fault_count);

  return 0;
}
