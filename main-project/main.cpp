#include <iostream>
#include "internet_protocol.h"
#include "file_reader.h"
#include "filter.h"
#include "sorts.h"

using namespace std;
void output(internet_protocol* subscriptions) {
	cout << subscriptions->begin.hours << ":" << subscriptions->begin.minutes << ":" << subscriptions->begin.seconds << " " << subscriptions->end.hours << ":" << subscriptions->end.minutes << ":" << subscriptions->end.seconds << " " << subscriptions->byterecived << " " << subscriptions->bytesend << " " << subscriptions->fileway << "\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #4. GIT\n";
    cout << "Variant #5. Internet Protocol\n";	
    cout << "Author: Daniil Kazakov\n";
//<<<<<<< HEAD
	cout << "Group: 24ох1д\n";

	internet_protocol* subscriptions[MAX_FILE_ROWS_COUNT];
	int size;

	read("data.txt", subscriptions, size);
	cout << "*****   *****\n\n";

	for (int i = 0; i < size; i++) output(subscriptions[i]);

	cout << "***** by Time  *****\n\n";

	insertionSort(subscriptions, cmpTimeDesc, size);

	for (int i = 0; i < size; i++)
	{
		//cout << calculateUsageTime(subscriptions[i]->begin, subscriptions[i]->end) << ": ";
		output(subscriptions[i]);
	}

	cout << "***** byCombo  *****\n\n";

	hoarSort(subscriptions, cmpCombo, 0, size - 1);

	for (int i = 0; i < size; i++) 
	{
		//cout << calculateUsageTime(subscriptions[i]->begin, subscriptions[i]->end) << ": ";
		output(subscriptions[i]);
	}

	
	int new_size;

	internet_protocol** filteredSkype = filter(subscriptions, size, check_services_for_skype, new_size);
	cout << "***** filteredSkype  *****\n\n";
	for (int i = 0; i < new_size; i++) output(filteredSkype[i]);

	delete[] filteredSkype;

	internet_protocol** filteredEight = filter(subscriptions, size, check_services_after_eight, new_size);
	cout << "***** filteredEight  *****\n\n";
	for (int i = 0; i < new_size; i++) output(filteredEight[i]);

	delete[] filteredEight;
	
	for (int i = 0; i < size; i++)
{
	delete subscriptions[i];
}

	//bool(*check_function)(internet_protocol*) = NULL;
   
	return 0;
}
