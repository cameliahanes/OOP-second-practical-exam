#pragma once
#include <stack>
#include "Controller.h"
#include <iostream>
#include "UndoOperation.h"
#include "UndoAddOperation.h"
#include "UndoMoveOperation.h"
using namespace std;

class UI {

private:
	Controller c;
	stack<UndoOperation*> operations;

public:
	UI(Controller& co) : c{ co } {}

	void print_menu() {
		std::cout << "Options: \n  ";
		std::cout << "1 - print all paintings in the gallery \n  ";
		std::cout << "2 - print all paintings in the special condition storage \n";
		std::cout << "3 - add painting \n";
		std::cout << "4 - move painting to the special storage \n";
		std::cout << "5 - undo last operation done in the database \n";
		std::cout << "0 - exit \n ";
	}

	void print_all_menu() {
		vector<Painting*> paintings = c.get_all_controller();
		for (auto p : paintings) {
			cout << p->toString();
		}
	}

	void print_from_sepcial_storage_menu() {
		vector<Painting*> paintings_special = c.get_all_special_storage();

		for (auto p : paintings_special) {
			cout << p->toString();
		}

	}

	void add_painting_menu() {
		string artist, title;
		int year;
		
		cout << "Enter title: ";
		cin >> title;
		cout << "Enter the name of the artist: ";
		cin >> artist;
		cout << "Give the year: ";
		cin >> year;
		
		if (artist == "" || title == "" || year < 500)
			throw std::exception("The painting can no be added to the gallery. \n");
		Painting* p = new Painting(artist, title, year);
		this->c.add_painting(p);

		UndoOperation *op = new UndoAddOperation(p, this->c.repo_all);
		this->operations.push(op);
	}

	void move_painting_menu() {
		string artist, title;
		int year;
		cout << "Enter title: ";
		cin >> title;
		cout << "Enter the name of the artist: ";
		cin >> artist;
		cout << "Give the year: ";
		cin >> year;
		Painting* p = new Painting(artist, title, year);
		this->c.move_to_special_storage(p);

		UndoOperation* op = new UndoMoveOperation(p, this->c.repo_all, this->c.repo_special_storage);
		this->operations.push(op);
	}

	void run() {
		while (true)
		{
			print_menu();
			int op;
			cin >> op;
			switch (op)
			{
			case 1:
				this->print_all_menu();
				break;
			case 2:
				this->print_from_sepcial_storage_menu();
				break;
			case 3:
				try {
					this->add_painting_menu();
				}
				catch(exception& e){
					cout << e.what();
				}
				break;
			case 4:
				/// move to special stprage
				try {
					this->move_painting_menu();
				}
				catch(exception& e) {
					cout << e.what();
				}
				break;
			case 0:
				exit(0);
			case 5:
			{
				/// undo last operation
				if (this->operations.empty())
					cout << "Already at earliest state.\n";
				else {
					UndoOperation* op = this->operations.top();
					this->operations.pop();
					op->execute_undo();
				}
				break;

			}

			default:
				break;
			}


		}





	}




};



