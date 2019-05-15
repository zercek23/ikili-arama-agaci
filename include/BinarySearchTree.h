/**        
* @file  BinarySearchTree.h
* @description BinarySearchTree'in class'ı, Dugum ve BST struct'ı ve içinde tanımlanmış elemanları.  
* @course  1.Öğretim A Grubu  
* @assignment  3.Ödev   
* @date  16.12.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
#include<iostream>

struct Dugum {
	int veri;
	Dugum *sol;
	Dugum *sag;
	Dugum(const int& vr, Dugum *sl = NULL, Dugum *sg = NULL) {
		veri = vr;
		sol = sl;
		sag = sg;
	}
};
struct BST {
	int veri;
	Dugum *dugum;
	BST *sol;
	BST *sag;
	BST(const int& vr, Dugum *dugum = NULL, BST *sl = NULL, BST *sg = NULL) {
		veri = vr;
		this->dugum = dugum;
		sol = sl;
		sag = sg;
	}
};

class BinarySearchTree
{
private:
	BST *agac;
	BST *adres[99];
	int agacSayisi;
	void AraveEkle(Dugum *&alt_Dugum, const int &yeni);
	BST *AraveEkle(BST *& alt_Dugum, const int & yeni);
	bool AraveSil(Dugum *&alt_Dugum, const int &yeni);
	bool AraveSil(BST *& alt_Dugum, const int & yeni);
	bool DugumSil(Dugum *&alt_Dugum);
	bool DugumSil(BST *& alt_Dugum);
	int Yukseklik(Dugum *alt_Dugum) const;
	int Yukseklik(BST * alt_Dugum) const;
	int MaksDeger(Dugum *alt_Dugum);
	int MinDeger(Dugum *alt_Dugum);
	void SeviyeyiYazdir(Dugum *alt_Dugum, int seviye) const;
public:
	BinarySearchTree();
	void AgacEkle(int yukseklik);
	void MaksDegerCikar();
	void MinDegerCikar();
	void Levelorder() const;
	void Temizle();
	~BinarySearchTree();
};

