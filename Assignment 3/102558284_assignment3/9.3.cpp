#include <iostream>
#include <vector>

using namespace std;

enum genre{ Rock, Pop, Country}; // Enumeration

//struct
typedef struct  
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
    add_album(albums); // add albums
        break;
    case '2':
    print_all_album(albums); // prints albums
        break;
    case '3':
    cout << "Select an album to play\n";
    cin >> album_name;
    select_track_to_play(albums,album_name); // play album
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
    // storting album data
    album temp;
    int genre_id;
    cout << "Enter album name" <<endl;   
    cin >> temp.album_name;
    cout << "Enter genre 0 -> Rock, 1 -> Pop, 2 ->Country" << endl;
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
    add.push_back(temp); // pushing data to vector
}

void print_all_album(vector <album> add)
{
    //displaying album data
    int count;
    for(int i = 0; i < add.size(); i ++){
        cout << "\nName of the album : " << add[i].album_name << "\n";
        cout << "Genre of the album :  " ;
        if(add[i].kind == 0){ // for enum 
            cout << "Rock\n";
        }else if(add[i].kind == 1){
            cout << "Pop\n";
        }else if(add[i].kind == 2) {
            cout << "Country\n";
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
        if(add.empty()){ // if no albums in vector
        cout << "You have no albums saved currently.\n";
        }
    for (int i = 0; i < add.size(); i++){
        if (add[i].album_name == album_name)
        {
            cout << "This album contains " << add[i].track_number << " tracks and those tracks are \n";
            for (int j = 0; j < add[i].track_number; j++) {
            cout << number << ". "<< add[i].tracks[j] << "\n";
            number++;
            }
            cout << "Please select a track to play from the above list\n"; 
            cin >> track_name;
            cout << "The track you selected " << track_name << " from the Album: " << album_name 
            << " is now playing from the location " << add[i].tracklocation << "\n";
            system(("cd "+add[i].tracklocation+" && start "+track_name+".mp3").c_str());
        }else{
            cout << "Album not found\n";
        }
    }

}