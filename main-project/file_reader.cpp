#include "file_reader.h"
#include "constants.h"
#include "internet_protocol.h"

#include <fstream>
#include <cstring>

times convert(char* str)
{
    times result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hours = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.minutes = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.seconds = atoi(str_number);
    return result;
}
// 09:00:00
void read(const char* file_name, internet_protocol* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            internet_protocol* item = new internet_protocol;
            file >> tmp_buffer;
            item->begin = convert(tmp_buffer);
            file >> tmp_buffer;
            item->end = convert(tmp_buffer);
            file >> item->byterecived;
            file >> item->bytesend;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->fileway, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}