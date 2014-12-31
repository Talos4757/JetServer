/*
 * JetServer.h
 *
 *  Created on: Dec 26, 2014
 *      Author: Matan Rosenberg
 */

#ifndef JETSERVER_H_
#define JETSERVER_H_

#define TCP_SOCKET 0
#define JPORT 4242

#include "vxWorks.h"
#include "sockLib.h"
#include "inetLib.h"

#include <iostream>
#include <stdio.h>
#include <vector>

#include "Utility.h"

using namespace std;

class JetServer
{
public:
	static vector<Target*> QueryJetson();
	static bool Init();
	static volatile bool Initing;
	static volatile bool IsStarted;
private:
	static int JetsonSocket;
	static int acp_socket;

	static Target* Deserialize(char encoded[]);
};


#endif /* JETSERVER_H_ */
