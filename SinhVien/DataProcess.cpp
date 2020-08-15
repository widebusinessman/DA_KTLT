// Viết chương trình thực hiện các chức năng thao tác với phần tử sinh viên:
// 1. Read List from File
// 2. Save List to File
// 3.  Print List
// 4. Update an Element
// 5. Add an Element
// 6. Delete an Element
// 7. Sort List
// 8. Set List to Dynamic Array
// 9. Set List to Linked List
// ===================== DANH SÁCH THÀNH VIÊN ===================================
//	Họ tên						MSSV
// Nguyễn Thanh Vinh			1660728
// Lương Triều Vỹ						
// 
// ==============================================================================
#include"DataProcess.h"

/*Hàm tạo ngẫu nhiên MSSV*/
string TaoNgauNhienMaSV(int mssv)
{
	const char* _maSV[4] = { "166000", "16600", "1660", "166" };
	string str = to_string(mssv);
	string masv;
	if (mssv < 10) {
		string str = to_string(mssv);
		masv = _maSV[0] + str;
	}
	else if (mssv >= 10 && mssv < 100) {
		string str = to_string(mssv);
		masv = _maSV[1] + str;
	}
	else if (mssv >= 100 && mssv < 1000) {
		string str = to_string(mssv);
		masv = _maSV[2] + str;
	}
	else if (mssv >= 1000 && mssv < 10000) {
		string str = to_string(mssv);
		masv = _maSV[3] + str;
	}
	return masv;
}
/*Hàm tạo ngẫu nhiên tên sinh viên*/
string TaoNgauNhienTenSV()
{
	string tensv;
	const char * Ho[18] = { "Nguyen ", "Tran ", "Le ", "Pham ", "Huynh ", "Phan ", "Vu ",
			"Vo ", "Dang ", "Bui ", "Do ", "Ho ", "Ngo ", "Duong ", "Ly ", "Trinh ", "Ha ", "Thai " };
	const char * Lot[9] = { "Dinh ", "Van ", "Thanh ", "Ngoc ", "Cong ", "The ", "Nhat ", "Tuong ", "" };
	const char * Ten[30] = { "Xuan ", "Ha ", "Thu ", "Dong ", "Tay ", "Nam ", "Bac ", "Trung ", "Dai ",
			"Cuc ", "Mai ", "Dao ", "Le ", "Nho ", "Cam ", "Quit ", "Buoi ", "Tac ", "Anh ", "Quan ", "Diep ",
			"Giang ", "Hieu ", "Khanh ", "Long ", "Linh ", "Minh ", "Phuong ", "Sinh ", "Thanh " };
	tensv = Ho[rand() % 18];
	int iTenLot = rand() % 9;
	if (iTenLot != 9) tensv = tensv + Lot[iTenLot];
	else {
		iTenLot = rand() % 18;
		if (strncmp(Ho[iTenLot], (const char*)tensv.c_str(), strlen(Ho[iTenLot])))
			tensv = tensv + Ho[rand() % 18];
	}
	tensv = tensv + Ten[rand() % 30];
	return tensv;
}
/*Hàm tạo ngẫu nhiên ngày sinh*/
Ngay TaoNgauNhienNgaySinh()
{
	Ngay d;
	int day[31] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };
	int month[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10, 11, 12 };
	int year = 1998;
	d.nam = year;
	d.thang = month[rand() % 12];
	switch (d.thang)
	{
	case 1:
	case 3:
	case 5: 
	case 7: 
	case 8: 
	case 10:
	case 12:
		d.ngay = day[rand() % 31];
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		d.ngay = day[rand() % 30];
		break;
	case 2:
		d.ngay = day[rand() % 28];
		break;
	}
	return d;
}
/*Hàm tạo ngẫu nhiên CMND*/
string TaoNgauNhienCMND(int masv)
{
	string cmnd;
	const char* CMND[4] = { "21228000", "2122800", "212280", "21228" };
	string str = to_string(masv);
	if (masv < 10) {
		string str = to_string(masv);
		cmnd = CMND[0] + str;
	}
	else if (masv >= 10 && masv < 100) {
		string str = to_string(masv);
		cmnd = CMND[1] + str;
	}
	else if (masv >= 100 && masv < 1000) {
		string str = to_string(masv);
		cmnd = CMND[2] + str;
	}
	else if (masv >= 1000 && masv < 10000) {
		string str = to_string(masv);
		cmnd = CMND[3] + str;
	}
	return cmnd;
}
/*Hàm tạo ngẫu nhiên sinh viên*/
void TaoNgauNhienSV(SINHVIEN &X, int mssv) 
{
	string masv = TaoNgauNhienMaSV(mssv);
	X.MaSV[0] = 0;
	strcat_s(X.MaSV, (char*)masv.c_str());

	string tensv = TaoNgauNhienTenSV();
	X.TenSV[0] = 0;
	strcat_s(X.TenSV, (char*)tensv.c_str());

	const char* _gioiTinh[2] = { "Nam", "Nu" };
	X.GioiTinh[0] = 0;
	strcat_s(X.GioiTinh, _gioiTinh[rand() % 2]);

	Ngay ns = TaoNgauNhienNgaySinh();
	X.NgaySinh = ns;

	string cmnd = TaoNgauNhienCMND(mssv);
	X.SoCMND[0] = 0;
	strcat_s(X.SoCMND, (char*)cmnd.c_str());
	//strcat_s(X.SoCMND, _maSV);
	X.DiaChi[0] = 0;
	strcat_s(X.DiaChi, "227 Nguyen Van Cu, Phuong 4, Quan 5, TP HCM");
	X.Email[0] = 0;
	//strcat_s(X.Email, _maSV);
	strcat_s(X.Email, "@student.hcmus.edu.vn");
	X.SoDT[0] = 0;
	strcat_s(X.SoDT, "0123456789");
	X.NganhHoc[0] = 0;
	strcat_s(X.NganhHoc, "Cong Nghe Thong Tin");
	X.SoMonDaHoc = 1;
	X.Mon[X.SoMonDaHoc] = { "Ky thuat lap trinh", 45, 30, 1, X.Mon->DiemMH[1] = {7.5, {1, 1, 1998} } };
}
/*Hàm đếm số sinh viên trong danh sách sinh viên*/
int demSV(SINHVIEN *sv)
{
	int soSV;
	if (sv == NULL)
		soSV = 0;
	else
		soSV = sizeof(sv) / sizeof(sv[0]);
	return soSV;
}
/*Tạo ngẫu nhiên DSSV với <num> sinh viên và <maxsize> phần tử, return false nếu không tạo được*/
bool TaoNgauNhien(DanhSachSV &ListSV, int num) 
{
	if (num < MAX) ListSV.size = MAX;
	else ListSV.size = num + 100;
	ListSV.sv = new SINHVIEN[ListSV.size];
	if (ListSV.sv == NULL) return false;
	ListSV.n = num;
	//srand(time(0));
	
	for (int i = 0; i < ListSV.n; i++) {
		int _soSV = demSV(ListSV.sv);
		TaoNgauNhienSV(ListSV.sv[i], _soSV + i + 1);
	}
		
	return true;
}
/*Mở rộng danh sách thêm Inc phần từ, nếu tạo không được thì giảm đi 10 cho đến khi tạo được hoặc Inc <= 0*/
//bool MoRongDS(DanhSachSV &ListSV, int Inc = 101) {
//	if (ListSV.n == ListSV.size) 
//	{
//		for (; Inc > 0; Inc -= 10) {
//			SINHVIEN* p = (SINHVIEN*)realloc(ListSV.sv, (ListSV.size + Inc) * sizeof(SINHVIEN));
//			if (p != NULL) {
//				ListSV.sv = p;
//				break;
//			}
//		}
//		if (Inc <= 0) return false;
//		ListSV.size += Inc;
//	}
//	return true;
//}
/*Thêm 1 sinh viên vào DSSV*/
//bool ThemSV(DanhSachSV &ListSV, SINHVIEN X = { "20192000", "Nguyen Van Cu", "Nam", { 1, 1, 1999 },
//		"079099001002", "", "", "", "Cong nghe Thong tin", 0 }) 
//{
//	if (ListSV.n == ListSV.size) // must increase array size
//		if (!MoRongDS(ListSV)) return false; //can not increase array size
//
//	ListSV.sv[ListSV.n++] = X;
//	return true;
//}

/*Hàm xuất sinh viên*/
void Xuat(SINHVIEN X, int i)
{
	cout << i << "\t" << X.MaSV << "\t" << X.TenSV << "\t" << X.GioiTinh 
		<< "\t" << X.NgaySinh.ngay << "/" << X.NgaySinh.thang << "/" << X.NgaySinh.nam 
		<< "\t" << X.SoCMND << endl;

}
/*Xuất DSSV theo từng trang, mỗi trang có <num> sinh viên, return số giây hàm chạy*/
//int Xuat(DanhSachSV ListSV, int num = 100)
//{
//	//time_t t1, t2;
//	//time(&t1); // lấy thời gian hiện tại
//	cout << "Danh sach SV: " << endl;
//	for (int i = 0; i < ListSV.n; i++)
//	{
//		cout << "\n#" << i + 1 << ". ";
//		Xuat(ListSV.sv[i]);
//		//if (_kbhit() && _getch() == 27) break; // nhấn ESC để thoát
//		//if (i % num == num - 1) cin.get();
//	}
//	cout << endl;
//	//time(&t2); // lấy thời gian hiện tại
//	//return difftime(t2, t1);
//	return 1;
//}