//
//  TCPSocketServer.cpp
//  Sockets
//
//  Created by Xavier Mawet on 9/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#include "TCPSocketServer.h"

TCPSocketServer::TCPSocketServer(int port, int max_pending_connexions)
    : SocketServer(socket_type::TCP, port),
     _pendingConnections(max_pending_connexions)
{
    std::cout << "TCPSocketServer constructor" << std::endl;
}

TCPSocketServer::TCPSocketServer(const TCPSocketServer& copy_tcpsocketserver)
    : SocketServer(copy_tcpsocketserver),
      _pendingConnections(copy_tcpsocketserver._pendingConnections)
{
    std::cout << "TCPSocketServer copy constructor" << std::endl;
}

TCPSocketServer& TCPSocketServer::operator=(const TCPSocketServer& copy_tcpsocketserver)
{
    std::cout << "TCPSocketServer operator =" << std::endl;
    
    SocketServer::operator=(copy_tcpsocketserver);
    
    this->_pendingConnections = copy_tcpsocketserver._pendingConnections;
    
    return *this;
}

TCPSocketServer::~TCPSocketServer(void)
{
    std::cout << "TCPSocketServer destructor" << std::endl;
}
