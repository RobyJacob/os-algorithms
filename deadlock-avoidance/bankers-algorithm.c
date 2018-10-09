#include <stdio.h>

int main(int argc, char const *argv[]) {
    int number_of_process,number_of_resources;
    printf("Number of process : ");
    scanf("%d", &number_of_process);
    printf("Number of resources : ");
    scanf("%d",&number_of_resources);

    int available[number_of_resources],
    max[number_of_process][number_of_resources],
    allocate[number_of_process][number_of_resources],
    need[number_of_process][number_of_resources];

    return 0;
}
