def check_password(password):
    """
    Funcion to check password policy
    :param password: the password
    :return: if the password accept our policy
    """
    SPECIAL_CHARS = '*&^%$#@'

    check_lowercase = False
    check_number = False
    check_uppercase = False
    check_special = False

    if 6 <= len(password) <= 12:
        for letter in password:
            if letter.islower():
                check_lowercase = True
            if letter.isdigit():
                check_number = True
            if letter.isupper():
                check_uppercase = True
            if letter in SPECIAL_CHARS:
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
