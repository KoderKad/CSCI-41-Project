#include<iostream>
#include<cmath>
#include<ctime>
#include<vector>
#include<limits>
#include<utility>
using namespace std;

void die() {
	cout << "Game Over, maybe you need to sharpen your skills." << endl;
	exit(1);
}

int main() {
	cout << "Welcome to The Rooms" << endl;
	cout << "This is a text-based role-playing game involving math problems and decision making." << endl;
	cout << "As you progress, write or remember answers to questions. As if you mess up, you will have to start from the beginning." << endl;
	cout << "Developed by Kehardip Dhillon and Austin Reichman." << endl;
	cout << "Art presented on paper, with an online link available." << endl;
	cout << "Press any valid number and enter when you are ready to begin." << endl;
	int a = 0;
	cin >> a;
	//VET
	if (!cin || a != 1) {
		cout << "If you can't start the game properly, you should probably not play the game. Otherwise ignore the reccomendation, and proceed on." << endl;
		{
			die();
		}
	}
	cout << "In 2532, the earth is withered and dying, from the change of the climate, to man-made conflict." << endl;
	cout << "Culture has changed from war, bad leadership, and government corruption. Baseless rebellions to authoritarian rule affects politics." << endl;
	cout << "Humans turn to extremes, just to get by, while some thrive upon it." << endl;
	cout << "From selling one's child for food, to the upperclass of society watching humans complete life-threatening experiments, like rats in mazes." << endl;
	cout << "The experiments are cruel and inhumane produced to make a profit. Comparable to gladiator pits of the Roman era." << endl;
	cout << "People are often used in these experiments, which range from physical to mentally draining tasks." << endl;
	cout << "The goal is for the person to complete the assigned objective." << endl;
	cout << "The experiments have many cameras livestreaming the events as they take place." << endl;
	cout << "Many people have died at the expense of entertainment." << endl;
	cout << "Not everyone is given a choice in whether they participate in the mazes." << endl;
	cout << "You are a test subject in a maze, with all eyes on you." << endl;
	cout << "The maze you are in, is called The Rooms." << endl;
	cout << "Many have attempted it before you, but with bad luck and skill, have perished." << endl;
	cout << "With procedural changes, and problem-solving, this maze always seems to amaze the crowd watching." << endl;
	cout << "Get ready to fight for your life." << endl;
	cout << "Press 1 to continue on." << endl;
	int l = 0;
	cin >> l;
	if (!cin || l != 1) die();
	cout << "You wake up to find youself in what appears to be a room with multiple cameras and white walls, as if you're being observed." << endl;
	cout << "The only object you have is a compuer tablet with instructions labeled chronologically." << endl;
	cout << "It appears to be named Tessa, and has an audio output." << endl;
	cout << "Tessa: You've been selected unconsenually to participate in the escape of this maze." << endl;
	cout << "Tessa: I will guide you through the maze, if you follow my instructions you will survive this test." << endl;
	cout << "Tessa: As you move through the maze, you will not be permitted to go back, unless permitted." << endl;
	cout << "Objective 1: There is a door north of you. Without any knowledge of how you got here, you must escape alive." << endl;
	cout << "Control: Type 1 to proceed to the door." << endl;
	cout << "(Location: Room 1)" << endl;
	int b = 0;
	cin >> b;
	//In room 1
	if (!cin || b != 1) die();
	cout << "(Location: Room 1)" << endl;
	cout << "As you approach the door, you notice a computer interface displaying a math problem. It requires an answer to open." << endl;
	cout << "Tessa: Solve the math problem to unlock the door. If you miss the problem, you will be terminated. The problem is: 2x+1=15" << endl;
	cout << "Objective 2: Solve 2x+1=15" << endl;
	cout << "Control: Type the answer numerically to proceed." << endl;
	int c = 0;
	cin >> c;
	//In room 1
	if (!cin || c != 7) die();
	cout << "(Location: Room 2)" << endl;
	cout << "Using basic algebra you were able to unlock the door." << endl;
	cout << "As you walk into the new room, you realize cameras are still present. The door behind you closes." << endl;
	cout << "Another identical door to the north in this room, but with a different problem." << endl;
	cout << "Tessa: Solve the math problem to complete part 1 of 2 in this exercise, to ultimately unlock the door." << endl;
	cout << "Part 1 of Objective 3: (-2(3+1)-5(x+6)+3=-15)" << endl;
	cout << "Control: Type in the answer without spaces." << endl;
	int d = 0;
	cin >> d;
	//In room 2
	if (!cin || d != -4) die();
	cout << "(Location: Room 2)" << endl;
	cout << "Part 1 is solved, now for part 2." << endl;
	cout << "Part 2 is displayed as a critical-thinking problem." << endl;
	cout << "Tessa: Solve the question, or the room will fill with lava." << endl;
	cout << "Part 2 of Objective 3: A family are on their way to the mall. They spend 1 and 1/4 hours to drive to the mall. They spend 6 and 1/2 hours at the mall. They spend 2 and 1/4 hours driving home. How much time is spent driving to and from the mall including the hours they were at the mall?" << endl;
	cout << "Control: Type in the answer numerically." << endl;
	int e = 0;
	cin >> e;
	//In room 2
	if (!cin || e != 10) die();
	cout << "(Location: Room 3)" << endl;
	cout << "Congratulations you have passed the second room, please enter room 3." << endl;
	cout << "Room 3 has another monitor with more problems to solve." << endl;
	cout << "Tessa: To advance past the next stage, you will answer the following questions." << endl;
	cout << "Problem 1: What has a face and two hands but no arms or legs?" << endl;
	cout << "Control: Type in the number corresponding to the best answer." << endl;
	cout << "(1):Trees" << endl;
	cout << "(2):Clock" << endl;
	cout << "(3):Liquid" << endl;
	cout << "(4):Corn" << endl;
	int f = 0;
	cin >> f;
	//In room 3
	if (!cin || f != 2) die();
	cout << "(Location: Room 3)" << endl;
	cout << "Problem 2: What man cannot live in a house?" << endl;
	cout << "Control: Type in the number corresponding to the best answer." << endl;
	cout << "(1):Snowman" << endl;
	cout << "(2):Homeless Woman" << endl;
	cout << "(3):Cashier" << endl;
	cout << "(4):Divorced Person" << endl;
	int g = 0;
	cin >> g;
	//In room 3
	if (!cin || g != 1) die();
	cout << "(Location: Room 3)" << endl;
	cout << "Problem 3: Why is a river rich?" << endl;
	cout << "Control: Type in the number corresponding to the best pun." << endl;
	cout << "(1):Because it invested correctly." << endl;
	cout << "(2):It is what it is." << endl;
	cout << "(3):The river contains gold." << endl;
	cout << "(4):It has 2 banks." << endl;
	int h = 0;
	cin >> h;
	//In room 3
	if (!cin || h != 4) die();
	cout << "(Location: Room 4)" << endl;
	cout << "The door latch begins to unwind." << endl;
	cout << "The door is now unlocked, you may now pass through the corridors and into the swamp land." << endl;
	cout << "The room is earth-like with a moist environment." << endl;
	cout << "Tessa: You must make your way through this area. Use the brain to defeat the monster in this room, or you will lose it." << endl;
	cout << "You find a pulse rifle on the ground, with instructions on how to operate it." << endl;
	cout << "Instructions: This weapon is powered by fusion cells, and it will automatically reload if you solve the questions it asks." << endl;
	cout << "Instructions: If you miss the question, the weapon will self-destruct, killing you in the process." << endl;
	cout << "Instructions: Only one round can be loaded at a time, aim at the object you intend to neutralize, and pull the trigger to shoot." << endl;
	cout << "Tessa: Load the first round by solving the problem presented currently on the weapons interface." << endl;
	cout << "Problem 1: 2+8= " << endl;
	int i = 0;
	cin >> i;
	//In room 4
	if (!cin || i != 10) die();
	cout << "(Location: Room 4)" << endl;
	cout << "The round is chambered, and ready to shoot." << endl;
	cout << "The mud is moist and deep but you manage to trudge through. The moisture in the air is heavy with buzzing activity and the sounds come from a far." << endl;
	cout << "You noticed a writhing between your legs. Suddenly it has you, it starts to wrap its tentacles around your legs and lifts its head to peer through the night straight into your eyes. Blazing bright yellow, the monster wears its teeth is a gruesome smile." << endl;
	cout << "Monster: You look weary and absolutely delicious human. I'm going to kill you aaaaahhhhhhh." << endl;
	cout << "(Monster Health: 100/100)" << endl;
	cout << "Shoot the monster by pressing 1." << endl;
	int j = 0;
	cin >> j;
	//room 4
	if (!cin || j != 1) die();
	cout << "(Location: Room 4)" << endl;
	cout << "(Monster Health: 70/100)" << endl;
	cout << "The shot was able to hit its chest." << endl;
	cout << "Monster: Darn you sly humans, I’ve been waiting to consume you for quite some time. Don’t think I’m through with you just yet, you will be seeing me soon. The monster says as it disappears below the murky water surface." << endl;
	cout << "Tessa: Reload your weapon. Don't forget you must kill the monster, and continue to the exist to escape." << endl;
	cout << "Problem 2: 20-1000= " << endl;
	int k = 0;
	cin >> k;
	//room 4
	if (!cin || k != -980) die();
	cout << "(Location: Room 4)" << endl;
	cout << "(Weapon Reloaded)" << endl;
	cout << "As you press forward through the mud and mirk you notice the humidity is starting to decrease and lighter slowly filling the air. Instead of loud smacks you notice the once wet ground is becoming harder and dryer turning to solid stone." << endl;
	cout << "Tessa: You are getting close to the exit. The monster will be expecting its dinner." << endl;
	cout << "You hear a loud sound from all directions. Then all of a sudden, the beast reappears before you. " << endl;
	cout << "Monster: THIS ENDS HERE!" << endl;
	cout << "Respond to the monster's threat." << endl;
	cout << "Control: Enter 1 to beg for your life. Enter 2 to taunt the monster." << endl;
	int m = 0;
	cin >> m;
	if (!cin) die();
	if (m < 1 || m > 2) die();
	if (m == 1) {
		cout << "You: Please don't hurt me!" << endl;
		cout << "You: I don't want to die!" << endl;
		cout << "You: I'm pooping my pants, my diaper is full!" << endl;
		cout << "You: We could talk this out." << endl;
		cout << "You: Maybe we can negotiate some kind of deal for my life." << endl;
		cout << "Monster: Time to die you wimpy child!" << endl;
		cout << "The monster feels confident to kill you quickly." << endl;
	}
	if (m == 2) {
		cout << "You: YOU CAN TRY LOSER THING! I WAS MEANT TO WIN THIS BATTLE!" << endl;
		cout << "You: What are you doing to do? Huh?" << endl;
		cout << "You: You're not going to do anything little baby." << endl;
		cout << "You: I'm going to teach you a thing or two in manners." << endl;
		cout << "You: I'm going to blow your head of stupid monster boy." << endl;
		cout << "Monster: HOW DARE YOU!" << endl;
		cout << "The monster is shocked at your response." << endl;
	}
	//room 4
	cout << "(Location: Room 4)" << endl;
	cout << "(Monster Health: 70/100)" << endl;
	cout << "You aim your gun at the monster, as it begins to charge you." << endl;
	cout << "You must think quickly of what your next decision will be. So what will it be." << endl;
	cout << "Press 1 to shoot at the monster." << endl;
	int n = 0;
	cin >> n;
	if (!cin || n != 1) die();
	//room 4
	cout << "(Location: Room 4)" << endl;
	cout << "(Monster Health: 40/100)" << endl;
	cout << "The monster has been stunned by your shot. It's a matter of time before it regains its strength to charge you." << endl;
	cout << "Tessa: I will let you decide between two choices, for you next move." << endl;
	cout << "Option (1): Keep moving and it will require one supercharged plasma round with a more complex problem." << endl;
	cout << "Option (2): Or complete one hard algebra problem to supercharge your round to the damage of 2 normal rounds." << endl;
	cout << "Tessa: It's your choice, but make it quick, as the monster is almost ready again." << endl;
	cout << "Control: Enter 1 or 2." << endl;
	int o = 0;
	cin >> o;
	if (!cin || o < 1 || o > 2) die();
	if (o == 1) {
		cout << "2x+1+1+1+1*0+1*2*5*0=1145" << endl;
		cout << "Type the answer numerically" << endl;
	}
	if (o == 2) {
		cout << "(3900+97)=7x" << endl;
		cout << "Simplify the equation." << endl;
	}
	int p = 0;
	cin >> p;
	if (!cin || p != 571) die();
	cout << "(Location: Room 4)" << endl;
	cout << "(Monster Health: 40/100)" << endl;
	cout << "Weapon has been supercharged." << endl;
	cout << "Press 1 to neutralize monster." << endl;
	int q = 0;
	cin >> q;
	if (!cin || q != 1) die();
	cout << "(Location: Room 4)" << endl;
	cout << "(Monster Health: 0/100)" << endl;
	cout << "The monster falls to the ground with its eyes wide open as it screams its last breath." << endl;
	cout << "Tessa: Can't say I'm not surprised." << endl;
	cout << "You finally make yourself to the exit, as the doors open themselves." << endl;
	cout << "Enter 1 to give an angry response. Enter 2 to give a sad response. " << endl;
	cout << "Control: Enter 1 or 2." << endl;
	int r = 0;
	cin >> r;
	if (!cin || r < 1 || r > 2) die();
	if (r == 1) {
		cout << "You: I hate you all!" << endl;
		cout << "You: You've all ruined my life." << endl;
		cout << "You: When I get the chance, I'm going to kill all of you." << endl;
		cout << "You: Everyone watching directly or indirectly supports this!" << endl;
		cout << "You: This isn't the American dream!" << endl;



	}
	if (r == 2) {
		cout << "You: What has my life been reduced to?" << endl;
		cout << "You: I don't know what I'm even doing right now." << endl;
		cout << "You: Was that monster a slave too?" << endl;
		cout << "You: This is messed up, bigtime. I don't know if I can go on like this." << endl;
		cout << "You: I feel bad..." << endl;

	}
	cout << "You win the game." << endl;
	cout << "You are free to go." << endl;
	cout << "Hope you enjoyed the game." << endl;
	cout << "Walking into the next room you are met with a new scenery. The left and right walls display numbers, and there are 3 doors north of the room." << endl;
	cout << "Tessa: I'm impressed that you made it this far. Most die during the algebra. " << endl;
	cout << "Tessa: You will use the numbers listed on the walls to choose your path through 1 of the 3 doors." << endl;
	cout << "Tessa: Haha just kidding, I will guide you out now." << endl;
	cout << "Your character makes it out of the maze with his head intact. " << endl;
	cout << "The End" << endl;



}

