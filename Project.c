#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


typedef struct student{
	char name[30];
	char id[15];
	float mid1;
	float mid2;
	float ass;
	float quiz;
	float final;
	float gpa;
	float max;
}sdt;

float getGPA(float sum,float total){
	float per;
	per = sum/total * 100;
	if(per<50)
		return 0;
	else if(per < 54)
		return 1;
	else if(per < 58)
		return 1.33;
	else if(per < 62)
		return 1.66;
	else if(per < 66)
		return 2.0;
	else if(per < 70)
		return 2.33;
	else if(per < 74)
		return 2.66;
	else if(per < 78)
		return 3.00;
	else if(per < 82)
		return 3.33;
	else if(per < 86)
		return 3.66;
	else if(per >= 86)
		return 4.00;
}

int search(char a[],char sch[]){
	int i,j=0;
	
	for(i=0;i<strlen(a);i++){
			
		if(a[i] == sch[i]){
			j++;
			if(j == strlen(a))
				return j;
				}
		else 
			j=0;
		}
		return 0;
}

void add_record(){
	
	
	FILE * info,*info22;
	int num,i,j;
	float sum;
	
	printf("\n\n\n\n\t\t\t\tHow many records you want to add: ");
	scanf(" %d",&num);
	
	sdt data[num],s1;
	
	info = fopen("program1.txt","a");
	info22 = fopen("program1.txt","r");
	
	for(i=0;i<num;i++){
	j = 0;
	fflush(stdin);
	system("cls");
		
		printf("\n\n\t\t\t\tRecord %d, Enter Details ",i+1);
		printf("\n\n\t\t\t\tStudent ID(K224639) :");
		scanf(" %s",data[i].id);
		while(fread(&s1,sizeof(sdt),1,info22)){
			j = search(s1.id,data[i].id);
			if(j != 0){
				printf("\n\n\t\t\t\tID Already Exists in Database\n\n\t\t\t\tPress any key to continue");
				getch();
				break;
			}
		}
		if(j != 0)
			continue;
		 
		printf("\n\t\t\t\tEnter Student Name: ");
		scanf(" %[^\n]s",data[i].name);
		printf("\n\t\t\t\tEnter Mid 1 Marks: ");
		scanf(" %f",&data[i].mid1);
		printf("\n\t\t\t\tEnter Mid 2 Marks: ");
		scanf(" %f",&data[i].mid2);
		printf("\n\t\t\t\tEnter Assignment marks: ");
		scanf(" %f",&data[i].ass);
		printf("\n\t\t\t\tEnter Quiz marks: ");
		scanf(" %f",&data[i].quiz);
		printf("\n\t\t\t\tEnter Final marks: ");
		scanf(" %f",&data[i].final);
		printf("\n\t\t\t\tEnter Maximum Total marks: ");
		scanf(" %f",&data[i].max);
		
		sum = (data[i].mid1 + data[i].mid2 +data[i].final+data[i].ass+data[i].quiz) ;
		data[i].gpa = getGPA(sum,data[i].max);
	
		fwrite(&data[i],sizeof(sdt),1,info);
		
	}
	fclose(info);
	fclose(info22);
}

void display_one(){
	FILE * fp;
	sdt s1;
	int i,j=0;
	char a[15];
	printf("\n\n\t\t\t\tEnter ID to search : ");
	scanf(" %s",a);
	fp = fopen("program1.txt","r");
	while(fread(&s1,sizeof(sdt),1,fp)){
		
		j = search(s1.id,a);
		
		if(j == strlen(s1.id))
			break;
	}
	if(j != 0){
		printf("\n\n\t\t\t\tID - %s\n\t\t\t\tName - %s\n\t\t\t\tMid1 - %.2f\n\t\t\t\tMid2 - %.2f\n\t\t\t\tAssigment - %.2f\n\t\t\t\tQuiz - %.2f\n\t\t\t\tFinal - %.2f\n\t\t\t\tGPA - %.2f\n",s1.id,s1.name,s1.mid1,s1.mid2,s1.ass,s1.quiz,s1.final,s1.gpa);
			}
		else
			printf("\n\n\t\t\t\tRECORD NOT FOUND");
	
	fclose(fp);

}


