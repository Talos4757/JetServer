/*
 * JetServer.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: Matan Rosenberg
 */

#include "JetServer.h"

vector<Target>* JetServer::GetTargets()
{
	vector<Target> *found = new vector<Target>(MAX_TARGETS);

	for(int i = 0; i < MAX_TARGETS; i++)
	{
		found->push_back(Deseriallize(QueryJetson()));
	}

	return found;
}

bool JetServer::Init()
{
	JetsonSocket = socket(AF_INET,SOCK_STREAM,TCP_SOCKET);
	if(JetsonSocket < 0)
	{
		return false;
	}

	struct sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_port = htons(7887);

	if(bind(JetsonSocket,(struct sockaddr *)&sa, sizeof sa) != 0)
	{
		//failure if not 0
		return false;
	}

	if(listen(JetsonSocket,6) < 0)
	{
			return false;
	}

	struct sockaddr sar;
	socklen_t st;

	acp_socket = accept(js,&sar,&st);

	return true;
}


char JetServer::QueryJetson() //Move to another thread?
{
	//Recv() goes here
	return 'c';
}

Target JetServer::Deseriallize(char encoded)
{
	return *(new Target);
}
