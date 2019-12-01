#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
// 2018280059(A Þubesi) Eyüb Salih Özdemir

/*programýn mantýðýný python üzerinde çalýþarak oturttum ve python'da tamamladým. c++'a çevirmeye çalýþtýðýmda,
ufak þeylerden beklemediðim þekilde zorluklarla karþýlaþtým. bu yüzden programýn yapýsý 
olduðundan çok daha karýþýk gözüküyor, bunun farkýndayým.

özellikle fonksiyon içinde fonksiyon tanýmlayamama kýsmý, derli toplu yapýyý çok bozdu.
ancak commentleri takip ederseniz, anlamak çok daha kolay olacaktýr.
sonraki programlarda daha temiz bir düzen kurmaya çalýþacaðým. */

//*Referans 1, sayý sistemleri arasý çevirme mantýðý:
//*https://www.ipracticemath.com/learn/numbersense/roman-numerals

//fonksiyon tanýmlamalarý
int BirlerBasamagi(int girdi); 
int OnlarBasamagi(int girdi);
int YuzlerBasamagi(int girdi);
int BinlerBasamagi(int girdi);

//sonucu büyük harfle vermek için gerekli fonksiyon
//*Referans 2, metni büyük harfe çevirme fonksiyonu:
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
	
//girilen roman sayýsýný decimal'a çevirmek için harflerine göre deðer döndürme fonksiyonu
//*Referans 3, "C++ forbids comparison between pointer and integer" hatasýnýn sebebi,
//*char ile iþlem yaparken single olmasý gerekirken, double quote kullanmak imiþ.
//*https://stackoverflow.com/a/2263700
int CalcValue(char x) {
	int c;
	if (x == 'I' || x == 'i' || x == 'Ý' || x == 'ý') {
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

//roman rakamýný, CalcValue'dan aldýðý deðerlere göre decimal olarak yazdýran fonksiyon
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
/*i<girdi.length ve i++ iþlemi son karakterde çakýþacaðý için doðru deðer hesaplamasýný "sonuc + CalcValue(girdi[-1])" þeklinde
son karakterin deðerini sonuca ekleyerek çözdüm
*/
}

int birlerBasamagi=0;
int onlarBasamagi=0;
int yuzlerBasamagi=0;
int binlerBasamagi=0;

int DecimalToRoman(int girdi) {
	
/*roman rakamlarýndaki "tekrarlama*", "sonraki deðer daha büyükse farkýný alma" ve "takip etme**" kurallarýndan
kaçýnmak için, deðer haritasý. 
tekrarlama*:I, X, C, ve M 3 kereden fazla tekrar edemez. V, L, ve D yalnýzca 1 kez kullanýlabilir.
takip etme**:I'dan sonra yalnýzca V ve X; X'ten sonra yalnýzca L ve C; C'den sonra ise yalnýzca D ve M gelebilir. */

//*Referans 4, C++'ta map yapýsý(python dictionary benzeri):
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

/*hesap mantýðým alttaki BasamakSayisiBulma bulma fonksiyonuna dayanýyor.
if-else aðacý önce sayýyýnýn kaç basamaklý olduðuna bakýyor.
daha sonra bu basamak sayýsýna göre, sayýyý, basamak deðerleri ile birlikte parçalýyor.
örneðin 1673 sayýsý,
1000, 600, 70, ve 3 þeklinde parlaçanýp, yukarýda verilen haritadaki deðerlerine göre aralarýnda boþluk olmadan yazdýrýlýnca,
istenilen roman sayýsý ortaya çýkýyor.
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

//main'de arka arkaya girdi alabilmek için çevirme fonksiyonunu ve karþýlama cümlesini
//tek fonksiyon altýnda derledim
void IntegerCevirYazdir() {
int sayi;
int verilenSayi;
cout << "Cevirim yapmak istediginiz degeri giriniz (1-3999): "<<endl;
cin >> verilenSayi;
DecimalToRoman(verilenSayi);
}

//basamak hesaplama fonksiyonlarý
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

//kullanýcýya iki iþlem arasýnda seçim farký sunmak için böyle bir yapý kurdum:
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
