# ChatRoom
1.��¼
json["msgid"] = LOG_MSG_GO;
json["id"]			//�û�id
json["password"]	//����

2.��¼����
json["msgid"] = LOG_MSG_ACK;
json["id"]			//��¼�û�id
json["name"]		//��¼�û�����
json["offlinemsg"]	//������Ϣ
json["friends"]		//������Ϣ,������id��name��state�����ֶ�
json["groups"]		//Ⱥ����Ϣ,������id��groupname��groupdesc��users�����ֶ�
					//users��������id��name��state��role�ĸ��ֶ�
json["errno"]		//�����ֶΣ�����ʱ�����ó�1���û����������ó�2
json["errmsg"]		//������Ϣ

3.ע��
json["msgid"] = REG_MSG;
json["name"]		//�û�����
json["password"]	//�û�����

4.ע�ᷴ��
json["msgid"] = REG_MSG_ACK;
json["id"]			//���û���������id��
json["errno"]		//������Ϣ��ʧ�ܻᱻ����Ϊ1

5.�Ӻ���
json["msgid"] = ADD_FRIEND_MSG;
json["id"]			//��ǰ�û�id
json["friendid"]	//Ҫ�ӵĺ��ѵ�id

6.һ��һ����
json["msgid"] = ONE_CHAT_MSG;
json["id"]			//������id
json["name"]		//����������
json["to"]			//������id
json["msg"]			//��Ϣ����
json["time"]		//����ʱ��

7.����Ⱥ
json["msgid"] = CREATE_GROUP_MSG;
json["id"]			//Ⱥ������id
json["groupname"]	//Ⱥ��
json["groupdesc"]	//Ⱥ����

8.����Ⱥ
json["msgid"] = ADD_GROUP_MSG;
json["id"]			//�û�id
json["groupid"]		//Ⱥid

9.Ⱥ��
json["msgid"] = GROUP_CHAT_MSG;
json["id"]			//������id
json["name"]		//����������
json["groupid"]		//����������
json["msg"]			//��Ϣ����
json["time"]		//����ʱ��

10.ע��
json["msgid"] = LOGINOUT_MSG;
json["id"]			//Ҫע����id
```