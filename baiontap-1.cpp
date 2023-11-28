#include <iostream>
#include <iomanip>
using namespace std;
class date{
	public:
		int ngay, thang, nam;
		void nhap(){
			cout<<"Nhap ngay vao co quan: ";
			cin>>ngay;
			cout<<"\nNhap thang vao co quan: ";
			cin>>thang;
			cout<<"\nNhap nam vao co quan: ";
			cin>>nam;
		}
		void xuat(){
			cout<<ngay<<"/"<<thang<<"/"<<nam<<"\t";
		}
};
class canbo{
	private:
		string macanbo, hoten;
		date ngaysinh;
	public:
		void nhap(){
			cout<<"Nhap ma can bo: ";
			cin>>macanbo;
			cout<<"Nhap ho ten: ";
			cin.ignore();
			getline(cin,hoten);
			ngaysinh.nhap();
			}
		void xuat(){
			cout<<"Ma can bo: " << macanbo;
			cout << "\nHo ten: " << hoten;
			cout << "\nNgay thang nam vao co quan: ";
			ngaysinh.xuat();
		}		
		bool operator <	(canbo& cb){
		if (ngaysinh.nam < cb.ngaysinh.nam) 
            return true;
        else if (ngaysinh.nam == cb.ngaysinh.nam) 
            if(ngaysinh.thang < cb.ngaysinh.thang)
                return true;
            else if (ngaysinh.thang == cb.ngaysinh.thang)
            	if (ngaysinh.ngay < cb.ngaysinh.ngay)
                	return true;
        return false;
    	}
};	
class giangvien:public canbo{
	private:
		string donvi;
		float hesoluong;
		float phucap;
	public:
		void nhap_cb(){
			nhap();
			cin.ignore();
			cout << "Nhap don vi cua giang vien: ";
			getline(cin, donvi);
			cout << "Nhap he so luong: ";
			cin >> hesoluong;
			cout << "Nhap phu cap chuc vu: ";
			cin >> phucap;
		}
		void xuat_cb(){
			xuat();
			cout << "\nDon vi: " << donvi;
			cout << "\nHe so luong: " << hesoluong;
			cout << "\nPhu cap chuc vu: " << phucap;
			cout << "\nTien luong cua giang vien: " << tinh_luong() << endl;
		}
		long tinh_luong(){
			return hesoluong * 1490000 + phucap;
		}
		string get_dv(){
			return donvi;
		}
};

int main() {
	giangvien gv[50];
	int n;
	do{
		cout<<"Nhap so luong can bo: ";
   		cin>>n;
   		if (n <= 0 or n >= 50)
   			cout << "So luong khong hop le!";
   }while(n > 50);
   
	cin.ignore();
	//nhap du lieu cho giang vien
   	for (int i = 0;i<n;i++){
   		cout << "Nhap thong tin cua giang vien thu " << i+1 << endl;
   		gv[i].nhap_cb();
	}
	
	//sap xep tang dan theo ngay vao co quan
	cout << "***************************************";
	cout << "\nDanh sach giang vien sap xep tang dan theo ngay vao co quan" << endl;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (gv[i] < gv[i]){
				giangvien tam = gv[i];
				gv[i] = gv[j];
				gv[j] = tam;
			}
	for (int i = 0; i < n; i++)
		gv[i].xuat_cb();
		
	//in ra man hinh luong trung binh cua giang vien 
	long tongLuong = 0;
	for (int i = 0; i < n; i++)
    	tongLuong += gv[i].tinh_luong();
    long luongTrungBinh = tongLuong / n;

    cout << "\nLuong trung binh cua cac giang vien: " << luongTrungBinh << endl;
	
	
	
	//bang luong cua giang vien theo tung don vi
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (gv[i].get_dv() > gv[j].get_dv()){
				giangvien tam = gv[i];
				gv[i] = gv[j];
				gv[j] = tam;
			}
	for (int i = 0; i < n; i++){
		if(i == 0 || gv[i].get_dv() != gv[i-1].get_dv())
			cout << "\nDon vi: " << gv[i].get_dv() << endl;
		gv[i].xuat_cb();
	}
	cout << "*************************************";
	
	return 0;
}
