#include <iostream>

class SmartArray {
public:
	int* arr_;
	int count_newnum = 0;
	int count_num = 0;

	explicit SmartArray(int count_num_) {
		arr_ = new int[count_num_];
		count_num = count_num_;
	}

	void outputSmartArray() {
		std::cout << "Array: " << std::endl;
		for (int i = 0; i < count_num; i++) {
			std::cout << arr_[i] << "\n";
		}
		std::cout << "\n";
	}

	void add_element(int newnum_) {
		if (count_newnum < count_num) {
			arr_[count_newnum] = newnum_;
			count_newnum++;
		}
		else { std::cout << "Overflow! Number '" << newnum_ << "' doesn't added." << "\n\n"; }
	}

	void print_element(int i_elem) {
		if (i_elem < count_num) {
			std::cout << i_elem << " ";
			std::cout << "Element = " << arr_[i_elem] << ";" << std::endl;
		}
		else { std::cout << i_elem << " Element " << "doesn't exist." << std::endl; }

	}

	int get_element(int i_elem) {
		if (i_elem < count_num) {
			return arr_[i_elem];
		}
		else { std::cout << i_elem << " Element " << "doesn't exist." << std::endl; }

	}

	void put_in_array(int i_, int i_put_) {
		arr_[i_] = i_put_;
	}

	~SmartArray() {
		delete[]arr_;
	}
};


int main()
{
	try {
		int amount_elem = -1;
		do{
			std::cout << "Enter amount elements of array: ";
			std::cin >> amount_elem;
		} while (amount_elem < 0);
		std::cout << std::endl;

		SmartArray arr1(amount_elem);
		arr1.add_element(1);
		arr1.add_element(4);
		arr1.add_element(5);
		arr1.outputSmartArray();

		SmartArray arr2(3);
		arr2.add_element(99);
		arr2.add_element(32);
		arr2.add_element(55);
		arr2.outputSmartArray();


		for (int i = 0; i < amount_elem; i++) {
			int i_copy = 0;
			i_copy = arr2.get_element(i);
			arr1.put_in_array(i, i_copy);
		}

		arr1.outputSmartArray();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}