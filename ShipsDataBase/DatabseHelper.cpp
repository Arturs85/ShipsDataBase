#include "pch.h"
#include "DatabaseHelper.h"
#include <exception>
#include <string>
#include <cstdio>
#include "MainPage.xaml.h"
#include "Ship.h"
#include <iostream>  
#include <stdlib.h>  
#include <comdef.h> 
#include "MilitaryShip.h"
#include "CivlShip.h"
//#include "atlbase.h"  
//#include "atlstr.h"  
//#include "comutil.h"  

//using namespace System;

using namespace std;
namespace ShipsDataBase
{
	bool DatabaseHelper::ready = false;
	vector<Ship*> *DatabaseHelper::data;

	DatabaseHelper::DatabaseHelper()
	{

	}

	DatabaseHelper::~DatabaseHelper()
	{
		sqlite3_close(portDatabase);
	}

	void DatabaseHelper::open()
	{
		//int result = sqlite3_open(":memory:", &database);
		int result = sqlite3_open_v2(dbFilePath, &portDatabase, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);

		if (result) {
			// Error
			throw exception(strcat("Error opening database: ", sqlite3_errmsg(portDatabase)));
		}
		else {
			// Ok!
		}
	}

	void DatabaseHelper::create()
	{
		int result1 = sqlite3_open_v2(dbFilePath, &portDatabase, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
		//sqlite3_open(":memory:", &database);
		char*sql2 = "CREATE TABLE ships("  \
			"ID INTEGER PRIMARY KEY AUTOINCREMENT     NOT NULL," \
			"nosaukums     TEXT    NOT NULL," \
			"tonnage     REAL    NOT NULL," \
			"valsts   TEXT     NOT NULL );";
		char*sql3 = "CREATE TABLE militaryShips("  \
			"ID INTEGER PRIMARY KEY      NOT NULL," \
			"lielgabali   REAL    NOT NULL," \
			"missiles   REAL     NOT NULL );";
		char*sql = "CREATE TABLE civilShips("  \
			"ID INTEGER PRIMARY KEY      NOT NULL," \
			"companyName   TEXT    NOT NULL);";
			
		
		char *zErrMsg = 0;
		//- Execute SQL statement
		int result = sqlite3_exec(portDatabase, sql, nullptr, 0, &zErrMsg);
		if (result != SQLITE_OK) {
			//! TODO fix
			char *s = new char[256];
			sprintf(s, "SQL error: %s\n", zErrMsg);
			MainPage::LogMessage(CharToString(s));//StringFromAscIIChars(s));
			sqlite3_free(zErrMsg);
		}
		else {
			MainPage::LogMessage("Table ships created successfully\n");
		}
	}

	void DatabaseHelper::deleteEntry(int id)
	{
		char *zErrMsg = 0;
		char* sql=new char[256];;
		 sprintf(sql, "DELETE from ships WHERE ID = %d; ", id);
		 int result = sqlite3_exec(portDatabase, sql, nullptr, 0, &zErrMsg);
		 sprintf(sql, "DELETE from militaryShips WHERE ID = %d; ", id);
		 result = sqlite3_exec(portDatabase, sql, nullptr, 0, &zErrMsg);
		 sprintf(sql, "DELETE from civilShips WHERE ID = %d; ", id);
		 result = sqlite3_exec(portDatabase, sql, nullptr, 0, &zErrMsg);
	}

	void DatabaseHelper::add(Ship * ship)
	{
				char* stmt2 = new char[256];

		
		char* stmt = new char[256];
		//wchar_t* nosaukums = new wchar_t((ship.getNosaukums())->Data());
		const char* nosaukums = GetCharFromWstring(ship->getNosaukums());
		const char* valsts = GetCharFromWstring(ship->getValsts());
		sprintf(stmt,
			"INSERT INTO ships (nosaukums, tonnage,valsts) "\
			"VALUES ('%s', %d, '%s' );",
			 nosaukums, ship->getTonnage(),valsts);
			
			char *zErrMsg = 0;
		int result = sqlite3_exec(portDatabase, stmt, nullptr, 0, &zErrMsg);
		if (result != SQLITE_OK) {
			//! TODO fix
			char *s = new char[256];
			sprintf(s, "SQL error: %s\n", zErrMsg);
			MainPage::LogMessage(CharToString(s));//StringFromAscIIChars(s));
			sqlite3_free(zErrMsg);
			int a = 4;
		}
		else {
			MainPage::LogMessage("added to ship table  successfully\n");
			int a = 4;
		}
		int lastId = sqlite3_last_insert_rowid(portDatabase);
		MainPage::LogMessage(lastId);

		if (MilitaryShip* militaryShip = dynamic_cast<MilitaryShip*>(ship))//ir military
		{
			MainPage::LogMessage("Military Ship detected, adding to table");
			sprintf(stmt2,
				"INSERT INTO militaryShips (ID,lielgabali, missiles) "\
				"VALUES (%d, %d, %d);",
				lastId, militaryShip->getLielgabali(), militaryShip->getMissiles()); // military id
			result = sqlite3_exec(portDatabase, stmt2, nullptr, 0, &zErrMsg);
			MainPage::LogMessage(result);

		}
		else if (CivilShip* civilShip = dynamic_cast<CivilShip*>(ship))//ir civil
		{
			MainPage::LogMessage("Civil Ship detected, adding to table");
			const char* companyName = GetCharFromWstring(civilShip->getCompanyName());

			sprintf(stmt2,
				"INSERT INTO civilShips (ID, companyName) "\
				"VALUES (%d, '%s');",
				lastId, companyName); //
			result = sqlite3_exec(portDatabase, stmt2, nullptr, 0, &zErrMsg);
			MainPage::LogMessage(result);
			if (result != SQLITE_OK) {
				//! TODO fix
				char *s = new char[256];
				sprintf(s, "SQL error: %s\n", zErrMsg);
				MainPage::LogMessage(CharToString(s));//StringFromAscIIChars(s));
				sqlite3_free(zErrMsg);
				
			}
		}
	}

	void DatabaseHelper::update(Ship * ship)
	{
		char* stmt = new char[256];
		const char* nosaukums = GetCharFromWstring(ship->getNosaukums());
		const char* valsts = GetCharFromWstring(ship->getValsts());
		sprintf(stmt,
			"UPDATE ships "\
			"SET nosaukums='%s', tonnage=%d, valsts='%s'"\
			"WHERE ID = %d;",
			nosaukums, ship->getTonnage(), valsts, ship->getID());
		char *zErrMsg = 0;
		int result = sqlite3_exec(portDatabase, stmt, nullptr, 0, &zErrMsg);//visiem kuìiem
		if (result != SQLITE_OK) {
				}
		else {
			MainPage::LogMessage("Table ships updated successfully\n");
			
		}
		
		if (MilitaryShip* militaryShip = dynamic_cast<MilitaryShip*>(ship))//ir military
		{
			MainPage::LogMessage("Military Ship detected, updating  table");
			sprintf(stmt,
				"UPDATE militaryShips "\
				"SET  lielgabali=%d, missiles=%d "\
				"WHERE ID = %d;", 
				 militaryShip->getLielgabali(), militaryShip->getMissiles(),ship->getID()); // military id
			result = sqlite3_exec(portDatabase, stmt, nullptr, 0, &zErrMsg);
			if (result != SQLITE_OK) {
				//! TODO fix
				char *s = new char[256];
				sprintf(s, "SQL error: %s\n", zErrMsg);
				MainPage::LogMessage(CharToString(s));//StringFromAscIIChars(s));
				sqlite3_free(zErrMsg);
			}

		}else if (CivilShip* civilShip = dynamic_cast<CivilShip*>(ship))//ir civil
		{
			MainPage::LogMessage("civil Ship detected, updating table");
			const char* companyName = GetCharFromWstring(civilShip->getCompanyName());

			sprintf(stmt,
				"UPDATE civilShips "\
				"SET  companyName='%s' "\
				"WHERE ID = %d;",
				companyName,  ship->getID()); // 
			result = sqlite3_exec(portDatabase, stmt, nullptr, 0, &zErrMsg);
			if (result != SQLITE_OK) {
				//! TODO fix
				char *s = new char[256];
				sprintf(s, "SQL error: %s\n", zErrMsg);
				MainPage::LogMessage(CharToString(s));//StringFromAscIIChars(s));
				sqlite3_free(zErrMsg);
			}

		}
	}

	
	Platform::String^ DatabaseHelper::CharToString(const unsigned char * char_array) {
		return CharToString((char *) char_array);
	}

	Platform::String ^ DatabaseHelper::CharToString(const char * char_array)
	{
		if (char_array == NULL) {
			return ref new Platform::String(L"");
			MainPage::LogMessage("CharToString--null Paramater");
		
		}
		std::string s_str = std::string(char_array);
		std::wstring wid_str = std::wstring(s_str.begin(), s_str.end());
		const wchar_t* w_char = wid_str.c_str();
		return ref new Platform::String(w_char);
	}

	vector<Ship*>* DatabaseHelper::getData()
	{
		sqlite3_stmt *stmt;
		sqlite3_prepare_v2(portDatabase, "SELECT ships.ID, ships.nosaukums , ships.tonnage, ships.valsts ,militaryShips.lielgabali, militaryShips.missiles FROM ships join militaryShips on ships.ID = militaryShips.ID "\
			//"UNION SELECT ships.ID, ships.nosaukums, ships.tonnage, ships.valsts, civilShips.companyName FROM ships join civilShips on ships.ID = civilShips.ID"
			" ORDER BY ships.tonnage ", //militaryShips
			-1, &stmt, NULL);
		vector<Ship*> * shipsVect = new vector<Ship*>();

		int rc = sqlite3_step(stmt);
		while (rc != SQLITE_DONE) {
			int id = sqlite3_column_int(stmt, 0);
			Platform::String^ nosaukums=CharToString(sqlite3_column_text(stmt, 1));
			int tonnage = sqlite3_column_int(stmt, 2);
			int lielgabali = sqlite3_column_int(stmt, 4);
			int missiles = sqlite3_column_int(stmt, 5);
			Platform::String^  valsts = CharToString(sqlite3_column_text(stmt, 3));
			shipsVect->push_back(new MilitaryShip(nosaukums,valsts,tonnage,lielgabali,missiles,id));

			rc = sqlite3_step(stmt);
		}

		sqlite3_finalize(stmt);
		// for civil ships
		sqlite3_stmt *stmt2;
		sqlite3_prepare_v2(portDatabase, "SELECT ships.ID, ships.nosaukums , ships.tonnage, ships.valsts ,civilShips.companyName FROM ships join civilShips on ships.ID = civilShips.ID", //militaryShips
			-1, &stmt2, NULL);
		 rc = sqlite3_step(stmt2);
		while (rc != SQLITE_DONE) {
			int id = sqlite3_column_int(stmt2, 0);
			Platform::String^ nosaukums = CharToString(sqlite3_column_text(stmt2, 1));
			int tonnage = sqlite3_column_int(stmt2, 2);
			Platform::String^ companyName = CharToString(sqlite3_column_text(stmt2, 4));
			Platform::String^  valsts = CharToString(sqlite3_column_text(stmt2, 3));
			shipsVect->push_back(new CivilShip(nosaukums, valsts, tonnage,companyName, id));

			rc = sqlite3_step(stmt2);
		}
		sqlite3_finalize(stmt2);

		return shipsVect;
	}

	

	
	const char* DatabaseHelper::GetCharFromWstring(Platform::String^ mwstring) 
	{
		// Create a string of wide characters, display it, and then  
		// use this string to create other types of strings.  
		
			const wchar_t *W = mwstring->Data();
			int Size = wcslen(W);
			char *CString = new char[Size + 1];
			CString[Size] = 0;
			for (int y = 0; y<Size; y++)
			{
				CString[y] = (char)W[y];
			}
			return (const char *)CString;
		
	
	}

}