void update(){
	FILE *fp,*fp1,*info22;
	sdt s1,ss22;
	
	
	int i,j=0,l,k,flag = 0;
	char a[15],option;
	float sum;
	
	printf("\n\n\t\t\t\tEnter ID to Update information : ");
	scanf(" %s",a);
	
	fp = fopen("program1.txt","r");
	fp1 = fopen("temp.txt","w");
	
	while(fread(&s1,sizeof(sdt),1,fp)){
		l = strlen(s1.id);
			
		j = search(s1.id,a);
		
			if(j == l){
				flag = 1;
				printf("\n\n\t\t\t\ta. ID - %s\n\t\t\t\tb. Name - %s\n\t\t\t\tc. Mid1 - %.2f\n\t\t\t\td. Mid2 - %.2f\n\t\t\t\te. Assigment - %.2f\n\t\t\t\tf. Quiz - %.2f\n\t\t\t\tg. Final - %.2f\n\n",s1.id,s1.name,s1.mid1,s1.mid2,s1.ass,s1.quiz,s1.final);
				printf("\n\n\t\t\t\tEnter option to update...");
				option = getch();
			
				switch(option){
				case 'a':
					info22 = fopen("program1.txt","r");
					printf("\n\n\t\t\t\tEnter New ID: ");
					scanf(" %s",&s1.id);
					while(fread(&ss22,sizeof(sdt),1,info22)){
						j = search(ss22.id,s1.id);
						if(j != 0){
							printf("\n\n\t\t\t\tID Already Exists in Database\n");
							fclose(info22);
							return;
							}
						}
						
					break;
				case 'b':
					printf("\n\n\t\t\t\tEnter New Name: ");
					scanf(" %[^\n]s",&s1.name);
					break;
				case 'c':
					printf("\n\n\t\t\t\tEnter Mid 1 Marks: ");
					scanf(" %f",&s1.mid1);
					sum = (s1.mid1 + s1.mid2 +s1.final+s1.ass+s1.quiz) ;
					s1.gpa = getGPA(sum,s1.max);
					break;
				case 'd':
					printf("\n\n\t\t\t\tEnter Mid 2 Marks: ");
					scanf(" %f",&s1.mid2);
					sum = (s1.mid1 + s1.mid2 +s1.final+s1.ass+s1.quiz) ;
					s1.gpa = getGPA(sum,s1.max);
					break;
				case 'e':
					printf("\n\n\t\t\t\tEnter Assignment Marks: ");
					scanf(" %f",&s1.ass);
					sum = (s1.mid1 + s1.mid2 +s1.final+s1.ass+s1.quiz) ;
					s1.gpa = getGPA(sum,s1.max);
					break;
				case 'f':
					printf("\n\n\t\t\t\tEnter Quiz Marks: ");
					scanf(" %f",&s1.quiz);
					sum = (s1.mid1 + s1.mid2 +s1.final+s1.ass+s1.quiz) ;
					s1.gpa = getGPA(sum,s1.max);
					break;
				case 'g':
					printf("\n\n\t\t\t\tEnter Final Marks: ");
					scanf(" %f",&s1.final);
					sum = (s1.mid1 + s1.mid2 +s1.final+s1.ass+s1.quiz) ;
					s1.gpa = getGPA(sum,s1.max);
					break;
				default:
					printf("INVALID OPTION");}
				}
	
		fwrite(&s1,sizeof(sdt),1,fp1);			
	}
	
	fclose(fp);
	fclose(fp1);
	
	if(flag != 1)
		printf("\n\n\t\t\tRECORD NOT FOUND");
	else{
		fp1 = fopen("temp.txt","r");
		fp  = fopen("program1.txt","w");
		
		while(fread(&s1,sizeof(sdt),1,fp1))
			fwrite(&s1,sizeof(sdt),1,fp);
			
		fclose(fp);
		fclose(fp1);
			}
}

	
void display_all(){
	int total=0;
	FILE * info;
	sdt data;
	info = fopen("program1.txt","r");
	
	printf("\t\t\tID\t\tName\t\tGPA");
	while(fread(&data,sizeof(sdt),1,info)){
		printf("\n\n\t\t\t%s\t\t%s\t\t%.2f",data.id,data.name,data.gpa);
		total++;
	}
	fclose(info);	
	
	printf("\n\n\n\t\t\t\tNO of RECORDS = %d\n",total);

}

void delete_a_record(){
	FILE *fp,*fp1;
	sdt s1;
	int i,j=0,l,flag = 0;
	char a[15],option;

	display_all();
	
	printf("\n\n\t\t\tEnter ID to Delete a record : ");
	scanf(" %s",a);
	
	fp = fopen("program1.txt","r");
	fp1 = fopen("temp.txt","w");
	
	while(fread(&s1,sizeof(sdt),1,fp)){
		l = strlen(s1.id);
			
		j = search(s1.id,a);
		
		if(j == l){
			flag = 1;
			continue;}
			
		fwrite(&s1,sizeof(sdt),1,fp1);	
	}
	fclose(fp);
	fclose(fp1);
	
	if( flag != 1)
		printf("\n\n\t\t\tRECORD NOT FOUND");
	else{
		
		
		fp1 = fopen("temp.txt","r");
		fp  = fopen("program1.txt","w");
		
		while(fread(&s1,sizeof(sdt),1,fp1))
			fwrite(&s1,sizeof(sdt),1,fp);
			
		fclose(fp);
		fclose(fp1);
		
		printf("\n\n\t\t\tRecord deleted!");
			}
		
	
}



int main(){
	char ch;
	
	while(1){
		
	system("cls");
	
	printf("\n\n\t\t\t\t\tSTUDENT RECORDS ");
	printf("\n\n\n\n\t\t\t\t\tMENU\n\n\t\t\t\t\ta. Add Records\n\t\t\t\t\tb. Remove a Record\n\t\t\t\t\tc. Edit a Record\n");
	printf("\t\t\t\t\td. Show GPA of all students\n\t\t\t\t\te. Show Full record of a student\n\t\t\t\t\tx. exit\n\t\t\t\t\t_______________________");

	ch = getch(),
	
	system("cls");
	
	if(ch == 'x')
		return 0;
	
	switch(ch){
		case 'a':
			add_record();
			break;
		case 'b':
			delete_a_record();
			break;
		case 'c':
			update();
			break;
		case 'd':
			display_all();	
			break;
		case 'e':
			display_one();
			break;
		case 'x':
			return 0;
		default:
			printf("\n\t\tEnter a valid option\n");
	}
	
	printf("\n\n\t\t\t\tPress any key to return to Menu");
	getch();

}
}
