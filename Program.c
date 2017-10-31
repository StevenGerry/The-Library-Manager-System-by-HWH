/*图书信息管理系统*/
/*上海建桥学院 黄文浩 王晓峰 编写 版权所有*/
/*可视化界面的图书管理软件*/


/*头文件 声明*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct books_list/*图书信息结构体*/
{
    char author[20]; /*作者名*/
    char bookname[20]; /*书名*/
    char publisher[20]; /*出版单位*/
    char pbtime[15]; /*出版时间*/
    char loginnum[10]; /*登陆号*/
    float price; /*价格*/
    char classfy[10]; /*分类号*/
    int left;
};


struct reader_list/*读者信息结构体*/
{
    char name[20];
    char readernumber[20];\
    char borrownum[20];
    char borrowday[20];
    int numborrow;
};

struct books_list sBook[32768]=/*图书信息结构体数组*/
{};

struct reader_list sReader[32768]=/*读者信息结构体数组*/
{};

void Insert()/*图书信息录入功能*/
{
    int i,n;
    char flag;
    FILE *fp;
    fp=fopen("book.dat","a+");
    if(NULL==fp)
    {
        printf("\nERROR");
        exit(-1);
    }
    i=0;
    printf("\n===============================================");
    printf("\n||欢迎使用音乃木阪学院图书馆图书信息录入系统||\n");
    printf("===============================================\n");
    do{
            printf("\n 请输入图书登陆号:");
            fflush(stdin);
            scanf("%s",&sBook[i].loginnum);
            printf("\n 请输入图书书名:");
            fflush(stdin);
            scanf("%s",&sBook[i].bookname);
            printf("\n 请输入图书作者名:");
            fflush(stdin);
            scanf("%s",&sBook[i].author);
            printf("\n 请输入图书出版社:");
            fflush(stdin);
            scanf("%s",&sBook[i].publisher);
            printf("\n 请输入图书出版时间:");
            fflush(stdin);
            scanf("%s",&sBook[i].pbtime);
            printf("\n 请输入图书分类号:");
            fflush(stdin);
            scanf("%s",&sBook[i].classfy);
            printf("\n 请输入图书价格:");
            fflush(stdin);
            scanf("%f",&sBook[i].price);
            printf("\n 请输入图书库存:");
            fflush(stdin);
            scanf("%d",&sBook[i].left);
            printf("\n");
            printf(" ━━━━ 添加成功！━━━━");
            printf("\n 继续添加？(Y/N):");
            fflush(stdin);
            scanf("%c",&flag);
            i++;
            system("pause");
            system("cls");
    }while(flag=='Y'||flag=='y');
    n=i;
    for (i=0;i<n;i++)
    fprintf(fp,"%s_%s_%s_%s_%s_%s_%.2f_%d_\n",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,sBook[i].price,sBook[i].left);
    fclose(fp);
}



void readinsert()/*读者信息录入功能*/
{
    printf("\n===============================================");
    printf("\n||欢迎使用音乃木阪学院图书馆读者信息录入系统||\n");
    printf("===============================================\n");
    FILE *p;int i,n;
    printf("\n请输入学生数：");
    scanf("%d",&n); fflush(stdin);
    p=fopen("reader.dat","a+");
    for(i=0;i<n;i++)
    {
    system("cls");
    printf("\n请输入读者的姓名:");
    scanf("%s",&sReader[i].name);
    fflush(stdin);
    printf("\n请输入读者的学号：");
    scanf("%s",&sReader[i].readernumber);
    fflush(stdin);
    printf("\n请输入%s所借阅的图书借阅号：",sReader[i].name);
    scanf("%s",&sReader[i].borrownum);
    fflush(stdin);
    printf("\n录入读者信息成功！");
    sReader[i].numborrow=0;
    fprintf(p,"%s_%s_%s_%d_0_\n",sReader[i].name,sReader[i].readernumber,sReader[i].borrownum,sReader[i].numborrow,sReader[i].borrowday);
    }
    fclose(p);
}

void bookoutput()/*图书信息一览功能*/
{
    FILE *fp;int i,n;
    fp=fopen("book.dat","r");
    if(NULL==fp)
    {
        printf("\nERROR");
        exit(-1);
    }
    printf("\n===============================================");
    printf("\n|| 音乃木阪学院图书馆       图书信息汇总一览||\n");
    printf("===============================================\n");
    i=0;
    do
    {
    ++i;
    }
    while(fscanf(fp,"%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%f_%d_\n",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,&sBook[i].price,&sBook[i].left)!=EOF);
    n=i;
    for(i=1;i<n;i++)
    printf("\n|%s|%s|%s|%s|%s|%s|%.2f|%d|",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,sBook[i].price,sBook[i].left);
    printf("\n共有%d本图书\n",i-1);
    fclose(fp);
}

