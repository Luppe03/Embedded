#include "EventLog.h"

EventLog* log_create(int capacity) {
    EventLog* log = new EventLog;
    log->size = 0;
    log->capacity = capacity;
    log->data = new Event[capacity];
    return log;
}

void log_destroy(EventLog* log) {
    delete[] log->data;
    delete log;
}

int log_size(const EventLog* log) {
    return log->size;
}

void log_append(EventLog* log, Event e) {
    if (log->size >= log->capacity) {
        int newCap = log->capacity * 2;
        Event* newData = new Event[newCap];
        for (int i = 0; i < log->size; ++i)
            newData[i] = log->data[i];
        delete[] log->data;
        log->data = newData;
        log->capacity = newCap;
    }
    log->data[log->size++] = e;
}

Event log_get(const EventLog* log, int index) {
    return log->data[index];
}

void log_set(EventLog* log, int index, Event e) {
    log->data[index] = e;
}
