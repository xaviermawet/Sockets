//
//  TCPSocketServer.cpp
//  Sockets
//
//  Created by Xavier Mawet on 9/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#include "TCPSocketServer.h"

TCPSocketServer::TCPSocketServer(int port, int max_pending_connections)
    : SocketServer(socket_type::TCP, port),
     _maxPendingConnections(max_pending_connections)
{
    std::cout << "TCPSocketServer constructor" << std::endl;
    
    // Listen
    this->setMaxPendingConnections(max_pending_connections);
}

TCPSocketServer::TCPSocketServer(const TCPSocketServer& copy_tcpsocketserver)
    : SocketServer(copy_tcpsocketserver),
      _maxPendingConnections(copy_tcpsocketserver._maxPendingConnections)
{
    std::cout << "TCPSocketServer copy constructor" << std::endl;
}

TCPSocketServer& TCPSocketServer::operator=(const TCPSocketServer& copy_tcpsocketserver)
{
    std::cout << "TCPSocketServer operator =" << std::endl;
    
    SocketServer::operator=(copy_tcpsocketserver);

    this->_maxPendingConnections = copy_tcpsocketserver._maxPendingConnections;
    
    return *this;
}

int TCPSocketServer::maxPendingConnections(void) const
{
    return this->_maxPendingConnections;
}

bool TCPSocketServer::setMaxPendingConnections(int max_pending_connections)
{
    if (max_pending_connections < 0)
        throw SocketException("Number of pending connections must be greater than zero");
    
    if (!this->listen(max_pending_connections))
        throw SocketException("Could not set socket in passive mode", SOCKET_ERRNO);
    
    this->_maxPendingConnections = max_pending_connections;
    
    return true;
}

TCPSocketServer::~TCPSocketServer(void)
{
    std::cout << "TCPSocketServer destructor" << std::endl;
}

bool TCPSocketServer::listen(const int backlog) const
{
    if (!this->isValid())
        return false;
    
    return ::listen(this->_sock, backlog) != SOCKET_ERROR;
}