void searchbook()
{
    FILE *fp;int i,n,k;char ch[20],flag;
    int cc;
    fp=fopen("book.dat","r");
    if(NULL==fp)
    {
        printf("\nERROR");
        exit(-1);
    }
    i=0;
    do
    {
    ++i;
    }
    while(fscanf(fp,"%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%f_%d_\n",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,&sBook[i].price,&sBook[i].left)!=EOF);
    n=i;
    printf("\n===============================================");
    printf("\n||欢迎使用音乃木阪学院图书馆书库信息查询系统||\n");
    printf("===============================================\n");
    do
    {
    printf("\n请输入要查书目的名字：\n");
    scanf("%s",&ch);
    printf("查找中！.....................\n");
    for(k=0;k<n;k++)
    {

        if (strcmp(ch,sBook[k].bookname)==0)
        {
        printf("=============================\n");
        printf("|         图书已找到！      |\n");
        printf("|书名：%s\n",sBook[k].bookname);
        printf("|作者：%s\n",sBook[k].author);
        printf("|出版社：%s\n",sBook[k].publisher);
        printf("|出版时间：%s\n",sBook[k].pbtime);
        printf("|登录号：%s\n",sBook[k].loginnum);
        printf("|分类号：%s\n",sBook[k].classfy);
        printf("|库存量：%d\n",sBook[k].left);
        cc=1;
        goto bd;
        }

    }
            bd:printf("\n");
            printf(" ━━━━ 查找完成！━━━━");
            fflush(stdin);
        if (cc==0)
        {
            printf("\n");
            printf("图书未找到！！");
        }
            printf("\n 继续查找？(Y/N):");
            fflush(stdin);
            scanf("%c",&flag);
            system("pause");
            system("cls");
    }while(flag=='Y'||flag=='y');

}


void searchreader()
{
    FILE *fp;int i,n,k;char ch[20],flag;
    int cc;
    fp=fopen("reader.dat","r");
    if(NULL==fp)
    {
        printf("\nERROR");
        exit(-1);
    }
    i=0;
    do
    {
    ++i;
    }
    while(fscanf(fp,"%[^_]_%[^_]_%[^_]_%d_%[^_]_\n",sReader[i].name,sReader[i].readernumber,sReader[i].borrownum,&sReader[i].numborrow,sReader[i].borrowday)!=EOF);
    n=i;
    printf("\n===============================================");
    printf("\n||欢迎使用音乃木阪学院图书馆书库读者查询系统||\n");
    printf("===============================================\n");
    do
    {
    printf("\n请输入要查读者的学号：\n");
    scanf("%s",&ch);
    printf("查找中！.....................\n");
    for(k=0;k<n;k++)
    {

        if (strcmp(ch,sReader[k].readernumber)==0)
        {
        printf("=============================\n");
        printf("|         学生已找到！      |\n");
        printf("|姓名：%s\n",sReader[k].name);
        printf("|学号：%s\n",sReader[k].readernumber);
        printf("|借阅号：%s\n",sReader[k].borrownum);
        printf("|借阅量：%d\n",sReader[k].numborrow);
        printf("|借期：%s\n",sReader[k].borrowday);
        cc=1;
        goto bd;
        }

    }
            bd:printf("\n");
            printf(" ━━━━ 查找完成！━━━━");
            fflush(stdin);
        if (cc==0)
        {
            printf("\n");
            printf("学生未找到！！");
        }
            printf("\n 继续查找？(Y/N):");
            fflush(stdin);
            scanf("%c",&flag);
            system("pause");
            system("cls");
    }while(flag=='Y'||flag=='y');

}

