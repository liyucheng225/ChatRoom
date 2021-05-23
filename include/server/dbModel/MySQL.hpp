#ifndef MYSQL_H
#define MYSQL_H
#include <mysql/mysql.h>
#include <muduo/base/Logging.h>
using namespace std;

#define SERVER "loaclhost"
#define USER "root"
#define PASSWD "990306"
#define BASENAME "ChatRoom"

class MySQL
{
public:
    MySQL(/* args */){
        conn = mysql_init(nullptr);
    }
        //释放连接
    ~MySQL() {
        if (conn != nullptr)
        {
            mysql_close(conn);
        }
    }

    //连接数据库
    bool connet() {
        MYSQL *p = mysql_real_connect(conn, SERVER, USER, PASSWD, BASENAME, 3306, nullptr, 0);
        if (p != nullptr)
        {
            //代码支持中文，因为默认是ASCII
            mysql_query(conn, "set names gbk");
            LOG_INFO << "connect mysql success!";
        }
        else
        {
            LOG_INFO << "connect mysql fail!";
        }

        return p;
    }

    //更新操作
    bool update(string sql) {
        if (mysql_query(conn, sql.c_str()))
        {
            LOG_INFO << __FILE__ << " : " << __LINE__ << " : " << sql << " update error!";
            return false;
        }
        return true;
    }

    //查询操作
    MYSQL_RES *query(string sql)
    {
        if (mysql_query(conn, sql.c_str()))
        {
            LOG_INFO << __FILE__ << " : " << __LINE__ << " : " << sql << " select error!";
            return nullptr;
        }
        return mysql_use_result(conn);
    }

    //获取连接
    MYSQL *get_connection() {
        return conn;
    }
private:
    MYSQL *conn;
};


#endif