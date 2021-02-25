class NumberList
{
    int numbers[10];
    int count;
public:
    void Init();
    bool Add(int x);
    void Sort();
    void Print();
    bool Insert(int pozitie, int x);
    void RemoveNumber(int x);
    void SetCount(int count);
};
