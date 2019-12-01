#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
// 2018280059(A �ubesi) Ey�b Salih �zdemir

/*program�n mant���n� python �zerinde �al��arak oturttum ve python'da tamamlad�m. c++'a �evirmeye �al��t���mda,
ufak �eylerden beklemedi�im �ekilde zorluklarla kar��la�t�m. bu y�zden program�n yap�s� 
oldu�undan �ok daha kar���k g�z�k�yor, bunun fark�nday�m.

�zellikle fonksiyon i�inde fonksiyon tan�mlayamama k�sm�, derli toplu yap�y� �ok bozdu.
ancak commentleri takip ederseniz, anlamak �ok daha kolay olacakt�r.
sonraki programlarda daha temiz bir d�zen kurmaya �al��aca��m. */

//*Referans 1, say� sistemleri aras� �evirme mant���:
//*https://www.ipracticemath.com/learn/numbersense/roman-numerals

//fonksiyon tan�mlamalar�
int BirlerBasamagi(int girdi); 
int OnlarBasamagi(int girdi);
int YuzlerBasamagi(int girdi);
int BinlerBasamagi(int girdi);

//sonucu b�y�k harfle vermek i�in gerekli fonksiyon
//*Referans 2, metni b�y�k harfe �evirme fonksiyonu:
//*https://stackoverflow.com/a/34946858
void toUpperCase(std::string& str) {
	std::transform(str.begin(), str.end(), str.begin(), ::toupper); }

//basamak sayisi hesaplama fonksiyonu
int BasamakSayisiBulma(int sayii) {
	int basamakSayisi=1;
	while (sayii>9) {
		sayii = sayii / 10;
	 	basamakSayisi += 1; }
	return basamakSayisi; }
	
//girilen roman say�s�n� decimal'a �evirmek i�in harflerine g�re de�er d�nd�rme fonksiyonu
//*Referans 3, "C++ forbids comparison between pointer and integer" hatas�n�n sebebi,
//*char ile i�lem yaparken single olmas� gerekirken, double quote kullanmak imi�.
//*https://stackoverflow.com/a/2263700
int CalcValue(char x) {
	int c;
	if (x == 'I' || x == 'i' || x == '�' || x == '�') {
 	    c = 1;
	    return c; }
	else if (x == 'V' || x == 'v') {
		c = 5;
		return c; }
	else if (x == 'X' || x == 'x') {
		c = 10;
		return c; }
	else if (x == 'L' || x == 'l') {
		c = 50;
		return c; }
	else if (x == 'C' || x == 'c') {
		c = 100;
		return c; }
	else if (x == 'D' || x == 'd') {
		c = 500;
		return c; }
	else if (x == 'M' || x == 'm') {
		c = 1000;
		return c; } }
	
string girdi;

//roman rakam�n�, CalcValue'dan ald��� de�erlere g�re decimal olarak yazd�ran fonksiyon
void RomanCevirYazdir() {
cout << "Roman rakami giriniz: "<<endl;
cin >> girdi;
	
int sonuc = 0;
for (int i = 0; i<girdi.length(); i++) {
	if (CalcValue(girdi[i]) >= CalcValue(girdi[i+1])) {
		sonuc = sonuc + CalcValue(girdi[i]); }
	else {
		sonuc = sonuc - CalcValue(girdi[i]); } }	
toUpperCase(girdi);
cout << girdi << "= " << sonuc + CalcValue(girdi[-1])<<endl; 
/*i<girdi.length ve i++ i�lemi son karakterde �ak��aca�� i�in do�ru de�er hesaplamas�n� "sonuc + CalcValue(girdi[-1])" �eklinde
son karakterin de�erini sonuca ekleyerek ��zd�m
*/
}

int birlerBasamagi=0;
int onlarBasamagi=0;
int yuzlerBasamagi=0;
int binlerBasamagi=0;

