#include <stdio.h>
#include <unistd.h>
#include <string.h> 

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

int main(){

FILE *fp;

char returnData[64];

fp = popen("/sbin/ifconfig eth0", "r");

while (fgets(returnData, 64, fp) != NULL)
{

    printf("%s", returnData);
}

pclose(fp);
}
