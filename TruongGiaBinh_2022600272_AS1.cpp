#include<iostream>
using namespace std;
#include<iomanip>
#include<string.h>

class Phieu;
class Nhacungcap
{
	private:
		char Manhacc[20];
		char Tennhacc[20];
		char Diachi[30];
		int Sdt;
	public:
		void nhap();
		void xuat();
};
void Nhacungcap::nhap()
{
	cout<<"Ma nha cung cap: ";       fflush(stdin);    gets(Manhacc);
	cout<<"Ten nha cung cap: ";      fflush(stdin);    gets(Tennhacc);
	cout<<"Dia chi: ";               fflush(stdin);    gets(Diachi);
	cout<<"SDT:";                    fflush(stdin);    cin>>Sdt;
}
void Nhacungcap::xuat()
{
	cout<<"Ma nha cung cap: "<<Manhacc<<setw(15);
	cout<<"Ten nha cung cap:  "<<Tennhacc<<endl;
	cout<<"Dia chi:  "<<Diachi<<setw(15)<<"SDT: "<<Sdt<<endl;
}
class Sanpham
{
	private:
		char Masp[20];
		char Tensp[20];
	    int Soluong, Dongia;
	public:
		void nhap();
		void xuat();
		float Thanhtien()
		{
			return Soluong * Dongia;
		}
	friend void Dem (Phieu K);	
	friend void Sapxep (Phieu &K);
};
void Sanpham::nhap()
{
	cout<<"Ma san pham: ";          fflush(stdin);    gets(Masp);
	cout<<"Ten san pham: ";         fflush(stdin);    gets(Tensp);
	cout<<"So luong: ";             fflush(stdin);    cin>>Soluong;
	cout<<"Don gia: ";                                cin>>Dongia;
}
void Sanpham::xuat()
{
	cout<<Masp<<setw(15)<<Tensp<<setw(15)<<Soluong<<setw(15)
	<<Dongia<<setw(15)<<Thanhtien()<<endl;
}
class Phieu
{
	private:
		char Maphieu[20];
		char Ngaylap[20];
		Nhacungcap X;
		Sanpham Y[20];
		int n;
	public:
		void nhap();
		void xuat();
	friend void Dem (Phieu K);	
	friend void Sapxep (Phieu &K);
};
void Phieu::nhap()
{
	cout<<"Ma phieu: ";           fflush(stdin);    gets(Maphieu);
	cout<<"Ngaylap: ";            fflush(stdin);    gets(Ngaylap);
	X.nhap();
	cout<<"Nhap so san pham: ";                     cin>>n;
	for(int i=0; i<n; i++)
	{
		Y[i].nhap();
	}
}
void Phieu::xuat()
{
	cout<<"\n Dai hoc Victory"<<endl;
	cout<<"======== PHIEU NHAP VAN PHONG PHAM========"<<endl;
	cout<<"Ma phieu: "<<setw(15)<<Maphieu<<setw(15)<<"Ngay lap:  "<<Ngaylap<<endl;
	X.xuat();
	cout<<"\n";
	cout<<"Masp"<<setw(15)<<"Ten san pham"<<setw(15)<<"So luong"<<setw(15)
	<<"Don gia"<<setw(15)<<"Thanh tien"<<endl;
	for(int i=0; i<n; i++)
	{
		Y[i].xuat();
	}
	float Tong = 0;
	for(int i=0; i<n; i++)
	{
		Tong += Y[i].Thanhtien();
	}
	cout<<setw(30)<<"TONG"<<setw(30)<<Tong<<endl;
	cout<<"Hieu truong"<<setw(25)<<"Phong tai chinh"<<setw(25)<<"Nguoi lap"<<endl;
}
void Dem(Phieu K)
{
	int dem = 0;
	for(int i=0; i<K.n; i++)
	{
		if(K.Y[i].Soluong < 80)
		{
			dem ++;
		}
	}
	if(dem == 0)
	{
           cout<<"Khong co sp nao co so luong nho hon 80";
    }
    else
    {
           cout<<"So sp co so luong nho hon 80 la: "<<dem<<endl;
    }
}
void Sapxep(Phieu &K)
{
	for(int i=0; i<K.n-1; i++)
	{
		for(int j=i+1; j<K.n; j++)
		{
			if(K.Y[i].Dongia > K.Y[j].Dongia)
			{
				Sanpham tg = K.Y[i];
				K.Y[i] = K.Y[j];
				K.Y[j] = tg;
			}
		}
	}
}
int main()
{
	Phieu K;
	K.nhap();
	K.xuat();
	
	Dem(K);
	
	Sapxep(K);
	K.xuat();
}
