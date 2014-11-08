//
//  Socket.h
//  Sockets
//
//  Created by Xavier Mawet on 8/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#ifndef __Sockets__Socket__
#define __Sockets__Socket__

/* Detect operating system */
#if defined(WIN32) || defined(_WIN32)

    #include <winsock2.h>
    #include <windows.h>

    #define SOCKET_ERRNO    WSAGetLastError()

    typedef int socklen_t;

#elif defined(__unix__) || defined (__gnu_linux__) || \
(defined(__APPLE__) && defined(__MACH__))

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <netdb.h>
    #include <errno.h>

    #define INVALID_SOCKET  -1
    #define SOCKET_ERROR    -1
    #define closesocket(s)  ::close(s) // "Native C" function
    #define SOCKET_ERRNO    errno

    typedef int                 SOCKET;
    typedef struct sockaddr_in  SOCKADDR_IN;
    typedef struct sockaddr     SOCKADDR;
    typedef struct in_addr      IN_ADDR;

#else

    #error Unsupported Operating System

#endif /* Detect operating system */

#include <cstdlib>
#include <cstdio>

class Socket
{
    public:
};

#endif /* defined(__Sockets__Socket__) */
