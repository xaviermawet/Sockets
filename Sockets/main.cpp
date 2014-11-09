//
//  main.cpp
//  Sockets
//
//  Created by Xavier Mawet on 8/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include "TCPSocket.h"

int main(int argc, const char * argv[])
{
    TCPSocket* tcpsock = new TCPSocket();
    std::cout << "TCP socket créée !\n";
    
    delete tcpsock;
    
    return EXIT_SUCCESS;
}
