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

TCPSocketClient::~TCPSocketClient(void)
{
    
}
