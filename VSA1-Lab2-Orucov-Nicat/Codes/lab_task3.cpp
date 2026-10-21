#include <bits/stdc++.h>
using namespace std;

struct PassengerNode
{
    int id;
    string name;
    string flightNumber;
    PassengerNode *next = nullptr;

    PassengerNode(int pID, string pName, string pFlight)
    {
        id = pID;
        name = pName;
        flightNumber = pFlight;
    }
};

class PassengerQueue
{
public:
    PassengerNode *frontNode = nullptr;
    PassengerNode *rearNode = nullptr;
    int count = 0;

    void enqueue(int id, string name, string flightNumber)
    {
        PassengerNode *newNode = new PassengerNode(id, name, flightNumber);
        if (rearNode == nullptr)
        {
            frontNode = rearNode = newNode;
        }
        else
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    bool dequeue()
    {
        if (isEmpty())
        {
            return false;
        }
        PassengerNode *temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode == nullptr)
        {
            rearNode = nullptr;
        }
        delete temp;
        count--;
        return true;
    }

    PassengerNode* peek()
    {
        return frontNode;
    }

    bool isEmpty()
    {
        return frontNode == nullptr;
    }

    int size()
    {
        return count;
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Novbe bosdur!" << endl;
            return;
        }
        cout << endl;
        cout << "    Serinisin Novbesi    " << endl;
        PassengerNode *current = frontNode;
        while (current != nullptr)
        {
            cout << "ID: " << current->id 
                 << " | Ad: " << current->name 
                 << " | Ucus No: " << current->flightNumber << endl;
            current = current->next;
        }
        cout << "------------------------------------------" << endl;
    }

    void clear()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

void runCode()
{
    PassengerQueue q;
    int choice;
    int passengerCounter = 1;

    while (true)
    {
        cout << endl << "===== SERNISIN QEYDIYYAT MENYUSU =====" << endl;
        cout << "1. Add Passenger" << endl;
        cout << "2. Check-In Passenger" << endl;
        cout << "3. Peek Passenger" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Count Passengers" << endl;
        cout << "6. Exit" << endl;
        cout << "Seciminiz: ";
        cin >> choice;

        if (choice == 1)
        {
            string name, flight;
            cout << "Ad daxil edin: ";
            cin >> name;
            cout << "Ucus nomresini daxil edin: ";
            cin >> flight;

            q.enqueue(passengerCounter++, name, flight);
            cout << "Sernisin novbeye elave olundu!" << endl;
        }
        else if (choice == 2)
        {
            PassengerNode *nextP = q.peek();
            if (nextP != nullptr)
            {
                cout << "Check-in edildi: " << nextP->name 
                     << " (Ucus: " << nextP->flightNumber << ")" << endl;
                q.dequeue();
            }
            else
            {
                cout << "Novbede sernisin yoxdur!" << endl;
            }
        }
        else if (choice == 3)
        {
            PassengerNode *nextP = q.peek();
            if (nextP != nullptr)
            {
                cout << endl << "Novbedeki Ilk Sernisin:" << endl;
                cout << "ID: " << nextP->id << endl;
                cout << "Ad: " << nextP->name << endl;
                cout << "Ucus No: " << nextP->flightNumber << endl;
            }
            else
            {
                cout << "Novbede sernisin yoxdur!" << endl;
            }
        }
        else if (choice == 4)
        {
            q.displayQueue();
        }
        else if (choice == 5)
        {
            cout << "Novbedeki sernisin sayi: " << q.size() << endl;
        }
        else if (choice == 6)
        {
            cout << "Proqramdan cixilir..." << endl;
            break;
        }
        else
        {
            cout << "Yanlis secim! Yeniden cehd edin." << endl;
        }
    }
}

void runExperiment(int count)
{
    PassengerQueue q;

    auto startEnqueue = chrono::high_resolution_clock::now();
    for (int i = 1; i <= count; i++)
    {
        q.enqueue(i, "Passenger" + to_string(i), "J2-" + to_string(100 + (i % 50)));
    }
    auto endEnqueue = chrono::high_resolution_clock::now();
    double enqueueTime = chrono::duration<double, milli>(endEnqueue - startEnqueue).count();

    auto startPeek = chrono::high_resolution_clock::now();
    for (int i = 1; i <= count; i++)
    {
        volatile auto *p = q.peek();
    }
    auto endPeek = chrono::high_resolution_clock::now();
    double peekTime = chrono::duration<double, milli>(endPeek - startPeek).count();

    auto startDequeue = chrono::high_resolution_clock::now();
    for (int i = 1; i <= count; i++)
    {
        q.dequeue();
    }
    auto endDequeue = chrono::high_resolution_clock::now();
    double dequeueTime = chrono::duration<double, milli>(endDequeue - startDequeue).count();

    cout << "Sernisin sayi: " << count << endl;
    cout << "Enqueue muddeti: " << enqueueTime << " ms" << endl;
    cout << "Peek muddeti: " << peekTime << " ms" << endl;
    cout << "Dequeue muddeti: " << dequeueTime << " ms" << endl;
    cout << "Umumi muddet: " << (enqueueTime + peekTime + dequeueTime) << " ms" << endl;
    cout << "-------------------------" << endl;
}

int main()
{
    cout << "Kodlarin isleme muddeti (ms)" << endl;
    runExperiment(100);
    runExperiment(1000);
    runExperiment(10000);

    runCode();

    return 0;
}