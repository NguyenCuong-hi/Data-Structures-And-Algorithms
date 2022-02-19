#include<iostream>
#include<iomanip>
#include<string.h>
#include <stdlib.h>
using namespace std;
struct Sinhvien
{
	int maSV;
	string hotenSV,lopsv;
	float dToan,dLy,dHoa;
};
typedef struct Sinhvien SV;
struct Node 
{
	Sinhvien SV;
	Node *next;
	Node *prevt;
	
};
typedef struct Node NODE;
struct DoublyList
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct DoublyList LIST;
void init_List(LIST &l)
{
	l.pHead = l.pTail =NULL;
}
NODE *init_NODE(SV s)
{
	NODE *p= new NODE();
	if(p==NULL)
	{
		cout<<"Error !";
		return NULL;
	}
	else 
	{
		p->SV = s;
		p->prevt = NULL;
		p->next = NULL;
	}
	return p; 
}
void title2()
{
	cout<<left<<setw(5)<<"STT"<<setw(20)<<"MA SINH VIEN"<<setw(32)<<"HO VA TEN"<<setw(30)<<"LOP"<<setw(12)<<"DIEM TOAN"<<setw(12)<<"DIEM LY"<<setw(12)<<"DIEM HOA"<<endl;
}
void show_NODE(NODE *p)
{
	
	cout<<left<<setw(20)<<p->SV.maSV;
	cout<<left<<setw(32)<<p->SV.hotenSV;
	cout<<left<<setw(30)<<p->SV.lopsv;
	cout<<left<<setw(12)<<p->SV.dToan;
	cout<<left<<setw(12)<<p->SV.dLy;
	cout<<left<<setw(12)<<p->SV.dHoa<<endl;

}

void show_List(LIST &l)
{
	int stt=1; 
	for(NODE *i= l.pHead; i != NULL; i= i->next)
	{
		 
		cout<<setw(5)<<stt++;
		show_NODE(i);
	}
}
//Nhap sinh vien ,dam bao ko trung
bool check_SV_cungma(LIST &l,int ma)
{
	
	for(NODE *i=l.pHead; i ; i=i->next)
	{
		if(i->SV.maSV == ma)
		{
			return true;
		}
		return false;
	}
	
}
void Input_all_data(LIST &l,SV &s)
{
	int ma ;
	cout << "\nMa Sinh Vien :";

    do
    {
    	cin>>ma;
    	if(check_SV_cungma(l,ma))
    		cout<<"Ton tai ! Nhap lai:";
    
    	
	}while(check_SV_cungma(l,ma));
	s.maSV = ma;
	cout<<"Ho Va Ten:";
	cin.ignore();
	getline(cin,s.hotenSV);
	cout<<"Lop :";
	getline(cin,s.lopsv);
	cout<<"Diem Toan:";
	cin>>s.dToan;
	cout<<"Diem Ly:";
	cin>>s.dLy;
	cout<<"Diem Hoa:";
	cin>>s.dHoa;
}
// Tim kiem sinh vien
void find_SV(LIST &l)
{
	SV s;
	int insert_ma;
	cin.ignore();
	cout<<"Nhap ma sinh vien can tim :";
	cin>>insert_ma;
	int count=1, stt=1 ;
	title2(); 
	for(NODE *i=l.pHead; i ; i= i->next)
	{
		if(insert_ma == i->SV.maSV)
		{
			cout<<setw(5)<<stt++;
			show_NODE(i);
			count=1;
			break ;
		}
		if(count==0)
		{
			cout<<"\n\tNo found Data"<<endl;
		}
		
	}
}
// Xu ly voi list de nhap danh sach
void insert_Tail(LIST &l,NODE *p )
{

 
	if(l.pHead == NULL)
	{
		l.pHead= l.pTail = p;
	}
	else
	{
		l.pTail->next = p;
		p->prevt = l.pTail;
		l.pTail = p;
	}
	
}
// Nhap du lieu/danh sach sinh vien
void input_list(LIST &l)
{
	int n,i=0,danhdau=0;
	while(true)
	{
		cout<<"Sinh vien thu "<<i+1;
		SV s;
		Input_all_data(l,s);
		NODE *p = init_NODE(s);
		insert_Tail(l,p);
		i++;
		n=i;
		cout<<"Nhan 0 de vao menu / Nhan 1 de tiep tuc:";
		cin>>danhdau;
		if(danhdau ==0)
		 break;
	}
//	int n;
//	cout<<"Nhap so luong sinh vien:";
//	cin>>n;
//	for(int i=0; i<n; i++)
//	{
//		cout<<"Sinh vien thu "<<i+1;
//		SV s;
//		Input_all_data(l,s);
//		NODE *p = init_NODE(s);
//		insert_Tail(l,p);
//		
//	}
	
}

