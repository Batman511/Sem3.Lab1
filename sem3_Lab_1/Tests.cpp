#include "ArraySequence.h"
#include "List_Sequence.h"
#include "Sorts.h"

int Test_Array_Sequence() {
	int* pr{ new int[5] {11,12,13,14,15} };
	ArraySequence<int> mas1(pr, 5);

	int* priv{ new int[3] {23,16,4} };
	ArraySequence<int> mas2(priv, 3);

	if (mas1[1] == 12 && mas1[4] == 15)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (mas1.GetFirst() == 11)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (mas1.GetLast() == 15)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (mas1.GetLength() == 5)
		std::cout << "Test GetSize: success" << "\n";
	else {
		std::cout << "Test GetSize: fail" << "\n";
	};

	if (mas1.Get(3) == 14)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	mas1.Append(76);
	if (mas1.GetFirst() == 76)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	mas1.Prepend(8);
	if (mas1.GetLast() == 8)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};


	mas1.GetSubSequence(2, 5);
	if (mas1[2] == 12 && mas1[3] == 13 && mas1[4] == 14 && mas1[5] == 8)
		std::cout << "Test GetSubSequence: success" << "\n";
	else {
		std::cout << "Test GetSubSequence: fail" << "\n";
	};


	int data = 44;
	mas1.InsertAt(data, 4);
	if (mas1[4] == 44)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	ArraySequence<int>* p2 = mas1.Concat(&mas2);
	if (p2->Get(0) == 76 && p2->Get(1) == 11 && p2->Get(2) == 12 && p2->Get(3) == 13
		&& p2->Get(4) == 44 && p2->Get(5) == 8 && p2->Get(6) == 23 && p2->Get(7) == 16
		&& p2->Get(8) == 4)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};


	DynamicArray<int> mas3(2);
	if (mas3[0] == -842150451 && mas3[1] == -842150451)
		std::cout << "Test Creation constructor: success" << "\n";
	else {
		std::cout << "Test Creation constructor: fail" << "\n";
	};
	//-842150451

	delete[7] pr;
	delete[3] priv;

	return 0;
}

int Test_Dynamic_Array() {
	int* pr{ new int[5] {11,12,13,14,15} };
	DynamicArray<int> mas1(pr, 5);

	if (mas1[1] == 12 && mas1[4] == 15)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (mas1.GetLength() == 5)
		std::cout << "Test GetSize: success" << "\n";
	else {
		std::cout << "Test GetSize: fail" << "\n";
	};

	if (mas1.Get(3) == 14)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	mas1.Resize(7);
	if (mas1.GetLength() == 7)
		std::cout << "Test Resize: success" << "\n";
	else {
		std::cout << "Test Resize: fail" << "\n";
	};

	int data = 44;
	mas1.Set(5, data);
	if (mas1[5] == 44)
		std::cout << "Test Set: success" << "\n";
	else {
		std::cout << "Test Set: fail" << "\n";
	};

	DynamicArray<int> mas2(2);
	if (mas2[0] == -842150451 && mas2[1] == -842150451)
		std::cout << "Test Creation constructor: success" << "\n";
	else {
		std::cout << "Test Creation constructor: fail" << "\n";
	};
	//-842150451

	delete[5] pr;

	return 0;
}

int Test_Linked_list() {
	int* a{ new int[6] {1,4,5,7,4,17} };
	int* b{ new int[5] {5,11,8,9,2} };

	LinkedList<int> list1{ a,6 };
	LinkedList<int> list2{ b,5 };

	if (list1.GetFirst() == 1)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (list1.GetLast() == 17)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (list1[2] == 5 && list1[5] == 17)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (list1.GetLength() == 6)
		std::cout << "Test GetLenght: success" << "\n";
	else {
		std::cout << "Test GetLenght: fail" << "\n";
	};

	if (list1.Get(3) == 7)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	list1.Append(5);
	if (list1[0] == 5)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	list2.Prepend(9);
	if (list2[5] == 9)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};

	LinkedList<int>* p = list2.GetSubList(1, 4);
	if (p->Get(0) == 11 && p->Get(1) == 8 && p->Get(2) == 9 && p->Get(3) == 2)
		std::cout << "Test GetSubList: success" << "\n";
	else {
		std::cout << "Test GetSubList: fail" << "\n";
	};

	list2.InsertAt(3, 2);
	if (list2[2] == 3)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	LinkedList<int>* p2 = list1.Concat(&list2);
	if (p2->Get(0) == 5 && p2->Get(1) == 1 && p2->Get(2) == 4 && p2->Get(3) == 5
		&& p2->Get(4) == 7 && p2->Get(5) == 4 && p2->Get(6) == 17 && p2->Get(7) == 5
		&& p2->Get(8) == 11 && p2->Get(9) == 3 && p2->Get(10) == 8 && p2->Get(11) == 9
		&& p2->Get(12) == 2 && p2->Get(13) == 9)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};

	delete[7] a;
	delete[6] b;

	return 0;
}

