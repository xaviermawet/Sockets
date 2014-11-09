//
//  TCPSocketClient.h
//  Sockets
//
//  Created by Xavier Mawet on 9/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#ifndef __Sockets__TCPSocketClient__
#define __Sockets__TCPSocketClient__

#include "Socket.h"

#define MAX_RECV 500

class TCPSocketClient : public Socket
{
    friend class TCPSocketServer;
    
    public:
    
        explicit TCPSocketClient(void);
        explicit TCPSocketClient(const TCPSocketClient& copy_tcpsocketclient);
        TCPSocketClient& operator=(const TCPSocketClient& copy_tcpsocketclient);
    
        bool connectToHost(const std::string& ip, const int port);
        bool connectToHostname(const std::string& hostname, const int port);
    
        ssize_t send(const std::string& message) const;
        ssize_t recv(std::string& message) const;
    
        virtual ~TCPSocketClient(void);
    
    protected:
    
        explicit TCPSocketClient(SOCKET sock);
    
        bool gethostbyname(const std::string& hostname);
        bool connect(const int port, const std::string& host = "");
    
        ssize_t send(const void *buffer, size_t length, int flags) const;
        ssize_t recv(void *buffer, size_t length, int flags) const;
    
        bool _connected;
};

#endif /* defined(__Sockets__TCPSocketClient__) */
