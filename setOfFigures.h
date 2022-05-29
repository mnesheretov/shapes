#pragma once
#include"tobj.h"
#include"point.h"
#include"vector.h"
#include"complex.h"
#include "line.h"
#include"square.h"
#include"circle.h"
#include"triangle.h"

template<class Type>
class TSet
{
public:
	int count;
	tobj<Type>** data;
	TSet();
	~TSet();
	void SetObj(tobj<Type>* _obj);

	void ToPrint();
	void ToPrint(int _numb);
	void ToPlot(int _numb);
	void DeleteLastObj();
	int GetCount();
};

template<class Type>
inline TSet<Type>::TSet()
{
	data = 0;
	count = 0;
}

template<class Type>
inline TSet<Type>::~TSet()
{
	delete[] data;
	data = 0;
}

template<class Type>
inline void TSet<Type>::SetObj(tobj<Type>* _obj)
{
	if (data == 0)
	{
		data = new tobj<Type>*[1];
		count++;
		data[0] = _obj;
	}
	else
	{
		tobj<Type>** temp = new tobj<Type>*[count + 1];

		for (int q = 0; q < count; q++)
			temp[q] = data[q];

		delete[] data;
		data = 0;

		data = new tobj<Type>*[count + 1];

		for (int q = 0; q < count; q++)
			data[q] = temp[q];

		data[count] = _obj;
		count++;

		delete[] temp;
		temp = 0;

	}
}


template<class Type>
inline void TSet<Type>::DeleteLastObj()
{
	if (data == 0)throw"array is empty";
	else if (data != 0)
	{
		tobj<Type>** temp = new tobj<Type>*[count - 1];
		for (int q = 0; q < count - 1; q++)
			temp[q] = data[q];

		delete[] data;
		data = 0;

		count--;
		data = new tobj<Type>*[count];
		for (int q = 0; q < count; q++)
			data[q] = temp[q];
	}
}

template<class Type>
inline int TSet<Type>::GetCount()
{
	return count;
}
