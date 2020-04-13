import socket
from threading import Thread
import argparse

IP = "127.0.0.1"
PORT = 6595
BUFFER = 1024

client_address = None
client_sock = None
server_sock = None

parser = argparse.ArgumentParser(description="Tunneling program")
parser.add_argument('-i', '--ip', type=str, help="IP to connect to")
parser.add_argument('-p', '--port', type=int, help="Port to connect to")
parser.add_argument('-sp', '--server_protocol', type=str, help="TCP/UDP", default="TCP")
parser.add_argument('-cp', '--client_protocol', type=str, help="TCP/UDP", default="TCP")
args = parser.parse_args()


def encode_message(message):
    encoded_message = ""
    for letter in message:
        encoded_message += chr(ord(letter) ^ (ord(letter) + 1))
    return encoded_message


def listen_to_client():
    global client_sock
    if args.client_protocol == "UDP":
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.bind((IP, PORT))
        client_sock = sock
    else:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.bind((IP, PORT))
        sock.listen(1)
        client_sock, address = sock.accept()
        print("client connected")


def connect_to_server():
    global server_sock
    if args.server_protocol == "UDP":
        server_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        server_sock.sendto(b"", (args.ip, args.port))
    else:
        server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_sock.connect((args.ip, args.port))
    print("connect to server")


def from_client_to_server():
    global client_address
    while True:
        if args.client_protocol == "UDP":
            message_recv, client_address = client_sock.recvfrom(BUFFER)
            print("client connected")
        else:
            message_recv = client_sock.recv(BUFFER)
        print(message_recv.decode())
        message_recv = encode_message(message_recv.decode()).encode() if message_recv is not None else message_recv
        if args.server_protocol == "UDP":
            server_sock.sendto(message_recv, (args.ip, args.port))
        else:
            server_sock.sendall(message_recv)


def from_server_to_client():
    while True:
        if args.server_protocol == "UDP":
            message_recv, address = server_sock.recvfrom(BUFFER)
            if message_recv == b"":
                message_recv, address = server_sock.recvfrom(BUFFER)
        else:
            message_recv = server_sock.recv(BUFFER)
        print(message_recv)
        if args.client_protocol == "UDP":
            while client_address is None:
                pass
            client_sock.sendto(message_recv, client_address)
        else:
            client_sock.sendall(message_recv)


if __name__ == '__main__':
    listen_to_client()
    connect_to_server()

    t1 = Thread(target=from_client_to_server)
    t2 = Thread(target=from_server_to_client)

    t1.start()
    t2.start()


# python Tunnle.py -i "127.0.0.1" -p 5555 -sp TCP -cp UDP
