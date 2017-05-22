#pragma once
#include <sqlite3.h>
#include "Ship.h"
#include <vector>
class Ship;
using namespace std;
namespace ShipsDataBase
{
	class DatabaseHelper {

	private:
		static bool ready;
		sqlite3 * portDatabase;
		static vector<Ship*> *data;
		const char* dbFilePath = "C:/Users/user/AppData/Local/Packages/5f3229d4-90a7-47ec-990c-92a3e1ff9adc_yzekw4x8qxe1g/LocalState/testDB2.db";
	public:
		DatabaseHelper();
		~DatabaseHelper();
		void open();
		void create();
		void close();
		void deleteEntry(int id);
		void add(Ship*);
		void update(Ship*);
		static Platform::String ^ CharToString(const unsigned char * char_array);
		static Platform::String ^ CharToString(const  char * char_array);

		vector<Ship*> * getData();
		static int insertShipCallback(void*data, int argc, char ** argv, char **azColName);
		static int callback(void*data, int argc, char ** argv, char **azColName);
		const char * GetCharFromWstring(Platform::String ^ mwstring);
	};
}