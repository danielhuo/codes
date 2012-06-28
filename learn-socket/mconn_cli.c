/*
 * berlinix, 2009/08/13
 *
 * test max tcp connect client
 *
 * 1. ulimit -H -S -n 100000
 * 2. sysctl -w net.ipv4.ip_local_port_range="1025 61000"
 */

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    int sockfd;
    const int maxfd = 250000; 
    int count = 0;
	int opt = 1;
	int connfd;

	unsigned short port;
	const char* ip;
	struct sockaddr_in addr;
	struct sockaddr_in maddr;	// my addr
	unsigned short mport;

	if(argc != 3){
		printf("usage: cli ip port\n");
		exit(0);
	}

	ip = argv[1];
	port = atoi(argv[2]);
	mport = port + 2;
	printf("test client, server %s:%d\n", ip, port);

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	inet_pton(AF_INET, ip, &addr.sin_addr);

	while(count < maxfd){
    	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
			printf("create socket failed, %d, %s\n", errno, strerror(errno));
			break;
		}

		if(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) != 0){
			printf("count(%d), sockfd(%d), connect failed, %d, %s\n", count, sockfd, errno, strerror(errno));
			break;
		}

		++count;
	}

	printf("connect count: %d\n", count);
    fflush(stdout);
    sleep(10*60);

    return 0;
}
