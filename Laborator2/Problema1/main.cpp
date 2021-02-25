#include "numberlist.h"

int main (void)
{
    NumberList L;
    L.Init();
    L.Add(10);
    L.Add(25);
    L.Add(15);
    L.Print();
    L.Sort();
    L.Print();
    L.Insert(2, 100);
    L.Print();
    L.Add(15);
    L.Sort();
    L.Print();
    L.RemoveNumber(15);
    L.Print();
    return 0;
}
