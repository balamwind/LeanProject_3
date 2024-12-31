#pragma once
#include <algorithm>


//템플릿을 사용하는 이유는 이런 확장 컨테이너 등을 매번 쓸 타입마다 일일이 같은 기능을 타입만 바꿔 새로 만들어서 쓰는 것이 매우 비효율적이기 때문
//어떤 타입이 올지 모르지만 일단 T로 가정을 해 변수를 생성할 수 있음
//실제 컴파일 과정에서 코드에서 사용된 타입으로 치환해 해당 클래스를 만들어 문제가 없게 만듦
//예를 들어 SimpleVector<int>를 썼으면 컴파일 과정에서 T를 int로 치환해 SimpleVector<int> 클래스를 새로 만들어줌
//컴파일 과정 중 최적화로 인해 구현을 .cpp에서 하는게 아닌 .h파일에서 해야한다
// 
//재할당 그림은 ReadMe에 있습니다
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

	//복사 생성자
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
			throw std::out_of_range("접근하려는 인자가 배열의 범위를 벗어났습니다.");

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