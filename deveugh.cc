#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string jimbos = "smooth"; //thou shalt always possess a smooth jimbo, if thou wouldst REALLY hoop

string factorysetting = "generic"; //used for monsterfactory and itemfactory

bool action = true; //ensures the player doesn't get attacked after looking at their map
bool hiddenknowledge = false;
bool fetchquest = false;

class player {
  public:
	int health = 50;
	int stamina = 10;
	int attack = 10;
	int defense = 5;
	int exp = 0;
	int level = 0;
	int gold = 0;

	int weapon = 0;
	int shield = 0;
	bool fire = false;
	bool water = false;
	bool plant = false;
	bool holy = false;

	bool shovel = false;
	bool raft = false;
	bool flower = false;

	bool waterseal = false;
	bool desertseal = false;
	bool forestseal = false;

	int getXpos() {
		return charXpos;
	}
	void setXpos(int xPos) {
		charXpos = xPos;
	}

	int getYpos() {
		return charYpos;
	}
	void setYpos(int yPos) {
		charYpos = yPos;
	}

  private:
	int charXpos = 0;
	int charYpos = 0;
};

player Hero;

class enemy {
  public:
	int health = 20;
	int stamina = 10;
	int attack = 5;
	int defense = 5;
	int level = 1;

	bool fire = false;
	bool water = false;
	bool plant = false;
	bool hard = false;
};

enemy Monster;

void victory() {
	cout << endl << "As the last shadows of Eugh dissipate, you hear a final '﻿ＮＯＯＯＯＯＯＯＯＯＯ' as the landscape returns to normal and the seals stop glowing." << endl;
	cout << endl << "You return to the village to find a raucous celebration, and the old man is there waiting to join in along with them." << endl;
	cout << endl << "The land is, at long last, safe." << endl;
	cout << endl << endl << "You win!" << endl;
	cout << "Level = " << Hero.level << endl;
	exit(0);
}

void reaper() {
	cout << endl << "A ghastly figure materializes in front of you." << endl << endl;
	cout << "'LOOKS LIKE THINGS DIDN'T GO SO WELL FOR YOU, ' he says." << endl << "'PERHAPS I COULD REMEDY THIS, IN EXCHANGE FOR A SMALL AMOUNT OF COIN'" << endl;
	cout << endl << "'WHAT DO YOU SAY ? 50 GOLD FOR A SECOND CHANCE ? '" << endl;
	cout << endl << "(You have " << Hero.gold << " gold. Enter X to pay, or enter Z to quit.)" << endl << endl;
	char fate;
	cin >> fate;
	switch (fate) {
	case 'X' :
		if (Hero.gold < 50) {
			cout << "'I'M AFRAID YOU'RE LOW ON FUNDS. SORRY, RULES ARE RULES.'" << endl << "'I'M SURE YOU UNDERSTAND. AFTER ALL, I HAVE A JOB TO DO.'" << endl << endl << "Game Over. Reload game to restart." << endl;
			exit(0);
		} else {
			Hero.gold = Hero.gold - 50;
			Hero.health = 50 + (5 * Hero.level);
			Hero.stamina = 10 + (2 * Hero.level);
			cout << "'SPLENDID. LET'S GET YOU PATCHED UP - ALRIGHT, GOOD TO GO. GOOD LUCK OUT THERE.'" << endl << endl;
			break;
		}
	case 'Z' :
		cout << "'A SHAME. SEE YOU AGAIN SOON, THEN.'" << endl << endl << "Game Over. Reload game to restart." << endl;
		exit(0);
	default :
		cout << "The skeleton looks at you quizzically. 'WHAT ? '" << endl;
		exit(0);
	}
}

