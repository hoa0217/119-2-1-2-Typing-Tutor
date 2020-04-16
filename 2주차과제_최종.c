#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

int random = 0;
char name[20];
char quiz[100];
char answer[100];
void help();
void typing();
void lesson();
void statics();
void views();

void green(){	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void purple(){ 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void yellow(){	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void blue(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void white(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main(void) {
	//메뉴선택
	while(1){
		system("cls");
		green();
		int input=0;
		int ch=0;
		printf("\n\t\t\tT Y P I N G  T E S T E R\n\n");
		purple();
		printf("\t\tPress the number keys to select your choice.\n\n\n");
 		yellow();
		printf("\t\t\t\t***MAIN MENU***\n\n");
		printf("\t\t================================================\n\n");
		printf("\t\t\t[1] Select User\n\n");
		printf("\t\t\t[2] Statistics\n\n");
		printf("\t\t\t[3] View User Records\n\n");
		printf("\t\t\t[4] About\n\n");
		printf("\t\t\t[5] Quit\n\n");
		printf("\t\t================================================\n\n");
		white();
		printf("\nEnter the choice: ");
		scanf("%d", &input);
		
		if (input == 1){
			system("cls");
			blue();
			printf("\n\t\t[Select User]\n\n");
			yellow();
			printf("Enter Username: ");
			scanf("%s", &name);
			typing();
			getch();
		}
		else if (input == 2){
			system("cls");
			blue();   
			printf("\n\t\t\t\t[static]\n\n");
			statics();
			getch();
		}
		else if (input == 3){
			system("cls");
			blue();
			printf("\n\t\t\t[View User Records]\n\n");
			views();
			getch();
		}
		else if (input == 4){
			system("cls");
			help();
			getch();
		}
		else if (input == 5){
			system("cls");
			exit(0);
			getch();
		}
		
		else{
			system( "cls" );
			printf("\nerror! Please retry! \n\n");
			getch();
		}
	} 
	return 0;
}

void help() {
	blue();
	printf("\n\t\t\t[About]\n\n");
	yellow();
	printf("\t\t   ***Typing tutor***\n\n");
	printf("a.k.a 119 project 2nd week - Class 1 Team 2\n");
	printf("Copyright(c)2020 by Heo_JeongHwa, Choi_GunWoo All rights reserved\n");
	printf("Date: 2020.04.13 to 2020.04.16\n\n\n");
	printf("\t\t      ***Lesson***\n\n");
	printf("\t\t    <Very long words>\n\n");
	printf("   1.pneumonoultramicroscopicsilicovolcanoconioses\n");
	printf("   2.floccinaucinihilipilification\n");
	printf("   3.hippopotomonstrosesquippedaliophobia\n");
	printf("   4.aequeosalinocalcalinoceraceoaluminosocupreovitriolic\n");
	printf("   5.bonus\n\n");
	printf("   For More Information\n");
	printf("   -> github.com/Choi-gunwoo/119-2-1-2-Typing-Tutor/network/members");
}

void typing(){
		clock_t start, end;
		double sec=0.0;
		FILE *fp =NULL;
		system("cls");
		random = rand()%5+1; // 난수 생성
		green();
		printf("\n\t~~No. %d Start!!~~\n\n", random); // 출력
		lesson(); // 문장출력 
		yellow();
		printf(quiz);
		printf("\n");
		start=clock();
		white();
		time_t t = time(NULL);
  		struct tm tm = *localtime(&t);
		scanf("%s", &answer);
		end=clock();
		sec = (double)(end-start);//진행시간
		green();
		printf("======================================\n\n");
		if(strcmp(answer, quiz)==0){
			printf("\t   Good job!\n");
			printf("\tCheck your view!\n");
			fp=fopen("score.txt","a");
			if(fp==NULL){
				printf("\nWRITE FAIL\n\n"); 
			}
			else{
				fprintf(fp,"%s %d %.2lf %d-%d-%d %d:%d:%d\n", &name, random, sec,
				tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,tm.tm_hour, 
				tm.tm_min, tm.tm_sec
				); //이름, 난수, 점수기록
				fclose(fp); 
			} 
		}
		else{
			printf("    NOOOOO You make a mistake!\n");
		} 
		
} 


void lesson() {
	if (random == 1) {
		char a[100] = "pneumonoultramicroscopicsilicovolcanoconioses";
		strcpy(quiz, a);
	}
	else if (random == 2) {
		char a[100] = "floccinaucinihilipilification";
		strcpy(quiz, a);
	}
	else if (random == 3) {
		char a[100] = "hippopotomonstrosesquippedaliophobia";
		strcpy(quiz, a);
	}
	else if (random == 4) {
		char a[100] = "aequeosalinocalcalinoceraceoaluminosocupreovitriolic";
		strcpy(quiz, a);
	}
	else {
		char a[100] = "bonus";
		strcpy(quiz, a);
	}
}

void statics(){
	FILE *fp2=NULL;
	char name1[10];
	int random1;
    double sec1;
    char day1[20];
    char time1[20];
	white();
	fp2 = fopen("score.txt", "r");
	if (fp2 == NULL){
		printf("No data");
	}
	else{
			while (EOF!= fscanf(fp2,"%s %d %lf\n %s %s",name1,&random1,&sec1,day1,time1)) // 파일의 마지막까지 읽으면서
			{	
				printf("name: %s   lesson : %d   duration : %.2lf s   date: %s   time : %s\n"
				,name1,random1,sec1/1000,day1,time1);

			}
			green();
			printf("================================================================================");
		}
}

void views(){
	yellow();
	printf("Enter Username: ");
	scanf("%s", &name);
	printf("\n");
	FILE *fp3=NULL;
	char name2[10];
	int random2;
    double sec2;
    char day2[20];
    char time2[20];
    
	fp3 = fopen("score.txt", "r");
	if (fp3 == NULL){
		white();
		printf("\n\nNo data");
	}
	else{
			while (EOF!= fscanf(fp3,"%s %d %lf\n %s %s",name2,&random2,&sec2,day2,time2)) // 파일의 마지막까지 읽으면서
			{
				if(strcmp(name,name2)==0){
					white();
					printf("name: %s   lesson : %d   duration : %.2lf s   date: %s   time : %s\n"
				,name2,random2,sec2/1000,day2,time2);
				}
				else{
				}
				
			}
			green();
			printf("================================================================================");
			printf("\n\n\t\t\t   [Reference]\n");
			printf("\n\t  If nothing came up, there is no matching user.");
		}
}
