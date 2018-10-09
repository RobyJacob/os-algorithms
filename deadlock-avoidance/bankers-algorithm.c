#include <stdio.h>

int lessThan(int *ar1,int *ar2,int size) {
    for (int i = 0; i < size; i++) {
        if (ar1[i] >= ar2[i]) return 0;
    }

    return 1;
}

void addWork(int *ar1,int *ar2,int size) {
    for (int i = 0; i < size; i++) {
        ar1[i] += ar2[i];
    }
}

int isAllTrue(int *arr,int size) {
    for (int i = 0; i < size; i++) {
        if (!arr[i]) return 0;
    }

    return 1;
}

int main(int argc, char const *argv[]) {
    int number_of_process,number_of_resources,number_of_instances,
    confirm = 0;
    printf("Number of process : ");
    scanf("%d", &number_of_process);
    printf("Number of resources : ");
    scanf("%d",&number_of_resources);

    int available[number_of_resources],
    max[number_of_process][number_of_resources],
    allocate[number_of_process][number_of_resources],
    need[number_of_process][number_of_resources],
    request[number_of_resources],
    work[number_of_resources],
    finish[number_of_process],
    safe[number_of_process];

    for (int p = 0; p < number_of_process; p++) {
        finish[p] = 0;
    }

    printf("Instances of each resource\n");
    for (int r = 0; r < number_of_resources; r++) {
        printf("Resource %d : ",r+1);
        scanf("%d",&available[r]);
    }
    printf("Max and allocate for each resource\n");
    for (int p = 0; p < number_of_process; p++) {
        printf("Process %d\n",p+1);
        for (int r = 0; r < number_of_resources; r++) {
            printf("Resource %d\n",r+1);
            printf("Max : ");
            scanf("%d", &max[p][r]);
            printf("Allocate : ");
            scanf("%d", &allocate[p][r]);
            need[p][r] = max[p][r] - allocate[p][r];    /* calculate need */
        }
        printf("Request ? : ");
        scanf("%d",&confirm);
        if (confirm) {
            for (int i = 0; i < number_of_resources; i++) {
                printf("Request for resource %d : ",i+1);
                scanf("%d", &request[i]);
                if (request[i] <= need[p][i]) {
                    if (request[i] <= available[i]) {
                        available[i] -= request[i];
                        allocate[p][i] += request[i];
                        need[p][i] -= request[i];
                    }
                } else {
                    printf("Request exceded claim ,can't process request\n");
                    break;
                }
            }
        }
    }

    for (int r = 0; r < number_of_resources; r++) {
        work[r] = available[r];
    }

    for (int p = 0; p < number_of_process; ) {
        if (!finish[p] && lessThan(need[p],work,number_of_resources)) {
            addWork(work,allocate[p],number_of_resources);
            finish[p] = 1;
            p++;
        } else if (isAllTrue(finish,number_of_process)) {
            safe[p] = 1;
        } else {
            if (p < number_of_process) p++;
            else p = 0;
        }
    }

    return 0;
}
