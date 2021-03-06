import sys
import re


def get_words_frequency(filename):
    """
        Function will get a file and return how many times each word appear in that file.
        :param filename:
        :return dict with each word frequency:
    """

    words_count = {}
    try:
        with open(filename, 'r') as file:
            # Make a list of each word with out whitespaces and quats
            words = [word.strip().lower().replace("'", "") for word in
                     re.findall(r'[a-zA-Z\']+', file.read())]
            # Add to dictionary
            for word in words:
                if word in words_count:
                    words_count[word] += 1
                elif word != '':
                    words_count[word] = 1
    except:
        print("Error while opening: {}".format(filename))

    return words_count


def print_words(filename):
    """
    Function will print all the words in a file and tell how many times each word appears.
    :param filename:
    :return:
    """
    print("print_words")
    # Sort by keys
    words = dict(sorted(get_words_frequency(filename).items()))
    for word, frequency in words.items():
        print(word, frequency)


def print_top(filename):
    """
    Function will print the top 20 words in a file and tell how many times each word appears.
    :param filename:
    :return:
    """
    print("print_top")
    # Sort by values
    words = sorted(get_words_frequency(filename).items(), key=lambda x: x[1], reverse=True)
    words = words[:20] if len(words) >= 20 else words
    for word, frequency in words:
        print(word, frequency)


def main():
    if len(sys.argv) != 3:
        print("usage: ./wordcount.py {--count | --topcount} file")
        sys.exit(1)

    option = sys.argv[1]
    filename = sys.argv[2]
    if option == '--count':
        print_words(filename)
    elif option == '--topcount':
        print_top(filename)

    else:
        print("unknown option: " + option)
        sys.exit(1)


if __name__ == '__main__':
    main()