// Xoa node dau , xoa nut cuoi va xoa bat ky de xoa 1 data sinh vien
void delete_pHead(NODE *pHead)
{
	if(pHead == NULL)
	{
		return ;
		
	}
	else
	{
		if(pHead->prevt = pHead->next)
		{
			delete pHead;
			pHead = NULL;
			return;
			
		}
		else
		{
			NODE *p = pHead;
			pHead = pHead->next;
			pHead->prevt = NULL;
			delete p;
			return;
		}
	}
}
 
void delete_pTail(NODE *pHead)
{
	LIST l; 
	if(pHead == NULL)
	{
		return ;
	}
	if(pHead->prevt = pHead->next)
	{
		delete pHead;
		pHead =NULL;
		return ;
	}
	for(NODE *i = pHead ; i ; i=i->next)
	{
		if(i->next->next == NULL)
		{
			delete i->next;
			i->next =NULL;
			break;
		}
	}
	
	
}
void delete_Sv(LIST &l)

{
	int maxoa,danhdau;
	
	do
	{
		cout<<"Nhap ma sinh vien can xoa :";
		cin>>maxoa;

	
		if(!check_SV_cungma(l,maxoa))
		{
			cout<<"\nMa sinh vien khong co ! Nhan 0 de tro ve !";
			cin>>danhdau;
		}
		if(danhdau == 0)
		break ;
		
	}
	while(!check_SV_cungma(l, maxoa));
	
	
	if(l.pHead->SV.maSV == maxoa)
	{
		delete_pHead(l.pHead);
		cout<<"\n\tRemove Success !\n";
		return;
	}
	if(l.pTail->SV.maSV == maxoa)
	{
		delete_pTail(l.pTail); // chu y cho nay 
		cout<<"\n\tRemove Success !\n";
		return;
	}
	
	NODE *pLeft = new NODE();
	NODE *pRight = new NODE();
	
	for(NODE *i=l.pHead; i !=NULL; i=i->next)
	{
		if(i->SV.maSV == maxoa)
		{
			pLeft = i->prevt;
			pRight= i->next;
			pLeft->next = pRight;
			if(pRight != NULL)
			pRight->prevt = pLeft;
			delete i;
			cout<<"\n\tRemove Success !\n";
			return;
			
		}
	}
}
// Nhap ten 1 lop va hien thi danh sach lop do
void search_class(LIST &l)
{

	string setClass;
	cin.ignore();
	cout<<"\n\t Nhap Lop :";
	getline(cin,setClass);

	int count =0,stt=1 ;
	title2();
	for(NODE *i=l.pHead; i != NULL; i=i->next)
	{
		if(i->SV.lopsv == setClass)
		{
			cout<<setw(5)<<stt++;
			show_NODE(i);
			
//			count = 1;
			return;
		}
		
	}
//		if(count == 0)
//			{
//				cout<<"\n\t LIST IS EMPTY \n";
//			}
		
		
}

// Tinh tong sinh vien co diem toan >= 5
void Sum_dToan (LIST &l)
{
	int count = 0;
	for(NODE *i= l.pHead; i!= NULL; i=i->next)
	{
		
		if(i->SV.dToan >= 5)
		{
			count++;
			
		}
		
	}
		if(count == 0)
		{
			cout<<"\n\t NO DATA\n";
		}
		else 
		{
			cout<<"\n\t Tong so sinh vien co diem toan tren 5 :"<<count;
		}
		
		
}
// Nhap ten va hien thi toan bo danh sach nhung nguoi co ten de nhap vao
void Search_Name(LIST &l)
{
	string set_Name;
	cin.ignore();
	cout<<"Tim Kiem :";
	getline(cin,set_Name);
	int count =0,stt=1;
	title2();
	for(NODE *i=l.pHead; i!=NULL; i=i->next)
	{
		if(i->SV.hotenSV == set_Name)
		{
				cout<<setw(5)<<stt++;
				show_NODE(i);
				count = 1;
		}
		
	}
	if(count == 0)
	cout<<"\n\t NO DATA \n";
 }
