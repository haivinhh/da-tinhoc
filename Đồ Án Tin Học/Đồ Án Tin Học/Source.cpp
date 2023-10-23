#include"iostream"
#include"string"
#include"stdlib.h"
#include"iomanip"// de sử dụng setw canh vi tri cho form bang diem
#include"fstream"
using namespace std;

struct SinhVien 
{
	string mssv;
	string name;
	string gioitinh;
	string lop;
	string sdt;
	float nmlt;//nhap mon lap trinh
	float csdl;//co so du lieu
	float web;// web
	float ctdl;//cau truc du lieu
	float dath;// do an tin hoc
	float gdtc;//giao duc the chat
	float tongdiem;
	float diemtb;
	string xeploai;
	
	

};
typedef struct SinhVien sinhvien;
struct node {
	sinhvien* data;// du lieu chua trong 1 cai node
	struct node* link;//con trỏ lk các node voi nhau
};
typedef struct node Node;
//khai báo cấu trúc của dslk đơn
struct list {
	Node* pHead;//node qli đầu ds
	Node* pTail;//node qli cuối ds
};
typedef struct list List;
void KhoiTaoList(List& l) {
	l.pHead = l.pTail = NULL;
}



void ThemVaoDauMotSinhVien(List& l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->link = l.pHead;
		l.pHead = p;
	}
}
void themvaocuoimotsinhvien(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead =l.pTail= p;
	}
	else
	{
		l.pTail->link = p;
		l.pTail = p;
	}
	
}

void sethl(sinhvien* sv)//ham xuat dssv theo lop
{

	if (sv->diemtb >= 8)
		sv->xeploai = "Gioi";
	else if (sv->diemtb >= 5)
		sv->xeploai = "Kha";
	else sv->xeploai = "Trung Binh";
}
void nhapthongtinsv(sinhvien* sv)
{

	cin.ignore();
	cout << "Nhap ID cua sinh vien: ";
	cin >> sv->mssv;
	fflush(stdin);
	cin.ignore();
	cout << "Nhap ten cua sinh vien: ";
	getline(cin, sv->name);
	fflush(stdin);
	cout << "Nhap lop cua sinh vien: ";
	getline(cin, sv->lop);
	fflush(stdin);
	cout << "Nhap gioi tinh cua sinh vien (Nam hoac Nu): ";
	getline(cin, sv->gioitinh);
	fflush(stdin);
	cout << "Nhap so dien thoai cua sinh vien: ";
	getline(cin, sv->sdt);
	cout << "Nhap diem nhap mon lap trinh: ";
	cin >> sv->nmlt;
	cout << "Nhap diem co so du lieu: ";
	cin >> sv->csdl;
	cout << "Nhap diem web: ";
	cin >> sv->web;
	cout << "Nhap diem cau truc du lieu: ";
	cin >> sv->ctdl;
	cout << "Nhap diem do an tin hoc: ";
	cin >> sv->dath;
	cout << "Nhap diem giao duc the chat: ";
	cin >> sv->gdtc;
	sv->tongdiem = (sv->nmlt + sv->csdl + sv->web + sv->ctdl + sv->dath + sv->gdtc);
	sv->diemtb = sv->tongdiem / 6;
	sethl(sv);

}
Node* KhoiTaoNode() 
{
	sinhvien* sv = new sinhvien;
	nhapthongtinsv(sv);
	Node* p = new Node;
	if (p == NULL) {
		cout << "full ram ko thể tao thêm\n";
		return 0;
	}
	p->data = sv;
	p->link = NULL;
	return p;
	
}
void dssv(List l ) //ds tat ca sv da nhap
{
	cout << left << setw(10) << "ID" << setw(30) << "TEN" << setw(10) << "GIOI TINH" << setw(5) << "Lop"
		<< setw(12) << "SDT" << "\n";
	cout << "======================================================================================================================\n";
	for (Node* k = l.pHead; k != NULL; k = k->link) {
		
		cout << left << setw(10) << k->data->mssv << setw(30) << k->data->name << setw(10) << k->data->gioitinh << setw(5) << k->data->lop
			<< setw(12) << k->data->sdt << endl;
	}
}

void xuatdssvlop(Node* k)//ham xuat dssv theo lop
{
	cout << left << setw(10) << k->data->mssv << setw(30) << k->data->name << setw(10) << k->data->gioitinh << setw(5) << k->data->lop
		<< setw(12) << k->data->sdt << setw(10) << k->data->diemtb << setw(10);
	if (k->data->diemtb >= 8)
		cout << "Gioi"<<endl;
	else if (k->data->diemtb >= 5)
		cout << "Kha"<<endl;
	else cout << "Trung Binh"<<endl;
}
//ham tim dssv theo lop
void dssvtheolop(List l) 
{
	string timlop;
	cout << "Nhap lop can tim: ";
	cin >> timlop;
	cout << left << setw(10) << "ID" << setw(30) << "TEN" << setw(10) << "GIOI TINH" << setw(5) << "Lop"
		<< setw(12) << "SDT" << setw(10) << "DIEM TB" << setw(10) << "XEP LOAI" << "\n";
	cout << "======================================================================================================================\n";
	for (Node* k = l.pHead; k != NULL; k = k->link) {
		if (k->data->lop == timlop) {
			xuatdssvlop(k);
		}
		

	}
}

