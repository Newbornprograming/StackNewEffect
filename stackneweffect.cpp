#include<iostream>
#include<conio.h>
#include<windows.h>
/*******************************************/
//deklarasi
using namespace std;
#define max 3
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};
struct paket kirim[max];
int top=1;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}
/*******************************************/
// void tambahdata(int x)
// {
//     gotoxy(20,15);cout<<"Inputkan Jenis Barang    :";
//     cin>>kirim[x].jenis_brg;
//     gotoxy(20,16);cout<<"Inputkan Berat           :";
//     cin>>kirim[x].berat;
//     gotoxy(20,17);cout<<"Inputkan Kota Tujuan     :";
//     cin>>kirim[x].kota;
// }

// void hapusdata(int x)
// {
//     gotoxy(40,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
//     gotoxy(40,13);cout<<kirim[x].jenis_brg<<" ";
//     cout<<kirim[x].berat<<" Kg ";
//     cout<<kirim[x].kota<<endl<<endl;
//     gotoxy(40,15);cout<<"Press Any Key...";
//     getch();
// }
//fungsi program stak
void push(int x)
{
    if(top>max)
    {
        gotoxy(20,20);cout<<"Sorry, Data Stak Sudah Penuh!!!";
        getch();
    }
    else
    {
        gotoxy(20,15);cout<<"Inputkan Jenis Barang    :";
        cin>>kirim[x].jenis_brg;
        gotoxy(20,16);cout<<"Inputkan Berat           :";
        cin>>kirim[x].berat;
        gotoxy(20,17);cout<<"Inputkan Kota Tujuan     :";
        cin>>kirim[x].kota;
        top++;
    }
}
void pop(int x)
{
    if(top==1)
    {
        gotoxy(20,20);cout<<"Sorry, Data Stak Kosong!!!";
        getch();
    }
    else
    {
        top--;
        gotoxy(40,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
        gotoxy(40,13);cout<<kirim[x-1].jenis_brg<<" ";
        cout<<kirim[x-1].berat<<" Kg ";
        cout<<kirim[x-1].kota<<endl<<endl;
        gotoxy(40,15);cout<<"Press Any Key...";
        getch();
    }
}
void tampildata(int x)
{
    if (top==1)
    {
        gotoxy(20,20);cout<<"Sorry, Data Stak Kosong!!!";
        getch();
    }
    else
    {
        gotoxy(40,10);cout<<"Daftar Kiriman Paket"<<endl;
        for(int a=1; a<x; a++)
        {
            gotoxy(40,19-a);
            cout<<a<<" ";
            cout<<kirim[a].jenis_brg<<" ";
            cout<<kirim[a].berat<<" kg ";
            cout<<kirim[a].kota<<endl;
        }
        gotoxy(40,20);
        cout<<"Press Any Key...";
        getch();
        /*harus Ijin --> #include<conio.h>*/
    }
}

int main()
{
    int pilih;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. Tambah Data";
        gotoxy(1,3);cout<<"2. Hapus Data Terakhir"<<endl;
        gotoxy(1,4);cout<<"3. Tampil Data"<<endl;
        gotoxy(1,5);cout<<"9. Keluar"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1)
            { /*Menambah data baru diletakan di DATAKE*/
                // tambahdata(datake);
                // datake++;
                push(top);
            }
        if(pilih==2)
            { /*Menghapus Data Terakhir (DATAKE-1*/
                // hapusdata(datake-1);
                // datake--;
                pop(top);
            }
        if(pilih==3) /*Menampilkan Data mulai
                        data ke-1 hingga DATAKE*/
            // tampildata(datake)
            tampildata(top);
            ;
    }
    while(pilih!=9);
    return 0;
}
