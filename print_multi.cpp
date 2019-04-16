/******************************************************************************
Author:
        Ashish Kumar Goyal

Description:
        Wanna print some pages in booklet form with multiple pages in
        a single A4 page, to be cut and made into a proper booklet.
        I/p-    ranges of pages [eg- "1,8 - 26, 35-46, 54-57"]
                grid size: m x n [m rows and n(even) columns per page]
                page number of blank page
                vertical / horizontal cut 
                [fold is opposite as cut between 2 pairs..]
            
        O/p-    Comma seperated page numbers to be used in print argument
                for proper booklet print with horizontal page ordering.

*******************************************************************************/

#include <iostream>
#define MAX_PAGE_LIMIT 100
using namespace std;

#define DEBUG

#ifndef DEBUG
#define DEBUG_P(x,y)
#else
#define DEBUG_P(x, y) cout<<x<<y;
#endif

void fill(int *a, int x, int y){
    static int i = 0;
    for(int ic=x; ic<=y; ic++) a[i++]= ic;
}

//TODO: implement this
bool parse_str(char *str, int* const pages){
    
    char *p = str;
    int i=0;
    int temp;
    while(p!=0){
        
        p++;
    }
    
    return true;
}

//stubs
int initialize_a(int *a){
    //1,1,8-26,35-49,54-57
    fill(a,1,1);
    fill(a,1,1);
    fill(a,8,26);
    fill(a,35,49);
    fill(a,54,57);
    return 40;
}
 void print_a(int *a, int size){
    for(int i=0;i<size;i++) cout<<a[i]<<",";
 }

int main()
{
    int a[MAX_PAGE_LIMIT]={0};
    char range_str[100] = {0};
    int m,n;
    int blank = 1, cut=1;
    //get the range and parse
    cout<<"Enter the range:"<<endl;
    cin.get(range_str, 100);
    DEBUG_P("Got range: ", range_str);
    
    //grid size:
    cout<<"grid size[m ,n(even)]: "<<endl;
    cin>>m>>n;
    //if(n%2!=0) {cout<<"n value not even!Exiting..."; return;}
    DEBUG_P("Grid size: m=", m);
    DEBUG_P("n: ", n);
    
    //Blank page:
    cout<<"pagenumber for blank page: "<<endl;
    //cin>>blank;
    DEBUG_P("Blank page: ", blank);
    
    //cut:
    cout<<"cut? 1:horizontal 2:vertical - "<<endl;
    //cin>>cut;
    DEBUG_P("Cut: ", cut);
    
    //output
    //parse_str(range_str,a);
    int total = initialize_a(a);
    print_a(a,total);
    
    
    //main_logic
    
    //firstly make total pages divisible by 4. add blanks.
    int rem = total%4;
    total+=rem;
    while(rem-- > 0) fill(a,blank,blank);
    
    //now holding 1 page at x, next page would be at x+m*n or x-m*n+n.
    int last=total-1, first=0;
    int ar[total]= {0};
    int id=0;
    //pair would be n 1 2 n-1....
    //just build for 2x2 as of now..
    int k = 1;
    while(k<=total/(m*n)){
        ar[id] = a[last];
        ar[id+1] = a[first];
        ar[id+1+(m-1)*n + 1]= a[first+1];
        ar[id+1+(m-1)*n + 2]= a[last-1];
        first+=2;
        last-=2;
        id = id + n;
        if(ar[id]!=0){ id+=m*n; k+=2;}
    }
    
    cout<<endl;
    print_a(ar,total);
    //string res;
    //cout<<endl<<res<<endl;
    cout<<"Hello World";
    return 0;
}
