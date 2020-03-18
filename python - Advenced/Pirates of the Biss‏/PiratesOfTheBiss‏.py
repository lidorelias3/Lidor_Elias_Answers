def dejumble(scramble_word, list_of_correct_words):
    for correct_word in list_of_correct_words:
        temp_scramble_word = scramble_word
        if len(correct_word) == len(scramble_word):
            for letter in correct_word:
                if letter in temp_scramble_word:


if __name__ == '__main__':
    dejumble("ortsp", ['sport', 'parrot', 'ports', 'matey'])
