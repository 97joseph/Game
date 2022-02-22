#include <string>

#include "Student.h"
#ifndef _CELL_H
#define _CELL_H
#pragma once

class Cell
{
private:
	Cell(Student *pStudent): mStudent(pStudent), mNext(nullptr) {}
	~Cell() {}

	friend class CList;
	Student *mStudent;
	Cell *mNext;
};

#endif // !_CELL_H

