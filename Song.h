#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H
#include <string>
using namespace std;

class Song{
private:
    string title;
    string artist;
    int size;

public:
    //Default constructor
    Song();

    //Constructor with artist, title, and size parameter
    //The user of the class will pass in a artist, title, and size (in MB) for a song
    //Sets the songs artist, title, and size to those passed in
    Song(string myTitle, string myArtist, int mySize);

    /* FUNCTION - string getArtist
    * gives the artist to the user

      input parms - void

      output parms - string
   */
    string getArtist() const;
    /* FUNCTION - string setArtist
    * sets the artist for the user

      input parms - string

      output parms - void
   */
    void setArtist(string myArtist);



    /* FUNCTION - string getTitle
   * gives the title to the user

     input parms - void

     output parms - string
  */
    string getTitle() const;
    /* FUNCTION - string setTitle
    * sets the title for the user

      input parms - string

      output parms - void
   */
    void setTitle(string myTitle);



    /* FUNCTION - string getSize
   * gives the size to the user

     input parms - void

     output parms - integer
  */
    int getSize() const;
    /* FUNCTION - string setSize
    * sets the size for the user

      input parms - integer

      output parms - void
   */
    void setSize(int mySize);

    //These functions override the operators for ==, <, and >
    bool operator == (Song const &rhs);
    bool operator < (Song const &rhs);
    bool operator > (Song const &rhs);
};

#endif //UTPOD_SONG_H
