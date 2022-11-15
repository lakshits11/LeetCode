class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int loginMin = stoi(loginTime.substr(0, 2))*60 + stoi(loginTime.substr(3, 2));
        int logoutMin = stoi(logoutTime.substr(0, 2))*60 + stoi(logoutTime.substr(3, 2));
        if(loginMin > logoutMin)
        {
            logoutMin += 1440;
        }
        if(loginMin%15!=0)
        {
            loginMin += (15-(loginMin%15));
        }
        if(logoutMin%15!=0)
        {
            logoutMin -= (loginMin%15);
        }
        
        return (logoutMin - loginMin)/15;
    }
};