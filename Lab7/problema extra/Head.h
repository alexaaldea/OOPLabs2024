#pragma once

template <class T>
class Vector
{
private:
	T* v;
	int count;
public:
	Vector()
	{
		int i;
		/*int i;
		this->count = count;
		v = new T[count + 1];
		for (i = 0; i < count; i++)
			v[i] = value[i];*/
		this->count = 0;
		this->v = new T[100];
		for (i = 0; i < 100; i++)
			v[i] = 0;
	}
	~Vector()
	{
		delete[] v;
	}
	Vector(const Vector& ex)
	{
		int i;
		this->count = ex.count;
		this->v = new T[100];
		for (i = 0; i < count; i++)
			v[i] = ex.v[i];
	}
	Vector(const Vector&& ex)
	{
		///this->v = new T[100];
		this->count = ex.count;
		char* copy = ex.v;
		ex.v = nullptr;
		this->v = copy;
		///this->v = NULL;
		///this->count = 0;
	}
	Vector(T* value)
	{
		int i;
		this->count = sizeof(value);
		v = new T[100];
		for (i = 0; i < count; i++)
			v[i] = value[i];
	}
	int operator[](int index)
	{
		return this->v[index];
	}
	void insert(int index, T element)
	{
		/*int i;
		if (index > 0 && index < count)
		{
			for (i = count; i > index; i--)
				v[i] = v[i - 1];
			v[index] = element;
			count++;
		}*/
		this->v[count] = element;
		if (index > count)
			this->count = index;
	}
	void remove(int index)
	{
		/*for (int i = index; i < count - 1; i++) {
			v[i] = v[i + 1];
		}
		count--;*/
		int i;
		for (i = index; i < count; i++)
			v[i] = v[i + 1];
		this->count--;
	}
	void sort(int (*callback)(T, T))
	{
		if (callback != nullptr)
		{
			int i, j;
			T aux;
			for (i = 0; i < count - 1; i++)
				for (j = i + 1; j < count; j++)
					if (callback(this->v[i], this->v[j]) == 1)
					{
						aux = v[i];
						v[i] = v[j];
						v[j] = aux;
					}
		}
	}
	void print()
	{
		int i;
		for (i = 0; i < count; i++)
			printf("%d ", v[i]);
	}
};