#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

int main(int argc, char** argv){
    return 0;

}

int conserve(const* server_address){
    int socket_fd=socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_port=htons(25);
    inet_pton(AF_INET,GetIPAddress(server_address ,addr.sin_addr)==1){
        connect(socket_fd, &addr, sizeof(addr));
    }
    return socket_fd;
}

const char* GetIPAddress(const* target_domain){
    const char* target_ip;
    struct in_addr *host_address;
    struct hostent * raw_list=gethostbyname(target_domain);
    for(int i = 0; raw_list -> h_addr_list[i]!=0;i++){
        host_address = raw_list->h_addr_list[i];
        target_ip=inet_ntoa(host_address);
    }
    return target_ip;
}