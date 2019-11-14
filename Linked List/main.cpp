#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* link;
};

struct Node* head;

void printf()
{
    struct Node* temp;
    temp = head;
    while(temp !=NULL)
    {
        cout << temp -> data << "  ";
        temp = temp->link;
    }
}
int main()
{
    head = NULL;
    head = (struct Node*) malloc(sizeof(struct Node*));
    head -> data = 5;
    head ->link = (struct Node*) malloc(sizeof(struct Node*));
    head ->link -> data = 2;
    head ->link -> link = (struct Node*) malloc(sizeof(struct Node*));
    head ->link -> link -> data = 10;
    head ->link -> link -> link = NULL;
    printf();
    return 0;
}
