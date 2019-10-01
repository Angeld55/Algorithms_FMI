#pragma once

#include <iostream>

class UnionFind //(for numbers from 1 to n)
{
	int* arr;
	int len;
	void CopyFrom(const UnionFind& other);
	void Free();
public:
	UnionFind(int count);
	UnionFind(const UnionFind& other);
	UnionFind& operator=(const UnionFind& other);
	~UnionFind();
	int GetRoot(int el);
	bool AreInOneSet(int el1, int el2);
	void Union(int el1, int el2);
};

inline void UnionFind::CopyFrom(const UnionFind& other)
{
	arr = new int[other.len];
	for (int i = 0; i < len; ++i)
		arr[i] = other.arr[i];
	len = other.len;
}

void UnionFind::Free()
{
	delete[] arr;
}


UnionFind::UnionFind(int count)
{
	arr = new int[count];
	for (int i = 0; i<count; i++)
		arr[i] = i;
}

UnionFind::UnionFind(const UnionFind& other)
{
	CopyFrom(other);
}

inline UnionFind& UnionFind::operator=(const UnionFind& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

UnionFind::~UnionFind()
{
	Free();
}

int UnionFind::GetRoot(int el)
{
	while (el != arr[el])
		el = arr[el];
	return el;

}
bool UnionFind::AreInOneSet(int el1, int el2)
{
	return GetRoot(el1) == GetRoot(el2);
}
void UnionFind::Union(int el1, int el2)
{
	int r = GetRoot(el1);
	int r2 = GetRoot(el2);
	arr[r] = r2;
}
