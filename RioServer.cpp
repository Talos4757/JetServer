/*
 * RioServer.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: Matan Rosenberg
 */

#include "RioServer.h"

const int MAX_TARGETS = 3;

static Target* RioServer::GetTargets()
{
	Target found[MAX_TARGETS];

	for(int i = 0; i < MAX_TARGETS; i++)
	{
		found[i] = Deseriallize(QueryJetson());
	}

	return &found;
}

static bool RioServer::Init()
{
	return this->AttemptConnect();
}

static bool RioServer::AttemptConnect()
{
	//bind()
	return true;
}

static char RioServer::QueryJetson() //Move to another thread?
{
	//Recv() goes here
	return new char;
}

static Target RioServer::Deseriallize(char encoded)
{
	return new Target;
}


