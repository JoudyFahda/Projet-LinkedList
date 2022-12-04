#include<iostream>
#include<vector>
using namespace std;


class LinkedList{
public:
    LinkedList(const vector<short>& = {}); 
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);
    ~LinkedList();

    short & operator[] (int index);
    const short operator[] (int index) const;
    bool operator==(const LinkedList& l)const{}

    void push_back(short);
    void push_front(short);
    int getSize() const;
    ostream& toOstream(ostream& out) const;

private:
    struct ListNode {
        ListNode(short val, ListNode* next = nullptr)
        :val(val), next(next) {}
        short val;
        ListNode* next;
    };

    ListNode* head;
    int size; 
    friend void swap(LinkedList& l1, LinkedList& l2){
        swap(l1.head,l2.head);
        swap(l1.size,l2.size);
    };
};

// external overloading:
ostream&operator<<(ostream&os, LinkedList& l){}