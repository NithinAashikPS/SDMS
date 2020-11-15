/* Declaration of Header Files START */
    #include<graphics.h>
    #include<stdio.h>
    #include<dir.h>
    #include<conio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<dos.h>
    #include<time.h>
    #pragma warn -par
    #define NUMBER 1
    #define LETTER 2
    #define ALLINPUT 3

/* Declaration of Header Files END */


/* Structure Defined For Student Details START*/

    struct student
    {
		char regno[15];
		char name[30];
		char gen[5];
		struct date birth;
		char dept[10];
		char blo[5];
		char height[4];
		char weight[4];
		char fname[30];
		char foccup[30];
		char mname[30];
		char moccup[30];
		char doorno[10];
		char addr1[40];
		char addr2[40];
		char dist[20];
		char state[20];
		char pincode[10];
		char mobnumber[10];
    }stu;

/* Structure Defined For Student Details END*/

/* Declaration of Functions START*/

    void drawbox(int left, int top, int right, int bottom);                /*To Draw A Rectangle*/
    void drawwindow(char head[30],int x1, int y1, int x2, int y2, int c);  /*To Make A New Window*/
    int blockey();                                                         /*Responce For Enter And Shift Key*/
    int confirm(char str[15]);                                             /*To Confirm Any Task*/
    char *input(int,int,int);                                              /*Take Input From User*/
    int findsturegno(char regno1[15]);                                     /*To Find Existing Register Numbe*/
    void notice(char text[2][30],int x1,int y1,int x2,int y2);             /*Notify When Two Sentence Is Available*/
    void notice1(char text[30],int x1,int y1,int x2,int y2);               /*Notify When One Sentence Is Available*/
    void inputdat(int *,int *,int *,int c);                                /*To Calculate Date*/
    char selectgender();                                                   /*To Select Gender*/
    int selectdept();                                                      /*To Select Department*/
    int selectblood();                                                     /*To Select Blood*/
    char *getregno(char text[30],int x1,int y1,int x2,int y2);             /*Get Register Number From User*/
    void path(char regno[15],int n);					   /*To Go Back From Current Window*/
    int menu(int);                                                         /*To Display Menu Option*/
    int AddStudent();                                                      /*Add New Student(s) */
    int SearchStudent(char regno[15]);                                     /*Search for a particular Student */
    int UpdateStudent(char regno[15]);                                     /*Update Student */
    int DeleteStudent(char regno[15]);                                     /*Deleter Student */
    int About();                                                           /*About Project*/
    void name();

/* Declaration of Functions END*/

/* Drawbox Function START*/

 void drawbox(int left, int top, int right, int bottom)
 {
	 int i;
	 for(i=0; i<right-left-1; i++) {
		 if(i==0) {
			 printf(" \332");
		} else if(i==right-left-2)
			printf("\277");
		else
			printf("\304");}
	for(i=0; i<bottom-top-1; i++) {
		gotoxy(2,i+2);
		printf("\263");
		gotoxy(right-left,i+2);
		printf("\263");}
	gotoxy(1,bottom-top+1);
	for(i=0; i<right-left-1; i++) {
		if(i==0) {
			printf(" \300");
		} else if(i==right-left-2)
			printf("\331");
		else
			printf("\304");}
}

/*Drawbox Function END*/

/*Drawwindow Function START*/

void drawwindow(char head[50],int x1, int y1, int x2, int y2, int c)
{
	textbackground(7);
	textcolor(0);
	window(x1-3,y1-2,x2+3,y1-2);
	clrscr();
	gotoxy(((x2+3)-(x1-3)+3-strlen(head))/2,1);printf("%s",head);
	textbackground(c);
	textcolor(WHITE);
	window(x1-3,y1-1,x2+3,y2+1);
	clrscr();
	drawbox(x1-3, y1-1, x2+3, y2+1);
	window(x1,y1,x2+1,y2);
}

/*Drawwindow Function END*/

/*Blockey Function START*/

int blockey()
{
	char ch;
ch:
    ch=getch();
	if(ch!=13&&ch!=27)goto ch;
	return ch;
}

/*Blockey Function END*/

/*Confirm Function START*/

int confirm(char str[15]){
	char conf[2][5]={"No","Yes"};
	int i,ch,select=0;
	clrscr();
	textbackground(0);
	window(24,10,57,18);
	clrscr();
	textbackground(14);
	window(23,9,56,17);
	clrscr();
	drawbox(2,1,35,9);
	gotoxy((33-(11+strlen(str)))/2,3);textcolor(15);
	cprintf("Confirm Your %s",str);
	do{
		for(i=0;i<=1;i++){
			if(i==select)
				textbackground(2);
			else textbackground(14);
			textcolor(15);
			gotoxy(8+i*16,7);
			cprintf(" %s ",conf[i]);
			}
		ch=getch();
		switch(ch){
			case 75:select--;if(select==-1) select=1;break;
			case 77:select++;if(select==2) select=0; break;}
    }while(ch!=13);
	return select;
}

