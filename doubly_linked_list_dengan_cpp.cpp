#include<iostream>
#include<cstdio>
#include<cstdlib>
/*
 * Mendeklarasikan Node 
 */
using namespace std;
struct node
{
    int memo;
    struct node *next;
    struct node *prev;
}*start;
 
/*
 * Class Declaration 
 */
class double_linked_list
{
    public:
        void create_list(int value);
        void insert_front(int value);
        void insert_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_dll();
        void count();
        void reverse();
        double_linked_list()
        {
            start = NULL;  
        }
};
 
/*
 * Main: Conatins Menu
 */
int main()
{
    int choice, element, position;
    double_linked_list dll;
    while (1)
    {
        cout<<endl<<"=================================="<<endl;
        cout<<endl<<" Operasi pada Doubly linked list"<<endl;
        cout<<endl<<"=================================="<<endl;         
        cout<<"1.Buat Node"<<endl;
        cout<<"2.Input di awal"<<endl;
        cout<<"3.Input setelah posisi"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Tampilkan"<<endl;
        cout<<"6.Count"<<endl;
        cout<<"7.Reverse"<<endl;
        cout<<"8.Keluar"<<endl;
        cout<<"Masukkan nomor : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Masukkan node: ";
            cin>>element;
            dll.create_list(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Masukkan node: ";
            cin>>element;
            dll.insert_front(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Insert nilai node: ";
            cin>>element;
            cout<<"Masukkan node setelah: ";
            cin>>position;
            dll.insert_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (start == NULL)
            {                      
                cout<<"Daftar kosong, tidak ada yang dihapus"<<endl;   
                break;
            }
            cout<<"Masukkan node yang akan dihapus: ";
            cin>>element;
            dll.delete_element(element);
            cout<<endl;
            break;
        case 5:
            dll.display_dll();
            cout<<endl;
            break;
        case 6:
            dll.count();
            break;    
        case 7:
            if (start == NULL)
            {
                cout<<"Daftar kosong, tidak ada node yang di reverse"<<endl;
                break;
            }
            dll.reverse();
            cout<<endl;
            break;
        case 8:
            exit(1);
        default:
            cout<<"Pilihan tidak sesuai dengan daftar"<<endl;
        }
    }
    return 0;
}
 
/*
 * Create Double Link List
 */
void double_linked_list::create_list(int value)
{
    struct node *s, *temp;
    temp = new(struct node); 
    temp->memo = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
 
/*
 * Insert di awal
 */
void double_linked_list::insert_front(int value)
{
    if (start == NULL)
    {
        cout<<"'Buat Node' terlebih dahulu."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->memo = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Node telah ditambahkan"<<endl;
}
 
/*
 * Insert pada posisi tertentu
 */
void double_linked_list::insert_after(int value, int pos)
{
    if (start == NULL)
    {
        cout<<"'Buat Node' terlebih dahulu."<<endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"Kurang dari ";
            cout<<pos<<" node."<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->memo = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Node telah ditambahkan"<<endl;
}
 
/*
 * Hapus node dari daftar
 */
void double_linked_list::delete_element(int value)
{
    struct node *tmp, *q;
     /* Node pertama dihapus*/
    if (start->memo == value)
    {
        tmp = start;
        start = start->next;  
        start->prev = NULL;
        cout<<"Node telah dihapus"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {   
        /* Node pada posisi tertentu dihapus*/
        if (q->next->memo == value)  
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Node telah dihapus"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
     /*Node terakhir dihapus*/
    if (q->next->memo == value)    
    {    
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Node telah dihapus"<<endl;
        return;
    }
    cout<<"Node "<<value<<" tidak ditemukan"<<endl;
}
 
/*
 * tampilkan Doubly Link List
 */
void double_linked_list::display_dll()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"Daftar kosong, tidak ada data yang dapat ditampilkan"<<endl;
        return;
    }
    q = start;
    cout<<"Doubly Link List  :"<<endl;
    while (q != NULL)
    {
        cout<<q->memo<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}
 
/*
 * Jumlah node dalam Doubly Link List
 */
void double_linked_list::count()
{  
    struct node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout<<"Jumlah node: "<<cnt<<endl;
}
 
/*
 * Reverse Doubly Link List
 */
void double_linked_list::reverse()
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
    start = p1;
    cout<<"Doubly Link List telah di reverse"<<endl; 
}