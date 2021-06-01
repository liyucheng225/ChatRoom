# ChatRoom
1.登录
json["msgId"] = LOG_MSG_GO;
json["id"]			//用户id
json["password"]	//密码

2.登录反馈
json["msgId"] = LOG_MSG_ACK;
json["id"]			//登录用户id
json["name"]		//登录用户密码
json["friends"]		//好友信息,里面有id、name、state三个字段
json["groups"]		//群组信息,里面有id，groupname，groupdesc，users三个字段
					//users里面则有id，name，state，role四个字段
json["type"]		//里面包含用户登陆成功，用户名或密码错误，用户在线三种

3.注册
json["msgId"] = REG_MSG_GO;
json["name"]		//用户姓名
json["password"]	//用户姓名
json["questionIndex"] //用户密保问题
json["answer"] //密保答案

4.注册反馈
json["msgId"] = REG_MSG_ACK;
json["id"]			//随即生成的不重复的9位id

5.加好友
json["msgId"] = ADD_FRIEND_MSG;
json["id"]			//当前用户id
json["friendid"]	//要加的好友的id

6.一对一聊天
json["msgId"] = ONE_CHAT_MSG;
json["id"]			//发送者id
json["name"]		//发送者姓名
json["to"]			//接受者id
json["msg"]			//消息内容
json["time"]		//发送时间

7.创建群
json["msgId"] = CREATE_GROUP_MSG;
json["id"]			//群创建者id
json["groupname"]	//群名
json["groupdesc"]	//群描述

8.加入群
json["msgId"] = ADD_GROUP_MSG;
json["id"]			//用户id
json["groupid"]		//群id

9.群聊
json["msgId"] = GROUP_CHAT_MSG;
json["id"]			//发送者id
json["name"]		//发送者姓名
json["groupid"]		//发送者姓名
json["msg"]			//消息内容
json["time"]		//发送时间

10.注销
json["msgId"] = LOGINOUT_MSG;
json["id"]			//要注销的id
```