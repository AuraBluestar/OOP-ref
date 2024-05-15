#include<iostream>
#include <stdexcept>
class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};
	class Compare2 :public Compare
	{
	public: int CompareElements(void* e1, void* e2) 
	{
		if (e1 == e2)
			return 0;
		else
			if (e1 < e2)
				return -1;
			else
				return 1;
	};
	};

template<class T>

class ArrayIterator
{
private:

	int Current;
	T* elem;// mai adaugati si alte date si functii necesare pentru iterator

public:

	ArrayIterator()
	{
		Current = 0;
	}
	ArrayIterator& operator ++ ()
	{
		return Current++;
	}
	ArrayIterator& operator -- ()
	{
		return Current--;
	}
	bool operator= (ArrayIterator<T>&)
	{
		return true;
	}
	bool operator!=(ArrayIterator<T>&)
	{
		if (Current)
			return true;
		return false;
	}
	T* GetElement(){}

};

template<class T>
int compare(const T& a, const T& b)
{
	if (a == b)
		return 0;
	else
		if (a < b)
			return -1;
		else
			return 1;
};

template<class T>

class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:

	Array()
	{
		// Lista nu e alocata, Capacity si Size = 0
		Capacity = 0;
		Size = 0;
		List = nullptr;
	}

	~Array() 
	{
		// destructor
		if (List != nullptr)
		{
			for (int i = 0; i < Size; i++)
				delete List[i];
			delete[] List;
		}
		Capacity = 0;
		Size = 0;
	}

	Array(int capacity)
	{ // Lista e alocata cu 'capacity' elemente
		Capacity = capacity;
		Size = 0;
		List = new T*;
	}

	Array(const Array<T>& otherArray)
	{ // constructor de copiere
		Array List = new Array;
		Capacity = GetCapacity(otherArray);
		Size = GetSize(otherArray);
		for (int i = 0; i < Size; i++) {
			List [i] = otherArray.List[i];
		}

	}

	T& operator[](int index)
	{
		if (index < 0 || index >= Size)
		{
			throw std::out_of_range("Index out of range");
		}

		return *(List[index]);
	}

	const Array<T>& operator+=(const T& newElem)
	{ // adauga un element de tipul T la sfarsitul listei si returneaza this
		try {
			if (Size + 1 < Capacity)
			{
				Size++;
				List[Size - 1] = new T(newElem);
			}
		}
		catch (const T& newElem)
		{
			Capacity *= 2;
			T** newList = new T*;
			for (int i = 0; i < Size; i++)
				newList[i] = List[i];
			for (int i = 0; i < Size; i++)
				delete List[i];
			Size++;
			newList[Size - 1] = newElem;
			for (int i = 0; i < Size; i++)
				List[i] = newList[i];
		}
		return(*this);
	}

	const Array<T>& Insert(int index, const T& newElem) {
		// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
		try 
		{
			if (index > 0 && index < Size) 
			{
				Size++;
				T** newList = new T*;
				for (int i = 0; i < index; i++)
					newList[i] = List[i];
				newList[index] = newElem;
				for (int i = index; i < Size; i++)
					newList[i] = List[i-1];
				for (int i = 0; i < Size; i++)
					delete List[i];
				for (int i = 0; i < Size; i++)
					List[i] = newList[i];

			}
		}
		catch(int index)
		{
			if(Size < index)
				throw std::out_of_range("Index out of range");
			else 
				throw std::out_of_range("Index does not exist");
		}
		return(*this);
	}
	
	const Array<T>& Insert(int index, const Array<T> otherArray)
	{// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
		T** newList = nullptr;
		int j = 0;
			for (int i = index; i < Size; i++)
			{
				newList[j] = List[i];
				j++;
			}
		int nr=0;
		for(int i= index; i<Size*2; i++)
			for (int j = 0; j < sizeof(otherArray); j++) 
			{
				List[i] = otherArray[j];
				nr++;
				Size++;
			}
		for (int i = index + nr; i < Size; i++)
			List[i] = newList[i - index - nr];

	}

	const Array<T>& Delete(int index) 
	{ // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
		try {
			if (List[index] < Size)
				for (int i = index; i < Size - 1; i++)
					List[i] = List[i+1];
			Size--;
		}
		catch(int a)
		{
			throw std::out_of_range("Index out of range");
		}
	}

	bool operator=(const Array<T>& otherArray) 
	{
		for (int i = 0; i < Size; i++)
			if (List[i] != otherArray[i])
				return false;
		return true;
	}

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	void Sort() 
	{ // sorteaza folosind comparatia intre elementele din T
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (List[i] > List[j])
				{
					T* k = List[i];
					List[i] = List[j];
					List[j] = k;
				}
	}

	void Sort(int(*compare)(const T&, const T&))
	{ // sorteaza folosind o functie de comparatie
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (compare(List[i], List[j])>0)
				{
					T* k = List[i];
					List[i] = List[j];
					List[j] = k;
				}
	}

	void Sort(Compare* comparator) 
	{ // sorteaza folosind un obiect de comparatie
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (Compare::CompareElements(List[i], List[j])>0)
				{
					T* k = List[i];
					List[i] = List[j];
					List[j] = k;
				}
		
	}


	int BinarySearch(const T& elem)
	{ // cauta un element folosind binary search in Array
		int st = 0, dr = Size - 1;
		while (st <= dr)
		{
			int m = (st + dr) / 2;
			if (*List[m] == elem)
				return m;
			else if (*List[m] < elem)
				st = m + 1;
			else dr = m - 1;
		}
		return -1;
	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{//  cauta un element folosind binary search si o functie de comparatie
		int st = 0, dr = Size - 1, cmp = -10;
		while (st <= dr)
		{
			int m = (st + dr) / 2;
			cmp = compare(*List[m], elem);

			if (cmp == 0)
				return m;
			else if (cmp < 0)
				st = m + 1;
			else dr = m - 1;
		}
		return -1;
	}

	int BinarySearch(const T& elem, Compare* comparator)
	{//  cauta un element folosind binary search si un comparator
		int st = 0, dr = Size - 1, cmp = -10;
		while (st <= dr)
		{
			int m = (st + dr) / 2;
			cmp = comparator->CompareElements(*List[m], elem);

			if (cmp == 0)
				return m;
			else if (cmp < 0)
				st = m + 1;
			else dr = m - 1;
		}
		return -1;
	}



	int Find(const T& elem)
	{ // cauta un element in Array
		int ok = -1;
		for (int i = 0; i < Size; i++)
			if (List[i] == elem) 
				ok = i;
		return ok;
	}

	int Find(const T& elem, int(*compare)(const T&, const T&))
	{//  cauta un element folosind o functie de comparatie
		for (int i = 0; i < Size; i++)
			if (compare(List[i], elem)==0)
				return i;
		return 0;
		
	}

	int Find(const T& elem, Compare* comparator)
	{//  cauta un element folosind un comparator
		for (int i = 0; i < Size; i++)
			if (Compare::CompareElements(List[i], elem)==0)
				return i;
		return 0;
	}


	int GetSize()
	{
		return Size;
	}

	int GetCapacity()
	{
		return Capacity;
	}

	ArrayIterator<T> GetBeginIterator()
	{
		return *List[0];
	}

	ArrayIterator<T> GetEndIterator()
	{
		return *List[Size - 1];
	}
};