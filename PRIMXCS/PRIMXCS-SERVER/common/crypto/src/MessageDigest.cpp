
//MessageDigest.cpp

#include <exception>
#include <fstream>

#include <MessageDigest.h>
#include <DoubleBuffering.h>

#ifndef __MESSAGEDIGEST_CPP__
#define __MESSAGEDIGEST_CPP__

using namespace std;

//Digesting a Full File
void IMessageDigest::DigestFile(string const& rostrFileIn, char* pcDigest)
{
	//Is the User's responsability to ensure that pcDigest is appropriately allocated
	//Open Input File
	ifstream in(rostrFileIn.c_str(), ios::binary);
	if(!in)
	{
		string ostrMsg = "FileDigest ERROR: in IMessageDigest::DigestFile(): Cannot open File " + rostrFileIn + "!";
		throw runtime_error(ostrMsg);
	}
	//Resetting first
	Reset();
	//Reading from file
	char szLargeBuff[BUFF_LEN+1] = {0};
	char szBuff[DATA_LEN+1] = {0};
	CDoubleBuffering oDoubleBuffering(in, szLargeBuff, BUFF_LEN, DATA_LEN);
	int iRead;
	while((iRead=oDoubleBuffering.GetData(szBuff)) > 0)
		AddData(szBuff, iRead);
	in.close();
	//Final Step
	FinalDigest(pcDigest);
}

#endif // __MESSAGEDIGEST_CPP__
