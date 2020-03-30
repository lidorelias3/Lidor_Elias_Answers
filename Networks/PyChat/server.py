import socket

LOCAL_IP = "127.0.0.1"
PORT = 5555
BUFFER_SIZE = 1024


def send_message(clients, message, sock):
    for client in clients:
        sock.sendto(message, client)





def client_management():
    clients = []
    # create connection
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # start listening
    sock.bind((LOCAL_IP, PORT))

    print("UDP server up and listening")

    while True:
        data = sock.recvfrom(BUFFER_SIZE)
        message = data[0]
        clients.append(data[1])
        send_message(clients, message, sock)
        print(clients, message)



if __name__ == '__main__':
    client_management()
