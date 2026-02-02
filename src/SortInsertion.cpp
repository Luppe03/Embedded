#include "SortStrategy.h"

void insertionSort(EventLog* log) {
    for (int i = 1; i < log->size; ++i) {
        Event key = log->data[i];
        int j = i - 1;
        while (j >= 0 && log->data[j].timestamp > key.timestamp) {
            log->data[j + 1] = log->data[j];
            j--;
        }
        log->data[j + 1] = key;
    }
}
