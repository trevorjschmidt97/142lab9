#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Song
{
public:
	Song(string songName = "none", string firstLine = "none");
	~Song();
	void SetName(string songName);
	string GetName();
	void SetFirstLine(string firstLine);
	string GetFirstLine();
	void SetTimesPlayed();
	int GetTimesPlayed();
	void IterateTimesPlayed();
private:
	string nameOfSong;
	string firstLineOfSong;
	int timesPlayed;
};

