#include "MovieSeries.h"

void MovieSeries::init()
{
	count = 0;
}

void MovieSeries::add(Movie* m)
{
	filme[count] = m;
	count++;
}

void MovieSeries::sort()
{
	for(int i =0; i<count-2; i++)
		if (filme[i]->get_years() < filme[i + 1]->get_years())
		{
			swap(filme[i], filme[i + 1]);
			i--;
		}
}

void MovieSeries::print()
{
	for (int i = 0; i < count; i++)
		cout << "Nume: " << filme[i]->get_name()<< "; Lungime:" << filme[i]->get_length() << " minute; An: " << filme[i]->get_year ()<< "; Ani de la lansare: " << filme[i]->get_years()<<"; IMDB: "<<filme[i]->get_score()<<endl;
}
