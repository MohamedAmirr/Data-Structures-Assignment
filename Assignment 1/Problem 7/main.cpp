#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

void BiasedSort(vector<string> &Songs) {
    list<string> li;
    string temp;

    for (int i = 0; i < Songs.size(); ++i) {
        for (int j = i + 1; j < Songs.size(); ++j) {
            if (Songs[j] < Songs[i]) {
                swap(Songs[j], Songs[i]);
            }
        }
    }

    for (auto &song: Songs) {
        if (song == "Untitled")
            li.push_front(song);
        else
            li.push_back(song);
    }

    Songs.clear();

    for (auto &song: li)
        Songs.push_back(song);
}

int main() {
    vector<string> songList;
    string songName;
    cout << "If you want to stop enter ( -1 )\n"
            "Enter Name of Songs:\n";

    while (cin >> songName) {
        if (songName == "-1")
            break;
        songList.push_back(songName);
    }

    BiasedSort(songList);

    for (int i = 0; i < songList.size(); ++i) {
        cout << songList[i] << endl;
    }
    return 0;
}