void boss() {

	cout << endl << endl << "You place the seals into their slots on the decrepit, stony altar. They begin to glow white, but then turn red as the sky darkens." << endl;
	cout << endl << endl << "Out of the abyss, tendrils of smoke and shadow congeal into a demonic colossus fifty stories high, black as ash save only for its dripping bloody eyes." << endl;
	cout << endl << endl << " ﻿Ｉ  ＡＭ  ＥＵＧＨ．  ＹＯＵ  ＷＩＬＬ  ＮＯＴ  ＤＥＦＥＡＴ  ＭＥ．" << endl << endl << endl << "Combat begins." << endl;

	bool combat = true;
	bool playerturn = true;
	bool defense = false;
	char playeraction;
	int enemyaction = 0;
	int enemyrand = 0;
	int damage = 0;
	cout << endl << "Standing firm against the demon, you ready yourself for battle." << endl << endl << "Enter G to attack, enter H to defend." << endl;
	while (combat == true) {
		if (Hero.health < 1) {
			cout << endl << "You have failed your quest! The ancestors have forsaken us!" << endl;
			reaper();
			break;
		}
		while (true) {
			if (defense == true) Hero.stamina += 4;
			cout << endl << "PLAYER HEALTH:  " << Hero.health << endl;
			cout <<         "PLAYER STAMINA: " << Hero.stamina << endl;
			cout << endl << "MONSTER HEALTH: " << Monster.health << endl;
			cout << endl << "Player's turn!" << endl << endl;
			cin >> playeraction;
			switch (playeraction) {
			case 'G':
				if (Hero.stamina < 1) {
					cout << endl << "You don't have enough stamina to muster an attack!" << endl << "Seeing your moment of weakness, the demon attacks." << endl;
					playerturn = false;
					defense = false;
					break;
				}
				if (defense == true) {
					if (Hero.stamina < 2) {
						damage = ((Hero.attack + Hero.weapon) * (Hero.attack + Hero.weapon)) / (Hero.attack + Hero.weapon + Monster.defense);
						Hero.health = Hero.health - damage;
						cout << endl << "The demon tries to evade, but you pinpoint his weak point and attack for " << damage << " damage!" << endl;
						defense = false;
						playerturn = true;
						break;
					}
					Monster.stamina -= 2;
					cout << endl << "You try to attack, but it hit only the shadows in the air!" << endl;
					Hero.stamina -= 2;
					defense = false;
					playerturn = false;
					break;
				}
				Hero.stamina -= 2;
				damage = ((Hero.attack + Hero.weapon) * (Hero.attack + Hero.weapon)) / (Hero.attack + Hero.weapon + Monster.defense);
				Monster.health = Monster.health - damage;
				cout << endl << "With a slicing blow, you deal " << damage << " damage!" << endl;
				defense = false;
				playerturn = false;
				break;
			case 'H':
				defense = true;
				cout << endl << "You brace yourself for Eugh's attack!" << endl;
				playerturn = false;
				break;
			default:
				cout << "Invalid input!(Try a capital G or H)" << endl;
			}
			if (playerturn == false) break;
		}
		if (Monster.health < 1) {
			cout << endl << "With a sickening metallic howl, the demon's shadowy form collapses into an ooze that sinks to the ground like lead." << endl;
			combat = false;
			victory();
			break;
		}
		cout << endl << "ＥＵＧＨ's turn!" << endl;
		if (defense == true) Monster.stamina += 2;
		enemyrand = (rand() % 5);
		if (enemyrand < 2) enemyaction = 1;
		else enemyaction = 0;
		switch (enemyaction) {
		case 0:
			if (Monster.stamina < 1) {
				cout << endl << "The demon tries to attack, but it cannot find the power to do so!" << endl;
				defense = false;
				playerturn = true;
				break;
			}
			if (defense == true) {
				if (Hero.stamina < 2) {
					damage = (Monster.attack * Monster.attack) / (Monster.attack + Hero.defense);
					Hero.health = Hero.health - damage;
					cout << endl << "You try to block, but the demon crushes you beneath his fist anyway! You take " << damage << " damage." << endl;
					defense = false;
					playerturn = true;
					break;
				}
				Hero.stamina -= 2;
				cout << endl << "The demon tries to attack, but against all odds you block it with your shield!" << endl;
				Monster.stamina -= 4;
				defense = false;
				playerturn = true;
				break;
			}
			Monster.stamina -= 2;
			damage = (Monster.attack * Monster.attack) / (Monster.attack + Hero.defense);
			Hero.health = Hero.health - damage;
			cout << endl << "The demon bludgeons you with a titanic blow for " << damage << " damage!" << endl;
			defense = false;
			playerturn = true;
			break;
		case 1:
			defense = true;
			cout << endl << "The demon scatters its form to evade your attacks!" << endl;
			playerturn = true;
			break;
		}
	}
}

