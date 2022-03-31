#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <math.h>
#include "simulation.h"
#include "queueAsArray.h"
using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers, int& transTime, int& tBetweenCArrival);

void runSimulation(int numberOfServers, int simulationTime, serverListType& serverList,
waitingCustomerQueueType& queue, int tBtwCustomerArrival, int transactionTime);

int main() {
 int simulationTime; // Total run time for the simulation as time units
 int numberOfServers; // Number of available servers for the queue
 int transactionTime; // Time that it takes for a customer/server to !nish a single transaction
 int tBtwCustomerArrival; // AVERAGE time between the arrival of each customer

 setSimulationParameters(simulationTime, numberOfServers, transactionTime, tBtwCustomerArrival);
 
 serverListType serverList = serverListType(numberOfServers); // Establish a list for all servers
 waitingCustomerQueueType queue = waitingCustomerQueueType(); // Establish a queue for all

 runSimulation(numberOfServers,simulationTime, serverList, queue, tBtwCustomerArrival,
transactionTime);
 return 0;
}

void setSimulationParameters(int& sTime, int& numOfServers, int& transTime, int& tBetweenCArrival) {
 cout << endl;
 cout << " Enter the simulation time: ";
 cin >> sTime;
 cout << " Enter the number of servers: ";
 cin >> numOfServers;
 cout << " Enter the transaction time: ";
 cin >> transTime;
 cout << " Enter the average time between customer arrivals: ";
 cin >> tBetweenCArrival;
 cout << endl;
 cout << "•••••••••••••••••••••• Begin Simulation ••••••••••••••••••••••" << endl;
}

void runSimulation(int numServers, int simulationTime, serverListType& serverList,
waitingCustomerQueueType& queue, int tBtwCustomerArrival, int transactionTime) {
 // Calculate the cut o" for the probability of a customer arriving using the Poisson Distributoin(exp(-1/NumCustomers))
 const double EulerConstant = std::exp(1.0);
 double cutOff = pow(EulerConstant, -1.0/tBtwCustomerArrival);
 
 srand(time(NULL));

 double rNum; // Random number using srand to compare against the cut o"
 int totalNumCustomers = 0; // Counter for the number of processed customers as they enter the
 bool queueChanged; // Flag to check if the queue has changed during each tick
 int totalWaitingTime = 0; // Cumulative waiting time of all customers
 for (int tick = 1; tick<=simulationTime; tick++){
 queueChanged = false;
 // Process a new tick for all servers -> set servers with completed transactions free!
 serverList.updateServers(cout);
 // If there are any customers in the queue, update their waiting times
 if (!queue.isEmptyQueue()){
 queue.updateWaitingQueue();
 }
 // If a new customer arrives at the current tick, add them to the waiting queue
 rNum = ((double) rand() / (RAND_MAX));
 if(rNum > cutOff){
 totalNumCustomers++;
 cout << "\x1b[31mCustomer number " << totalNumCustomers << " came at time: " << tick << "\x1b[0m"
<< endl;
 customerType nextUp = customerType(totalNumCustomers, tick, 0, transactionTime);
 queue.addQueue(nextUp);
 queueChanged = true;
 }
 // If there are free servers and customers are waiting in the queue, process a customer
 for (int i = 0; i < numServers && (serverList.getFreeServerID() != -1); i++){
 if(!queue.isEmptyQueue()){
 customerType beingServed = queue.front();
 serverList.setServerBusy(serverList.getFreeServerID(), beingServed, transactionTime);
 queue.deleteQueue();
 }
 }
 // If there are more customers left in the queue, add their wait times to the cumulative waiting time

 if (!queue.isEmptyQueue()) {
 totalWaitingTime += queue.getCount();
 if (queueChanged){
 cout << "\x1b[36mCustomers in the queue: ";
 queue.printQueue();
 cout<<"\x1b[0m\n";

 }
 }
 } // End of the clock loop
 serverList.updateServers(cout);
 // If there are any customers in the queue, update their waiting times
 if (!queue.isEmptyQueue()){
 queue.updateWaitingQueue();
 }
 // Output the input data
 cout << endl << "Total simulation time: " << simulationTime << endl;
 cout << "Number of servers: " << numServers << endl;
 cout << "Transaction time: " << transactionTime << endl;
 cout << "Average time difference between customer arrival: " << tBtwCustomerArrival << endl << endl;
 // Output the calculated simulation data
 cout << "\x1b[33mTotal waiting time: " << totalWaitingTime << endl;
 cout << "Number of customers that completed a transaction: " <<
serverList.getNumCompletedTransactions() << endl;
 cout << "Number of customers left in the servers:" << serverList.getNumberOfBusyServers() << endl;
 cout << "Number of customers left in the waiting queue: " << queue.getCount() << endl;
 cout << "Average waiting time: " <<
(double)totalWaitingTime/(serverList.getNumCompletedTransactions()+serverList.getNumberOfBusyServers
()+queue.getCount()) <<"\x1b[0m\n";
 cout << "•••••••••••••••••••••• End Simulation ••••••••••••••••••••••" << endl << endl;
}
