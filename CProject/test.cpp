/*************************************************************************
    > File Name: test.cpp
    > Author: mrcao
    > Mail: 1805448051@qq.com 
    > Created Time: 2018年07月26日 星期四 20时36分25秒
	g++ test.cpp `mysql_config --cflags --libs` -o test
 ************************************************************************/

#include <stdio.h>
#include <mysql/mysql.h>

int cppDatebase::DatabaseQuery(char *cmd, char **row)
{
	if (NULL == cmd || NULL == row)
		　　
		{
			　　　　cout << "[query] cmd error" << endl;
			　　　　return (-1);
			　　
		}

	　　mysql_real_query(dbHandle, cmd, strlen(cmd));

	　　MYSQL_RES *result = mysql_store_result(dbHandle);
	　　if (result != NULL)
　　
	{
		　　　　int numLine = mysql_num_rows(result);
		　　　　int numList = mysql_num_fields(result);
		　　
	}
	　　else 　　
	{
		　　　　cout << "[query] mysql_store_result error !" << endl;
		　　　　return (-1);
		　　
	}
	　　while ((row = mysql_fetch_row(result)))
　　
	{
		　　　　printf("%s, %s %s %s\n", row[0], row[1], row[2], row[3]);
		　　
	}
	　　mysql_free_result(result);

	　　return 0;
}

int main(int argc, char *argv[])
{
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, "localhost", "admin", "admin", "test", 0, NULL, CLIENT_FOUND_ROWS)) //"root":数据库管理员 "":root密码 "test":数据库的名字
	{
		printf("connect success!\n");
		res = mysql_query(&conn, "insert into test values('user','123456')");
		if (res)
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
