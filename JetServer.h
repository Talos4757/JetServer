/*
 * JetServer.h
 *
 *  Created on: Dec 26, 2014
 *      Author: Matan Rosenberg
 */

#ifndef JETSERVER_H_
#define JETSERVER_H_

#define TCP_SOCKET 0

const int MAX_TARGETS = 3;

#include <iostream>
#include <stdio.h>
#include <vector>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#include "Utility.h"

using namespace std;

class JetServer
{
public:
	static vector<Target*> QueryJetson();
	
private:
	static int JetsonSocket;
	static int acp_socket;

	static bool Init();

	static Target* Deseriallize(char[] encoded);
};


#endif /* JETSERVER_H_ */
