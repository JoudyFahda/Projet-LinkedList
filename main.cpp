#include "LinkedList/LinkedList.hpp"

int main(){
    LinkedList list1({1,2,3});
    LinkedList list2({4,5});
    LinkedList list3;
    cout << "list1 = " << list1 << endl;
    cout << "list2 = " << list2 << endl;
    LinkedList list3(list1);
    cout << "list3 = " << list3 << endl;
    list3 = list2;
    cout << "list3 = " << list3 << endl;
    return 0;
}