// Sap xep tang dan theo ma sinh vien
 void sapxep(LIST &l)
 {
 	int stt=1;
 	title2();
 	for(NODE *i=l.pHead; i !=NULL; i=i->next)
 	{
 		for(NODE *j=i->next; j!=NULL; j=j->next)
 		{
 			if(i->SV.maSV > j->SV.maSV)
 			{
 				NODE *temp = i;
 					i = j;
 					j = temp;
			 }
		 }
		  cout<<setw(5)<<stt++;
		 show_NODE(i);
		 
	 }
  } 
  // Sap xep tang dan theo toan , ly , hoa
  void sapxep_Theodiemtoan(LIST &l)
 {
 	int stt=1;
 	for(NODE *i=l.pHead; i !=NULL; i=i->next)
 	{
 		for(NODE *j=i->next; j!=NULL; j=j->next)
 		{
 			if(i->SV.dToan > j->SV.dToan)
 			{
 				NODE *temp = i;
 					i = j;
 					j = temp;
			}
		 }
		  cout<<setw(5)<<stt++;
		 show_NODE(i);
		 
	 }
  } 
  void sapxep_Theodiemly(LIST &l)
 {
 	int stt=1;
 	for(NODE *i=l.pHead; i !=NULL; i=i->next)
 	{
// 		for(NODE *j=i->next; j!=NULL; j=j->next)
// 		{
//				 if(i->SV.dLy > j->SV.dLy)
//	 			{
////	 				NODE *temp = i;
////	 					i = j;
////	 					j = temp;
//					swap(i->SV,j->SV);
//				 }
//		 }
		NODE *min = i;
		if(i->SV.dLy < min->SV.dLy)
		i = min;
		swap(i->SV , min->SV);
		 cout<<setw(5)<<stt++;
		 show_NODE(i);
  }
}
  void sapxep_Theodiemhoa(LIST &l)
 {
 	int stt=1;
 	for(NODE *i=l.pHead; i !=NULL; i=i->next)
 	{
 		for(NODE *j=i->next; j!=NULL; j=j->next)
 		{
 		
				if(i->SV.dHoa > j->SV.dHoa)
	 			{
//	 				NODE *temp = i;
//	 					i = j;
//	 					j = temp;
					swap(i,j);
				 } 
			}
		 cout<<setw(5)<<stt++;
		 show_NODE(i);
		 
	 }
  } 
  // Kiem tra cung lop hay ko
  bool check_SV_cunglop(LIST &l, string set_class)
  {
  	for(NODE *i=l.pHead; i!= NULL; i=i->next)
  	{
  		if(i->SV.lopsv == set_class)
  		{
  			return true;
		  }
		else 
		{
			return  false;
		}
  }
  // Xoa toan bo ds SV cua lop da nhap
}
  void delete_class(LIST &l)
  {
  	string set_class;
  	cout << "\nTim Kiem :";
    do
    {
    	cin>>set_class;
    	if(!check_SV_cunglop(l,set_class))
    		cout<<"Khong ton tai ! Nhap lai:";
    
    	
	}while(!check_SV_cunglop(l,set_class));
  	
  	while (check_SV_cunglop(l,set_class)) {
		
		if ( l.pHead->next == NULL) {
			if ( l.pHead->SV.lopsv == set_class)
			 {
			   delete_pHead(l.pHead);
			    cout<<"\n\t -- XOA THANH CONG !!! -- \n ";
			    return;
			 }
		 }
	     NODE *pLeft = new NODE() ;
	     NODE *pRight= new NODE();
	    for(NODE *i= l.pHead ;i != NULL ; i = i->next)
	    {
			if(l.pHead -> SV.lopsv == set_class){
	    		l.pHead = l.pHead ->next ;
	    		delete i;
	    		break;
 		    }
	    	else if (i->SV.lopsv == set_class)
	    	{
	    		pLeft=i->prevt;
		 	 	pRight=i->next;
		 	 	pLeft->next=pRight;
		 	 	if(pRight!=NULL)
		 	 	pRight->prevt=pLeft;
		 	 	delete i;
	        }
	   	}
  	}
   	cout<<"\n\tRemove Success \n ";
 }

  
