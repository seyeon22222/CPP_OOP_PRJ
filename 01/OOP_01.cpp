#include <iostream>
#include <cstring>

const int NAME_LEN = 20;

void show(void);
void view(void);
void withdraw(void);
void deposit(void);
void make(void);

typedef struct Account
{
	int ID;
    char name[NAME_LEN];
    int balance;
} Account;

Account acc[100];
int acc_num = 0;

int main(void)
{
	int num;
    
    while (1)
    {
    	view();
        std::cout << "선택 :";
        std::cin >> num;
        
        if (num == 1)
        	make();
        else if (num == 2)
        	deposit();
        else if (num == 3)
        	withdraw();
        else if (num == 4)
        	show();
        else if (num == 5)
        	return 0;
        else
        	std::cout << "잘못된 입력입니다. 다시 시도해주세요." << std::endl;
    }
    return 0;
}

void view(void)
{
	std::cout <<"---------Menu---------"<< std::endl;
    std::cout <<"1. 계좌개설" << std::endl;
    std::cout <<"2. 입금"<< std::endl;
    std::cout <<"3. 출금"<< std::endl;
    std::cout <<"4. 계좌정보 전체 출력"<< std::endl;
    std::cout <<"5. 프로그램 종료"<< std::endl;
}

void make(void)
{
	int id;
    char name[NAME_LEN];
    int balance;
   
	std::cout <<"[계좌개설]"<< std::endl;
    std::cout << "계좌ID :"; std::cin >> id;
    std::cout << "이 름 :"; std::cin >> name;
    std::cout << "입금액 :"; std::cin >> balance;
	std::cout << std::endl;
    
	acc[acc_num].ID = id;
    acc[acc_num].balance = balance;
    strcpy(acc[acc_num].name, name);
    acc_num++;
}

void deposit(void)
{
	int money;
    int id;
    
    std::cout << "[입 금]" << std::endl;
    std::cout << "계좌ID :";
    std::cin >> id;
    std::cout << "입금액 :";
    std::cin >> money;
    
    for (int i = 0; i < acc_num; i++)
    {
    	if (acc[i].ID == id)
        {
        	acc[i].balance += money;
            std::cout << "입 금 완 료" << std::endl;
            return;
        }
    }
    std::cout << "잘못된 ID입니다." << std::endl;
}

void withdraw(void)
{
	int money;
    int	id;
    
    std::cout << "[출 금]" << std::endl;
    std::cout << "계좌ID :";
    std::cin >> id;
    std::cout << "출금액 :";
    std::cin >> money;
    
    for (int i = 0; i < acc_num; i++)
    {
    	if (acc[i].ID == id)
        {
        	acc[i].balance -= money;
            std::cout << "출 금 완 료" << std::endl;
            return;
        }
    }
    std::cout << "잘못된 ID입니다." << std::endl;
}

void show(void)
{
	std::cout << "------------" << std::endl;
	std::cout << "[전체 계좌 출력]" << std::endl;
	std::cout << "------------" << std::endl;
	for (int i = 0; i < acc_num; i++)
    {
    	std::cout << "계좌 ID :" << acc[i].ID << std::endl;
        std::cout << "이름 :" << acc[i].name << std::endl;
        std::cout << "잔액 :" << acc[i].balance << std::endl;
    }
}