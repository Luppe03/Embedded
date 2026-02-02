#include <iostream>
#include <sstream>
#include <cstdlib>

#include "EventQueue.h"
#include "EventLog.h"
#include "SortStrategy.h"

extern void insertionSort(EventLog*);
extern void selectionSort(EventLog*);

static int globalTimestamp = 0;

Event generateEvent() {
    Event e;
    e.timestamp = globalTimestamp++;
    e.sensorId = rand() % 4;
    e.type = static_cast<EventType>(rand() % 3);
    e.value = rand() % 100;
    return e;
}

int main() {
    EventQueue* queue = queue_create(5);
    EventLog* log = log_create(8);

    std::cout << "Embedded Event Logger (type 'help')\n";

    std::string line;
    while (true) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;

        if (cmd == "tick") {
            int n; ss >> n;
            for (int i = 0; i < n; ++i) {
                queue_enqueue(queue, generateEvent());
                Event e;
                if (queue_dequeue(queue, &e))
                    log_append(log, e);
            }
        }
        else if (cmd == "print") {
            for (int i = 0; i < log->size; ++i) {
                Event e = log->data[i];
                std::cout << e.timestamp
                          << " sensor=" << e.sensorId
                          << " value=" << e.value << "\n";
            }
        }
        else if (cmd == "sort") {
            std::string which; ss >> which;
            SortFn fn = nullptr;
            if (which == "insertion") fn = insertionSort;
            if (which == "selection") fn = selectionSort;
            if (fn) fn(log);
        }
        else if (cmd == "find") {
            int id; ss >> id;
            for (int i = 0; i < log->size; ++i)
                if (log->data[i].sensorId == id)
                    std::cout << log->data[i].timestamp << "\n";
        }
        else if (cmd == "help") {
            std::cout << "Commands:\n"
                      << " tick <n>\n print\n sort insertion|selection\n"
                      << " find <sensorId>\n exit\n";
        }
        else if (cmd == "exit") {
            break;
        }
    }

    log_destroy(log);
    queue_destroy(queue);
    return 0;
}
