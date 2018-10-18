#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<iomanip.h>
void update();
void showmenu();
void display();
void addword();
void prog();

 class node
  {
    public:
    char word[20],meaning[20];
    void writeword()
    {

    cout<<"Word:";cin>>word;
    cout<<"Meaning:";gets(meaning);

    }
    }dict;

void addword()
{
ofstream ofs;
ofs.open("new1.dat",ios::binary|ios::app);
dict.writeword();
ofs.write((char*)&dict,40);
ofs.close();
}

void display()
{
ifstream ifs;
ifs.open("new1.dat",ios::in);
while(ifs.read((char*)&dict,sizeof(dict)))
 {   { cout<<"\nWord:";cout<<dict.word;
       cout<<setw(20);
      cout<<"Meaning:";puts(dict.meaning);
      delay(500);
     }
     getch();


 }
ifs.close();

}

void update()
{
char updtd[20],upmean[20];
fstream fs;
cout<<"\nPlease enter the word to updated..:";
cin>>updtd;
cout<<"\nPlease enter the meaning..:";
gets(upmean);
fs.open("new1.dat",ios::in|ios::out|ios::binary);
int updt=0;
while(fs.read((char*)&dict,sizeof(dict)))
   {
      updt=fs.tellg();
    if(strcmp(dict.word,updtd)==0)
    { fs.seekg(updt-sizeof(dict));
      strcpy(dict.meaning,upmean);
      fs.write((char*)&dict,sizeof(dict));
    }
   }
fs.close();
}

void search()
{
char search[20];
fstream fs;
cout<<"\nPlease enter the word to be searched::";
cin>>search;
fs.open("new1.dat",ios::in);
while(fs.read((char*)&dict,sizeof(dict)))
   {
    if(strcmp(dict.word,search)==0)
     { cout<<"\n**Your word is found**\n";
       cout<<"\nWORD:"<<search;
       cout<<"\nMEANING:"<<dict.meaning;
    getch();
     }
   }

}

void intro()
{
int i;
clrscr();
gotoxy(10,5);
cout<<"COMPUTER DICTIONARY\n";
gotoxy(10,6);
cout<<"___________________";
gotoxy(20,20);
cout<<"..........Done by Abhilash & Ashwin..........";
gotoxy(10,10);
cout<<"DICTIONARY LOADING.......";
for(i=0;i<50;i++)
{
 gotoxy(10+i,12);
 cout<<"þþþþ";
 gotoxy(11,13);
 cout<<2*i<<"% completed";
 delay(80);
}
clrscr();
showmenu();
}
void showmenu()
{
 cout<<"ENGLISH-ENGLISH DICTIONARY";
 cout<<"\n**************************";
 gotoxy(2,2);
 cout<<"\n\n[1].Add a word.";
 cout<<"\n[2].Find meaning.";
 cout<<"\n[3].Display all.";
 cout<<"\n[4].Update meaning.";
 cout<<"\n[5].Save and Close.\n\nEnter your Choice:";

}
void prog()
{ int choice;
  clrscr();
  showmenu();
  cin>>choice;
  switch(choice)
  {
   case 1:  addword();
	    break;
   case 2:  search();
	    break;
   case 3:  display();
	    break;
   case 4:  update();
	    break;
   case 5:  return;
   default: cout<<"WRONG INPUT...\nEnter Again";
	    delay(100);
	    prog();
	    break;
  }
  flushall();
    prog();
 }

void main()
{
 clrscr();
textbackground(4);
cout<<"ENGLISH-ENGLISH DICTIONARY";
cout<<"**************************";
intro();
prog();
getch();
}
