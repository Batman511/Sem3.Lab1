#include "ArraySequence.h"


//сортировка слиянием
template <typename T>
Sequence<T>* MergeSort(Sequence<T>* mas, int left, int right) {
	if (left == right) return mas;
	//if (right == -1 || left > right) exit;


	int middle = (left + right) / 2;

	MergeSort(mas, left, middle);
	MergeSort(mas, middle + 1, right);

	int i(left), j(middle + 1); //начало пути левой и правой частей
	Sequence<T>* tmp = new ArraySequence<T>(right+1); //новый массив
	//for (int k = 0; k < right; k++)
	//	tmp->Prepend(0);

	for (int step = 0; step < (right - left + 1); step++) {
		//записываем меньший из элементов
		if ((j > right) || ((i <= middle) && (mas->Get(i) < mas->Get(j)))) { //условие минимального в левой части
			tmp->InsertAt(mas->Get(i),step);
			//tmp->Prepend(mas->Get(i));
			i++;
		}
		else { //условие минимального в правой части
			tmp->InsertAt(mas->Get(j),step);
			//tmp->Prepend(mas->Get(j));
			j++;
		}
	}
	//перезапись исходного массива
	for (int step = 0; step < (right - left + 1); step++)
		mas->InsertAt(tmp->Get(step),left + step);

	return mas;
}

//быстрая сортировка
template <typename T>
Sequence<T>* QuickSort(Sequence<T>* mas, int left, int right) {
	if (left == right) return mas;
	if (right == -1 || left > right) exit;


	T index; //указательный элемент
	int l_hold(left), r_hold(right); //левая и правая границы
	index = mas->Get(left); //начинаем с крайнего левого

	while (left < right) { //пока границы не пересеклись
		while ((left < right) && (mas->Get(right) >= index))
			right--; //то есть двигаем правую границы к левой пока не найдем элемент меньший index
		if (left != right) { //если границы не пересеклись, то меняем местами и сдвигаем левую границу 
			mas->InsertAt(mas->Get(right),left);
			left++;
		}
		while ((left < right) && (mas->Get(left) <= index))
			left++; //аналогично двигаем левую границу вправо пока не найдем элемент больший index
		if (left != right) {
			mas->InsertAt(mas->Get(left), right);
			right--;
		}
	}
	
	mas->InsertAt(index, left); //ставим указательный элемент на нужное место
	
	int index2 = left; //обнуляем границы
	left = l_hold;
	right = r_hold;

	//рекурсивно вызываем сортировку для левой и правой части относ указательного элемента
	if (left < index2)
		QuickSort(mas, left, index2 - 1);
	if (right > index2)
		QuickSort(mas, index2 + 1, right);

	return mas;
}

//сортировка простым выбором
template <typename T>
Sequence<T>* SelectionSort(Sequence<T>* mas) {
	int size = mas->GetLength();
	if (size == 1) return mas;
	if (size == 0) exit;

	int min; //индекс минимума
	T tmp;

	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (mas->Get(j) < mas->Get(min))
				min = j; //находим наименьший элемент
		}

		tmp = mas->Get(i);
		mas->InsertAt(mas->Get(min), i);
		mas->InsertAt(tmp, min); //ставим минимальный на место i и продолжаем искать наименьшие
	}

	return mas;
}
