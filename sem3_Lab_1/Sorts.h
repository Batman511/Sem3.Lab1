#include "ArraySequence.h"


//���������� ��������
template <typename T>
Sequence<T>* MergeSort(Sequence<T>* mas, int left, int right) {
	if (left == right) return mas;
	//if (right == -1 || left > right) exit;


	int middle = (left + right) / 2;

	MergeSort(mas, left, middle);
	MergeSort(mas, middle + 1, right);

	int i(left), j(middle + 1); //������ ���� ����� � ������ ������
	Sequence<T>* tmp = new ArraySequence<T>(right+1); //����� ������
	//for (int k = 0; k < right; k++)
	//	tmp->Prepend(0);

	for (int step = 0; step < (right - left + 1); step++) {
		//���������� ������� �� ���������
		if ((j > right) || ((i <= middle) && (mas->Get(i) < mas->Get(j)))) { //������� ������������ � ����� �����
			tmp->InsertAt(mas->Get(i),step);
			//tmp->Prepend(mas->Get(i));
			i++;
		}
		else { //������� ������������ � ������ �����
			tmp->InsertAt(mas->Get(j),step);
			//tmp->Prepend(mas->Get(j));
			j++;
		}
	}
	//���������� ��������� �������
	for (int step = 0; step < (right - left + 1); step++)
		mas->InsertAt(tmp->Get(step),left + step);

	return mas;
}

//������� ����������
template <typename T>
Sequence<T>* QuickSort(Sequence<T>* mas, int left, int right) {
	if (left == right) return mas;
	if (right == -1 || left > right) exit;


	T index; //������������ �������
	int l_hold(left), r_hold(right); //����� � ������ �������
	index = mas->Get(left); //�������� � �������� ������

	while (left < right) { //���� ������� �� �����������
		while ((left < right) && (mas->Get(right) >= index))
			right--; //�� ���� ������� ������ ������� � ����� ���� �� ������ ������� ������� index
		if (left != right) { //���� ������� �� �����������, �� ������ ������� � �������� ����� ������� 
			mas->InsertAt(mas->Get(right),left);
			left++;
		}
		while ((left < right) && (mas->Get(left) <= index))
			left++; //���������� ������� ����� ������� ������ ���� �� ������ ������� ������� index
		if (left != right) {
			mas->InsertAt(mas->Get(left), right);
			right--;
		}
	}
	
	mas->InsertAt(index, left); //������ ������������ ������� �� ������ �����
	
	int index2 = left; //�������� �������
	left = l_hold;
	right = r_hold;

	//���������� �������� ���������� ��� ����� � ������ ����� ����� ������������� ��������
	if (left < index2)
		QuickSort(mas, left, index2 - 1);
	if (right > index2)
		QuickSort(mas, index2 + 1, right);

	return mas;
}

//���������� ������� �������
template <typename T>
Sequence<T>* SelectionSort(Sequence<T>* mas) {
	int size = mas->GetLength();
	if (size == 1) return mas;
	if (size == 0) exit;

	int min; //������ ��������
	T tmp;

	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (mas->Get(j) < mas->Get(min))
				min = j; //������� ���������� �������
		}

		tmp = mas->Get(i);
		mas->InsertAt(mas->Get(min), i);
		mas->InsertAt(tmp, min); //������ ����������� �� ����� i � ���������� ������ ����������
	}

	return mas;
}
