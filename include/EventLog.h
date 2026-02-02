#pragma once
#include "Event.h"

struct EventLog {
    Event* data;
    int size;
    int capacity;
};

EventLog* log_create(int capacity);
void log_destroy(EventLog* log);

int  log_size(const EventLog* log);
void log_append(EventLog* log, Event e);

Event log_get(const EventLog* log, int index);
void  log_set(EventLog* log, int index, Event e);
