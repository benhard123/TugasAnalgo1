#include <iostream>
#include <conio.h>

using namespace std;

struct human{
    string name;
    bool proposed=false;
    human* next;
};

struct men{
    string man;
    bool engaged=false;
    human* woman;
    men* next;
};

struct women{
    string woman;
    bool engaged=false;
    human* man;
    women* next;
};

struct match{
    string man;
    string woman;
    match* tail;
    match* next;
};


typedef men* mon;
typedef women* womon;

void proses(match*& hasil,mon& kosong, mon& tail, mon& test1, womon& w, mon& m){
        womon test2=w;
        human* test3;
        test3=test1->woman;
        while(test3->proposed && test3->next!=NULL){
            test3=test3->next;
        }
        while(test2!=NULL){
            if(test2->woman.compare(test3->name)==0){
                break;
            }
            else{
                test2=test2->next;
            }
        }
        if (!test2->engaged){
            if(hasil==NULL){
                hasil=new match;
                hasil->man=test1->man;
                hasil->woman=test2->woman;
                cout<<hasil->man<<endl;
                cout<<hasil->woman<<endl;
                hasil->tail=hasil;
                hasil->next=NULL;
            }
            else{
                match* test5=new match;
                test5->man=test1->man;
                test5->woman=test2->woman;
                cout<<test5->man<<endl;
                cout<<test5->woman<<endl;
                hasil->tail->next=test5;
                hasil->tail=test5;
                hasil->tail->next=NULL;
            }
            test1->engaged=true;
            test2->engaged=true;
            test3->proposed=true;
            test1=test1->next;
        }
        else{
            match* test5=hasil;
            human* test6=test2->man;
            mon test7=m;
            while(test5!=NULL){
                if(test5->woman.compare(test2->woman)==0){
                    break;
                }
                else{
                    test5=test5->next;
                }
            }
            while(test6!=NULL){
                if(test5->man.compare(test6->name)==0){
                    test3->proposed=true;
                    if(kosong==NULL){
                        kosong=new men;
                        kosong->man=test1->man;
                        kosong->woman=test1->woman;
                        test1=test1->next;
                        tail=kosong;
                        kosong->next=NULL;
                    }
                    else{
                        tail->next=new men;
                        tail->next->man=test1->man;
                        tail->next->woman=test1->woman;
                        tail=tail->next;
                        cout<<tail->man<<" still free"<<endl;
                        test1=test1->next;
                        tail->next=NULL;
                    }
                    break;
                }
                else if(test1->man.compare(test6->name)==0){
                    while(test7!=NULL){
                        if(test7->man.compare(test5->man)==0){
                            break;
                        }
                        else{
                            test7=test7->next;
                        }
                    }
                    test5->man=test1->man;
                    cout<<test5->man<<endl;
                    cout<<test5->woman<<endl;
                    test1->engaged=true;
                    test3->proposed=true;
                    test7->engaged=false;
                    if(kosong==NULL){
                        kosong=new men;
                        kosong->man=test7->man;
                        kosong->woman=test7->woman;
                        cout<<kosong->man<<" become free"<<endl;
                        tail=kosong;
                        kosong->next=NULL;
                    }
                    else{
                        tail->next=new men;
                        tail->next->man=test7->man;
                        tail->next->woman=test7->woman;
                        tail=tail->next;
                        cout<<tail->man<<" become free"<<endl;
                        tail->next=NULL;
                    }
                    test1=test1->next;
                    break;
                }
                test6=test6->next;
            }
        }
}

match* matching(mon& m, womon& w){
    match* hasil=NULL;
    mon kosong=NULL;
    mon tail=NULL;
    mon test1=m;
    while(kosong!=NULL || test1!=NULL){
        if(kosong==NULL){
            proses(hasil,kosong,tail,test1,w,m);
        }
        else{
            proses(hasil,kosong,tail,kosong,w,m);
        }
        // getch();
    }
    return hasil;
}

