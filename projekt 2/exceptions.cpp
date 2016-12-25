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
void AlreadyLoadedException::writeout()
{
	printf("0x00000003 A database is already loaded!\n");
}
//==============================================================================
void InvalidListTypeException::writeout()
{
	printf("0x00000004 Creating lists of this type is not supported!\n");
}
//==============================================================================
void CorruptedDatabaseException::writeout()
{
	printf("0x00000005 Database file is corrupted!\n");
}
//==============================================================================
void FileNotFoundException::writeout()
{
	printf("0x00000006 Database file is missing! Check filename and try again.\n");
}
//==============================================================================
void DatabaseNotLoadedException::writeout()
{
	printf("0x00000007 No database is loaded right now! A database is required for that operation.\n");
}
//==============================================================================