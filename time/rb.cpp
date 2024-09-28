#include <cstdlib>
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

template<typename t, typename u>
class process {
public:
    pid_t pNum = 0;
    u startAT = 0, AT = 0, BTLeft = 0, BT = 0, tempBT = 0, CT = 0, TAT = 0, WT = 0, RT = 0;
    int priority = 0;
    
    //Set functions
    //Completion time
    void setCT(u time) {
        CT = time;
        setTAT();
        setWT();
    }
  
    //Turn around time
    void setTAT() {
        TAT = CT - startAT;
    }
  
    //Waiting time
    void setWT() {
        WT = TAT - BT;
    }
    //Set starting arrival time
    void Pset() {
        startAT = AT;
        BTLeft = BT;
    }
    //Response time
    void setRT(u time) {
        RT = time - startAT;
    }
    //End set functions

    //Figure out if the Arrival time is first over the priority or priority queue
    friend bool operator<(const t& a, const t& b) {
        return a.AT > b.AT;
    }
};
  
//FCFS algorithm
template<typename t>
priority_queue<t> FCFS(priority_queue<t> readyQueue, queue<t>* gantt) {
    priority_queue<t> completionQueue;
    t p;
    time_t clock = 0;
  
    //Check if queue is empty
    while (!readyQueue.empty()) {
  
        while (clock < readyQueue.top().AT) {
            p.tempBT++;
            clock++;
        }
        if (p.tempBT > 0) {
            p.pNum = -1;
            p.CT = clock;
            (*gantt).push(p);
        }

        p = readyQueue.top();
        readyQueue.pop();
        p.setRT(clock);

        while (p.BTLeft > 0) {
            p.tempBT++;
            p.BTLeft--;
            clock++;
        }

        p.setCT(clock);
        //Gantt chart update 
        (*gantt).push(p);
        p.tempBT = 0;
  
        //Queue update
        completionQueue.push(p);
    }
    return completionQueue;
}
  
//RB algorithm
template<typename t>
priority_queue<t> RB(priority_queue<t> readyQueue, time_t Time_Slice, queue<t>* gantt) {
    priority_queue<t> completionQueue;
    t p;
    time_t clock = 0;
  
    while (!readyQueue.empty()) {
        while (clock < readyQueue.top().AT) {
            p.tempBT++;
            clock++;
        }
        if (p.tempBT > 0) {
            p.pNum = -1;
            p.CT = clock;
            (*gantt).push(p);
        }
        p = readyQueue.top();
        readyQueue.pop();
  
        if (p.AT == p.startAT)
            p.setRT(clock);
  
        while (p.BTLeft > 0 && (p.tempBT < Time_Slice || readyQueue.empty() || clock < readyQueue.top().AT)) {
            p.tempBT++;
            p.BTLeft--;
            clock++;
        }
  
        if (p.BTLeft == 0) {
            p.AT = p.startAT;
            p.setCT(clock);
            (*gantt).push(p);
            p.tempBT = 0;
            completionQueue.push(p);
        }
        else {
            p.AT = clock;
            p.CT = clock;
            (*gantt).push(p);
            p.tempBT = 0;
            readyQueue.push(p);
        }
    }
  
    return completionQueue;
}

//SJFP for non and preemptive
template<typename t>
t Pindex(priority_queue<t>* main_queue, int index) {
    priority_queue<t> RM;
    int i;
    t p;
    switch (index) {
    case 0:
        p = (*main_queue).top();
        (*main_queue).pop();
        break;
    default:
        for (i = 0; i < index; i++) {
            RM.push((*main_queue).top());
            (*main_queue).pop();
        }
        p = (*main_queue).top();
        (*main_queue).pop();
        while (!(*main_queue).empty()) {
            RM.push((*main_queue).top());
            (*main_queue).pop();
        }
        (*main_queue) = RM;
        break;
    }
    return p;
}

template<typename t, typename u>
u MinBT(priority_queue<t> main_queue, u clock)
{
    u min = 0;
    while (!main_queue.empty() && main_queue.top().AT <= clock) {
        if (min == 0 || min > main_queue.top().BTLeft)
            min = main_queue.top().BTLeft;
        main_queue.pop();
    }
    return min;
}

template<typename t, typename u>
int MinBTIndex(priority_queue<t> main_queue, u limit)
{
    int index, i = 0;
    u min = 0;
    while (!main_queue.empty() && main_queue.top().AT <= limit) {
        if (min == 0 || main_queue.top().BTLeft < min) {
            min = main_queue.top().BTLeft;
            index = i;
        }
        main_queue.pop();
        i++;
    }
    return index;
}
//SJFP for non and preemptive end

