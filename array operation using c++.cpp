#include<iostream>
#include<stdlib.h>
using namespace std;
   class array
   {
   	private:
   	int *a;
   	int size;
   	int length;
   	void swap(int *x, int *y);
   	
   	public:
   		array()
   		{
   			size=10;
   			length=0;
   			a=new int[size];
		}
		array(int sz)
		{
			size=sz;
			length=0;
			a=new int[size];
		}
		~array()
		{
			delete []a;
		}
		void display();
        void add_append(int x);
        void insert(int index,int x);
        int Delete(int index);
        int linear(int key);
        int binary(int key);
        int get(int index);
        void set(int index,int x);
        void max_min();
        void left_shift_rot();
        void right_shift_rot();
        int sum();
        float avg();
        void reverse();
        void insert_sort(int x);
        int sorted_array();
        void arranging_array();
        array merge(array arr2);
        array Union(array arr2);
        array difference(array arr2);
        array intersection(array arr2);
   };
   
   void array::swap(int *x,int *y)
   {
   	int temp=*x;
   	*x=*y;
   	*y=temp;
   }
   void array::display()
   {
   	for(int i=0;i<length;i++)
   	    cout<<a[i]<<" ";
   	cout<<endl;
   }
   
   void array::add_append(int x)
   {
   	if(length<size)
   	a[length]=x;
   	length++;
   }
   
   void array::insert(int index,int x)
   {
   	if(index>=0&&index<=length){
	   
   	for(int i=length;i>index;i--)
   	{
   		a[i]=a[i-1];
	}
	a[index]=x;
	length++;
    }
   }
   
   int array::Delete(int index)
   {
   	int x=0;
   	if(index>=0&&index<=length)
   	{
   		x=a[index];
   		for(int i=index;i<length-1;i++)
   		{
   			a[i]=a[i+1];
		}
		length--;
		return x;
	}
	return 0;
   }
   
   int array::linear(int key)
   {
   	for(int i=0;i<length;i++)
   	{
   		if(key==a[i])
   		{   
   		    swap(&a[i],&a[0]);
   			return i;
		}
	   }
	   return -1;
   }
   
   int array:: binary(int key)
   {
   	int l=0;
   	int h=length-1;
   	int mid;
   	if(l<=h)
   	{
   		mid=(l+h)/2;
   		if(key==a[mid])
   		{
   			return mid;
		}
		else if(key<a[mid])
		    h=mid-1;
		else
		    l=mid+1;
	}
	 return -1;  
   }
   
   int array::get(int index)
   {
   	if(index>=0&&index<length)
   	    return a[index];
   	else
	   return -1;    
   }
   
   void array::set(int index,int x)
   {
   	if(index>=0&&index<length)
   	    a[index]=x;
   }
   
void array::max_min()
   {
   	int max=a[0];
   	int min=a[0];
   	for(int i=1;i<length;i++)
   	{
   		if(a[i]<min)
   		{
   			min=a[i];
		}
		else if(a[i]>max)
		{
			max=a[i];
		}
	}
	cout<<"Max: "<<max<<endl;
	cout<<"Min: "<<min<<endl;
   }
   void array::reverse()
   {
   	int i=0;
   	int j=length-1;
   	for(;i<j;i++,j--)
   	swap(&a[i],&a[j]);
   }
   
   int array:: sum( )
   {
   	int total=0;
   	for(int i=0;i<length;i++)
   	{
   		total+=a[i];
	}
	return total;  
   }
   
   float array:: avg()
   {
   	float total=0;
   	for(int i=0;i<length;i++)
   	{
   		total+=a[i];
	}
	return (float)total/length;
   }
   
void array::left_shift_rot()
{
		int x=a[0];
		for(int i=0;i<length;i++)
		{
			a[i]=a[i+1];
		}
		a[length-1]=x;			
}

void array::right_shift_rot()
{
		int y=a[length-1];
		for(int i=length-1;i>=0;i--)
		{
			a[i]=a[i-1];
		}
		a[0]=y;	
}

