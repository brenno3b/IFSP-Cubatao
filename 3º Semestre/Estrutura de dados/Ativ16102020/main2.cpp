#include <iostream>
using namespace std;

int divisao(int a[], int l, int u){
	int v;
	int i;
	int j;
	int temp;
	v=a[l];
	i=l;
	j=u+1;
	
	do{
		do
			i++;
		while(a[i]<v && i<=u);
		do
			j--;
		while(v<a[j]);
		
		if(i<j){
		temp =a[i];
		a[i]=a[j];
		a[j]=temp;
		}
	}while(i<j);
	
	a[l]=a[j];
	a[j]=v;
	
	return(j);
}

void quick_sort(int a[], int l, int u){
	int j;
	if(l<u){
		j=divisao(a,l,u);
		quick_sort(a, l, j-1);
		quick_sort(a, j+1, u);
	}
}



void print(int t, int *a){
	int i;
	for(i=0;i<t;i++){
		cout << "Elemento: " << i << "=" << a[i] << endl;
		
	}
	
	cout << "----------" << endl;
}

int main(int argc, char** argv)
{
	int v[8] = {26, 49, 38, 13, 58, 87, 34, 93};
	
	print(8, v);
	quick_sort(v,0,8);
	for(int i=0;i<8;i++){
	cout << v[i] << ", ";
	}
	
	return 0;
}