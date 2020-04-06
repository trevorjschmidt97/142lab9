/*
TREVOR SCHMIDT 
trevorjschmidt97@gmail.com
CS 142 - Section 22
MAIN LAB 9 - PLAYLISTS 

new used in main.cpp line 44
*/

#include <string>
#include "Song.h"
#include "Playlist.h"

int main() {
	int userPlaylistOption;
	int userSongOption;
	string userOption;
	string songName;
	string firstLine;
	string playlistName;
	Song *newSong;
	vector <Song*> songsVector;
	vector <Playlist> playlistVector;


	cout << "Welcome to the Firstline Player! Enter options to see menu options." << endl << endl;
	cout << "Enter your selection now: ";
	cin >> userOption;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << endl;


	while (userOption != "quit") {
		if (userOption == "add") {
			cout << "Read in Song names and first lines (type\"STOP\" when done) :" << endl;
			cout << "Song Name: ";
			getline(cin, songName);
			while (songName != "STOP") {
				cout << endl;
				cout << "Song's first line: ";
				getline(cin, firstLine);
				cout << endl;
				newSong = new(Song); // NEW HERE
				newSong->SetName(songName);
				newSong->SetFirstLine(firstLine);
				songsVector.push_back(newSong);
				cout << "Song name: ";
				getline(cin, songName);
			}
			cout << endl << endl;
		}
		else if (userOption == "list") {
			for (unsigned int i = 0; i < songsVector.size(); ++i) {
				cout << songsVector.at(i)->GetName() << ": \"" << songsVector.at(i)->GetFirstLine() << "\", "
					<< songsVector.at(i)->GetTimesPlayed() << " play(s)." << endl;
			}
		}
		else if (userOption == "addp") {
			Playlist newPlaylist;
			cout << "Playlist name: ";
			getline(cin, playlistName);
			newPlaylist.SetNamePlaylist(playlistName);
			playlistVector.push_back(newPlaylist);
			cout << endl << endl;
		}
		else if (userOption == "addsp") {
			for (unsigned int i = 0; i < playlistVector.size(); ++i) {
				cout << i << ": " << playlistVector.at(i).GetNamePlaylist() << endl;
			}
			cout << "Pick a playlist index number: ";
			cin >> userPlaylistOption;
			cin.clear();
			cin.ignore(10000, '\n');
			for (unsigned int i = 0; i < songsVector.size(); ++i) {
				cout << i << ": " << songsVector.at(i)->GetName() << endl;
			}
			cout << "Pick a song index number: ";
			cin >> userSongOption;
			cin.clear();
			cin.ignore(10000, '\n');

			Song* songPointer = songsVector.at(userSongOption);

			(playlistVector.at(userPlaylistOption)).AddSong(songPointer);
			cout << endl << endl;
		}
		else if (userOption == "listp") {
			for (unsigned int i = 0; i < playlistVector.size(); ++i) {
				cout << i << ": " << playlistVector.at(i).GetNamePlaylist() << endl;
			}
			cout << endl;
		}
		else if (userOption == "play") {
			for (unsigned int i = 0; i < playlistVector.size(); ++i) {
				cout << i << ": " << playlistVector.at(i).GetNamePlaylist() << endl;
			}
			cout << "Pick a playlist index number: ";
			cin >> userPlaylistOption;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl << endl;
			cout << "Playing first lines of playlist: " << playlistVector.at(userPlaylistOption).GetNamePlaylist() << endl;

			playlistVector.at(userPlaylistOption).PlaySongsInPlaylist();
		}
		else if (userOption == "delp") {
			for (unsigned int i = 0; i < playlistVector.size(); ++i) {
				cout << i << ": " << playlistVector.at(i).GetNamePlaylist() << endl;
			}
			cout << "Pick a playlist index number to delete: ";
			cin >> userPlaylistOption;
			cin.clear();
			cin.ignore(10000, '\n');
			playlistVector.erase(playlistVector.begin() + userPlaylistOption);
			cout << endl << endl;
		}
		else if (userOption == "delsp") {
			for (unsigned int i = 0; i < playlistVector.size(); ++i) {
				cout << i << ": " << playlistVector.at(i).GetNamePlaylist() << endl;
			}
			cout << "Pick a playlist index number: ";
			cin >> userPlaylistOption;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl;
			for (unsigned int i = 0; i < playlistVector.at(userPlaylistOption).playlistSongs.size(); ++i) {
				cout << i << ": " << playlistVector.at(userPlaylistOption).playlistSongs.at(i)->GetName() << endl;
			}
			cout << "Pick a song index number to delete: ";
			cin >> userSongOption;
			cin.clear();
			cin.ignore(10000, '\n');
			playlistVector.at(userPlaylistOption).DeleteSong(userSongOption);
			cout << endl << endl;
		}
		else if (userOption == "delsl") {
			for (unsigned int i = 0; i < songsVector.size(); ++i) {
				cout << i << ": " << songsVector.at(i)->GetName() << endl;
			}
			cout << "Pick a song index number: ";
			cin >> userSongOption;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl;
			Song *songToDel = songsVector.at(userSongOption);
			for (int i = 0; i < (int)playlistVector.size(); ++i) {
				playlistVector.at(i).DeleteSong(songToDel);
			}
			songsVector.erase(songsVector.begin() + userSongOption);
			delete(songToDel); // DELETE HERE
			cout << endl << endl;
		}
		else {
			cout << "add"     << "\t" << "Adds a list of songs to the library"                 << endl;
			cout << "list"    << "\t" << "Lists all the songs in the library"                  << endl;
			cout << "addp"    << "\t" << "Adds a new playlist"                                 << endl;
			cout << "addsp"   << "\t" << "Adds a song to a playlist"                           << endl;
			cout << "listp"   << "\t" << "Lists all the playlists"                             << endl;
			cout << "play"    << "\t" << "Plays a playlist"                                    << endl;
			cout << "delp"    << "\t" << "Deletes a playlist"                                  << endl;
			cout << "delsp"   << "\t" << "Deletes a song from a playlist"                      << endl;
			cout << "delsl"   << "\t" << "Deletes a song from the library (and all playlists)" << endl;
			cout << "options" << "\t" << "Prints this options menu"                            << endl;
			cout << "quit"    << "\t" << "Quits the program"                                   << endl;
			cout << endl;
		}
		cout << "Enter your selection now: ";
		cin >> userOption;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Goodbye!" << endl;

	for (unsigned int i = 0; i < songsVector.size(); ++i) {
		delete songsVector.at(i); // DELETE HERE
	}


	//system("pause");
	return 0;
}