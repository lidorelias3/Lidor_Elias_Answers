def return_all_evens(array):
    """
    Function will return a new list with only even numbers.
    :param array:
    :return new list with only even numbers:
    """
    array_without_odds = []

    for num in array:
        try:
            if num % 2 == 0:
                array_without_odds.append(num)
        except TypeError:
            print("{} is not a number".format(num))
    return array_without_odds


if __name__ == '__main__':
    print(return_all_evens([1010, 1, 2, 3, 4, 5, 10, 50, 'b', 25, 23, 26, 100, 'a']))
