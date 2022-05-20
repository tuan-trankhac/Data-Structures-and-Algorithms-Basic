#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
typedef struct DNode{
    int val;
    struct DNode *prev;
    struct DNode *next;
}DNode;
DNode *first, *last;

void initlist()
{
    first = NULL;
    last = NULL;
}
int listEmpty()
{
    return first == NULL && last == NULL;
}
DNode *makeNode(int v){
    DNode *p = (DNode*)malloc(sizeof(DNode));
    p->val =v;
    p->next=NULL;
    p->prev=NULL;
    return p;
}
void Remove_Node(DNode *p){
    if(p==NULL) return;
    if(first==last && p== first){
        first =NULL; last=NULL; free(p); return ;
    }
    if(p==first){
        first= p->next;
        first->prev=NULL;
        free(p);
        return ;
    }
    if(p==last){
        last=p->prev;
        last->next=NULL;
        free(p);
        return;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}
void insertLast(int x){
    DNode *p = makeNode(x);
    if(first==NULL&&last==NULL){
        first=p;
        last=p;
        return;
    }
    p->prev=last;
    last->next=p;
    last = p;
}
void insertFirst(int x){
    DNode *p = makeNode(x);
    if(first==NULL&&last==NULL){
        first=p;
        last=p;
        return;
    }
    first->prev=p;
    p->next=first;
    first = p;
}
void processInsertLast()
{
    int x;
    scanf("%d",&x);
    insertLast(x);
}
void processInsertFirst()
{
    int x;
    scanf("%d",&x);
    insertFirst(x);
}
DNode *find(int x)
{
    for (DNode *p = first; p != NULL; p = p->next)
    {
        if (p->val==x)
            return p;
    }
    return NULL;
}
void ClearAll(){
    DNode *p = first;
    while (p != NULL)
    {
        DNode *np = p->next;
        free(p);
        p = np;
    }
}
void pop_front(){
    DNode *tmp=first;
    if(listEmpty()) return ;
    first = first->next;
    first->prev=NULL;
    free(tmp);
}
void pop_back(){
    DNode *tmp=last;
    if(listEmpty()) return ;
    last = last->prev;
    last->next=NULL;
    free(tmp);
}
int SizeL(){
    int count=0;
    for (DNode *p = first; p != NULL; p = p->next)
    {
        count++;
    }
    return count;
}
void processRemove()
{
    int x;
    scanf("%d", &x);
    Remove_Node(find(x));
}
void printListLeftRight()
{
    for (DNode *p = first; p != NULL; p = p->next)
        printf("%d\n", p->val);
}
void printListRightLeft()
{
    for (DNode *p = last; p != NULL; p = p->prev)
        printf("%d\n", p->val);
}
void processPrintList()
{
    printf("Danh sach tu trai qua phai\n");
    printListLeftRight();
    printf("Danh sach tu phai qua trai\n");
    printListRightLeft();
}
int main(){
    initlist();
    while (1)
    {
        printf("Enter command: ");
        char cmd[MAX];
        scanf("%s", cmd);
        if (strcmp(cmd, "Quit") == 0)
            break;
        else if (strcmp(cmd, "Insert_Last") == 0)
            processInsertLast();
        else if (strcmp(cmd, "Insert_First") == 0)
            processInsertFirst();
        else if (strcmp(cmd, "Remove") == 0)
            processRemove();
        else if (strcmp(cmd, "Print") == 0)
            processPrintList();
        else if(strcmp(cmd,"Clear")==0)
            ClearAll();
        else if(strcmp(cmd,"Size")==0)
            printf("Size = %d\n", SizeL());
        else if(strcmp(cmd,"Pop_Back")==0)
            pop_back();
        else if(strcmp(cmd,"Pop_Front")==0)
            pop_front();
    }
}