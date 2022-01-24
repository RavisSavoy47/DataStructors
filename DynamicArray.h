#pragma once

template <typename T>
class DynamicArray
{
public:
	DynamicArray() {};
	~DynamicArray() {};

	void addItem(T* item);
	bool removeitem(T* item);
	void sortItems();
	T* getItem(int index);
	int getLength();

private:
	T** m_items;
	int m_length;

};

template<typename T>
inline void DynamicArray<T>::addItem(T* item)
{
	T** tempItem = new T* [m_items + 1];
	//Copy the values from the old array to the new array
	for (int i = 0; i < m_length; i++)
	{
		tempItem[i] = m_items[i];
	}

	//Set the last value in the new array to be the actor we want to add
	tempItem[m_length] = T;
	//Set old array to hold the values of the new array
	m_items = tempItem;
	m_length++;
}

template<typename T>
inline bool DynamicArray<T>::removeitem(T* item)
{
    //Check to see if the actor was null
    if (!T)
    {
        return false;
    }

    bool itemRemoved = false;
    //Create a new array with a size one less than our old array
    T** newItem = new T* [m_length - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_length; i++)
    {
        if (T != m_items[i])
        {
            newItem[j] = m_items[i];
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
        m_items = newItem;
        m_length--;
    }
    //Return whether or not the removal was successful
    return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
    template <typename T>
    void insertionSort(T item[], int size)
    {
        int j = 0;
        int key = 0;

        for (int i = 1; i < size; i++)
        {
            key = item[i];
            j = i - 1;

            while (j >= 0 && item[j] > key)
            {
                item[j + 1] = item[j];
                j--;
            }

            item[j + 1] = key;
        }
    }
}

template<typename T>
inline T* DynamicArray<T>::getItem(int index)
{
    //Return false if the index is out of bounds
    if (index < 0 || index >= m_length)
        return nullptr;

    return m_items[index];
}

template<typename T>
inline int DynamicArray<T>::getLength()
{
	return m_length;
}
