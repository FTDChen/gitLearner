# ifndef CONCRETESUBJECT_H
# define CONCRETESUBJECT_H

#include <iostream>
#include <list>
#include "subjectIf.h"
#include "observerIf.h"

using namespace std;

class ConcreteSubject : public SubjectIf
{
public:
	ConcreteSubject() {m_attribute = 20;}
	
	void setAttr(int attribute)
	{
		m_attribute = attribute;
	}
	void registerObserver(ObserverIf *observer)
	{
		m_observers.push_back(observer);
	}
	void removeObserver(ObserverIf *observer)
	{
		m_observers.remove(observer);
	}
	void notifyObserver()
	{
		list<ObserverIf *>::iterator it = m_observers.begin();
		while(it != m_observers.end())
		{
			(*it)->update(m_attribute);
			++it;
		}
	}
private:
	list<ObserverIf *> m_observers;//list of observers
	int m_attribute;
};

# endif // CONCRETESUBJECT_H
