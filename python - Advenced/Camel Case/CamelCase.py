import sys


def main():
    if len(sys.argv) != 2:
        print("usage: ./CamelCase.py sentence")
        sys.exit(1)

    camleCase_to_regular = lambda sentence: ''.join(
        [' {}'.format(letter) if letter.isupper() else letter for letter in sentence])

    print(camleCase_to_regular(sys.argv[1]))


if __name__ == '__main__':
    main()
