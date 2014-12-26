/*
 * RioServer.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: Matan Rosenberg
 */

#include "RioServer.h"

const int MAX_TARGETS = 3;

vector<Target>* RioServer::GetTargets()
{
	vector<Target> *found;

	for(int i = 0; i < MAX_TARGETS; i++)
	{
		found->push_back(Deseriallize(QueryJetson()));
	}

	return found;
}

bool RioServer::Init()
{
	return AttemptConnect();
}

bool RioServer::AttemptConnect()
{
	//bind()
	return true;
}

char RioServer::QueryJetson() //Move to another thread?
{
	//Recv() goes here
	return 'c';
}

Target RioServer::Deseriallize(char encoded)
{
	return *(new Target);
}
