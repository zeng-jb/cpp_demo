/*
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
*/
#include<windows.h>
#include<iostream>
#include <assert.h>
#include<sql.h>
#include <sqlext.h>
using namespace std;
main(){
    SQLHENV serverhenv;
    SQLHDBC serverhdbc;
    SQLHSTMT serverhstmt;
    SQLRETURN ret;
    SQLCHAR sno[20]={0},sex[20]={0},sname[20]={0},dept[20]={0},classno[20]={0},bdate[30]={0},cno[20]={0},cname[20]={0},semester[10]={10};
    SQLINTEGER grade=0,length;

    //分配环境句柄
    ret = SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&serverhenv);

    //设置环境属性
    ret = SQLSetEnvAttr(serverhenv,SQL_ATTR_ODBC_VERSION,(void*)SQL_OV_ODBC3,0);
    if(!SQL_SUCCEEDED(ret))
    {
        cout<<"AllocEnvHandle error!"<<endl;
        system("pause");
    }

    //分配连接句柄
    ret = SQLAllocHandle(SQL_HANDLE_DBC,serverhenv,&serverhdbc);
    if(!SQL_SUCCEEDED(ret))
    {
        cout<<"AllocDbcHandle error!"<<endl;
        system("pause");
    }

    //数据库连接
    ret = SQLConnect(serverhdbc,(SQLCHAR*)"test1",SQL_NTS,(SQLCHAR*)"root",SQL_NTS,(SQLCHAR*)"Zeng19980715**",SQL_NTS);//第二个参数是之前配置的数据源，后面是数据库用户名和密码
    if(!SQL_SUCCEEDED(ret))
    {
        cout<<"SQL_Connect error!"<<endl;
        system("pause");\
    }

    //分配执行语句句柄
    ret = SQLAllocHandle(SQL_HANDLE_STMT,serverhdbc,&serverhstmt);

    //执行SQL语句
    ret=SQLExecDirect(serverhstmt,(SQLCHAR*)"insert into course values('C00','数据结构',00,5,'春');",SQL_NTS);
    ret=SQLExecDirect(serverhstmt,(SQLCHAR*)"select cno,cname,semester from course",SQL_NTS);
    if(ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO){
        //绑定数据
        SQLBindCol(serverhstmt,1, SQL_C_CHAR, (void*)cno,sizeof(cno), &length);
        SQLBindCol(serverhstmt,2, SQL_C_CHAR, (void*)cname,sizeof(cname), &length);
        SQLBindCol(serverhstmt,3, SQL_C_CHAR, (void*)semester,sizeof(semester), &length);
        //将光标移动到下行,即获得下行数据
        while(SQL_NO_DATA != SQLFetch(serverhstmt))
        {
            cout<<"cno:"<<cno<<" cname:"<<cname<<" semester:"<<semester;
            cout<<endl;
        }
    }

    //释放语句句柄
    ret=SQLFreeHandle(SQL_HANDLE_STMT,serverhstmt);
    if(SQL_SUCCESS!=ret && SQL_SUCCESS_WITH_INFO != ret)
        cout<<"free hstmt error!"<<endl;

    //断开数据库连接
    ret=SQLDisconnect(serverhdbc);
    if(SQL_SUCCESS!=ret&&SQL_SUCCESS_WITH_INFO!=ret)
        cout<<"disconnected error!"<<endl;

    //释放连接句柄
    ret=SQLFreeHandle(SQL_HANDLE_DBC,serverhdbc);
    if(SQL_SUCCESS!=ret&&SQL_SUCCESS_WITH_INFO!=ret)
        cout<<"free hdbc error!"<<endl;

    //释放环境句柄句柄
    ret=SQLFreeHandle(SQL_HANDLE_ENV,serverhenv);
    if(SQL_SUCCESS!=ret&&SQL_SUCCESS_WITH_INFO!=ret)
        cout<<"free henv error!"<<endl;
    system("pause");
}
