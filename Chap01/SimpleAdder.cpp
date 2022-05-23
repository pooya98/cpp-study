#include <iostream>

int main(void)
{
    int val1;
    std::cout<<"첫번 째 숫자 입력: ";
    std::cin>>val1;

    int val2;
    std::cout<<"두번 째 숫자 입력: ";
    std::cin>>val2;

    int result = val1 + val2;
    std::cout<<"덧셈 결과: "<<result<<std::endl;

    return 0;
}