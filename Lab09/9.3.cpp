#include <iostream>
#include <vector>

using namespace std;

enum genre{pop, Jazz, Classic}; // Enumeration

//struct
typedef struct album // typdef so dont have to use struct everytime
{
    string album_name;
    genre kind;
    int track_number;
    string tracks[5];
    string tracklocation;
}album;

//Function prototypes
int add_album(vector <album> add);
void print_all_album();
void select_track_to_play();

int main()
{
    vector <album> add; 
    int menu =0;
    
    do { //switch menu 
        cout << "\n(1)Enter 1 to add an album\n" <<
        "(2)Enter 2 to print the album details.\n" <<
        "(3)Enter 3 to play a track from an album.\n" <<
        "(4)Enter 4 to Exit.\n";
    cin >> menu;

    switch (menu)
    {
    case 1:
    add_album(add);

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

int add_album(vector <album> add)
{
    album store;
    cout << "Enter album name \n";
    cin >> store.album_name;
    cout << "Enter genre 0 ->  pop, 1 -> Jazz, 2 -> Classic \n";
    //cin >> store.kind; enum
    cout << "Enter number of tracks in the album \n";
    cin >> store.track_number;
    cout << "Enter the names for these " << store.track_number << " tracks\n";
    for (int i = 0; i < store.track_number; i++) {
        cin >> store.tracks[i];
    }
    cout << "Enter the file location of these tracks\n";
    cin >> store.tracklocation;
    add.push_back({store.album_name, store.kind, store.track_number,store.tracklocation}); 
}

// void print_all_album(vector <album> add)
// {
    
// }


// void select_track_to_play()
// {

    
// }