void itemfactory() {
	action = true;
	int factoryxp = Monster.level * 10;
	Hero.exp = factoryxp;
	cout << endl << "You gained " << factoryxp << " experience points!" << endl;
	if (Hero.exp >= ((Hero.level + 1) * 100)) cout << endl << "You've gained a level! Your health and stamina rise by 5 each." << endl;
	Hero.exp = Hero.exp - ((Hero.level + 1) * 100);
	Hero.level++;
	Hero.health = 50 + (5 * Hero.level);
	Hero.stamina = 10 + (2 * Hero.level);
	int tombola = rand() % 6;
	if (tombola < 3) {
		int factorygold = rand() % 20 + 5;
		Hero.gold += factorygold;
		cout << endl << "You found " << factorygold << " gold!" << endl;
	} else if (tombola < 5) {
		int randweapon = rand() % (Hero.level + rand() % 5) + 1;
		cout << endl << "You found a new blade that does " << randweapon << " damage! Would you like to keep it?" << endl;
		cout << "(Enter X to keep, enter anything else to leave.)" << endl;
		char pickup;
		cin >> pickup;
		switch (pickup) {
		case 'X':
			Hero.weapon = randweapon;
			randweapon = 0;
			cout << "You take the weapon." << endl;
			break;
		default:
			cout << "You decide to leave the weapon behind." << endl;
			randweapon = 0;
		}
	} else {
		int randshield = rand() % (Hero.level + rand() % 5) + 1;
		cout << endl << "You found a new shield with " << randshield << " defense! Would you like to keep it?" << endl;
		cout << "(Enter X to keep, enter anything else to leave.)" << endl;
		char pickup;
		cin >> pickup;
		switch (pickup) {
		case 'X':
			Hero.shield = randshield;
			randshield = 0;
			cout << "You take the shield." << endl;
			break;
		default:
			cout << "You decide to leave the shield behind." << endl;
			randshield = 0;
		}
	}

}
void combat() {
	bool combat = true;
	bool playerturn = true;
	bool defense = false;
	char playeraction;
	int enemyaction = 0;
	int enemyrand = 0;
	int damage = 0; //THAT'S A LOTTA DAMAGE
	cout << "You engage the monster, weapon held at the ready." << endl << endl << "Enter G to attack, enter H to defend." << endl;
	while (combat == true) {
		if (jimbos == "hesi") {
			cout << endl << "The monster flees at the sight of your impressive jimbo." << endl;
			combat = false;
			itemfactory();
			break;
		}
		if (Hero.health < 1) {
			cout << endl << "You died!" << endl;
			reaper();
			break;
		}
		while (true) {
			if (defense == true) Hero.stamina += 4;
			cout << endl << "PLAYER HEALTH:  " << Hero.health << endl;
			cout <<         "PLAYER STAMINA: " << Hero.stamina << endl;
			cout << endl << "MONSTER HEALTH: " << Monster.health << endl;
			cout << endl << "Player's turn!" << endl << endl;
			cin >> playeraction;
			switch (playeraction) {
			case 'G':
				if (Hero.stamina < 1) {
					cout << endl << "You don't have enough stamina to muster an attack!" << endl << "Seeing your moment of weakness, the monster attacks." << endl;
					playerturn = false;
					defense = false;
					break;
				}
				if (defense == true) {
					if (Hero.stamina < 2) {
						damage = ((Hero.attack + Hero.weapon) * (Hero.attack + Hero.weapon)) / (Hero.attack + Hero.weapon + Monster.defense);
						Hero.health = Hero.health - damage;
						cout << endl << "The monster tries to defend, but you deftly strike through it for " << damage << " damage!" << endl;
						defense = false;
						playerturn = true;
						break;
					}
					Monster.stamina -= 2;
					cout << endl << "You try to attack, but the monster was able to deflect it!" << endl;
					Hero.stamina -= 2;
					defense = false;
					playerturn = false;
					break;
				}
				Hero.stamina -= 2;
				damage = ((Hero.attack + Hero.weapon) * (Hero.attack + Hero.weapon)) / (Hero.attack + Hero.weapon + Monster.defense);
				Monster.health = Monster.health - damage;
				cout << endl << "With a slicing blow, you deal " << damage << " damage!" << endl;
				defense = false;
				playerturn = false;
				break;
			case 'H':
				defense = true;
				cout << endl << "You brace yourself for an oncoming attack!" << endl;
				playerturn = false;
				break;
			default:
				cout << "Invalid input!(Try a capital G or H)" << endl;
			}
			if (playerturn == false) break;
		}
		if (Monster.health < 1) {
			cout << endl << "With that blow, the monster crumples to the ground and disappears. You've won!" << endl;
			combat = false;
			itemfactory();
			break;
		}
		cout << endl << "Monster's turn!" << endl;
		if (defense == true) Monster.stamina += 2;
		enemyrand = (rand() % 5);
		if (enemyrand < 2) enemyaction = 1;
		else enemyaction = 0;
		switch (enemyaction) {
		case 0:
			if (Monster.stamina < 1) {
				cout << endl << "The monster tries to attack, but is too winded!" << endl;
				defense = false;
				playerturn = true;
				break;
			}
			if (defense == true) {
				if (Hero.stamina < 2) {
					damage = (Monster.attack * Monster.attack) / (Monster.attack + Hero.defense);
					Hero.health = Hero.health - damage;
					cout << endl << "You try to block, but the monster shatters your stance! You take " << damage << " damage." << endl;
					defense = false;
					playerturn = true;
					break;
				}
				Hero.stamina -= 2;
				cout << endl << "The monster tries to attack, but you block it with your shield!" << endl;
				Monster.stamina -= 4;
				defense = false;
				playerturn = true;
				break;
			}
			Monster.stamina -= 2;
			damage = (Monster.attack * Monster.attack) / (Monster.attack + Hero.defense);
			Hero.health = Hero.health - damage;
			cout << endl << "The monster lurches forward and strikes you for " << damage << " damage!" << endl;
			defense = false;
			playerturn = true;
			break;
		case 1:
			defense = true;
			cout << endl << "The monster enters a defensive stance!" << endl;
			playerturn = true;
			break;
		}
	}
}

void monsterfactory(enemy & Monster) {
	int encounter = rand() % 8;
	if (factorysetting != "peace" && action != true) {
		if (encounter < 4) {
			Monster.level = (1 + Hero.level + (rand() % 5));
			if (factorysetting == "fire" || factorysetting == "water" || factorysetting == "plant") Monster.level += (rand() % (1 * Hero.level));
			else if (factorysetting == "hard") Monster.level += (rand() % (2 * Hero.level));
			Monster.health = (20 + (5 * Monster.level));
			Monster.stamina = (10 + (rand() % Monster.level) * 2);
			Monster.attack = (2 + (Monster.level * 2) + ((rand() % 2) * (Monster.level / 2)) - ((rand() % 2) * (Monster.level / 2)));
			Monster.defense = (2 + (Monster.level * 2) + ((rand() % 2) * (Monster.level / 2)) - ((rand() % 2) * (Monster.level / 2)));

			Monster.fire = false;
			Monster.water = false;
			Monster.plant = false;
			Monster.hard = false;

			if (factorysetting == "fire") Monster.fire = true;
			if (factorysetting == "water") Monster.water = true;
			if (factorysetting == "plant") Monster.plant = true;
			if (factorysetting == "hard") Monster.hard = true;

			//maybe remove this, maybe don't

			cout << "Level " << Monster.level << " Monster engages you!" << endl;
			//cout << "Monster health is " << Monster.health << endl;
			//cout << "Monster stamina is " << Monster.stamina << endl;
			//cout << "Monster attack is " << Monster.attack << endl;
			//cout << "Monster defense is " << Monster.defense << endl;

			combat();

		} else if (encounter < 7) cout << endl << "Nothing happens!" << endl;
		else {
			cout << endl << "You found a chest!" << endl;
			itemfactory();
		}
	} else cout << endl << "You stand idly." << endl;
}

