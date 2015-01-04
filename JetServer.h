#ifndef JETSERVER_H_
#define JETSERVER_H_

#define TCP_SOCKET 0
#define JPORT 4242

/*
 * cRio socket includes (VxWorks)
#include "vxWorks.h"
#include "sockLib.h"
#include "inetLib.h"
*/


//RoboRio includes (Linux RT)
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#include <iostream>
#include <stdio.h>
#include <vector>
#include <pthread.h>

#include "SmartDashboard/SmartDashboard.h"
#include "WPILib.h"

#include "Utility.h"

using namespace std;

class JetServer
{
public:
	static vector<Target*> QueryJetson();
	static void Init();

	static volatile bool IsConnected;

private:
	static int JetsonSocket;
	static int acp_socket;

	static volatile bool Initing;
	static volatile bool initErrorFlag;
	
	static pthread_t InitThread;


	static void* DoStart(void* args);
	static Target* Deserialize(char encoded[]);
};


#endif /* JETSERVER_H_ */
