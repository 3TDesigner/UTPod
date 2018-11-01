#include "Song.h"
#include "UtPod.h"
#include <string>
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
    tail = NULL;

    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}

UtPod::UtPod(int mySize){
    if(mySize > MAX_MEMORY || mySize <= 0){
        memSize = MAX_MEMORY;
    }else{
        memSize = mySize;
    }

    songs = NULL;
    tail = NULL;

    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}

int UtPod::getRemainingMemory(){
    int count = 0;
    SongNode *ptr = songs;

    while(ptr != NULL){
        count += ptr->s.getSize();
        ptr = ptr->next;
    }

    return memSize - count;
}

int UtPod::addSong(Song const &s){
    SongNode* temp = new SongNode();
    temp->next = NULL;
    temp->s = s;
    int memoryLeft = getRemainingMemory() - s.getSize();

    if(memoryLeft > 0) {
        if (songs == NULL) {
            songs = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        return SUCCESS;
    }else{
        return NO_MEMORY;
    }
}

int UtPod::removeSong(Song const &s){
    SongNode *ptr = songs;
    SongNode *trail = songs;

    if(getRemainingMemory() != memSize) {
        while (ptr != NULL){
            if(ptr->s == s){
                if (ptr == songs){
                    songs = ptr->next;
                }else{
                    trail->next = ptr->next;
                }
                delete(ptr);
                return SUCCESS;
            }else{
                trail = ptr;
                ptr = ptr->next;
            }
        }
    }

    return NOT_FOUND;
}

void UtPod::shuffle(){
    int countSongs = 0;
    SongNode *ptr = songs;
    Song temp("","",0);
    SongNode *p1;
    SongNode *p2;

    while(ptr != NULL){
        countSongs++;
        ptr = ptr->next;
    }

    if(countSongs > 2) {
        for (int i = 0; i < countSongs; i++) {
            int song1 = rand() % countSongs;
            int song2 = rand() % countSongs;

            ptr = songs;
            for (int j = 0; j < song1; j++) {
                ptr = ptr->next;
            }
            p1 = ptr;

            ptr = songs;
            for (int k = 0; k < song2; k++) {
                ptr = ptr->next;
            }
            p2 = ptr;

            temp = p1->s;
            p1->s = p2->s;
            p2->s = temp;
        }
    }
}

void UtPod::showSongList(){
    SongNode *ptr = songs;

    while(ptr != NULL){
        cout << ptr->s.getTitle() << ", " << ptr->s.getArtist() << ", " << ptr->s.getSize() << " MB" << endl;
        ptr = ptr->next;
    }
}

void UtPod::sortSongList(){
    int countSongs = 0;
    SongNode *ptr = songs;
    SongNode *p1;
    SongNode *p2;
    Song temp("","",0);
    int minIdx;

    //Counts the number of songs
    while(ptr != NULL){
        countSongs++;
        ptr = ptr->next;
    }

    for(int i = 0; i < countSongs - 1; i++){
        minIdx = i;
        for(int j = i+1; j < countSongs; j++){
            //Find data at j
            ptr = songs;
            for (int k = 0; k < j; k++) {
                ptr = ptr->next;
            }
            p1 = ptr;

            //Find data at minimum index
            ptr = songs;
            for (int l = 0; l < minIdx; l++) {
                ptr = ptr->next;
            }
            p2 = ptr;

            if(p1->s < p2->s){
                minIdx = j;
            }
        }
        //Find data at j
        ptr = songs;
        for (int k = 0; k < i; k++) {
            ptr = ptr->next;
        }
        p1 = ptr;

        //Find data at minimum index
        ptr = songs;
        for (int l = 0; l < minIdx; l++) {
            ptr = ptr->next;
        }
        p2 = ptr;

        //Swap
        temp = p1->s;
        p1->s = p2->s;
        p2->s = temp;
    }
}

void UtPod::clearMemory(){
    SongNode *ptr = songs;
    if(getRemainingMemory() != memSize) {
        while(songs != NULL){
            songs = songs->next;
            delete(ptr);
            ptr = songs;
        }
    }
}

int UtPod::getTotalMemory() {
    return memSize;
}

UtPod::~UtPod(){
    clearMemory();
}