void oldman() {
	cout << "Do you wish to approach the old man?" << endl;
	cout << endl << "YES (X) NO (ANY)" << endl;
	char input;
	cin >> input;
	switch (input) {
	case 'X' :
		if (hiddenknowledge == false) {
			cout << endl << endl << "Ah. So you have returned. I didn't think I'd live to see the day..." << endl << "The great evil has fallen upon this land. The demon, Eugh. That is his name, it's not just me being disgusted. Eugh." << endl;
			cout << endl << "You are of course the only one that can stop him. I regret to say, it seems the temples have been swallowed by time itself..." << endl << "The three great seals, though, still remain. You will need to find them." << endl;
			cout << endl << "I know you are up to the task. There is one in each region - one for the Desert, the Forest, and the Waters." << endl << "They may be difficult to come by, so don't hesitate to stop by if you need guidance." << endl;
			hiddenknowledge = true;
			action = true;
		} else if (hiddenknowledge == true) {
			cout << endl << "The forest seal is closest to here. I remember something about 'to avoid a great fall, use the power of the moon'. The fall part confuses me, but I know just north of here there is a grove of sacred moon flowers." << endl;
			cout << "Secondly, the water seal - these verses have been lost to time, but I'm confident if you travel along the river to the east you'll eventually find it." << endl;
			cout << "Finally... the desert seal. It is buried in the sands somewhere. All I know is that it speaks of the land between four dunes." << endl;
			cout << "Once you have found all three, travel to the far corner of the mountains to face your destiny." << endl;
			action = true;
		} else cout << "The old man stares at you, trying but failing to remember who you are. This should not happen." << endl;
	}
}

void josephi() {
	cout << "A thickly mustachioed man in gilded clothing rushes out to greet you as you come in." << endl;
	cout << endl << "'Aha, yes, it is I, Josephi! I come, offer to you deal. You buy, 25 gold, receive ~mystery item!~'" << endl;
	cout << "'Maybe good, maybe bad. Even I am not knowing! Will you give chance to me, friend?'" << endl;
	cout << endl <<  "PAY 25 GOLD FOR RANDOM ITEM (X)   WALK AWAY (ANY)" << endl;
	char input;
	cin >> input;
	switch (input) {
	case 'X' :
		if (Hero.gold < 25) {
			cout << "'Oh, haha, I make mistake! You come another time, when you have gold. Then we make deal!'" << endl;
			action = true;
			break;
		} else {
			Hero.gold -= 25;
			cout << "'Wow! Here we go! You not regret this, thank you good friend! Have a mystery!'" << endl;
			itemfactory();
			break;
		}
	default:
		cout << "'Is ok, you come back other time. I still selling wares all day, all night!'" << endl;
		action = true;
		break;

	}
}

