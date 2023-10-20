#include <iostream>
#include <cstring>

void show(void);
void view(void);
void withdraw(void);
void deposit(void);
void make(void);

class Account
{
private:
	int 	id;
	int 	balance;
	char	*name;

public:
	Account(int id, int money, char *new_name) : id(id), balance(money)
	{
		name = new char[strlen(new_name) + 1];
		strcpy(name, new_name);
	}
	~Account() {delete []name;}
	int Getid() {return id;}
	void deposit(int money)	{ balance += money; }
	int withdraw(int money)
	{
		if (balance < money)
			return 0;
		balance -= money;
		return money;
	}
	void info()
	{
		std::cout << "계좌 ID :" << id << std::endl;
        std::cout << "이름 :" << name << std::endl;
        std::cout << "잔액 :" << balance << std::endl;
	}
};

const int NAME_LEN = 20;
Account *acc[100];
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
		{
			for (int i = 0; i < acc_num; i++)
				delete acc[i];
			return 0;
		}
        else
        	std::cout << "잘못된 입력입니다. 다시 시도해주세요." << std::endl;
    }
    return 0;
}

void view(void)
{
	std::cout <<"---------Menu---------"<< std::endl;
    std::cout <<"1. 계좌개설"<< std::endl;
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
    
	acc[acc_num++] = new Account(id, balance, name);
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
    	if (acc[i]->Getid() == id)
        {
        	acc[i]->deposit(money);
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
    	if (acc[i]->Getid() == id)
        {
        	if (acc[i]->withdraw(money) == 0)
			{
				std::cout << "잔 액 부 족" << std::endl;
            	return;
			}
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
    	acc[i]->info();
		std::cout << std::endl;
    }
}