void menu()
{
	cout<<right<<setw(82)<<"*** QUAN LY SINH VIEN ***"<<endl;
	cout<<setw(88)<<"		   ======================================================"<<endl;  
	cout<<setw(45)<<"|	"<<"1.HIEN THI TOAN BO DANH SACH"<<"			|"<<endl;
	cout<<setw(45)<<"|	"<<"2.TIM KIEM THEO MA SINH VIEN"<<"			|"<<endl;
	cout<<setw(45)<<"|	"<<"3.THEM SINH VIEN VAO CUOI DANH SACH"<<"		|"<<endl;
	cout<<setw(45)<<"|	"<<"4.XOA SINH VIEN"<<" 				|"<<endl;
	cout<<setw(45)<<"|	"<<"5.HIEN THI DANH SACH CUA LOP"<<"			|"<<endl;
	cout<<setw(45)<<"|	"<<"6.SO LUONG SINH VIEN DIEM TOAN TREN 5"<<"		|"<<endl;
	cout<<setw(45)<<"|	"<<"7.TIM SINH VIEN THEO TEN"<<"			|"<<endl;
	cout<<setw(45)<<"|	"<<"8.DANH SACH SINH VIEN TANG THEO MA SINH VIEN"<<"	|"<<endl;
	cout<<setw(45)<<"|	"<<"9.DANH SACH SINH VIEN TANG THEO DIEM"<<"		|"<<endl;
	cout<<setw(45)<<"|	"<<"10.XOA LOP"<<"					|"<<endl;
	cout<<setw(88)<<"		   ======================================================"<<endl; 
}
 
//void return_Menu(){
//	int selec ;
//	do {
//		cout<<" NHAP 0 DE DEN MENU : ";
//		cin>> selec;
//		if ( selec == 11)
//		system ("PAUSE"); 
//	}while ( selec!=11);
void Select_menu(LIST &l)
{
	int select;
	cout<<"NHAP LUA CHON :";
	cin>>select;
	while(select<0 || select>10)
	{
		cout<<"ERROR ! NHAP LAI :";
		cin>>select;
		
	}
	
	switch (select) 
	{
		case 1:
			{
			
			cout<<"\n\tDANH SACH SINH VIEN\n";
			title2();
			show_List(l);
			system("PAUSE"); 
			system("cls"); 
			menu(); 
			Select_menu(l);
			system("PAUSE");
			
			}break;
		case 2:
			{
			 
			find_SV(l);
			
			system("PAUSE");
			system("cls"); 
			menu(); 
			Select_menu(l);
			system("PAUSE");
			}break;
			
		case 3:
			{
			system("cls");
			cout<<"\n\r THONG TIN SINH VIEN:\n";
			SV s;
			Input_all_data(l,s);
			NODE *p = init_NODE(s);
			insert_Tail(l,p);
			cout<<"\nADD SUCCESS !\n";
			system("PAUSE"); 
			system("cls"); 
			menu(); 
			Select_menu(l);	
				
			}
			
			break;
		case 4:
			{
			
			delete_Sv(l);
			system("PAUSE");	
			system("cls"); 
			menu(); 
			Select_menu(l);
			}
			break;
		case 5:
			{
			search_class(l);
			system("PAUSE"); 
			system("cls");	
			menu(); 
			Select_menu(l);
			}break;
			
		case 6:
			{
			system("cls");
			Sum_dToan (l);
			system("PAUSE");
			system("cls"); 
			menu(); 
			Select_menu(l);	
			}
		
			break;
		case 7:
			{
			system("cls");
			Search_Name(l);	
			system("PAUSE");
			system("cls"); 
			menu(); 
			Select_menu(l);
			}
			
			break;
		case 8:
			{
			system("cls");
			sapxep(l);
			system("PAUSE");
			system("cls"); 
			menu(); 
			Select_menu(l);
			}
			break;
		case 9:
			{
			system("cls");
			cout<<"\n\t SAP XEP TANG DAN THEO DIEM TOAN\n";
			title2();
			sapxep_Theodiemtoan(l);
			cout<<"\n\t SAP XEP TANG DAN THEO DIEM LY\n";
			title2();
			sapxep_Theodiemly(l); 
			cout<<"\n\t SAP XEP TANG DAN THEO DIEM HOA\n";
			title2();
			sapxep_Theodiemhoa(l);
			system("PAUSE");	
			system("cls"); 
			menu(); 
			Select_menu(l);
			}
			break;
			
		case 10:
			{
			system("cls");
			delete_class(l);
			cout<<"\n\tDANH SACH SAU KHI XOA\n";
			title2();
			show_List(l);
			system("PAUSE");
			system("cls"); 
			menu(); 
			Select_menu(l);
			}
			break;
		default:
			{
			system("cls");
			cout<<"\n\tTHOAT\n";
			}
			
			break;
	}
	
}

main()
{
	LIST l;
	init_List(l);
	//return_Menu();
	input_list(l); 
	menu(); 
	Select_menu(l);
	system("PAUSE");
	
}

