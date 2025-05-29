#include <iostream>
#include "internet_protocol.h"
#include "file_reader.h"
#include "filter.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #4. GIT\n";
    cout << "Variant #5. Internet Protocol\n";	
    cout << "Author: Daniil Kazakov\n";
//<<<<<<< HEAD

	internet_protocol* subscriptions[MAX_FILE_ROWS_COUNT];
	int size;

	read("data.txt", subscriptions, size);
	cout << "*****   *****\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << subscriptions[i]->begin.hours << ":" << subscriptions[i]->begin.minutes << ":" << subscriptions[i]->begin.seconds << " " << subscriptions[i]->end.hours << ":" << subscriptions[i]->end.minutes << ":" << subscriptions[i]->end.seconds << " " << subscriptions[i]->byterecived << " " << subscriptions[i]->bytesend << " " << subscriptions[i]->fileway << "\n";
	}
	int new_size;

	internet_protocol** filteredSkype = filter(subscriptions, size, check_services_for_skype, new_size);
	cout << "***** filteredSkype  *****\n\n";
	for (int i = 0; i < new_size; i++)
	{
		cout << filteredSkype[i]->begin.hours << ":" << filteredSkype[i]->begin.minutes << ":" << filteredSkype[i]->begin.seconds << " " << filteredSkype[i]->end.hours << ":" << filteredSkype[i]->end.minutes << ":" << filteredSkype[i]->end.seconds << " " << filteredSkype[i]->byterecived << " " << filteredSkype[i]->bytesend << " " << filteredSkype[i]->fileway << "\n";
	}
	delete[] filteredSkype;

	internet_protocol** filteredEight = filter(subscriptions, size, check_services_after_eight, new_size);
	cout << "***** filteredEight  *****\n\n";
	for (int i = 0; i < new_size; i++)
	{
		cout << filteredEight[i]->begin.hours << ":" << filteredEight[i]->begin.minutes << ":" << filteredEight[i]->begin.seconds << " " << filteredEight[i]->end.hours << ":" << filteredEight[i]->end.minutes << ":" << filteredEight[i]->end.seconds << " " << filteredEight[i]->byterecived << " " << filteredEight[i]->bytesend << " " << filteredEight[i]->fileway << "\n";
	}
	delete[] filteredEight;

    cout << "Group: 24ох1д\n";

	for (int i = 0; i < size; i++)
{
	delete subscriptions[i];
}

	//bool(*check_function)(internet_protocol*) = NULL;
   
	return 0;
}
