import re

def check_password(password):
    """
    Funcion to check password policy
    :param password: the password
    :return: if the password accept our policy
    """
    check_lowercase = False
    check_number = False
    check_uppercase = False
    check_special = False

    if 6 <= len(password) <= 12:
        if re.search('[a-z]', password):
            check_lowercase = True
        if re.search('[0-9]', password):
            check_number = True
        if re.search('[A-Z]', password):
            check_uppercase = True
        if re.search('[*&^%$#@]', password):
            check_special = True

    if check_lowercase and check_number and check_uppercase and check_special:
        return True
    else:
        return False


if __name__ == '__main__':
    passwords = input("insert passwords:\n")
    for password in passwords.split(', '):
        if check_password(password):
            print(password)