//ham xau sv theo id
void xuatdssvid(Node* k)
{
	cout << left << setw(10) << k->data->mssv << setw(30) << k->data->name << setw(10) << k->data->gioitinh << setw(5) << k->data->lop
		<< setw(12) << k->data->sdt << setw(10) << k->data->diemtb << setw(10); 
	if (k->data->diemtb >= 8)
		cout << "Gioi" << endl;
	else if (k->data->diemtb >= 5)
		cout << "Kha" << endl; 
	else cout << "Trung Binh" << endl;
	cout << "\n";
	cout << "==================================================" << "\n";
	cout << "||    Mon            " << "    \t|\t" << "Diem" << "\t||" << "\n";
	cout << "==================================================" << "\n";
	cout << "||Diem nhap mon lap trinh" << "\t|\t" << k->data->nmlt << "\t||" << "\n";
	cout << "||Diem co so du lieu     " << "\t|\t" << k->data->csdl << "\t||" << "\n";
	cout << "||Diem web               " << "\t|\t" << k->data->web << "\t||" << "\n";
	cout << "||Diem cau truc du lieu  " << "\t|\t" << k->data->ctdl << "\t||" << "\n";
	cout << "||Diem do an tin hoc     " << "\t|\t" << k->data->dath << "\t||" << "\n";
	cout << "||Diem giao duc the chat " << "\t|\t" << k->data->gdtc << "\t||" << "\n";
	cout << "==================================================" << "\n";
}
//ham tìm sv theo id
void searchsv(List l) 
{
	string  mssv;
	cout << "Nhap ID sinh vien can tim:  ";
	cin >> mssv;
	cout << left << setw(10) << "ID" << setw(30) << "TEN" << setw(10) << "GIOI TINH" << setw(5) << "Lop"
		<< setw(12) << "SDT" << setw(10) << "DIEM TB" << setw(10) << "XEP LOAI" << "\n";
	cout << "======================================================================================================================\n";
	for (Node* k = l.pHead; k != NULL; k = k->link) {
		if (k->data->mssv == mssv) {
			xuatdssvid(k);
		}
	}
}
//ham cập nhật sv
void capnhatsv(List& l) 
{
	string mssv;
	cout << "Nhap Ma So sinh vien can chinh sua thong tin : ";
	cin >> mssv;
	for (Node* k = l.pHead; k != NULL; k = k->link) {
		if (k->data->mssv == mssv) {
			cout << "Moi ban sua thong tin sinh vien co ma so : " << mssv << endl;
			nhapthongtinsv(k->data);
			cout << "Cap nhat sinh vien thanh cong";
		}
	}

}
//hàm xóa sv đầu
void xoadau(List& l)
{
	if (l.pHead == NULL)//nếu ds rỗng
	{
		return;
	}
	Node* p = l.pHead;//node p là node sẽ xóa
	l.pHead = l.pHead->link;//cập nhật lại p.Head là phần tử kế tiếp
	delete p;
}
//hàm xóa sv cuối
void xoacuoi(List& l)
{
	if (l.pTail == NULL)
	{
		return;
	}
	 if (l.pHead->link == NULL)//truong hợp ds có 1 ptu
	{
		xoadau(l);
		return;
	}
		for (Node* k = l.pHead; k != NULL; k = k->link)//duyệt từ đầu đến cuối danh sach
		{
			if (k->link == l.pTail)//phát hiện thằng cuối 
			{
				delete l.pTail;//xoa di ptu cuối
				k->link = NULL;//cho con trỏ của node kế cuối đến vùng nhớ NULL
				l.pTail = k;//cập nhật lại l.ptail
				return;
			}
		}
}
//ham xoa sv bat ky
void xoasvbatky(List& l)
{
	string mssv;
	cin.ignore();
	cout << "Nhap mssv can xoa: ";
	cin >> mssv;
	Node* g = new Node;
	if (l.pHead->data->mssv==mssv)
	{
		xoadau(l);
		return;
	}
	 if (l.pTail->data->mssv == mssv)
	{
		xoacuoi(l);
		return;
	}
	 //xoa giua
	for (Node* k = l.pHead; k != NULL; k = k->link) {
		if (k->data->mssv == mssv) 
		{
			g->link = k->link;
			k = g;
		}
		g = k;
	}
}

