import sys


def replace_every_second_word(sentence, word_to_replace="biss10"):
    """
    Function will return a new string. In the new string each even word will replace to a new word
    :param sentence: the sentence
    :param word_to_replace: optional - the new word. default - 'biss10'
    :return: a new sentense
    """
    new_sentence = []
    even = False
    for word in sentence.split(' '):
        if even:
            new_sentence.append(word_to_replace)
            even = False
        else:
            new_sentence.append(word)
            even = True

    return ' '.join(new_sentence)


def main():
    if len(sys.argv) != 2:
        print("usage: ./WordSwap.py sentence")
        sys.exit(1)

    sentence = sys.argv[1]
    print(replace_every_second_word(sentence))


if __name__ == '__main__':
    main()
