#pragma once

enum class EventType {
    TEMP,
    BUTTON,
    MOTION
};

struct Event {
    int timestamp;
    int sensorId;
    EventType type;
    int value;
};
