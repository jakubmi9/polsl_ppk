#include "stdafx.h"
#include "exceptions.h"
//==============================================================================
void NoArgumentException::writeout()
{
	printf("0x00000001 No argument passed!\n");
}
//==============================================================================
void InvalidArgumentException::writeout()
{
	printf("0x00000002 Invalid argument!\n");
}
//==============================================================================