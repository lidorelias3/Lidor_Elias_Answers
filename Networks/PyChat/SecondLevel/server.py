import socket
import select

LOCAL_IP = "127.0.0.1"
PORT = 5555
BUFFER_SIZE = 1024
clients = []


def send_message(message, black_list=[]):
    """
    Function will send message to all the connected clients
    :param black_list: Don't send message to clients in blacklist
    :param message: The message to send
    :return:
    """
    print(message)
    for client in clients[1:]:
        if client not in black_list:
            client.sendall(str.encode(message))


def client_management():
    # create connection
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind((LOCAL_IP, PORT))
    sock.listen(5)
    clients.append(sock)

    while clients:
        select_read, _, _ = select.select(clients, [], [])
        for i in select_read:
            # If new client
            if i is sock:
                client, address = sock.accept()
                clients.append(client)
                send_message("{} has logged in!".format(address))
            else:
                try:
                    # If new message
                    data = i.recv(BUFFER_SIZE)
                    send_message("{client} {message}".format(client=address, message=data.decode()))
                except:
                    # If logout
                    send_message("{} has logged out!".format(i.getpeername()), [i])
                    clients.remove(i)


if __name__ == '__main__':
    client_management()
