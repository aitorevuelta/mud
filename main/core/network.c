#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <network.h>


bool pingServer(char server_ip[], int server_port) {
    IPaddress ip;
    if (SDLNet_ResolveHost(&ip, server_ip, server_port) < 0) {
        return false;
    }

    TCPsocket server_socket = SDLNet_TCP_Open(&ip);
    if (!server_socket) {
        return false;
    }

    SDLNet_TCP_Close(server_socket);
    return true;
}