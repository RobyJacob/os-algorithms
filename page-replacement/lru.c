#include<stdio.h>
#include <stdlib.h>

int leastUsed(int *arr1,int *arr2,int *pos,int frames_count) {
    *pos++;
    *pos %= frames_count;
    int least = arr2[*pos];
    *pos++;
    while (*pos < frames_count) {
        if (arr1[least] > arr1[arr2[*pos]]) {
            least = arr2[*pos];
        }
        *pos++;
        // *pos %= frames_count;
    }

    return least;
}

int main() {
  int victim = -1,visit_count[50],
  no_of_pages,
  no_of_frames,
  page_fault_count = 0,
  flag = 0,
  least;

  printf("Number of frames : ");
  scanf("%d",&no_of_frames);
  printf("Number of pages : ");
  scanf("%d",&no_of_pages);
  int frames[no_of_frames],ref[no_of_pages];
  for (int i = 0; i < no_of_pages; i++) {
    printf("Page %d : ",i+1);
    scanf("%d",&ref[i]);
    visit_count[ref[i]] = 0;
  }
  for (int i = 0; i < no_of_frames; i++) {
    frames[i] = -1;
  }

  printf("\n");
  for (int p = 0; p < no_of_pages; p++) {
    flag = 0;
    for (int f = 0; f < no_of_frames; f++) {
      if (frames[f] == ref[p]) {
        flag = 1;
        visit_count[ref[p]]++;
        break;
      }
    }
    if (flag == 0) {
      page_fault_count++;
      victim++;
      victim = victim % no_of_frames;
      if (frames[victim] == -1) {
          frames[victim] = ref[p];
      } else if (frames[victim] > -1) {
          while (visit_count[frames[victim]] != 0) {
              victim++;
              victim %= no_of_frames;
              if (victim == no_of_frames-1) {
                  least = leastUsed(visit_count,frames,&victim,no_of_frames);
                  frames[least] = ref[p];
                  continue;
              }
          }
          frames[victim] = ref[p];
      }
      for (int f = 0; f < no_of_frames; f++) {
          // fflush(stdin);
          printf("Frame %d : %d\n",f+1,frames[f]);
      }
    }
    printf("\n");
  }

  // for (int p = 0; p < no_of_pages; p++) {
  //     printf("%d\t",visit_count[ref[p]]);
  // }

  printf("Page fault : %d\n",page_fault_count);

  return 0;
}
