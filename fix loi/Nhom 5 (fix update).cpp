#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAXDS = 100;
struct Tuyen
{
	string Matuyen;
	string Tentuyen;
	string Diemdau;
	string Diemcuoi;
	string Culy;
};
typedef struct Tuyen TUYEN;

struct Danh_sach
{
	int Tongtuyen;
	TUYEN DST[MAXDS];
};
typedef struct Danh_sach DSTUYEN;


void HoanVi(TUYEN &, TUYEN &);
void ThemViTriBatKy(DSTUYEN &, int);

void NhapTuyen(TUYEN &, DSTUYEN);
void XuatTuyen(TUYEN);
void NhapDS_Tuyen(DSTUYEN &);
void XuatDS_Tuyen(DSTUYEN);
int ghi(DSTUYEN &);
int doc(DSTUYEN &);
void menu();

void main()
{
	menu();
	std::system("pause");
}


void NhapTuyen(TUYEN &tuyen, DSTUYEN ds)
{

	cout << "\nNhap ma: ";
	fflush(stdin);
	getline(cin, tuyen.Matuyen);
	cout << "\nNhap Ten Tuyen: ";
	getline(cin, tuyen.Tentuyen);
	cout << "\nNhap Diem Dau: ";
	getline(cin, tuyen.Diemdau);
	cout << "\nNhap Diem Cuoi: ";
	getline(cin, tuyen.Diemcuoi);
	cout << "\nNhap Cu Ly: ";
	getline(cin, tuyen.Culy);
}

void XuatTuyen(TUYEN tuyen)
{
	cout << "\n===========////===========";
	cout << "\nMa Tuyen: " << tuyen.Matuyen;
	cout << "\nTen Tuyen: " << tuyen.Tentuyen;
	cout << "\nDiem Dau: " << tuyen.Diemdau;
	cout << "\nDiem Cuoi: " << tuyen.Diemcuoi;
	cout << "\nCu Ly: " << tuyen.Culy;
	cout << "\n===========////===========";
}
void NhapDS_Tuyen(DSTUYEN &ds)
{
	do
	{
		cout << "\nNhap Tong so tuyen: ";
		cin >> ds.Tongtuyen;
		if (ds.Tongtuyen < 0 || ds.Tongtuyen > 100)
		{
			cout << "\n======================";
			cout << "\nNhap Sai Roi . Phai nhap trong khoang 0->" << MAXDS << " . Moi nhap lai !!";
			cout << "\n======================";
		}
		else{
			for (int i = 0; i < ds.Tongtuyen; i++)
			{
				cout << "\n======================";
				cout << "\nNhap tuyen thu " << i + 1;
				NhapTuyen(ds.DST[i], ds);
				cout << "\n======================";
			}
		}

	} while (ds.Tongtuyen < 0 || ds.Tongtuyen > 100);

}
void XuatDS_Tuyen(DSTUYEN ds)
{
	for (int i = 0; i < ds.Tongtuyen; i++)
	{
		cout << "\nThong tin tuyen thu" << i + 1;
		XuatTuyen(ds.DST[i]);
		cout << endl;
	}
}

void HoanVi(TUYEN &s1, TUYEN &s2)
{
	TUYEN s3 = s1;
	s1 = s2;
	s2 = s3;
}
void ThemDau(DSTUYEN &ds)
{
	TUYEN s;
	s = ds.DST[0];
	cout << "\nNhap thong tin tuyen muon them: ";
	NhapTuyen(ds.DST[0], ds);
	ds.Tongtuyen += 1;
	for (int i = 1; i < ds.Tongtuyen; i++)
	{
		HoanVi(ds.DST[i], s);
	}
}
void ThemGiua(DSTUYEN &ds, int vitri)
{
	TUYEN s;
	for (int i = 0; i < ds.Tongtuyen; i++)
	{
		if (i == vitri)
		{
			s = ds.DST[i];
			cout << "\nNhap thong tin tuyen muon them: ";
			NhapTuyen(ds.DST[i], ds);
			ds.Tongtuyen += 1;
			for (int i = vitri + 1; i < ds.Tongtuyen; i++)
			{
				HoanVi(ds.DST[i], s);
			}
		}
	}
}
void ThemCuoi(DSTUYEN &ds)
{
	ds.Tongtuyen += 1;
	cout << "\nNhap thong tin tuyen muon them: ";
	NhapTuyen(ds.DST[ds.Tongtuyen - 1], ds);
}
void ThemViTriBatKy(DSTUYEN &ds, int vitri)
{
	if (vitri == 0)
	{
		ThemDau(ds);
		return;
	}
	if (vitri == ds.Tongtuyen - 1)
	{
		ThemCuoi(ds);
		return;
	}
	if (vitri != 0 && vitri != ds.Tongtuyen)
	{
		ThemGiua(ds, vitri);
		return;
	}
}

