/*
 * RioServer.h
 *
 *  Created on: Dec 26, 2014
 *      Author: Matan Rosenberg
 */

#ifndef RIOSERVER_H_
#define RIOSERVER_H_

#include <iostream>
#include <stdio.h>
#include <vector>

#include <sys/socket.h>
#include <sys/types.h>

#include "Utility.h"

using namespace std;

static class RioServer
{
public:
	static Target* GetTargets();

private:
	static int JetSocket;
	//other sockets (for potentially other devices) will go here

	static bool Init();
	static bool AttemptConnect();

	static char QueryJetson();
	static Target Deseriallize(char encoded);
};


#endif /* RIOSERVER_H_ */