/*Confirm Function END*/

/*Input Function START*/

 char *input(int type,int limit,int c)
 {
	 char result[50]="";
	 char ch;
	 int index = 0,i;
	 _setcursortype(2);
	 do {
		 ch=getch();
		 if((type==3||type==0)&&index<limit){
			 if(isalpha(ch)||(ch>='!'&&ch<='@')||ch==95) {
				 result[index++]=ch;
				 if(type==0){
					 textcolor(c);cprintf("*");
				}else{
					textcolor(c);cprintf("%c",ch);
				}}}
	if(type==1&&index<limit){
		if(ch>=40&&ch<=57) {
			result[index++] = ch;
			textcolor(c);cprintf("%c",ch);
		}}
	if(type==2&&index<limit)
		if(isalpha(ch)||ch==' ') {
			result[index++]=ch;
			textcolor(c);cprintf("%c",ch);}
		if(ch==8&&index>0) {
			result[index--]=NULL;
			printf("\b \b");}
		if(ch==94&&type==0&&index>0){
			_setcursortype(0);
			result[index]=0;
		for(i=0;i<index;i++)
			printf("\b");
		textcolor(c);cprintf("%s",result);
		for(i=0;i<index;i++)
			printf("\b");
		delay(100);
		for(i=0;i<index;i++)
			textcolor(c),cprintf("*");
		_setcursortype(2);}
		} while((ch != 13||index<1)&&ch!=27);
		result[index] =0;
		_setcursortype(0);
		return ch==27?"00":result;
}

/*Input Funcion END*/

/*Find Register Number Function START*/

int findsturegno(char regno[15])
{
	FILE *fp;
	int i,f=0;
	char filename[40]="C:/SDMS/";
	for(i=0;i<4;i++){
	filename[strlen(filename)]=regno[i];
	}filename[strlen(filename)]='/';
	for(i=4;i<6;i++){
		filename[strlen(filename)]=regno[i];
	}filename[strlen(filename)]='/';
	for(i=6;i<9;i++){
		filename[strlen(filename)]=regno[i];
	}filename[strlen(filename)]='/';
	for(i=9;i<12;i++){
		filename[strlen(filename)]=regno[i];
	}strcat(filename,".BIN");
	if(fp=fopen(filename,"r")){
	      fclose(fp);
	      f=1;
	}else
	      f=0;
	return f;
}

/*Find Register Number Function END*/

/*Notice Function START*/

void notice(char text[2][30],int x1,int y1,int x2,int y2)
{
	textbackground(0);
	window(x1+1,y1+1,x2+1,y2+1);
	clrscr();
	textbackground(3);
	textcolor(15);
	window(x1,y1,x2,y2);
	clrscr();
	drawbox(1,1,x2-x1+1,y2-y1+1);
	gotoxy((x2-x1+3)/2-strlen(text[0])/2,2);printf("%s",text[0]);
	gotoxy((x2-x1+3)/2-strlen(text[1])/2,3);printf("%s",text[1]);
	gotoxy((x2-x1+2)/2,5);textbackground(2);cprintf(" OK ");
}

/*Notice Function END*/

/*Notice1 Function START*/

void notice1(char text[30],int x1,int y1,int x2,int y2)
{
	textbackground(0);
	window(x1+1,y1+1,x2+1,y2+1);
	clrscr();
	textbackground(3);
	textcolor(15);
	window(x1,y1,x2,y2);
	clrscr();
	drawbox(1,1,x2-x1+1,y2-y1+1);
	gotoxy((x2-x1+3)/2-strlen(text)/2,2);printf("%s",text);
	gotoxy((x2-x1+2)/2,5);textbackground(2);cprintf(" OK ");
}

/*Notice1 Function END*/

/*Inputdat Function START*/

void inputdat(int *day,int *mon,int *year,int c)
 {
	 char ch,reday[3]="",remon[3]="",reyear[5]="";
	 int d=0,m=0,y=0,i=0;
	 _setcursortype(2);
	 do{
		 ch=getch();
		 if(isdigit(ch)&&i<8){
			 if(i<2){
				 reday[d++]=ch;
				 textcolor(c);cprintf("%c",ch);
			 }else if(i<4){
				 remon[m++]=ch;
				 textcolor(c);cprintf("%c",ch);
			 }else if(i<8){
				 reyear[y++]=ch;
				 textcolor(c);cprintf("%c",ch);
			 }
		if(i==1||i==3){textcolor(c);cprintf("/");}
		i++;}
		if(ch == 8) {
			if(i != 0) {
				i--;
				if(i<2){
					reday[d--]=NULL;
					textcolor(c);cprintf("\b \b");
					}else if(i<4){
						remon[m--]=NULL;
						textcolor(c);cprintf("\b \b");
						}else if(i<8){
							reyear[y--]=NULL;
							textcolor(c);cprintf("\b \b");
							}
							if(i==1||i==3){
								printf("\b \b");
								}
								}
								}
	}while((ch != 13||i<8)&&ch!=27);
	if(ch==13){
		*day=atoi(reday);
		*mon=atoi(remon);
		*year=atoi(reyear);
		}
		_setcursortype(0);
}