void TK_Ma(DSTUYEN ds, string ma)
{
	for (int i = 0; i < ds.Tongtuyen; i++)
	{
		if (ds.DST[i].Matuyen == ma)
		{
			cout << "\nThong tin tuyen xe buyt voi ma can tim kiem la: " << ma;
			cout << "\n=======================================";
			XuatTuyen(ds.DST[i]);
			cout << "=========================================";
			return;
		}
	}
	cout << "\n**************Thong Bao***************";
	cout << "\nMa ban nhap khong co trong danh sach.";
	cout << "\n**************************************\n";

}
void TK_Ten(DSTUYEN ds, string ten)
{
	for (int i = 0; i < ds.Tongtuyen; i++)
	{
		if (ds.DST[i].Tentuyen == ten)
		{
			XuatTuyen(ds.DST[i]);

		}
	}
	cout << "\n**************Thong Bao***************";
	cout << "\nTen ban nhap khong co trong danh sach.";
	cout << "\n**************************************\n";

}
void TimKiem(DSTUYEN ds)
{
	int chon;
	string ma, ten;
	do
	{
		cout << "\n----------Menu tim kiem------------";
		cout << "\nChon 0: De thoat khoi chuong trinh.";
		cout << "\nChon 1: De tim theo ma.";
		cout << "\nChon 2: De tim theo ten.";
		cout << "\n-----------------------------------\n";
	chonlai:
		cout << "\nBan hay nhap 1 lua chon: ";
		cin >> chon;
		if (cin.fail())
		{
			cout << "\n**************Nhac Nho***************";
			cout << "\nNhap sai kieu du lieu. Xin nhap lai !";
			cout << "\n*************************************\n";
			goto chonlai;
		}
		 else if (chon < 0 || chon > 3)
		{

			cout << "\n****************Nhac Nho*****************";
			cout << "\nBan chi co 4 lua cho 0->3. Xin chon lai !";
			cout << "\n*****************************************\n";

			goto chonlai;
		}
		else
		{
			switch (chon)
			{
			case 1:
				system("cls");
				cout << "\n======================================";
				cout << "\nNhap ma tuyen xe buyt ma ban muon tim kiem: ";
				fflush(stdin);
				getline(cin, ma);
				cout << "\n======================================";
				TK_Ma(ds, ma);
				break;
			case 2:
				system("cls");
				cout << "\n=======================================";
				cout << "\nNhap ten tuyen xe buyt ma ban muon tim kiem: ";
				fflush(stdin);
				getline(cin, ten);
				cout << "\n=======================================";
				cout << "\nDanh sach cac tuyen xe buyt voi ten can tim kiem la: " << ten;
				cout << "\n=======================================";
				TK_Ten(ds, ten);
				cout << "=========================================";

				break;
			default:
				cout << "\n****************Nhac Nho*****************";
				cout << "\nBan da thoat khoi Menu tim kiem.";
				cout << "\n*****************************************\n";
			}
		}
	} while (chon != 0);
}
void Xoa1TuyenXe_KhiBietMaTen(DSTUYEN &ds, string maten)
{
	if (ds.Tongtuyen == 1)
	{
		ds.Tongtuyen = 0;
		cout << "\n*******Thong Bao*******";
		cout << "\nTuyen xe buyt cua ban rong.";
		cout << "\n***********************\n";

	}
	Tuyen s;
	for (int i = 0; i < ds.Tongtuyen; i++)
	{
		if (ds.DST[i].Matuyen == maten)
		{
			s = ds.DST[i];
			ds.DST[i] = ds.DST[i + 1];
			for (int j = i + 1; j < ds.Tongtuyen; j++)
			{
				HoanVi(ds.DST[j], ds.DST[j + 1]);
			}
			ds.Tongtuyen -= 1;
			cout << "\n*******Thong Bao*******";
			cout << "\nThong tin tuyen xe buyt ban muon xoa.";
			XuatTuyen(s);
			cout << "\nBan da xoa thanh cong.";
			cout << "\n***********************\n";
			return;
		}
		else if (ds.DST[i].Tentuyen == maten)
		{
			s = ds.DST[i];
			ds.DST[i] = ds.DST[i + 1];
			for (int j = i + 1; j < ds.Tongtuyen; j++)
			{
				HoanVi(ds.DST[j], ds.DST[j + 1]);
			}
			ds.Tongtuyen -= 1;
			cout << "\n*******Thong Bao*******";
			cout << "\nThong tin tuyen xe ma ban muon xoa.";
			XuatTuyen(s);
			cout << "\nBan da xoa thanh cong.";
			cout << "\n***********************\n";
			return;
		}
		else
		{
			cout << "\n Khong tim thay tuyen xe buyt ma ban muon Xoa!Vui long kiem tra lai!";
		}
	}
	cout << "\n*****************************Thong Bao***************************";
	cout << "\nMa tuyen : " << maten << " ma hoac ten ban vua nhap khong co trong danh sach.";
	cout << "\n****************************************************************\n";

}
void Shift(DSTUYEN &ds, int left, int right, int tieuchi) 
{
	if (tieuchi == 1) 
	{
		int i, j;
		string ma;
		i = left; j = 2 * i + 1; 
		ma = ds.DST[i].Matuyen; 
		while (j <= right) 
		{
			if (j < right && ds.DST[j].Matuyen < ds.DST[j + 1].Matuyen) 
				
				j = j + 1; 
			if (ds.DST[j].Matuyen <= ma) 
				
				break;
			else 
			{
				HoanVi(ds.DST[i], ds.DST[j]); 
				i = j; 
				j = 2 * i + 1; 
				
			}
		}
	}
	if (tieuchi == 2) 
	{
		int i, j;
		string ten;
		i = left; j = 2 * i + 1;
		ten = ds.DST[i].Tentuyen;
		while (j <= right)
		{
			if (j < right && ds.DST[j].Tentuyen < ds.DST[j + 1].Tentuyen)
			{
				j = j + 1;
			}
			if (ds.DST[j].Tentuyen <= ten)
			{
				break;
			}
			else
			{
				HoanVi(ds.DST[i], ds.DST[j]);
				i = j;
				j = 2 * i + 1;
			}
		}
	}
	if (tieuchi == 3) 
	{
		int i, j;
		string ma;
		i = left; j = 2 * i + 1;
		ma = ds.DST[i].Matuyen;
		while (j <= right)
		{
			if (j < right && ds.DST[j].Matuyen < ds.DST[j + 1].Matuyen)
			{
				j = j + 1;
			}
			if (ds.DST[j].Matuyen <= ma)
			{
				break;
			}
			else
			{
				HoanVi(ds.DST[i], ds.DST[j]);
				i = j;
				j = 2 * i + 1;
			}
		}
	}
}

