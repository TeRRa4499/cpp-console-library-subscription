#ifndef INTERNET_PROTOCOL_H
#define INTERNET_PROTOCOL_H
#include <string>
#include "constants.h"
using namespace std;
struct times
{
    int hours;
    int minutes;
    int seconds;
};
struct internet_protocol
{
    times begin;
    times end;
    unsigned long byterecived;
    unsigned long bytesend;
    char fileway[MAX_STRING_SIZE];
};

#endif