int Test_List_Sequence() {
	int* a{ new int[6] {1,4,5,7,4,17} };
	LinkedListSequence<int> list1{ a,6 };

	int* b{ new int[5] {5,11,8,9,2} };
	LinkedListSequence<int> list2{ b,5 };

	if (list1.GetFirst() == 1)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (list1.GetLast() == 17)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (list1[2] == 5 && list1[5] == 17)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (list1.GetLength() == 6)
		std::cout << "Test GetLenght: success" << "\n";
	else {
		std::cout << "Test GetLenght: fail" << "\n";
	};

	if (list1.Get(3) == 7)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	list1.Append(5);
	if (list1.Get(0) == 5)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	list2.Prepend(9);
	if (list2.Get(5) == 9)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};

	Sequence<int>* p = list2.GetSubSequence(1, 4);
	if (p->Get(0) == 11 && p->Get(1) == 8 && p->Get(2) == 9 && p->Get(3) == 2)
		std::cout << "Test GetSubList: success" << "\n";
	else {
		std::cout << "Test GetSubList: fail" << "\n";
	};

	list2.InsertAt(3, 2);
	if (list2.Get(2) == 3)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	LinkedListSequence<int>* p2 = list1.Concat(&list2);
	if (p2->Get(0) == 5 && p2->Get(1) == 1 && p2->Get(2) == 4 && p2->Get(3) == 5
		&& p2->Get(4) == 7 && p2->Get(5) == 4 && p2->Get(6) == 17 && p2->Get(7) == 5
		&& p2->Get(8) == 11 && p2->Get(9) == 3 && p2->Get(10) == 8 && p2->Get(11) == 9
		&& p2->Get(12) == 2 && p2->Get(13) == 9)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};

	delete[7] a;
	delete[6] b;

	return 0;
}