void location(player & Hero) { //handles room description, monster and item type, and calls functions specific to unique rooms
	int locationX = Hero.getXpos();
	int locationY = Hero.getYpos();

	string mapgrid [10][10]; //this really sucked
	mapgrid [0][0] = "waterplains";
	mapgrid [0][1] = "waterplains";
	mapgrid [0][2] = "waterraft";
	mapgrid [0][3] = "waterplains";
	mapgrid [0][4] = "plainswater";
	mapgrid [0][5] = "plainsdesert";
	mapgrid [0][6] = "desertplains";
	mapgrid [0][7] = "desert";
	mapgrid [0][8] = "desert";
	mapgrid [0][9] = "desert";
	mapgrid [1][0] = "plainswater";
	mapgrid [1][1] = "plainswater";
	mapgrid [1][2] = "plainswater";
	mapgrid [1][3] = "waterplains";
	mapgrid [1][4] = "plainswater";
	mapgrid [1][5] = "plainsdesert";
	mapgrid [1][6] = "desertplains";
	mapgrid [1][7] = "deserttemple";
	mapgrid [1][8] = "desert";
	mapgrid [1][9] = "desert";
	mapgrid [2][0] = "plains";
	mapgrid [2][1] = "plains";
	mapgrid [2][2] = "plainswater";
	mapgrid [2][3] = "waterplains";
	mapgrid [2][4] = "plainswater";
	mapgrid [2][5] = "plainsdesert";
	mapgrid [2][6] = "desertplains";
	mapgrid [2][7] = "desert";
	mapgrid [2][8] = "desert";
	mapgrid [2][9] = "desert";
	mapgrid [3][0] = "plains";
	mapgrid [3][1] = "plains";
	mapgrid [3][2] = "plainswater";
	mapgrid [3][3] = "waterplains";
	mapgrid [3][4] = "waterplains";
	mapgrid [3][5] = "plainswater";
	mapgrid [3][6] = "plainsdesert";
	mapgrid [3][7] = "desertplains";
	mapgrid [3][8] = "desert";
	mapgrid [3][9] = "desert";
	mapgrid [4][0] = "plains";
	mapgrid [4][1] = "market";
	mapgrid [4][2] = "plains";
	mapgrid [4][3] = "plainswater";
	mapgrid [4][4] = "watertemple";
	mapgrid [4][5] = "plainswater";
	mapgrid [4][6] = "desertplains";
	mapgrid [4][7] = "desertshovel";
	mapgrid [4][8] = "desert";
	mapgrid [4][9] = "desert";
	mapgrid [5][0] = "plainsforest";
	mapgrid [5][1] = "plainsforest";
	mapgrid [5][2] = "plainsforest";
	mapgrid [5][3] = "corner1";
	mapgrid [5][4] = "water1";
	mapgrid [5][5] = "water2";
	mapgrid [5][6] = "corner2";
	mapgrid [5][7] = "corner3";
	mapgrid [5][8] = "desertmountain";
	mapgrid [5][9] = "desertmountain";
	mapgrid [6][0] = "forestplains";
	mapgrid [6][1] = "forestplains";
	mapgrid [6][2] = "forestplains";
	mapgrid [6][3] = "forestplains";
	mapgrid [6][4] = "forestwater";
	mapgrid [6][5] = "canyonwater";
	mapgrid [6][6] = "corner4";
	mapgrid [6][7] = "mountaindesert";
	mapgrid [6][8] = "mountaindesert";
	mapgrid [6][9] = "holy";
	mapgrid [7][0] = "foresttemple";
	mapgrid [7][1] = "forest";
	mapgrid [7][2] = "forest";
	mapgrid [7][3] = "forest";
	mapgrid [7][4] = "forestwater";
	mapgrid [7][5] = "canyonwater";
	mapgrid [7][6] = "mountainwater";
	mapgrid [7][7] = "mountain";
	mapgrid [7][8] = "mountain";
	mapgrid [7][9] = "mountain";
	mapgrid [8][0] = "forest";
	mapgrid [8][1] = "forest";
	mapgrid [8][2] = "forest";
	mapgrid [8][3] = "oldman";
	mapgrid [8][4] = "forestwater";
	mapgrid [8][5] = "canyonwater";
	mapgrid [8][6] = "mountainwater";
	mapgrid [8][7] = "mountain";
	mapgrid [8][8] = "mountain";
	mapgrid [8][9] = "mountainapproach";
	mapgrid [9][0] = "forest";
	mapgrid [9][1] = "forest";
	mapgrid [9][2] = "forest";
	mapgrid [9][3] = "flower";
	mapgrid [9][4] = "forestwater";
	mapgrid [9][5] = "canyonwater";
	mapgrid [9][6] = "mountainwater";
	mapgrid [9][7] = "mountain";
	mapgrid [9][8] = "mountainapproach";
	mapgrid [9][9] = "finaltemple";

	string mapdescribe = mapgrid [locationY][locationX]; //calls terrain description from player coordinates
	if (mapdescribe == "plains") {
		factorysetting = "generic";
		cout << endl << "A vast plain stretches before you, filled with waving acres of grass and wild grain." << endl;
	} else if (mapdescribe == "plainswater") {
		factorysetting = "generic";
		cout << endl << "The rolling expanses of grassland taper down to a river delta here, creating wet, marshy fields." << endl;
	} else if (mapdescribe == "plainsforest") {
		factorysetting = "generic";
		cout << endl << "The grasslands grow sparser here as an imposing treeline appears in the distance." << endl;
	} else if (mapdescribe == "plainsdesert") {
		factorysetting = "generic";
		cout << endl << "Green grass turns to yellow here as the ground dries out and the sun beats down." << endl << "To the east it stops entirely, becoming an arid desert." << endl;
	} else if (mapdescribe == "corner1") {
		factorysetting = "generic";
		cout << endl << "You find yourself at the threshold of the plains, a point where the roaring river beside you trails off into a canyon." << endl;
	} else if (mapdescribe == "corner2") {
		factorysetting = "generic";
		cout << endl << "The river beside you trails off into the mountains to the north, irrigating rough patches of grain." << endl;
	} else if (mapdescribe == "corner3") {
		factorysetting = "fire";
		cout << endl << "The mountains, desert, and plains intersect here in a patchy steppe plateau." << endl << "A mountain trail winds through a narrow pass to the north." << endl;
	} else if (mapdescribe == "corner4") {
		factorysetting = "hard";
		cout << endl << "Atop a mountain precipice, you can see a river below you snake into canyons and rocky shores." << endl << "Below you to the south you see grasslands lining the edge of a harsh desert." << endl;
	} else if (mapdescribe == "waterplains") {
		factorysetting = "water";
		cout << endl << "A roaring river runs through the plains here, glistening in the midday sun. It seems shallow enough to cross." << endl;
	} else if (mapdescribe == "water1") {
		factorysetting = "water";
		cout << endl << "The river curves mightily here at the base of an impressive forest, cutting into the landscape and dipping to the east." << endl;
	} else if (mapdescribe == "water2") {
		factorysetting = "water";
		cout << endl << "The river here bends in a wide arc and rushes down into a canyon." << endl << "It shallows out briefly at the banks of a muddy plain at the foot of the mountains." << endl;
	} else if (mapdescribe == "canyonwater") {
		factorysetting = "water";
		cout << endl << "Standing at the base of a wide canyon, you see the river tumble down and carve a path between the forest and the mountains." << endl;
	} else if (mapdescribe == "forest") {
		factorysetting = "plant";
		cout << endl << "A dense oak forest rises around you, blanketing the ground in a cool shade." << endl;
	} else if (mapdescribe == "forestplains") {
		factorysetting = "plant";
		cout << endl << "Through the tree line to the south you can make out rolling grasslands." << endl << "To the north the thicket of tree trunks grows ever denser." << endl;
	} else if (mapdescribe == "forestwater") {
		factorysetting = "plant";
		cout << endl << "The forest tapers off and then drops into a canyon here, steep but traversable." << endl << "Below at the base of the canyon flows a white river rapid." << endl;
	} else if (mapdescribe == "desert") {
		factorysetting = "fire";
		cout << endl << "An endless sea of sandy dunes stretches as far as the eye can see. The sun beats down oppressively." << endl;
	} else if (mapdescribe == "desertplains") {
		factorysetting = "fire";
		cout << endl << "Dusty earth turns to sand here as the sun grows ever hotter." << endl << "Thin yellow grass thickens out to the west, while dunes rise before you to the east." << endl;
	} else if (mapdescribe == "desertmountain") {
		factorysetting = "fire";
		cout << endl << "Cracked earth rises out of the sand to become a steppe plateau here as the foothills meet the desert to the south." << endl << "The steppe ascends gradually to the north, leading up into the mountains." << endl;
	} else if (mapdescribe == "mountain") {
		factorysetting = "hard";
		cout << endl << "Rocky slopes line the sides of the trail as you hike further, rising high above the fog and plunging into the abyss." << endl;
	} else if (mapdescribe == "mountainwater") {
		factorysetting = "hard";
		cout << endl << "The mountains open up into a clearing overlooking a wide canyon, where a river cuts through the rock." << endl << "Beyond that, a vast forest sprawls westward." << endl;
	} else if (mapdescribe == "mountaindesert") {
		factorysetting = "hard";
		cout << endl << "Dry foothills slope up northward into the mountains, shrouded in a dry mist." << endl << "Below, the foothills bottom out into the heat of the desert." << endl;
	} else if (mapdescribe == "mountainapproach") {
		factorysetting = "hard";
		cout << endl << "A steep path winds through narrow rocky valleys ahead of you." << endl << "Far, far above, just below the clouds, you can make out a fearsome stone temple carved into the side of the mountain." << endl;
	} else if (mapdescribe == "finaltemple") {
		factorysetting = "boss";
		cout << endl << "A towering stone facade carved with monumental and grotesque imagery marks the end of the mountain trail." << endl << "Before you, a vast chasm plummets downwards into eternity. A narrow footbridge crosses the gap, your only safety from the misty canopy far below." << endl;
		if (hiddenknowledge == true && Hero.forestseal == true && Hero.waterseal == true && Hero.desertseal == true) {
			cout << endl << "Gathering the seals together, you realize there is no turning back. Are you sure?" << endl;
			cout << "FACE EUGH (X)   GATHER STRENGTH (ANY)" << endl;
			char input;
			cin >> input;
			switch (input) {
			case 'X' :
				boss();
				break;
			default:
				cout << "You decide it would be best to gather strength before facing Eugh." << endl;
				break;
			}
		} else {
			cout << endl << "You are not ready. Gather your strength and collect the stones before facing Eugh." << endl;
		}
	} else if (mapdescribe == "watertemple") {
		factorysetting = "water";
		cout << endl << "A roaring river runs through the plains here, glistening in the midday sun. It seems shallow enough to cross. " << endl;
		if (hiddenknowledge == true) cout << "In this particular spot, however, the river is at its most shallow, slowing down as it bottoms out over rocks." << endl << "You can spot a local fisherman on the banks of the river, taking advantage of this perfect fishing spot." << endl;
		if (hiddenknowledge == true && Hero.waterseal == false && fetchquest == false) {
			cout << "He is using the Water Seal as fish bait." << endl;
			cout << endl <<  "APPROACH THE MAN (X)   WALK AWAY (ANY)" << endl;
			char input;
			cin >> input;
			switch (input) {
			case 'X' :
				cout << endl << "'What, this here bait?' he says, 'It's pretty special, ain't it? All the fish flock to it. If you want it... Hmmm...'" << endl;
				cout << "'Tell you what. I'm in a predicament right now, I can't rightly get home without my raft, an' it floated upstream... somehow.'" << endl;
				cout << "'You get me that raft, I'll give you this here bait. Deal?'" << endl;
				fetchquest = true;
				action = true;
				break;
			default :
				cout << "You decide to leave the man to his business." << endl;
				break;
			}
		}
		if (hiddenknowledge == true && Hero.waterseal == false && fetchquest == true && Hero.raft == true) {
			cout << endl << "The fisherman yelps with delight to see his raft in one piece, then contains himself before addressing you." << endl;
			cout << "'You've done me a mighty fine service, so I'm in your debt.' he says, 'But before I give this to you, I got a test for ya..." << endl;
			cout << endl << "He leans in. 'What's the magic word?'" << endl;
			string magicword;
			cin >> magicword;
			if (magicword == "Please" || magicword == "please" || magicword == "Please?" || magicword == "please?") {
				cout << "'Well, actually, I was lookin' fer 'Abracadabra' but that works too. Here ya go!'" << endl;
				Hero.raft = false;
				fetchquest = false;
				Hero.waterseal = true;
				action = true;
				cout << endl << "You got the Water Seal!" << endl;
			} else if (magicword == "abracadabra" || magicword == "hocuspocus" || magicword == "shazam" || magicword == "presto" || magicword == "xyzzy") {
				cout << "'Darn tootin'! I like yer spunk, kid, here- have this, too, for a job well done. You earned it!'" << endl;
				Hero.raft = false;
				fetchquest = false;
				action = true;
				Hero.waterseal = true;
				cout << endl << "You got the Water Seal (and 10 gold)!" << endl;
			} else cout << "'Nope, that's... not what I was looking for. I'm gonna keep it until you get it right!'" << endl;
		}
	} else if (mapdescribe == "foresttemple") {
		factorysetting = "plant";
		cout << endl << "The forest gives way to a lush oasis, where a waterfall flows endlessly from a spring-fed lake." << endl;
		if (hiddenknowledge == true) cout << "You now understand what the old man's verse meant - a waterfall, not a physical fall." << endl;
		if (Hero.flower == true && hiddenknowledge == true) {
			cout << "Trying to make sense of the riddle, you cover your head in the petal only to find the falls part before you." << endl << "Behind the falls, in a small mossy alcove, lies the Forest Seal." << endl;
			cout << endl << "You got the Forest Seal!" << endl;
			Hero.forestseal = true;
			Hero.flower = false;
		}
	} else if (mapdescribe == "deserttemple") {
		factorysetting = "fire";
		cout << endl << "An endless sea of sandy dunes stretches as far as the eye can see. The sun beats down oppressively." << endl;
		if (hiddenknowledge == true) cout << "You notice that four of the dunes in the area almost seem to curve towards a single point at their center." << endl;
		if (Hero.shovel == true && hiddenknowledge == true) {
			cout << "Remarking that this is the spot the old man mentioned, you begin digging. Surprisingly, the seal is only a few feet down." << endl;
			cout << endl << "You got the Desert Seal!" << endl;
			Hero.desertseal = true;
			Hero.shovel = false;
		}
	} else if (mapdescribe == "oldman") {
		factorysetting = "peace";
		cout << endl << "Hidden within a clearing in the woods here is a small cabin built of logs, clay, and thatch." << endl << "An old man in a maroon sleeping gown sits on the porch smoking his pipe." << endl;
		oldman();
	} else if (mapdescribe == "market") {
		factorysetting = "peace";
		cout << endl << "A well - worn road leads to a small market town nestled atop the nearby hill. You approach the town." << endl;
		josephi();
	} else if (mapdescribe == "desertshovel") {
		factorysetting = "fire";
		cout << endl << "The dunes here have been dug up as part of a sprawling archaeological dig. Tools and scaffolding are scattered about." << endl;
		if (Hero.shovel == false && Hero.desertseal == false) {
			cout << "A shovel is propped up against one of the tents. You take the shovel." << endl;
			Hero.shovel = true;
		}
	} else if (mapdescribe == "holy") {
		factorysetting = "hard";
		cout << endl << "A rugged trail snakes down through the mountains on to greener pastures. The promise of new lands await you." << endl << "Buy the full version to access!" << endl;
	} else if (mapdescribe == "flower") {
		factorysetting = "peace";
		cout << endl << "A dense oak forest rises around you, blanketing the ground in a cool shade." << endl;
		if (hiddenknowledge == true) cout << "You didn't notice it at first, but here the ground is teeming with various flowers and vegetation." << endl;
		if (Hero.flower == false && Hero.forestseal == false && hiddenknowledge == true) {
			cout << "Hidden beneath dense fronds of foliage, you spot the massive, white petals of the sacred moon flower. You pick one." << endl;
			Hero.flower = true;
		}
	} else if (mapdescribe == "waterraft") {
		factorysetting = "water";
		cout << endl << "A roaring river runs through the plains here, glistening in the midday sun. It seems shallow enough to cross." << endl;
		if (hiddenknowledge == true && Hero.raft == false) cout << "You notice a well-maintained wooden raft lazily floating upstream." << endl;
		if (hiddenknowledge == true && Hero.waterseal == false && fetchquest == true && Hero.raft == false) {
			cout << "Edging close to the bank, you manage to snag the raft and pull it out of the water." << endl;
			Hero.raft = true;
		}
	} else cout << endl << "A hollow voice says 'fool'." << endl;

	monsterfactory(Monster);
}

