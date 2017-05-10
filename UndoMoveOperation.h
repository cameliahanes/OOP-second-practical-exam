#pragma once
#include "UndoOperation.h"
#include "Repository.h"
class UndoMoveOperation : public UndoOperation {
private:
	Repository &repo, &storage;

public:
	UndoMoveOperation(Painting* p, Repository& r, Repository& st) : UndoOperation{ p }, repo{ r }, storage{st}{}

	void UndoMoveOperation::execute_undo() {
		/// having that it wa moved to the special storage now delete it from the storage and move it to the repository back

		this->repo.add_painting(painting);
		this->storage.remove_painting(painting);

	}


};
