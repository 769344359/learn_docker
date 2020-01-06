#include <linux/netlink.h>
#include <sys/socket.h>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
int main(){
    // create a socket fd
   int sock_fd = socket(AF_NETLINK, SOCK_RAW, 0);
   if(sock_fd <0){
       perror("create socket error");
       exit(-1);
   }

    //bind
   	struct sockaddr_nl	local;
       	memset(&local, 0, sizeof(local));
	local.nl_family = AF_NETLINK;
	local.nl_groups = 0;
   	if (bind(sock_fd, (struct sockaddr *)&local,
		 sizeof(local)) < 0) {
		perror("Cannot bind netlink socket");
		return -1;
	}
}