void test_MergeSort() {
	std::cout << "   ***** TESTS MERGESORT *****   " << "\n";

	int* mas1_{ new int[9] { 2,4,17,8,34,1,55,0,3 } };
	ArraySequence<int> mas1(mas1_, 9);

	MergeSort(&mas1, 0, 8);
	if (mas1[0] == 0 && mas1[1] == 1 && mas1[2] == 2 && mas1[3] == 3 && mas1[4] == 4 && mas1[5] == 8
		&& mas1[6] == 17 && mas1[7] == 34 && mas1[8] == 55)
		std::cout << "Test Normal: success" << "\n";
	else {
		std::cout << "Test Normal: fail" << "\n";
	};
	delete[] mas1_;


	int* mas2_{ new int[5] { 70,14000,84,1123,1000 } };
	ArraySequence<int> mas2(mas2_, 5);

	MergeSort(&mas2, 0, 4);
	if (mas2[0] == 70 && mas2[1] == 84 && mas2[2] == 1000 && mas2[3] == 1123 && mas2[4] == 14000)
		std::cout << "Test Big: success" << "\n";
	else {
		std::cout << "Test Big: fail" << "\n";
	};
	delete[] mas2_;


	int* mas3_{ new int[1] { 4 } };
	ArraySequence<int> mas3(mas3_,1);

	MergeSort(&mas3, 0, 0);
	if (mas3[0] == 4)
		std::cout << "Test One_element: success" << "\n";
	else {
		std::cout << "Test One_element: fail" << "\n";
	};
	delete[] mas3_;


	int* mas4_{ new int[3] { 0,0,0 } };
	ArraySequence<int> mas4(mas4_,3);

	MergeSort(&mas4, 0, 2);
	if (mas4[0] == 0 && mas4[1] == 0 && mas4[2] == 0)
		std::cout << "Test Zero: success" << "\n";
	else {
		std::cout << "Test Zero: fail" << "\n";
	};
	delete[] mas4_;


	int* mas5_{ new int[6] { -23,0,-4,-10,-111,-1000 } };
	ArraySequence<int> mas5(mas5_, 6);
	MergeSort(&mas5, 0, 5);
	if (mas5[0] == -1000 && mas5[1] == -111 && mas5[2] == -23 && mas5[3] == -10 && mas5[4] == -4
		&& mas5[5] == 0)
		std::cout << "Test Negative: success" << "\n";
	else {
		std::cout << "Test Negative: fail" << "\n";
	};
	delete[] mas5_;


	int* mas6_{ new int[9] { 8,-4,-17,0,34,17,-26,48,0 } };
	ArraySequence<int> mas6(mas6_,9);

	MergeSort(&mas6, 0, 8);
	if (mas6[0] == -26 && mas6[1] == -17 && mas6[2] == -4 && mas6[3] == 0 && mas6[4] == 0 && mas6[5] == 8
		&& mas6[6] == 17 && mas6[7] == 34 && mas6[8] == 48)
		std::cout << "Test Mix: success" << "\n";
	else {
		std::cout << "Test Mix: fail" << "\n";
	};
	delete[] mas6_;


	int* mas7_{ new int[0] { } };
	ArraySequence<int> mas7(mas7_,0);

	MergeSort(&mas7, 0, 0);
	if (mas7.GetLength() == 0)
		std::cout << "Test Empty: success" << "\n";
	else {
		std::cout << "Test Empty: fail" << "\n";
	};
	delete[] mas7_;


	int* mas8_{ new int[6] { 15,14,13,12,11,10 } };
	ArraySequence<int> mas8(mas8_,6);

	MergeSort(&mas8, 0, 5);
	if (mas8[0] == 10 && mas8[1] == 11 && mas8[2] == 12 && mas8[3] == 13 && mas8[4] == 14 && mas8[5] == 15)
		std::cout << "Test Back: success" << "\n";
	else {
		std::cout << "Test Back: fail" << "\n";
	};
	delete[] mas8_;


	int* mas9_{ new int[6] { 10,11,12,13,14,15 } };
	ArraySequence<int> mas9(mas9_,6);

	MergeSort(&mas9, 0, 5);
	if (mas9[0] == 10 && mas9[1] == 11 && mas9[2] == 12 && mas9[3] == 13 && mas9[4] == 14 && mas9[5] == 15)
		std::cout << "Test Direction: success" << "\n";
	else {
		std::cout << "Test Direction: fail" << "\n";
	};
	delete[] mas9_;


	int* mas10_{ new int[2] { 8,-1 } };
	ArraySequence<int> mas10(mas10_,2);

	MergeSort(&mas10, 0, 1);
	if (mas10[0] == -1 && mas10[1] == 8)
		std::cout << "Test Two_element: success" << "\n";
	else {
		std::cout << "Test Two_element: fail" << "\n";
	};
	delete[] mas10_;

	
	double* mas11_{ new double[6] { -12.3,13.2,2.111,6.6,0,-2 } };
	ArraySequence<double> mas11(mas11_, 6);

	MergeSort(&mas11, 0, 5);
	if (mas11[0] == -12.3 && mas11[1] == -2 && mas11[2] == 0 && mas11[3] == 2.111 && mas11[4] == 6.6 && mas11[5] == 13.2)
		std::cout << "Test Double: success" << "\n";
	else {
		std::cout << "Test Double: fail" << "\n";
	};
	delete[] mas11_; 


}

