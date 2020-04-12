import socket

LOCAL_IP = "127.0.0.1"
PORT = 5555
BUFFER_SIZE = 1024


def send_message(clients, message, sock):
    """
    Function will send message to all the connected clients
    :param clients: A set of all clients
    :param message: The message to send
    :param sock:
    :return:
    """
    for client in clients:
        sock.sendto(message, client)


def client_management():
    """
    Function will recv messages
    :return:
    """
    clients = set()
    # create connection
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # start listening
    sock.bind((LOCAL_IP, PORT))

    while True:
        data = sock.recvfrom(BUFFER_SIZE)
        message = data[0]
        clients.add(data[1])
        send_message(clients, message, sock)
        print(str(list(clients)[-1]) + ": " + message.decode())


if __name__ == '__main__':
    client_management()
