//
//  UDPSocket.h
//  Sockets
//
//  Created by Xavier Mawet on 9/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#ifndef __Sockets__UDPSocket__
#define __Sockets__UDPSocket__

#include "Socket.h"

class UDPSocket : public Socket
{
    public:
    
        explicit UDPSocket(void);
        explicit UDPSocket(const UDPSocket& copy_udpsocket);
        UDPSocket& operator=(const UDPSocket& copy_udpsocket);
    
        virtual ~UDPSocket(void);
    
    protected:
};

#endif /* defined(__Sockets__UDPSocket__) */
