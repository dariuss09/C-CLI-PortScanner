#include <iostream>
#include <vector>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

bool is_port_open(const std::string& ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        return false;
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &server.sin_addr);

    int result = connect(sock, (struct sockaddr*)&server, sizeof(server));
    close(sock);
    
    return result == 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Utilizare: " << argv[0] << " <Adresa_IP>\n";
        return 1;
    }

    std::string ip = argv[1];
    std::cout << "Se scanează porturile pentru IP-ul: " << ip << "...\n";

    std::vector<int> common_ports = {21, 22, 23, 80, 443, 3306, 8080};

    for (int port : common_ports) {
        if (is_port_open(ip, port)) {
            std::cout << "[+] Port " << port << " - DESCHIS\n";
        }
    }

    std::cout << "Scanare finalizată.\n";
    return 0;
}
