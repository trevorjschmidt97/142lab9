#include "Playlist.h"

Playlist::Playlist(string nameOfPlaylist) {
}

Playlist::~Playlist() {
}

void Playlist::SetNamePlaylist(string playlistName) {
	nameOfPlaylist = playlistName;
}

string Playlist::GetNamePlaylist() {
	return nameOfPlaylist;
}

void Playlist::AddSong(Song* songPointer) {
	playlistSongs.push_back(songPointer);
}

void Playlist::PlaySongsInPlaylist() {
	for (int i = 0; i < (int)playlistSongs.size(); ++i) {
		cout << playlistSongs.at(i)->GetFirstLine() << endl;
		playlistSongs.at(i)->IterateTimesPlayed();
	}
}

void Playlist::DeleteSong(int index) {
	playlistSongs.erase(playlistSongs.begin() + index);
}

void Playlist::DeleteSong(Song *songPtr) {
	int nSongs = (int)(playlistSongs.size());	
	for (int i = 0; i < nSongs; ++i) {
		if (playlistSongs.at(i) == songPtr) {
			playlistSongs.erase(playlistSongs.begin() + i);
			return;
		}
	}
}