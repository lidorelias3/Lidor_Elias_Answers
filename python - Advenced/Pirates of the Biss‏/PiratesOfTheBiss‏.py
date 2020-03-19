import re


def dejumble(scramble_word, list_of_correct_words):
    """
    Function take scramble word and a list of a words and
    check what word in the list the scramble word can be
    :param scramble_word: word in pirate language
    :param list_of_correct_words: a list of words in our language
    :return: the words that the scramble word can make
    """
    valid_words = []
    # for each word
    for current_word in list_of_correct_words:
        if sorted(current_word) == sorted(scramble_word):
            valid_words.append(current_word)

    return valid_words


if __name__ == '__main__':
    print(dejumble("ortsp", ['sport', 'parrot', 'ports', 'matey']))
