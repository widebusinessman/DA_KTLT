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

int main()
{
	DanhSachSV ListSV;
	cout << " Chuong trinh Quan Ly Sinh Vien * Phong Dao Tao * DHKHTN "<<endl;
	//if (!TaoNgauNhien(ListSV, 5, 5)) // dung mang dong thi 10000 sv hoac tham chi nhieu hon han van thuong ok
	//	return 0;
	int n = 10;
	ListSV.sv = new SINHVIEN[n];
	TaoNgauNhien(ListSV, n);
	//int second = Xuat(ListSV, ListSV.n + 1);
	//cout << endl << "Thoi gian xuat danh sach la : " << second << " giay" << endl;
	//system("pause"); // tam ngung chtr kieu nay ko hay lam nhung SV nen biet & dao sau tim hieu ve ham system()
	//ThemSV(ListSV);
	//Xuat(ListSV, ListSV.n + 1);
	for (int i = 0; i < n; i++) {
		Xuat(ListSV.sv[i], i+1);
	}
	_getch();
}