int DecimalToRoman(int girdi) {
	
/*roman rakamlar�ndaki "tekrarlama*", "sonraki de�er daha b�y�kse fark�n� alma" ve "takip etme**" kurallar�ndan
ka��nmak i�in, de�er haritas�. 
tekrarlama*:I, X, C, ve M 3 kereden fazla tekrar edemez. V, L, ve D yaln�zca 1 kez kullan�labilir.
takip etme**:I'dan sonra yaln�zca V ve X; X'ten sonra yaln�zca L ve C; C'den sonra ise yaln�zca D ve M gelebilir. */

//*Referans 4, C++'ta map yap�s�(python dictionary benzeri):
//*https://stackoverflow.com/a/50950304
std::map<int, std::string> mymap;
mymap[0]="";
mymap[1]="I";
mymap[2]="II";
mymap[3]="III";
mymap[4]="IV";
mymap[5]="V";
mymap[6]="VI";
mymap[7]="VII";
mymap[8]="VIII";
mymap[9]="IX";
mymap[10]="X";
mymap[20]="XX";
mymap[30]="XXX";
mymap[40]="XL";
mymap[50]="L";
mymap[60]="LX";
mymap[70]="LXX";
mymap[80]="LXXX";
mymap[90]="XC";
mymap[100]="C";
mymap[200]="CC";
mymap[300]="CCC";
mymap[400]="CD";
mymap[500]="D";
mymap[600]="DC";
mymap[700]="DCC";
mymap[800]="DCCC";
mymap[900]="CM";
mymap[1000]="M";
mymap[2000]="MM";
mymap[3000]="MMM";

/*hesap mant���m alttaki BasamakSayisiBulma bulma fonksiyonuna dayan�yor.
if-else a�ac� �nce say�y�n�n ka� basamakl� oldu�una bak�yor.
daha sonra bu basamak say�s�na g�re, say�y�, basamak de�erleri ile birlikte par�al�yor.
�rne�in 1673 say�s�,
1000, 600, 70, ve 3 �eklinde parla�an�p, yukar�da verilen haritadaki de�erlerine g�re aralar�nda bo�luk olmadan yazd�r�l�nca,
istenilen roman say�s� ortaya ��k�yor.
*/
if (BasamakSayisiBulma(girdi) == 1) {
	girdi=birlerBasamagi;
	cout<<mymap[BirlerBasamagi(girdi)]<<endl;}
else if (BasamakSayisiBulma(girdi) == 2){
	cout << mymap[OnlarBasamagi(girdi)] << mymap[BirlerBasamagi(girdi)]<<endl;}
else if (BasamakSayisiBulma(girdi) == 3) {
	cout << mymap[YuzlerBasamagi(girdi)] << mymap[OnlarBasamagi(girdi)] << mymap[BirlerBasamagi(girdi)]<<endl;}
else if (BasamakSayisiBulma(girdi) == 4 && girdi<4000) {
	cout << mymap[BinlerBasamagi(girdi)] << mymap[YuzlerBasamagi(girdi)] << mymap[OnlarBasamagi(girdi)]
	<< mymap[BirlerBasamagi(girdi)] << endl;}
else {
	cout << "Hatali deger girdiniz!"<<endl;} 
}

//main'de arka arkaya girdi alabilmek i�in �evirme fonksiyonunu ve kar��lama c�mlesini
//tek fonksiyon alt�nda derledim
void IntegerCevirYazdir() {
int sayi;
int verilenSayi;
cout << "Cevirim yapmak istediginiz degeri giriniz (1-3999): "<<endl;
cin >> verilenSayi;
DecimalToRoman(verilenSayi);
}

//basamak hesaplama fonksiyonlar�
int BirlerBasamagi(int girdi) {
	birlerBasamagi=girdi%10;
		return birlerBasamagi; }

int OnlarBasamagi(int girdi) {
	onlarBasamagi = (girdi%100) - BirlerBasamagi(girdi);
		return onlarBasamagi; }
	
int YuzlerBasamagi(int girdi) {
	yuzlerBasamagi = (girdi%1000) - (BirlerBasamagi(girdi) + OnlarBasamagi(girdi));
		return yuzlerBasamagi; }
	
int BinlerBasamagi(int girdi) {
	binlerBasamagi = (girdi%10000) - (BirlerBasamagi(girdi) + OnlarBasamagi(girdi) +
 	YuzlerBasamagi(girdi));
		return binlerBasamagi; }

//kullan�c�ya iki i�lem aras�nda se�im fark� sunmak i�in b�yle bir yap� kurdum:
int main() {
	int soru;
	cout << "Roman sayilarini Arap sayilarina cevirmek icin 1, tersi icin 2 tuslayiniz." << endl;
	cin >> soru;
	while (true) {
		if (soru == 2) {
			IntegerCevirYazdir();
		}
		else if (soru == 1) {
			RomanCevirYazdir();
		}
		else {
			cout << "Hatali tuslama yaptiniz. Tekrar deneyiniz."<<endl;
			break;
		}
	}
  	return 0;
}
