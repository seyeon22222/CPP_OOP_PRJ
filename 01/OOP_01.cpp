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
        std::cout << "���� :";
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
        	std::cout << "�߸��� �Է��Դϴ�. �ٽ� �õ����ּ���." << std::endl;
    }
    return 0;
}

void view(void)
{
	std::cout <<"---------Menu---------"<< std::endl;
    std::cout <<"1. ���°���" << std::endl;
    std::cout <<"2. �Ա�"<< std::endl;
    std::cout <<"3. ���"<< std::endl;
    std::cout <<"4. �������� ��ü ���"<< std::endl;
    std::cout <<"5. ���α׷� ����"<< std::endl;
}

void make(void)
{
	int id;
    char name[NAME_LEN];
    int balance;
   
	std::cout <<"[���°���]"<< std::endl;
    std::cout << "����ID :"; std::cin >> id;
    std::cout << "�� �� :"; std::cin >> name;
    std::cout << "�Աݾ� :"; std::cin >> balance;
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
    
    std::cout << "[�� ��]" << std::endl;
    std::cout << "����ID :";
    std::cin >> id;
    std::cout << "�Աݾ� :";
    std::cin >> money;
    
    for (int i = 0; i < acc_num; i++)
    {
    	if (acc[i].ID == id)
        {
        	acc[i].balance += money;
            std::cout << "�� �� �� ��" << std::endl;
            return;
        }
    }
    std::cout << "�߸��� ID�Դϴ�." << std::endl;
}

void withdraw(void)
{
	int money;
    int	id;
    
    std::cout << "[�� ��]" << std::endl;
    std::cout << "����ID :";
    std::cin >> id;
    std::cout << "��ݾ� :";
    std::cin >> money;
    
    for (int i = 0; i < acc_num; i++)
    {
    	if (acc[i].ID == id)
        {
        	acc[i].balance -= money;
            std::cout << "�� �� �� ��" << std::endl;
            return;
        }
    }
    std::cout << "�߸��� ID�Դϴ�." << std::endl;
}

void show(void)
{
	std::cout << "------------" << std::endl;
	std::cout << "[��ü ���� ���]" << std::endl;
	std::cout << "------------" << std::endl;
	for (int i = 0; i < acc_num; i++)
    {
    	std::cout << "���� ID :" << acc[i].ID << std::endl;
        std::cout << "�̸� :" << acc[i].name << std::endl;
        std::cout << "�ܾ� :" << acc[i].balance << std::endl;
    }
}