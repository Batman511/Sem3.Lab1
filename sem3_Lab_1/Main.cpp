#include "Sorts.h"
#include "Tests.h"
#include "ArraySequence.h"
#include "List_Sequence.h"
#include <chrono>
#include <string>

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

//// Для MergeSort      choice_sort=1
//// Для QuckSort       choice_sort=2
//// Для SelectionSort  choice_sort=3
template<typename T>
double time_sort(Sequence<T>*mas, int choice_sort) {

	auto start = std::chrono::high_resolution_clock::now();
	if (choice_sort == 2)  QuickSort(mas, 0, mas->GetLength() - 1);
	else if (choice_sort == 1)  MergeSort(mas, 0, mas->GetLength() - 1);
	else if (choice_sort == 3)  SelectionSort(mas);
	auto finish = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
	double time_sort = duration.count();
	return time_sort;
}

//проверка ввода
std::string check_enter(std::string mas[],int size) {
	int kok(0);

	std::string type;
	do {
		std::cin >> type;
		for (int i = 0; i < size; i++)
			if (type == mas[i]) kok++;
		if (kok!=1)	std::cout<<"ERROR. You need choose an action. \n";
	} while (kok!=1);

	return type;
};

void interface() {

	std::cout << "What type of data do you want to work with? \n";
	std::cout << "Choose type of the sequence:\n1. int\n2. double\n";

	std::string mas_check_enter_1[2]{ "1","2" };
	std::string new_type = check_enter(mas_check_enter_1, 2);
	int type;
	
	if (new_type == "1") type = 1;
	else if (new_type == "2") type = 2;

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

		std::cout << "\nYour choice: ";

		std::string mas_check_enter_2[7]{ "1","2","3","4","5","6","7"};
		std::string new_choice = check_enter(mas_check_enter_2, 7);

		if (new_choice == "1") choice = 1;
		else if (new_choice == "2") choice = 2;
		else if (new_choice == "3") choice = 3;
		else if (new_choice == "4") choice = 4;
		else if (new_choice == "5") choice = 5;
		else if (new_choice == "6") choice = 6;
		else if (new_choice == "7") choice = 7;

		Sequence<int>* mas1;
		mas1 = new ArraySequence<int>();

		Sequence<double>* mas2;
		mas2 = new ArraySequence<double>();

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
			std::cout << "Enter size of the sequence: ";
			int count;
			std::cin >> count;

			Sequence<int> * mas1_;
			mas1_ = new ArraySequence<int>();
			Sequence<int>* mas1_copy;
			mas1_copy = new ArraySequence<int>(count);
			
			Sequence<double>* mas2_;
			mas2_ = new ArraySequence<double>();
			Sequence<double>* mas2_copy;
			mas2_copy = new ArraySequence<double>(count);

			if (type == 1) {
				for (int i = 0; i < count; i++) {
					int data;
					std::cout << "Element " << i << " : ";
					std::cin >> data;
					mas1_->Prepend(data);
				};
				mas1_copy->Copy(mas1_);
			}
			else if (type == 2) {
				for (int i = 0; i < count; i++) {
					double data;
					std::cout << "Element " << i << " : ";
					std::cin >> data;
					mas2_->Prepend(data);
				};
				mas2_copy->Copy(mas2_);
			};

			std::cout << "TimeList: \n";

			if (type == 1) {
				double time_sort1 = time_sort(mas1_, 1);
				std::cout << "Time for Mergesort is " << time_sort1 << " mircosecond \n";
				mas1_->Copy(mas1_copy);

				/*
				auto start2 = std::chrono::high_resolution_clock::now();
				QuickSort(mas1_, 0, mas1_->GetLength() - 1);
				auto finish2 = std::chrono::high_resolution_clock::now();
				auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(finish2 - start2);
				double time_sort2 = duration2.count(); */

				double time_sort2 = time_sort(mas1_, 2);
				std::cout << "Time for Quicksort is " << time_sort2 << " mircosecond \n";
				mas1_->Copy(mas1_copy);

				/*auto start3 = std::chrono::high_resolution_clock::now();
				SelectionSort(mas1_);
				auto finish3 = std::chrono::high_resolution_clock::now();
				auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(finish3 - start3);
				double time_sort3 = duration3.count();*/

				double time_sort3 = time_sort(mas1_, 3);
				std::cout << "Time for Selectionsort is " << time_sort3 << " mircosecond \n";
			}
			else if (type == 2) {
				double time_sort1 = time_sort(mas2_, 1);
				std::cout << "Time for Mergesort is " << time_sort1 << " mircosecond \n";
				mas2_->Copy(mas2_copy);


				double time_sort2 = time_sort(mas2_, 2);
				std::cout << "Time for Quicksort is " << time_sort2 << " mircosecond \n";
				mas2_->Copy(mas2_copy);


				double time_sort3 = time_sort(mas2_, 3);
				std::cout << "Time for Selectionsort is " << time_sort3 << " mircosecond \n";
			}

			delete[] mas1_;
			delete[] mas1_copy;
			delete[] mas2_;
			delete[] mas2_copy;
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
			Sequence<int>* random__copy;
			random__copy = new ArraySequence<int>(size_random2);
			

			for (int i = 0; i < size_random2; i++) {
				int ran = 100 + rand() % 1200;
					random__1->InsertAt(ran, i);
			}
			random__copy->Copy(random__1);

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
				random__1->Copy(random__copy);


				auto start22 = std::chrono::high_resolution_clock::now();
				QuickSort(random__1, 0, size_random2 - 1);
				auto finish22 = std::chrono::high_resolution_clock::now();
				auto duration22 = std::chrono::duration_cast<std::chrono::microseconds>(finish22 - start22);
				double time_sort22 = duration22.count();

				std::cout << "Time for Quicksort is " << time_sort22 << " mircosecond \n";
				random__1->Copy(random__copy);


				auto start33 = std::chrono::high_resolution_clock::now();
				SelectionSort(random__1);
				auto finish33 = std::chrono::high_resolution_clock::now();
				auto duration33 = std::chrono::duration_cast<std::chrono::microseconds>(finish33 - start33);
				double time_sort33 = duration33.count();

				std::cout << "Time for Selectionsort is " << time_sort33 << " mircosecond \n";
			}

			delete[] random__1;
			delete[] random__copy;
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
		default: std::cout << "ERROR. You kill me.";
		}
	} while (choice != 7);

}

int main() {

	interface(); 
	return 0;
}

