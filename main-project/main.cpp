#include <iostream>
#include "internet_protocol.h"
#include "file_reader.h"

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

//=======
    cout << "Group: 24ох1д\n";
//>>>>>>> data
    return 0;
}
