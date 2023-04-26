// Sequence.cpp

#include "Sequence.h"

Sequence::Sequence()
 : m_size(0)
{}

int Sequence::insert(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos > size()  ||  size() == DEFAULT_MAX_ITEMS)
    return -1;
    uncheckedInsert(pos, value);
    return pos;
}

int Sequence::insert(const ItemType& value)
{
    if (size() == DEFAULT_MAX_ITEMS)
        return -1;
    int pos;
    for (pos = 0; pos < size()  &&  value > m_data[pos]; pos++)
    ;
    uncheckedInsert(pos, value);
    return pos;
}
     
bool Sequence::erase(int pos)
{
    if (pos < 0  ||  pos >= size())
    return false;
    for ( ; pos < size() - 1; pos++)
    m_data[pos] = m_data[pos+1];
    m_size--;
    return true;
}

int Sequence::remove(const ItemType& value)
{
    int keepPos = find(value);
    if (keepPos == -1)
    return 0;
    int count = 1;
    for (int examinePos = keepPos+1; examinePos < size(); examinePos++)
    {
    if (m_data[examinePos] == value)
        count++;
    else
    {
        m_data[keepPos] = m_data[examinePos];
        keepPos++;
    }
    }
    m_size -= count;
    return count;
}
     
bool Sequence::get(int pos, ItemType& value) const
{
    if (pos < 0  ||  pos >= size())
        return false;
    value = m_data[pos];
    return true;
}

bool Sequence::set(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos >= size())
        return false;
    m_data[pos] = value;
    return true;
}

int Sequence::find(const ItemType& value) const
{
    for (int pos = 0; pos < size(); pos++)
        if (m_data[pos] == value)
        return pos;
    return -1;
}

void Sequence::swap(Sequence& other)
{
      // Swap elements.  Since the only elements that matter are those up to
      // m_size and other.m_size, only they have to be moved.

    int maxSize = (m_size > other.m_size ? m_size : other.m_size);
    for (int k = 0; k < maxSize; k++)
    {
        ItemType tempItem = m_data[k];
        m_data[k] = other.m_data[k];
        other.m_data[k] = tempItem;
    }

      // Swap sizes

    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
}

void Sequence::uncheckedInsert(int pos, const ItemType& value)
{
    for (int k = size(); k > pos; k--)
    m_data[k] = m_data[k-1];
    m_data[pos] = value;
    m_size++;
}
