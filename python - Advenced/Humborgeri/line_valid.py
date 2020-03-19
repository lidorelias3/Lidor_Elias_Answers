import math
import re


def format_spots(lines):
    """
    Function will convert the lines string to a dict we can work with
    :param lines: The map in string
    :return: Dict of spots to each important spot
    """
    spots = {'x': [], 'horizontal': [], 'vertical': [], 'corner': []}

    for y in range(len(lines)):
        for x in range(len(lines[y])):
            # find X spot
            if lines[y][x] == 'X':
                spots['x'].append((x, y))
            # find horizontal lines
            elif lines[y][x] == '-':
                spots['horizontal'].append((x, y))
            # find vertical lines
            elif lines[y][x] == '|':
                spots['vertical'].append((x, y))
            # find corners
            elif lines[y][x] == '+':
                spots['corner'].append((x, y))
            elif lines[y][x] != ' ':
                raise ValueError
    return spots


def check_what_around(spots, spot, curr_direction=None):
    """
    Function will check what around a given spot in the direction we can move
    :param spots: the dict of spots
    :param spot: the spot to check around
    :param curr_direction: the direction we allow to move
    :return: a dict with what around the spot
    """
    spots_around = {'x': [], 'horizontal': [], 'vertical': [], 'corner': []}
    for key in spots.keys():
        if (curr_direction is None or curr_direction == 'horizontal') and key != 'vertical':
            if (spot[0] + 1, spot[1]) in spots[key]:
                spots_around[key].append((spot[0] + 1, spot[1]))
            if (spot[0] - 1, spot[1]) in spots[key]:
                spots_around[key].append((spot[0] - 1, spot[1]))
        if (curr_direction is None or curr_direction == 'vertical') and key != 'horizontal':
            if (spot[0], spot[1] + 1) in spots[key]:
                spots_around[key].append((spot[0], spot[1] + 1))
            if (spot[0], spot[1] - 1) in spots[key]:
                spots_around[key].append((spot[0], spot[1] - 1))

    return spots_around


def check_direction(prev_spot, next_spot):
    """
    Fuction will check what direction we going by a 2 point
    :param prev_spot: previous spot
    :param next_spot: next spot
    :return: horizontal or vertical
    """
    if (prev_spot[0] + 1 == next_spot[0] and prev_spot[1] == next_spot[1]) or (
                        prev_spot[0] - 1 == next_spot[0] and prev_spot[1] == next_spot[1]):
        return 'horizontal'
    if (prev_spot[0] == next_spot[0] and prev_spot[1] + 1 == next_spot[1]) or (
                    prev_spot[0] == next_spot[0] and prev_spot[1] - 1 == next_spot[1]):
        return 'vertical'


def calc_distance(first_point, second_point):
    """
    Calc distance between two points
    :param first_point:
    :param second_point:
    :return: the distence
    """
    return math.sqrt(abs((first_point[0] - second_point[0]) ** 2 + (first_point[1] - second_point[1]) ** 2))


def check_what_closer(spots, corner_spot, end_spot, current_direction):
    """
    Check where we need to go
    :param spots:
    :param corner_spot:
    :param end_spot:
    :param current_direction:
    :return:
    """
    # check if we need to go left or right
    if current_direction == 'horizontal':
        around_spots = check_what_around(spots, corner_spot, 'vertical')
        spot_to_check = around_spots['vertical']
        spot_to_check.extend(around_spots['corner'])
        if len(spot_to_check) > 1:
            if calc_distance(spot_to_check[0], end_spot) > calc_distance(spot_to_check[1], end_spot):
                return spot_to_check[1]
            else:
                return spot_to_check[0]
        else:
            return spot_to_check[0]
    # check if we need to go up or down
    if current_direction == 'vertical':
        around_spots = check_what_around(spots, corner_spot, 'horizontal')
        spot_to_check = around_spots['horizontal']
        spot_to_check.extend(around_spots['corner'])
        if len(spot_to_check) > 1:
            if calc_distance(spot_to_check[0], end_spot) > calc_distance(spot_to_check[1], end_spot):
                return spot_to_check[1]
            else:
                return spot_to_check[0]
        else:
            return spot_to_check[0]


