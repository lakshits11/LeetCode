class Bank {
private:
    vector<long long> bankk;
public:
    Bank(vector<long long>& balance) {
        bankk = balance;
    }
    
    bool transfer(int ac1, int ac2, long long money) {
        if(ac1>bankk.size() || ac2>bankk.size())
            return false;
        if(bankk[ac1-1] < money)
            return false;
        bankk[ac1-1] -= money;
        bankk[ac2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > bankk.size())
            return false;
        bankk[account-1] += money;
        return true;
    }
    
    bool withdraw(int ac1, long long money) {
        if(ac1 > bankk.size())
            return false;
        if(bankk[ac1-1] < money)
            return false;
        bankk[ac1-1] -= money;
        return true;
    }
};