#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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
	setlocale(LC_ALL, "Turkish");

	node* ogr = (node*)malloc(sizeof(node));
	printf("öðrenci numarasý: ");
	scanf("%d",&ogr->no);
	printf("adý : ");
	scanf("%s",&ogr->ad);
	printf("vize notu : ");
	scanf("%d",&ogr->vize);
	printf("final notu : ");
	scanf("%d",&ogr->final);

	if (head == NULL)
	{
		head = ogr;
		head->next = NULL;
		printf("liste oluþturuldu ilk öðrenci kaydý yapýldý\n");
	}
	else
	{
		ogr->next = head;
		head = ogr;
		printf("öðrenci kaydý yapýldý\n");
	}

	return head;
}
node* sil(node *head)
{
	setlocale(LC_ALL, "Turkish");
	bool sonuc = false;
	if (head == NULL)
	{
		printf("liste boþ, silinecek öðrenci yok! \n");
		return head;
		sonuc = true;
	}
	else
	{
		int ogrNo;
		printf("öðrenci numarasý: ");
		scanf("%d",&ogrNo);
		if (head->no == ogrNo && head->next == NULL)
		{
			free(head);
			head = NULL;
			printf("listede kalan son öðrenci silindi\n");
			sonuc = true;
		}
		else if (head->no == ogrNo && head->next != NULL)
		{
			node* p = head->next;
			free(head);
			head = p;
			printf("%d numaralý öðrenci silindi...\n", ogrNo);
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
					printf("%d numaralý öðrenci silindi\n", ogrNo);
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
				printf("%d nummaralý ögrenci silindi... \n", ogrNo);
				sonuc = true;
			}
		}
		if (!sonuc)
			printf("%d numaralý öðrenci listede yok !", ogrNo);
	}

	return head;
}
node* yazdir(node* head)
{
	setlocale(LC_ALL, "Turkish");
	system("cls");
	if (head == NULL)
	{
		printf("liste boþ!\n");
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

		printf("liste boþ, dosyaya kaydedilecek veri yok\n");

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
	setlocale(LC_ALL, "Turkish");
	int secim;
	node* head = NULL;
	while (1)
	{
		printf("\nÖÐRENCÝ KAYIT UYGULAMASI \n");
		printf("1--Öðrenci Ekle \n");
		printf("2--Öðrenci Sil \n");
		printf("3--Öðrenci Listesi \n");
		printf("4--Öðrenci listesini dosyaya aktar\n");
		printf("0--Çýkýþ \n");
		printf("Seçiminizi yapýnýz... [0- 3]\n");
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
		default: printf("hatalý seçim yaptýnýz!\n");
		}
	}

	return 0;
}
