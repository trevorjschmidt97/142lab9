#include "Song.h"

Song::Song(string songName, string firstLine) {
	nameOfSong = songName;
	firstLineOfSong = firstLine;
	timesPlayed = 0;
}

Song::~Song() {
}

void Song::SetName(string songName) {
	nameOfSong = songName;
}

string Song::GetName() {
	return nameOfSong;
}

void Song::SetFirstLine(string firstLine) {
	firstLineOfSong = firstLine;
}

string Song::GetFirstLine() {
	return firstLineOfSong;
}

void Song::SetTimesPlayed() {
	cout << "SetTimesPlayed function doesn't work yet";
}

int Song::GetTimesPlayed() {
	return timesPlayed;
}

void Song::IterateTimesPlayed() {
	timesPlayed = timesPlayed + 1;
}