#include <iostream>
#include <cmath>
using namespace std;

class Check {
public:
    Check(): CheckNum(0), CheckMemo(), CheckAmount(0){}
    int getCheckNum() {return CheckNum;}
    string getCheckMemo() {return CheckMemo;}
    float getCheckAmount() {return CheckAmount;}
private:
    int CheckNum;
    string CheckMemo;
    float CheckAmount;
};

class CheckBook {
public:
    CheckBook(): balance(0),numOfChecks(0) {}
    CheckBook(float amount): balance(amount),numOfChecks(0) {}
    void deposit(float amount);
    void displayChecks();
    bool writeCheck(float amount);
    int getallChecks() {return allChecks;}
private:
    float balance;
    Check checks [5];
    float lastDeposit;
    int numOfChecks = 0;
    int checkLimit = 5;
    int allChecks;
};

int main() {
    CheckBook cb1(1000), cb2(500);

    for(int i=0; i<10;i++){
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }
    cout<<"cb1 check details"<<endl;
    cb1.displayChecks();
    cout<<"cb2 check details"<<endl;
    cb2.displayChecks();

    cout<<cb1.getallChecks()<<endl;
    cout<<cb2.getallChecks()<<endl;


    return 0;
}

void CheckBook::deposit(float amount) {
    balance+=amount;
    numOfChecks++;
}

void CheckBook::displayChecks() {
    for (int i=0; i<numOfChecks; i++) {
        cout << checks [i] << endl;
    }
}

bool CheckBook::writeCheck(float amount) {
    if (amount =< balance)
        if (numOfChecks < 5 && allchecks < 10)
            balance-=amount;
            numOfChecks++;
            allChecks++;
            return true;
        else
            return false;
    else
        return false;
