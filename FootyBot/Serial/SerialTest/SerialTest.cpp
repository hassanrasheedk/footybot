// SerialTest.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <windows.h>

#include "Serial.h"
#include "stdafx.h"

using namespace std;

#define RX_BUFFSIZE 20

void printUsage(_TCHAR progName[]);


int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 2)
	{
		printUsage(argv[0]);

		cout << "press any key and enter to quit" << endl;
		char temp;
		cin >> temp;

		return 10;
	}

	try
	{
		cout << "Opening com port" << endl;
		tstring commPortName(argv[1]);
		Serial serial(commPortName);
		cout << "Port opened" << endl;

		cout << "writing something to the serial port" << endl;
		serial.flush();
		int sentinel = 0;
		while (true)
		{
			char *hi = "F";
			sentinel++;
			switch (sentinel)
			{
			case 1:
				hi = "R";
				break;
			case 2:
				hi = "L";
				break;
			default:
				return 0;
				break;
			}
			int bytesWritten = serial.write(hi);
			cout << bytesWritten << " bytes were written to the serial port" << hi << endl;
			if (bytesWritten != sizeof(hi) - 1)
			{
				cout << "Writing to the serial port timed out" << endl;
			}

			char buffer[RX_BUFFSIZE];

			/*cout << "Reading from the serial port: ";
			for (int i = 0; i < 10; i++)
			{
			int charsRead = serial.read(buffer, RX_BUFFSIZE);
			cout << buffer;
			Sleep(100);
			}
			cout << endl;*/
			Sleep(2000);
		}

	}
	catch (const char *msg)
	{
		cout << msg << endl;
	}

	cout << "press any key and enter to quit" << endl;
	char temp;
	cin >> temp;

	return 0;
}

void printUsage(_TCHAR progName[])
{
#if defined(UNICODE)
	wcout << progName << " <comm port>" << endl
		<< "e.g., " << progName << " COM1" << endl;
#else
	cout << progName << " <comm port>" << endl
		<< "e.g., " << progName << " COM1" << endl;
#endif

}