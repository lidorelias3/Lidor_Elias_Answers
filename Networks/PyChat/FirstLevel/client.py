import socket

LOCAL_IP = "127.0.0.1"
PORT = 5555
BUFFER_SIZE = 1024


def send_message(sock):
    """
    Function will send a message to the server and recv a message
    :param sock:
    :return:
    """
    try:
        while True:
            user_message = input("> ")
            sock.sendto(str.encode(user_message), (LOCAL_IP, PORT))
            response = sock.recvfrom(BUFFER_SIZE)
            print(response[0].decode())
    except ConnectionResetError:
        print("Server is down")

if __name__ == '__main__':
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    send_message(sock)