void test_QuickSort() {
	std::cout << "   ***** TESTS QUICKSORT *****   " << "\n";

	int* mas1_{ new int[9] { 2,4,17,8,34,1,55,0,3 } };
	ArraySequence<int> mas1(mas1_, 9);

	QuickSort(&mas1, 0, 8);
	if (mas1[0] == 0 && mas1[1] == 1 && mas1[2] == 2 && mas1[3] == 3 && mas1[4] == 4 && mas1[5] == 8
		&& mas1[6] == 17 && mas1[7] == 34 && mas1[8] == 55)
		std::cout << "Test Normal: success" << "\n";
	else {
		std::cout << "Test Normal: fail" << "\n";
	};
	delete[] mas1_;


	int* mas2_{ new int[5] { 70,14000,84,1123,1000 } };
	ArraySequence<int> mas2(mas2_, 5);

	QuickSort(&mas2, 0, 4);
	if (mas2[0] == 70 && mas2[1] == 84 && mas2[2] == 1000 && mas2[3] == 1123 && mas2[4] == 14000)
		std::cout << "Test Big: success" << "\n";
	else {
		std::cout << "Test Big: fail" << "\n";
	};
	delete[] mas2_;


	int* mas3_{ new int[1] { 4 } };
	ArraySequence<int> mas3(mas3_, 1);

	QuickSort(&mas3, 0, 0);
	if (mas3[0] == 4)
		std::cout << "Test One_element: success" << "\n";
	else {
		std::cout << "Test One_element: fail" << "\n";
	};
	delete[] mas3_;


	int* mas4_{ new int[3] { 0,0,0 } };
	ArraySequence<int> mas4(mas4_, 3);

	QuickSort(&mas4, 0, 2);
	if (mas4[0] == 0 && mas4[1] == 0 && mas4[2] == 0)
		std::cout << "Test Zero: success" << "\n";
	else {
		std::cout << "Test Zero: fail" << "\n";
	};
	delete[] mas4_;


	int* mas5_{ new int[6] { -23,0,-4,-10,-111,-1000 } };
	ArraySequence<int> mas5(mas5_, 6);

	QuickSort(&mas5, 0, 5);
	if (mas5[0] == -1000 && mas5[1] == -111 && mas5[2] == -23 && mas5[3] == -10 && mas5[4] == -4
		&& mas5[5] == 0)
		std::cout << "Test Negative: success" << "\n";
	else {
		std::cout << "Test Negative: fail" << "\n";
	};
	delete[] mas5_;


	int* mas6_{ new int[9] { 8,-4,-17,0,34,17,-26,48,0 } };
	ArraySequence<int> mas6(mas6_, 9);

	QuickSort(&mas6, 0, 8);
	if (mas6[0] == -26 && mas6[1] == -17 && mas6[2] == -4 && mas6[3] == 0 && mas6[4] == 0 && mas6[5] == 8
		&& mas6[6] == 17 && mas6[7] == 34 && mas6[8] == 48)
		std::cout << "Test Mix: success" << "\n";
	else {
		std::cout << "Test Mix: fail" << "\n";
	};
	delete[] mas6_;


	int* mas7_{ new int[0] { } };
	ArraySequence<int> mas7(mas7_, 0);

	QuickSort(&mas7, 0, 0);
	if (mas7.GetLength() == 0)
		std::cout << "Test Empty: success" << "\n";
	else {
		std::cout << "Test Empty: fail" << "\n";
	};
	delete[] mas7_;


	int* mas8_{ new int[6] { 15,14,13,12,11,10 } };
	ArraySequence<int> mas8(mas8_, 6);

	QuickSort(&mas8, 0, 5);
	if (mas8[0] == 10 && mas8[1] == 11 && mas8[2] == 12 && mas8[3] == 13 && mas8[4] == 14 && mas8[5] == 15)
		std::cout << "Test Back: success" << "\n";
	else {
		std::cout << "Test Back: fail" << "\n";
	};
	delete[] mas8_;


	int* mas9_{ new int[6] { 10,11,12,13,14,15 } };
	ArraySequence<int> mas9(mas9_, 6);

	QuickSort(&mas9, 0, 5);
	if (mas9[0] == 10 && mas9[1] == 11 && mas9[2] == 12 && mas9[3] == 13 && mas9[4] == 14 && mas9[5] == 15)
		std::cout << "Test Direction: success" << "\n";
	else {
		std::cout << "Test Direction: fail" << "\n";
	};
	delete[] mas9_;


	int* mas10_{ new int[2] { 8,-1 } };
	ArraySequence<int> mas10(mas10_, 2);

	QuickSort(&mas10, 0, 1);
	if (mas10[0] == -1 && mas10[1] == 8)
		std::cout << "Test Two_element: success" << "\n";
	else {
		std::cout << "Test Two_element: fail" << "\n";
	};
	delete[] mas10_;


	double* mas11_{ new double[6] { -12.3,13.2,2.111,6.6,0,-2 } };
	ArraySequence<double> mas11(mas11_, 6);

	QuickSort(&mas11, 0, 5);
	if (mas11[0] == -12.3 && mas11[1] == -2 && mas11[2] == 0 && mas11[3] == 2.111 && mas11[4] == 6.6 && mas11[5] == 13.2)
		std::cout << "Test Double: success" << "\n";
	else {
		std::cout << "Test Double: fail" << "\n";
	};
	delete[] mas11_;

}

