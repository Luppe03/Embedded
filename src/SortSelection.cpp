#include "SortStrategy.h"

void selectionSort(EventLog* log) {
    for (int i = 0; i < log->size - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < log->size; ++j)
            if (log->data[j].timestamp < log->data[minIdx].timestamp)
                minIdx = j;

        Event tmp = log->data[i];
        log->data[i] = log->data[minIdx];
        log->data[minIdx] = tmp;
    }
}