void CreateHeap(DSTUYEN &ds, int tieuchi) 
{								
	int l = 0;
	l = (ds.Tongtuyen - 1) / 2;  
	while (l >= 0) 
	{
		Shift(ds, l, ds.Tongtuyen - 1, tieuchi);  
		l = l - 1; 
	}
}
void HeapSort(DSTUYEN &ds, int tieuchi)
{
	int r;
	CreateHeap(ds, tieuchi); 
	r = ds.Tongtuyen - 1; 
	while (r > 0) 
	{
		HoanVi(ds.DST[0], ds.DST[r]); 
		r = r - 1; 
		Shift(ds, 0, r, tieuchi); 

	}
}

void SX_TheoTieuChi(DSTUYEN &ds)
{
	int chon;
	string Cchon;

	do
	{
		cout << "\n----------Menu Sap Xep-------------";
		cout << "\nChon 0: De thoat khoi chuong trinh.";
		cout << "\nChon 1: De sap xep theo ma.";
		cout << "\nChon 2: De sap xep theo ten.";
		cout << "\nChon 3: De sap xep theo cu ly.";
		cout << "\n-----------------------------------\n";
	chonlai:

		cout << "\nBan hay nhap 1 lua chon: ";
		fflush(stdin);
		getline(cin, Cchon);
		chon = atof((char *)Cchon.c_str());
		if (chon < 0 || chon > 3)
		{
			system("cls");
			cout << "\n****************Nhac Nho*****************";
			cout << "\nBan chi co 4 lua cho 0->3. Xin chon lai !";
			cout << "\n*****************************************";
			goto chonlai;
		}
		switch (chon)
		{
		case 1:
			system("cls");
			HeapSort(ds, 1);
			cout << "\n****************Thong Bao*******************";
			cout << "\nBan da sap xep danh sach theo ma thanh cong.";
			cout << "\n********************************************\n";
			break;
		case 2:
			system("cls");
			HeapSort(ds, 2);
			cout << "\n****************Thong Bao*******************";
			cout << "\nBan da sap xep danh sach theo ten thanh cong.";
			cout << "\n********************************************\n";
			break;
		case 3:
			system("cls");
			HeapSort(ds, 3);
			cout << "\n****************Thong Bao*************************";
			cout << "\nBan da sap xep danh sach theo cu ly thanh cong.";
			cout << "\n**************************************************\n";
			break;
		default:
			cout << "\n****************Nhac Nho****************";
			cout << "\nBan da thoat khoi Menu sap xep.";
			cout << "\n****************************************\n";
		}
	} while (chon != 0 && cin.fail());
}
int ghi(DSTUYEN &ds)
{
	FILE *f;
	f=fopen("text.txt","wb");
	if(f==NULL)
		return 0;
	fwrite(&ds.Tongtuyen,sizeof(int),1,f);
	fwrite(&ds.DST,sizeof(Danh_sach),ds.Tongtuyen,f);
	fclose(f);
	return 1;
}
int doc(DSTUYEN &ds)
{
	FILE *f;
	f=fopen("text.txt","rb");
	if(f==NULL)
		return 0;
	fread(&ds.Tongtuyen,sizeof(int),1,f);
	fread(&ds.DST,sizeof(Danh_sach),ds.Tongtuyen,f);
	fclose(f);
	return 1;
}
void Bangchon()
{
	cout << "\n----------Menu----------";
	cout << "\nChon 0: De thoat chuong trinh";
	cout << "\nChon 1: Nhap danh sach cua mot tuyen";
	cout << "\nChon 2: Xuat danh sach cua mot tuyen";
	cout << "\nChon 3: Them tuyen vao vi tri bat ky trong danh sach";
	cout << "\nChon 4: Tim kiem tuyen xe buyt theo ma hoac ten";
	cout << "\nChon 5: xoa tuyen xe buyt khi biet ma hoac ten tuyen xe:";
	cout << "\nChon 6: sap xep theo 1 tieu chi nao do: ma, ten, cu ly: ";
	cout << "\nChon 7: Ghi File";
	cout << "\nChon 8: Doc File";

}
void menu()
{
	TUYEN tuyen;
	Danh_sach ds;
	int chonmenu;
	int vitrithem;
	string tuyenmuonxoa;
	do{
	chonlai:
		Bangchon();
		cout << "\n--------------------";
		cout << "\nBan hay nhap 1 lua chon: ";
		fflush(stdin);
		cin >> chonmenu;
		if (chonmenu < 0 || chonmenu > 9)
		{
			std::system("cls");
			cout << "\n************Nhac Nho************";
			cout << "\nBan chi duoc chon tu 0->8. Xin chon lai !";
			cout << "\n*****************************************";
			goto chonlai;
		}

		switch (chonmenu)
		{
		case 1:
			std::system("cls");
			NhapDS_Tuyen(ds);
			break;
		case 2:
			std::system("cls");
			if (ds.Tongtuyen < 0)
			{
				cout << "\n***********Nhac Nho**************";
				cout << "\nDanh sach cua ban dang rong.";
				cout << "\nBan hay chon 1 de nhap tuyen vao.";
				cout << "\n*********************************";

			}
			else
			{
				cout << "\nDanh sach cac tuyen trong danh sach cua ban.";
				cout << "\n==================================================";
				XuatDS_Tuyen(ds);
			}
			break;
		case 3:
			std::system("cls");
			if (ds.Tongtuyen < 0)
			{
				cout << "\n***********Nhac Nho**************";
				cout << "\nDanh sach cua ban dang rong.";
				cout << "\nBan hay chon 1 de nhap danh sach.";
				cout << "\n*********************************";
				break;
			}
			else
			{
				cout << "\n*****************Goi Y***********************";
				cout << "\nTong phan tu trong danh sach la: " << ds.Tongtuyen << ".";
				cout << "\nTuc la ban hay chon 1 vi tri tu 0->" << ds.Tongtuyen - 1 << ".";
				do{
					cout << "\n================================";
					cout << "\nNhap vao vi tri ban muon them: ";
					cin >> vitrithem;

					cout << "\n=================================";
					if (vitrithem < 0 || vitrithem >= ds.Tongtuyen)
					{
						cout << "\n**********************Nhac Nho*************************";
						cout << "\nTong phan tu trong danh sach cua ban la: " << ds.Tongtuyen << ".";
						cout << "\nNen mang cua ban chay tu vi tri tu 0->" << ds.Tongtuyen - 1 << ".";
						cout << "\nVi vay ban hay chon 1 vi tri phu hop. Xin chon lai !.";
						cout << "\n*******************************************************";
					}
				} while (vitrithem < 0 || vitrithem >= ds.Tongtuyen);
				ThemViTriBatKy(ds, vitrithem);
				break;
		case 4:
			system("cls");
			if (ds.Tongtuyen < 0)
			{
				cout << "\n***********Nhac Nho**************";
				cout << "\nDanh sach cua ban dang rong.";
				cout << "\nBan hay chon 1 de nhap tuyen di.";
				cout << "\n*********************************";
				break;
			}
			else
			{
				cout << "\nChuc nang tim kiem!" << endl;
				TimKiem(ds)
					;
				break;
			}
		case 5:
			if (ds.Tongtuyen < 0)
			{
				cout << "\n***********Nhac Nho**************";
				cout << "\nDanh sach cua ban dang rong.";
				cout << "\nBan hay chon 1 de nhap danh sach.";
				cout << "\n*********************************";
				break;
			}
			else
			{
				system("cls");
				cout << "\n*****************Goi Y*********************";
				cout << "\nTong phan tu trong danh sach cua ban la: " << ds.Tongtuyen << ".";
				cout << "\n*******************************************";

				cout << "\n=================================";
				cout << "\nNhap vao ma hoac ten xe buyt ma ban muon xoa: ";
				fflush(stdin);
				getline(cin, tuyenmuonxoa);
				Xoa1TuyenXe_KhiBietMaTen(ds, tuyenmuonxoa);
				cout << "\n=================================";
				break;
			}
		case 6:
			system("cls");
			if (ds.Tongtuyen < 0)
			{
				cout << "\n***********Nhac Nho**************";
				cout << "\nDanh sach cua ban dang rong.";
				cout << "\nBan hay chon 1 de nhap danh sach.";
				cout << "\n**********************************";
				break;
			}
			else
			{
				SX_TheoTieuChi(ds);
				break;
			}

		case 7:
			std::system("cls");
			ghi(ds);
			cout <<"\nDanh sach da duoc luu!!";
			break;			
		case 8:
			std::system("cls");
			doc(ds);
			cout<<"\nDanh sach doc duoc la:\n";
			XuatDS_Tuyen(ds);
			break;
		default:
			cout << "\n*********Cam On***********.";
			cout <<endl;
			break;
			}
			}		
}while (chonmenu != 0);
	}