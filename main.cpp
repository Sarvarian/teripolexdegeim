#include <iostream>
#include <tuple>
#include <ctime>

#include "Art.cpp"

#define endl "\n"
#define sub auto

sub CreateNumbers(const int Difficulty) -> const std::tuple<int, int>;
sub GetInput() -> const std::tuple<int, int>;

int main() // This is 'main'. This is where program starts.
{
	srand((unsigned int)time(nullptr));


	{ // Print introduction.
		using std::cout;
		cout << Art::Start;
		cout << " The Dark Ones conqueror the world. Hero, you are our only hope." << endl;
		cout << " You need to find three magic numbers in order to defeat the Dark Ones." << endl;
		cout << " ----------------------------------------------------------------------" << endl;
	}

	while (true)
	{
		const int LevelDifficulty{ []() -> const int {static int Dificulity{ 0 }; Dificulity += 1; return Dificulity; }() };

		const auto [MagicSum, MagicProduct] { CreateNumbers(LevelDifficulty) };

		{ // Print game informations.
			using std::cout;
			cout << endl;
			cout << " --------- You are at Level " << LevelDifficulty << " --------- " << endl;
			cout << endl;
			cout << "* Sum of magic numbers is " << MagicSum << "." << endl;
			cout << "* Product of magic numbers is " << MagicProduct << endl;
			cout << endl;
		}

		const auto [GuessSum, GuessProduct] { GetInput() };

		if (GuessSum == MagicSum && GuessProduct == MagicProduct)
		{ // Print win message.
			if (LevelDifficulty == 10)
			{
				using std::cout;
				cout << endl;
				cout << Art::Win;
				cout << endl;
				cout << " --------------------------------------------------------------------------------------------" << endl;
				cout << " You find the three magic numbers and defeat The Dark Ones. Congratulation. You save the day." << endl;
				cout << " --------------------------------------------------------------------------------------------" << endl;
				break;
			}
		}
		else if ( GuessSum == 207 && GuessProduct == 328509)
		{
			using std::cout;
			cout << endl;
			cout << Art::Glitch;
			cout << endl;
			break;

		}
		else
		{ // Print lose message.
			using std::cout;
			cout << endl;
			cout << Art::Deamon;
			cout << " ----------------------------------------------------------------------------" << endl;
			cout << " You failed to find magic numbers. The Dark Ones now gonna destroy the world." << endl;
			cout << " ----------------------------------------------------------------------------" << endl;
			break;
		}
	}

	std::cin.clear();
	std::cin.ignore();
	std::cin.get();
	return 0;
}

sub CreateNumbers(const int Difficulty) -> const std::tuple<int, int>
{
	const int Modifier{ 5 * Difficulty };
	const int NumberA{ (rand() % Modifier) + 1 };
	const int NumberB{ (rand() % Modifier) + 1 };
	const int NumberC{ (rand() % Modifier) + 1 };

	return std::make_tuple(
		NumberA + NumberB + NumberC,
		NumberA * NumberB * NumberC
	);
}

sub GetInput() -> const std::tuple<int, int>
{
	using std::cin;
	int GuessA;
	int GuessB;
	int GuessC;
	cin >> GuessA >> GuessB >> GuessC;
	cin.clear();
	cin.ignore();
	return std::make_tuple(
		GuessA + GuessB + GuessC,
		GuessA * GuessB * GuessC
	);
}