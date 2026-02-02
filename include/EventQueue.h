#pragma once
#include "Event.h"

struct EventQueue {
    Event* buffer;
    int capacity;
    int head;
    int tail;
    int count;
};

EventQueue* queue_create(int capacity);
void queue_destroy(EventQueue* q);

bool queue_isEmpty(const EventQueue* q);
bool queue_isFull(const EventQueue* q);

bool queue_enqueue(EventQueue* q, Event e);
bool queue_dequeue(EventQueue* q, Event* out);
