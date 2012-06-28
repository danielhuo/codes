/*
 * berlinix, 2009/08/13
 *
 * test max tcp connect server
 *
 * 1. ulimit -H -S -n 500000
 */

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>

volatile sig_atomic_t ccount = 0;

void handle(int sno){
	printf("connect count: %d\n", ccount);
	signal(SIGALRM, handle);
	alarm(1);
}

int main(int argc, char* argv[])
{
    int sockfd;
	int opt = 1;
	int connfd;

	unsigned short port;
	struct sockaddr_in addr;

	if(argc != 2){
		printf("usage: serv port\n");
		exit(0);
	}

	port = atoi(argv[1]);
	printf("test server, port %d\n", port);

	signal(SIGALRM, handle);
	alarm(1);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	
	if(bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == 0){
		printf("server bind ok\n");
	}
	else{
		printf("bind failed, %d, %s\n", errno, strerror(errno));
		exit(0);
	}

	listen(sockfd, 1024);

	while(1){
		connfd = accept(sockfd, NULL, 0);
        if(connfd < 0){
            printf("accept error: %d, %s\n", errno, strerror(errno));
            if(errno == EMFILE){
                printf("access max file open, count: %d, server exit\n", ccount);
                break;
            }
        }
		++ccount;
	}

    return 0;
}
