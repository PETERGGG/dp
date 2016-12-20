
#ifndef _COMMAND_HPP  
#define _COMMAND_HPP  

#include <iostream>  
#include <stack>  
#include <string>  

class Command
{
public:
	Command(){}
	virtual ~Command(){}

	virtual void Execute() = 0;
};


class InputCommand : public Command
{
public:

	InputCommand(const std::string &input)
	{
		mInput = input;
	}
	~InputCommand()
	{}

	void Execute()
	{
		printf("Êä³ö£º %s\n", mInput.c_str());
	}

private:

	std::string mInput;
};

class Commander
{
public:
	Commander(Command *pCmd)
	{
		
		mUndo.push(pCmd);
	}


	void ExecuteCommand(Command *pCmd)
	{
		pCmd->Execute();
		mUndo.push(pCmd);
	}

	void Undo()
	{
		if (mUndo.size() < 2)
		{
			
			printf("undo failed.\n");
			return;
		}

		printf("undo:\n");

		
		auto pCmd = mUndo.top();

		
		mRedo.push(pCmd);

		
		mUndo.pop();

		
		pCmd = mUndo.top();

		pCmd->Execute();

	}

	void Redo()
	{
		if (mRedo.empty())
		{
			
			printf("redo failed.\n");
			return;
		}

		printf("redo:\n");

		auto pCmd = mRedo.top();

		pCmd->Execute();

		mRedo.pop();

		mUndo.push(pCmd);
	}

private:
	std::stack< Command* > mUndo;
	std::stack< Command* > mRedo;
};

#endif  
