#include <iostream>
#include <vector>

using namespace std;

enum genre{ pop, Jazz, Classic}; // Enumeration

//struct
struct album // typdef so dont have to use struct everytime
{
    string album_name;
    genre kind;
    int track_number;
    string tracks[5];
    string tracklocation;
};

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
        cout << "Name of the album : " << add[i].album_name << "\n";
        cout << "Genre of the album : " << add[i].kind << "\n";
        cout << "No. of tracks : " << add[i].track_number << "\n";
        count = add[i].track_number;
        cout << "Tracks  are : " << endl; 
        cout << add.size();
        // for (int j = 0; i < count; j++) {                         // MESSING UP HERE
        // cout << "i is :" << i << "j is " << j << "\n";           // MESSING UP HERE
        // cout <<  add[i].tracks[j] << endl;                       // MESSING UP HERE
        // }
        cout << "Tracks are located at " <<  add[i].tracklocation << "\n";
    }
}

void select_track_to_play(vector <album>add, string album_name)
{
    string track_name;
    for (int i = 0; i < add.size(); i++){
        if (add[i].album_name == album_name)
        {
            cout << "This album contains " << add[i].track_number << " and those tracks are \n";
            for (int j = 1; i <= add[i].track_number; j++) {
            cout << i << ". "<< add[i].tracks[j] << "\n";
            }
            cout << "Please select a track to play from the above list\n";
            cin >> track_name;
            cout << "The track you selected " << track_name << " from the Album: " << album_name 
            << " is now playing from the location " << add[i].tracklocation << "\n";
        }
    }
    cout << "Album not found\n";
}
    

int main()
{
    string album_name;
    vector <album> albums; 
    add_album(albums);
    print_all_album(albums);
   // cout << "Select an album to play\n";
    //cin >> album_name;
   // select_track_to_play(albums,album_name);

}