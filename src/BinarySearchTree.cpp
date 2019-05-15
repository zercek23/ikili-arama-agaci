/**        
* @file  BinarySearchTree.cpp
* @description BinarySearchTree'in classının içindeki fonksiyonları.  
* @course  1.Öğretim A Grubu  
* @assignment  3.Ödev   
* @date  16.12.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
#include "BinarySearchTree.h"
#include <cmath>
#include <algorithm>
using namespace std;

void BinarySearchTree::AraveEkle(Dugum *&alt_Dugum, const int &yeni) {
	if (alt_Dugum == NULL) alt_Dugum = new Dugum(yeni);
	else if (yeni < alt_Dugum->veri)
		AraveEkle(alt_Dugum->sol, yeni);
	else if (yeni > alt_Dugum->veri)
		AraveEkle(alt_Dugum->sag, yeni);
	else return; // Aynı eleman var.
}
BST *BinarySearchTree::AraveEkle(BST *&alt_Dugum, const int &yeni) {
	
	if (alt_Dugum == NULL) {alt_Dugum = new BST(yeni);system("pause");}
	else if (yeni < alt_Dugum->veri) 
		AraveEkle(alt_Dugum->sol, yeni);
	else if (yeni > alt_Dugum->veri) 
		AraveEkle(alt_Dugum->sag, yeni);	
	else return alt_Dugum; // Aynı eleman var.
}
bool BinarySearchTree::AraveSil(Dugum *&alt_Dugum, const int &yeni)
{
	if (alt_Dugum == NULL) return false; //Eleman yok
	if (alt_Dugum->veri == yeni)
		return DugumSil(alt_Dugum);
	else if (yeni < alt_Dugum->veri)
		return AraveSil(alt_Dugum->sol, yeni);
	else
		return AraveSil(alt_Dugum->sag, yeni);
}
bool BinarySearchTree::AraveSil(BST *&alt_Dugum, const int &yeni)
{
	if (alt_Dugum == NULL) return false; //Eleman yok
	if (alt_Dugum->veri == yeni)
		return DugumSil(alt_Dugum);
	else if (yeni < alt_Dugum->veri)
		return AraveSil(alt_Dugum->sol, yeni);
	else
		return AraveSil(alt_Dugum->sag, yeni);
}
bool BinarySearchTree::DugumSil(Dugum *&alt_Dugum)
{
	Dugum *silinecekDugum = alt_Dugum;

	if (alt_Dugum->sag == NULL) alt_Dugum = alt_Dugum->sol;
	else if (alt_Dugum->sol == NULL)alt_Dugum = alt_Dugum->sag;
	else {
		silinecekDugum = alt_Dugum->sol;
		Dugum *ebeveynDugum = alt_Dugum;
		while (silinecekDugum->sag != NULL) {
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->sag;
		}
		alt_Dugum->veri = silinecekDugum->veri;
		if (ebeveynDugum == alt_Dugum) alt_Dugum->sol = silinecekDugum->sol;
		else ebeveynDugum->sag = silinecekDugum->sol;
	}
	delete silinecekDugum;
	return true;
}
bool BinarySearchTree::DugumSil(BST *&alt_Dugum)
{
	BST *silinecekDugum = alt_Dugum;

	if (alt_Dugum->sag == NULL) alt_Dugum = alt_Dugum->sol;
	else if (alt_Dugum->sol == NULL)alt_Dugum = alt_Dugum->sag;
	else {
		silinecekDugum = alt_Dugum->sol;
		BST *ebeveynDugum = alt_Dugum;
		while (silinecekDugum->sag != NULL) {
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->sag;
		}
		alt_Dugum->veri = silinecekDugum->veri;
		if (ebeveynDugum == alt_Dugum) alt_Dugum->sol = silinecekDugum->sol;
		else ebeveynDugum->sag = silinecekDugum->sol;
	}
	delete silinecekDugum;
	return true;
}

int BinarySearchTree::Yukseklik(Dugum *alt_Dugum)const {
	if (alt_Dugum == NULL) return -1; // Ortada düğüm yoksa yükseklik anlamsızdır. Kodun çalışması adına -1 verilmektedir.
	return 1 + max(Yukseklik(alt_Dugum->sol), Yukseklik(alt_Dugum->sag));
}
int BinarySearchTree::Yukseklik(BST *alt_Dugum)const {
	if (alt_Dugum == NULL) return -1; // Ortada düğüm yoksa yükseklik anlamsızdır. Kodun çalışması adına -1 verilmektedir.
	return 1 + max(Yukseklik(alt_Dugum->sol), Yukseklik(alt_Dugum->sag));
}
int BinarySearchTree::MaksDeger(Dugum *alt_Dugum)
{
	if (alt_Dugum == NULL) return 0;
	if (alt_Dugum->sag != NULL) return MaksDeger(alt_Dugum->sag);
	return alt_Dugum->veri;
}
int BinarySearchTree::MinDeger(Dugum *alt_Dugum)
{
	if (alt_Dugum == NULL) return 0;
	if (alt_Dugum->sol != NULL) return MinDeger(alt_Dugum->sol);
	return alt_Dugum->veri;
}
void BinarySearchTree::SeviyeyiYazdir(Dugum *alt_Dugum, int seviye)const {
	if (alt_Dugum == NULL) return;
	if (seviye == 0) cout << alt_Dugum->veri << " ";
	else {
		SeviyeyiYazdir(alt_Dugum->sol, seviye - 1);
		SeviyeyiYazdir(alt_Dugum->sag, seviye - 1);
	}
}
BinarySearchTree::BinarySearchTree()
{
	agac = NULL;
	agacSayisi = 0;
}
void BinarySearchTree::AgacEkle(int yukseklik)
{
	agac = new BST(yukseklik);
	agac = AraveEkle(agac, yukseklik);
	adres[agacSayisi] = agac;
	
	AraveEkle(agac->dugum, rand() % 100 + 1);
	int a = 0;
	while (a != yukseklik)
	{
		AraveEkle(agac->dugum, rand() % 100 + 1);
		a = Yukseklik(agac->dugum);
	}
	agacSayisi++;
}
void BinarySearchTree::MaksDegerCikar()
{
	for (int i = 0; i < agacSayisi; i++)
	{
		if (adres[i]->dugum != NULL)
		{
			if (adres[i]->dugum == NULL)
			{
				AraveSil(adres[i], adres[i]->veri);
				agacSayisi--;
			}
			else AraveSil(adres[i]->dugum, MaksDeger(adres[i]->dugum));
		}		
	}
}
void BinarySearchTree::MinDegerCikar()
{
	for (int i = 0; i < agacSayisi; i++)
	{
		if (adres[i]->dugum != NULL)
		{
			if (adres[i]->dugum == NULL)
			{
				AraveSil(adres[i], adres[i]->veri);
				agacSayisi--;
			}
			else AraveSil(adres[i]->dugum, MinDeger(adres[i]->dugum));
		}
	}
}

void BinarySearchTree::Levelorder()const {
	for (int i = 0; i < agacSayisi; i++)
	{
		if (adres[i]->dugum != NULL)
		{
			int h = Yukseklik(adres[i]->dugum);
			for (int level = 0; level <= h; level++)
				SeviyeyiYazdir(adres[i]->dugum, level);
			cout << endl << endl;
		}
	}
}

void BinarySearchTree::Temizle() {
	for(int i = 0; i < agacSayisi; i++)
	{
		while(adres[i]->dugum == NULL) MaksDegerCikar();
		DugumSil(adres[i]);
	}	
}
BinarySearchTree::~BinarySearchTree()
{
	delete agac->dugum;
	delete agac;
}
