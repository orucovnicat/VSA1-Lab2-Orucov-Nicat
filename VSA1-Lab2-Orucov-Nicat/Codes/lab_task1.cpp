#include <bits/stdc++.h>
using namespace std;

struct SongNode
{
    int id;
    string name;
    string artist;
    SongNode *prev = nullptr;
    SongNode *next = nullptr;

    SongNode(int songID, string songName, string songArtist)
    {
        id = songID;
        name = songName;
        artist = songArtist;
    }
};

class MusicPlaylist
{
public:
    SongNode *head = nullptr;
    SongNode *tail = nullptr;
    SongNode *current = nullptr;

    void addMusic(int id, string name, string artist)
    {
        SongNode *newSong = new SongNode(id, name, artist);
        if (head == nullptr)
        {
            head = tail = current = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }

    bool deleteSong(int id)
    {
        if (head == nullptr)
        {
            return false;
        }

        SongNode *delNode = head;
        while (delNode != nullptr && delNode->id != id)
        {
            delNode = delNode->next;
        }

        if (delNode == nullptr)
        {
            return false;
        }

        if (delNode == current)
        {
            if (current->next != nullptr)
            {
                current = current->next;
            }
            else
            {
                current = current->prev;
            }
        }

        if (delNode == head && delNode == tail)
        {
            head = tail = current = nullptr;
        }
        else if (delNode == head)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (delNode == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            delNode->prev->next = delNode->next;
            delNode->next->prev = delNode->prev;
        }

        delete delNode;
        return true;
    }

    SongNode* searchSong(int id)
    {
        SongNode *temp = head;
        while (temp != nullptr && temp->id != id)
        {
            temp = temp->next;
        }
        return temp;
    }

    void displayPlaylist()
    {
        if (head == nullptr)
        {
            cout << "Pleylist bosdur!" << endl;
            return;
        }

        cout << endl;
        cout << "    Musiqi Pleylisti    " << endl;
        SongNode *temp = head;
        while (temp != nullptr)
        {
            cout << "ID: " << temp->id 
                 << " | Mahni: " << temp->name 
                 << " | Ifaci: " << temp->artist;
            if (temp == current)
            {
                cout << "  <-- [Oxunur]";
            }
            cout << endl;
            temp = temp->next;
        }
        cout << "------------------------------------------" << endl;
    }

    void playNext()
    {
        if (current != nullptr && current->next != nullptr)
        {
            current = current->next;
            cout << "Novbeti mahniya kecildi: " << current->name << " (" << current->artist << ")" << endl;
        }
        else
        {
            cout << "Novbeti mahni yoxdur (Siyahinin sonundasiniz)!" << endl;
        }
    }

    void playPrev()
    {
        if (current != nullptr && current->prev != nullptr)
        {
            current = current->prev;
            cout << "Evvelki mahniya kecildi: " << current->name << " (" << current->artist << ")" << endl;
        }
        else
        {
            cout << "Evvelki mahni yoxdur (Siyahinin basindasiniz)!" << endl;
        }
    }

    void showCurrent()
    {
        if (current != nullptr)
        {
            cout << endl << "Hazirda Oxunan Mahni:" << endl;
            cout << "ID: " << current->id << endl;
            cout << "Mahni: " << current->name << endl;
            cout << "Ifaci: " << current->artist << endl;
        }
        else
        {
            cout << "Hec bir mahni secilmeyib!" << endl;
        }
    }

    void clear()
    {
        SongNode *temp = head;
        while (temp != nullptr)
        {
            SongNode *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = current = nullptr;
    }
};

void runCode()
{
    MusicPlaylist playlist;
    int choice;
    int songCounter = 1;

    while (true)
    {
        cout << endl << "===== MUSIQI PLEYLISTI MENYUSU =====" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Delete Song" << endl;
        cout << "3. Search Song" << endl;
        cout << "4. Play Next Song" << endl;
        cout << "5. Play Previous Song" << endl;
        cout << "6. Current Song" << endl;
        cout << "7. Display Playlist" << endl;
        cout << "8. Exit" << endl;
        cout << "Seciminiz: ";
        cin >> choice;

        if (choice == 1)
        {
            string name, artist;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Mahninin adini daxil edin: ";
            getline(cin, name);
            cout << "Ifacinin adini daxil edin: ";
            getline(cin, artist);

            playlist.addMusic(songCounter++, name, artist);
            cout << "Mahni pleyliste elave olundu!" << endl;
        }
        else if (choice == 2)
        {
            int id;
            cout << "Silinecek mahninin ID-sini daxil edin: ";
            cin >> id;

            if (playlist.deleteSong(id))
            {
                cout << "Mahni ugurla silindi!" << endl;
            }
            else
            {
                cout << "Bu ID-ye uygun mahni tapilmadi!" << endl;
            }
        }
        else if (choice == 3)
        {
            int id;
            cout << "Axtarilan mahninin ID-sini daxil edin: ";
            cin >> id;

            SongNode *found = playlist.searchSong(id);
            if (found != nullptr)
            {
                cout << endl << "Mahni Tapildi:" << endl;
                cout << "ID: " << found->id << endl;
                cout << "Ad: " << found->name << endl;
                cout << "Ifaci: " << found->artist << endl;
            }
            else
            {
                cout << "Bele bir mahni movcud deyil!" << endl;
            }
        }
        else if (choice == 4)
        {
            playlist.playNext();
        }
        else if (choice == 5)
        {
            playlist.playPrev();
        }
        else if (choice == 6)
        {
            playlist.showCurrent();
        }
        else if (choice == 7)
        {
            playlist.displayPlaylist();
        }
        else if (choice == 8)
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

void runTest(int count)
{
    MusicPlaylist playlist;

    auto startAdd = chrono::high_resolution_clock::now();
    for (int i = 1; i <= count; i++)
    {
        playlist.addMusic(i, "Music " + to_string(i), "Artist " + to_string(i));
    }
    auto endAdd = chrono::high_resolution_clock::now();
    double addTime = chrono::duration<double, milli>(endAdd - startAdd).count();

    auto startSearch = chrono::high_resolution_clock::now();
    for (int i = 1; i <= count; i++)
    {
        playlist.searchSong(i);
    }
    auto endSearch = chrono::high_resolution_clock::now();
    double searchTime = chrono::duration<double, milli>(endSearch - startSearch).count();

    auto startDelete = chrono::high_resolution_clock::now();
    for (int i = 1; i <= count; i++)
    {
        playlist.deleteSong(i);
    }
    auto endDelete = chrono::high_resolution_clock::now();
    double deleteTime = chrono::duration<double, milli>(endDelete - startDelete).count();

    cout << "Say: " << count << endl;
    cout << "Add: " << addTime << " ms" << endl;
    cout << "Search: " << searchTime << " ms" << endl;
    cout << "Delete: " << deleteTime << " ms" << endl;
    cout << "Umumi: " << (addTime + searchTime + deleteTime) << " ms" << endl;
    cout << "-------------------------" << endl;
}

int main()
{
    cout << "Kodlarin isleme muddeti (ms)" << endl;
    runTest(100);
    runTest(1000);
    runTest(10000);

    runCode();

    return 0;
}