void borrow()/*借书功能*/
{
    int number_borrow_book;
    char student_number[20],book_number[20],return_day[20],flag;
    int i,j,m,n,kb,kr;
    FILE *fp;
    fp=fopen("book.dat","w+");
    if(NULL==fp)
    {
        printf("\nERROR");
        exit(-1);
    }
    FILE *p;
    p=fopen("reader.dat","w+");
    if(NULL==p)
    {
        printf("\nERROR");
        exit(-1);
    }
    i=0;
    j=0;
    m=0;
    n=0;
    printf("\n===============================================");
    printf("\n||欢迎使用音乃木阪学院图书馆    书籍借阅系统||\n");
    printf("===============================================\n");
    do
    {
    ++i;
    }
    while(fscanf(fp,"%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%f_%d_\n",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,&sBook[i].price,&sBook[i].left)!=EOF);
    n=i;
    do
    {
    ++j;
    }
    while(fscanf(p,"%[^_]_%[^_]_%[^_]_%d_%[^_]_\n",sReader[j].name,sReader[j].readernumber,sReader[j].borrownum,&sReader[j].numborrow,sReader[j].borrowday)!=EOF);
    m=j;
    printf("%d  %d",m,n);
    do
    {
    printf("\n请输入学生借阅证编号：");
    scanf("%s",&student_number);
    fflush(stdin);
        do
        {
        printf("\n请输入图书登录号：");
        scanf("%s",&book_number);
        fflush(stdin);
        printf("\n请输入图书归还时间：");
        scanf("%s",&return_day);
        fflush(stdin);
        for (j=0;j<=m;j++)
        {
        if (strcmp(student_number,sReader[j].borrownum)==0)
        {
            for(i=0;i<=n;i++)
            {
                if (strcmp(book_number,sBook[i].loginnum)==0)
                {
                    printf("\n%d %d",sBook[i].left,sReader[j].numborrow);
                    sReader[j].numborrow=sReader[j].numborrow+1;
                    sBook[i].left=sBook[i].left-1;
                    strcpy(sReader[j].borrowday,return_day);
                    printf("\n%d %d",sBook[i].left,sReader[j].numborrow);
                }
            }
        }
        }
    printf(" ━━━━ 借阅完成！━━━━");
    printf("\n");
    fflush(stdin);
    printf("\n 继续为本学生办理借阅？(Y/N):");
    fflush(stdin);
    scanf("%c",&flag);
    system("pause");
    system("cls");
    }while(flag=='Y'||flag=='y');
    printf("\n");
    fflush(stdin);
    printf("\n 继续办理他人借阅？(Y/N):");
    fflush(stdin);
    scanf("%c",&flag);
    system("pause");
    system("cls");
    }while(flag=='Y'||flag=='y');
    for (i=0;i<n;i++)
    {
    fprintf(fp,"%s_%s_%s_%s_%s_%s_%.2f_%d_\n",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,sBook[i].price,sBook[i].left);
    }
    fclose(fp);
    for (j=0;j<m;j++)
    {
    fprintf(p,"%s_%s_%s_%d_%s_",sReader[j].name,sReader[j].readernumber,sReader[j].borrownum,sReader[j].numborrow,sReader[j].borrowday);
    }
    fclose(p);
}


void returnbook()/*还书功能*/
{
    int number_borrow_book;
    char student_number[20],book_number[20],return_day[20],flag;
    char str[]="0";
    int i,j,m,n,kb,kr;
    FILE *fp;
    fp=fopen("book.dat","w+");
    if(NULL==fp)
    {
        printf("\nERROR");
        exit(-1);
    }
    FILE *p;
    p=fopen("reader.dat","w+");
    if(NULL==p)
    {
        printf("\nERROR");
        exit(-1);
    }
    i=0;
    j=0;
    m=0;
    n=0;
    printf("\n===============================================");
    printf("\n||欢迎使用音乃木阪学院图书馆    书籍归还系统||\n");
    printf("===============================================\n");
    do
    {
    ++i;
    }
    while(fscanf(fp,"%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%f_%d_\n",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,&sBook[i].price,&sBook[i].left)!=EOF);
    n=i;
    do
    {
    ++j;
    }
    while(fscanf(p,"%[^_]_%[^_]_%[^_]_%d_%[^_]_\n",sReader[j].name,sReader[j].readernumber,sReader[j].borrownum,&sReader[j].numborrow,sReader[j].borrowday)!=EOF);
    m=j;
    do
    {
    printf("\n请输入学生借阅证编号：");
    scanf("%s",&student_number);
    fflush(stdin);
        do
        {
        printf("\n请输入图书登录号：");
        scanf("%s",&book_number);
        fflush(stdin);
        for (j=0;j<=m;j++)
        {
        if (strcmp(student_number,sReader[j].borrownum)==0)
        {
            for(i=0;i<=n;i++)
            {
                if (strcmp(book_number,sBook[i].loginnum)==0)
                {
                    printf("\n%d %d",sBook[i].left,sReader[j].numborrow);
                    sReader[j].numborrow=sReader[j].numborrow-1;
                    sBook[i].left=sBook[i].left+1;
                    strcpy(sReader[j].borrowday,str);
                    printf("\n%d %d",sBook[i].left,sReader[j].numborrow);
                }
            }
        }
        }
    printf(" ━━━━ 归还完成！━━━━");
    printf("\n");
    fflush(stdin);
    printf("\n 继续为本学生办理还书？(Y/N):");
    fflush(stdin);
    scanf("%c",&flag);
    system("pause");
    system("cls");
    }while(flag=='Y'||flag=='y');
    printf("\n");
    fflush(stdin);
    printf("\n 继续办理他人还书？(Y/N):");
    fflush(stdin);
    scanf("%c",&flag);
    system("pause");
    system("cls");
    }while(flag=='Y'||flag=='y');
    for (i=0;i<n;i++)
    {
    fprintf(fp,"%s_%s_%s_%s_%s_%s_%.2f_%d_\n",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,sBook[i].price,sBook[i].left);
    }
    fclose(fp);
    for (j=0;j<m;j++)
    {
    fprintf(p,"%s_%s_%s_%d_%s_",sReader[j].name,sReader[j].readernumber,sReader[j].borrownum,sReader[j].numborrow,sReader[j].borrowday);
    }
    fclose(p);
}



