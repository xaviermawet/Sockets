//
//  TCPSocketServer.h
//  Sockets
//
//  Created by Xavier Mawet on 9/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#ifndef __Sockets__TCPSocketServer__
#define __Sockets__TCPSocketServer__

#include "TCPSocket.h"
#include "SocketServer.h"

#define DEFAULT_MAX_CON  5

class TCPSocketServer : public SocketServer
{
    public:
    
        explicit TCPSocketServer(int port,
                                 int max_pending_connexions = DEFAULT_MAX_CON);
        explicit TCPSocketServer(const TCPSocketServer& copy_tcpsocketserver);
        TCPSocketServer& operator=(const TCPSocketServer& copy_tcpsocketserver);
    
        virtual ~TCPSocketServer(void);
    
    protected:
    
        int _pendingConnections;
};

#endif /* defined(__Sockets__TCPSocketServer__) */