//SJFP preemptive
template<typename t, typename u>
priority_queue<t> SJFP(priority_queue<t> readyQueue, queue<t>* gantt)
{
    priority_queue<t> completion_queue;
    t p;
    u clock = 0;
  
    while (!readyQueue.empty()) {
        while (clock < readyQueue.top().AT) {
            p.tempBT++;
            clock++;
        }
        if (p.tempBT > 0) {
            p.pNum = -1;
            p.CT = clock;
            (*gantt).push(p);
        }
        p = Pindex(&readyQueue, MinBTIndex(readyQueue, clock));
        if (p.AT == p.startAT)
            p.setRT(clock);
        while (p.BTLeft > 0 && (readyQueue.empty() || clock < readyQueue.top().AT || p.BTLeft <= MinBT(readyQueue, clock))) {
            p.BTLeft--;
            p.tempBT++;
            clock++;
        }
        if (p.BTLeft == 0) {
            p.AT = p.startAT;
            p.setCT(clock);
            (*gantt).push(p);
            p.tempBT = 0;
            completion_queue.push(p);
        }
        else {
            p.AT = clock;
            p.CT = clock;
            (*gantt).push(p);
            p.tempBT = 0;
            readyQueue.push(p);
        }
    }
  
    return completion_queue;
}

//SJFP Non-preemptive
template<typename t, typename u>
priority_queue<t> SJFNP(priority_queue<t> readyQueue, queue<t>* gantt)
{
    priority_queue<t> completion_queue;
    t p;
    u clock = 0;
    while (!readyQueue.empty()) {
        while (clock < readyQueue.top().AT) {
            p.tempBT++;
            clock++;
        }
        if (p.tempBT > 0) {
            p.pNum = -1;
            p.CT = clock;
            (*gantt).push(p);
        }
        p = Pindex(&readyQueue, MinBTIndex(readyQueue, clock));
        p.setRT(clock);
        while (p.BTLeft > 0) {
            p.tempBT++;
            p.BTLeft--;
            clock++;
        }
        p.setCT(clock);
        (*gantt).push(p);
        p.tempBT = 0;
        completion_queue.push(p);
    }
    return completion_queue;
}

//elements in the table
template<typename t>
priority_queue<t> setData() {
    priority_queue<t> readyQueue;
    t temp;

    //store variables for file
    int processNum, arrivalTime, burstTime, prio;
    int l=0, i=0;
    vector<int>PN;
    vector<int>at;
    vector<int>bt;
    vector<int>p;

    //Read file
    ifstream FileRead("preeminput.txt");
    while (FileRead >> arrivalTime >> burstTime >> prio >> processNum) {
    at.push_back(arrivalTime);
    bt.push_back(burstTime);
    p.push_back(prio);
    PN.push_back(processNum);
    l++;
    }

    //table 
    bool high;
    cout << endl << "+----------------+--------------" << "+------------+-----------------" << "+-----------------+--------------+---------------+";

    if (high == true) {
        cout << "----------+" << endl;
    }
    else{
        cout << endl;
    }
        
    cout << "| Process Number | Arrival Time " << "| Burst Time | Completion Time " << "| Turnaround Time | Waiting Time | Response Time |";

    if (high == true) {
        cout << " Priority |" << endl;
    }
    else{
        cout << endl;
    }

    cout << "+----------------+--------------" << "+------------+-----------------" << "+-----------------+--------------+---------------+";
    if (high == true) {
        cout << "----------+" << endl;
    }
    else{
        cout << endl;
    }


    for(int i=0;i<l;++i){
        //process
        processNum = to_string(PN[i]).length();
        cout << '|' << string(8 - processNum / 2 - processNum % 2, ' ') << PN[i] << string(8 - processNum / 2, ' ');
        //AT
        arrivalTime = to_string(at[i]).length();
        cout << '|' << string(7 - arrivalTime / 2 - arrivalTime % 2, ' ') << at[i] << string(7 - arrivalTime / 2, ' ');
        //BT
        burstTime = to_string(bt[i]).length();
        cout << '|' << string(6 - burstTime / 2 - burstTime % 2, ' ') << bt[i] << string(6 - burstTime / 2, ' ');
        //CT
        cout << '|' << string(8, ' ') << '0' << string(8, ' ');
        //TAT
        cout << '|' << string(8, ' ') << '0' << string(8, ' ');
        //WT
        cout << '|' << string(7, ' ') << '0' << string(6, ' ');
        //RT
        cout << '|' << string(7, ' ') << '0' << string(7, ' ');
        //priority
        if (high == true) {
            prio = to_string(p[i]).length();
            cout << '|' << string(8 - prio / 2 - prio % 2, ' ') << p[i] << string(8 - prio / 2, ' ');
        }
        cout << "|\n";
    }

    cout << "+----------------+--------------" << "+------------+-----------------" << "+-----------------+--------------+---------------+";
    if (high == true) { 
        cout << "----------+";
    }

    //Close file
    FileRead.close();

    for(int i=0;i<l;++i){
        temp.AT = at[i];
        temp.BT = bt[i];
        temp.priority = p[i];
        temp.pNum = PN[i];
        temp.Pset();
        readyQueue.push(temp);
    }
    
    return readyQueue;
}
  
