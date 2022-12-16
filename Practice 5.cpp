#include <iostream>


class Smart_arr
{
public:
	int l = 0;
	int* arr = new int;


	void add(int num)
	{
		int* arr1 = new int[l + 1];
		for (int i = 0; i < l; i++)
		{
			arr1[i] = arr[i];
		}
		arr1[l] = num;
		l++;
		delete[] arr;
		arr = arr1;
	}

	void out_l()
	{
		std::cout << "Текущая длина: " << l << std::endl;
	}

	void out_elem(int i)
	{
		std::cout << "Элемент под индексом " << i << " - " << arr[i] << std::endl;
	}

	void replace_elem(int i, int new_elem)
	{
		arr[i] = new_elem;
	}

	void delete_elem(int i)
	{
		int* arr1 = new int[l - 1];
		int f = 0;
		for (int j = 0; j < l; j++)
		{
			if (j == i)
			{
				f++;
				continue;
			}
			arr1[j - f] = arr[j];
		}
		delete arr;
		l -= 1;
		arr = arr1;
	}

	void insert_elem(int num, int i)
	{
		int* arr1 = new int[l + 1];
		int f = 0;
		for (int j = 0; j < l + 1; j++)
		{
			if (j == i)
			{
				f++;
				arr1[i] = num;
			}
			else
			{
				arr1[j] = arr[j - f];
			}

		}
		delete arr;
		l++;
		arr = arr1;
	}

};


int main()
{
	setlocale(LC_ALL, "Russian");
	Smart_arr array;
	int inp, ind;

	std::cout << "Управление:\n0 - выход\n1 - добавить элемент\n2 - вывести длину\n3 - вывести элемент по индексу\n4 - заменить элемент по индексу\n5 - удалить элемент по индексу\n6 - вставить элемент по индексу" << std::endl;
	while (true)
	{
		std::cin >> inp;
		if (inp == 0)
		{
			break;
		}
		else
		{
			if (inp == 1)
			{
				std::cout << "Введите элемент:";
				std::cin >> inp;
				array.add(inp);
			}
			else
			{
				if (inp == 2)
				{
					array.out_l();
				}
				else
				{
					if (inp == 3)
					{
						if (array.l > 0)
						{
							std::cout << "Введите индекс:";
							std::cin >> inp;
							if (array.l > inp)
							{
								array.out_elem(inp);
							}
							
						}
					}
					else
					{
						if (inp == 4)
						{
							std::cout << "Введите элемент:";
							std::cin >> inp;
							std::cout << "Введите индекс:";
							std::cin >> ind;
							array.replace_elem(inp, ind);
						}
						else
						{
							if (inp == 5)
							{
								if (array.l > 0)
								{
									std::cout << "Введите индекс:";
									std::cin >> inp;
									if (array.l > inp)
									{
										array.delete_elem(inp);
									}
								}
								
							}
							else
							{
								if (inp == 6)
								{
									std::cout << "Введите элемент:";
									std::cin >> inp;
									std::cout << "Введите индекс:";
									std::cin >> ind;
									array.insert_elem(inp, ind);
								}
							}
						}
					}
				}
			}
		}
	}
}