/*Inputdat Function END*/

/*Select Gender Function START*/

 char selectgender()
 {
	 char gender[2][5]={"M","F"};
	 char ch;
	 int result;
	 int n,i=0;
	 do {
		 textcolor(15);
		 gotoxy(18,5);
		 cprintf("%c %s %c",174,gender[i],175);
	 do{
		 ch=getch();
		}while(ch!=75&&ch!=77&&ch!=13&&ch!=27);
		if(ch==77) {i++;if(i>=2) i=0;}
		else if(ch==75){ i--;if(i<=-1) i=1;}
		} while(ch!=13&&ch!=27);
		if(ch==13) {
			result=i;
		}else{
			result=0;
		}
	return result;
}

/*Select Gender Function END*/

/*Select Department Function START*/

 int selectdept(){
	 char branch[6][20]={"Civil","CSE  ","ECE  ","EEE  "," IT  ","Mech "};
	 char ch;
	 int result;
	 int n,i=0;
	 do {
		 textcolor(15);
		 gotoxy(18,9);
		 cprintf("%c %s %c",174,branch[i],175);
	 do{
		 ch=getch();
		}while(ch!=75&&ch!=77&&ch!=13&&ch!=27);
		if(ch==77) {i++;if(i>=6) i=0;}
		else if(ch==75){ i--;if(i<=-1) i=5;}
		} while(ch!=13&&ch!=27);
		if(ch==13) {
			result=i;
		}else{
			result=0;
		}
	return result;
}

/*Select Department Function END*/

/*Select Blood Function START*/

int selectblood()
{
	char blood[8][4]={"O+ ","O- ","A+ ","A- ","B+ ","B- ","AB+","AB-"};
	char ch;
	int result;
	int n,i=0;
	do {
		textcolor(15);
		gotoxy(18,11);
		cprintf("%c %s %c",174,blood[i],175);
	do{
		ch=getch();
	}while(ch!=75&&ch!=77&&ch!=13&&ch!=27);
	if(ch==77) {i++;if(i>=8) i=0;}
	else if(ch==75){ i--;if(i<=-1) i=7;}
	} while(ch!=13&&ch!=27);
    if(ch==13) {
		result=i+1;
	}else{
		result=0;}
	return result;
}

/*Select Blood Function END*/

/*Get Register Number START*/

char *getregno(char text[30],int x1,int y1,int x2,int y2)
{
	char regno[15];
	textbackground(0);
	window(x1+1,y1+1,x2+1,y2+1);
	clrscr();
	textbackground(3);
	textcolor(15);
	window(x1,y1,x2,y2);
	clrscr();
	drawbox(1,1,x2-x1+1,y2-y1+1);
	gotoxy((x2-x1+3)/2-strlen(text)/2,1);printf("%s",text);
	gotoxy((x2-x1+2)/2,5);textbackground(2);cprintf(" OK ");
	textbackground(3);
	gotoxy(8,3);textcolor(15);cprintf("RegNo:"); strcpy(regno,input(1,12,15));
	return regno;
}

/*Get Register Number END*/

/*Path Function START*/

void path(char regno[15],int n){
	FILE *fp;
	int i;
	char filename[40]="C:/SDMS/";
	for(i=0;i<4;i++){
	filename[strlen(filename)]=regno[i];
	}filename[strlen(filename)]='/';
	mkdir(filename);
	for(i=4;i<6;i++){
		filename[strlen(filename)]=regno[i];
	}filename[strlen(filename)]='/';
	mkdir(filename);
	for(i=6;i<9;i++){
		filename[strlen(filename)]=regno[i];
	}filename[strlen(filename)]='/';
	mkdir(filename);
	for(i=9;i<12;i++){
		filename[strlen(filename)]=regno[i];
	}strcat(filename,".BIN");
	if(n==0){
		fp=fopen(filename,"w");
		fwrite(&stu,sizeof(struct student),1,fp);
	}else if(n==1){
		fp=fopen(filename,"r");
		fread(&stu,sizeof(struct student),1,fp);
	}else if(n==2){
		      remove(filename);
		      notice1("Delete Successfull",24,10,55,15);
		      blockey();
	}
	fclose(fp);
}

/*Path Function END*/

/*Menu Function START*/

