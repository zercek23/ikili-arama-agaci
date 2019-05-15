/**        
* @file  main.cpp
* @description Programın çalıştığı ve bittiği main dosyası.
* @course  1.Öğretim A Grubu  
* @assignment  3.Ödev   
* @date  16.12.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
#include <iostream>
#include "BinarySearchTree.cpp"
#include <string>
using namespace std;


int main() {
	BinarySearchTree *agac = new BinarySearchTree();
	string a;
	int sec;

	cout << "Basamaklari giriniz: ";
	getline(cin, a);

	for (int i = 0; i < a.length(); i++)
	{	
		char b = a[i];
		int sayi = b - 48;
		agac->AgacEkle(sayi);		
	}

	do {
		system("cls");
		cout << "1-Agaclardan Maksimum Degeri Cikar" << endl;
		cout << "2-Agaclardan Minimum Degeri Cikar" << endl;
		cout << "3-Tum Agaclari Level Order Yazdir" << endl;
		cout << "4-Cikis" << endl;
		cout << "=> ";
		cin >> sec;

		if (sec == 1) agac->MaksDegerCikar();
		else if (sec == 2) agac->MinDegerCikar();
		else if (sec == 3) 
		{ 
			agac->Levelorder();
			system("pause");
		}
		else if (sec == 4)break;
	} while (sec != 4);
	
	delete agac;
	return 0;
}