
#include <iostream>
#include <vector>
#include <cstdint>

// Aufgabe Selection Sort mit einem Vekor (Back to coding)

void SelecionSort(std::vector<int>& vec)
{
	std::uint32_t min_val = 0;
	size_t prev_index = 0;

	for (size_t min_index = 0; min_index < vec.size(); ++min_index)
	{
		min_val = vec[min_index];

		for (size_t j = 0; j < vec.size(); ++j)
		{
			if (vec[j] < min_val)
			{
				min_val = vec[j];
				prev_index = j;
			}
		}
		vec[prev_index] = vec[min_index];
		vec[min_index] = min_val;
	}
}

// Aufgabe Insertion Sort Algorithm mit zwei Vektoren (sortiert und unsortiert)

std::vector<int> InsertionSort_SecondVec(std::vector<int>& unsorted_vec)
{
	std::vector<int> sorted_vec;
	std::vector<int>::iterator sort_pos = sorted_vec.end();
	std::vector<int>::iterator shift_pos;
	std::uint32_t val = *unsorted_vec.begin();

	while (unsorted_vec.size() > 0)
	{
		val = *unsorted_vec.begin();
		sort_pos = sorted_vec.end();

		while (*sort_pos > val)
		{
			shift_pos = sort_pos + 1;
			*shift_pos = *sort_pos;

			--sort_pos;
		}

		*sort_pos = val;

		unsorted_vec.erase(unsorted_vec.begin());
	}
}

// Aufgabe Insertion Sort mit einem Vektor (Back to coding)

void InsertionSort_SingleVec(std::vector<int>& vec)
{
	std::vector<int>::iterator val_pos = vec.begin();
	std::vector<int>::iterator sort_pos = vec.begin();
	std::vector<int>::iterator shift_from_pos;
	std::vector<int>::iterator shift_to_pos;
	std::uint32_t val = *val_pos;

	while (val_pos != vec.end())
	{
		val = *val_pos;
		sort_pos = val_pos;

		while (val <= *sort_pos)
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

void BubbleSort(std::vector<int>& vec)
{
	std::vector<int>::iterator first_val = vec.begin();
	std::vector<int>::iterator second_val = vec.begin() + 1;
	std::uint32_t temp = 0;

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

// Aufgabe Bubble Sort mit einem Vektor (Back to coding, ChatGPT 4o)

void BubbleSortChatGpt(std::vector<int>& vec)
{
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


