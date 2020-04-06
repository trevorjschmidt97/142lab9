#pragma once
#include "Song.h"

class Playlist
{
public:
	Playlist(string nameOfPlaylist = "none");
	~Playlist();
	void SetNamePlaylist(string playlistName);
	void AddSong(Song*);
	string GetNamePlaylist();
	void PlaySongsInPlaylist();
	void DeleteSong(int index);
	void DeleteSong(Song *songPtr);
	vector <Song*> playlistSongs;
private:
	string nameOfPlaylist;
};


