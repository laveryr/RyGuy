#include <iostream>
#include <cmath>
using namespace std;

struct Check {
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
private:
    float balance;
    Check checks [5];
    float lastDeposit;
    int numOfChecks = 0;
    int checkLimit = 5;
};

int main() {
    CheckBook cb1(1000);
    cb1.deposit(500);
    cb1.writeCheck(200);
    cb1.writeCheck(300);
    cb1.displayChecks();

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
        if (numOfChecks < 5)
            balance-=amount;
            numOfChecks++;
            return true;
        else
            return false;
    else
        return false;

}
