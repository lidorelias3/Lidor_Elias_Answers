#include <stdio.h>

#define WATER 2
#define AIR 2
#define FIRE 4
#define LAND 4

typedef struct pokemon
{
	int attack;
	int defense;
	int effectiveness;
	char* name;
}pokemon;

void winner_pokemon(pokemon first, pokemon second);

int main()
{
	pokemon first = { 20, 25, FIRE, "Lidor" };
	pokemon second = { 80, 25, LAND, "Elias" };

	winner_pokemon(first, second);
	system("PAUSE");
	return 0;
}

void winner_pokemon(pokemon first, pokemon second)
{
	/*Function print which pokemon win in a battle*/
	int first_pokemon_power = (first.attack / first.defense)*first.effectiveness * 50;
	int second_pokemon_power = (second.attack / second.defense)*second.effectiveness * 50;

	if (first_pokemon_power > second_pokemon_power)
	{
		printf("The winner is: %s\n", first.name);
	}
	else if (first_pokemon_power < second_pokemon_power)
	{
		printf("The winner is: %s\n", second.name);
	}
	else
	{
		printf("Its a tie\n");
	}

}