int menu(int select)
{
	char chr=175, ch, menu[6][30]={"1.  Add  Student","2.  Search  Student","3.  Update  Student","4.  Delete  Student","5.  About Project","6.  Exit/Quit"};
	int i,x;
	clrscr();
	drawwindow("STUDENT DETAILS MAINTANANCE SYSTEM",4,5,77,22,RED);
	do{
		clrscr();
		x=4;
		for(i=0;i<6;i++,x+=2)
			if(i==select){
				textcolor(GREEN);
				gotoxy(27,x) ;
		cprintf("%c",chr) ;
				gotoxy(29,x);
		cprintf("%s",menu[i]);
			}else{
				textcolor(WHITE);
				gotoxy(29,x);
		cprintf("%s",menu[i]);
			}
	ch=getch();
		switch(ch){
			case 72:select--;
				if(select==-1) select=0;
					break;
	    case 80:select++;
				if(select==6) select=5;
					break;
	    case 10:if(select<6)ch=13;
				break;}
	}while(ch!=13);
    return select;
}

/*Menu Function END*/

/*Add Student Function START*/

int AddStudent()
{
	FILE *fp;
	struct date dai;
	int day=0,mon=0,year=0;
	char ch;
	char regno[15],name[35],gen[5],dept[10],blo[5],height[4],weight[4],mobnumber[10],fname[35],foccup[30],mname[35],moccup[30],doorno[10],addr1[40],addr2[40],dist[20],state[30],pincode[10];
	char text[2][30]={"Student added","Enter to add another"};
	char gender[2][5]={"M","F"};
	char blood[9][4]={"00","O+","O-","A+","A-","B+","B-","AB+","AB-"};
	char branch[8][20]={"Civil","CSE","ECE","EEE","IT","Mech"};
	do{
		getdate(&dai);
		drawwindow("ADD STUDENT",4,5,77,22,GREEN);
		gotoxy(1,1);textcolor(15);cprintf("Register Number :"); strcpy(regno,input(1,12,15));
		if(strcmp(regno,"00")==0) break;
		if(findsturegno(regno)==1){
			notice1("This Reg no is in exist",24,10,55,15);
			blockey();
			continue;}

		gotoxy(1,3);textcolor(15); cprintf("Name Of Student :"); strcpy(name,input(2,17,15));
		if(strcmp(name,"00")==0) break;
		gotoxy(1,5);textcolor(15); cprintf("GENDER          :");strcpy(gen,gender[selectgender()]);
		if(strcmp(gen,"00")==0) break;
	date:
		gotoxy(1,7);textcolor(15); cprintf("Date Of Birth   :"); gotoxy(18,7);inputdat(&day,&mon,&year,15);
		if(day==0||mon==0||year==0) break;
		else if(day>31||mon>12||year<1900||year>dai.da_year||(mon>dai.da_mon&&year>=dai.da_year)||(day>dai.da_day&&mon>=dai.da_mon&&year>=dai.da_year)){
			gotoxy(18,7);printf("DD/MM/YYYY");
			day=0;mon=0;year=0;
			goto date;
		}
		gotoxy(1,9);textcolor(15); cprintf("Department      :");strcpy(dept,branch[selectdept()]);
		if(strcmp(dept,"00")==0) break;
		gotoxy(1,11);textcolor(15);cprintf("Blood Group     :");strcpy(blo,blood[selectblood()]);
		if(strcmp(blo,"00")==0) break;
		gotoxy(1,13);textcolor(15);cprintf("Height in cm    :"); strcpy(height,input(1,3,15));
		if(strcmp(height,"00")==0) break;
		gotoxy(1,15);textcolor(15);cprintf("Weight in kg    :"); strcpy(weight,input(1,3,15));
		if(strcmp(weight,"00")==0) break;
		gotoxy(1,17);textcolor(15);cprintf("Mobile Number   :"); strcpy(stu.mobnumber,input(1,10,15));
		if(strcmp(stu.mobnumber,"00")==0) break;
		gotoxy(37,1);textcolor(15); cprintf("Father's Name       :"); strcpy(fname,input(2,17,15));
		if(strcmp(fname,"00")==0) break;
		gotoxy(37,3);textcolor(15); cprintf("Father's Occupation :"); strcpy(foccup,input(2,17,15));
		if(strcmp(foccup,"00")==0) break;
		gotoxy(37,5);textcolor(15); cprintf("Mother's Name       :"); strcpy(mname,input(2,17,15));
		if(strcmp(mname,"00")==0) break;
		gotoxy(37,7);textcolor(15); cprintf("Mother's Occupation :"); strcpy(moccup,input(2,17,15));
		if(strcmp(moccup,"00")==0) break;
		gotoxy(37,9);textcolor(15); cprintf("Door Number         :"); strcpy(doorno,input(3,10,15));
		if(strcmp(doorno,"00")==0) break;
		gotoxy(37,10);textcolor(15);cprintf("Address Line 1      :"); strcpy(addr1,input(2,17,15));
		if(strcmp(addr1,"00")==0) break;
		gotoxy(37,11);textcolor(15);cprintf("Address Line 2      :"); strcpy(addr2,input(2,17,15));
		if(strcmp(addr2,"00")==0) break;
		gotoxy(37,13);textcolor(15);cprintf("District            :"); strcpy(dist,input(2,17,15));
		if(strcmp(dist,"00")==0) break;
		gotoxy(37,15);textcolor(15);cprintf("State               :"); strcpy(state,input(2,17,15));
		if(strcmp(state,"00")==0) break;
		gotoxy(37,17);textcolor(15);cprintf("Pincode             :"); strcpy(pincode,input(1,7,15));
		if(strcmp(pincode,"00")==0) break;

		strcpy(stu.regno,regno);
		strcpy(stu.name,name);
		strcpy(stu.gen,gen);
		stu.birth.da_day=day;
		stu.birth.da_mon=mon;
		stu.birth.da_year=year;
		strcpy(stu.dept,dept);
		strcpy(stu.blo,blo);
		strcpy(stu.height,height);
		strcpy(stu.weight,weight);
		strcpy(stu.fname,fname);
		strcpy(stu.foccup,foccup);
		strcpy(stu.mname,mname);
		strcpy(stu.moccup,moccup);
		strcpy(stu.doorno,doorno);
		strcpy(stu.addr1,addr1);
		strcpy(stu.addr2,addr2);
		strcpy(stu.dist,dist);
		strcpy(stu.state,state);
		strcpy(stu.pincode,pincode);


		path(regno,0);

		notice(text,24,10,55,15);
		ch=blockey();
		if(ch==27) break;
		}while(1);
		return 0;
}

