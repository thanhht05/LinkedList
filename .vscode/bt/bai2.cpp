#include <iostream>
#include <string>
using namespace std;

struct NutM
{
    int maM;
    NutM *Tiep;
};
struct NutGV
{
    string maGV;
    string hoTenGV;
    NutGV *Down;
    NutM *DSM;
};
NutGV *first;


NutGV * addNutGV(string maGV, string ht){
    NutGV * newNutGv = new NutGV();
    newNutGv->maGV=maGV;
    newNutGv->hoTenGV=ht;
    newNutGv->DSM=NULL;
    newNutGv->Down=NULL;
    return newNutGv;
}
void inLast(NutGV * &first, string maGV, string ht, ){
    NutGV * newNutGV=addNutGV(maGV, ht);
    if(first==NULL){
        first=newNutGV;
    }
    NutGV * cur=first;
    while(cur->Down!=NULL){
        cur=cur->Down;
    }
    cur->Down=newNutGV;
}
NutGV *addr(NutGV *first, string mgv)
{
    if (first == NULL)
    {
        return NULL;
    }
    NutGV *f = first;
    while (f != NULL)
    {
        if (f->maGV == mgv)
        {
            return f;
        }
        f = f->Down;
    }
    return NULL;
}
int main()

{
}