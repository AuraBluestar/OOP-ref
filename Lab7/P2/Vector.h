#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class Vector
{
private:
	std::vector<T> vect;
public:
	Vector();
	~Vector();
	Vector(const Vector& other);
	Vector(Vector&& other);
	void insert(size_t index, int element);
	void remove(size_t index);
	T& operator[](std::size_t index);
	void sort(int (*function)(int, int));
	void print();
};

template<typename T>
inline Vector<T>::Vector()
{
	vect = {};
}

template<typename T>
inline Vector<T>::~Vector()
{
	vect.clear();
}

template<typename T>
inline Vector<T>::Vector(const Vector& other)
{
	this->vect = other.vect;
}

template<typename T>
inline Vector<T>::Vector(Vector&& other)
{
	this->vect = std::move(other.vect);
}

template<typename T>
inline void Vector<T>::insert(size_t index, int element)
{
	if (index <= vect.size() && index >= 0)
		vect.insert(vect.begin() + index, element);
}

template<typename T>
inline void Vector<T>::remove(size_t index)
{
	if (index < vect.size() && index >= 0)
		vect.erase(vect.begin() + index);
}

template<typename T>
inline T& Vector<T>::operator[](std::size_t index)
{
	return vect[index];
}

template<typename T>
inline void Vector<T>::sort(int(*function)(int, int))
{
	for (int i = 0; i < vect.size() - 1; i++)
	{
		if(function==nullptr)
		{
			if (vect[i] > vect[i + 1])
			{
				std::swap(vect[i], vect[i + 1]);
				i--;
			}
		}
		else
		{
			if (function(vect[i], vect[i + 1]) == 1)
			{
				std::swap(vect[i], vect[i + 1]);
				i--;
			}
		}
	}
}

template<typename T>
inline void Vector<T>::print()
{
	for (int i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
}


