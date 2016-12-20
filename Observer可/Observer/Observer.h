#pragma once
#include "Subject.h"

using namespace std;


class Observer{                    //观察者抽象类
public:
	virtual void registerSubject(Subject *base) = 0;
	virtual void update(Subject *base) = 0;
protected:
	Subject * _subject;
};
