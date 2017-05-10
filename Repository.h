#pragma once
#include <vector>
#include "Painting.h"
#include <fstream>
class Repository {
private:
	std::vector<Painting*> paintings;

public:
	Repository(const std::vector<Painting*> p) : paintings(p) {}
	
	std::vector<Painting*> get_all() {
		return this->paintings;
	}

	bool add_painting(Painting* p) {
		this->paintings.push_back(p);
		return true;
	}

	int painting_found(std::string artist, std::string title, int y) {
		for (int i = 0; i < this->paintings.size(); ++i) {
			Painting* ppp = this->paintings[i];
			if (ppp->get_artist() == artist && ppp->get_title() == title && ppp->get_year() == y)
				return i;
		}
		return -1;
	}

	bool remove_painting(Painting* p) {
		int r = painting_found(p->get_artist(), p->get_title(), p->get_year());
		if (r == -1)
			return false;
		this->paintings.erase(this->paintings.begin() + r, this->paintings.begin() + r + 1);
		return true;
	}


};


