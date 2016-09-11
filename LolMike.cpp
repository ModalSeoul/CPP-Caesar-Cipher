// LolMike.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Caesar.h"
#include <iostream>

Caesar m_Caesar;

int main()
{
 	char* felon = m_Caesar.encrypt("neck tattoo");
	std::cout << felon << std::endl;
	int n;
	std::cin >> n;
	return 0;
}