#pragma once

template <typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	void addItem(T item);
    void addItems(T item[], int size);
	bool removeitem(T item);
	void sortItems();
	T getItem(int index);
	int getLength();

private:
	T* m_item;
	int m_length;

};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
    m_length = 0;
    m_item = nullptr;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
  
}

template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	T* tempArray = new T [getLength() + 1];
	//Copy the values from the old array to the new array
	for (int i = 0; i < getLength(); i++)
	{
        tempArray[i] = m_item[i];
	}

	//Set the last value in the new array to be the actor we want to add
    tempArray[getLength()] = item;

    delete[] m_item;

	//Set old array to hold the values of the new array
	m_item = tempArray;
	m_length++;
}

template<typename T>
inline void DynamicArray<T>::addItems(T item[], int size)
{
    for (int i = 0; i < size; i++)
        addItem(item[i]);
}

template<typename T>
inline bool DynamicArray<T>::removeitem(T item)
{
    //Check to see if the actor was null
    if (!item || getLength() <= 0)
        return false;

    bool itemRemoved = false;
    //Create a new array with a size one less than our old array
    T* tempArray = new T [getLength() - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < getLength(); i++)
    {
        if (item != m_item[i] || itemRemoved)
        {
            tempArray[j] = m_item[i];
            j++;
        }
        else 
        {
            itemRemoved = true;
        }
    }

    //Set the old array to the new array
    if (itemRemoved)
    {
        delete[] m_item;
        m_item = tempArray;
        m_length--;
    }
    //Return whether or not the removal was successful
    return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
    int j = 0;
    T key;

    for (int i = 1; i < getLength(); i++)
    {
        key = m_item[i];
        j = i - 1;

        while (j >= 0 && m_item[j] > key)
        {
            m_item[j + 1] = m_item[j];
            j--;
        }

        m_item[j + 1] = key;
    }
}

template<typename T>
inline T DynamicArray<T>::getItem(int index)
{
    //Return false if the index is out of bounds
    if (index < 0 || index >= getLength())
        return T();

    return m_item[index];
}

template<typename T>
inline int DynamicArray<T>::getLength()
{
	return m_length;
}
