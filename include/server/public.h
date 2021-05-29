#ifndef PUBLIC_H
#define PUBLIC_H
    /*
        server��client�Ĺ���ͷ�ļ�
    */
enum MsgType {
    LOG_MSG_GO = 1,  //��¼��Ϣ����login
    LOG_MSG_BACK,  //��¼��Ӧ��Ϣ
    REG_MSG_GO,     //ע����Ϣ����regist
    REG_MSG_ACK,    //ע����Ӧ��Ϣ
    ONE_CHAT_MSG,   //һ��һ������Ϣ
    ADD_FRIEND_MSG, //��Ӻ�����Ϣ
    SEARCH_FRIEND_MSG, //���Һ���
    SEARCH_CHATRECORD_GO, //��ѯ�����¼
    SEARCH_CHATRECORD_BACK, //��ѯ�����¼��Ӧ
    CREATE_GROUP_MSG, //����Ⱥ��
    ADD_GROUP_MSG,    //����Ⱥ��
    GROUP_CHAT_MSG,   //Ⱥ����Ϣ
    LOGINOUT_MSG,   //ע����Ϣ

    LOGIN_BACK_SUCCESS,//��½�ɹ�
    LOGIN_BACK_ISONLINE,//��½�û�������    
    LOGIN_BACK_EMPTY,//��½�û�������
    LOGIN_BACK_NOONLINE,//�û�������

};

#endif

