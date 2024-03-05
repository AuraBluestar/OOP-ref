#include "Movie.h"
#include<iostream>
using namespace std;


Movie::Movie()
{
	IMDB = 0;
	lenght = 0;
	release_year = 0;
	present_year = 2023;
	for (int i = 0; i < 256; i++)
		name[i] =' ';
}

void Movie::set_name(const char nume[256])
{
	for (int i = 0; i < 256; i++)
		name[i] = nume[i];
}

void Movie::set_score(double scor)
{
	if (scor >= 1 && scor <= 10)
		IMDB = scor;
}

void Movie::set_year(int an)
{
	release_year = an;
}

void Movie::set_length(int lungime)
{
	lenght = lungime;
}

char *Movie::get_name()
{
	return(name);
}

double Movie::get_score()
{
	return(IMDB);
}

int Movie::get_year()
{
	return(release_year);
}

int Movie::get_length()
{
	return(lenght);
}

int Movie::get_years()
{
	return(present_year - release_year);
}

void Movie::set_years(int an)
{
	present_year = an;
}

