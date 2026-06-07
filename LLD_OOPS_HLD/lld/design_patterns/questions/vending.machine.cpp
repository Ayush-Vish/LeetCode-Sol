#include<bits/stdc++.h> 
using namespace std;



class VendingMachine;

class State{
public:
    virtual void insertMoney(VendingMachine* vm, int amount) = 0;
    virtual void selectProduct(VendingMachine* vm, string product) = 0;
    virtual void dispenseProduct(VendingMachine* vm) = 0;
};


class NoCoinState;
class HasCoinState;

class VendingMachine{
private:
    State* currentState;
public:
    VendingMachine(State *state) :currentState(state){}
    void setState(State* state){
        currentState = state;
    }
    
    void insertMoney(int amount){
        currentState->insertMoney(this, amount);
    }

    void selectProduct(string product){
        currentState->selectProduct(this, product);
    }


};


class NoCoinState : public State{
public:
    void insertMoney(VendingMachine*vm, int amount)override;
    void selectProduct(VendingMachine* vm, string product) override;
    void dispenseProduct(VendingMachine* vm) override;

};

class HasCoinState : public State{
public:
    void insertMoney(VendingMachine*vm, int amount)override;
    void selectProduct(VendingMachine* vm, string product) override;
    void dispenseProduct(VendingMachine* vm) override;
};
NoCoinState noCoinState;
HasCoinState hasCoinState;

// NoCoinState implementation
void NoCoinState::insertMoney(VendingMachine* vm, int amount) {
    cout << "Money inserted: " << amount << endl;
    vm->setState(&hasCoinState);
}

void NoCoinState::selectProduct(VendingMachine* vm, string product) {
    cout << "Please insert money first\n";
}

// HasCoinState implementation
void HasCoinState::insertMoney(VendingMachine* vm, int amount) {
    cout << "Money already inserted\n";
}

void HasCoinState::selectProduct(VendingMachine* vm, string product) {
    cout << "Dispensing " << product << endl;

    // Go back to initial state
    vm->setState(&noCoinState);
}
void NoCoinState::dispenseProduct(VendingMachine* vm) {
    cout << "Cannot dispense. Insert money first.\n";
}

void HasCoinState::dispenseProduct(VendingMachine* vm) {
    cout << "Product dispensed.\n";
    vm->setState(&noCoinState);
}


int main(){
    VendingMachine vm(&noCoinState);
    vm.insertMoney(100);
    vm.selectProduct("Soda");
    vm.insertMoney(50);
    vm.selectProduct("Chips");

    return 0;
    
}
