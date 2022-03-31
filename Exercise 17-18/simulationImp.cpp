//TODO: Implement the methods specified in the instructions.
// Methods provided in the textbook are defined below
//NOTE: Various methods defined below have portions commented out to avoid compilation errors.  Uncomment these portions as you define the methods.  Commented out sections are marked with the word 'TODO'

#include <iostream>
#include <string>
#include <cstdlib>

#include "simulation.h"
#include "queueAsArray.h"

using namespace std;


//*************** customerType ************
void customerType::setCustomerInfo(int customerN, int arrvTime,
                                   int wTime, int tTime)
{
    customerNumber = customerN;
    arrivalTime = arrvTime;
    waitingTime = wTime;
    transactionTime = tTime;
}

customerType::customerType(int customerN, int arrvTime, int wTime,
                           int tTime)
{
    setCustomerInfo(customerN, arrvTime, wTime, tTime);
}


int customerType::getWaitingTime() const
{
	return waitingTime;
}

void customerType::incrementWaitingTime()
{
    waitingTime++;
}

//**************** serverType **********

serverType::serverType()
{
    status = "free";
    transactionTime = 0;
}

bool serverType::isFree() const
{
    return (status == "free");
}

void serverType::setBusy()
{
    status = "busy";
}

void serverType::setFree()
{
    status = "free";
}

void serverType::setTransactionTime(int t)
{
    transactionTime = t;
}

void serverType::setTransactionTime()
{
    //TODO: uncomment once getTransactionTime is defined
    /*
    int time;

    time = currentCustomer.getTransactionTime();

    transactionTime = time;
    */
}

void serverType::decreaseTransactionTime()
{
    transactionTime--;
}

//************** serverListType ***********

serverListType::serverListType(int num)
{
    numOfServers = num;
    servers = new serverType[num];
}

serverListType::~serverListType()
{
    delete [] servers;
}

int serverListType::getFreeServerID() const
{
    int serverID = -1;

    int i;

    for (i = 0; i < numOfServers; i++)
        if (servers[i].isFree())
        {
            serverID = i;
            break;
        }

    return serverID;
}

int serverListType::getNumberOfBusyServers() const
{
    int busyServers = 0;

    int i;

    for (i = 0; i < numOfServers; i++)
        if (!servers[i].isFree())
            busyServers++;

    return busyServers;
}

void serverListType::setServerBusy(int serverID,
                                   customerType cCustomer,
                                   int tTime)
{
    servers[serverID].setBusy();
    servers[serverID].setTransactionTime(tTime);
    //TODO: uncomment once setCurrentCustomer has been defined
    //servers[serverID].setCurrentCustomer(cCustomer);
}

void serverListType::setServerBusy(int serverID,
                                   customerType cCustomer)
{
    //TODO: uncomment once getTransactionTime and setCurrentCustomer have been defined
    /*
	int time;

	time = cCustomer.getTransactionTime();

	servers[serverID].setBusy();
	servers[serverID].setTransactionTime(time);
    servers[serverID].setCurrentCustomer(cCustomer);
    */
}


void serverListType::updateServers(ostream& outFile)
{
    int i;

    for (i = 0; i < numOfServers; i++)
        if (!servers[i].isFree())
        {
            servers[i].decreaseTransactionTime();

            //TODO: Uncomment this block once the methods contained in it have been defined
            /*
            if (servers[i].getRemainingTransactionTime() == 0)
            {
                outFile << "From server number " << (i + 1)
                        << " customer number "
                        << servers[i].getCurrentCustomerNumber()
                        << "\n     departed at time unit "
                        << servers[i].
                              getCurrentCustomerArrivalTime()
                           + servers[i].
                              getCurrentCustomerWaitingTime()
                           + servers[i].
                              getCurrentCustomerTransactionTime()
                        << endl;
                servers[i].setFree();
            }
            */
        }
}

//*************** waitQueue ************


waitingCustomerQueueType::waitingCustomerQueueType(int size)
                          :queueType<customerType>(size)
{
}

void waitingCustomerQueueType::updateWaitingQueue()
{
    customerType cust;

    //TODO: uncomment once setWaitingTime is defined
    //cust.setWaitingTime(-1);
    int wTime = 0;

	addQueue(cust);

    while (wTime != -1)
    {
        cust = front();
        deleteQueue();

        wTime = cust.getWaitingTime();
        if (wTime == -1)
            break;
        cust.incrementWaitingTime();
        addQueue(cust);
	}
}
