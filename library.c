//including necessary libraries.
#include <stdio.h>
#include <string.h>

//creating a structure to act as a database to store 3 books.
struct Library{
	int id;
	char author[50];
	int iss,ret,cnt;
}lib[3];

//declaring the main function
int main(){
	int n;
    
    //inputs for the 3 books.
	for(int i=0; i<3; i++){
		printf("Enter the book ID:");
		scanf("%d",&lib[i].id);
		printf("Enter the author of the book:");
		scanf("%s",lib[i].author);
		lib[i].iss=0;
		lib[i].ret=0;
		lib[i].cnt=0;
	}
    
    //letting the user choose the option.
	while(n!=3){
        printf("1.Issue\n2.Return\n3.Exit\n");
		scanf("%d",&n);
        //updating the availability of the book.
		if(n==1){
			int id1;
			printf("Enter the ID of the book:");
			scanf("%d",&id1);
			for(int k=0; k<3; k++){
				if(id1==lib[k].id && lib[k].iss==0){
					lib[k].iss=1;
					lib[k].ret=0;
					lib[k].cnt+=1;
                    printf("Book issued\n");
					break;
				}else if(id1==lib[k].id && lib[k].iss!=0){
					printf("The book is not available at the moment\n");
				}
			}
		}else if(n==2){
			int id2;
			printf("Enter the ID of the book:");
			scanf("%d",&id2);
			for(int k=0; k<3; k++){
				if(id2==lib[k].id){
					lib[k].iss=0;
					lib[k].ret=0;
					break;
				}
			}
		}
	}
    
  //printing the overview of the library.
	for(int a=0; a<3; a++){
		printf("Book ID-%d  issue-%d  return-%d  Number of times issued-%d\n",lib[a].id,lib[a].iss,lib[a].ret,lib[a].cnt);
	}
}
