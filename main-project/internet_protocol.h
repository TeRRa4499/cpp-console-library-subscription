#ifndef INTERNET_PROTOCOL_H
#define INTERNET_PROTOCOL_H
#include <string>
#include "constants.h"

struct time
{
    int hours;
    int minutes;
    int seconds;
};
struct internet_protocol
{
    time begin;
    time end;
    unsigned long bytebeg;
    unsigned long byteend;
    string fileway;
};

#endif