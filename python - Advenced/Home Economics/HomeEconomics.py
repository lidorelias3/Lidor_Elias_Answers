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
    current_percent_down = percentLossByMonth
    current_old_car_value = startPriceOld
    current_new_car_value = startPriceNew
    number_of_months = 0
    while current_money + current_old_car_value < current_new_car_value:
        number_of_months += 1
        if number_of_months % 2 == 0:
            current_percent_down += 0.5
        current_money += savingPerMonth
        if current_money + current_old_car_value > current_new_car_value:
            break
        current_old_car_value *= (1 - current_percent_down / 100)
        current_new_car_value *= (1 - current_percent_down / 100)
    return number_of_months, round(current_money + current_old_car_value * (1 - current_percent_down / 100) - current_new_car_value * (1 - current_percent_down / 100))


if __name__ == '__main__':
    print(calc_price(2000, 8000, 1000, 1.5))