/*Add Student Function END*/

/*Search Student Function START*/

int SearchStudent(char regno[15])
{
	if(findsturegno(regno)==0){
		notice1("Register number Not Found",24,10,55,15);
		blockey();
	}else{
	drawwindow("SEARCH STUDENT",4,5,77,22,GREEN);
	path(regno,1);

	gotoxy(1,1);textcolor(11); cprintf("Register Number :");textcolor(15);cprintf(" %s",stu.regno);
	gotoxy(1,3);textcolor(11); cprintf("Name Of Student :");textcolor(15);cprintf(" %s",stu.name);
	gotoxy(1,5);textcolor(11); cprintf("Gender          :");textcolor(15);cprintf(" %s",stu.gen);
	gotoxy(1,7);textcolor(11); cprintf("Date Of Birth   :");textcolor(15);cprintf(" %02d/%02d/%d",stu.birth.da_day,stu.birth.da_mon,stu.birth.da_year);
	gotoxy(1,9);textcolor(11); cprintf("Department      :");textcolor(15);cprintf(" %s",stu.dept);
	gotoxy(1,11);textcolor(11);cprintf("Blood Group     :");textcolor(15);cprintf(" %s",stu.blo);
	gotoxy(1,13);textcolor(11);cprintf("Height in cm    :");textcolor(15);cprintf(" %s",stu.height);
	gotoxy(1,15);textcolor(11);cprintf("Weight in kg    :");textcolor(15);cprintf(" %s",stu.weight);
	gotoxy(1,17);textcolor(11);cprintf("Mobile Number   :");textcolor(15);cprintf(" %s",stu.mobnumber);
	gotoxy(37,1);textcolor(11); cprintf("Father's Name       :");textcolor(15);cprintf(" %s",stu.fname);
	gotoxy(37,3);textcolor(11); cprintf("Father's Occupation :");textcolor(15);cprintf(" %s",stu.foccup);
	gotoxy(37,5);textcolor(11); cprintf("Mother's Name       :");textcolor(15);cprintf(" %s",stu.mname);
	gotoxy(37,7);textcolor(11); cprintf("Mother's Occupation :");textcolor(15);cprintf(" %s",stu.moccup);
	gotoxy(37,9);textcolor(11); cprintf("Door Number         :");textcolor(15);cprintf(" %s",stu.doorno);
	gotoxy(37,10);textcolor(11);cprintf("Address1            :");textcolor(15);cprintf(" %s",stu.addr1);
	gotoxy(37,11);textcolor(11);cprintf("Address2            :");textcolor(15);cprintf(" %s",stu.addr2);
	gotoxy(37,13);textcolor(11);cprintf("District            :");textcolor(15);cprintf(" %s",stu.dist);
	gotoxy(37,15);textcolor(11);cprintf("State               :");textcolor(15);cprintf(" %s",stu.state);
	gotoxy(37,17);textcolor(11);cprintf("Pincode             :");textcolor(15);cprintf(" %s",stu.pincode);

	while(blockey()==13);
	return 1;
	}
	return 1;
}

/*Search Student Function END*/

/*Update Student Function START*/

