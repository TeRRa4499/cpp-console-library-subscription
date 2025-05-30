#include "sorts.h"

int calculateUsageTime(const times& begin, const times& end) 
{
    int begin_sec = begin.hours * 3600 + begin.minutes * 60 + begin.seconds;
    int end_sec = end.hours * 3600 + end.minutes * 60 + end.seconds;
    return end_sec - begin_sec;
}


bool cmpCombo(const internet_protocol* a, const internet_protocol* b) {

    if (!a || !b) return false;

    int name_cmp = strcmp(a->fileway, b->fileway);
    if (name_cmp != 0) {
        return name_cmp < 0;
    }

    return (a->byterecived + a->bytesend) > (b->byterecived + b->bytesend);
}



bool cmpTimeDesc(const internet_protocol* a, const internet_protocol* b)
{
    if (!a || !b) return false;

    int time_a = calculateUsageTime(a->begin, a->end);
    int time_b = calculateUsageTime(b->begin, b->end);

    return time_a > time_b;
}


void insertionSort(internet_protocol** arr, bool (*cmp)(const internet_protocol* a1, const internet_protocol* a2), int size) {
    for (int i = 1; i < size; ++i) {
        internet_protocol* key = arr[i];
        int j = i - 1;

        // Сдвигаем элементы больше текущего влево
        while (j >= 0 && cmp(key, arr[j])) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

void hoarSort(internet_protocol* arr[], bool (*cmp)(const internet_protocol* a1, const internet_protocol* a2), int left, int right)
{
   if (left >= right) return;

    internet_protocol* pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (cmp(arr[i], pivot)) i++;  // arr[i] < pivot
        while (cmp(pivot, arr[j])) j--;  // arr[j] > pivot

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    hoarSort(arr, cmp, left, j);
    hoarSort(arr, cmp, i, right);
}


