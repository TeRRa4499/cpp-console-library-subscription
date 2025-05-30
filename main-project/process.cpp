#include "processing.h"

long time_to_seconds(struct times t) {
    return t.hours * 3600L + t.minutes * 60L + t.seconds;
}

int process( internet_protocol* protocols[], int size, const char* program_name) {
    long total_seconds = 0;

    for (int i = 0; i < size; ++i) {
        if (strcmp(protocols[i]->fileway, program_name) == 0) {
            long begin_sec = time_to_seconds(protocols[i]->begin);
            long end_sec = time_to_seconds(protocols[i]->end);
            total_seconds += (end_sec - begin_sec);
        }
    }
    return total_seconds;
}