import math


class PLANE(object):
    def __init__(self):
        self.x = 0
        self.y = 0
        self.DIRECTION = {'UP': lambda s, steps: setattr(s, 'y', s.y + steps),
                          'DOWN': lambda s, steps: setattr(s, 'y', s.y - steps),
                          'LEFT': lambda s, steps: setattr(s, 'x', s.x - steps),
                          'RIGHT': lambda s, steps: setattr(s, 'x', s.x + steps)}

    def movement(self, direction, number_of_steps):
        """
        Function will move the plane X step to the Y direction
        :param direction: The location to move for
        :param number_of_steps: How many step
        :return: None
        """
        if direction not in self.DIRECTION.keys():
            raise ValueError
        self.DIRECTION[direction](self, number_of_steps)
        print(self.x, self.y)

    def calc_distance(self, from_point):
        """
        Function return the distance between the plane to the start point
        :param from_point: Start point
        :return: The distance
        """
        return math.sqrt(abs((from_point[0] - self.x) ** 2 + (from_point[1] - self.y) ** 2))


if __name__ == '__main__':
    user_input = [None]
    curr_plain = PLANE()
    print("Please write the plan direction followed by the number of steps")
    while user_input[0] != '0':
        try:
            user_input = input().split(' ')
            # Check if input valid
            if len(user_input) == 2 and user_input[1].isnumeric():
                direction = user_input[0]
                steps = user_input[1]
                curr_plain.movement(direction.upper(), int(steps))
            # Print the distance
            elif user_input[0] == '0':
                print(int(curr_plain.calc_distance((0, 0))))
            else:
                print("Invalid input")
        except ValueError:
            print("The plane can move in the following directions: UP, DOWN, LEFT, RIGHT"
                  " Please make sure to add the number of steps")
