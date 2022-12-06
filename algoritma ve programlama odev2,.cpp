#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Mahmut Esat Yýldýz

struct ogrenci {
	int no;
	char ad[50];
	int vize, final;
	struct ogrenci* next;
};
typedef struct ogrenci node;

node* ekle(node* head)
{

	node* ogr = (node*)malloc(sizeof(node));
	printf("ogrenci numarasi: ");
	scanf("%d",&ogr->no);
	printf("adi : ");
	scanf("%s",&ogr->ad);
	printf("vize notu : ");
	scanf("%d",&ogr->vize);
	printf("final notu : ");
	scanf("%d",&ogr->final);

	if (head == NULL)
	{
		head = ogr;
		head->next = NULL;
		printf("liste olusturuldu ilk ogrenci kaydi yapildi\n");
	}
	else
	{
		ogr->next = head;
		head = ogr;
		printf("ogrenci kaydi yapildi\n");
	}

	return head;
}
node* sil(node *head)
{

	bool sonuc = false;
	if (head == NULL)
	{
		printf("liste bos, silinecek ogrenci yok! \n");
		return head;
		sonuc = true;
	}
	else
	{
		int ogrNo;
		printf("ogrenci numarasi: ");
		scanf("%d",&ogrNo);
		if (head->no == ogrNo && head->next == NULL)
		{
			free(head);
			head = NULL;
			printf("listede kalan son ogrenci silindi\n");
			sonuc = true;
		}
		else if (head->no == ogrNo && head->next != NULL)
		{
			node* p = head->next;
			free(head);
			head = p;
			printf("%d numarali ogrenci silindi...\n", ogrNo);
			sonuc = true;
		}
		else
		{
			node* p, * q;
			p = head;
			q = p;
			while (p->next != NULL)
			{
				if (p->no == ogrNo)
				{
					q->next = p->next;
					free(p);
					printf("%d numarali ogrenci silindi\n", ogrNo);
					sonuc = true;
					break;
				}
				q = p;
				p = p->next;

			}
			if (p->no == ogrNo)
			{
				q->next = NULL;
				free(p);
				printf("%d numarali ogrenci silindi... \n", ogrNo);
				sonuc = true;
			}
		}
		if (!sonuc)
			printf("%d numarali ogrenci listede yok !", ogrNo);
	}

	return head;
}
node* yazdir(node* head)
{
	
	system("cls");
	if (head == NULL)
	{
		printf("liste bos!\n");
	}
	else
	{
		node* p;
		p = head;
		while (p != NULL)
		{
			printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
			printf("Numara : %d\nAd : %s\nVize notu : %d\nFinal notu : %d\n ", p->no, p->ad, p->vize, p->final);
			p = p->next;
		}
	}

	return head;
}
node* dosyayayaz(node* head)
{


	if (head == NULL)
	{

		printf("liste bos, dosyaya kaydedilecek veri yok\n");

	}
	else
	{
		FILE* dosya = fopen("C:\\Users\\CASPER\\Desktop\\çalýþmalarým\\baglilistecikis.txt", "w");
		node* p = head;
		while (p != NULL)
		{
			fprintf(dosya, "%d", p->no);
			fprintf(dosya, "\n");
			fprintf(dosya, p->ad);
			fprintf(dosya, "\n");
			fprintf(dosya, "%d", p->vize);
			fprintf(dosya, "\n");
			fprintf(dosya, "%d", p->final);
			fprintf(dosya, "\n");
			p = p->next;
		}
		printf("listedeki verileri 'baglilistecikis.txt' isimli dosyaya kaydedildi \n");

		fclose(dosya);

	}
	return head;
}
int main()
{
	int secim;
	node* head = NULL;
	while (1)
	{
		printf("\t----OGRENCI KAYIT UYGULAMASI ---- \n");
		printf("1--Ogrenci Ekle \n");
		printf("2--Ogrenci Sil \n");
		printf("3--Ogrenci Listesi \n");
		printf("4--Ogrenci listesini dosyaya aktar\n");
		printf("0--Cýkýs \n");
		printf("Seciminizi yapiniz... [0- 3]\n");
		scanf("%d",&secim);

		switch (secim)
		{
		case 1: head = ekle(head);
			break;
		case 2: head = sil(head);
			break;
		case 3: head = yazdir(head);
			break;
		case 4: head = dosyayayaz(head);
			break;
		case 0: exit(0);
			break;
		default: printf("hatali secim yaptiniz!\n");
		}
	}

	return 0;
}

