/*Given a singly linked list of integers, sort it using 'Bubble Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// its complexity is O(n)
Node *takeinput2()
{
    int d;
    cin >> d;
    Node *head = NULL;
    Node *tail = NULL;
    while (d != -1)
    {
        Node *newnode = new Node(d);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            Node *temp = head;
            tail->next = newnode;
            tail = newnode; // OR  tail = tail->next
        }
        cin >> d;
    }
    return head;
}

// function to count length of linked list

int countlength(Node *head)
{ // recursively
    if (head == NULL)
    {
        return 0;
    }
    int smallop = countlength(head->next);
    return smallop + 1;
}

// function for bubble sort

Node *bubbleSort(Node *head)
{

    int len = countlength(head);

    // running loop for n-1 iterations

    for (int i = 0; i < len; i++)
    {

        Node *prev = NULL;
        Node *curr = head;
        Node *next = curr->next;

        // traversing list

        while (curr->next != NULL)
        {

            // comparing two corresponding elements

            if (curr->data > curr->next->data)
            {

                // case of head node
                if (prev == NULL)
                {
                    curr->next = next->next;
                    next->next = curr;
                    head = next;
                }

                else
                {
                    prev->next = curr->next;
                    curr->next = next->next;
                    next->next = curr;
                }
                prev = next;
                next = curr->next;
            }

            else
            {
                prev = curr;
                curr = next;
                next = next->next;
            }
        }
    }

    return head;
}

int main()
{
    Node *head = takeinput2();
    Node *h = bubbleSort(head);
    print(h);
}