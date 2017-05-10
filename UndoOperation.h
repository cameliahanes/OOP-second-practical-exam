#pragma once
#include "Painting.h"
class UndoOperation {

protected:
	Painting* painting;

public:
	UndoOperation(Painting* p) : painting{p} {}
	virtual void execute_undo() = 0;

};