int main(){

    mon m;
    womon w;

    m=new men;
    m->man="Victor";
    m->woman=new human;
    m->woman->name="Bertha";
    m->woman->next=new human;
    m->woman->next->name="Amy";
    m->woman->next->next=new human;
    m->woman->next->next->name="Diane";
    m->woman->next->next->next=new human;
    m->woman->next->next->next->name="Erika";
    m->woman->next->next->next->next=new human;
    m->woman->next->next->next->next->name="Clare";
    m->woman->next->next->next->next->next=NULL;

    m->next=new men;
    m->next->man="Wyatt";
    m->next->woman=new human;
    m->next->woman->name="Diane";
    m->next->woman->next=new human;
    m->next->woman->next->name="Bertha";
    m->next->woman->next->next=new human;
    m->next->woman->next->next->name="Amy";
    m->next->woman->next->next->next=new human;
    m->next->woman->next->next->next->name="Clare";
    m->next->woman->next->next->next->next=new human;
    m->next->woman->next->next->next->next->name="Erika";
    m->next->woman->next->next->next->next->next=NULL;
    
    m->next->next=new men;
    m->next->next->man="Xavier";
    m->next->next->woman=new human;
    m->next->next->woman->name="Bertha";
    m->next->next->woman->next=new human;
    m->next->next->woman->next->name="Erika";
    m->next->next->woman->next->next=new human;
    m->next->next->woman->next->next->name="Clare";
    m->next->next->woman->next->next->next=new human;
    m->next->next->woman->next->next->next->name="Diane";
    m->next->next->woman->next->next->next->next=new human;
    m->next->next->woman->next->next->next->next->name="Amy";
    m->next->next->woman->next->next->next->next->next=NULL;
    
    m->next->next->next=new men;
    m->next->next->next->man="Yancey";
    m->next->next->next->woman=new human;
    m->next->next->next->woman->name="Amy";
    m->next->next->next->woman->next=new human;
    m->next->next->next->woman->next->name="Diane";
    m->next->next->next->woman->next->next=new human;
    m->next->next->next->woman->next->next->name="Clare";
    m->next->next->next->woman->next->next->next=new human;
    m->next->next->next->woman->next->next->next->name="Bertha";
    m->next->next->next->woman->next->next->next->next=new human;
    m->next->next->next->woman->next->next->next->next->name="Erika";
    m->next->next->next->woman->next->next->next->next->next=NULL;
    
    m->next->next->next->next=new men;
    m->next->next->next->next->man="Zeus";
    m->next->next->next->next->woman=new human;
    m->next->next->next->next->woman->name="Bertha";
    m->next->next->next->next->woman->next=new human;
    m->next->next->next->next->woman->next->name="Diane";
    m->next->next->next->next->woman->next->next=new human;
    m->next->next->next->next->woman->next->next->name="Amy";
    m->next->next->next->next->woman->next->next->next=new human;
    m->next->next->next->next->woman->next->next->next->name="Erika";
    m->next->next->next->next->woman->next->next->next->next=new human;
    m->next->next->next->next->woman->next->next->next->next->name="Clare";
    m->next->next->next->next->woman->next->next->next->next->next=NULL;

    w=new women;
    w->woman="Amy";
    w->man=new human;
    w->man->name="Zeus";
    w->man->next=new human;
    w->man->next->name="Victor";
    w->man->next->next=new human;
    w->man->next->next->name="Wyatt";
    w->man->next->next->next=new human;
    w->man->next->next->next->name="Yancey";
    w->man->next->next->next->next=new human;
    w->man->next->next->next->next->name="Xavier";
    w->man->next->next->next->next->next=NULL;

    w->next=new women;
    w->next->woman="Bertha";
    w->next->man=new human;
    w->next->man->name="Xavier";
    w->next->man->next=new human;
    w->next->man->next->name="Wyatt";
    w->next->man->next->next=new human;
    w->next->man->next->next->name="Yancey";
    w->next->man->next->next->next=new human;
    w->next->man->next->next->next->name="Victor";
    w->next->man->next->next->next->next=new human;
    w->next->man->next->next->next->next->name="Zeus";
    w->next->man->next->next->next->next->next=NULL;
    
    w->next->next=new women;
    w->next->next->woman="Clare";
    w->next->next->man=new human;
    w->next->next->man->name="Wyatt";
    w->next->next->man->next=new human;
    w->next->next->man->next->name="Xavier";
    w->next->next->man->next->next=new human;
    w->next->next->man->next->next->name="Yancey";
    w->next->next->man->next->next->next=new human;
    w->next->next->man->next->next->next->name="Zeus";
    w->next->next->man->next->next->next->next=new human;
    w->next->next->man->next->next->next->next->name="Victor";
    w->next->next->man->next->next->next->next->next=NULL;
    
    w->next->next->next=new women;
    w->next->next->next->woman="Diane";
    w->next->next->next->man=new human;
    w->next->next->next->man->name="Victor";
    w->next->next->next->man->next=new human;
    w->next->next->next->man->next->name="Zeus";
    w->next->next->next->man->next->next=new human;
    w->next->next->next->man->next->next->name="Yancey";
    w->next->next->next->man->next->next->next=new human;
    w->next->next->next->man->next->next->next->name="Xavier";
    w->next->next->next->man->next->next->next->next=new human;
    w->next->next->next->man->next->next->next->next->name="Wyatt";
    w->next->next->next->man->next->next->next->next->next=NULL;

    w->next->next->next->next=new women;
    w->next->next->next->next->woman="Erika";
    w->next->next->next->next->man=new human;
    w->next->next->next->next->man->name="Yancey";
    w->next->next->next->next->man->next=new human;
    w->next->next->next->next->man->next->name="Wyatt";
    w->next->next->next->next->man->next->next=new human;
    w->next->next->next->next->man->next->next->name="Zeus";
    w->next->next->next->next->man->next->next->next=new human;
    w->next->next->next->next->man->next->next->next->name="Xavier";
    w->next->next->next->next->man->next->next->next->next=new human;
    w->next->next->next->next->man->next->next->next->next->name="Victor";
    w->next->next->next->next->man->next->next->next->next->next=NULL;

    match* ok=matching(m,w);
    match* test=ok;
    cout<<"\n";
    while(test!=NULL){
        if(test->next==NULL){
            cout<<"("<<test->man<<","<<test->woman<<")";
        }
        else{
            cout<<"("<<test->man<<","<<test->woman<<"), ";
        }
        test=test->next;
    }
    
    getch();
    return 0;
}