//Waiting Time
template<typename t>
double getWT(priority_queue<t> processes) {
    double total = 0;
    while (!processes.empty()) {
        total += processes.top().WT;
        processes.pop();
    }
    return total;
}
  
//Turn around time
template<typename t>
double getTAT(priority_queue<t> processes) {
    double total = 0;
    while (!processes.empty()) {
        total += processes.top().TAT;
        processes.pop();
    }
    return total;
}
  
//Completion time
template<typename t>
double getCT(priority_queue<t> processes) {
    double total = 0;
    while (!processes.empty()) {
        total += processes.top().CT;
        processes.pop();
    }
    return total;
}
  
//Response time
template<typename t>
double getRT(priority_queue<t> processes) {
    double total = 0;
    while (!processes.empty()) {
        total += processes.top().RT;
        processes.pop();
    }
    return total;
}
  
//Print table and Queue
template<typename t>
void printTableQueue(priority_queue<t> main_queue, bool high) {
    int i = 0, temp, size = main_queue.size();
    priority_queue<t> tempq = main_queue;
    double temp1;

    //queue
    cout << endl;
    //ct
    temp1 = getCT(tempq);
    cout << "\nTotal completion time: " << temp1 << endl;
    cout << "Average completion time: " << temp1 / size << endl;
    //tat
    temp1 = getTAT(tempq);
    cout << "\nTotal turnaround time: " << temp1 << endl;
    cout << "Average turnaround time: " << temp1 / size << endl;
    //wt
    temp1 = getWT(tempq);
    cout << "\nTotal waiting time: " << temp1 << endl;
    cout << "Average waiting time: " << temp1 / size << endl;
    //rt
    temp1 = getRT(tempq);
    cout << "\nTotal response time: " << temp1 << endl;
    cout << "Average response time: " << temp1 / size << endl;
    
    //table 
    cout << endl << "+----------------+--------------" << "+------------+-----------------" << "+-----------------+--------------+---------------+";

    if (high == true) {
        cout << "----------+" << endl;
    }
    else{
        cout << endl;
    }
        
    cout << "| Process Number | Arrival Time " << "| Burst Time | Completion Time " << "| Turnaround Time | Waiting Time | Response Time |";

    if (high == true) {
        cout << " Priority |" << endl;
    }
    else{
        cout << endl;
    }

    cout << "+----------------+--------------" << "+------------+-----------------" << "+-----------------+--------------+---------------+";
    if (high == true) {
        cout << "----------+" << endl;
    }
    else{
        cout << endl;
    }
    
    while (!main_queue.empty()) {
        //process
        temp = to_string(main_queue.top().pNum).length();
        cout << '|' << string(8 - temp / 2 - temp % 2, ' ') << main_queue.top().pNum << string(8 - temp / 2, ' ');
        //AT
        temp = to_string(main_queue.top().startAT).length();
        cout << '|' << string(7 - temp / 2 - temp % 2, ' ') << main_queue.top().startAT << string(7 - temp / 2, ' ');
        //BT
        temp = to_string(main_queue.top().BT).length();
        cout << '|' << string(6 - temp / 2 - temp % 2, ' ') << main_queue.top().BT << string(6 - temp / 2, ' ');
        //CT
        temp = to_string(main_queue.top().CT).length();
        cout << '|' << string(8 - temp / 2 - temp % 2, ' ') << main_queue.top().CT << string(9 - temp / 2, ' ');
        //TAT
        temp = to_string(main_queue.top().TAT).length();
        cout << '|' << string(8 - temp / 2 - temp % 2, ' ') << main_queue.top().TAT << string(9 - temp / 2, ' ');
        //WT
        temp = to_string(main_queue.top().WT).length();
        cout << '|' << string(7 - temp / 2 - temp % 2, ' ') << main_queue.top().WT << string(7 - temp / 2, ' ');
        //RT
        temp = to_string(main_queue.top().RT).length();
        cout << '|' << string(7 - temp / 2 - temp % 2, ' ') << main_queue.top().RT << string(8 - temp / 2, ' ');
        //priority
        if (high == true) {
            temp = to_string(main_queue.top().priority).length();
            cout << '|' << string(5 - temp / 2 - temp % 2, ' ') << main_queue.top().priority << string(5 - temp / 2, ' ');
        }
        cout << "|\n";
        main_queue.pop();
    }

    cout << "+----------------+--------------" << "+------------+-----------------" << "+-----------------+--------------+---------------+";
    if (high == true) { 
        cout << "----------+";
    }
}
  
