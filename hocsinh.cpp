#include <iostream>
#include <cstring> // Để dùng strcmp và strcpy
using namespace std;

typedef char St25[25];
typedef char St8[8];

struct HocSinh
{
    int MaHS;
    St25 HoTen;
    St8 NgaySinh;
    HocSinh *Next;
};

struct Lop
{
    St8 TenLop;
    HocSinh *DSHS; // Danh sách học sinh trong lớp
    Lop *Down;     // Con trỏ đến lớp tiếp theo
};

Lop *F = nullptr; // Danh sách lớp

// Hàm tìm lớp theo tên
Lop *TimLop(Lop *F, St8 Blop)
{
    Lop *cur = F;
    while (cur != nullptr)
    {
        if (strcmp(cur->TenLop, Blop) == 0)
        {
            return cur;
        }
        cur = cur->Down;
    }
    return nullptr; // Không tìm thấy lớp
}

// Hàm thêm lớp vào danh sách liên kết
void ThemLop(Lop *&F, St8 TenLop)
{
    Lop *newLop = new Lop;
    strcpy(newLop->TenLop, TenLop);
    newLop->DSHS = nullptr; // Chưa có học sinh
    newLop->Down = F;
    F = newLop;
}

// Hàm thêm học sinh vào danh sách của một lớp
void ThemHocSinh(Lop *F, St8 TenLop, int MaHS, St25 HoTen, St8 NgaySinh)
{
    Lop *lop = TimLop(F, TenLop);
    if (lop == nullptr)
    {
        cout << "Lop " << TenLop << " khong ton tai!\n";
        return;
    }

    HocSinh *newHS = new HocSinh;
    newHS->MaHS = MaHS;
    strcpy(newHS->HoTen, HoTen);
    strcpy(newHS->NgaySinh, NgaySinh);
    newHS->Next = lop->DSHS; // Thêm vào đầu danh sách học sinh
    lop->DSHS = newHS;
}

// Hàm in danh sách lớp và học sinh
void InDanhSachLop(Lop *F)
{
    Lop *curLop = F;
    while (curLop != nullptr)
    {
        cout << "Lop: " << curLop->TenLop << endl;

        HocSinh *curHS = curLop->DSHS;
        if (curHS == nullptr)
        {
            cout << "  Khong co hoc sinh.\n";
        }
        else
        {
            while (curHS != nullptr)
            {
                cout << "  MaHS: " << curHS->MaHS
                     << ", HoTen: " << curHS->HoTen
                     << ", NgaySinh: " << curHS->NgaySinh << endl;
                curHS = curHS->Next;
            }
        }
        cout << "----------------------\n";
        curLop = curLop->Down;
    }
}

int main()
{
    // Thêm các lớp
    ThemLop(F, "12A1");
    ThemLop(F, "11B2");
    ThemLop(F, "10C3");

    // Thêm học sinh vào các lớp
    ThemHocSinh(F, "12A1", 1001, "Nguyen Van A", "01/01/2006");
    ThemHocSinh(F, "12A1", 1002, "Tran Thi B", "12/12/2006");
    ThemHocSinh(F, "11B2", 2001, "Le Van C", "05/03/2007");

    Lop *lop = TimLop(F, "12A1");

    return 0;
}