//đém số sv đã nhập
int demsv(List l)
{
	int k = 0;
	list tmp = l;
	while (tmp.pHead != NULL)
	{
		k++;
		tmp.pHead = tmp.pHead->link;
	}
	return k;
}
//ghi file sv
void ghifile(ofstream& fileout, List l)
{
	fileout << "so sv la: " << demsv(l) << endl;
	while (l.pHead != NULL)
	{

		fileout << l.pHead->data->mssv << ",";
		fileout << l.pHead->data->name << ",";
		fileout << l.pHead->data->lop << ",";
		fileout << l.pHead->data->gioitinh << ",";
		fileout << l.pHead->data->sdt << ",";
		fileout << l.pHead->data->nmlt << ",";
		fileout << l.pHead->data->csdl << ",";
		fileout << l.pHead->data->web << ",";
		fileout << l.pHead->data->ctdl << ",";
		fileout << l.pHead->data->dath << ",";
		fileout << l.pHead->data->gdtc << ",";
		fileout << l.pHead->data->tongdiem << ",";
		fileout << l.pHead->data->diemtb << ",";
		fileout << l.pHead->data->xeploai << endl;
		l.pHead = l.pHead->link;
	}
}

//luu sv vào file txt
void luufile(List l)
{
	ofstream fileout;
	fileout.open("sinhvien.txt", ios::out);
	ghifile(fileout,l);
	fileout << endl;
	fileout.close();
	
}
//đọc file sv
void docfilesv(ifstream& filein, List& l)
{
	int x = 0;
	filein >> x;
	filein.seekg(1, 1);
	for (int i = 0; i < x; i++)
	{
		Node* p = new Node;
		sinhvien* sv = new sinhvien;
	
			getline(filein, sv->mssv, ',');
			getline(filein, sv->name, ',');
			getline(filein, sv->gioitinh, ',');
			getline(filein, sv->lop, ',');
			getline(filein, sv->sdt, ',');
			filein >> sv->nmlt, ',';
			filein >> sv->csdl, ',';
			filein >> sv->web, ',';
			filein >> sv->ctdl, ',';
			filein >> sv->dath, ',';
			filein >> sv->gdtc, ',';
			filein >> sv->tongdiem, ',';
			filein >> sv->diemtb, ',';
			getline(filein, sv->xeploai);
		p->data=sv;
			ThemVaoDauMotSinhVien(l, p);

			
	}
}

//đọc sv từ file 
void docfile(List& l)
{
	ifstream filein;
	filein.open("sinhvien.txt", ios::in);
	docfilesv(filein, l);
	filein.close();
}


//menu
void ChucNang(List& l) 
{
	char confirm;
	do
	{
		system("cls");
		int n;
		cout << "==========================================" << "\n";
		cout << "||       MENU QUAN LY SINH VIEN C++     ||" << "\n";
		cout << "==========================================" << "\n";
		cout << "|| 1. Them sinh vien                    ||" << "\n";
		cout << "|| 2. Danh sach sinh vien               ||" << "\n";
		cout << "|| 3. Danh sach sinh vien theo lop      ||" << "\n";
		cout << "|| 4. Tim sinh vien bang ID             ||" << "\n";
		cout << "|| 5. Cap nhat sinh vien                ||" << "\n";
		cout << "|| 6. Xoa sinh vien                     ||" << "\n";
		cout << "|| 7. Doc File                          ||" << "\n";
		cout << "|| 8. Ghi File                          ||" << "\n";
		cout << "|| 0. Thoat                             ||" << "\n";
		cout << "==========================================" << "\n";
		cout << "\nNhap chuc nang ban  chon : ";
		cin >> n;
		if (n == 1) {
			cout << "Moi Ban nhap thong tin 1 sinh vien : \n";
			Node* p = KhoiTaoNode();
			ThemVaoDauMotSinhVien(l, p);
		}
		if (n == 2) {
			cout << "***Danh sach tat ca sinh vien***\n";
			dssv(l);
		}
		if (n == 3) {
			cout << "***Danh sach sinh vien theo lop***\n";
			dssvtheolop(l);
		}
		if (n == 4) {
			cout << "***Tim sinh vien bang ID***\n";
			searchsv(l);
		}
		if (n == 5) {
			cout << "***Cap nhat sinh vien***\n";
			capnhatsv(l);
		}
		if (n == 6) {
			cout << "***Xoa sinh vien***\n";
			xoasvbatky(l);
			cout << "***Xoa sinh vien thanh cong***\n";
		}
		
		if (n == 7) {
			docfile(l);
			
		}if (n == 8) {
			
			luufile(l);
			cout << "***Luu sinh vien vào sinhvien.txt thanh cong***";
		}
		if (n == 0) {
			break;
		
		}
		cout << "\n******************************\n";
		cout << "Nhan y de tiep tuc chon menu: ";
		cin >> confirm;
	} while (confirm == 'y');
}



int main() 
{
	List l;
	KhoiTaoList(l);
	ChucNang(l);
	return 0;
}