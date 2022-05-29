#pragma once
#include"tobj.h"
#include<iostream>
template<class Type>
class TTetrahedron : public tobj<Type>
{
protected:
	TVector<Type> FirstPoint, SecondPoint, ThirdPoint, FourthPoint;
	int dim;
	TString name;
public:
	TTetrahedron();
	TTetrahedron(const TTetrahedron<Type>& _tetr);
	~TTetrahedron();
	virtual void Print();
	virtual int GetDim();
	virtual void SetName(const TString& _name);
	virtual TString& GetName();
	virtual TVector<Type>& operator [] (int i);

};

template<class Type>
inline TTetrahedron<Type>::TTetrahedron()
{
	std::cout << "input dim of first point" << std::endl;
	std::cin >> FirstPoint;

	std::cout << std::endl;
	std::cout << "input dim of second point" << std::endl;
	std::cin >> SecondPoint;

	std::cout << std::endl;
	std::cout << "input dim of third point" << std::endl;
	std::cin >> ThirdPoint;

	std::cout << std::endl;
	std::cout << "input dim of fourth point" << std::endl;
	std::cin >> FourthPoint;

	dim = FirstPoint.GetLength();
	name.SetConstString("tetrahedron");
	if (FirstPoint.GetLength() != SecondPoint.GetLength() && ThirdPoint.GetLength() != FourthPoint.GetLength()) throw "dim of points isn't equals!";//compare 4 points; compare 1 with 2 and 3 with 4. Later we must to compare 1(or 2) with 3(or 4). If only one point hasn't equals dim, we will catch exception 
	else if (FirstPoint.GetLength() != FourthPoint.GetLength()) throw "dim of points isn't equals!";

}

template<class Type>
inline TTetrahedron<Type>::TTetrahedron(const TTetrahedron<Type>& _tetr)
{
	name = _tetr.name;
	FirstPoint = _tetr.FirstPoint;
	SecondPoint = _tetr.SecondPoint;
	ThirdPoint = _tetr.ThirdPoint;
	FourthPoint = _tetr.FourthPoint;
	dim = _tetr.dim;
}

template<class Type>
inline TTetrahedron<Type>::~TTetrahedron()
{
}

template<class Type>
inline void TTetrahedron<Type>::Print()
{
	std::cout << "name = " << name;
	std::cout << "dim =" << dim << std::endl;
	std::cout << "FirstVector = " << FirstPoint << std::endl;
	std::cout << "SecondVector = " << SecondPoint << std::endl;
	std::cout << "ThirdVector = " << ThirdPoint << std::endl;
	std::cout << "FourthVector = " << ThirdPoint << std::endl;
}

template<class Type>
inline int TTetrahedron<Type>::GetDim()
{
	return dim;
}

template<class Type>
inline void TTetrahedron<Type>::SetName(const TString& _name)
{
	name = _name;
}

template<class Type>
inline TString& TTetrahedron<Type>::GetName()
{
	return name;
}

template<class Type>
inline TVector<Type>& TTetrahedron<Type>::operator[](int i)
{
	switch (i)
	{
	case 0:
		return FirstPoint;
	case 1:
		return SecondPoint;
		break;
	case 2:
		return ThirdPoint;
		break;
	case 3:
		return FourthPoint;
		break;

	default:
		throw "undefined behavior. You trying to get unexist cell of array";
	}
}