int UpdateStudent(char regno[15])
{
	struct date dai;
	int day=0,mon=0,year=0;
	char ch;
	char name[35],gen[5],dept[10],blo[5],height[4],weight[4],mobnumber[10],fname[35],foccup[30],mname[35],moccup[30],doorno[10],addr1[40],addr2[40],dist[20],state[30],pincode[10];
	char text[30]={"Student updated"};
	char gender[2][5]={"M","F"};
	char blood[9][4]={"00","O+","O-","A+","A-","B+","B-","AB+","AB-"};
	char branch[8][20]={"Civil","CSE","ECE","EEE","IT","Mech"};

	if(findsturegno(regno)==0){
		notice1("Register number Not Found",24,10,55,15);
		blockey();
	}else{
	do{
		getdate(&dai);
		drawwindow("UPDATE STUDENT",4,5,77,22,GREEN);
		gotoxy(1,1);textcolor(15);cprintf("Register Number :"); cprintf("%s",regno);

		gotoxy(1,3);textcolor(15); cprintf("Name Of Student :"); strcpy(name,input(2,17,15));
		if(strcmp(name,"00")==0) break;
		gotoxy(1,5);textcolor(15); cprintf("GENDER          :");strcpy(gen,gender[selectgender()]);
		if(strcmp(gen,"00")==0) break;
	date:
		gotoxy(1,7);textcolor(15); cprintf("Date Of Birth   :"); gotoxy(18,7);inputdat(&day,&mon,&year,15);
		if(day==0||mon==0||year==0) break;
		else if(day>31||mon>12||year<1900||year>dai.da_year||(mon>dai.da_mon&&year>=dai.da_year)||(day>dai.da_day&&mon>=dai.da_mon&&year>=dai.da_year)){
			gotoxy(18,7);printf("DD/MM/YYYY");
			day=0;mon=0;year=0;
			goto date;
		}
		gotoxy(1,9);textcolor(15); cprintf("Department      :");strcpy(dept,branch[selectdept()]);
		if(strcmp(dept,"00")==0) break;
		gotoxy(1,11);textcolor(15);cprintf("Blood Group     :");strcpy(blo,blood[selectblood()]);
		if(strcmp(blo,"00")==0) break;
		gotoxy(1,13);textcolor(15);cprintf("Height in cm    :"); strcpy(height,input(1,3,15));
		if(strcmp(height,"00")==0) break;
		gotoxy(1,15);textcolor(15);cprintf("Weight in kg    :"); strcpy(weight,input(1,3,15));
		if(strcmp(weight,"00")==0) break;
		gotoxy(1,17);textcolor(15);cprintf("Mobile Number   :"); strcpy(stu.mobnumber,input(1,10,15));
		if(strcmp(stu.mobnumber,"00")==0) break;
		gotoxy(37,1);textcolor(15); cprintf("Father's Name       :"); strcpy(fname,input(2,17,15));
		if(strcmp(fname,"00")==0) break;
		gotoxy(37,3);textcolor(15); cprintf("Father's Occupation :"); strcpy(foccup,input(2,17,15));
		if(strcmp(foccup,"00")==0) break;
		gotoxy(37,5);textcolor(15); cprintf("Mother's Name       :"); strcpy(mname,input(2,17,15));
		if(strcmp(mname,"00")==0) break;
		gotoxy(37,7);textcolor(15); cprintf("Mother's Occupation :"); strcpy(moccup,input(2,17,15));
		if(strcmp(moccup,"00")==0) break;
		gotoxy(37,9);textcolor(15); cprintf("Door Number         :"); strcpy(doorno,input(3,10,15));
		if(strcmp(doorno,"00")==0) break;
		gotoxy(37,10);textcolor(15);cprintf("Address Line 1      :"); strcpy(addr1,input(2,17,15));
		if(strcmp(addr1,"00")==0) break;
		gotoxy(37,11);textcolor(15);cprintf("Address Line 2      :"); strcpy(addr2,input(2,17,15));
		if(strcmp(addr2,"00")==0) break;
		gotoxy(37,13);textcolor(15);cprintf("District            :"); strcpy(dist,input(2,17,15));
		if(strcmp(dist,"00")==0) break;
		gotoxy(37,15);textcolor(15);cprintf("State               :"); strcpy(state,input(2,17,15));
		if(strcmp(state,"00")==0) break;
		gotoxy(37,17);textcolor(15);cprintf("Pincode             :"); strcpy(pincode,input(1,7,15));
		if(strcmp(pincode,"00")==0) break;

		strcpy(stu.regno,regno);
		strcpy(stu.name,name);
		strcpy(stu.gen,gen);
		stu.birth.da_day=day;
		stu.birth.da_mon=mon;
		stu.birth.da_year=year;
		strcpy(stu.dept,dept);
		strcpy(stu.blo,blo);
		strcpy(stu.height,height);
		strcpy(stu.weight,weight);
		strcpy(stu.fname,fname);
		strcpy(stu.foccup,foccup);
		strcpy(stu.mname,mname);
		strcpy(stu.moccup,moccup);
		strcpy(stu.doorno,doorno);
		strcpy(stu.addr1,addr1);
		strcpy(stu.addr2,addr2);
		strcpy(stu.dist,dist);
		strcpy(stu.state,state);
		strcpy(stu.pincode,pincode);


		path(regno,0);

		notice1(text,24,10,55,15);
		ch=blockey();
		if(ch==27) return 2;
		}while(0);
	}
	return 2;
}

