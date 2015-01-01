#include "JetServer.h"

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0])) //please note that this will not work on dynamically allocated arrays

volatile bool JetServer::IsConnected = false;
volatile bool JetServer::Initing = false;
int JetServer::JetsonSocket = 0;
int JetServer::acp_socket = 0;

bool JetServer::Init()
{
	Initing = true;
	if(IsConnected)
	{
		Initing = false;
		return true;		
	}
	
	JetsonSocket = socket(AF_INET,SOCK_STREAM,TCP_SOCKET);
	if(JetsonSocket < 0)
	{
		Initing = false;
		return false;
	}

	struct sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_port = htons(JPORT);
	sa.sin_addr.s_addr = INADDR_ANY;

	if(bind(JetsonSocket,(struct sockaddr *)&sa, sizeof(sa)) != 0)
	{
		//failure if not 0
		Initing = false;
		return false;
	}

	if(listen(JetsonSocket,6) < 0)
	{
		Initing = false;
		return false;
	}

	struct sockaddr sar;
	/*socklen_t*/ int st;
	SmartDashboard::PutString("JetServer Connection Status","Connecting");
	acp_socket = accept(JetsonSocket,&sar,&st);
	SmartDashboard::PutString("JetServer Connection Status","Connected");

	IsStarted=true;
	Initing = false;
	return true;
}


vector<Target*> JetServer::QueryJetson()
{
	vector<Target*> targets;
	if(!IsStarted)
	{
		return targets;
	}
	
	char buffer[sizeof(int)];
	char targetbuffer[TARGETSIZE];

	recv(acp_socket,buffer,4,0);
    int UpcomingTargets = *(int*)buffer;


	for(int i = 0; i < UpcomingTargets; i++)
	{
		if(recv(acp_socket,targetbuffer,TARGETSIZE,0) == -1){
			IsStarted = false;
			SmartDashboard::PutString("JetServer Connection Status","Disconnected");
			return targets;
		}
		targets.push_back(Deserialize(targetbuffer));
	}

	return targets;
}

Target* JetServer::Deserialize(char encoded[])
{
	if(ARRAY_SIZE(encoded) == TARGETSIZE)
	{
		Target* target = new Target();

		target->type = *(TargetType*)encoded;
		target->distance = *(double*)(&encoded[sizeof(int)]);
		target->h_angle = *(double*)(&encoded[sizeof(double) + sizeof(int)]);
		target->v_angle = *(double*)(&encoded[2*sizeof(double)+ sizeof(int)]);

		return target;
	}
	else
	{
		return NULL;
	}
}
