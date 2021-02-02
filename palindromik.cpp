#include "pch.h"
#include <iostream>
#include <string>
#include <fstream> //Dosyalama işlemleri için gerekli olan kütüphane
using namespace std;


bool Palindromik(string kelime_sayi) // recursive(öz yinelemeli) fonksiyon
{
	int baslangic = 0; // girilen kelimenin veya sayının başlangıç indeksi
	int bitis = kelime_sayi.length() - 1; // bitiş = girilen kelimenin veya sayının uzunluğunun bir eksiği çünkü 0 dan başlattık 

	for (baslangic = 0; baslangic < bitis; baslangic++) // girilen kelimenin veya sayının palindromik olup olmadığını bulmamızı kolaylaştıracak for döngüsü
	{
		if (kelime_sayi[baslangic] != kelime_sayi[bitis]) // eğer kelimede veya sayıda ters şekliyle olan karşılaştırmada herhangi bir uyumsuz ifade durumu varsa boolean değer false döner
		{
			return false;
		}
		bitis--; // eğer kelimede veya sayıda ters şekliyle olan karşılaştırmada herhangi bir uyumsuz ifade yoksa bitişi bir bir eksiltip başlangıcı bir bir arttırıyoruz
	}
}


int main() // ana fonksiyon
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter kullanabilmek için 
	string word_number; // kullanıcın klavyeden gireceği hem sayı hemde kelime olabilecek string tipinde değişken 
	char query; // işleme devam edip etmeyeceklerini sorgulamak için kullanacağımız char tipinde değişken
	ofstream dosya; // dosya oluşturmak için kullanıldı 
	dosya.open("palindrom.txt"); // palindrom.txt adında bir dosya açıldı

	while (true) // kullanıcıdan işleme devam etmek istemediği girdisini alana kadar devam edecek while(true) döngüsü
	{
		cout << "Denetlenecek veriyi giriniz: " << endl; // kullanıcıdan değer istendi
		cin >> word_number;
		if (Palindromik(word_number)) // girilen değer yukarıdaki recursive fonksiyonun içine yerleştirildi 
		{
			cout << "İfade palindromik ve dosyaya yazıldı. " << endl; // eğer recursive fonksiyon true olarak dönerse ifade palindromiktir çıktısı ekrana yazıldı
			dosya << word_number << endl; // ve bu palindromik değer dosyaya eklendi
		}
		else
		{
			cout << "İfade palindromik değil. " << endl; // eğer recursive fonksiyon false olarak dönerse ifade palindromik değildir çıktısı ekrana yazıldı ve bu değer dosyaya eklenmedi
		}
		cout << "Devam etmek istiyor musunuz? E/H " << endl; // kullanıcıya devam etmek isteyip istemediği soruldu
		cin >> query; // kullanıcıdan karakter almak için kullanılan fonksiyon olan getche() conio.h kütüphanesinde bulunur
		if (query == 'E' || query == 'e') // eğer klavyeden girilen cevap 'E' veya 'e' ise tekrar döngünün başına dönüldü
		{
			cout << endl;
			continue; // döngü devam etti
		}
		else // cevap 'E' veya 'e' değilse 
		{
			dosya.close(); // dosya kapatıldı
			break; // döngü kırıldı 
		}
	}
	return 0;
}