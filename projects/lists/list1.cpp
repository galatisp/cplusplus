// handle a linked list
#include <iostream>

#define N 3
using namespace std;

struct node
{
    int info;
    struct node *next;
};

typedef node *nodeptr;
nodeptr add(int , nodeptr );

nodeptr lastNode(nodeptr);




nodeptr readList()
{
    nodeptr head = nullptr, n, last;

    int data;

    //construct head node;
    if (scanf("%d", &data) == 1)
    {
        n = new node;
        n->info = data;
        n->next = nullptr;
        head = n;
    }
    else
        return head;

    last = head;
    
    while (scanf("%d", &data) == 1)
    {
        n = new node;
        n->info = data;
        n->next = nullptr;
        last->next = n;
        last = n;
    }
    return head;
}

nodeptr readListReversed()
{
    nodeptr head = nullptr, n;
    int data;
    while (scanf("%d", &data) == 1)
    {
        n = new node;
        n->info = data;
        n->next = head;
        head = n;
       
    }
    return head;
}

nodeptr reverseList(nodeptr list)
{

    nodeptr head = nullptr, n;
    int data;
    while (list != nullptr)
    {
        n = new node;
        n->info = list->info;
        n->next = head;
        head = n;
        list = list->next;
    }
    return head;
}

void print(nodeptr p)
{
    while (p != nullptr)
    {
        printf("%d \n", p->info);
        p = p->next;
    }
}

/* Add a new node to the head of a linked list */
nodeptr add(int num, nodeptr head)
{
    nodeptr new_node;
    // C way of requesting dynamic memory
    // new_node = (node *) malloc(sizeof(node));
    new_node = new node;
    new_node->info = num;
    new_node->next = head;

    return new_node;
}

/* Add a new node to the end of a linked list */
void addAtEnd(int num, nodeptr head)
{
    nodeptr new_node, last;
    last = lastNode(head);
    new_node = new node;
    new_node->info = num;
    new_node->next = nullptr;
    last->next = new_node;

}

/* Remove an element from a linked list */
nodeptr remove(int num, nodeptr head)
{
    nodeptr current_node = head;
    nodeptr prev_node;
    int cnt = 0;
    while (current_node != NULL)
    {
        if (current_node->info == num)
        {
            if (current_node == head)
            {
                head = current_node->next;
            }
            else
            {
                prev_node->next = current_node->next;
            }
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
    return (head);
}

nodeptr lastNode(nodeptr list)
{
    while (list != nullptr)
    {
        if (list->next == nullptr)
            return list;
        list = list->next;
        
    }
    return list;
}

int main()
{
    nodeptr list = readList();
   

    // nodeptr rev = reverseList(list);
    // print(rev);
    // print(list);
    //to handle character input which stops readList
    char line[256];
    fgets(line, sizeof(line), stdin);
    int num; 
    printf("Poion aritho na prosthesw sthn arxh ths listas?");
    scanf("%d", &num);
    list = add(num, list);
    print(list);

    printf("Poion aritho na prosthesw sto TELOS ths listas?");
    scanf("%d", &num);
    addAtEnd(num, list);
    print(list);
 
    printf("Poion aritho na sbiso apo th lista?");
    scanf("%d", &num);
    list = remove(num, list);
    print(list);
}
