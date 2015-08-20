#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>


int main()
{
	FILE* fp;
	char returnData[64];
        
	fp = popen("/sbin/ifconfig eth0", "r");
	char x[75][75];
	int i = 0;
	
	while (fgets(returnData, 64, fp) != NULL)
	{
     char* token = strtok(returnData, ":");
		while(token != NULL)
		{			
			strcpy(x[i], token);
			i++;
    		token = strtok(NULL," ");
		}	      
	}
	printf("IP Address eth0: %s \n", x[6]);
	pclose(fp);
}
