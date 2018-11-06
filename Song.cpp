#include "Song.h"
#include <string>
using namespace std;

Song::Song(){
    artist = "";
    title = "";
    size = 0;
}

Song::Song(string myTitle, string myArtist, int mySize){
    artist = myArtist;
    title = myTitle;
    size = mySize;
}

string Song::getArtist() const{
    return artist;
}

void Song::setArtist(string myArtist){
    artist = myArtist;
}

string Song::getTitle() const{
    return title;
}

void Song::setTitle(string myTitle){
    title = myTitle;
}

int Song::getSize() const{
    return size;
}

void Song::setSize(int mySize){
    size = mySize;
}

bool Song::operator == (Song const &rhs){
    return(artist == rhs.artist && title == rhs.title && size == rhs.size);
}

bool Song::operator > (Song const &rhs){
    if(artist != rhs.artist){
        return(artist > rhs.artist);
    }else if(title != rhs.title){
        return(title > rhs.title);
    }else if(size != rhs.size){
        return(size > rhs.size);
    }
    return false;
}

bool Song::operator < (Song const &rhs){
    if(artist != rhs.artist){
        return(artist < rhs.artist);
    }else if(title != rhs.title){
        return(title < rhs.title);
    }else if(size != rhs.size){
        return(size < rhs.size);
    }
    return false;
}
