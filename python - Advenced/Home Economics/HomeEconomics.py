def calc_price(startPriceOld, startPriceNew, savingPerMonth, percentLossByMonth):
    """
    Function will calc how many month it take to buy a new car,
    according to your month saving and the depreciation value of the cars
    :param startPriceOld: The old car start price
    :param startPriceNew: The new car start price
    :param savingPerMonth: How many you save in each month
    :param percentLossByMonth: How much the depreciation of the car is
    :return: The number of months you need to save and how much money you will have after the purchase
    """
    current_money = 0
    number_of_months = 0
    current_precent_down = percentLossByMonth
    while current_money + startPriceOld * (1 - current_precent_down / 100) < startPriceNew * (
                1 - current_precent_down / 100):
        current_money += savingPerMonth
        number_of_months += 1
        if number_of_months % 2 == 0:
            current_precent_down += 0.5

    return number_of_months, round(current_money + startPriceOld * (1 - current_precent_down / 100)) - startPriceNew * (
        1 - current_precent_down / 100)


if __name__ == '__main__':
    print(calc_price(2000, 8000, 1000, 1.5))
