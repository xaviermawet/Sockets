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

class TCPSocketClient : public Socket
{
    friend class TCPSocketServer;
    
    public:
    
        explicit TCPSocketClient(void);
        explicit TCPSocketClient(const TCPSocketClient& copy_tcpsocketclient);
        TCPSocketClient& operator=(const TCPSocketClient& copy_tcpsocketclient);
    
        bool connectToHost(const std::string& ip, const int port);
    
        virtual ~TCPSocketClient(void);
    
    protected:
    
        explicit TCPSocketClient(SOCKET sock);
    
        bool connect(const int port, const std::string& host = "");
    
        bool _connected;
};

#endif /* defined(__Sockets__TCPSocketClient__) */
