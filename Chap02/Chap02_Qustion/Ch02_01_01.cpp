#include <iostream>
using namespace std;

void PlusOneFunc(int &value){
    value++;
}

void ChangeSignFunc(int &value)
{
    value *= (-1);
}

int main(void)
{
    int a = 1;

    PlusOneFunc(a);
    cout<<"PlusOneFunc(a): "<<a<<endl;

    ChangeSignFunc(a);
    cout<<"ChangeSignFunc(a): "<<a<<endl;
    
    return 0;
}