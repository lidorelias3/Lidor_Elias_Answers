import socket
from threading import Thread
import time
import os

LOCAL_IP = "127.0.0.1"
PORT = 5555
BUFFER_SIZE = 1024

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((LOCAL_IP, PORT))


def send_message(message):
    sock.sendall(str.encode(message))


def type_message():
    while True:
        message = input("> ")
        send_message(message)


def get_messages():
    """
    Function will send a message to the server and recv a message
    :param sock:
    :return:
    """
    try:
        while True:
            response = sock.recvfrom(BUFFER_SIZE)
            print(response[0].decode())

    except ConnectionResetError:
        print("Server is down")
        os._exit(1)


if __name__ == '__main__':
    t = Thread(target=get_messages)
    t.start()
    time.sleep(0.5)
    type_message()
