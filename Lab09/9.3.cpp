#include <iostream>

using namespace std;

enum genre{pop, Jazz, Classic};

typedef struct album
{
    string album_name;
    genre kind;
    int track_number;
    string tracks[5];
    string tracklocation;
};

void add_album();
void print_all_album();
void select_track_to_play();

int main()
{
    int menu =0;

    do {
        cout << "\n(1)Enter 1 to add an album\n" <<
        "(2)Enter 2 to print the album details.\n" <<
        "(3)Enter 3 to play a track from an album.\n" <<
        "(4)Enter 4 to Exit.\n";
    cin >> menu;

    switch (menu)
    {
        
    case 1:

        break;

    case 2:

        break;

    case 3:

        break; 

    case 4:
        return 0;
        break;

    default:
        cout << "Error! Invalid Selection";
        break;
    }}while(menu != 4);


}