void rewritebook()/*修改图书信息功能*/
{
    int i,n,k;
    char code[20];
    i=0;k=0;
    system("cls");
    FILE *fp;
    fp=fopen("book.dat","w+");
    if(NULL==fp)
    {
        printf("\nERROR");
        exit(-1);
    }
    do
    {
    ++i;
    }while(fscanf(fp,"%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%f_%d_\n",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,&sBook[i].price,&sBook[i].left)!=EOF);
    n=i;
    fflush(stdin);
    printf("\n===============================================");
    printf("\n||欢迎使用音乃木阪学院图书馆图书信息修改系统||\n");
    printf("===============================================\n");
    printf("\n");
    printf("\n请输入要修改图书的登陆号：");
    gets(code);
    fflush(stdin);
    for (i=0;i<=n;i++)
    {
        if (strcmp(code,sBook[i].loginnum)==0)
        {
            printf("\n 请修改图书书名:");
            fflush(stdin);
            scanf("%s",&sBook[i].bookname);
            printf("\n 请修改图书作者名:");
            fflush(stdin);
            scanf("%s",&sBook[i].author);
            printf("\n 请修改图书出版社:");
            fflush(stdin);
            scanf("%s",&sBook[i].publisher);
            printf("\n 请修改图书出版时间:");
            fflush(stdin);
            scanf("%s",&sBook[i].pbtime);
            printf("\n 请修改图书分类号:");
            fflush(stdin);
            scanf("%s",&sBook[i].classfy);
            printf("\n 请修改图书价格:");
            fflush(stdin);
            scanf("%f",&sBook[i].price);
            printf("\n 请修改图书库存:");
            fflush(stdin);
            scanf("%d",&sBook[i].left);
            printf("\n");
            goto pt;
        }
    }
    pt:for (i=0;i<n;i++)
    {
    fprintf(fp,"%s_%s_%s_%s_%s_%s_%.2f_%d_\n",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,sBook[i].price,sBook[i].left);
    }
    fclose(fp);
}

