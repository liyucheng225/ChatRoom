#include "ChatService.h"

ChatService* ChatService::instance() {
    static ChatService chatService;
    return &chatService;
}

ChatService::ChatService() {

}

ChatService::~ChatService() {

}