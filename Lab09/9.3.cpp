#include <iostream>
#include <vector>

using namespace std;

enum genre{ pop, Jazz, Classic}; // Enumeration

//struct
typedef struct  // typdef so dont have to use struct everytime
{
    string album_name;
    genre kind;
    int track_number;
    string tracks[5];
    string tracklocation;
}album;

//Function prototypes
int add_album(vector <album> &add);
void print_all_album(vector <album> add, int size);
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
    print_all_album(add,2);
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

int add_album(vector <album> &add)
{
    album temp;
    int genre_id;
    cout << "Enter Name" <<endl;   
    cin >> temp.album_name;
    cout << "Enter Genre 0-2" << endl;
    cin >> genre_id;
    temp.kind = static_cast<genre>(genre_id);
    add.push_back(temp);
}

void print_all_album(vector <album> add, int size)
{
    //int size = 2;
    for(int i = 0; i < size; i ++){
        cout << add[i].album_name << "\n";
        cout << add.at(i).album_name << "\n";
        cout <<  add[i].kind << "\n";
    }
}


// void select_track_to_play()
// {

    
// }