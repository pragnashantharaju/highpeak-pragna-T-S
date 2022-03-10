#include <stdio.h>

//my structure
struct goods{
    char name[100];
    int price;
};
typedef struct goods goods;

//sorting
void bubbleSort(goods arr[], int n) {
    int i,j;
    for(i=0;i<n;i++) {
        for(int j=n-1;j>i;j--) {
            if(arr[j].price<arr[j-1].price) {
                //swapping
                goods temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
} 

int parse(char s[]) {
    int i=0,price=0;
    while(s[i]!=':') i++;
    i+=2;
    while(s[i]!='\0') {
        price = price*10+((int)s[i]-(int)'0');
        i++;
    }
    return price;
}

int main() {
    int n=0,i,m;
    goods arr[100];
    char skip[100]; 
    //getting number of employees
    scanf("%s%s%s%d\n",skip,skip,skip,&m);
    
    //skipping the line "Goodies and Prices"
    scanf("%s%s%s\n",skip,skip,skip);
    
    //Reading till end 
    while(1) {
        int t = scanf("%[^\n]%*c",arr[n].name);
        if(t==-1) break;
        arr[n].price = parse(arr[n].name);
        n++;
    }
    
    //Sorting the input
    bubbleSort(arr,n);
    
    //Finding min difference
    int start,end,diff=arr[n-1].price-arr[0].price;
    for(i=0;i<n-m;i++) {
        if(arr[i+(m-1)].price-arr[i].price<diff) {
            diff=arr[i+m-1].price-arr[i].price;
            start=i;end=i+m-1;
        }
    }
    
    //printing answer
    printf("Goodies Selected for distribution are:\n\n");
    for(i=start;i<=end;i++) {
        printf("%s\n", arr[i].name);
    }
    printf("\nAnd the difference between the chosen goodie with highest and the lowest price is %d\n",arr[end].price-arr[start].price);
    return 0;
}