bool Push( ElementType X, Deque D )
{
    if((D->Rear+1)%(D->MaxSize)==D->Front)
        return false;
    D->Front--;
    D->Front=(D->MaxSize+D->Front)%(D->MaxSize);
    D->Data[D->Front]=X;
    return true;
}
ElementType Pop( Deque D )
{
    if(D->Front==D->Rear)
        return ERROR;
    ElementType d=D->Data[D->Front];
    D->Front++;
    D->Front=D->Front%(D->MaxSize);
    return d;
}
bool Inject( ElementType X, Deque D )
{
    if((D->Rear+1)%(D->MaxSize)==D->Front)
        return false;
    D->Data[D->Rear]=X;
    D->Rear=(D->Rear+1)%D->MaxSize;
    return true;
}
ElementType Eject( Deque D )
{
    if(D->Front==D->Rear)
        return ERROR;
    if(!D->Rear)
        D->Rear=D->MaxSize;
    D->Rear--;
    ElementType d=D->Data[D->Rear];
    return d;
}
