#ifndef FILTER_H
#define FILTER_H
#include "internet_protocol.h"

internet_protocol** filter(internet_protocol* array[], int size, bool (*check)(internet_protocol* element), int& result_size);


bool check_services_for_skype(internet_protocol* element);

bool check_services_after_eight(internet_protocol* element);

#endif
