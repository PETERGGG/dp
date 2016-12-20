#include "Command.hpp"


int main()
{
	
	Commander *p = new Commander(new InputCommand("[empty]"));

	
	p->ExecuteCommand(new InputCommand("1"));
	
	p->ExecuteCommand(new InputCommand("2"));
	
	p->ExecuteCommand(new InputCommand("3"));

	
	p->Undo();
	
	p->Undo();

	
	p->ExecuteCommand(new InputCommand("K"));

	
	p->Undo();

	
	p->Undo();

	
	p->Undo();

	
	p->Redo();
	
	p->Redo();
	
	p->Redo();

	
	p->ExecuteCommand(new InputCommand("K1"));

	
	p->Undo();

	
	p->Redo();

	
	p->Redo();

	
	p->Redo();
	delete p;
	return 0;
}