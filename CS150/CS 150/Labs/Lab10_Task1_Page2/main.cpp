#indef JUICEMACHINE_H
#define JUICEMACHINE_H

class cashRegister
{
public:
    int getCurrentBalance() const;
    void acceptAmount(int amountIn);
    cashRegister(int cashIn);
private:
    int cashOnHand;
};

class dispenserType
{
public:
    int getNoOfItems() const;
    int getCost() const;
    void makeSale();
    dispenserType(int setNoOfItems = 50, int setCost = 50);

private:
    int numberOfItems;
    int cost;
};
#endif
