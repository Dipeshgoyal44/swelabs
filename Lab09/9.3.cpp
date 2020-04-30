#include <iostream>
#include <vector>

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

int add_album(vector <album> add);
void print_all_album();
void select_track_to_play();

int main()
{
    vector <album> add;
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
    cout << "Case 1\n";
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
    int newalbum = 0;
    string temp;
    
    cout << "Enter album name \n";
    cin >> temp;

    for (int i = 1 ; i <= 1 + newalbum; i++){ 
        add.album_name.insert(i,temp);
    }
    cout << add[1].album_name << endl;
    newalbum++;

}

void print_all_album()
{


}

void select_track_to_play()
{

    
}