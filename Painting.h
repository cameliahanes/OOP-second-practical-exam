#pragma once
#include <string>
using namespace std;
class Painting {

public:
	Painting(std::string& artis, std::string& titl, int yea) : artist(artis),  title(titl),  year(yea) {}

	int get_year() {
		return year;
	}

	string get_title() {
		return title;
	}

	string get_artist() {
		return artist;
	}

	virtual std::string toString() const {
		string buffer = " ARTIST: " + this->artist + " TITLE: " + this->title + + " YEAR: " + to_string(this->year) + " \n";
		return buffer;
	}

protected:
	int year;
	string title;
	string artist;
};