/*Update Student Function END*/

/*Delete Student Function START*/

int DeleteStudent(char regno[15])
{
	char ch;

	if(findsturegno(regno)==0){
		notice1("Register number Not Found",24,10,55,15);
		blockey();
	}else{
	drawwindow("DELETE STUDENT",4,5,77,22,GREEN);
	path(regno,1);

	gotoxy(1,1);textcolor(11); cprintf("Register Number :");textcolor(15);cprintf(" %s",stu.regno);
	gotoxy(1,3);textcolor(11); cprintf("Name Of Student :");textcolor(15);cprintf(" %s",stu.name);
	gotoxy(1,5);textcolor(11); cprintf("Gender          :");textcolor(15);cprintf(" %s",stu.gen);
	gotoxy(1,7);textcolor(11); cprintf("Date Of Birth   :");textcolor(15);cprintf(" %02d/%02d/%d",stu.birth.da_day,stu.birth.da_mon,stu.birth.da_year);
	gotoxy(1,9);textcolor(11); cprintf("Department      :");textcolor(15);cprintf(" %s",stu.dept);
	gotoxy(1,11);textcolor(11);cprintf("Blood Group     :");textcolor(15);cprintf(" %s",stu.blo);
	gotoxy(1,13);textcolor(11);cprintf("Height in cm    :");textcolor(15);cprintf(" %s",stu.height);
	gotoxy(1,15);textcolor(11);cprintf("Weight in kg    :");textcolor(15);cprintf(" %s",stu.weight);
	gotoxy(1,17);textcolor(11);cprintf("Mobile Number   :");textcolor(15);cprintf(" %s",stu.mobnumber);
	gotoxy(37,1);textcolor(11); cprintf("Father's Name       :");textcolor(15);cprintf(" %s",stu.fname);
	gotoxy(37,3);textcolor(11); cprintf("Father's Occupation :");textcolor(15);cprintf(" %s",stu.foccup);
	gotoxy(37,5);textcolor(11); cprintf("Mother's Name       :");textcolor(15);cprintf(" %s",stu.mname);
	gotoxy(37,7);textcolor(11); cprintf("Mother's Occupation :");textcolor(15);cprintf(" %s",stu.moccup);
	gotoxy(37,9);textcolor(11); cprintf("Door Number         :");textcolor(15);cprintf(" %s",stu.doorno);
	gotoxy(37,10);textcolor(11);cprintf("Address1            :");textcolor(15);cprintf(" %s",stu.addr1);
	gotoxy(37,11);textcolor(11);cprintf("Address2            :");textcolor(15);cprintf(" %s",stu.addr2);
	gotoxy(37,13);textcolor(11);cprintf("District            :");textcolor(15);cprintf(" %s",stu.dist);
	gotoxy(37,15);textcolor(11);cprintf("State               :");textcolor(15);cprintf(" %s",stu.state);
	gotoxy(37,17);textcolor(11);cprintf("Pincode             :");textcolor(15);cprintf(" %s",stu.pincode);


	while(blockey()==27);
	if(confirm("Delete")==1){
	    path(regno,2);}
	else
	    DeleteStudent(regno);
	}
	return 3;
}

/*Delete Student Function END*/

/*About Function START*/

int About() {
	char ch;
	drawwindow("ABOUT PROJECT",4,5,77,22,GREEN);
	gotoxy(21,1);printf("STUDENT DETAILS MAINTANANCE SYSTEM");
	gotoxy(21,2);printf("----------------------------------");
	gotoxy(24,4);textcolor(YELLOW); cprintf("Created by    : Nithin Aashik");
	gotoxy(24,6);textcolor(9);      cprintf("Team Members  : Vimal");
	gotoxy(24,8);textcolor(9);      cprintf("                Sureshmani");
	gotoxy(24,10);textcolor(9);     cprintf("                Ramesh Kannan");
	gotoxy(24,12);textcolor(9);     cprintf("                Sudharsanakumar");
	gotoxy(24,15);textcolor(RED);   cprintf("Version       : 1.0");
	while(blockey()==13);
	return 4;

}

/*About Function END*/

/* Main Function START*/

