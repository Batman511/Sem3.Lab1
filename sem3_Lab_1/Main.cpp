#include "Sorts.h"
#include "Tests.h"
#include "ArraySequence.h"
#include <chrono>

//проверка на истинность сортировки
template<typename T>
bool auto_check(Sequence<T>* mas) {
	if (mas->GetLength() == 0)
		return true;
	int true_ = 1;

	for (int i = 0; i < mas->GetLength() - 1; i++) {
		if (mas->Get(i + 1) >= mas->Get(i))
			true_ += 1;
	}

	if (true_ == mas->GetLength())
		return true;
	else 
		return false;
}

void interface() {

	std::cout << "What type of data do you want to work with? \n";
	std::cout << "Choose type of the sequence:\n1. int\n2. double\n";
	int type;
	do {
		std::cin >> type; 
		if ((type != 1) && (type != 2))
		{
			std::cout << ("You must choose 1 or 2\n");
		}
	} while ((type != 1) && (type != 2));

	int sort_choice, test_choice,size_random, size_random2;
	
	//выбор функции
	int choice = 0;
	do {
		std::cout << "\n  Choose the operation:\n"
		"1. Enter sequence and sort it \n"
		"2. Find out the best sort for your sequence\n"
		"3. Create random sequence and sort it\n"
		"4. Find out the best sort for random sequence\n"
		"5. See Tests\n"
		"6. Check loyalty of sort\n"
		"7. exit\n";
		
		Sequence<int>* mas1;
		mas1 = new ArraySequence<int>();

		Sequence<double>* mas2;
		mas2 = new ArraySequence<double>();
	
		std::cout << "\nYour choice: ";
		std::cin >> choice; std::cout << "\n";

		switch (choice) {
		case 1:
			if (type == 1) mas1->Enter();
			if (type == 2) mas2->Enter();


			std::cout << " Choose the sort:\n"
				"1. MergeSort \n"
				"2. QuickSort\n"
				"3. SelectionSort\n";
			std::cin >> sort_choice;

			if (type == 1){
				std::cout << "Your sequence: \n";
				mas1->Print();
			}
			if (type == 2) {
				std::cout << "Your sequence: \n";
				mas2->Print();
			}

			if (sort_choice == 1) {
				if (type == 1) {int size = mas1->GetLength() ; MergeSort(mas1, 0, size - 1); }
				if (type == 2) { int size = mas2->GetLength(); MergeSort(mas2, 0, size - 1); }
				
				if (type == 1) {
					std::cout << "Right sequence: \n";
					mas1->Print();
				}
				if (type == 2) {
					std::cout << "Right sequence: \n";
					mas2->Print();
				}
			} else if (sort_choice == 2) {
				if (type == 1) { int size = mas1->GetLength(); QuickSort(mas1, 0, size - 1); }
				if (type == 2) { int size = mas2->GetLength(); QuickSort(mas2, 0, size - 1); }

				if (type == 1) {
					std::cout << "Right sequence: \n";
					mas1->Print();
				}
				if (type == 2) {
					std::cout << "Right sequence: \n";
					mas2->Print();
				}
			}else if (sort_choice == 3) {
				if (type == 1)  SelectionSort(mas1); 
				if (type == 2)  SelectionSort(mas2); 

				if (type == 1) {
					std::cout << "Right sequence: \n";
					mas1->Print();
				}
				if (type == 2) {
					std::cout << "Right sequence: \n";
					mas2->Print();
				}
			}

			delete[] mas1;
			delete[] mas2;

			break;
		case 2:
			Sequence<int> * mas1_1;
			mas1_1 = new ArraySequence<int>();
			Sequence<int>* mas1_2;
			mas1_2 = new ArraySequence<int>();
			Sequence<int>* mas1_3;
			mas1_3 = new ArraySequence<int>();

			Sequence<double>* mas2_1;
			mas2_1 = new ArraySequence<double>();
			Sequence<double>* mas2_2;
			mas2_2 = new ArraySequence<double>();
			Sequence<double>* mas2_3;
			mas2_3 = new ArraySequence<double>();


			if (type == 1) {
				std::cout << "Enter size of the sequence: ";
				int count;
				std::cin >> count;

				for (int i = 0; i < count; i++) {
					int data;
					std::cout << "Element " << i << " : ";
					std::cin >> data;
					mas1_1->Prepend(data);
					mas1_2->Prepend(data);
					mas1_3->Prepend(data);
				};
			}
			else if (type == 2) {
				std::cout << "Enter size of the sequence: ";
				int count;
				std::cin >> count;

				for (int i = 0; i < count; i++) {
					double data;
					std::cout << "Element " << i << " : ";
					std::cin >> data;
					mas2_1->Prepend(data);
					mas2_2->Prepend(data);
					mas2_3->Prepend(data);
				};
			}



			std::cout << "TimeList: \n";

			if (type == 1) {
				auto start1 = std::chrono::high_resolution_clock::now();
				MergeSort(mas1_1, 0, mas1_1->GetLength() - 1);
				auto finish1 = std::chrono::high_resolution_clock::now();
				auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(finish1 - start1);
				double time_sort1 = duration1.count();

				std::cout << "Time for Mergesort is " << time_sort1 << " mircosecond \n";



				auto start2 = std::chrono::high_resolution_clock::now();
				QuickSort(mas1_2, 0, mas1_2->GetLength() - 1);
				auto finish2 = std::chrono::high_resolution_clock::now();
				auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(finish2 - start2);
				double time_sort2 = duration2.count();

				std::cout << "Time for Quicksort is " << time_sort2 << " mircosecond \n";



				auto start3 = std::chrono::high_resolution_clock::now();
				SelectionSort(mas1_3);
				auto finish3 = std::chrono::high_resolution_clock::now();
				auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(finish3 - start3);
				double time_sort3 = duration1.count();

				std::cout << "Time for Selectionsort is " << time_sort3 << " mircosecond \n";
			}
			else if (type == 2) {
				auto start1 = std::chrono::high_resolution_clock::now();
				MergeSort(mas2_1, 0, mas2_1->GetLength() - 1);
				auto finish1 = std::chrono::high_resolution_clock::now();
				auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(finish1 - start1);
				double time_sort1 = duration1.count();

				std::cout << "Time for Mergesort is " << time_sort1 << " mircosecond \n";



				auto start2 = std::chrono::high_resolution_clock::now();
				QuickSort(mas2_2, 0, mas2_2->GetLength() - 1);
				auto finish2 = std::chrono::high_resolution_clock::now();
				auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(finish2 - start2);
				double time_sort2 = duration2.count();

				std::cout << "Time for Quicksort is " << time_sort2 << " mircosecond \n";



				auto start3 = std::chrono::high_resolution_clock::now();
				SelectionSort(mas2_3);
				auto finish3 = std::chrono::high_resolution_clock::now();
				auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(finish3 - start3);
				double time_sort3 = duration3.count();

				std::cout << "Time for Selectionsort is " << time_sort3 << " mircosecond \n";
			}

			delete[] mas1_1;
			delete[] mas1_2;
			delete[] mas1_3;
			delete[] mas2_1;
			delete[] mas2_2;
			delete[] mas2_3;
			break;
		case 3:
			std::cout << "Size of random sequence:  ";
			std::cin >> size_random;

			Sequence<int>* random_1;
			random_1 = new ArraySequence<int>(size_random);

			for (int i = 0; i < size_random; i++)
				random_1->InsertAt(100 + rand()%1200,i);

			std::cout << "Random sequence: \n";
			random_1->Print();

			QuickSort(random_1,0,size_random-1);
			std::cout << "Right sequence: \n";
			random_1->Print();

			delete[] random_1;
			break;
		case 4:
			
			std::cout << "Size of random sequence:  ";
			std::cin >> size_random2;

			Sequence<int>* random__1;
			random__1 = new ArraySequence<int>(size_random2);
			Sequence<int>* random_2;
			random_2 = new ArraySequence<int>(size_random2);
			Sequence<int>* random_3;
			random_3 = new ArraySequence<int>(size_random2);

			for (int i = 0; i < size_random2; i++) {
				int ran = 100 + rand() % 1200;
					random__1->InsertAt(ran, i);
					random_2->InsertAt(ran, i);
					random_3->InsertAt(ran, i);
			}
			std::cout << "Random sequence: \n";
			random__1->Print();

			std::cout << "\n TimeList: \n";

			if (type == 1 || type == 2) {
				auto start11 = std::chrono::high_resolution_clock::now();
				MergeSort(random__1, 0, size_random2 - 1);
				auto finish11 = std::chrono::high_resolution_clock::now();
				auto duration11 = std::chrono::duration_cast<std::chrono::microseconds>(finish11 - start11);
				double time_sort11 = duration11.count();

				std::cout << "Time for Mergesort is " << time_sort11 << " mircosecond \n";



				auto start22 = std::chrono::high_resolution_clock::now();
				QuickSort(random_2, 0, size_random2 - 1);
				auto finish22 = std::chrono::high_resolution_clock::now();
				auto duration22 = std::chrono::duration_cast<std::chrono::microseconds>(finish22 - start22);
				double time_sort22 = duration22.count();

				std::cout << "Time for Quicksort is " << time_sort22 << " mircosecond \n";



				auto start33 = std::chrono::high_resolution_clock::now();
				SelectionSort(random_3);
				auto finish33 = std::chrono::high_resolution_clock::now();
				auto duration33 = std::chrono::duration_cast<std::chrono::microseconds>(finish33 - start33);
				double time_sort33 = duration33.count();

				std::cout << "Time for Selectionsort is " << time_sort33 << " mircosecond \n";
			}

			delete[] random__1;
			delete[] random_2;
			delete[] random_3; 
			break;
		case 5:
			std::cout << " Choose the test:\n"
				"1. test_MergeSort \n"
				"2. test_QuickSort\n"
				"3. test_SelectionSort\n";
			std::cin >> test_choice;

			if (test_choice == 1) test_MergeSort();
			else if (test_choice == 2) test_QuickSort();
			else if (test_choice == 3) test_SelectionSort();

			break;
		case 6:
			std::cout << "Write the sequence: \n";
			Sequence<int>* loyality_1;
			loyality_1 = new ArraySequence<int>();

			loyality_1->Enter();

			std::cout << "Your sequence: \n";
			loyality_1->Print();

			if (auto_check(loyality_1) == true) std::cout << "\n True";
			else std::cout << "\n False";

			delete[] loyality_1;
			break;
		case 7:
			std::cout << " ***** Good job ***** \n";
			break;
		default: std::cout << "ERROR. You need choose an action.";
		}
	} while (choice != 7);

}

int main() {

	interface(); 

	return 0;
}

