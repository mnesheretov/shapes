#pragma once
#include"point.h"
#include"vector.h"
#include"tobj.h"

template<class Type>
class TLine : public tobj<Type>
{
protected:
	int dim;
	TVector<Type> FirstPoint, SecondPoint;
	TString name;
public:
	TLine();
	~TLine();
	TLine(const TLine<Type>& _line);
	virtual int GetDim();
	virtual void SetName(const TString& _name);
	virtual TString& GetName();
	virtual TVector<Type>& operator [] (int i);
};

template<class Type>
inline TLine<Type>::TLine()
{
	std::cout << "input dim of first point" << std::endl;
	std::cin >> FirstPoint;

	std::cout << std::endl;

	std::cout << "input dim of second point" << std::endl;
	std::cin >> SecondPoint;

	dim = FirstPoint.GetLength();
	name.SetConstString("line");
	if (FirstPoint.GetLength() != SecondPoint.GetLength()) throw "dim of 1-st point != dim of 2-d point !!!";

}

template<class Type>
inline TLine<Type>::~TLine()
{

}

template<class Type>
inline TLine<Type>::TLine(const TLine<Type>& _line)
{
	FirstPoint = _line.FirstPoint;
	SecondPoint = _line.SecondPoint;
	dim = _line.dim;
	name = _line.name;
}


template<class Type>
inline int TLine<Type>::GetDim()
{
	return 0;
}

template<class Type>
inline void TLine<Type>::SetName(const TString& _name)
{
	name = _name;
}

template<class Type>
inline TString& TLine<Type>::GetName()
{
	return name;
}

template<class Type>
inline TVector<Type>& TLine<Type>::operator[](int i)
{
	switch (i)
	{
	case 0:
		return FirstPoint;
	case 1:
		return SecondPoint;
		break;

	default:
		throw "undefined behavior. You trying to get unexist cell of array";
	}
}