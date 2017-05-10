#pragma once
#include "UndoOperation.h"
#include "Repository.h"

class UndoAddOperation : public UndoOperation {
private:
	Repository &paintings_repo;
	
	
public:
	UndoAddOperation(Painting* p, Repository& r) : UndoOperation{ p }, paintings_repo{r} {	}

	void UndoAddOperation::execute_undo() {
		this->paintings_repo.remove_painting(this->painting);
	}
};



