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

int add_album(vector <album> &add)
{
    album temp;
    int genre_id;
    cout << "Enter Name" <<endl;   
    cin >> temp.album_name;
    cout << "Enter Genre 0-2" << endl;
    cin >> genre_id;
    temp.kind = static_cast<genre>(genre_id);
    cout << temp.kind;
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
    for(int i = 0; i < add.size(); i ++){
        cout << add[i].album_name << "\n";
        cout <<  add[i].kind << "\n";
        cout << add[i].track_number << "\n";
        for (int i = 0; i < add[i].track_number; i++) {
        cout << add[i].tracks[i];
        }
        cout << add[i].tracklocation;
    }
}

int main()
{
    vector <album> albums; 
    add_album(albums);
    print_all_album(albums);
}
