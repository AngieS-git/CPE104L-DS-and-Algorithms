#include <fstream>
#include <string>
#include "queueAsArray.h"
using namespace std;
class customerType {
public:
 customerType(int cN = 0, int arrvTime = 0, int wTime = 0, int tTime = 0);
 void setCustomerInfo(int customerN = 0, int inTime = 0, int wTime = 0, int tTime = 0);
 int getWaitingTime() const;
 void setWaitingTime(int time);
 void incrementWaitingTime();
 int getArrivalTime() const;
 int getTransactionTime() const;
 int getCustomerNumber() const;
private:
 int customerNumber;
 int arrivalTime;
 int waitingTime;
 int transactionTime;
};
class serverType {
public:
 serverType();
 bool isFree() const;
 void setBusy();
 void setFree();
 void setTransactionTime(int t);
 void setTransactionTime();
 int getRemainingTransactionTime() const;
 void decreaseTransactionTime();
 void setCurrentCustomer(customerType cCustomer);
 int getCurrentCustomerNumber() const;
 int getCurrentCustomerArrivalTime() const;
 int getCurrentCustomerWaitingTime() const;
 int getCurrentCustomerTransactionTime() const;
private:
 customerType currentCustomer;
 string status;
 int transactionTime;
};
class serverListType {
public:
 serverListType(int num = 1);
 ~serverListType();
 int getFreeServerID() const;
 int getNumberOfBusyServers() const;
 void setServerBusy(int serverID, customerType cCustomer, int tTime);
 void setServerBusy(int serverID, customerType cCustomer);
 void updateServers(ostream& outFile);
 int getNumCompletedTransactions();
 //Return the number of completed transactions
private:
 int numOfServers;
 serverType *servers;
 int numCompletedTransactions; // New variable to count all completed transactions
};
class waitingCustomerQueueType: public queueType<customerType> {
public:
 waitingCustomerQueueType(int size = 100);
 void updateWaitingQueue();
 void printQueue();
};
