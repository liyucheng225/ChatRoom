#ifndef PUBLIC_H
#define PUBLIC_H
    /*
        server和client的公共头文件
    */
enum MsgType {
    LOG_MSG_GO = 1,  //登录消息，绑定login
    LOG_MSG_BACK,  //登录响应消息
    REG_MSG_GO,     //注册消息，绑定regist
    REG_MSG_ACK,    //注册响应消息
    ONE_CHAT_MSG,   //一对一聊天消息
    ADD_FRIEND_MSG, //添加好友消息
    SEARCH_FRIEND_MSG, //查找好友
    SEARCH_CHATRECORD_GO, //查询聊天记录
    SEARCH_CHATRECORD_BACK, //查询聊天记录响应
    CREATE_GROUP_MSG, //创建群聊
    ADD_GROUP_MSG,    //加入群聊
    GROUP_CHAT_MSG,   //群聊消息
    LOGINOUT_MSG,   //注销消息

    LOGIN_BACK_SUCCESS,//登陆成功
    LOGIN_BACK_ISONLINE,//登陆用户以在线    
    LOGIN_BACK_EMPTY,//登陆用户不存在
    LOGIN_BACK_NOONLINE,//用户不在线

};

#endif

