# ChatRoom
1.��¼
json["msgId"] = LOG_MSG_GO;
json["id"]			//�û�id
json["password"]	//����

2.��¼����
json["msgId"] = LOG_MSG_ACK;
json["id"]			//��¼�û�id
json["name"]		//��¼�û�����
json["friends"]		//������Ϣ,������id��name��state�����ֶ�
json["groups"]		//Ⱥ����Ϣ,������id��groupname��groupdesc��users�����ֶ�
					//users��������id��name��state��role�ĸ��ֶ�
json["type"]		//��������û���½�ɹ����û�������������û���������

3.ע��
json["msgId"] = REG_MSG_GO;
json["name"]		//�û�����
json["password"]	//�û�����
json["questionIndex"] //�û��ܱ�����
json["answer"] //�ܱ���

4.ע�ᷴ��
json["msgId"] = REG_MSG_ACK;
json["id"]			//�漴���ɵĲ��ظ���9λid

5.�Ӻ���
json["msgId"] = ADD_FRIEND_MSG;
json["id"]			//��ǰ�û�id
json["friendid"]	//Ҫ�ӵĺ��ѵ�id

6.һ��һ����
json["msgId"] = ONE_CHAT_MSG;
json["id"]			//������id
json["name"]		//����������
json["to"]			//������id
json["msg"]			//��Ϣ����
json["time"]		//����ʱ��

7.����Ⱥ
json["msgId"] = CREATE_GROUP_MSG;
json["id"]			//Ⱥ������id
json["groupname"]	//Ⱥ��
json["groupdesc"]	//Ⱥ����

8.����Ⱥ
json["msgId"] = ADD_GROUP_MSG;
json["id"]			//�û�id
json["groupid"]		//Ⱥid

9.Ⱥ��
json["msgId"] = GROUP_CHAT_MSG;
json["id"]			//������id
json["name"]		//����������
json["groupid"]		//����������
json["msg"]			//��Ϣ����
json["time"]		//����ʱ��

10.ע��
json["msgId"] = LOGINOUT_MSG;
json["id"]			//Ҫע����id
```