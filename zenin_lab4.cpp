#include <iostream>
using namespace std;

struct Song {
    string title;
    int priority;
};

Song karaoke_queue[100];

int front = -1;
int rear = -1;
int max_queue = 10;

bool isFull() {
    return ((rear + 1) % max_queue == front);
}

bool isEmpty() {
    return (front == -1);
}

string enqueue(string song, int priority) {
    if (isFull()) {
        return "The queue is full. Try again later";
    }

    Song newSong = {song, priority};

    if (isEmpty()) {
        front = rear = 0;
        karaoke_queue[rear] = newSong;
    } else {
        
        int i = rear;
        int next = (rear + 1) % max_queue;
        while (i != (front - 1 + max_queue) % max_queue &&
               karaoke_queue[i].priority < priority) {
            karaoke_queue[(i + 1) % max_queue] = karaoke_queue[i];
            i = (i - 1 + max_queue) % max_queue;
        }
        karaoke_queue[(i + 1) % max_queue] = newSong;
        rear = next;
    }

    return "a song has been added in the queue";
}

string dequeue() {
    if (isEmpty()) {
        return "There is no song in queue. Try adding first";
    }

    string song = karaoke_queue[front].title;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % max_queue;
    }

    return song;
}

int main() {
    cout << enqueue("Dilaw", 1) << endl;
    cout << enqueue("Sining", 3) << endl;
    cout << enqueue("Marilag", 2) << endl;
    cout << enqueue("Palagi", 5) << endl;
    cout << enqueue("Karera", 4) << endl;

    // Show queue by dequeuing:
    while (!isEmpty()) {
        cout << "Now playing: " << dequeue() << endl;
    }

    return 0;
}
