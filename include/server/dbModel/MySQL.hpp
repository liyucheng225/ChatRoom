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
        //�ͷ�����
    ~MySQL() {
        if (conn != nullptr)
        {
            mysql_close(conn);
        }
    }

    //�������ݿ�
    bool connet() {
        MYSQL *p = mysql_real_connect(conn, SERVER, USER, PASSWD, BASENAME, 3306, nullptr, 0);
        if (p != nullptr)
        {
            //����֧�����ģ���ΪĬ����ASCII
            mysql_query(conn, "set names gbk");
            LOG_INFO << "connect mysql success!";
        }
        else
        {
            LOG_INFO << "connect mysql fail!";
        }

        return p;
    }

    //���²���
    bool update(string sql) {
        if (mysql_query(conn, sql.c_str()))
        {
            LOG_INFO << __FILE__ << " : " << __LINE__ << " : " << sql << " update error!";
            return false;
        }
        return true;
    }

    //��ѯ����
    MYSQL_RES *query(string sql)
    {
        if (mysql_query(conn, sql.c_str()))
        {
            LOG_INFO << __FILE__ << " : " << __LINE__ << " : " << sql << " select error!";
            return nullptr;
        }
        return mysql_use_result(conn);
    }

    //��ȡ����
    MYSQL *get_connection() {
        return conn;
    }
private:
    MYSQL *conn;
};


#endif