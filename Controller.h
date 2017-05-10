#pragma once

#include "Repository.h"

class Controller {

private:
	
public:
	Repository repo_all;
	Repository repo_special_storage;

	Controller(Repository& repo, Repository& storage) : repo_all{ repo }, repo_special_storage{ storage } {}

	bool add_painting(Painting *pp) {
		return this->repo_all.add_painting(pp);
	}

	void remove_painting(Painting* pp) {
		if (this->repo_all.painting_found(pp->get_artist(), pp->get_title(), pp->get_year()) == -1)
			throw std::exception("Can not remove, painting not in the gallery! \n");
		else {
			bool res = this->repo_all.remove_painting(pp);
			if (res == true)
				throw std::exception("Painting was successfully removed!\n");
			else
				throw std::exception("Could not remove painting!\n");
		}
	}

	void move_to_special_storage(Painting* p) {
		if (this->repo_all.painting_found(p->get_artist(), p->get_title(), p->get_year()) == -1)
			throw std::exception("Can not move to special storage, painting not in the gallery! \n");
			this->repo_special_storage.add_painting(p);
			this->repo_all.remove_painting(p);
	}

	vector<Painting*> get_all_controller() {
		return this->repo_all.get_all();
	}

	vector<Painting*> get_all_special_storage() {
		return this->repo_special_storage.get_all();
	}

};


