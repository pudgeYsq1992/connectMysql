#include <stdio.h>
#include <mysql.h>

int main(int argc, char *argv[])
{
	MYSQL conn;
	int res;
	mysql_init(&conn);
	printf("init over!\n");
	if(mysql_real_connect(&conn,"localhost","","","test",0,NULL,CLIENT_FOUND_ROWS)) // 第二个参数是user,默认为当前用户,如果用户不匹配则无法连接.
		
	{
		printf("connect success!\n");
		res=mysql_query(&conn,"insert into test values('user','123456')");
		if(res)
		{
			printf("error\n");
		}
		else
		{
			printf("OK\n");
		}
		mysql_close(&conn);
	}
	return 0;
}
