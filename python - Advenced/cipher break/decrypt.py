import string


def xor(char, xor_with):
    """
    Function xor between a char and a value to xor with
    :param char:
    :param xor_with:
    :return: the xored value
    """
    return chr(int(char) ^ ord(xor_with))


def check_if_printable(text):
    """
    Check how many word in the text in a common english words list
    :param text: the text
    :return: If it possible to be the real text
    """
    common_english_words = ["the", "of", "to", "and", "a", "in", "is", "it", "you", "that", "he", "was", "for", "on",
                            "are", "with", "as", "I", "his", "they", "be", "at", "one", "have", "this", "from", "or",
                            "had", "by", "not", "word", "but", "what", "some", "we", "can", "out", "other", "were",
                            "all", "there", "when", "up", "use", "your", "how", "said", "an", "each", "she", "which",
                            "do", "their", "time", "if", "will", "way", "about", "many", "then", "them", "write",
                            "would", "like", "so", "these", "her", "long", "make", "thing", "see", "him", "two", "has",
                            "look", "more", "day", "could", "go", "come", "did", "number", "sound", "no", "most",
                            "people", "my", "over", "know", "water", "than", "call", "first", "who", "may", "down",
                            "side", "been", "now", "find", "any", "new", "work", "part", "take", "get", "place", "made",
                            "live", "where", "after", "back", "little", "only", "round", "man", "year", "came", "show",
                            "every", "good", "me", "give", "our", "under", "name", "very", "through", "just", "form",
                            "sentence", "great", "think", "say", "help", "low", "line", "differ", "turn", "cause",
                            "much", "mean", "before", "move", "right", "boy", "old", "too", "same", "tell", "does",
                            "set", "three", "want", "air", "well", "also", "play", "small""end", "put", "home"]
    common_words_in_our_text = []
    for word in text.split(' '):
        if word.lower() in common_english_words:
            common_words_in_our_text.append(word)

    # if 40% word from the text in the common word it high chance that it will be the text
    if len(common_words_in_our_text) > len(text.split(' ')) * 0.40:
        return True
    else:
        return False


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
