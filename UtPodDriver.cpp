#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    Song s1("Alpha", "Song 1", 4);
    int result = t.addSong(s1);
    cout << "add result = " << result << endl;

    Song s2("Beta", "Song 2", 5);
    result = t.addSong(s2);
    cout << "add result = " << result << endl;

    Song s3("Beta", "Song 3", 6);
    result = t.addSong(s3);
    cout << "add result = " << result << endl;

    Song s4("Gamma", "Song 4", 7);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;

    Song s5("Omega", "Song 5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    Song s6("Sigma", "Song 6", 350);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    Song s7("Sigma", "Song 7", 55);
    result = t.addSong(s7);
    cout << "add result = " << result << endl;

    cout << endl << "Add All Songs" << endl;

    t.showSongList();

    t.shuffle();

    cout << endl << "Shuffle" << endl;

    t.showSongList();

    t.sortSongList();

    cout << endl << "Sorted List" << endl;

    t.showSongList();

    t.shuffle();

    cout << endl << "Shuffle Again" << endl;

    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    cout << endl << "Removing Song 2 & 3" << endl;

    t.showSongList();

    cout << endl;

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s7);
    cout << "delete result = " << result << endl;

    cout << endl << "Removing the rest of the songs";

    t.showSongList();

    cout << endl;

    result = t.removeSong(s6);

    cout << endl << "Trying to remove Song 6, but its not present" << endl;
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.addSong(s7);
    cout << "add result = " << result << endl;

    cout << endl << "Add Song 5 again" << endl;

    t.showSongList();

    cout << endl << "memory left = " << t.getRemainingMemory() << endl;
    cout << "total memory = " << t.getTotalMemory() << endl;
}