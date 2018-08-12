#ifndef SORT
#define SORT
#include <string.h>

void sort(Process *p, int size,char basedon[]) {
	Process tproc;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (strcmp(basedon,"at") == 0) {
				if (p[j].at > p[j+1].at) {
					tproc = p[j];
					p[j] = p[j+1];
					p[j+1] = tproc;
				}
			} else if (strcmp(basedon,"bt")) {
				if (p[j].bt > p[j+1].bt) {
					tproc = p[j];
					p[j] = p[j+1];
					p[j+1] = tproc;
				}
			}
		}
	}
}

#endif
