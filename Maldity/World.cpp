#include "World.h"
#include "Creature.h"


World::World()
{}

World::~World()
{}

void World::Look()const{

	printf("%s", player->position->description.C_str());
	List<Entity*>::Node* it;


	for (int i = 0; i < entity.Size(); i++)
	{
		if (entity[i] == player->position)
		{
			it = entity[i]->inside.first;
			
			while (it != nullptr)
			{
				if (it->data->type == NON_EQUIP_ITEM || it->data->type == EQUIP_ITEM)
					printf("There's a %s in the floor.\n", it->data->name.C_str());

				else if (it->data->type == NPC)
					printf("%s is here.\n", it->data->name.C_str());


				it = it->next;
			}
			break;
		}	
	}
}



void World::CreateWorld()
{


	
	//Rooms

	entity.PushBack(forest = new Room("Forest","You are in a forest. \nAt south, you see that the road drives to a city. \nAt west, a high hill. \nAt north, the road vanishes in the distance. \nAt east, only the sea.\n"));
	entity.PushBack(road = new Room("Road", "You are in a high road. \nAt north, there's a mass of gothic buildings. \nAt south, the sea, and a small beach. \nAt west, a way to a big dock. \nAt east, the road that drives to the forest.\n"));
	entity.PushBack(beach = new Room("Beach", "The beach is small and it's full of rocks\nYou can only see the main road, at north, and the wide open sea, at south.\n"));
	entity.PushBack(dock = new Room("Dock", "The dock is really impressive.\nThere are enourmous woody ships in all directions except for the east.\n"));
	entity.PushBack(center = new Room("Center", "Gothic buildings are all around of a narrow square.\nYou can see the main road at south, and a couple of sinister alleys that go \ndeeper into the city.\nOnly the alley of the north seems a little bit safer.\nYou can see two doors, at west and at east.\n"));
	entity.PushBack(alley = new Room("Alley", "The narrow alley goes up from the city center.\nThere's a small door that have a 'Tavern' placard at your left.\nThe alley continues ascending to the north.\n"));
	entity.PushBack(tavern = new Room("Tavern", "The house seems to be an old tavern, with the door oriented at east.\n"));
	entity.PushBack(top = new Room("Top", "You are in the elevated district of the city.\nYou can see a little alley at south and a enormous statue at east, beyond the\nfells.\n"));
	entity.PushBack(fells = new Room("Fells", "The fells are surrounded by dark trees. The enourmous statue rises over them.\n"));
	entity.PushBack(statue = new Room("Statue", "The enormous statue seems to be a Virgin.\nIt looks like she has a balcony on her top.\nThe dark mass of trees looks you from the west.\nThere are stairs that go up inside the statue.\nAt south, a little road goes down the fells.\n"));
	entity.PushBack(house = new Room("House", "You are in the hall of an old house. The building looks like a gothic palace,\nbut it's dusty and seems abandoned.\n"));
	entity.PushBack(balcony = new Room("Balcony", "The head of the virgin is sculpted as a balcony. You can see the whole village \nfrom here.\n"));
	entity.PushBack(shop = new Room("Shop", "Compared to the rest of the city, the shop looks miserable.\nIt's impossible to determine what is sold here.\n"));


	//Forest exits
	entity.PushBack(new Exit("", "The road vanishes in the distance.\nBetter no to follow it.\n", forest, nullptr, N, false, true));
	entity.PushBack(new Exit("", "The road follows the coast and approaches to the village.\n", forest, road, S, false, true));
	entity.PushBack(new Exit("", "The sea looks grey and unpeaceful.\n", forest, nullptr, E, false, true));
	entity.PushBack(new Exit("", "You can't go on that direction.\nThe hill is too high.\n", forest, nullptr, W, false, true));
	

	//Road exits
	entity.PushBack(new Exit("", "The alleys seem to drive to the city center.\n", road, center, N, false, true));
	entity.PushBack(new Exit("", "Narrow stairs sculpted in rock descends to the beach.\n", road, beach, S, false, true));
	entity.PushBack(new Exit("", "The road leaves the city and follows the coast.\n", road, forest, E, false, true));
	entity.PushBack(new Exit("", "At the distance, you can see numerous boat masts.\n", road , dock, W, false, true));

	
	//Beach exits
	entity.PushBack(new Exit("", "The stairs go back to the road\n", beach, road, N, false, true));
	entity.PushBack(new Exit("", "You look at the sea. The horizon is cloudy, and the water, grey.\nYou feel a little relief for stay in land,\nbut the cold and ferocious wind spreads it.\n", beach, nullptr, S, false, true));
	entity.PushBack(new Exit("", "The rocks are too abrupt to walk over them.\n", beach, nullptr, E, false, true));
	entity.PushBack(new Exit("", "The rocks are too abrupt to walk over them.\n", beach, nullptr, W, false, true));

	
	//Dock exits

	entity.PushBack(new Exit("", "The big boats seems old and abandoned. Better not try to go into.\n", dock, nullptr, N, false, true));
	entity.PushBack(new Exit("", "The big boats seems old and abandoned. Better not try to go into.\n", dock, nullptr, S, false, true));
	entity.PushBack(new Exit("", "Between the gigant boats, you can see the road.\n", dock, road, E, false, true));
	entity.PushBack(new Exit("", "The big boats seems old and abandoned. Better not try to go into.\n", dock, nullptr, W, false, true));




	//Center exits

	entity.PushBack(new Exit("", "The northern alley leaves the square between buildings. It seems to ascend.\n", center, alley, N, false, true));
	entity.PushBack(new Exit("", "You can see the main road, near the sea.\n", center, road, S, false, true));
	entity.PushBack(new Exit("", "It seems to be the entrance a shop.\n", center, shop, E, true, false));
	entity.PushBack(new Exit("", "It seems to be a door to a house.\n", center, house, W, true, false));
	

	//Alley exits

	entity.PushBack(new Exit("", "The alley continues ascending.\n", alley, top, N, false, true));
	entity.PushBack(new Exit("", "The alley descends to the city center.\n", alley, center, S, false, true));
	entity.PushBack(new Exit("", "The gothic buildings looks impressive, and the rest of the alleys,\ntoo dark to go into.\n", alley, nullptr, E, false, true));
	entity.PushBack(new Exit("", "It seems to be the door of a tavern.\n", alley, tavern, W, true, false));


/*
	//Tavern


	exit[24]->orientation = "north";
	exit[25]->orientation = "south";
	exit[26]->orientation = "east";
	exit[27]->orientation = "west";

	exit[24]->origin = "Tavern";
	exit[25]->origin = "Tavern";
	exit[26]->origin = "Tavern";
	exit[27]->origin = "Tavern";

	exit[24]->destination = "";
	exit[25]->destination = "";
	exit[26]->destination = "Alley";
	exit[27]->destination = "";

	exit[24]->description = "The tavern has no more exits than the east one.\n";
	exit[25]->description = "The tavern has no more exits than the east one.\n";
	exit[26]->description = "This is the only door of the tavern.\n";
	exit[27]->description = "The tavern has no more exits than the east one.\n";

	exit[26]->door = true;
	exit[26]->open = true;

	//Top Disctrict


	exit[28]->orientation = "north";
	exit[29]->orientation = "south";
	exit[30]->orientation = "east";
	exit[31]->orientation = "west";

	exit[28]->origin = "Top";
	exit[29]->origin = "Top";
	exit[30]->origin = "Top";
	exit[31]->origin = "Top";

	exit[28]->destination = "";
	exit[29]->destination = "Alley";
	exit[30]->destination = "Fells";
	exit[31]->destination = "";

	exit[28]->description = "The city is surrounded by a chain of old fells.\nThe woody mountain looks dark and threatening.\n";
	exit[29]->description = "You can see the alley descending to the city.\n";
	exit[30]->description = "Between dark and high trees, you can see a enormous statue.\n";
	exit[31]->description = "The city is surrounded by a chain of old fells.\nThe woody mountains looks dark and threatening.\n";


	//Fells


	exit[32]->orientation = "north";
	exit[33]->orientation = "south";
	exit[34]->orientation = "east";
	exit[35]->orientation = "west";

	exit[32]->origin = "Fells";
	exit[33]->origin = "Fells";
	exit[34]->origin = "Fells";
	exit[35]->origin = "Fells";

	exit[32]->destination = "";
	exit[33]->destination = "";
	exit[34]->destination = "Statue";
	exit[35]->destination = "Top";

	exit[32]->description = "The forest is too dense to go into it.\n";
	exit[33]->description = "The forest is too dense to go into it.\n";
	exit[34]->description = "Between dark and high trees, you can see a enormous statue.\n";
	exit[35]->description = "You can see some buildings between the trees.\n";



	//Statue


	exit[36]->orientation = "north";
	exit[37]->orientation = "south";
	exit[38]->orientation = "east";
	exit[39]->orientation = "west";

	exit[36]->origin = "Statue";
	exit[37]->origin = "Statue";
	exit[38]->origin = "Statue";
	exit[39]->origin = "Statue";

	exit[36]->destination = "";
	exit[37]->destination = "Forest";
	exit[38]->destination = "Balcony";
	exit[39]->destination = "Fells";

	exit[36]->description = "The mountains look so terrifying\n";
	exit[37]->description = "The hill descends abruptly to a forest.\nIt's possible that you can't climb back.\n";
	exit[38]->description = "The statue has a little opened door.\nYou can see stairs behind it.\n";
	exit[39]->description = "The fells look tenebrous, but it's the only way to go to the village.\n";


	//Balcony


	exit[40]->orientation = "north";
	exit[41]->orientation = "south";
	exit[42]->orientation = "east";
	exit[43]->orientation = "west";

	exit[40]->origin = "Balcony";
	exit[41]->origin = "Balcony";
	exit[42]->origin = "Balcony";
	exit[43]->origin = "Balcony";

	exit[40]->destination = "";
	exit[41]->destination = "";
	exit[42]->destination = "";
	exit[43]->destination = "Statue";

	exit[40]->description = "The mountains look so terrfying.\n";
	exit[41]->description = "The gothic city is placed between the feets of the mountains and the grey sea.\nIt looks like a phantom village.\n";
	exit[42]->description = "You can see a little road at the bottom of the fells.\nOne of its sides goes to the city.\nThe other, vanishes in the distance.\n";
	exit[43]->description = "That stairs are the only way to go down the balcony.\n";


	//House



	exit[44]->orientation = "north";
	exit[45]->orientation = "south";
	exit[46]->orientation = "east";
	exit[47]->orientation = "west";

	exit[44]->origin = "House";
	exit[45]->origin = "House";
	exit[46]->origin = "House";
	exit[47]->origin = "House";

	exit[44]->destination = "";
	exit[45]->destination = "";
	exit[46]->destination = "Center";
	exit[47]->destination = "";

	exit[44]->description = "The only exit is the door at the east.\n";
	exit[45]->description = "The only exit is the door at the east.\n";
	exit[46]->description = "This is the only exit of the old house.\n";
	exit[47]->description = "The only exit is the door at the east.\n";

	exit[46]->door = true;
	exit[46]->open = true;


	//Shop


	exit[48]->orientation = "north";
	exit[49]->orientation = "south";
	exit[50]->orientation = "east";
	exit[51]->orientation = "west";

	exit[48]->origin = "Shop";
	exit[49]->origin = "Shop";
	exit[50]->origin = "Shop";
	exit[51]->origin = "Shop";

	exit[48]->destination = "";
	exit[49]->destination = "";
	exit[50]->destination = "";
	exit[51]->destination = "Center";

	exit[48]->description = "The only exit is the door at the west.\n";
	exit[49]->description = "The only exit is the door at the west.\n";
	exit[50]->description = "The only exit is the door at the west.\n";
	exit[51]->description = "You can see the city center from the interior of the shop.\n";
	
	*/

//Create stats struct
Stats Jasna_stats(20, 2, 5, 100);

Stats non_bonus(0, 0, 0, 0);
Stats sword_bonus(0, 5, 0, 0);
Stats armor_bonus(0, 0, 3, 0);
Stats fang_bonus(0, 2, 0, 0);


//Create creatures
entity.PushBack(player = new Creature("Jasna", "", forest, PLAYER, Jasna_stats, 5));




//Creates items
entity.PushBack(key = new Item("Key", "It's an old, little, rusty key.\n", EQUIP_ITEM, non_bonus, 0));
entity.PushBack(coffer = new Item("Coffer", "An old wooden box. You can put objects into it.\n", NON_EQUIP_ITEM, non_bonus, 3));
entity.PushBack(coin = new Item("Coin", "A very old coin. It seems to be made in gold.\nIt has a strange symbol impressed in it.\n", EQUIP_ITEM, non_bonus, 0));
entity.PushBack(totem = new Item("Totem", "A strange totem, made in wood.\nIt's impossible to determine what it represents...\n", EQUIP_ITEM, non_bonus, 0));
entity.PushBack(sword = new Item("Sword", "It's a short sword, very sharpen.\n", EQUIP_ITEM, sword_bonus, 0));
entity.PushBack(armor = new Item("Armor", "A strange, shiny armor that covers the chest.\n", EQUIP_ITEM, armor_bonus, 0));
entity.PushBack(map = new Item("Map", "The old map of a sailor. It doesn't represent any continent recognizable...\n",  EQUIP_ITEM, non_bonus, 0));
entity.PushBack(fang = new Item("Fang", "It seems to be the fang of a sea creature.\nBut any sea creature known has that fangs...\n", EQUIP_ITEM, fang_bonus, 0));
entity.PushBack(rope = new Item("Rope", "A simple piece of rope. Nothing strange.\n", EQUIP_ITEM, non_bonus, 0));
entity.PushBack(swordcase = new Item("Swordcase", "Very useful case, perfect for keep a sword inside.\n", EQUIP_ITEM, non_bonus, 1));
entity.PushBack(vial = new Item("Vial", "A cristal bottle, with a dark, red sustance in it. Maybe blood?\n", EQUIP_ITEM, non_bonus, 0));


//Locates creatures and items
forest->inside.PushBack(player);
forest->inside.PushBack(coffer);
coffer->inside.PushBack(key);

player->position = forest;



}

