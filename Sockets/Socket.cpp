//
//  Socket.cpp
//  Sockets
//
//  Created by Xavier Mawet on 8/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#include "Socket.h"

Socket::Socket(socket_type sock_type)
    : _sock(INVALID_SOCKET)
{
    // Create socket file descriptor
    this->_sock = ::socket(AF_INET, static_cast<int>(sock_type), 0);
    if (!this->is_valid())
        throw SocketException("Unable to create socket", SOCKET_ERRNO);
    
    /* Specifies that the rules used in validating addresses supplied to bind()
     * should allow reuse of local addresses
     */
    int on = 1;
    if (::setsockopt(this->_sock, SOL_SOCKET, SO_REUSEADDR,(const char*)&on,
                     sizeof(on)) == SOCKET_ERROR)
        throw SocketException("Unable to reuse address", SOCKET_ERRNO);
    
    // Initialize struct SOCKADDR_IN
    memset(&this->_addr, 0, sizeof(this->_addr));
}

Socket::Socket(const Socket& copy_socket)
    : _sock(copy_socket._sock)
{
    memcpy((void*)&this->_addr, (void*)&copy_socket._addr, sizeof(SOCKADDR_IN));
}

Socket& Socket::operator=(const Socket& copy_socket)
{
    if (this != &copy_socket)
    {
        // Close current connection if needed
        if (this->is_valid())
            this->close();
        
        this->_sock = copy_socket._sock;
        memcpy((void*)&this->_addr, (void*)&copy_socket._addr, sizeof(SOCKADDR_IN));
    }
    
    return *this;
}

bool Socket::is_valid(void) const
{
    return this->_sock != INVALID_SOCKET;
}

bool Socket::close(void)
{
    if (closesocket(this->_sock) == SOCKET_ERROR)
        return false;
    
    this->_sock = INVALID_SOCKET;
    return true;
}
