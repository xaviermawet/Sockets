//
//  TCPSocket.h
//  Sockets
//
//  Created by Xavier Mawet on 8/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#ifndef __Sockets__TCPSocket__
#define __Sockets__TCPSocket__

#include "Socket.h"

class TCPSocket : public Socket
{
    public:
    
        explicit TCPSocket(void);
        explicit TCPSocket(const TCPSocket& copy_tcpsocket);
        TCPSocket& operator=(const TCPSocket& copy_tcpsocket);
    
        virtual ~TCPSocket(void);
    
    protected:
};

#endif /* defined(__Sockets__TCPSocket__) */
