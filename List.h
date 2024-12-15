#ifndef LIST_H
#define LIST_H

#include <iostream>
namespace PlannerCLI {
	/**
		\brief Dynamic Array.

		\remarks This class remains incomplete and filled with bugs,
	*/
	template<typename T>
	class List
	{
	public:
		List();
		virtual ~List();

		void Add(T data);
		T& At(size_t position);
		T Remove(size_t position);

		size_t GetSize() const{
			return m_nSize;
		}

		void Update();

		T& operator[](size_t position);

	protected:
		void Allocate();
	private:
		T* m_data;

		size_t m_nSize = 0;
	};

	template<typename T>
	List<T>::List() {
		
	}

	template<typename T>
	List<T>::~List() {
		if (this->m_nSize != 0) {
			free(this->m_data);
			this->m_nSize = 0;
		}
	}

	template<typename T>
	void List<T>::Add(T data) {
		this->m_nSize++;

		std::cout << "Size: " << this->m_nSize << std::endl;
		std::cout << "Size of data: " << sizeof(data) << std::endl;
		std::cout << "Size of T: " << sizeof(T) << std::endl;

		T* temp = this->m_data;

		if (this->m_nSize > 1) {
			this->Update();
		}
		else {
			this->Allocate();
		}

		std::cout << "Size of m_data" << sizeof(this->m_data) << std::endl;

		if (!this->m_data) {
			std::cout << "Error reallocating memory" << std::endl;
			this->m_data = temp;
		}
		else {
			this->m_data[this->m_nSize - 1] = data;
		}
	}

	template<typename T>
	T& List<T>::At(size_t position) {
		T value = this->m_data[position];
		return value;
	}

	template<typename T>
	void List<T>::Allocate() {
		this->m_data = (T*)calloc(this->m_nSize, sizeof(T));
	}

	template<typename T>
	void List<T>::Update() {
		this->m_data = (T*)realloc(this->m_data, this->m_nSize * sizeof(T));
	}

	template<typename T>
	T List<T>::Remove(size_t position) {
		T value = this->m_data[m_nSize - 1];

		this->m_nSize--;

		if (this->m_nSize > 1) {
			this->Update();
		}

		return value;
	}

	template<typename T>
	T& List<T>::operator[](size_t position) {
		return this->At(position);
	}
}

#endif

