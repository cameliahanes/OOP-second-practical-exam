#include "UI.h"

int main() {
	vector<Painting*> paintings, storage_paintings;
	Repository r(paintings);
	Repository storage(storage_paintings);
	Controller c(r, storage);
	UI ui(c);
	ui.run();
}