void whatdoyoudo(player & Hero) {
	cout << endl << "What do you wish to do ? " << endl << endl << "I) Inventory" << endl << "M) Map" << endl << "N) North" << endl << "E) East" << endl << "W) West" << endl << "S) South" << endl;
	char input;
	cin >> input;
	switch (input) {
	case 'I' :
		cout << "You are level " << Hero.level << "." << endl;
		cout << "You currently have " << Hero.exp << " experience, and need " << (Hero.level + 1) * 100 << " experience to level up." << endl;
		cout << endl << "PLAYER HEALTH:   " << Hero.health << endl;
		cout <<         "PLAYER STAMINA:  " << Hero.stamina << endl;
		cout << endl << "You are equipped with a weapon that does " << Hero.weapon << " damage, and a shield with " << Hero.shield << " defense." << endl;
		cout << "You have " << Hero.gold << " gold." << endl << endl;
		if (Hero.forestseal == true) cout << "You have the Forest Seal." << endl;
		if (Hero.waterseal == true) cout << "You have the Water Seal." << endl;
		if (Hero.desertseal == true) cout << "You have the Desert Seal." << endl;
		if (Hero.shovel == true) cout << "You have a shovel." << endl;
		if (Hero.flower == true) cout << "You have the sacred moon flower." << endl;
		if (Hero.raft == true) cout << "You have the raft." << endl;
		action = true;
		break;
	case 'M' :
		cout << "║0, 9             - N -             9, 9║" << endl;
		cout << "╠═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╣" << endl;
		cout << "║♣♣♣│♣♣♣│♣♣♣│♣♣♣│♣♣♣│███│▲▲▲│▲▲▲│▲▲▲│▲▲▲║" << endl;
		cout << "╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢" << endl;
		cout << "║♣♣♣│♣♣♣│♣♣♣│♣♣♣│♣♣♣│███│▲▲▲│▲▲▲│▲▲▲│▲▲▲║" << endl;
		cout << "╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢" << endl;
		cout << "║♣♣♣│♣♣♣│♣♣♣│♣♣♣│♣♣♣│███│▲▲▲│▲▲▲│▲▲▲│▲▲▲║" << endl;
		cout << "╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢" << endl;
		cout << "║♣♣♣│♣♣♣│♣♣♣│♣♣♣│♣♣♣│███│▲▲▲│▲▲▲│▲▲▲│▲▲▲║" << endl;
		cout << "╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢" << endl;
		cout << "║▒▒▒│▒▒▒│▒▒▒│▒▒▒│███│███│▒▒ │░░ │░░ │░░ ║" << endl;
		cout << "╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢" << endl;
		cout << "║▒▒▒│♦$♦│▒▒▒│▒▒▒│███│▒▒▒│▒▒ │░░ │░░ │░░ ║" << endl;
		cout << "╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢" << endl;
		cout << "║▒▒▒│▒▒▒│▒▒▒│███│███│▒▒▒│▒▒ │░░ │░░ │░░ ║" << endl;
		cout << "╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢" << endl;
		cout << "║▒▒▒│▒▒▒│▒▒▒│███│▒▒▒│▒▒▒│░░ │░░ │░░ │░░ ║" << endl;
		cout << "╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢" << endl;
		cout << "║▒▒▒│▒▒▒│▒▒▒│███│▒▒▒│▒▒▒│░░ │░░ │░░ │░░ ║" << endl;
		cout << "╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢" << endl;
		cout << "║███│███│███│███│▒▒▒│▒▒▒│░░ │░░ │░░ │░░ ║" << endl;
		cout << "╠═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╣" << endl;
		cout << "║0, 0             - S -             9, 0║" << endl;
		cout << endl << "LEGEND : " << endl << "----------------" << endl <<  "▒▒▒ = Plains" << endl << "███ = River" << endl << "░░  = Desert" << endl << "♣♣♣ = Forest" << endl << "▲▲▲ = Mountains" << endl << "♦$♦ = Market" << endl;
		cout << endl << "You are at coordinates " << Hero.getXpos() << ", " << Hero.getYpos() << "." << endl;
		action = true;
		break;
	case 'N' :
		if (Hero.getYpos() > 8) {
			cout << "An invisible force compels you to stay within the map boundaries." << endl;
			action = true;
			break;
		}
		Hero.setYpos(Hero.getYpos() + 1);
		action = false;
		break;
	case 'E' :
		if (Hero.getXpos() > 8) {
			cout << "An invisible force compels you to stay within the map boundaries." << endl;
			action = true;
			break;
		}
		Hero.setXpos(Hero.getXpos() + 1);
		action = false;
		break;
	case 'W' :
		if (Hero.getXpos() < 1) {
			cout << "An invisible force compels you to stay within the map boundaries." << endl;
			action = true;
			break;
		}
		Hero.setXpos(Hero.getXpos() - 1);
		action = false;
		break;
	case 'S' :
		if (Hero.getYpos() < 1) {
			cout << "An invisible force compels you to stay within the map boundaries." << endl;
			action = true;
			break;
		}
		Hero.setYpos(Hero.getYpos() - 1);
		action = false;
		break;
	case '~' :
		if (jimbos == "smooth") {
			jimbos = "hesi";
			cout << endl << "You now have a  - Ｈ Ｅ Ｓ Ｉ   Ｊ Ｉ Ｍ Ｂ Ｏ- . Use it wisely." << endl;
			action = true;
			break;
		}
		if (jimbos == "hesi") {
			jimbos = "smooth";
			cout << endl << "Your jimbos are smooth once more. No one can deny that you REALLY hoop." << endl;
			action = true;
			break;
		}
	default:
		cout << "Invalid input!(Try capitalizing the letter)" << endl;
		action = true;
	}
	location(Hero);
}

