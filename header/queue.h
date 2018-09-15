#ifndef QUEUE
#define QUEUE

void enqueue(int *queue,int *front,int *rear,int item) {
  if (*front == -1) (*front)++;
  (*rear)++;
  queue[*rear] = item;
}

int dequeue(int *queue,int *front,int *rear) {
  int popped_item = 0;

  if (*front == -1) return -1;

  if (*front == *rear) {
    popped_item = queue[*front];
    *front = -1;
    *rear = -1;
    return  popped_item;
  }

  popped_item = queue[*front];
  (*front)++;
  return popped_item;
}

#endif
