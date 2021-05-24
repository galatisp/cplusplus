// handle a linked list as a queue
#include <iostream>

using namespace std;

struct node
{
    int info;
    struct node *next;
};

typedef node *nodeptr;

class list
{
    nodeptr head;
    

public:
    list();                 /* κατασκευαστής: κατασκευάζει μία κενή λίστα */
    bool empty();           /* ελέγχει αν η λίστα είναι κενή */
    int size();             /* επιστρέφει το μέγεθος της λίστας */
    void add(int k, int x); /* εισάγει το στοιχείο x στη θέση k της λίστας */

    int get(int k);     /* επιστρέφει την τιμή του στοιχείου στη θέση k της λίστας */
    void remove(int k); /* διαγράφει το στοιχείο στη θέση k της λίστας */
};

// Member functions definitions including constructor
list::list(void)
{
    head = nullptr;
   
    cout << "List has been initiated" << endl;
    
}

bool list::empty(void)
{
    if (head == nullptr) 
    {
        return true;
    }
    return false;
}

int list::size(){
    int k = 0;
    nodeptr curr = head;
    while (curr != nullptr){
        k++;
        curr = curr->next;
    }
    return k;
}

/* Add a new value at k position of a list */
void list::add(int k, int x)
{
    nodeptr new_node;
    new_node = new node;
    new_node->info = x;
    new_node->next = nullptr;
    if (head == nullptr) 
    {
        head = new_node;
       
    }
    else
    {  int pos=0;
        nodeptr curr = head;
        while ((curr != nullptr) && (pos < k-1)){
            curr = curr->next;
            pos++;
        }
        
        new_node->next = curr->next;
        curr->next = new_node;
    }

    
    
}

/* Return the first item of a list */
int list::get(int k)
{

    if (empty())
    {
        return -1;
    }
    else
    {
        int pos=0;
        int info = -1;
        nodeptr curr = head;
        while ((curr != nullptr) && (pos < k)){
            curr = curr->next;
            pos++;
        }
        if (curr != nullptr){
            return curr->info;
        }
        else{
            return info;
        }
    }
}

/* Remove item at k position of a list */
void list::remove(int k)
{
    if (head != nullptr) 
   {  int pos=0;
        nodeptr curr = head;
        while ((curr != nullptr) && (pos < k-1)){
            curr = curr->next;
            pos++;
        }
        nodeptr tbd = curr->next;
        curr->next = curr->next->next;
        delete tbd;
    }

    
    
}


int main()
{
    list l1;
    l1.add(0, 14);
    l1.add(1, 15);
    l1.add(1, 18);
    l1.add(1, 22);
    l1.remove(1);
   
    
    int pos =0;
    while (pos < l1.size())
    {
        
        cout << pos << " " << l1.get(pos) << endl;
        pos++;
    }
}
