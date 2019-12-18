#include<stdio.h>
#include<winsock2.h>
#include <windows.h>
#include "Structures.h"
#include <errno.h>
#include <fcntl.h>


void ConnectS();
void Deconnect();



#pragma warning (disable:4996)
#pragma comment(lib,"ws2_32.lib")