/* void playerattack() {
if (player.stamina < 2) return 0;
player.stamina = player.stamina - 2;
enemy.health = enemy.health - (player.attack - (enemy.defense / player.attack));
if (enemy.health < 1) {
cout << "You won!" << endl;
exit(0);
}
 cout << "You attack for " << (player.attack - (enemy.defense / player.attack)) << " damage!" << endl;
 } */

int main() {
	Hero.setXpos(1);
	Hero.setYpos(2);
	srand(time(NULL));

	cout << "WELCOME TO EUGHQUEST" << endl;
	cout << "<PRESS ANY KEY TO CONTINUE>" << endl;
	char progress;
	cin >> progress;
	cout << endl;
	cout << "You wake up in a clearing. You must seal the demon. Memories of an old man surface as you remember your calling." << endl;
	while (jimbos == "smooth" || jimbos == "hesi") { //I will probably regret this at some point
		whatdoyoudo(Hero);
	}
	/*  string turn;
	cout << "Ready... fight! (Press G to attack, press H to defend!)" << endl;
	while (true) {
	cout << "Your turn!" << endl;
	cin >> turn;
	if (!cin || turn != (G || g || H || h)) {
	cout << "Try again!" << endl;
	continue
	}
	 if (turn == (G || g)) playerattack();
	 //defense thing here later
	 cout << "Enemy's turn!" << endl;
	 enemyattack();
	} */
}

