#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef struct BNode
{
    int id;
    BNode *leftChild;
    BNode *rightChild;
} BNode;
BNode *root;
BNode *makeNode(int id)
{
    BNode *p = new BNode;
    p->id = id;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}
void inOrder(BNode *r)
{
    stack<BNode *> s;
    BNode *tail = r;

    while (tail != NULL || !s.empty())
    {

        while (tail != NULL)
        {
            s.push(tail);
            tail = tail->leftChild;
        }

        tail = s.top();
        s.pop();

        cout << tail->id << " ";
        tail = tail->rightChild;
    }
    cout<<"\n";
}
void PreOrder(BNode *r)
{
    stack<BNode *> s;
    BNode *tail = r;
    while (tail != NULL || !s.empty())
    {

        while (tail != NULL)
        {
            s.push(tail);
            cout << tail->id << " ";
            tail = tail->leftChild;
        }
        tail = s.top();
        s.pop();
        tail = tail->rightChild;
    }
    cout<<"\n";
}
void PostOrder(BNode *r)
{
    stack<BNode *> s1, s2;
    BNode *tail;

    s1.push(r);
    while (!s1.empty())
    {
        tail = s1.top();
        s1.pop();
        s2.push(tail); 
        if (tail->leftChild!=NULL)
            s1.push(tail->leftChild);
        if (tail->rightChild!=NULL)
            s1.push(tail->rightChild);
    }
    while (!s2.empty())
    {
        tail = s2.top();
        s2.pop();
        cout << tail->id << " ";
    }
    cout<<"\n";
}
int main()
{
    root = makeNode(10);
    root->leftChild = makeNode(8);
    root->rightChild = makeNode(2);
    root->leftChild->leftChild = makeNode(3);
    root->leftChild->rightChild = makeNode(5);
    root->rightChild->leftChild = makeNode(2);
    inOrder(root);
    PreOrder(root);
    PostOrder(root);
}