#include <bits/stdc++.h>
using namespace std;

struct PageNode
{
    int id;
    string url;
    string visitTime;
    PageNode *next = nullptr;

    PageNode(int pageID, string pageURL, string timeStr)
    {
        id = pageID;
        url = pageURL;
        visitTime = timeStr;
    }
};

class BrowserStack
{
public:
    PageNode *topNode = nullptr;
    int count = 0;

    void push(int id, string url, string visitTime)
    {
        PageNode *newNode = new PageNode(id, url, visitTime);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    bool pop()
    {
        if (isEmpty())
        {
            return false;
        }
        PageNode *temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
        return true;
    }

    PageNode* top()
    {
        return topNode;
    }

    bool isEmpty()
    {
        return topNode == nullptr;
    }

    int size()
    {
        return count;
    }

    void displayHistory()
    {
        if (isEmpty())
        {
            cout << "Tarixce bosdur!" << endl;
            return;
        }
        cout << endl;
        cout << "Brauzer Tarixcesi" << endl;
        PageNode *current = topNode;
        while (current != nullptr)
        {
            cout << "Page ID: " << current->id 
                 << " | URL: " << current->url 
                 << " | Visit Time: " << current->visitTime << endl;
            current = current->next;
        }
        cout << "------------------------------------------" << endl;
    }

    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

void runCode()
{
    BrowserStack history;
    int choice;
    int pageCounter = 1;

    while (true)
    {
        cout << endl;
        cout << "1. Visit Page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Current Page" << endl;
        cout << "4. Display History" << endl;
        cout << "5. Exit" << endl;
        cout << "Seciminiz: ";
        cin >> choice;

        if (choice == 1)
        {
            string url;
            string timeStr;

            cout << "URL daxil edin: ";
            cin >> url;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Visit Time daxil edin: ";
            getline(cin, timeStr);

            history.push(pageCounter++, url, timeStr);
            cout << "Sehifeye daxil olundu!" << endl;
        }
        else if (choice == 2)
        {
            if (history.pop())
            {
                cout << "Geri qayidildi (Evvelki sehife silindi)." << endl;
            }
            else
            {
                cout << "Geri qayitmaq ucun sehife yoxdur!" << endl;
            }
        }
        else if (choice == 3)
        {
            PageNode *current = history.top();
            if (current != nullptr)
            {
                cout << endl << "Cari Sehife:" << endl;
                cout << "Page ID: " << current->id << endl;
                cout << "URL: " << current->url << endl;
                cout << "Visit Time: " << current->visitTime << endl;
            }
            else
            {
                cout << "Hec bir sehife aciq deyil!" << endl;
            }
        }
        else if (choice == 4)
        {
            history.displayHistory();
        }
        else if (choice == 5)
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
    BrowserStack stack;

    auto startPush = chrono::high_resolution_clock::now();
    for (int i = 1; i <= count; i++)
    {
        stack.push(i, "tap.az" + to_string(i), "2026-10-21 12:00:00");
    }
    auto endPush = chrono::high_resolution_clock::now();
    double pushTime = chrono::duration<double, milli>(endPush - startPush).count();

    auto startPop = chrono::high_resolution_clock::now();
    for (int i = 1; i <= count; i++)
    {
        stack.pop();
    }
    auto endPop = chrono::high_resolution_clock::now();
    double popTime = chrono::duration<double, milli>(endPop - startPop).count();

    cout << "Emeliyyat sayi: " << count << endl;
    cout << "Push muddeti: " << pushTime << " ms" << endl;
    cout << "Pop muddeti: " << popTime << " ms" << endl;
    cout << "Umumi muddet: " << (pushTime + popTime) << " ms" << endl;
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