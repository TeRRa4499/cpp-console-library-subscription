#include "filter.h"
#include <cstring>
#include <string>
#include <iostream>

internet_protocol** filter(internet_protocol* array[], int size, bool (*check)(internet_protocol* element), int& result_size)
{
	internet_protocol** result = new internet_protocol * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_services_for_skype(internet_protocol* element)
{
	//long i,answw;
	//bool answ;
	//string s1 = "Skype.exe", s2=element->fileway;
	///////////long j;
	////for (i = 0; i <= element->fileway.size(); i++) {if (element->fileway[i]==) }
	////while (i <= element->fileway.size()) { if (element->fileway[i] == '\'	) {} i++;}
	//answw = s2.find(s1);
	//if (answw > 0) { answ = 1; }
	//else { answ = 0; }
	////////j = i;
	return strstr(element->fileway, "Skype.exe");//strcmp(element->fileway, s1) == 0;///?  !=
}

bool check_services_after_eight(internet_protocol* element)
{
	if (element->begin.hours >= 8) { return 1;}
	else { return 0; }
	//return element->start.month == 3 && element->start.year == 2015;
}
