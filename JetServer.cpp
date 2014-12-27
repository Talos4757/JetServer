/*
 * JetServer.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: Matan Rosenberg
 */

#include "JetServer.h"

bool JetServer::Init()
{
	JetsonSocket = socket(AF_INET,SOCK_STREAM,TCP_SOCKET);
	if(JetsonSocket < 0)
	{
		return false;
	}

	struct sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_port = htons(JPORT);
	sa.sin_addr.s_addr = INADDR_ANY;

	if(bind(JetsonSocket,(struct sockaddr *)&sa, sizeof(sa)) != 0)
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


vector<Target*> JetServer::QueryJetson()
{
	vector<Target*> targets;

	char buffer[4];
	char targetbuffer[16];

	recv(acp_socket,buffer,4,0);
  int UpcomingTargets = *(int*)buffer;


	for(int i = 0; i < UpcomingTargets; i++)
	{
		recv(acp_socket,targetbuffer,16,0);
		targets.push_back(Deserialize(targetbuffer));
	}

	return targets;
}

Target* JetServer::Deserialize(char encoded[])
{
	Target* target = new Target();

	target->type = *(int*)encoded;
	target->distance = *(double*)(&encoded[4]);
	target->h_angle = *(double*)(&encoded[8]);
	target->v_angle = *(double*)(&encoded[12]);

	return target;
}
