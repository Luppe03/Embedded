#include "EventQueue.h"

EventQueue* queue_create(int capacity) {
    EventQueue* q = new EventQueue;
    q->buffer = new Event[capacity];
    q->capacity = capacity;
    q->head = q->tail = q->count = 0;
    return q;
}

void queue_destroy(EventQueue* q) {
    delete[] q->buffer;
    delete q;
}

bool queue_isEmpty(const EventQueue* q) {
    return q->count == 0;
}

bool queue_isFull(const EventQueue* q) {
    return q->count == q->capacity;
}

bool queue_enqueue(EventQueue* q, Event e) {
    if (queue_isFull(q)) return false;
    q->buffer[q->tail] = e;
    q->tail = (q->tail + 1) % q->capacity;
    q->count++;
    return true;
}

bool queue_dequeue(EventQueue* q, Event* out) {
    if (queue_isEmpty(q)) return false;
    *out = q->buffer[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->count--;
    return true;
}
