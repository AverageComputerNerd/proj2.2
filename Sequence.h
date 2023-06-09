#ifndef Sequence_h
#define Sequence_h
#include <string>

using ItemType = std::string;

class Sequence
{
public:
    Sequence();
    Sequence(const Sequence& other);  //copy constructor
    Sequence& operator = (const Sequence& other); //assignment operator
    ~Sequence();  //destrucotor
    
    bool empty() const;
    int size() const;
    int insert (int pos, const ItemType& value);
    int insert (const ItemType& value);
    bool erase (int pos);
    int remove (const ItemType& value);
    bool get (int pos, ItemType& value) const;
    bool set (int pos, const ItemType& value);
    int find (const ItemType& value) const;
    void swap (Sequence& other);
    
private:
    struct Node
    {
        ItemType data;
        Node* next;
        Node* previous;
    };
    Node* head;
    Node* tail;
    int m_size;
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif
