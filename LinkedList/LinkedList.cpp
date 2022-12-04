#include "LinkedList.hpp"

// Definition de notre constructeur:
LinkedList:: LinkedList(const vector<short>& vect= {}){
    ListNode* node1 = new ListNode(vect[0]); // next is going to be by default a nullptr
    head= node1;

    for (size_t i=1; i<vect.size();i++){
        ListNode * node= new ListNode(vect[i]);
        node1 -> next = node;
        node1 = node;
    }

    size = vect.size();
}

// Definition de notre constructeur de copie:
LinkedList::LinkedList(const LinkedList& liste){
    size = liste.size; 
    ListNode * newnode = new ListNode( (liste.head)-> val); //on cree un pointeur newnode qui pointe vers une memoire allouee dynamiquement contenant la 1ere ListNode de la linked list qu'on copie.
    head= newnode; 
    ListNode * savedPtr= newnode; //on sauvegarde l'adresse memoire de notre newnode car on va la changer dans la forloop 
    ListNode * nextNodePtr = (liste.head) -> next; //on sauvegarde l'adresse memoire du next de notre 1ere listNode

    for (size_t i=0; i<liste.size; i++){
        newnode= new ListNode(nextNodePtr -> val); //on reinitialise notre newnode, il va pointer au node suivant dans la liste.
        savedPtr -> next = newnode; // le next de notre node precedent contient maintenant l'adresse memoire du node qui suit.
        savedPtr = newnode;//Reinitialisation: on sauvegarde l'adresse memoire de notre newnode courant.
        nextNodePtr = nextNodePtr -> next;//Reinitialisation: on sauvegarde l'adresse memoire du next de notre listNode courante.
    }
}


// Definition de notre destructeur:

LinkedList:: ~LinkedList(){
    ListNode* ptr = head; //on cree un pointeur qui contient l'adresse memoire head de notre linkedList.
    while ( ptr != NULL){ //on parcours notre linkedList
        head = head -> next; //notre head est maintenant celui qui suit 
        delete ptr; 
        ptr = head; //on reinitialise notre pointeur au head reninitialisé
    }
}


//operateur =
LinkedList& LinkedList :: operator=(const LinkedList& liste){
    LinkedList listeCopiee(liste);
    swap(*this,listeCopiee);
    return *this;
}

//we will define an external overloading operator << , for that we need the size of our linked list
//However, size is a private attribute, so we need to create a getSize() function

int LinkedList::getSize()const{
    int size=0;
    ListNode* ptr =head;
    while (ptr != nullptr){
        size++;
        ptr=ptr->next;
    }
    return size;
}

ostream& LinkedList:: toOstream(ostream&out) const{
   ListNode* node=head;
    out<< "[ ";
    for(size_t i=0; i<getSize(); i++){
        out <<node->val << " "; 
        node=(node->next);
    }
    out << "]";
    return out;
}

//external overloading of the insertion operator (<<)
ostream&operator<<(ostream&os, LinkedList& liste){
    return liste.toOstream(os);
}

bool LinkedList::operator==(const LinkedList& liste)const{
    ListNode* first = head;
    ListNode* second = liste.head;
    if (size!=liste.size){
        return false;
    }
    while(first!=nullptr){
        if( (first->val) != (second->val) ){
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
}