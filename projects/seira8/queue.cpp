// handle a linked list as a queue
#include <iostream>

using namespace std;

struct node
{
    int info;
    struct node *next;
};

typedef node *nodeptr;

class queue
{
    nodeptr front;
    nodeptr rear;

public:
    queue();             /* κατασκευαστής: κατασκευάζει μία κενή ουρά */
    bool empty();        /* ελέγχει αν η ουρά είναι κενή */
    void enqueue(int x); /* εισάγει ένα στοιχείο στην ουρά */
    int dequeue();       /* αφαιρεί ένα στοιχείο από μια μη κενή ουρά */
    int peek();          /* επιστρέφει (χωρίς να αφαιρεί) το πρώτο στοιχείο μιας μη κενής ουράς */
};

// Member functions definitions including constructor
queue::queue(void)
{
    front = nullptr;
    rear = nullptr;
    cout << "Queue has been initiated" << endl;
}

bool queue::empty(void)
{
    if ((front == nullptr) && (rear == nullptr))
    {
        return true;
    }
    return false;
}

/* Add a new node to the end of a queue */
void queue::enqueue(int x)
{
    nodeptr new_node;
    new_node = new node;
    new_node->info = x;
    new_node->next = nullptr;
    if (empty())
    {
        front = new_node;
        rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}

/* Remove the first item of a queue */
int queue::dequeue()
{
    int x;
    if(empty()){
        return -1;
    }
    else if (front==rear) //last item
    {
        x = front->info;
        delete front;
        front = nullptr;
        rear = nullptr;
        return x;
    }
    else 
    {
        nodeptr next = front->next;
        x = front->info;
        delete front;
        front = next;
        return x;
    }
    
}


/* Return the first item of a queue */
int queue::peek()
{
    
    if (front != nullptr)
    { 
        return front->info;
    }
    else
        return -1;
}


int main()
{
   queue q1;
   q1.enqueue(5);
   q1.enqueue(2);
//    cout << q1.dequeue() << endl;
//     cout << q1.dequeue() << endl;
//      cout << q1.dequeue() << endl;

   while(!q1.empty()){
       cout << q1.dequeue() << endl;

   }
}
