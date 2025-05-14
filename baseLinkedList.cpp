#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next = NULL;
};
Node *head = NULL;

Node *makeNewNode(int val)
{
    Node *newNode = new Node();
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insetLast(Node *&head, int val)
{
    Node *newNode = makeNewNode(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    return;
}

void insertFirst(Node *&head, int val)
{
    Node *newNode = makeNewNode(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}
// delete a node with elements in list is unique
void deleteANode(Node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    Node *cur = head;
    Node *next = NULL;
    Node *pre = NULL;

    while (cur != NULL)
    {
        next = cur->next;

        if (cur->val == val)
        {
            if (pre == NULL)
            {
                head = next;
                delete cur;
                cur = head;
            }
            else
            {
                pre->next = next;
                delete cur;
                cur = next;
            }
        }
        pre = cur;
        cur = next;
    }
}

void display()
{
    Node *cur = head;
    while (cur != NULL)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
}
int main()
{
    insertFirst(head, 1);
    insertFirst(head, 2);
    insertFirst(head, 3);
    insertFirst(head, 4);
    deleteANode(head, 4);
    display();
}