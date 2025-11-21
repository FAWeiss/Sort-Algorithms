
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

// Aufgabe Selection Sort mit einem Vekor (Back to coding)

//Funktion von Grund auf überarbeitet, um das Swapping korrekt zu implementieren.

void SelecionSort(std::vector<int>& vec)
{
	if (vec.empty())
	{
		std::cerr << "Vector empty!\n";
		return;
	}

	std::vector<int>::iterator min_pos;

	for (size_t i = 0; i < vec.size(); ++i)
	{
		min_pos = std::min_element(vec.begin() + i, vec.end());
		std::swap(*(vec.begin() + i), *min_pos);
	}
}

// Aufgabe Insertion Sort Algorithm mit zwei Vektoren (sortiert und unsortiert)

// Manuelles Verschieben der Iteratoren hat nicht zuverlässsig funktioniert (out of bounds), 
// daher die Funktion noch mal von Grund auf überarbeitet und stattdessen insert verwendet

std::vector<int> InsertionSort_SecondVec(std::vector<int>& unsorted_vec)
{
	if (unsorted_vec.empty())
	{
		std::cerr << "Vector empty!\n";
		return{};
	}

	std::vector<int> sorted_vec;
	std::vector<int>::iterator sort_pos;

	while (!unsorted_vec.empty())
	{
		sort_pos = std::upper_bound(sorted_vec.begin(), sorted_vec.end(), unsorted_vec.front());
		sorted_vec.insert(sort_pos, unsorted_vec.front());
		unsorted_vec.erase(unsorted_vec.begin());
	}
	return sorted_vec;
}

// Aufgabe Insertion Sort mit einem Vektor (Back to coding)

// Out of bounds Zugriffe ausgebessert

void InsertionSort_SingleVec(std::vector<int>& vec)
{
	if (vec.empty())
	{
		std::cerr << "Vector empty!\n";
		return;
	}

	std::vector<int>::iterator val_pos = vec.begin() + 1;
	std::vector<int>::iterator sort_pos = vec.begin();
	std::vector<int>::iterator shift_from_pos;
	std::vector<int>::iterator shift_to_pos;
	std::int32_t val = *val_pos;

	while (val_pos != vec.end())
	{
		val = *val_pos;
		sort_pos = val_pos;

		while ((sort_pos != vec.begin()) && (val <= *sort_pos))
		{
			--sort_pos;
		}

		shift_to_pos = val_pos;

		while ((shift_to_pos <= val_pos) && (shift_to_pos > sort_pos))
		{
			shift_from_pos = shift_to_pos - 1;
			*shift_to_pos = *shift_from_pos;

			--shift_to_pos;
		}

		*sort_pos = val;

		++val_pos;
	}
}

// Aufgabe Bubble Sort Algorithm mit einem Vektor

// Äußere Schleife hinzugefügt

void BubbleSort(std::vector<int>& vec)
{
	if (vec.empty())
	{
		std::cerr << "Vector empty!\n";
		return;
	}

	std::vector<int>::iterator first_val = vec.begin();
	std::vector<int>::iterator second_val = vec.begin() + 1;
	std::uint32_t temp = 0;

	for (size_t i = 0; i < vec.size(); ++i)
	{
		while (second_val != vec.end())
		{
			if (*first_val > *second_val)
			{
				temp = *second_val;
				*second_val = *first_val;
				*first_val = temp;
			}
			++first_val;
			++second_val;
		}
	}
}

// Aufgabe Bubble Sort mit einem Vektor (Back to coding, ChatGPT 4o)

void BubbleSortChatGpt(std::vector<int>& vec)
{
	if (vec.empty())
	{
		std::cerr << "Vector empty!\n";
		return;
	}

	std::uint32_t temp = 0;

	for (size_t i = 0; i < vec.size(); ++i)
	{
		for (size_t j = 0; j < vec.size() - 1 - i; ++j)
		{
			if (vec[j] > vec[j + 1])
			{
				temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
			}
		}
	}
}
