//
//  TCPSocket.cpp
//  Sockets
//
//  Created by Xavier Mawet on 8/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#include "TCPSocket.h"

TCPSocket::TCPSocket(void)
    : Socket(socket_type::TCP)
{
    std::cout << "TCPSocket constructor" << std::endl;
}

TCPSocket::TCPSocket(const TCPSocket& copy_tcpsocket)
    : Socket(copy_tcpsocket)
{
    std::cout << "TCPSocket copy constructor" << std::endl;
}

TCPSocket& TCPSocket::operator=(const TCPSocket &copy_tcpsocket)
{
    Socket::operator=(copy_tcpsocket);
    
    return *this;
}

TCPSocket::~TCPSocket(void)
{
    std::cout << "TCPSocket destructor" << std::endl;
}
