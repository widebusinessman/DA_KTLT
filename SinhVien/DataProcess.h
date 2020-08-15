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
#pragma once

#ifndef __DataProcess_h__
#define __DataProcess_h__
#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include<iostream>
#include<sstream>
using namespace std;
#define MAX 12345

/*Tạo struct Ngày*/
struct Ngay 
{
	int ngay, thang, nam;
};
/*Tạo struct Điểm môn học*/
struct DiemMonHoc 
{
	float Diem;
	Ngay NgayVaoDiem;
};
/*Tạo struct Môn học*/
struct MonHoc 
{
	char TenMH[20];
	int  SoTietLT;
	int  SoTietTH;
	int  SoLanHoc;
	DiemMonHoc DiemMH[14]; // Gia đình sinh viên có thể học 1 môn tối đa 14 lần 
};
/*Tạo struct Sinh viên*/
struct SINHVIEN 
{
	char MaSV[9];
	char TenSV[30];
	char GioiTinh[5];
	Ngay NgaySinh;
	char SoCMND[13];
	char DiaChi[90];
	char Email[40];
	char SoDT[12];
	char NganhHoc[30];
	int  SoMonDaHoc;
	MonHoc Mon[50];
};

struct DanhSachSV 
{
	SINHVIEN *sv;
	int n; // Số sinh viên thực sự
	int size; // Kích thước tối đa hiện tại của mảng (Số phần tử được cấp phát trong Heap)
};
/*Hàm tạo ngẫu nhiên MSSV*/
string TaoNgauNhienMaSV(int mssv);
/*Hàm tạo ngẫu nhiên tên sinh viên*/
string TaoNgauNhienTenSV();
/*Hàm tạo ngẫu nhiên ngày sinh*/
Ngay TaoNgauNhienNgaySinh();
/*Hàm tạo ngẫu nhiên CMND*/
string TaoNgauNhienCMND(int masv);
/*Hàm tạo ngẫu nhiên sinh viên*/
void TaoNgauNhienSV(SINHVIEN &X);
/*Hàm đếm số sinh viên trong danh sách sinh viên*/
int demSV(SINHVIEN *sv);
/*Tạo ngẫu nhiên DSSV với <num> sinh viên và <maxsize> phần tử, return false nếu không tạo được*/
bool TaoNgauNhien(DanhSachSV &ListSV, int num);
/*Mở rộng danh sách thêm Inc phần từ, nếu tạo không được thì giảm đi 10 cho đến khi tạo được hoặc Inc <= 0*/
bool MoRongDS(DanhSachSV &ListSV, int Inc = 101);
/*Thêm 1 sinh viên vào DSSV*/
bool ThemSV(DanhSachSV &ListSV, SINHVIEN X = { "20192000", "Nguyen Van Cu", "Nam", { 1, 1, 1999 },
		"079099001002", "", "", "", "Cong nghe Thong tin", 0 });
/*Hàm xuất sinh viên*/
void Xuat(SINHVIEN X, int i);
/*Xuất DSSV theo từng trang, mỗi trang có <num> sinh viên, return số giây hàm chạy*/
int Xuat(DanhSachSV ListSV, int num = 100);

#endif // !__DataProcess_h__
