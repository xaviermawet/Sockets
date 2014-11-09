//
//  main.cpp
//  Sockets
//
//  Created by Xavier Mawet on 8/11/14.
//  Copyright (c) 2014 Xavier Mawet. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include "TCPSocketServer.h"

#define PORT 8000

using namespace std;

int main(int argc, const char * argv[])
{
//    TCPSocketServer* tcpsock1 = new TCPSocketServer(PORT);
//    
//    cout << "-------------------------------------" << endl;
//    
//    TCPSocketServer* tcpsock2 = new TCPSocketServer(*tcpsock1);
//    
//    cout << "-------------------------------------" << endl;
//    
//    delete tcpsock1;
//    
//    cout << "-------------------------------------" << endl;
//    
//    delete tcpsock2;
    
    TCPSocketServer sock1(PORT);
    TCPSocketServer sock2(PORT + 1);
    
    cout << "-------------------------------------" << endl;
    
    sock1 = sock2;
    
    cout << "-------------------------------------" << endl;
    
    return EXIT_SUCCESS;
}
