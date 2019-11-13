
#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* 由裁判实现，细节不表 */
bool IsBST ( BinTree T );

int main()
{
    BinTree T;
    
    T = BuildTree();
    if ( IsBST(T) ) printf("Yes\n");
    else printf("No\n");
    
    return 0;
}
/* 你的代码将被嵌在这里 */
bool IsBST ( BinTree T )
{
    BinTree T1=NULL,T2=NULL;
    if(T == NULL)
        return true;
    else if(T->Left == NULL && T->Right == NULL)
        return true;
    T1=T->Left;
    if(T1!=NULL)
    {
        while(T1->Right!=NULL)
        {
            T1=T1->Right;
        }
    }
    T2=T->Right;
    if(T2!= NULL)
    {
        while(T2->Left!=NULL)
        {
            T2=T2->Left;
        }
    }
    if(T1->Data<T->Data && T2->Data>T->Data)
        return true;
    else
        return false;
    
}
