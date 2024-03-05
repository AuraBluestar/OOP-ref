#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Movie
{
private:
	char name[256];
	int release_year, lenght, present_year;
	double IMDB;
public:
	Movie();
	void set_name(const char nume[256]);
	void set_score(double scor);
	void set_year(int an);
	void set_length(int lungime);
	char * get_name();
	double get_score();
	int get_year();
	int get_length();
	int get_years();
	void set_years(int an);
};

