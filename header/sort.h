#ifndef SORT
#define SORT

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

#endif
