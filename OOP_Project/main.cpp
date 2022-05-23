#include <iostream>

#define NUM_MENU_OPTION 5
#define PROGRAM_EXIT_OPTION 5
#define MAX_LEN_USER_NAME 20

void show_menu();
int get_user_select();
void select_menu(int option_num);

void activity_MakeAccout();
void activity_DepositMoney();
void activity_WithdrawMoney();
void activity_ShowAllAcountInfo();

typedef struct 
{
    int accoutID;
    int balance;
    char userName[MAX_LEN_USER_NAME];
}Account;

Account accArr[100];
int accNum = 0;

int main(void)
{
    while(true){
        show_menu();
        int user_input = get_user_select();

        if(user_input == -1){
            std::cout<<"잘못된 입력!\n"<<std::endl;
            continue;
        }

        if(user_input == PROGRAM_EXIT_OPTION){
            std::cout<<"프로그램 종료"<<std::endl;
            break;
        }

        select_menu(user_input);
    }

    return 0;
}

void show_menu()
{
    std::cout<<"------Menu------"<<std::endl;
    std::cout<<"1. 계좌개설"<<std::endl;
    std::cout<<"2. 입금"<<std::endl;
    std::cout<<"3. 출금"<<std::endl;
    std::cout<<"4. 계좌정보 전체 출력"<<std::endl;
    std::cout<<"5. 프로그램 종료"<<std::endl;
}

int get_user_select()
{
    int user_input;
    std::cout<<"선택 : ";
    std::cin>>user_input;

    std::cout<<std::endl;

    if((1 <= user_input) && (user_input <= NUM_MENU_OPTION)){
        return user_input;
    }
    else{
        return -1;
    }
}

void select_menu(int option_num)
{
    switch(option_num)
    {
        case 1:
            activity_MakeAccout();
            break;

        case 2:
            activity_DepositMoney();
            break;

        case 3:
            activity_WithdrawMoney();
            break;
        
        case 4:
            activity_ShowAllAcountInfo();
            break;
    }

    std::cout<<std::endl;
}

void activity_MakeAccout()
{
    accNum += 1;

    std::cout<<"[계좌개설]"<<std::endl;
    std::cout<<"계좌ID : ";
    std::cin>>accArr[accNum].accoutID;

    std::cout<<"이  름 : ";
    std::cin>>accArr[accNum].userName;
    
    std::cout<<"입금액 : ";
    std::cin>>accArr[accNum].balance;
}

void activity_DepositMoney()
{
    bool result = false;
    int accountID;
    int deposit;

    std::cout<<"[입   금]"<<std::endl;
    std::cout<<"계좌ID : ";
    std::cin>>accountID;

    std::cout<<"입금액 : ";
    std::cin>>deposit;

    for (int i = 1; i <= accNum; i++){
        if(accArr[i].accoutID == accountID){
            accArr[i].balance += deposit;
            result = true;
            break;
        }
    }

    if(result){
        std::cout<<"입금완료"<<std::endl;
    }
    else {
        std::cout<<"입금실패"<<std::endl;
    }
}

void activity_WithdrawMoney()
{
    bool result = false;
    int accountID;
    int withdrawal;

    std::cout<<"[출   금]"<<std::endl;
    std::cout<<"계좌ID : ";
    std::cin>>accountID;

    std::cout<<"출금액 : ";
    std::cin>>withdrawal;

    for (int i = 1; i <= accNum; i++){
        if(accArr[i].accoutID == accountID){
            if((accArr[i].balance - withdrawal) >= 0){
                accArr[i].balance -= withdrawal;
                result = true;
            }
            break;
        }
    }

    if(result){
        std::cout<<"출금완료"<<std::endl;
    }
    else {
        std::cout<<"출금실패"<<std::endl;
    }
}

void activity_ShowAllAcountInfo()
{
    bool result = false;
    int accountID;

    std::cout<<"[계좌조회]"<<std::endl;
    std::cout<<"계좌ID : ";
    std::cin>>accountID;
    std::cout<<std::endl;

    for (int i = 1; i <= accNum; i++){
        if(accArr[i].accoutID == accountID){
            std::cout<<"계좌ID : "<<accArr[i].accoutID<<std::endl;
            std::cout<<"이  름 : "<<accArr[i].userName<<std::endl;
            std::cout<<"잔  액 : "<<accArr[i].balance<<std::endl;
            result = true;
            break;
        }
    }

    if(!result){
        std::cout<<"조회실패"<<std::endl;
    }

}
