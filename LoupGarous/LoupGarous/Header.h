#include<stdio.h>
#include<winsock2.h>
#include <windows.h>
#include "Structures.h"
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <thread>



#pragma warning (disable:4996)
#pragma warning (disable:6031)
#pragma warning (disable:6011)
#pragma comment(lib,"ws2_32.lib")
joueur* mesJoueurs;
