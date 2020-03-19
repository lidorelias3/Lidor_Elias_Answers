def line_valid(lines):
    x_spots = []
    straight_lines = []
    corner = []
    for y in range(len(lines)):
        for x in range(len(y)):
            # find X spot
            if spot == 'X':
                x_spots.append((x, y))
            # find straight lines
            if spot == '-':
                straight_lines.append((x, y))
            # find corners
            if spot == '+':
                corner.append((x, y))
    print(corner)
    print(x_spots)
    print(straight_lines)




grid = ["           ",
        "X---------X",
        "           ",
        "           "]
line_valid(grid)  # ---> True

'''
Examples:
grid = ["           ",
        "X---------X",
        "           ",
        "           "]
line_valid(grid)  # ---> True


grid = ["     ",
        "  X  ",
        "  |  ",
        "  |  ",
        "  X  "]
line_valid(grid)  # ---> True

# Note: this grid is only valid when starting on the right-hand X, but still considered valid
grid = ["                      ",
        "   +-------+          ",
        "   |      +++---+     ",
        "X--+      +-+   X     "]
line_valid(grid)  # ---> True


grid = [" X  ",
        " |  ",
        " +  ",
        " X  "]
line_valid(grid)  # ---> False


grid = ["              ",
        "   +------    ",
        "   |          ",
        "X--+      X   ",
        "              "]
line_valid(grid)  # ---> False


grid = ["      +------+",
        "      |      |",
        "X-----+------+",
        "      |       ",
        "      X       "]
line_valid(grid)  # ---> False


'''
