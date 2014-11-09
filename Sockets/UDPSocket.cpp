//
//  UDPSocket.cpp
//  Sockets
//
//  Created by Xavier Mawet on 9/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#include "UDPSocket.h"

UDPSocket::UDPSocket(void)
    : Socket(socket_type::UDP)
{
    // Nothing to do here ...
}

UDPSocket::UDPSocket(const UDPSocket& copy_udpsocket)
    : Socket(copy_udpsocket)
{
    // Nothing to do here ...
}

UDPSocket& UDPSocket::operator=(const UDPSocket& copy_udpsocket)
{
    if (this != &copy_udpsocket)
    {
        Socket::operator=(copy_udpsocket);
    }
    
    return *this;
}

UDPSocket::~UDPSocket(void)
{
    // Nothing to do here ...
}