def check_if_board_empty(spots):
    for key, val in spots.items():
        if key != 'x':
            if val:
                return True
    return False


def check_if_valid(lines, start_point, end_point):
    """
    check if the map is valid
    :param lines: the map string
    :param start_point: which 'X' to start
    :return: True if valid false if not
    """
    spots = format_spots(lines)
    start = spots['x'][start_point]
    end = spots['x'][end_point]
    curr_spot = start
    prev_spot = curr_spot
    curr_direction = None
    number_of_ways = 0
    spot_around = check_what_around(spots, curr_spot)

    if spot_around['x'] and spot_around['x'][0] != start:
        number_of_ways += 1
    while True:
        # if we got '-'
        if spot_around['horizontal']:
            curr_direction = 'horizontal'
            if len(spot_around['horizontal']) > 1:
                return False
            curr_spot = spot_around['horizontal'][0]
            spots['horizontal'].remove(curr_spot)

        # if we got '|'
        if spot_around['vertical']:
            curr_direction = 'vertical'
            if len(spot_around['vertical']) > 1:
                return False
            curr_spot = spot_around['vertical'][0]
            spots['vertical'].remove(curr_spot)

        # if we got '+' we will change our direction
        if spot_around['corner']:
            if curr_direction is None:
                curr_direction = check_direction(prev_spot, spot_around['corner'][0])
            if curr_direction == 'vertical':
                curr_direction = 'horizontal'
            elif curr_direction == 'horizontal':
                curr_direction = 'vertical'
            curr_spot = check_what_closer(spots, curr_spot, end, curr_direction)
            if curr_spot is None:
                return False
            spots['corner'].remove(curr_spot)

        # if we got 'X' we done
        if spot_around['x'] and spot_around['x'][0] != start and not check_if_board_empty(spots) and curr_spot != start:
            number_of_ways += 1
        if prev_spot == curr_spot:
            break
        spot_around = check_what_around(spots, curr_spot, curr_direction)
        prev_spot = curr_spot
    if number_of_ways == 1:
        return True
    else:
        return False


def line_valid(lines):
    """
    Function will check to either 'X' spots
    :param lines:
    :return:
    """
    try:
        if not check_if_valid(lines, 0, 1):
            if not check_if_valid(lines, 1, 0):
                return False
        return True
    except ValueError:
        pass


grid = ["           ",
        "X---------X",
        "           ",
        "           "]
print(line_valid(grid))  # ---> True

grid = ["     ",
        "  X  ",
        "  |  ",
        "  |  ",
        "  X  "]
print(line_valid(grid))  # ---> True

# Note: this grid is only valid when starting on the right-hand X, but still considered valid
grid = ["                      ",
        "   +-------+          ",
        "   |      +++---+     ",
        "X--+      +-+   X     "]
print(line_valid(grid))  # ---> True

grid = [" X  ",
        " |  ",
        " +  ",
        " X  "]
print(line_valid(grid))  # ---> False

grid = ["              ",
        "   +------    ",
        "   |          ",
        "X--+      X   ",
        "              "]
print(line_valid(grid))  # ---> False

grid = ["      +------+",
        "      |      |",
        "X-----+------+",
        "      |       ",
        "      X       "]
print(line_valid(grid))  # ---> False

grid = ["X          ",
        "X          ",
        "           ",
        "           ",
        "           "]
print(line_valid(grid))  # ---> False

grid = ["X---------+",
        "X         |",
        "|         |",
        "|         |",
        "+---------+"]
print(line_valid(grid))  # ---> False

grid = ["    ++    ",
        "   ++++   ",
        "   ++++   ",
        "  X-++-X  "]
print(line_valid(grid))  # ---> False
