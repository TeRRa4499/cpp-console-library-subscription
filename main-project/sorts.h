#pragma once
#include <iostream>
#include "internet_protocol.h"


int calculateUsageTime(const times& begin, const times& end);


bool cmpTimeDesc(const internet_protocol* a, const internet_protocol* b);
bool cmpCombo(const internet_protocol* a, const internet_protocol* b);


void insertionSort(internet_protocol** arr, bool (*cmp)(const internet_protocol* a1, const internet_protocol* a2), int size);

void hoarSort(internet_protocol* arr[], bool (*cmp)(const internet_protocol* a1, const internet_protocol* a2), int left, int right);

