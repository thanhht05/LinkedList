#include <iostream>
using namespace std;

struct Nut
{
    int So;
    Nut *tiep;
};
Nut *head = NULL;

Nut *addNut(int so)
{
    Nut *newNut = new Nut();
    newNut->So = so;
    newNut->tiep = NULL;
    return newNut;
}

void themCuoiList(Nut *&head, int val)
{
    Nut *newNut = addNut(val);
    if (head == NULL)
    {
        head = newNut;
        return;
    }
    Nut *cur = head;
    while (cur->tiep != NULL)
    {
        cur = cur->tiep;
    }
    cur->tiep = newNut;
}

void inNut(Nut *head)
{
    Nut *cur = head;
    while (cur != NULL)
    {
        cout << cur->So << " ";
        cur = cur->tiep;
    }
    cout << endl;
}

int checkSort()
{
    if (head == NULL || head->tiep == NULL)
    {
        // Danh sách rỗng hoặc chỉ có 1 phần tử => đã tăng dần
        return 1;
    }
    Nut *cur = head;

    while (cur->tiep != NULL)
    {

        if (cur->So > cur->tiep->So)
        {
            return 0;
        }
        cur = cur->tiep;
    }
    return 1;
}

void sortAsc()
{
    Nut *cur = head;
    Nut *index = NULL;

    while (cur != NULL)
    {
        index = cur->tiep;

        while (index != NULL)
        {
            if (cur->So > index->So)
            {
                int tem = cur->So;
                cur->So = index->So;
                index->So = tem;
            }
            index = index->tiep;
        }
        cur = cur->tiep;
    }
}

void insetAsc(int val)
{
    Nut *newNut = addNut(val);

    Nut *cur = head;

    while (cur->tiep != NULL && cur->tiep->So < val)
    {
        cur = cur->tiep;
    }
    newNut->tiep = cur->tiep;
    cur->tiep = newNut;
    // 1->2->3->4->5
}
int findSo(Nut *head, int so)
{
    Nut *cur = head;
    while (cur != NULL)
    {
        if (cur->So == so)
        {
            return 1; // Tìm thấy
        }
        cur = cur->tiep;
    }
    return 0; // Không tìm thấy
}
Nut *findGiao(Nut *L1, Nut *L2)
{
    Nut *kq = NULL;

    Nut *cur = L1;
    while (cur != NULL)
    {
        if (findSo(L2, cur->So) && !findSo(kq, cur->So))
        {
            themCuoiList(kq, cur->So);
        }
        cur = cur->tiep;
    }
    return kq;
}

Nut *findHop(Nut *L1, Nut *L2)
{
    Nut *kq = NULL;

    Nut *cur = L1;
    while (cur != NULL)
    {
        themCuoiList(kq, cur->So);
        cur = cur->tiep;
    }

    Nut *curL2 = L2;
    while (curL2 != NULL)
    {
        if (!findSo(kq, curL2->So))
        {
            themCuoiList(kq, curL2->So);
        }
        curL2 = curL2->tiep;
    }
    return kq;
}
int main()
{
    Nut *L1 = NULL;
    Nut *L2 = NULL;

    themCuoiList(L1, 1);
    themCuoiList(L1, 2);
    themCuoiList(L1, 3);
    themCuoiList(L1, 4);

    themCuoiList(L2, 3);
    themCuoiList(L2, 4);
    themCuoiList(L2, 5);
    themCuoiList(L2, 6);

    // Nut *kq = findGiao(L1, L2);

    // cout << "Giao cua L1 va L2: ";

    Nut *kq = findHop(L1, L2);

    cout << "Hop cua L1 va L2: ";
    inNut(kq); // Output: 3 4
}
