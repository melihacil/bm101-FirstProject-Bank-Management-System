#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
void gecikme(int);
void menu();
void hesapekleme();
void hesaplar();
void hesapsilme(void);
void bilgiguncelle();
void yoneticigirisi();
void yoneticikrd();
void musterigirisi();
void musterihesapekleme();
void musterihesapgirisi();
void islem(int);
void musterikredi(int);
struct
{
char isim[10], soyisim[10],sifre[10];
int hesapno;
long kimlikno;
long telefonno;
long para;
}ekle,islm,krd;

int main()
{
    setlocale(LC_ALL, "Turkish");
    system("color 2");
    int secenek;
    printf("\n\n\t\t\t1.Musteri girisi\n\t\t\t2.Yonetici Girisi\n\t\t\t3.Cikis\n\t\t\t");
    scanf("%d", &secenek);
    switch (secenek)
    {
        case 1:
        system("cls");
		musterigirisi();
        break;
        case 2:
        yoneticigirisi();
        break;
        case 3:
        printf("Iyi gunler");
        break;
        default:
        printf("\t\t\tlutfen 1-3 arasi bir rakam giriniz\n");
        main();
    }

}
void gecikme(int a)
{
    int i,k,b;
    for (i = 1; i <= 32767; i++)
       for (k = 1; k <= a; k++)
       {
       	b=k;
	   }
}
void yoneticigirisi()
{
	setlocale(LC_ALL, "Turkish");
    system("color 2");
    int girissecim=1,acilis,i,x;
    char sifre1[20], sifre2[20],sifreatama[20];
    FILE *dosya;
	dosya = fopen("sifre.txt", "r");
	if ( dosya = fopen("sifre.txt", "r") != NULL) //dosya varsa çalýþýr
    {

        dosya = fopen("sifre.txt", "r");
        fscanf(dosya,"%s", &sifre1);
        
        do
        {
        printf("\n\n\t\t\tLutfen sifreyi giriniz = ");
        scanf("%s", &sifre2);
        if (strcmp(sifre1,sifre2) == 0)
        {
        printf("\t\t\tSifre Eslesti!\n");
        printf("\t\t\tYukleniyor");
    for(i=0;i<=5;i++)
        {
            gecikme(2000);
            printf(".");
        }
        printf("\n\t\t\t Yukleniyor");
    for(i=0;i<=5;i++)
        {
            gecikme(2000);
            printf(".");
        }
        system("cls");
        menu();
		girissecim = 0;
        }
    else
    {
        printf("\t\t\tYanlis sifre girdiniz!\n");
        printf("\t\t\tYeniden sifre girmek için 1'e\n\t\t\tCikis yapmak için herhangi bir tusa basiniz.");
        scanf("%d", &x);
        girissecim = x;
    }
    }while(girissecim == 1);
        fclose(dosya);
    }
    else  //dosya yoksa çalýþýr
    {

        dosya = fopen("sifre.txt", "w");
        printf("Yonetici hesabin sifresi bulunmamaktadir!\n Lutfen yonetici hesabi için bir sifre belirleyin!\nSifre = ");
        scanf("%s", &sifreatama);
        fprintf(dosya, "%s", sifreatama);
        printf("Sifre atamaniz tamamlandi!\n");
        for(i=0;i<=5;i++)
        {
            gecikme(2000);
            printf(".");
        }
        system("cls");
		menu();
        
	}
}
void menu() 
{
    int secim,i;
	system("color 1");
	printf("\t     ___       ______   __   __         .______        ___      .__   __.  __  ___      ___      \n");
	printf("\t    /   \\     /      | |  | |  |        |   _  \\      /   \\     |  \\ |  | |  |/  /     /   \\     \n");
	printf("\t   /  ^  \\   |  ,----' |  | |  |        |  |_)  |    /  ^  \\    |   \\|  | |  '  /     /  ^  \\    \n");
	printf("\t  /  /_\\  \\  |  |      |  | |  |        |   _  <    /  /_\\  \\   |  . `  | |    <     /  /_\\  \\   \n");
	printf("\t /  _____  \\ |  `----. |  | |  `----.   |  |_)  |  /  _____  \\  |  |\\   | |  .  \\   /  _____  \\  \n");
	printf("\t/__/     \\__\\ \\__||__| |__| |_______|   |______/  /__/     \\__\\ |__| \\__| |__|\\__\\ /__/     \\__\\ \n");
	printf("\t\t\t\t\t------------------\n");
	printf("\t\t\t\t\t 1. Hesap ekle\n\t\t\t\t\t 2. Hesap sil\n\t\t\t\t\t 3. Hesaplari goruntule \n\t\t\t\t\t 4. Hesap bilgilerini guncelle\n");
	printf("\t\t\t\t\t 5. Kredi Onay / Iptal\n\t\t\t\t\t 6.Cikis");
	printf("\n\t\t\t\t\t------------------\n\t\t\t\t\t");
	scanf("%d", &secim);
	switch (secim)
	{
    case 1:
       hesapekleme();
       break;
    case 2:
       hesapsilme();
       break;
    case 3:
        hesaplar();
        break;
    case 4:
        bilgiguncelle();
        break;
    case 5:
    	yoneticikrd();
    	break;
	case 6:
        system("cls");
        printf("Iyi Gunler!\n");
        for(i=0;i<=10;i++)
        {
            gecikme(1500);
            printf(".");
        }
        break;
    default:
        printf("lutfen 1-7 arasi bir rakam giriniz!");
        menu();
		}
}
void hesapekleme(void) //yonetici hesap ekleme
{
   int secenek=0,denemeno,x=0,a;
   FILE *hedef_dosya;
   
   hedef_dosya = fopen("bankabilgileri.txt", "a+");
   printf("Hesap numarasi giriniz\n");
   scanf("%d", &denemeno);
   while(fscanf(hedef_dosya,"%d %s %s %ld %ld %ld %s", &ekle.hesapno,&ekle.isim,&ekle.soyisim,&ekle.kimlikno,&ekle.telefonno,&ekle.para,&ekle.sifre) != EOF)
       {
        
           if (denemeno == ekle.hesapno) //hesap numarasý kullanýmda ise çalýþýr
           {
           	printf("Girdiginiz hesap numarasi kullanimda!\n");
           	x = 1;
		   }
		}
   if (x == 0 )
   {
      ekle.hesapno = denemeno;
   printf("Musteri ismini giriniz\n");
   scanf("%s", &ekle.isim);
   printf("Musterinin soyismini giriniz\n");
   scanf("%s", &ekle.soyisim);
   printf("Musterinin TC kimlik numarasini giriniz\n");
   scanf("%ld", &ekle.kimlikno);
   printf("Musterinin telefon numarasini giriniz\n");
   scanf("%ld", &ekle.telefonno);
   printf("Hesaba eklenecek parayi giriniz\n");
   scanf("%ld", &ekle.para);
   printf("Hesap için olusturulacak sifreyi giriniz\n");
   scanf("%s", &ekle.sifre);
   fprintf(hedef_dosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
   printf("Hesap eklenmistir.\n");
   fclose(hedef_dosya);
   printf("1.Menuye don\n2.Cikis");
   scanf("%d", &secenek);
   if (secenek == 1)
    menu();
   }
   else if (x == 1)
   {
       printf("1.Yeniden dene\n2.Cikis");
       scanf("%d", &a);
       if (a==1)
       hesapekleme();
   }

}
void hesaplar() //yonetici hesaplarýn gosterildiði menu
{
    int a=0,b=0;
	int secenek;
	FILE *goruntule;
    
    goruntule = fopen("bankabilgileri.txt","r");
    
    system("cls");
    printf("\n HesapNo Isim \tSoyisim\t TC \tTelNo \tPara Miktari \tSifre seklinde siralanmaktadir\n");

    while(fscanf(goruntule,"%d %s %s %ld %ld %ld %s", &ekle.hesapno,&ekle.isim,&ekle.soyisim,&ekle.kimlikno,&ekle.telefonno,&ekle.para,&ekle.sifre) != EOF)
       {
           printf("\n   %d \t%s \t%s \t%ld \t%ld \t%ld \t%s",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
           a++;
       }

    fclose(goruntule);
    if (a == 0)
        {   system("cls");
            printf("\nKayit Bulunamamistir!!\n");
		}
			
	do
    {
	printf("\n\n1.Menuye Don\n2.Cikis\n");
    scanf("%d",&secenek);
    if (secenek==1){
        menu();
        break;
    }
    else if (secenek == 2)
    {
	
        printf("iyi gunler!");
        break;
    }
	else
        printf("lutfen geçerli bir rakam giriniz");
    }while(b==0);
    
}
void hesapsilme(void) //yonetici hesap silme
{
    FILE *eski,*yeni;
    int a=0,secim,silinen;

    eski=fopen("bankabilgileri.txt","r");
    yeni=fopen("yenibilgi.txt","w");
    printf("Silmek istediginiz hesap numarasini giriniz\n");
    scanf("%d",&silinen);
    while (fscanf(eski,"%d %s %s %ld %ld %ld %s", &ekle.hesapno,&ekle.isim,&ekle.soyisim,&ekle.kimlikno,&ekle.telefonno,&ekle.para,&ekle.sifre)!= EOF) //yeni dosya oluþturup silinmek istenen hesap harici yazar
   {
        if(ekle.hesapno != silinen)
        {
            fprintf(yeni,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
        }
        else
            {
            a++;
            printf("Hesap silinmistir\n");
            }
   }
   fclose(yeni);
   fclose(eski);
   remove("bankabilgileri.txt");//dosyayý siler
   rename("yenibilgi.txt","bankabilgileri.txt");//yeni dosyanýn adýný deðiþtirir
   if(a==0)
        {
            printf("Kayit Bulunamadi!\n");
            printf("1. Yeniden deneyin \n2. Ana Menu \n3.Cikis\n");
            scanf("%d",&secim);
            switch (secim)
            {
            case 1:
                hesapsilme();
                break;
            case 2:
                menu();
                break;
            case 3:
                printf("iyi gunler!");
                break;
            default:
                printf("lutfen 1-3 arasý bir rakam giriniz!");
            }
        }
    else
        {
        printf("\n1.Menu\n2.Cikis\n");
        scanf("%d",&secim);
        system("cls");
        if (secim==1)
        {
            menu();
        }
        else
            printf("iyi gunler!");
        }
}
void bilgiguncelle()
{
	int secenek,test=0,scnk1,hno;
    FILE *eskidosya,*yenidosya;
    eskidosya = fopen("bankabilgileri.txt","r");
    yenidosya = fopen("deneme.txt","w");
    system("cls");
	printf("Degistirmek istediginiz hesap numarasini giriniz = ");
	scanf("%d", &hno);
    while (fscanf(eskidosya,"%d %s %s %ld %ld %ld %s", &ekle.hesapno,&ekle.isim,&ekle.soyisim,&ekle.kimlikno,&ekle.telefonno,&ekle.para,&ekle.sifre)!= EOF) //yeni dosya oluþturup silinmek istenen hesap harici yazar
   {
       
       if(ekle.hesapno != hno)
        {   
		   fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
	    }   
		
		else
		{
		    printf("\nHangi bilgiyi degistirmek istersiniz?\n1.Sifre\n2.Telefon Numarasi\n3.İslem yapmadan cik\n");
            scanf("%d",&scnk1);
            system("cls");
            if(scnk1 == 1)
            {
                printf("Yeni sifrenizi giriniz\n");
                scanf("%s",islm.sifre);
                fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,islm.sifre);
                system("cls");
                printf("Sifreniz degisti");
            }
            else if(scnk1 == 2)
            {
                printf("Yeni telefon numaranizi giriniz\n");
                scanf("%ld",&islm.telefonno);
                fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,islm.telefonno,ekle.para,ekle.sifre);
                system("cls");
                printf("Telefon numaraniz guncellenmistir");
            }

            
            else
                    fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
        }
    }
	fclose(yenidosya);
	fclose(eskidosya);
	remove("bankabilgileri.txt");
	rename("deneme.txt","bankabilgileri.txt");
	printf("\n\n\t\t\tIsleminiz tamamlandi!\n\n\t\t\t1.Menu\n\t\t\t2.Cikis\n");
	scanf("%d", &secenek);
	switch (secenek)
	{
		case 1:
			menu();
			break;
		default:
			printf("iyi gunler!");
	}
}
void yoneticikrd()
{
	int a=0,secnk,onyno=0;
	long eklenecekpara=0;
	FILE *goruntule,*eskikrd,*yenikrd,*eskidosya,*yenidosya;
    
    goruntule = fopen("kredi.txt","r");
    
    system("cls");
    printf("\n\tHesapNo Kredi Miktari\n");

    while(fscanf(goruntule,"%d %ld", &ekle.hesapno,&krd.para) != EOF)
       {
           printf("\n\t%d \t%ld",ekle.hesapno,krd.para);
           a++;
       }
	fclose(goruntule);
    if (a == 0)
        {   system("cls");
            printf("\nKredi Basvurusu Yapan Bulunamamistir!\n");
		    menu();
		}
	else
	{
		printf("\n\n\n\t1.Kredi Onaylama\n\t2.Kredi Iptal\n\t3.Menu\n\t4.Cikis\n\t");
		scanf("%d", &secnk);
		switch (secnk)
		{
			case 1:
				eskikrd = fopen("kredi.txt","r");
                yenikrd = fopen("krd.txt","w");
                eskidosya = fopen("bankabilgileri.txt","r");
                yenidosya = fopen("krdonayy.txt","w");
				printf("\nHesap Numarasini giriniz =");
				scanf("%d", &onyno);
				while (fscanf(eskikrd,"%d %ld", &ekle.hesapno,&krd.para)!= EOF)
                {
                    if (onyno == ekle.hesapno) //hesap numarasýna ait baþvuru varsa çalýþýr
                    {
           	            eklenecekpara = krd.para;
		            }  
		            else 
		            {
		            	fprintf(yenikrd,"%d %ld\n",ekle.hesapno,krd.para);
					}
		        }
				while(fscanf(eskidosya,"%d %s %s %ld %ld %ld %s", &ekle.hesapno,&ekle.isim,&ekle.soyisim,&ekle.kimlikno,&ekle.telefonno,&ekle.para,&ekle.sifre)!= EOF)
                {
                    if(ekle.hesapno != onyno)
                    {   
		                fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
	                }   
	                else
	                {
	                	ekle.para += eklenecekpara;
	                	printf("%ld", ekle.para);
						fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
					}
                }
                fclose(yenidosya);
	            fclose(eskidosya);
	            fclose(eskikrd);
	            fclose(yenikrd);
	            remove("kredi.txt");
				remove("bankabilgileri.txt");
	            rename("krdonayy.txt","bankabilgileri.txt");
                rename("krd.txt","kredi.txt");
                menu();
				break;
            case 2:
            	eskikrd = fopen("kredi.txt","r");
                yenikrd = fopen("krd.txt","w");
                printf("\nHesap Numarasini giriniz =");
				scanf("%d", &onyno);
				while (fscanf(eskikrd,"%d %ld", &ekle.hesapno,&krd.para)!= EOF)
                {
                    if (onyno == ekle.hesapno)
                    {
						   printf("%d . hesabin kredi basvurusu iptal edilmistir!\n",onyno);
		            }  
		            else 
		            {
		            	fprintf(yenikrd,"%d %ld\n",ekle.hesapno,krd.para);
					}
		        }
		        fclose(eskikrd);
	            fclose(yenikrd);
				remove("kredi.txt");
		        rename("krd.txt","kredi.txt");
		        
				menu();
		        break;
            case 3:
            	menu();
            	break;
            default:
            	printf("Iyi gunler!");
		}
	}
}
void musterigirisi() //muþteri menusu
{
    int musterisecenek;
    system("color 7");
	printf("\t     ___       ______   __   __         .______        ___      .__   __.  __  ___      ___      \n");
	printf("\t    /   \\     /      | |  | |  |        |   _  \\      /   \\     |  \\ |  | |  |/  /     /   \\     \n");
	printf("\t   /  ^  \\   |  ,----' |  | |  |        |  |_)  |    /  ^  \\    |   \\|  | |  '  /     /  ^  \\    \n");
	printf("\t  /  /_\\  \\  |  |      |  | |  |        |   _  <    /  /_\\  \\   |  . `  | |    <     /  /_\\  \\   \n");
	printf("\t /  _____  \\ |  `----. |  | |  `----.   |  |_)  |  /  _____  \\  |  |\\   | |  .  \\   /  _____  \\  \n");
	printf("\t/__/     \\__\\ \\__||__| |__| |_______|   |______/  /__/     \\__\\ |__| \\__| |__|\\__\\ /__/     \\__\\ \n");
	printf("\t\t\t\t---------Bankamiza Hosgeldiniz!---------\n");
	printf("\t\t\t\t\t 1. Yeni Hesap Oluþtur\n\t\t\t\t\t 2. Hesaba Giris Yap\n\t\t\t\t\t 3. Cikis");
	printf("\n\t\t\t\t\t ------------------------\n\t\t\t\t\t ");
	scanf("%d", &musterisecenek);
	switch (musterisecenek)
	{
    case 1:
        musterihesapekleme();
        system("cls");
        break;
    case 2:
        musterihesapgirisi();
        break;
    case 3:
        printf("Iyi Gunler!");
        break;
    default :
        printf("lutfen 1-3 arasi bir rakam giriniz!!!\n");
        musterigirisi();
	}
}
void musterihesapekleme() //Muþteri hesap ekleme bolumu
{
   int secenek=0,denemeno,x=0,a;
   FILE *hedef_dosya;

   hedef_dosya = fopen("bankabilgileri.txt", "a+");
   printf("Olusturmak istediginiz hesap için bir hesap numarasi giriniz\n");
   scanf("%d", &denemeno);
   while(fscanf(hedef_dosya,"%d %s %s %ld %ld %ld %s", &ekle.hesapno,&ekle.isim,&ekle.soyisim,&ekle.kimlikno,&ekle.telefonno,&ekle.para,&ekle.sifre) != EOF) //hesap numarasýnýn var olup olmadýðýný kontrol eder
       {

           if (denemeno == ekle.hesapno)
           {
           	  printf("Girdiginiz hesap numarasi kullanimda!\n");
           	  x = 1;
           }
       }
   if (x == 0){  
   ekle.hesapno = denemeno; //hesap numarasý bulunmadýðýnda çalýþýr 
   printf("Isminizi giriniz\n");
   scanf("%s", &ekle.isim);
   printf("Soyisminizi giriniz\n");
   scanf("%s", &ekle.soyisim);
   printf("TC kimlik numaranizi giriniz\n");
   scanf("%ld", &ekle.kimlikno);
   printf("Telefon numaranizi giriniz\n");
   scanf("%ld", &ekle.telefonno);
   printf("Hesabiniza için maksimum 10 karakterli bir sifre giriniz\n");
   scanf("%s", &ekle.sifre);
   printf("Hesabiniza yatirmak istediginiz miktari giriniz\n");
   scanf("%ld", &ekle.para);
   fprintf(hedef_dosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
   printf("Hesap eklenmistir.\n");
   fclose(hedef_dosya);
   printf("1.Menuye don\n2.Cikis\n");
   scanf("%d", &secenek);
   if (secenek == 1)
    musterigirisi();
   }
   else if (x == 1)
   {
       printf("1. Yeniden dene\n2.Cikis\n");
       scanf("%d", &a);
       if (a==1)
        musterihesapekleme();
   }
}
void musterihesapgirisi()
{
   char sifre1[10],denemesifre[10];
   int a=0,girisno,secenek,b=0,x;
   FILE *hedef_dosya;
   hedef_dosya = fopen("bankabilgileri.txt", "a+");
   printf("Hesap Numaranizi Giriniz\n");
   scanf("%d", &girisno);
   while(fscanf(hedef_dosya,"%d %s %s %ld %ld %ld %s", &ekle.hesapno,&ekle.isim,&ekle.soyisim,&ekle.kimlikno,&ekle.telefonno,&ekle.para,&ekle.sifre) != EOF)
    {
        if (girisno == ekle.hesapno)
        {
            a = 1;
            break;
        }
    }
    if (a==1)
    {
        printf("Lutfen sifrenizi giriniz = ");
        scanf("%s", &denemesifre);

        if (strcmp(denemesifre,ekle.sifre))
        {
        printf("Yanlis sifre Girdiniz!\n");
        do {
        printf("1.Yeniden dene\n2.Menu\n3.Cikis\n");
        scanf("%d", &secenek);
        switch (secenek)
        {
        case 1:
            system("cls");
            musterihesapgirisi();
            b=1; // deðiþebilir
            break;
        case 2:
            system("cls");
            musterigirisi();
            b=1;
            break;
        case 3:
			printf("iyi gunler!");
            b=1;
            break;
        default:
            printf("lutfen 1-3 arasi bir rakam giriniz!");
        }
        }while(b==0);
        }
        else
        {
            fclose(hedef_dosya);
			printf("Giris Basarili!");
			system("cls");
            islem(girisno);
            printf("\n1.Menu\n2.Çikis\n");
            scanf("%d", &x);
            if (x==1)
            {
               system("cls");
               musterigirisi();
            }
        }


    }

    else if (a == 0)
    {
        printf("Girdiginiz hesap bulunamamistir\n");
        do {
        printf("1.Yeniden dene\n2.Menu\n3.Cikis\n");
        scanf("%d", &secenek);
        switch (secenek)
        {
        case 1:
            fclose(hedef_dosya);
			system("cls");
            musterihesapgirisi();
            b=1; 
            break;
        case 2:
            fclose(hedef_dosya);
			system("cls");
            musterigirisi();
            b=1;
            break;
        case 3:
            fclose(hedef_dosya);
			printf("iyi gunler!");
            b=1;
            break;
        default:
            printf("lutfen 1-3 arasi bir rakam giriniz!");
        }
        }while(b==0);
    }
}
void islem(int numara)
{
    int secenek,test=0,scnk1;
    FILE *eskidosya,*yenidosya;
    eskidosya = fopen("bankabilgileri.txt","r");
    yenidosya = fopen("deneme.txt","w");
    while (fscanf(eskidosya,"%d %s %s %ld %ld %ld %s", &ekle.hesapno,&ekle.isim,&ekle.soyisim,&ekle.kimlikno,&ekle.telefonno,&ekle.para,&ekle.sifre)!= EOF) //yeni dosya oluþturup silinmek istenen hesap harici yazar
   {
       
       if(ekle.hesapno != numara)
        {   
		   fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
	    }   
		
		else
		{
            printf("\n\n\t\t\tYapmak istediginiz iþlemi seçiniz");
			printf("\n\t\t\t1.Para Yatir\n\t\t\t2.Para Çek\n\t\t\t3.Hesap Bilgilerini Degiþtir\n\t\t\t4.Kredi Basvurusunda bulun\n\t\t\t5.Cikis\n\t\t\t");
			scanf("%d",&secenek);
            if (secenek==1)
            {
                printf("Hesabiniza yatirmak istediginiz miktari giriniz = ");
                scanf("%ld",&islm.para);
                ekle.para+=islm.para;
                fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
                printf("\nBasariyla hesabiniza yatti\n");
            }
            else if (secenek == 2)
            {
                printf("Hesabinizdan çekmek istediðiniz miktari giriniz = ");
                scanf("%ld",&islm.para);
                ekle.para-=islm.para;
                fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
                printf("\nHesabinizdan para çekildi!\n");
            }
            else if (secenek == 3)
            {
                printf("\nHangi bilgiyi degistirmek istersiniz?\n1.sifre\n2.Telefon Numarasi\n3.islem yapmadan çýk\n");
                scanf("%d",&scnk1);
                system("cls");
                if(scnk1 == 1)
                {
                    printf("Yeni sifenizi giriniz\n");
                    scanf("%s",islm.sifre);
                    fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,islm.sifre);
                    system("cls");
                    printf("sifreniz degisti");
                }
                else if(scnk1 == 2)
                {
                    printf("Yeni telefon numarainizi giriniz\n");
                    scanf("%ld",&islm.telefonno);
                    fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,islm.telefonno,ekle.para,ekle.sifre);
                    system("cls");
                    printf("Telefon numaraniz guncellenmistir");
                }

            }
            else if (secenek == 4)
            {
                fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
				musterikredi(numara);
            }
            else
            {
                fprintf(yenidosya,"%d %s %s %ld %ld %ld %s\n",ekle.hesapno,ekle.isim,ekle.soyisim,ekle.kimlikno,ekle.telefonno,ekle.para,ekle.sifre);
            }    
            
                
            
		}
	}
   fclose(yenidosya);
   fclose(eskidosya);
   remove("bankabilgileri.txt");           //eski dosyayý siler
   rename("deneme.txt","bankabilgileri.txt");// yeni dosyaya eski dosyanýn ismini verir
}
void musterikredi(int no)
{
    FILE *dsya;
    dsya = fopen("kredi.txt","a+");
    int a=0,x=0;
    long b;
    printf("\t\t\tHesap no= %d\n", no);
    do
    {
    printf("\t\t\tAlmak istediginiz kredi miktarini giriniz\n\t\t\t");
    scanf("%ld", &b);
    if ( b<=0)
    printf("Lutfen pozitif bir deger giriniz\n");
    }while( b <= 0);
    while (fscanf(dsya,"%d %ld", &ekle.hesapno,&krd.para)!= EOF)
    {
       if (no == ekle.hesapno) //hesap numarasýna ait baþvuru varsa çalýþýr
           {
           	printf("Girdiginiz hesap numarasýna ait kredi bulunmakta!\n");
           	x = 1;
		   }  
    }
    if (x==0)
    {
		fprintf(dsya,"%d %ld\n",no,b);
        printf("Kredi Basvurunuz alinmistir\nKrediniz onaylanirsa krediniz hesabiniza aktarilacaktir!\n");
    }
    fclose(dsya);
    
}

