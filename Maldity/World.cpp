#include "World.h"
#include "Player.h"


World::World()
{
	
	player = new Player("Jasna", "", 0);

	player->sanity = 100;
	player->atk = 2;
	player->def = 5;
	player->health = 20;


}

World::~World()
{}

void World::Look()const{

	printf("%s", player->position->data->description.C_str());

	List <Item*> ::Node* n = player->position->data->inside.first;

	while (n != nullptr)
	{
		printf("There's a %s in the floor.\n", n->data->name.C_str);
		n = n->next;
	}
}



void World::CreateWorld()
{
	
	
	

	item.PushBack(new Item("Key", "It's a old, little, rusty key.\n", "Shop", EQUIP_ITEM, 0));
	item.PushBack(new Item("Coffer", "An old wooden box. You can put objects into it.\n", "House",  NON_EQUIP_ITEM, 3));
	item.PushBack(new Item("Coin", "A very old coin. It seems to be made in gold.\nIt has a strange symbol impressed in it.\n", "Coffer", EQUIP_ITEM, 0));
	item.PushBack(new Item("Totem", "A strange totem, made in wood.\nIt's impossible to determine what it represents...\n", "Statue", EQUIP_ITEM, 0));
	item.PushBack(new Item("Sword", "It's a short sword, very sharpen.\n", "Coffer", EQUIP_ITEM, 0));
	item.PushBack(new Item("Armor", "A strange, shiny armor that covers the chest.\n", "Coffer", EQUIP_ITEM, 0));
	item.PushBack(new Item("Map", "The old map of a sailor. It doesn't represent any continent recognizable...\n", "Dock", EQUIP_ITEM, 0));
	item.PushBack(new Item("Fang", "It seems to be the fang of a sea creature.\nBut any sea creature known has that fangs...\n", "Beach", EQUIP_ITEM, 0));
	item.PushBack(new Item("Rope", "A simple piece of rope. Nothing strange.\n", "Shop", EQUIP_ITEM, 0));
	item.PushBack(new Item("Swordcase", "Very useful case, perfect for keep a sword inside.\n", "Coffer", EQUIP_ITEM, 1));
	item.PushBack(new Item("Vial", "A cristal bottle, with a dark, red sustance in it. Maybe blood?\n", "Tavern", EQUIP_ITEM, 0));

	item[4]->bonus_atk = 5;
	item[5]->bonus_def = 5;
	item[7]->bonus_atk = 3;



	//Forest
	
	room.PushBack(new Room("Forest","You are in a forest. \nAt south, you see that the road drives to a city. \nAt west, a high hill. \nAt north, the road vanishes in the distance. \nAt east, only the sea.\n"));

	exit.PushBack(new Exit("", "The road vanishes in the distance.\nBetter no to follow it.\n", "Forest", "", "north", false, true));
	exit.PushBack(new Exit("", "The road follows the coast and approaches to the village.\n", "Forest", "Road", "south", false, true));
	exit.PushBack(new Exit("", "The sea looks grey and unpeaceful.\n", "Forest", "", "east", false, true));
	exit.PushBack(new Exit("", "You can't go on that direction.\nThe hill is too high.\n", "Forest", "", "west", false, true));
	

	//Road

	room.PushBack(new Room("Road", "You are in a high road. \nAt north, there's a mass of gothic buildings. \nAt south, the sea, and a small beach. \nAt west, a way to a big dock. \nAt east, the road that drives to the forest.\n"));

	exit.PushBack(new Exit("", "The alleys seem to drive to the city center.\n", "Road", "Center", "north", false, true));
	exit.PushBack(new Exit("", "Narrow stairs sculpted in rock descends to the beach.\n", "Road", "Beach", "south", false, true));
	exit.PushBack(new Exit("", "The road leaves the city and follows the coast.\n", "Road", "Forest", "east", false, true));
	exit.PushBack(new Exit("", "At the distance, you can see numerous boat masts.\n", "Road", "Dock", "west", false, true));

	
	//Beach

	room.PushBack(new Room("Beach", "The beach is small and it's full of rocks\nYou can only see the main road, at north, and the wide open sea, at south.\n"));
	

	exit.PushBack(new Exit("", "The stairs go back to the road\n", "Beach", "Road", "north", false, true));
	exit.PushBack(new Exit("", "You look at the sea. The horizon is cloudy, and the water, grey.\nYou feel a little relief for stay in land,\nbut the cold and ferocious wind spreads it.\n", "Beach", "", "south", false, true));
	exit.PushBack(new Exit("", "The rocks are too abrupt to walk over them.\n", "Beach", "", "east", false, true));
	exit.PushBack(new Exit("", "The rocks are too abrupt to walk over them.\n", "Beach", "", "west", false, true));

	
	//Dock
/*
	room.PushBack(new Room("Dock", "The dock is really impressive.\nThere are enourmous woody ships in all directions except for the east.\n"));

	exit[12]->orientation = "north";
	exit[13]->orientation = "south";
	exit[14]->orientation = "east";
	exit[15]->orientation = "west";

	exit[12]->origin = "Dock";
	exit[13]->origin = "Dock";
	exit[14]->origin = "Dock";
	exit[15]->origin = "Dock";

	exit[12]->destination = "";
	exit[13]->destination = "";
	exit[14]->destination = "Road";
	exit[15]->destination = "";

	exit[12]->description = "The big boats seems old and abandoned. Better not try to go into.\n";
	exit[13]->description = "The big boats seems old and abandoned. Better not try to go into.\n";
	exit[14]->description = "Between the gigant boats, you can see the road.\n";
	exit[15]->description = "The big boats seems old and abandoned. Better not try to go into.\n";


	//Center

	room.PushBack(new Room("Center","Gothic buildings are all around of a narrow square.\nYou can see the main road at south, and a couple of sinister alleys that go \ndeeper into the city.\nOnly the alley of the north seems a little bit safer.\nYou can see two doors, at west and at east.\n"));

	exit[16]->orientation = "north";
	exit[17]->orientation = "south";
	exit[18]->orientation = "east";
	exit[19]->orientation = "west";

	exit[16]->origin = "Center";
	exit[17]->origin = "Center";
	exit[18]->origin = "Center";
	exit[19]->origin = "Center";

	exit[16]->destination = "Alley";
	exit[17]->destination = "Road";
	exit[18]->destination = "Shop";
	exit[19]->destination = "House";

	exit[16]->description = "The northern alley leaves the square between buildings. It seems to ascend.\n";
	exit[17]->description = "You can see the main road, near the sea.\n";
	exit[18]->description = "It seems to be the entrance a shop.\n";
	exit[19]->description = "It seems to be a door to a house.\n";

	exit[18]->door = true;
	exit[18]->open = false;
	exit[19]->door = true;
	exit[19]->open = false;


	//Alley

	room.PushBack(new Room("Alley", "The narrow alley goes up from the city center.\nThere's a small door that have a 'Tavern' placard at your left.\nThe alley continues ascending to the north.\n"));

	exit[20]->orientation = "north";
	exit[21]->orientation = "south";
	exit[22]->orientation = "east";
	exit[23]->orientation = "west";

	exit[20]->origin = "Alley";
	exit[21]->origin = "Alley";
	exit[22]->origin = "Alley";
	exit[23]->origin = "Alley";

	exit[20]->destination = "Top";
	exit[21]->destination = "Center";
	exit[22]->destination = "";
	exit[23]->destination = "Tavern";

	exit[20]->description = "The alley continues ascending.\n";
	exit[21]->description = "The alley descends to the city center.\n";
	exit[22]->description = "The gothic buildings looks impressive, and the rest of the alleys,\ntoo dark to go into.\n";
	exit[23]->description = "It seems to be the door of a tavern.\n";

	exit[23]->door = true;
	exit[23]->open = false;


	//Tavern

	room.PushBack(new Room("Tavern","The house seems to be an old tavern, with the door oriented at east.\n"));

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

	room.PushBack(new Room("Top","You are in the elevated district of the city.\nYou can see a little alley at south and a enormous statue at east, beyond the\nfells.\n"));

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

	room.PushBack(new Room("Fells","The fells are surrounded by dark trees. The enourmous statue rises over them.\n"));

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

	room.PushBack(new Room("Statue", "The enormous statue seems to be a Virgin.\nIt looks like she has a balcony on her top.\nThe dark mass of trees looks you from the west.\nThere are stairs that go up inside the statue.\nAt south, a little road goes down the fells.\n"));

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

	room.PushBack(new Room("Balcony","The head of the virgin is sculpted as a balcony. You can see the whole village \nfrom here.\n"));

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

	room.PushBack(new Room("House", "You are in the hall of an old house. The building looks like a gothic palace,\nbut it's dusty and seems abandoned.\n"));


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

	room.PushBack(new Room("Shop", "Compared to the rest of the city, the shop looks miserable.\nIt's impossible to determine what is sold here.\n"));

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
}

