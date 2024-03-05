#pragma once
#include<iostream>
#include "Movie.h"
class MovieSeries
{
private:
	Movie* filme[16];
	int count;
public:
	void init();
	void add(Movie *m);
	void sort();
	void print();
};

