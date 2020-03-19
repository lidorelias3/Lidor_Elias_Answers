import string


# xor char with key
def xor(char, xor_with):
    return chr(int(char) ^ ord(xor_with))


# check if all the chars printable
def check_if_printable(text):
    for char in text:
        if 32 >= ord(char) or ord(char) <= 122:
            return False
    return True


def main():
    # get data from file
    with open('big_secret.txt', 'r') as file:
        file_data = file.read()
    counter = 0

    # brute force each option
    for a in string.ascii_lowercase:
        for b in string.ascii_lowercase:
            for c in string.ascii_lowercase:
                clear_text = ""
                for char in file_data.split(','):
                    if counter % 3 == 0:
                        clear_text += xor(char, a)
                    if counter % 3 == 1:
                        clear_text += xor(char, b)
                    if counter % 3 == 2:
                        clear_text += xor(char, c)
                    counter += 1

                if check_if_printable(clear_text):
                    print(clear_text)


if __name__ == '__main__':
    main()
