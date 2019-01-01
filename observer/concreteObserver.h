#ifndef CONCRETEOBSERVER_H
#define CONCRETEOBSERVER_H

#include "subjectIf.h"
#include <iostream>
#include <string>

using namespace std;

class ConcreteObserver : public ObserverIf
{
public:
	ConcreteObserver(string observerName)
	{
		m_observerName = observerName;
	};

	void update(int attribute)
	{
		cout<<"observer : "<<m_observerName<<" attribute "<<attribute<<endl;
	}

private:
	string m_observerName;
};

#endif// CONCRETEOBSERVER_H
