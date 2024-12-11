#ifndef LIST_H
#define LIST_H
namespace PlannerCLI {
	/**
		\brief Dynamic Array.
	*/
	template<typename T>
	class List
	{
	public:
		List();
		virtual ~List();

		void Add(T data);
		T Remove(size_t position);

		size_t GetSize() const{
			return m_nSize;
		}

		void Update();

		T& operator[](size_t position);

	private:
		T* m_data;

		size_t m_nSize = 0;
	};

	template<typename T>
	List<T>::List() {
		this->m_data = (T*)calloc(1, sizeof(T*));
	}

	template<typename T>
	List<T>::~List() {
		
	}

	template<typename T>
	void List<T>::Add(T data) {
		this->m_nSize++;

		this->Update();

		m_data[m_nSize - 1] = data;
	}

	template<typename T>
	void List<T>::Update() {
		this->m_data = (T*)realloc(this->m_data, m_nSize * sizeof(T*));
	}

	template<typename T>
	T List<T>::Remove(size_t position) {
		T value = this->m_data[m_nSize - 1];

		this->m_nSize--;

		this->Update();

		return value;
	}

	template<typename T>
	T& List<T>::operator[](size_t position) {
		T value = this->m_data[m_nSize - 1];
		return value;
	}
}

#endif

