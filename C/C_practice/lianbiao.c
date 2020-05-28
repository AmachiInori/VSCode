#include<stdlib.h>
#include<stdio.h>
#define Error(Str) FatalError(Str)
#define FatalError(Str) fprintf(stderr, "%s\n", Str), exit(1);

struct Node;
typedef int elememtType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty( List L );
int isEmpty( List L );
int isLast( Position P, List L );
Position Find( elememtType X, List L );
void Delete( elememtType X, List L);
Position FindPrevious( elememtType X, List L );

struct Node
{
    elememtType Element;
    Position Next;
};

List
MakeEmpty( List L )
{
    if (L == NULL)
    {
        FatalError("Must use CreatList first");
    }
    else
    {
        Position P = L -> Next, temp;
        while (P -> Next != NULL)
        {
            temp = P;
            P = P -> Next;
            free(temp);
        }
    }
    return L;
}

int 
isEmpty( List L )
{
    return L -> Next == NULL;
}

int
isLast( Position P, List L )
{
    return P -> Next == NULL;
}

Position 
Find( elememtType X, List L )
{
    if (L == NULL)
    {
        FatalError("Must use CreatList first");
    }
    Position P = L -> Next;
    while (P -> Element != X && P != NULL)
    {
        P = P -> Next;
    }
    return P;
}

void 
Delete( elememtType X, List L )
{
    if (L == NULL)
    {
        FatalError("Must use CreatList first");
    }

    Position P = FindPrevious(X, L);
    if(!isLast(P, L))
    {
        
    }
}

Position 
FindPrevious( elememtType X, List L )
{
    if (L == NULL)
    {
        FatalError("Must use CreatList first");
    }

    Position P = L -> Next;
    while (P -> Next != NULL && P -> Next -> Element != X)
    {
        P = P -> Next;
    }

    return P;
}