void main()
{
	int opt=0,i,a=11;
	char regno[15];
	clrscr();
	_setcursortype(0);
	textcolor(GREEN);
	name();
	gotoxy(9,9);
	cprintf("STUDENT DETAILS MAINTANANCE SYSTEM");
	for(i=0;i<30;i++)
	{
	gotoxy(a++,18);
	textcolor(GREEN);
	cprintf("%c",176);
	}
	a=11;
	for(i=0;i<30;i++)
	{
	textcolor(GREEN);
	delay(2000);
	gotoxy(21,20);
	cprintf("Loading..  ");
	delay(2000);
	gotoxy(21,20);
	cprintf("Loading  ..");
	gotoxy(a++,18);
	cprintf("%c",219);
	delay(2000);
	gotoxy(21,20);
	cprintf("Loading    ");
	}
	gotoxy(21,20);
	cprintf("Press Enter");
	blockey();
	clrscr();
	do{
			switch(menu(opt)){
				case 0:opt=AddStudent();break;
				case 1:strcpy(regno,getregno("Provide Reg No",24,10,55,15));
				       if(strlen(regno)>11){
						   opt=SearchStudent(regno);break;
					   }
					   else{
						   notice1(" Invalid Register number  ",24,10,55,15);
						   blockey();
						   opt=1;
					       break;}
				case 2:strcpy(regno,getregno("Provide Reg No",24,10,55,15));
				       if(strlen(regno)>11){
						   opt=UpdateStudent(regno);break;
					   }
					   else{
						   notice1(" Invalid Register number  ",24,10,55,15);
						   blockey();
						   opt=2;
					       break;}
				case 3:strcpy(regno,getregno("Provide Reg No",24,10,55,15));
				       if(strlen(regno)>11){
						   opt=DeleteStudent(regno);break;
					   }
					   else{
						   notice1(" Invalid Register number  ",24,10,55,15);
						   blockey();
						   opt=3;
					       break;}
				case 4:opt=About();break;
				case 5:if(confirm("Quit")==1){
				       clrscr();
				       exit(0); }
				       else {opt=5;break;}
				}
		}while(1);
}

/* Main Function END*/

void name()
{
	int i;
	textbackground(0);
	textcolor(GREEN);
	window(15,5,65,25);
	clrscr();
	drawbox(1,1,51,7);


	for(i=5;i<14;i++){
	gotoxy(i,2);
	cprintf("%c",196);
	}
	gotoxy(5,2);
	cprintf("%c",218);
	for(i=3;i<5;i++){
	gotoxy(5,i);
	cprintf("%c",179);
	}
	gotoxy(5,4);
	cprintf("%c",192);
	for(i=6;i<12;i++){
	gotoxy(i,4);
	cprintf("%c",196);
	}
	gotoxy(12,4);
	cprintf("%c",191);
	for(i=5;i<7;i++){
	gotoxy(12,i);
	cprintf("%c",179);
	}
	gotoxy(12,6);
	cprintf("%c",217);
	for(i=4;i<12;i++){
	gotoxy(i,6);
	cprintf("%c",196);
	}
	gotoxy(13,2);
	cprintf("%c",191);
	gotoxy(4,6);
	cprintf("%c",192);


	for(i=16;i<25;i++){
	gotoxy(i,2);
	cprintf("%c",196);
	}
	gotoxy(25,2);
	cprintf("%c",191);
	for(i=16;i<25;i++){
	gotoxy(i,6);
	cprintf("%c",196);
	}
	gotoxy(25,6);
	cprintf("%c",217);
	for(i=3;i<6;i++){
	gotoxy(25,i);
	cprintf("%c",179);
	}
	for(i=3;i<6;i++){
	gotoxy(18,i);
	cprintf("%c",179);
	}
	gotoxy(15,2);
	cprintf("%c",218);
	gotoxy(15,6);
	cprintf("%c",192);


	for(i=40;i<49;i++){
	gotoxy(i,2);
	cprintf("%c",196);
	}
	gotoxy(40,2);
	cprintf("%c",218);
	for(i=3;i<5;i++){
	gotoxy(40,i);
	cprintf("%c",179);
	}
	gotoxy(40,4);
	cprintf("%c",192);
	for(i=6;i<12;i++){
	gotoxy(i,51);
	cprintf("%c",196);
	}
	gotoxy(47,4);
	cprintf("%c",191);
	for(i=5;i<7;i++){
	gotoxy(47,i);
	cprintf("%c",179);
	}
	gotoxy(47,6);
	cprintf("%c",217);
	for(i=39;i<47;i++){
	gotoxy(i,6);
	cprintf("%c",196);
	}
	gotoxy(48,2);
	cprintf("%c",191);
	gotoxy(39,6);
	cprintf("%c",192);


	for(i=2;i<6;i++){
	gotoxy(27,i);
	cprintf("%c",179);
	}
	gotoxy(27,2);
	cprintf("%c",218);
	for(i=2;i<6;i++){
	gotoxy(37,i);
	cprintf("%c",179);
	}
	gotoxy(37,2);
	cprintf("%c",191);
	gotoxy(32,2);
	cprintf("%c",194);
	for(i=28;i<32;i++){
	gotoxy(i,2);
	cprintf("%c",196);
	}
	for(i=33;i<37;i++){
	gotoxy(i,2);
	cprintf("%c",196);
	}
	for(i=3;i<6;i++){
	gotoxy(32,i);
	cprintf("%c",179);
	}
	gotoxy(32,6);
	cprintf("%c",193);
	gotoxy(27,6);
	cprintf("%c",192);
	gotoxy(37,6);
	cprintf("%c",217);
}