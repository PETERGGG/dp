// Composite.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>  
#include <string>  
#include <list>  
using namespace std;

class Component
{
protected:
	string name;
public:
	Component(string name)
		:name(name)
	{   }
	virtual void AddComponent(Component *component) {   }
	virtual void RemoveComponent(Component *component)  {   }
	virtual void GetChild(int depth)    { }
};


class Composite :public Component
{
private:
	list<Component*> _componets;

public:
	Composite(string name)
		:Component(name)
	{ }
	void AddComponent(Component *component)
	{
		_componets.push_back(component);
	}
	void RemoveComponent(Component *component)
	{
		_componets.remove(component);
	}
	void GetChild(int depth)
	{
		string tmpstring(depth, '-');
		cout << tmpstring << name << endl;
		list<Component*>::iterator iter = _componets.begin();
		for (; iter != _componets.end(); iter++)
		{
			(*iter)->GetChild(depth + 2);
		}
	}
};

int main()
{
	Composite *root = new Composite("root");


	Composite *lay1 = new Composite("layer1");
	Composite *lay2 = new Composite("layer2_1");
	Composite *lay3 = new Composite("layer2_2");


	lay1->AddComponent(lay2);
	lay1->AddComponent(lay3);


	Composite *lay4 = new Composite("layer4");
	Composite *lay5 = new Composite("layer5");
	


	lay4->AddComponent(lay5);
	




	root->AddComponent(lay1);
	root->AddComponent(lay4);

	root->GetChild(1);
	cout << endl;
	lay1->GetChild(1);
	cout << endl;
	lay2->GetChild(1);

	
	system("pause");
	return 0;
}