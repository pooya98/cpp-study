#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char name[20] = "kang";
    char cpy_name[20];

    int length = strlen(name);

    cout<<"strlen(name): "<<length<<endl;
    
    strcat(name, "!");

    cout<<"strcat(name, \"!\"): "<<name<<endl;

    strcpy(cpy_name, name);

    cout<<"strcpy(cpy_name, name): "<<cpy_name<<endl;

    int result = strcmp(cpy_name, name);

    cout<<"strcmp(cpy_name, name): "<<result<<endl;

    return 0;
}