#pragma once
#include <algorithm>


//���ø��� ����ϴ� ������ �̷� Ȯ�� �����̳� ���� �Ź� �� Ÿ�Ը��� ������ ���� ����� Ÿ�Ը� �ٲ� ���� ���� ���� ���� �ſ� ��ȿ�����̱� ����
//� Ÿ���� ���� ������ �ϴ� T�� ������ �� ������ ������ �� ����
//���� ������ �������� �ڵ忡�� ���� Ÿ������ ġȯ�� �ش� Ŭ������ ����� ������ ���� ����
//���� ��� SimpleVector<int>�� ������ ������ �������� T�� int�� ġȯ�� SimpleVector<int> Ŭ������ ���� �������
//������ ���� �� ����ȭ�� ���� ������ .cpp���� �ϴ°� �ƴ� .h���Ͽ��� �ؾ��Ѵ�
// 
//���Ҵ� �׸��� ReadMe�� �ֽ��ϴ�
template<typename T>
class SimpleVector
{
protected:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	SimpleVector() : SimpleVector(10) {}

	SimpleVector(int size)
	{
		currentSize = 0;
		currentCapacity = size;
		data = new T[currentCapacity];
	}

	//���� ������
	SimpleVector(const SimpleVector& obj)
	{
		currentSize = obj.currentSize;
		currentCapacity = obj.currentCapacity;

		obj.resize(obj.currentCapacity);
	}

	~SimpleVector()
	{
		delete[] data;
	}

	T& operator[](int index)
	{
		if (index < 0 || index >= currentSize)
			throw std::out_of_range("�����Ϸ��� ���ڰ� �迭�� ������ ������ϴ�.");

		return data[index];
	}


public:
	void push_back(const T& value)
	{
		if (currentSize == currentCapacity)
		{
			currentCapacity += 5;
			resize(currentCapacity);
		}

		data[currentSize++] = value;
	}

	void pop_back()
	{
		if (currentSize > 0)
			currentSize--;
	}

	void sortData()
	{
		sort(data, data + currentSize);
	}

	inline int size() { return currentSize; }
	inline int capacity() { return currentCapacity; }

private:
	void resize(int newCapacity)
	{
		if (newCapacity <= currentSize)
			return;

		T* temp = new T[newCapacity];
		for (int i = 0; i < currentSize; i++)
			temp[i] = data[i];

		delete[] data;

		data = temp;
	}
};