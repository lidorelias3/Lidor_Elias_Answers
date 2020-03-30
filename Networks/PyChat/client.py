import socket

import threading

LOCAL_IP = "127.0.0.1"
PORT = 5555
BUFFER_SIZE = 1024


def recv_message(sock):
    while True:
        response = sock.recvfrom(BUFFER_SIZE)
        print(response)


def send_message(sock):
    while True:
        user_message = input("Enter your message: ")
        sock.sendto(str.encode(user_message), (LOCAL_IP, PORT))


if __name__ == '__main__':
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.connect((LOCAL_IP, PORT))
    threading.Thread(target=recv_message, args=(sock,)).start()
    send_message(sock)