void test_SelectionSort() {
	std::cout << "   ***** TESTS SELECTIONSORT *****   " << "\n";

	int* mas1_{ new int[9] { 2,4,17,8,34,1,55,0,3 } };
	ArraySequence<int> mas1(mas1_, 9);

	SelectionSort(&mas1);
	if (mas1[0] == 0 && mas1[1] == 1 && mas1[2] == 2 && mas1[3] == 3 && mas1[4] == 4 && mas1[5] == 8
		&& mas1[6] == 17 && mas1[7] == 34 && mas1[8] == 55)
		std::cout << "Test Normal: success" << "\n";
	else {
		std::cout << "Test Normal: fail" << "\n";
	};
	delete[] mas1_;


	int* mas2_{ new int[5] { 70,14000,84,1123,1000 } };
	ArraySequence<int> mas2(mas2_, 5);

	SelectionSort(&mas2);
	if (mas2[0] == 70 && mas2[1] == 84 && mas2[2] == 1000 && mas2[3] == 1123 && mas2[4] == 14000)
		std::cout << "Test Big: success" << "\n";
	else {
		std::cout << "Test Big: fail" << "\n";
	};
	delete[] mas2_;


	int* mas3_{ new int[1] { 4 } };
	ArraySequence<int> mas3(mas3_, 1);

	SelectionSort(&mas3);
	if (mas3[0] == 4)
		std::cout << "Test One_element: success" << "\n";
	else {
		std::cout << "Test One_element: fail" << "\n";
	};
	delete[] mas3_;


	int* mas4_{ new int[3] { 0,0,0 } };
	ArraySequence<int> mas4(mas4_, 3);

	SelectionSort(&mas4);
	if (mas4[0] == 0 && mas4[1] == 0 && mas4[2] == 0)
		std::cout << "Test Zero: success" << "\n";
	else {
		std::cout << "Test Zero: fail" << "\n";
	};
	delete[] mas4_;


	int* mas5_{ new int[6] { -23,0,-4,-10,-111,-1000 } };
	ArraySequence<int> mas5(mas5_, 6);

	SelectionSort(&mas5);
	if (mas5[0] == -1000 && mas5[1] == -111 && mas5[2] == -23 && mas5[3] == -10 && mas5[4] == -4
		&& mas5[5] == 0)
		std::cout << "Test Negative: success" << "\n";
	else {
		std::cout << "Test Negative: fail" << "\n";
	};
	delete[] mas5_;


	int* mas6_{ new int[9] { 8,-4,-17,0,34,17,-26,48,0 } };
	ArraySequence<int> mas6(mas6_, 9);

	SelectionSort(&mas6);
	if (mas6[0] == -26 && mas6[1] == -17 && mas6[2] == -4 && mas6[3] == 0 && mas6[4] == 0 && mas6[5] == 8
		&& mas6[6] == 17 && mas6[7] == 34 && mas6[8] == 48)
		std::cout << "Test Mix: success" << "\n";
	else {
		std::cout << "Test Mix: fail" << "\n";
	};
	delete[] mas6_;


	int* mas7_{ new int[0] { } };
	ArraySequence<int> mas7(mas7_, 0);

	SelectionSort(&mas7);
	if (mas7.GetLength() == 0)
		std::cout << "Test Empty: success" << "\n";
	else {
		std::cout << "Test Empty: fail" << "\n";
	};
	delete[] mas7_;


	int* mas8_{ new int[6] { 15,14,13,12,11,10 } };
	ArraySequence<int> mas8(mas8_, 6);

	SelectionSort(&mas8);
	if (mas8[0] == 10 && mas8[1] == 11 && mas8[2] == 12 && mas8[3] == 13 && mas8[4] == 14 && mas8[5] == 15)
		std::cout << "Test Back: success" << "\n";
	else {
		std::cout << "Test Back: fail" << "\n";
	};
	delete[] mas8_;


	int* mas9_{ new int[6] { 10,11,12,13,14,15 } };
	ArraySequence<int> mas9(mas9_, 6);

	SelectionSort(&mas9);
	if (mas9[0] == 10 && mas9[1] == 11 && mas9[2] == 12 && mas9[3] == 13 && mas9[4] == 14 && mas9[5] == 15)
		std::cout << "Test Direction: success" << "\n";
	else {
		std::cout << "Test Direction: fail" << "\n";
	};
	delete[] mas9_;


	int* mas10_{ new int[2] { 8,-1 } };
	ArraySequence<int> mas10(mas10_, 2);

	SelectionSort(&mas10);
	if (mas10[0] == -1 && mas10[1] == 8)
		std::cout << "Test Two_element: success" << "\n";
	else {
		std::cout << "Test Two_element: fail" << "\n";
	};
	delete[] mas10_;


	double* mas11_{ new double[6] { -12.3,13.2,2.111,6.6,0,-2 } };
	ArraySequence<double> mas11(mas11_, 6);

	SelectionSort(&mas11);
	if (mas11[0] == -12.3 && mas11[1] == -2 && mas11[2] == 0 && mas11[3] == 2.111 && mas11[4] == 6.6 && mas11[5] == 13.2)
		std::cout << "Test Double: success" << "\n";
	else {
		std::cout << "Test Double: fail" << "\n";
	};
	delete[] mas11_;


}