#pragma once
#include "Subject.h"

using namespace std;


class Observer{                    //�۲��߳�����
public:
	virtual void registerSubject(Subject *base) = 0;
	virtual void update(Subject *base) = 0;
protected:
	Subject * _subject;
};