//Print gantt chart
template<typename t>
void printGanttChart(queue<t> gantt) {
    int temp, prev = 0;
    queue<t> spaces = gantt;
    cout << "\n\nGantt Chart: \n\n+";
  
    while (!spaces.empty()) {
        cout << string(to_string(spaces.front().pNum).length() + (spaces.front().pNum != -1) + 2 * spaces.front().tempBT, '-') << "+";
        spaces.pop();
    }

    cout << "\n|";
    spaces = gantt;
  
    //Process numbers gantt chart
    while (!spaces.empty()) {
        cout << string(spaces.front().tempBT, ' ');
        if (spaces.front().pNum == -1){
            cout << "IS" << string(spaces.front().tempBT, ' ') << '|';
        }
        else{
            cout << "P" << spaces.front().pNum << string(spaces.front().tempBT, ' ') << '|';
            spaces.pop();
        }
    }

    spaces = gantt;
    cout << "\n+";
  
    while (!spaces.empty()) {
        cout << (string(to_string(spaces.front().pNum).length()
                            + (spaces.front().pNum != -1)
                            + 2 * spaces.front().tempBT,
                        '-'))
             << "+";
        spaces.pop();
    }
    spaces = gantt;
    cout << "\n0";

    while (!spaces.empty()) {
        temp = to_string(spaces.front().CT).length();
        cout << (string(to_string(spaces.front().pNum).length() + (spaces.front().pNum != -1) + 2 * spaces.front().tempBT - temp / 2 - prev, ' ')) << spaces.front().CT;
        prev = temp / 2 - temp % 2 == 0;
        spaces.pop();
    }
    cout << "\n\n";
}
  
// Driver Code
template <typename t>
int main() {
    int i=0;

    while(i!=7){
        cout << "STL Non-Preemptive Scheduling RR enter 1: " << endl;
        cout << "STL Preemptive Scheduling FCFS enter 2: " << endl;
        cout << "STL Non-Preemptive Scheduling SJF enter 3: " << endl;
        cout << "STL Preemptive Scheduling SJF enter 4: " << endl;
        cout << "Linked List Preemptive Scheduling enter 5: " << endl;
        cout << "Linked List Non-Preemptive Scheduling enter 6: " << endl;
        cout << "To leave enter 7: " << endl;
        cin >> i;
        
        if(i==1){
            //Queue
            priority_queue<t> readyQueue;
            priority_queue<t> completionQueue;

            //Queue with Gantt Chart process
            queue<t> gantt;
            int tq = 2;
            readyQueue = t::setData();
            
            //Completion data
            completionQueue = RB(readyQueue, tq, &gantt);
        
            //Print table
            printTableQueue(completionQueue, false);
            cout <<endl << "\nTime Quantum for round robin: " << tq << endl;
        
            //Print Gantt Chart
            printGanttChart(gantt);
        }
        else if(i==2){
            //Queue
            priority_queue<t> readyQueue;
            priority_queue<t> completionQueue;

            //Queue with Gantt Chart process
            queue<t> gantt;
            readyQueue = t::setData();
            
            //Completion data
            completionQueue = FCFS(readyQueue, &gantt);
        
            //Print table
            printTableQueue(completionQueue, false);
        
            //Print Gantt Chart
            printGanttChart(gantt);
        }
        if(i==3){
            //Queue
            priority_queue<t> readyQueue;
            priority_queue<t> completionQueue;

            //Queue with Gantt Chart process
            queue<t> gantt;
            readyQueue = t::setData();
            
            //Completion data
            completionQueue = SJFNP(readyQueue, &gantt);
        
            //Print table
            printTableQueue(completionQueue, false);
        
            //Print Gantt Chart
            printGanttChart(gantt);
        }
        else if(i==4){
            //Queue
            priority_queue<t> readyQueue;
            priority_queue<t> completionQueue;

            //Queue with Gantt Chart process
            queue<t> gantt;
            readyQueue = t::setData();
            
            //Completion data
            completionQueue = SJFP(readyQueue, &gantt);
        
            //Print table
            printTableQueue(completionQueue, false);
        
            //Print Gantt Chart
            printGanttChart(gantt);
        }
    }
    return 0;
}