#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *Next;
};

Node *f = nullptr; // Con trỏ đầu danh sách

// Hàm thêm một node vào danh sách
void addNode(int value)
{
    Node *newNode = new Node();
    newNode->info = value;
    newNode->Next = nullptr;

    if (f == nullptr)
    {
        f = newNode; // Nếu danh sách rỗng, gán node mới làm đầu
    }
    else
    {
        Node *temp = f;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Next = newNode; // Thêm node vào cuối danh sách
    }
}
// Tìm số nút trong danh sách F có giá trị trường Info bé hơn một số nguyên X cho trước.
int findX(int value)
{
    Node *tem = f;
    while (tem != nullptr)
    {
        if (tem->info == value)
        {
            return tem->info;
        }
        tem = tem->Next;
        return -1;
    }
}

// xap sep dslk tang dan

void xapSepTangDan()
{
    // truong hop danh sach null hoac chi co 1 node
    if (f == nullptr || f->Next == nullptr)
    {
        return;
    }
    Node *cur = f;
    Node *index = nullptr;
    while (cur != nullptr)
    {
        index = cur->Next;
        while (index != nullptr)
        {
            if (cur->info > index->info)
            {
                int tem = cur->info;
                cur->info = index->info;
                index->info = tem;
            }
            index = index->Next;
        }
        cur = cur->Next;
    }
}

// sap xep giam dan
void sapXepGiamDan()
{
    if (f == nullptr || f->Next == nullptr)
    {
        return;
    }
    Node *cur = f;
    Node *index = nullptr;
    while (cur != nullptr)
    {
        index = cur->Next;
        while (index != nullptr)
        {

            if (cur->info < index->info)
            {
                int tem = cur->info;
                cur->info = index->info;
                index->info = tem;
            }
            index = index->Next;
        }
        cur = cur->Next;
    }
}

// 2. Chèn một nút có giá trị trường Info bằng X vào danh sách F đã được sắp xếp theo thứ tự tăng dần của trường Info.

void chenVaoDSsortTangDan(int value)
{
    Node *newNode = new Node;
    newNode->info = value;
    newNode->Next = nullptr;

    if (f == nullptr || value <= f->info)
    {
        newNode->Next = f;
        f = newNode;
        return;
    }
    Node *tem = f;

    while (tem->Next != nullptr && tem->Next->info < value)
    {
        tem = tem->Next;
    }
    newNode->Next = tem->Next;
    tem->Next = newNode;
}

void chenVaoSDSortGiamDan(int value)
{
    Node *newNode = new Node();
    newNode->info = value;
    newNode->Next = nullptr;
    if (f == nullptr || value >= f->info)
    {
        newNode->Next = f;
        f = newNode;
    }

    Node *tem = f;
    while (tem->Next != nullptr && tem->Next->info > value)
    {
        tem = tem->Next;
    }
    newNode->Next = tem->Next;
    tem->Next = newNode;
}

// tim dci chi cua 1 node
Node *timDiaChi(int x)
{
    Node *cur = f;
    while (cur != nullptr)
    {
        if (cur->info == x)
        {
            return cur;
        }
        else if (cur->info > x)
        {
            return nullptr;
        }
        cur = cur->Next;
    }
    return nullptr;
}
// Hàm hiển thị danh sách
void displayList()
{
    Node *temp = f;
    while (temp != nullptr)
    {
        cout << temp->info << " ";
        temp = temp->Next;
    }
    cout << endl;
}

int main()
{
    // Thêm 5 số nguyên vào danh sách
    addNode(20);
    addNode(10);
    addNode(50);
    addNode(40);
    addNode(30);

    // int x = 100;
    // int find = findX(x);
    // if (find != -1)
    // {
    //     cout << find;
    // }
    // else
    // {
    //     cout << "Ko tim thay";
    // }
    // sapXepGiamDan();
    // displayList();

    // chenVaoDSsortGiamDan(100);

    xapSepTangDan();
    chenVaoDSsortTangDan(11);

    displayList();
    Node *rs = timDiaChi(11);
    if (rs)
    {
        cout << "node duoc tim thay tai dia chi " << rs;
    }
    else
    {
        cout << "ko tim thay";
    }
    return 0;
}
