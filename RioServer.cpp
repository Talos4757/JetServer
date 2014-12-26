/*
 * RioServer.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: matan
 */

#include "RioServer.h"


static vector<Target> RioServer::GetTargets()
{
	return new vector<Target>;
}

static bool RioServer::Init()
{
	return true;
}

static bool RioServer::AttemptConnect()
{
	return true;
}

static vector<char> RioServer::QueryJetson()
{
	return new vector<char>;
}

static Target RioServer::Deseriallize()
{
	return new Target;
}