void array::insert_sort(int x)
{
	int i=length-1;
	if(length==size)
	    return;
	while(i>=0&&a[i]>x)
	{
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=x;
	length++;    	
}

int array::sorted_array()
{
	for(int i=0;i<length-1;i++)
	{
		if(a[i]>a[i+1])
		    return 0;
		
	}
	 return 1;    
}

void array:: arranging_array()
{
	int i=0;
	int j=length-1;
	while(i<j)
	{
		while(a[i]<0)
		{
			i++;
		}
		while(a[j]>0)
		{
			j--;
		}
		if(i<j)
		{
			swap(&a[i],&a[j]);
		}
	}
}

array array::merge(array arr2)
{
	int i,j,k;
	i=j=k=0;
	array arr3=new array(length+arr2.length);

	while(i<length && j<arr2.length)
	{
		if(a[i]<arr2.a[j])
		   arr3->a[k++]=a[i++];
		else
		    arr3->a[k++]=arr2.a[j++];   
	}
	for(;i<length;i++)
	    arr3->a[k++]=a[i];
	for(;j<arr2.length;j++)
	    arr3->a[k++]=arr2.a[j];
     arr3->length = length + arr2.length;
    
    return arr3;
}
array array:: Union(array arr2)
{
   	int i,j,k;
	i=j=k=0;
	
	array arr3 = new array(length+arr2.length);
	while(i<length && j<arr2.length)
	{
		if(a[i]<arr2.a[j])
		   arr3->a[k++]=a[i++];
		else if(arr2.a[j]<a[i])
		    arr3->a[k++]=arr2.a[j++];
		else
		{
			arr3->a[k++]=a[i++];
			j++;
		}	   
	}
	for(;i<length;i++)
	    arr3->a[k++]=a[i];
	for(;j<arr2.length;j++)
	    arr3->a[k++]=arr2.a[j];
    arr3->length=k;
   
    return arr3;	
}

array array::intersection(array arr2)
{
   	int i,j,k;
	i=j=k=0;
	
	array arr3 = new array(length+arr2.length);
	while(i<length && j<arr2.length)
	{
		if(a[i]<arr2.a[j])
		   i++;
		else if(arr2.a[j]<a[i])
		    j++;
		else if(a[i]==arr2.a[j])
		{
			arr3->a[k++]=a[i++];
			j++;
		}	   
	}

    arr3->length=k;
   
    return arr3;	
}

array array:: difference(array arr2)
{
   	int i,j,k;
	i=j=k=0;
	
	array arr3 =new array(length+arr2.length);
	while(i<length && j<arr2.length)
	{
		if(a[i]<arr2.a[j])
		   arr3->a[k++]=a[i++];
		else if(arr2.a[j]<a[i])
		    j++;
		else
		{
			i++;
			j++;
		}	   
	}
	for(;i<length;i++)
	    arr3->a[k++]=a[i];

    arr3->length=k;
 
    return arr3;	
}
   
   int main()
   {
   	
   	int x,index,ch;
   	char search;
   	int sz;
   	cout<<"Array size: ";
   	cin>>sz;
   	array arr1(sz);
 
    array arr2(5);
    cout << "Enter elements for arr2: ";
    for (int i = 0; i < 5; i++)
    {
        int elem;
        cin >> elem;
        arr2.add_append(elem);
    }
    array arr3(10);
    array arr4(10);
    array arr5(10);
    array arr6(10);

	
	
   	
   	do{
   		cout<<" MENU "<<endl<<"1. Insert"<<endl<<"2. Append"<<endl
   		<<"3. Delete"<<endl<<"4. Search"<<endl<<"5. Get"<<endl
   		<<"6. Set"<<endl<<"7. MaxMin"<<endl<<"8. Reverse"<<endl
   		<<"9. left_shift_rotate"<<endl<<"10. right_shift_rotate"<<endl
   		<<"11. Sum"<<endl<<"12. Avg"<<endl<<"13. Insert_sorted"<<endl
   		<<"14. SortedArray"<<endl<<"15. ArrangingArray"<<endl
   		<<"16. Merge Arrays"<<endl<<"17. Union"<<endl<<"18. Intersection"<<endl<<"19. Difference"<<endl
   		<<"20. Display"<<endl<<"21. Exit"<<endl;
   		
   		cout<<"Enter your choice: ";
   		cin>>ch;
   		
   		switch(ch)
   		{
   			case 1:cout<<"Enter the Element and Index: ";
   			        cin>>x>>index;
   			        arr1.insert(index,x);
   			        break;
   			case 2:cout<<"Enter the Element: ";
   			        cin>>x;
   			        arr1.add_append(x);
   			        break;
   			case 3:cout<<"Enter the index: ";
			        cin>>index;
					x=arr1.Delete(index);
					cout<<"Deleted element is: "<<x<<endl;
					break;
			case 4:cout<<"Enter the Element To search: ";
			        cin>>x;
			        cout<<"Enter type of search 'l' or 'b': ";
			        cin>>search;
			        if(search=='l')
			            cout<<arr1.linear(x);
			        else if(search=='b')
					    cout<<arr1.binary(x);    
					else
					    cout<<"Invalid Input.";
					break;
			case 5:cout<<"Enter the Index: ";
			        cin>>index;
					cout<<arr1.get(index);
					break;
		    case 6:cout<<"Enter the Element and Index: ";
			        cin>>x>>index;
					arr1.set(index,x);
					break;
		    case 7:arr1.max_min();
				   break;
			case 8:arr1.reverse();
			       break;	   
		    case 9:arr1.left_shift_rot();
			       break;
		    case 10:arr1.right_shift_rot();
			        break;
			case 11:cout<<"Sum is "<<arr1.sum()<<endl;
			        break;
			case 12:cout<<"Avg is "<<arr1.avg()<<endl;
			        break;
			case 13:cout<<"Enter the element: ";
			        cin>>x;
					arr1.insert_sort(x);
					break;
			case 14:arr1.sorted_array();
			        if(0)
			          cout<<"False"<<endl;
			        else
					  cout<<"True"<<endl;  
			        break;
			case 15:arr1.arranging_array();
			        break;
			case 16:arr3=arr1.merge(arr2);
			        arr3.display();
			        break;
			case 17:arr4=arr1.Union(arr2);
			        arr4.display();
			        break;
			case 18:arr5=arr1.intersection(arr2);
			        arr5.display();
			        break;
			case 19:arr6=arr1.difference(arr2);
			        arr6.display();
			        break;        
		    case 20:arr1.display();
			        break;															   		   											        
		   }
		    
	   }
		   while(ch<21);
   	
   	      return 0;
   	
   }