/*
# Name : Khai TK
# Age  : 1999
# Date : 30.05.2020
*/

#include<stdio.h>
#include<string.h>
#define m 2020

struct SinhVien{
	char masv[15];
	char hoten[30];
	int namsinh;
	char khoa[10];
	SinhVien *next;
};

SinhVien *phead;

void Nhap(SinhVien *sv){
	SinhVien *pnode, *ptail;
	
	char masv[15];
	char hoten[30];
	int namsinh;
	char khoa[10];
	
	char ktra;
	do{
		pnode = new SinhVien;
		fflush(stdin);
		printf("Nhap ma sv : ");
		gets(masv);
		printf("Nhap ho ten : ");
		gets(hoten);
		fflush(stdin);
		printf("Nhap nam sinh : ");
		scanf("%d", &namsinh);
		fflush(stdin);
		printf("Nhap ten khoa : ");
		gets(khoa);
		
		strcpy(pnode->masv, masv);
		strcpy(pnode->hoten, hoten);
		pnode->namsinh = namsinh;
		strcpy(pnode->khoa, khoa);
		pnode->next = NULL;
		
		if(phead == NULL){
			phead = pnode;
			ptail = pnode;
		}else{
			ptail->next = pnode;
			ptail = pnode;
		}
		
		fflush(stdin);
		printf("Nhan c de tiep tuc ? ");
		scanf("%s", &ktra);
	}while(ktra == 'c');
}

void Xuat(SinhVien *sv){
	SinhVien *pnode = sv;
	int i = 0; 
	while(pnode != NULL){
		printf("%d     %s      %s     %d      %s\n", 
		i++, pnode->masv, pnode->hoten, (m - pnode->namsinh), pnode->khoa);
		pnode = pnode->next;
	}
}

SinhVien *Locate(SinhVien *sv, int vitri){
	SinhVien *pnode = sv;
	int count = 1;
	while((pnode != NULL) && (count < vitri)){
		count++;
		pnode = pnode->next;
	}
	return pnode;
}

void Chen(SinhVien *sv,char masv[15], char hoten[30], int namsinh, char khoa[10], int vitri){
	SinhVien *temp1 = new SinhVien;
	SinhVien *temp2 = new SinhVien;
	
	strcpy(temp1->masv, masv);
	strcpy(temp1->hoten, hoten);
	temp1->namsinh = namsinh;
	strcpy(temp1->khoa, khoa);
	
	if(vitri == 0){
		temp1->next = phead;
		phead = temp1;
	}else{
		temp2 = Locate(sv,vitri -1);
		if(temp2 == NULL){
			printf("Vi tri khong hop le !");
		}else{
			temp1->next = temp2->next;
			temp2->next = temp1;
		}
	}
}

void Xoa(SinhVien *sv, int vitri){
	SinhVien *temp1 = new SinhVien;
	SinhVien *temp2 = new SinhVien;
	
	if(vitri == 0){
		temp1 = phead;
		phead = temp1->next;
		delete(temp1);
	}else{
		temp2 = Locate(sv, vitri-1);
		if(temp2 == NULL){
			printf("vi tri khong hop le !");
		}else{
			temp1 = temp2->next;
			temp2->next = temp1->next;
			delete(temp1);
		}
	}
}
int main(){
	phead = NULL;
	Nhap(phead);
	printf("===			Thong Tin				 ===\n");
	printf("STT     MASV      TEN     TUOI      KHOA\n");
	Xuat(phead);
	
	int vitri;
	char masv[15];
	char hoten[30];
	int namsinh;
	char khoa[10];
	
	fflush(stdin);
	printf("Nhap vi tri muon chen : ");
	scanf("%d", &vitri);
	fflush(stdin);
	printf("Nhap ma sv : ");
	gets(masv);
	printf("Nhap ho ten : ");
	gets(hoten);
	fflush(stdin);
	printf("Nhap nam sinh : ");
	scanf("%d", &namsinh);
	fflush(stdin);
	printf("Nhap ten khoa : ");
	gets(khoa);
	
	Chen(phead,masv,hoten,namsinh,khoa,vitri);
	printf("===		Thong Tin Sau Khi Chen	 ===\n");
	printf("STT     MASV      TEN     TUOI      KHOA\n");
	Xuat(phead);
	
	int vitri1;
	printf("Nhap vi tri can xoa : ");
	scanf("%d", &vitri1);
	Xoa(phead, vitri1);
	printf("===		Thong Tin Sau Khi Xoa	 ===\n");
	printf("STT     MASV      TEN     TUOI      KHOA\n");
	Xuat(phead);
	
	
}