void delbook()/*删除图书信息*/
{
    int i,n,k,ii;
    char code[20];
    i=0;k=0;
    system("cls");
    FILE *fp;
    fp=fopen("book.dat","w+");
    if(NULL==fp)
    {
        printf("\nERROR");
        exit(-1);
    }
    do
    {
    ++i;
    }while(fscanf(fp,"%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%[^_]_%f_%d_\n",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,&sBook[i].price,&sBook[i].left)!=EOF);
    n=i;
    fflush(stdin);
    printf("\n===============================================");
    printf("\n||欢迎使用音乃木阪学院图书馆书库图书删除系统||\n");
    printf("===============================================\n");
    printf("\n");
    printf("\n请输入要删除图书的登陆号：");
    gets(code);
    fflush(stdin);
    for (i=0;i<=n;i++)
    {
        if (strcmp(code,sBook[i].loginnum)==0)
        {
            k=i;
        }
    }
        printf("\n您要删除的图书信息如下：");
        printf("|书名：%s\n",sBook[i].bookname);
        printf("|作者：%s\n",sBook[i].author);
        printf("|出版社：%s\n",sBook[i].publisher);
        printf("|出版时间：%s\n",sBook[i].pbtime);
        printf("|登录号：%s\n",sBook[i].loginnum);
        printf("|分类号：%s\n",sBook[i].classfy);
        printf("|库存量：%d\n",sBook[i].left);
    for (i=k;i<=n;i++)
    {
        ii=i+1;
        strcpy(sBook[i].loginnum,sBook[ii].loginnum);
        strcpy(sBook[i].bookname,sBook[ii].bookname);
        strcpy(sBook[i].author,sBook[ii].author);
        strcpy(sBook[i].publisher,sBook[ii].publisher);
        strcpy(sBook[i].pbtime,sBook[ii].pbtime);
        strcpy(sBook[i].classfy,sBook[ii].classfy);
        sBook[i].price=sBook[ii].price;
        sBook[i].left=sBook[ii].left;
    }
    printf("\n——————删除完成——————\n");
    for (i=0;i<n;i++)
    {
    fprintf(fp,"%s_%s_%s_%s_%s_%s_%.2f_%d_\n",sBook[i].loginnum,sBook[i].bookname,sBook[i].author,sBook[i].publisher,sBook[i].pbtime,sBook[i].classfy,sBook[i].price,sBook[i].left);
    }
    fclose(fp);
    system("pause");
}

int main(void)/*主程序*/
{
    int i;char choice;
    system("color 71");
        st:for(;;)
        {
            printf(" ┏━┓━━━━━━━━━━━━━━━━━━━┏━┓\n");
            printf(" ┃  ┃       音乃木阪学院图书管理系统       ┃  ┃\n");
            printf(" ┃  ┗━━━━━━━━━━━━━━━━━━━┛  ┃\n");
            printf(" ┃ ->[1]图书信息录入                            ┃\n");
            printf(" ┃                                              ┃\n");
            printf(" ┃ ->[2]图书信息浏览                            ┃\n");
            printf(" ┃                                              ┃\n");
            printf(" ┃ ->[3]图书信息查询                            ┃\n");
            printf(" ┃                           /   | / _____      ┃\n");
            printf(" ┃ ->[4]图书信息修改        /|   |  |_____      ┃\n");
            printf(" ┃                         / |___|   ____|      ┃\n");
            printf(" ┃ ->[5]图书信息删除      /                     ┃\n");
            printf(" ┃                                              ┃\n");
            printf(" ┃ ->[6]图书借出功能                            ┃\n");
            printf(" ┃                                              ┃\n");
            printf(" ┃ ->[7]图书归还功能         ラブライブ!        ┃\n");
            printf(" ┃                            LoveLive!         ┃\n");
            printf(" ┃ ->[8]读者信息输入                            ┃\n");
            printf(" ┃                                              ┃\n");
            printf(" ┃ ->[9]读者信息查询                            ┃\n");
            printf(" ┃                                     Gench(c) ┃\n");
            printf(" ┃ ->[0]X退 出 系 统       上海缪斯信息技术公司 ┃\n");
            printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━┛\n");
            printf(" 请选择:");fflush(stdin);
            scanf("%c",&choice);
            if(choice=='1')
            {
                system("cls");
                Insert();
                system("cls");
            }
            else if(choice=='2')
            {
                system("cls");
                bookoutput();
                system("pause");
                system("cls");
            }
            else if(choice=='3')
            {
                system("cls");
                searchbook();
                system("cls");
            }
            else if(choice=='4')
            {
                system("cls");
                rewritebook();
                system("cls");
            }
            else if(choice=='5')
            {
                system("cls");
                delbook();
                system("cls");
            }
            else if(choice=='6')
            {
                system("cls");
                borrow();
                system("cls");
            }
            else if(choice=='7')
            {
                system("cls");
                returnbook();
                system("cls");
            }
            else if(choice=='8')
            {
                system("cls");
                readinsert();
                system("pause");
                system("cls");
            }
            else if(choice=='9')
            {
                system("cls");
                searchreader();
                system("cls");
            }
            else if(choice=='0')
            {
                printf("\n");
                printf(" ━━━━━━━━ 感谢使用图书管理系统 ━━━━━━━━\n");
                break;
            }
            else
            {
                printf(" ━━━━ 输入错误，请重新输入！━━━━\n");
                system("pause");
                system("cls");
                goto st;
                break;
            }
        }
    return 0;
}
