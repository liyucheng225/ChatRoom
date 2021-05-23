#ifndef OFFLINEMESSAGEMODEL_H
#define OFFLINEMESSAGEMODEL_H

#include <string>
#include <vector>

using namespace std;

//����offlinemessage��Ĳ���
class OfflineMessageModel
{
public:
    //�洢�û���������Ϣ
    bool insert(int id, string msg);

    //ɾ���û���������Ϣ
    bool remove(int id);

    //��ѯ�û���������Ϣ
    vector<string> query(int id);
};
#endif