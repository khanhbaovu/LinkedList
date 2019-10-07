#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

struct canbo {
  long maso;
  char ten[8];
};

struct node {
  canbo info;
  node *next;
};

struct danhsach {
  node *pfirst;
  node *plast;
};

void khoitao(danhsach &d) {
  d.pfirst = d.plast = NULL;
}

int ktrong(danhsach d) {
  if(d.pfirst == NULL || d.plast == NULL) {
    return 1;
  }
  return 0 ;
}

void themdau(danhsach &d, canbo x) {
  node *p = new node;
  p->info = x;
  if(d.pfirst == NULL) {
    d.pfirst = d.plast = p;
  }
  else {
    p->next = d.pfirst;
    d.pfirst = p;
  }
}

void themcuoi(danhsach &d, canbo x) {
  node *p = new node;
  p->info = x;
  if(d.plast == NULL) {
    d.pfirst = d.plast = p;
  }
  else {
    d.plast->next = p;
    d.plast = p;
  }
}

void themtruock(danhsach &d, canbo x, int k) {
  node *p = new node;
  p->info = x;
  node *y = d.pfirst;
  node *z;
  int i = 1;
  while(i<k) {
    z = y;
    y = y->next;
    i++;
  }
  if(y == d.pfirst) {
    themdau(d, x);
    return;
  }
  p->next = y;
  z->next = p;
}

void themsauk(danhsach &d, canbo x, int k) {
  node *p = new node;
  p->info = x;
  node *y = d.pfirst;
  node *z;
  int i = 1;
  while(i<k+1) {
    z = y;
    y = y->next;
    i++;
  }
  if(z == d.plast) {
    themcuoi(d,x);
    return;
  }
  p->next = y;
  z->next = p;
}

void xoadau(danhsach &d) {
  node *p = d.pfirst;
  d.pfirst = d.pfirst->next;
  delete p;
}

void xoacuoi(danhsach &d) {
  node *p;
  for(node *k = d.pfirst; k!=NULL; k = k->next) {
    if(k == d.plast) {
        d.plast = p;

        d.plast->next = NULL;
        delete k;
    }
    p = k;
  }
}

void xoa(danhsach &d) {
  node *p;
  while(d.pfirst != NULL) {
    p = d.pfirst;

   d.pfirst = d.pfirst->next;
    delete p;
  }
  d.plast = NULL;
}

void xoak(danhsach &d, int k) {
  node *x = d.pfirst;
  node *y;
  node *z;
  int i = 1;
  while(i<k+1) {
    z = y;
    y = x;
    x = x->next;
    i++;
  }
  if(y == d.pfirst || y == d.plast) {
    xoa(d);
    return;
  }
  z->next = x;
  delete y;
}

void xem(danhsach d) {
  if(d.pfirst == NULL || d.plast == NULL) {
    cout<<"DANH SACH RONG"<<endl;
  }
  for(node *k = d.pfirst; k!=NULL; k = k->next) {
    cout<<"TEN CAN BO: "<<k->info.ten<<endl;
    cout<<"MA SO: "<<k->info.maso<<endl;
  }
}

void daonguoc(danhsach &d) {
  node *x;
  node *y;
  node *z;
  x = d.pfirst;
  y = x->next;
  z = y->next;

  d.plast = x;
  x->next = NULL;
  y->next = x;
  while(z!=NULL ) {
    x = y;
    y = z;
    z = z->next;
    y->next = x;
  }
  d.pfirst = y;
}

void doctep(danhsach &d) {
  ifstream input;
  input.open("input.txt", ios::in);
  int n;
  input>>n;
  canbo x;
  for(int i=0; i<n; i++) {
    fflush(stdin);
    input.getline(x.ten, 8);
    input>>x.maso;
    themcuoi(d,x);
  }
  input.close();
}

void ghitep(danhsach d) {
  ofstream output;
  output.open("output.txt", ios::out);
  if(d.pfirst == NULL || d.plast == NULL) {
    output<<"DANH SACH RONG";
  }
  for(node *k = d.pfirst; k!=NULL; k = k->next) {
    output<<k->info.ten<<" "<<k->info.maso<<endl;
  }
  output.close();
}

void menu(int &m) {
  cout<<"DANH SACH CAN BO"<<endl;
  cout<<"1.THEM CAN BO VAO CUOI DANH SACH"<<endl;
  cout<<"2.THEM CAN BO VAO DAU DANH SACH"<<endl;
  cout<<"3.THEM CAN BO VAO TRUOC VI TRI YEU CAU"<<endl;
  cout<<"4.THEM CAN BO VAO SAO VI TRI YEU CAU"<<endl;
  cout<<"5.KIEM TRA DANH SACH RONG"<<endl;
  cout<<"6.XOA DAU DANH SACH"<<endl;
  cout<<"7.XOA CUOI DANH SACH"<<endl;
  cout<<"8.XOA CAN BO VI TRI YEU CAU"<<endl;
  cout<<"9.XOA TOAN BO DANH SACH"<<endl;
  cout<<"10. DAO NGUOC DANH SACH"<<endl;
  cout<<"11.XEM DANH SACH"<<endl;
  cout<<"BAN MUON LAM GI: ";
  cin>>m;
  cout<<"-------------------------------------"<<endl;
}

void taocanbo(canbo &x, int m, int &k) {
  cout<<"NHAP TEN: ";
  fflush(stdin);
  cin.getline(x.ten, 8);
  cout<<"NHAP MA SO: ";
  cin>>x.maso;
  if(m == 3 || m == 4 || m==8) {
    cout<<"VI TRI: ";
    cin>>k;
  }
}
int main()
{
    danhsach ds;
    canbo cb;
    int m, k;
    khoitao(ds);
    while(1) {
    menu(m);
    if(m==0) {
        break;
    }
    switch (m){
      case 1:
        {
            taocanbo(cb,m, k);
            themcuoi(ds, cb);
            cout<<"----------------------"<<endl;
            break;
        }
      case 2:
        {
            taocanbo(cb,m,k);
            themdau(ds,cb);
            break;
        }
      case 3:
        {
            taocanbo(cb, m,k);
            themtruock(ds,cb,k);
            cout<<"-----------------------"<<endl;
            break;
        }
      case 4:
        {
            taocanbo(cb,m,k);
            themsauk(ds,cb,k);
            cout<<"-----------------------"<<endl;
            break;
        }
      case 5:
        {
            if(ktrong(ds)==1){
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
            cout<<"-----------------------"<<endl;
            break;
        }
      case 6:
        {
            xoadau(ds);
            cout<<"-----------------------"<<endl;
            break;
        }
      case 7:
        {
            xoacuoi(ds);
            cout<<"-----------------------"<<endl;
            break;
        }
      case 8:
        {
            cout<<"VI TRI: ";
            cin>>k;
            xoak(ds,k);
            cout<<"-----------------------"<<endl;
            break;
        }
      case 9:
        {
            xoa(ds);
            cout<<"-----------------------"<<endl;
            break;
        }
      case 10:
        {
            daonguoc(ds);
            cout<<"-----------------------"<<endl;
            break;
        }
      case 11:
        {
            xem(ds);
            cout<<"-----------------------"<<endl;
            break;
        }
      case 0:
        {
            break;
        }
    }
    }
    node *khanh = new node;
    cout<<khanh->next<<endl;
    khanh->next = NULL;
    cout<<khanh->next;
    return 0;
}
