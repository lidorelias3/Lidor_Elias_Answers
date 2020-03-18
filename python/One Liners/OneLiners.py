from functools import reduce


def main():
    # one liner functions
    culc_sum = lambda number_list: sum(number_list)
    check_palindrome = lambda number: str(number) == str(number)[::-1]
    factorial = lambda number: reduce((lambda a, b: a * b), range(1, number + 1))

    # check functions
    print(culc_sum([1, 2, 3, 4, 5, 10]))
    print(check_palindrome(12121))
    print(factorial(6))


if __name__ == '__main__':
    main()
