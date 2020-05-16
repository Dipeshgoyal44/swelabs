#include <iostream>
#include <vector>
#include <conio.h>

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
void print_all_album(vector <album> add);
void select_track_to_play(vector <album>add, string album_name);

int main()
{
    string album_name;
    vector <album> albums; 
    char menu;
    
    do { //switch menu 
        cout << "\n(1)Enter 1 to add an album\n" <<
        "(2)Enter 2 to print the album details.\n" <<
        "(3)Enter 3 to play a track from an album.\n" <<
        "(4)Enter 4 to Exit.\n";
    cin >> menu;

    switch (menu)
    {
    case '1':
    add_album(albums);
        break;
    case '2':
    print_all_album(albums);
        break;
    case '3':
    cout << "Select an album to play\n";
    cin >> album_name;
    select_track_to_play(albums,album_name);
        break;
    case '4':
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
    cout << "Enter number of tracks in the album \n";
    cin >> temp.track_number;
    cout << "Enter the names for these " << temp.track_number << " tracks\n";
    for (int i = 0; i < temp.track_number; i++) {
        cin >> temp.tracks[i];
    }
    cout << "Enter the file location of these tracks\n";
    cin >> temp.tracklocation;
    add.push_back(temp);
}

void print_all_album(vector <album> add)
{
    int count;
    for(int i = 0; i < add.size(); i ++){
        cout << "\nName of the album : " << add[i].album_name << "\n";
        cout << "Genre of the album : " ;
        if(add[i].kind == 0){
            cout << "pop\n";
        }else if(add[i].kind == 1){
            cout << "Jazz\n";
        }else if(add[i].kind == 2) {
            cout << "Classic\n";
        }
        cout << "No. of tracks : " << add[i].track_number << "\n";
        cout << "Tracks  are : " << endl; 
        for (int j = 0; j < add[i].track_number; j++) {                               
        cout <<  add[i].tracks[j] << endl;                       
        }
        cout << "Tracks are located at " <<  add[i].tracklocation << "\n";
    }
}

void select_track_to_play(vector <album>add, string album_name)
{
    string track_name;
    int number = 1;
        if(add.empty()){
        cout << "Album not found\n";
        }
    for (int i = 0; i < add.size(); i++){
        if (add[i].album_name == album_name)
        {
            cout << "This album contains " << add[i].track_number << " tracks and those tracks are \n";
            for (int j = 0; j < add[i].track_number; j++) {
            cout << number << ". "<< add[i].tracks[j] << "\n";
            number++;
            }
            cout << "Please select a track to play from the above list\n"; // VALIDATION
            cin >> track_name;
            cout << "The track you selected " << track_name << " from the Album: " << album_name 
            << " is now playing from the location " << add[i].tracklocation << "\n";
            system("d:");
            system("cd D:\\BACS Year 1 Semester 1\\Technical Software Development\\Labs\\Lab09\track_folder");
            system("start cross.mp3");
        }else{
            cout << "Album not found\n";
        }
    }

}