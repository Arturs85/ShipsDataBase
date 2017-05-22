//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once
#include <sqlite3.h>
#include "MainPage.g.h"
#include "Ship.h"
#include "CXclass.h"
#include "ShipViewModel.h"
#include "DatabaseHelper.h"
using namespace std;
class DatabaseHelper;
namespace ShipsDataBase
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();
		static void LogMessage(Object ^ parameter);
		property ShipViewModel^ ViewModel
		{
			ShipViewModel^ get() { return this->viewModel; };
		}
//static Ship* CxToShip(CXclass^ item);
	private:
		int sortNumber =0;
		int militaryShipCount = 0;
		int civilShipCount = 0;
		Platform::String^ statusText = "";
		CXclass^ selectedItem;
		ShipViewModel^ viewModel;
				DatabaseHelper* databaseHelper;
		sqlite3 *testDB;
		void refreshList();
		void appBarButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		void appBarButton1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void appBarButtonSave_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void listView_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
		void appBarButtonDelete_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void AddMilitary_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void addCivil_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Page_Loaded_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
