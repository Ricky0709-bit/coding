#include <iostream>
using namespace std;

#define SIZE 10

struct Queue {
    int q[SIZE];
    int front, rear;
} queue;

int isempty(struct Queue* queue) {
    return queue->front > queue->rear;
}

int isfull(struct Queue* queue) {
    return queue->rear == SIZE - 1;
}

int enqueue(struct Queue* queue, int value) {
    if (!isfull(queue)) {
        if (queue->front != 0) {
            // Shift elements to the start of the array if front != 0
            int j = 0;
            for (int i = queue->front; i <= queue->rear; i++) {
                queue->q[j++] = queue->q[i];
            }
            queue->rear = queue->rear - queue->front;
            queue->front = 0;
        }
        queue->rear++;
        queue->q[queue->rear] = value;
        return 1;
    } else {
        cout << "Queue Overflow.\n";
        return 0;
    }
}

int dequeue(struct Queue* queue) {
    if (!isempty(queue)) {
        int value = queue->q[queue->front++];
        // Reset queue if it becomes empty
        if (queue->front > queue->rear) {
            queue->front = 0;
            queue->rear = -1;
        }
        return value;
    } else {
        cout << "Queue is empty.\n";
        return -1;
    }
}

int peek(struct Queue* queue) {
    if (!isempty(queue)) {
        return queue->q[queue->front];
    } else {
        cout << "Queue is empty.\n";
        return -1;
    }
}

void print(struct Queue* queue) {
    if (isempty(queue)) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue Elements:\n";
        for (int i = queue->front; i <= queue->rear; i++) {
            cout << queue->q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int ch, data;

    cout << "Queue Operations:\n";
    cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
    queue.front = 0;
    queue.rear = -1;

    do {
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter Data to Insert: ";
                cin >> data;
                if (enqueue(&queue, data)) {
                    cout << "Element inserted successfully\n";
                }
                break;
            case 2:
                data = dequeue(&queue);
                if (data != -1) {
                    cout << "Deleted element is: " << data << "\n";
                }
                break;
            case 3:
                data = peek(&queue);
                if (data != -1) {
                    cout << "First element is: " << data << "\n";
                }
                break;
            case 4:
                print(&queue);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }
    } while (ch != 5);

    return 0;
}
