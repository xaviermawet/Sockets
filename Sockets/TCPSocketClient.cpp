//
//  TCPSocketClient.cpp
//  Sockets
//
//  Created by Xavier Mawet on 9/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#include "TCPSocketClient.h"

TCPSocketClient::TCPSocketClient(void)
    : Socket(socket_type::TCP), _connected(false)
{
    
}

TCPSocketClient::TCPSocketClient(const TCPSocketClient& copy_tcpsocketclient)
    : Socket(copy_tcpsocketclient), _connected(copy_tcpsocketclient._connected)
{
    
}

TCPSocketClient& TCPSocketClient::operator=(const TCPSocketClient& copy_tcpsocketclient)
{
    if (this != &copy_tcpsocketclient)
    {
        Socket::operator=(copy_tcpsocketclient);
        this->_connected = copy_tcpsocketclient._connected;
    }
    
    return *this;
}

bool TCPSocketClient::connectToHost(const std::string& ip, const int port)
{
    this->_connected = this->connect(port, ip);
    
    if (!this->_connected)
        throw SocketException("Unable to connect to the host", SOCKET_ERRNO);
    
    return true;
}

TCPSocketClient::~TCPSocketClient(void)
{
    
}

TCPSocketClient::TCPSocketClient(SOCKET sock)
    : Socket(sock), _connected(false)
{
    
}

bool TCPSocketClient::connect(const int port, const std::string& host)
{
    if (!this->isValid())
        return false;
    
    this->_addr.sin_family = AF_INET;
    this->_addr.sin_port   = htons(port);
    
    if (host != "")
    {
        inet_pton(AF_INET, host.c_str(), &this->_addr.sin_addr);
        
        if (SOCKET_ERRNO == EAFNOSUPPORT)
            return false;
    }
    
    return ::connect(this->_sock, (SOCKADDR*)&this->_addr, sizeof(SOCKADDR))
            != SOCKET_ERROR;
}
