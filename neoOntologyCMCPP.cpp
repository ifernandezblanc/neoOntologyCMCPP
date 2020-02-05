/*==============================================================================
Author: Dominik Bulka, Iñigo Fernandez del Amo - 2020
Email: inigofernandezdelamo@outlook.com
License: This code has been developed for research and demonstration purposes.

Copyright (c) 2020 Dominik Bulka. All Rights Reserved.
Copyright (c) 2020 Iñigo Fernandez del Amo. All Rights Reserved.
Copyright (c) 2020 Cranfield University. All Rights Reserved.
Copyright (c) 2020 Babcock International Group. All Rights Reserved.

All Rights Reserved.
Confidential and Proprietary - Protected under copyright and other laws.

Date: 26/01/2020
==============================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include "HTTPRequest.hpp"
#pragma comment(lib, "Ws2_32.lib")
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	// Apendix: endl-new line; \-escape symbol (program is not reading next symbol as internal function; \n-new line

	// Declaration of variables
	int ping1 = 0;
	int i = 0;
	int count = 0;
	size_t position;
	char ping[500];
	char ping2[5000];
	char hour[80];
	char date[80];
	char message[500];
	string line1;
	string line2;
	string line3;
	fstream file;
	time_t actual_time;
	struct tm* data;
	strcpy(message, "");
	strcpy(ping, "");
	system("del C:\\DigitalTwin\\data\\ /F /Q");

	// Load the current time into the program and display it as a message
pkt1:
	time(&actual_time);
	data = localtime(&actual_time);
	strftime(hour, 80, "%#c", data);
	system("cls");
	cout << hour << endl;
	strftime(hour, 80, "%y%m%d%H%M%S", data);
	strftime(date, 80, "%Y-%m-%dT%H:%M:%S", data);
	cout << message;

	// Saving information if server fails
	if (count > 0)
	{
		ping1 = system("ping -n 2 -w 20 -i 10 138.250.108.1");
		system("cls");
		cout << message << endl;
		if (ping1 == 1)
		{
			strcpy(message, "Connection with Server restored!\n");
			while (count > 0)
			{
				file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::in | ios::out);
				file.seekg(+0, ios_base::beg);
				getline(file, line1);
				getline(file, line2);

				http::Request request(line1); //.c_str()
				http::Response response = request.send("POST", line2, { "Content-Type: application/json" });
				count--;
			}
		}
		else
		{
			strcpy(message, "Connection with Server lost!\n");
		}
	}
	else
	{
		strcpy(message, "");
	}

	// Component 1 - Device 1 | Component: 1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_2 | Device: Heli_CMC_Connectivity_Time
	ping1 = system("ping -n 2 -w 20 -i 10 -a 192.168.0.2");
	time(&actual_time);
	data = localtime(&actual_time);
	strftime(hour, 80, "%y%m%d%H%M%S", data);
	strftime(date, 80, "%Y-%m-%dT%H:%M:%S", data);

	if (ping1 == 1)
	{
		try
		{
			i = 1;
			// Device 1 disconnected - Time: 0 seconds
			// Http request
			strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_CMC_State_ConnectionTime_");
			strcat(ping, hour);
			strcat(ping, "/input");
			http::Request request(ping);
			// Http post form
			strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_CMC_State_ConnectionTime_");
			strcat(ping2, hour);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
			strcat(ping2, "[");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
			strcat(ping2, "0");
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
			strcat(ping2, date);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#second\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateStatus\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Faulty\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Status\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDominion\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Electrics\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Dominion\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStatePhenomenon\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#ElectricLoss\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Phenomenon\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_CMC_Connectivity_Time\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_2\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
			strcat(ping2, "]");
			strcat(ping2, "}");
			http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
			// Command message
			// cout << string(response.body.begin(), response.body.end()) << endl; // print the result
			strcat(message, "Communication failed with CM_Computer; cable or device broken\n");
		}
		catch (const exception)//const exception& e
		{
			file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
			file << ping << endl << ping2 << endl;
			file.close();
			count++;
			// cerr << "Request failed, error: " << e.what() << endl;
		}
	}
	else
	{
		try
		{
			i = 0;
			// Device 1 connected - Time: 1 second
			// Http request
			strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_CMC_State_ConnectionTime_");
			strcat(ping, hour);
			strcat(ping, "/input");
			http::Request request(ping);
			// Http post from
			strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_CMC_State_ConnectionTime_");
			strcat(ping2, hour);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
			strcat(ping2, "[");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
			strcat(ping2, "1");
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
			strcat(ping2, date);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#second\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateStatus\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Faulty\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Status\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDominion\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Electrics\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Dominion\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStatePhenomenon\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#ElectricLoss\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Phenomenon\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_CMC_Connectivity_Time\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_2\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
			strcat(ping2, "]");
			strcat(ping2, "}");
			http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
			// Command message
			// cout << string(response.body.begin(), response.body.end()) << endl; // print the result
		}
		catch (const exception)
		{
			file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
			file << ping << endl << ping2 << endl;
			file.close();
			count++;
			// cerr << "Request failed, error: " << e.what() << endl;
		}
	}

	// Component 2 - Device 2 | Component: 1_OpEx-0_2_CMR-BBCKCDT2019_1 | Device: Heli_Camera_Connectivity_Time
	ping1 = system("ping -n 2 -w 20 -i 10 -a 192.168.0.3");
	time(&actual_time);
	data = localtime(&actual_time);
	strftime(hour, 80, "%y%m%d%H%M%S", data);
	strftime(date, 80, "%Y-%m-%dT%H:%M:%S", data);
	if (ping1 == 1)
	{
		try
		{
			// Device 2 disconnected - Time: 0 seconds
			// Http request
			strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_Camera_State_ConnectionTime_");
			strcat(ping, hour);
			strcat(ping, "/input");
			http::Request request(ping);
			// Http post form
			strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_Camera_State_ConnectionTime_");
			strcat(ping2, hour);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
			strcat(ping2, "[");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
			strcat(ping2, "0");
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
			strcat(ping2, date);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#second\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateStatus\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Faulty\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Status\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDominion\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Electrics\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Dominion\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStatePhenomenon\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#ElectricLoss\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Phenomenon\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_Camera_Connectivity_Time\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_2_CMR-BBCKCDT2019_1\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
			strcat(ping2, "]");
			strcat(ping2, "}");
			http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
			// Command message
			// cout << string(response.body.begin(), response.body.end()) << endl; // print the result
			strcat(message, "Communication failed with Camera; cable or device broken\n");
		}
		catch (const exception)
		{
			file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
			file << ping << endl << ping2 << endl;
			file.close();
			count++;
			// cerr << "Request failed, error: " << e.what() << endl;
		}
	}
	else
	{
		try
		{
			// Device 2 connected - Time: 1 second
			// Http request
			strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_Camera_State_ConnectionTime_");
			strcat(ping, hour);
			strcat(ping, "/input");
			http::Request request(ping);
			// Http post form
			strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_Camera_State_ConnectionTime_");
			strcat(ping2, hour);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
			strcat(ping2, "[");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
			strcat(ping2, "1");
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
			strcat(ping2, date);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#second\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateStatus\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Faulty\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Status\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDominion\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Electrics\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Dominion\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStatePhenomenon\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#ElectricLoss\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Phenomenon\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_Camera_Connectivity_Time\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_2_CMR-BBCKCDT2019_1\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
			strcat(ping2, "]");
			strcat(ping2, "}");
			http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
			// Command message
			// cout << string(response.body.begin(), response.body.end()) << endl; // print the result
		}
		catch (const exception)
		{
			file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
			file << ping << endl << ping2 << endl;
			file.close();
			count++;
			// cerr << "Request failed, error: " << e.what() << endl;
		}
	}

	// Component 3 - Device 3 | Component: 1_OpEx-0_1_MNT-BBCKTSHBCDT2019_3 | Device: Heli_Monitor_Connectivity_Time
	ping1 = system("ping -n 2 -w 20 -i 10 -a 192.168.0.5");
	time(&actual_time);
	data = localtime(&actual_time);
	strftime(hour, 80, "%y%m%d%H%M%S", data);
	strftime(date, 80, "%Y-%m-%dT%H:%M:%S", data);
	if (ping1 == 1)
	{
		try
		{
			// Device 3 disconnected - Time: 0 seconds
			// Http request
			strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_Monitor_State_ConnectionTime_");
			strcat(ping, hour);
			strcat(ping, "/input");
			http::Request request(ping);
			// Http post form
			strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_Monitor_State_ConnectionTime_");
			strcat(ping2, hour);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
			strcat(ping2, "[");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
			strcat(ping2, "0");
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
			strcat(ping2, date);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#second\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateStatus\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Faulty\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Status\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDominion\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Electrics\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Dominion\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStatePhenomenon\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#ElectricLoss\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Phenomenon\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_Monitor_Connectivity_Time\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_1_MNT-BBCKTSHBCDT2019_3\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
			strcat(ping2, "]");
			strcat(ping2, "}");
			http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
			// Command message
			// cout << string(response.body.begin(), response.body.end()) << endl; // print the result
			strcat(message, "Communication failed with Monitor; cable or device broken\n");
		}
		catch (const exception)
		{
			file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
			file << ping << endl << ping2 << endl;
			file.close();
			count++;
			//cerr << "Request failed, error: " << e.what() << endl;
		}
	}
	else
	{
		try
		{
			// Device 3 connected - Time: 1 second
			// Http request
			strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_Monitor_State_ConnectionTime_");
			strcat(ping, hour);
			strcat(ping, "/input");
			http::Request request(ping);
			// Http post form
			strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_Monitor_State_ConnectionTime_");
			strcat(ping2, hour);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
			strcat(ping2, "[");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
			strcat(ping2, "1");
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
			strcat(ping2, date);
			strcat(ping2, "\",");
			strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#second\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateStatus\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Faulty\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Status\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDominion\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#Electrics\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Dominion\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStatePhenomenon\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#ElectricLoss\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Phenomenon\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_Monitor_Connectivity_Time\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
			strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_1_MNT-BBCKTSHBCDT2019_3\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
			strcat(ping2, "]");
			strcat(ping2, "}");
			http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
			// Command message
			// cout << string(response.body.begin(), response.body.end()) << endl; // print the result
		}
		catch (const exception)
		{
			file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
			file << ping << endl << ping2 << endl;
			file.close();
			count++;
			// cerr << "Request failed, error: " << e.what() << endl;
		}
	}

	// Component (1,2) - Device (4,5,6) | Component: (1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_2,1_OpEx-0_2_RAM-BBCKTSHBRAMDT2019_2) | Device: (Heli_CMC_CPU_Usage,Heli_CMC_CPU_Temperature,Heli_CMC_RAM_Usage)
	if (i == 1)
	{
		goto pkt2;
	}
	strcpy(ping, "C://DigitalTwin/data/"); 									//strcpy-function that overwrites information in the given character variable
	strcat(ping, "CM_date.txt");
pkt3:
	file.open(ping, ios::in | ios::out); 									//opening (creating) a file in a given location, in-to read, out-to write.
	if (file.good())														//conditional function is executed only when the condition from the bracket is true																			//file.good - if successful opening of the file is true
	{ 																		//entry character to a loop or condition
		file.seekg(+0, ios_base::beg); 										//setting the cursor in a file at position 0 relative to the beginning of the file
		getline(file, line1);
		getline(file, line2);
		getline(file, line3);
		file.close();
		position = line1.find("100\""); 							//search function in the string variable of the parenthesis from the bracket and assigning its position to the variable
		if (position < 5) 														//conditional function is executed only when the condition from the bracket is true
		{ 																		//entry character to a loop or condition
			line1 = "100"; 														//operation of assigning a variable to a given value
		} 																		//exit character from a loop or condition
		position = line1.find("\""); 							//search function in the string variable of the parenthesis from the bracket and assigning its position to the variable
		if (position < 5) 														//conditional function is executed only when the condition from the bracket is true
		{ 																		//entry character to a loop or condition
			line1 = "0.0"; 														//operation of assigning a variable to a given value
		}													//transferring the whole line of text from the file to the string variable
		position = line2.find("100"); 							//search function in the string variable of the parenthesis from the bracket and assigning its position to the variable
		if (position < 5) 														//conditional function is executed only when the condition from the bracket is true
		{ 																		//entry character to a loop or condition
			line2 = "100"; 														//operation of assigning a variable to a given value
		}
	}
	else
	{
		if (i == 2)
		{
			goto pkt4;
		}
		else
		{
			i++;
			file.close();
			Sleep(100);
			goto pkt3;
		}
	}
pkt4:
	i = 0;
	file.close();
	time(&actual_time);
	data = localtime(&actual_time);
	strftime(hour, 80, "%y%m%d%H%M%S", data);
	strftime(date, 80, "%Y-%m-%dT%H:%M:%S", data);
	// Component 1 - Device 4 | Component: 1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_2 | Device: Heli_CMC_CPU_Usage
	try
	{
		// Device 4 - Usage in "watt" (UPG: To modify to show real watts)
		// Http request
		strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_CMC_State_CPUUsage_");
		strcat(ping, hour);
		strcat(ping, "/input");
		http::Request request(ping);
		// Http post form
		strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_CMC_State_CPUUsage_");
		strcat(ping2, hour);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
		strcat(ping2, "[");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
		strcat(ping2, line1.c_str());
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
		strcat(ping2, date);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#watt\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_CMC_CPU_Usage\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_2\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
		strcat(ping2, "]");
		strcat(ping2, "}");
		http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
		// Command message
		// cout << string(response.body.begin(), response.body.end()) << endl; // print the result
	}
	catch (const exception)
	{
		file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
		file << ping << endl << ping2 << endl;
		file.close();
		count++;
		// cerr << "Request failed, error: " << e.what() << endl;
	}
	// Component 2 - Device 6 | Component: 1_OpEx-0_2_RAM-BBCKTSHBRAMDT2019_2 | Device: Heli_CMC_RAM_Usage
	try
	{
		// Device 6 - Usage in "watt" (UPG: To modify to show real watts)
		// Http request
		strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_CMC_State_RAMUsage_");
		strcat(ping, hour);
		strcat(ping, "/input");
		http::Request request(ping);
		// Http post form
		strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_CMC_State_RAMUsage_");
		strcat(ping2, hour);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
		strcat(ping2, "[");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
		strcat(ping2, line2.c_str());
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
		strcat(ping2, date);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#watt\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_CMC_RAM_Usage\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_2_RAM-BBCKTSHBRAMDT2019_2\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
		strcat(ping2, "]");
		strcat(ping2, "}");
		http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
		// Command message
		// cout << string(response.body.begin(), response.body.end()) << endl; // print the result
	}
	catch (const exception)
	{
		file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
		file << ping << endl << ping2 << endl;
		file.close();
		count++;
		// cerr << "Request failed, error: " << e.what() << endl;
	}
	// Component 1 - Device 5 | Component: 1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_2 | Device: Heli_CMC_CPU_Temperature
	try
	{
		// Device 5 - Temperature in "degreeCelsius"
		// Http request
		strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_CMC_State_CPUTemperature_");
		strcat(ping, hour);
		strcat(ping, "/input");
		http::Request request(ping);
		// Http post form
		strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_CMC_State_CPUTemperature_");
		strcat(ping2, hour);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
		strcat(ping2, "[");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
		strcat(ping2, line3.c_str());
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
		strcat(ping2, date);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#degreeCelsius\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_CMC_CPU_Temperature\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_2\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
		strcat(ping2, "]");
		strcat(ping2, "}");
		http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
		// Command message
		// cout << string(response.body.begin(), response.body.end()) << endl; // print the result

	}
	catch (const exception)
	{
		file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
		file << ping << endl << ping2 << endl;
		file.close();
		count++;
		// cerr << "Request failed, error: " << e.what() << endl;
	}
	// Component (4,5) - Device (7,8,9) | Component: (1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_1,1_OpEx-0_2_RAM-BBCKTSHBRAMDT2019_1) | Device: (Heli_MMC_CPU_Usage,Heli_MMC_CPU_Temperature,Heli_MMC_RAM_Usage)
pkt2:
	line1 = " ";
	line2 = " ";
	line3 = " ";
	i = 0;
	strcpy(ping, "C://DigitalTwin/data/"); 									//strcpy-function that overwrites information in the given character variable
	strcat(ping, "MM_date.txt");
pkt5:
	file.open(ping, ios::in | ios::out); 									//opening (creating) a file in a given location, in-to read, out-to write.
	if (file.good())														//conditional function is executed only when the condition from the bracket is true																			//file.good - if successful opening of the file is true
	{ 																		//entry character to a loop or condition
		file.seekg(+0, ios_base::beg); 										//setting the cursor in a file at position 0 relative to the beginning of the file
		getline(file, line1);
		getline(file, line2);
		getline(file, line3);
		file.close();
		position = line1.find("100\""); 										//search function in the string variable of the parenthesis from the bracket and assigning its position to the variable
		if (position < 5) 															//conditional function is executed only when the condition from the bracket is true
		{ 																			//entry character to a loop or condition
			line1 = "100"; 															//operation of assigning a variable to a given value
		} 																			//exit character from a loop or condition
		position = line1.find("\""); 											//search function in the string variable of the parenthesis from the bracket and assigning its position to the variable
		if (position < 5) 															//conditional function is executed only when the condition from the bracket is true
		{ 																			//entry character to a loop or condition
			line1 = "0.0"; 															//operation of assigning a variable to a given value
		}																		//transferring the whole line of text from the file to the string variable
		position = line2.find("100"); 											//search function in the string variable of the parenthesis from the bracket and assigning its position to the variable
		if (position < 5) 															//conditional function is executed only when the condition from the bracket is true
		{ 																			//entry character to a loop or condition
			line2 = "100"; 															//operation of assigning a variable to a given value
		}
	}
	else
	{
		if (i == 2)
		{
			goto pkt6;
		}
		else
		{
			i++;
			file.close();
			Sleep(100);
			goto pkt5;
		}
	}
pkt6:
	i = 0;
	file.close();
	time(&actual_time);
	data = localtime(&actual_time);
	strftime(hour, 80, "%y%m%d%H%M%S", data);
	strftime(date, 80, "%Y-%m-%dT%H:%M:%S", data);
	// Component 4 - Device 7 | Component: 1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_1 | Device: Heli_MMC_CPU_Usage
	try
	{
		// Device 7 - Usage in "watt" (UPG: To modify to show real watts)
		// Http request
		strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_MMC_State_CPUUsage_");
		strcat(ping, hour);
		strcat(ping, "/input");
		http::Request request(ping);
		// Http post form
		strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_MMC_State_CPUUsage_");
		strcat(ping2, hour);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
		strcat(ping2, "[");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
		strcat(ping2, line1.c_str());
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
		strcat(ping2, date);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#watt\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_MMC_CPU_Usage\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_1\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
		strcat(ping2, "]");
		strcat(ping2, "}");
		http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
		// Command message
		// cout << string(response.body.begin(), response.body.end()) << endl; // print the result
	}
	catch (const exception)
	{
		file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
		file << ping << endl << ping2 << endl;
		file.close();
		count++;
		//cerr << "Request failed, error: " << e.what() << endl;
	}
	// Component 5 - Device 9 | Component: 1_OpEx-0_2_RAM-BBCKTSHBRAMDT2019_1 | Device: Heli_MMC_RAM_Usage
	try
	{
		// Device 9 - Usage in "watt" (UPG: To modify to show real watts)
		// Http request
		strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_MMC_State_RAMUsage_");
		strcat(ping, hour);
		strcat(ping, "/input");
		http::Request request(ping);
		// Http post form
		strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_MMC_State_RAMUsage_");
		strcat(ping2, hour);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
		strcat(ping2, "[");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
		strcat(ping2, line2.c_str());
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
		strcat(ping2, date);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#watt\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_MMC_RAM_Usage\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_2_RAM-BBCKTSHBRAMDT2019_1\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
		strcat(ping2, "]");
		strcat(ping2, "}");
		http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
		// Command message
		// cout << string(response.body.begin(), response.body.end()) << endl; // print the result
	}
	catch (const exception)
	{
		file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
		file << ping << endl << ping2 << endl;
		file.close();
		count++;
		//cerr << "Request failed, error: " << e.what() << endl;
	}
	// Component 4 - Device 8 | Component: 1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_1 | Device: Heli_MMC_CPU_Temperature
	try
	{
		// Device 8 - Temperature in "degreeCelsius"
		// Http request
		strcpy(ping, "http://138.250.108.1:3003/api/ontologies/diagont/individual/Heli_MMC_State_CPUTemperature_");
		strcat(ping, hour);
		strcat(ping, "/input");
		http::Request request(ping);
		// Http post form
		strcpy(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#Heli_MMC_State_CPUTemperature_");
		strcat(ping2, hour);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontOntology\":\"http://138.250.108.1:3003/api/files/owl/diagont#\",\"ontClass\": \"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontProperties\":");
		strcat(ping2, "[");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateValue\",\"ontValue\":\"");
		strcat(ping2, line3.c_str());
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#double\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateDate\",\"ontValue\":\"");
		strcat(ping2, date);
		strcat(ping2, "\",");
		strcat(ping2, "\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://www.w3.org/2001/XMLSchema#dateTime\",\"ontType\": \"http://www.w3.org/2002/07/owl#DatatypeProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#hasStateUnit\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/diagont#degreeCelsius\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/diagont#Unit\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#measuredByDevice\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#Heli_MMC_CPU_Temperature\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Device\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"},");
		strcat(ping2, "{\"ontName\":\"http://138.250.108.1:3003/api/files/owl/diagont#refersToComponent\",\"ontValue\":\"http://138.250.108.1:3003/api/files/owl/orgont#1_OpEx-0_1_CPU-BBCKTSHBCPUDT2019_1\",\"ontDomain\":\"http://138.250.108.1:3003/api/files/owl/diagont#State\",\"ontRange\":\"http://138.250.108.1:3003/api/files/owl/orgont#Component\",\"ontType\": \"http://www.w3.org/2002/07/owl#ObjectProperty\"}");
		strcat(ping2, "]");
		strcat(ping2, "}");
		http::Response response = request.send("POST", ping2, { "Content-Type: application/json" });
		// Command message
		// cout << string(response.body.begin(), response.body.end()) << endl; // print the result
	}
	catch (const exception)
	{
		file.open("C://DigitalTwin/data/Fail_of_server.txt", ios::out | ios::app);
		file << ping << endl << ping2 << endl;
		file.close();
		count++;
		// cerr << "Request failed, error: " << e.what() << endl;
	}

	line1 = " ";
	line2 = " ";
	line3 = " ";
	goto pkt1;
	system("cls");
	cout << "Critical software error, please contact IT about it\n\n\n";
	system("pause");																		//jump function to the "pkt1" label
	return 0; 																				//exit from the program
}