
template <class T>
class ReferencePtr {
private:
	T* m_ptr;
public:

	ReferencePtr() : m_ptr{ nullptr } {}

	friend class ReferencePtr;
	template <class U>
	ReferencePtr(U* ptr) {
		m_ptr = ptr;
		if (m_ptr != nullptr)
			m_ptr->add_ref();
	}

	template <class U>
	ReferencePtr(const ReferencePtr<U>& other) {
		m_ptr = other.m_ptr;
		if(m_ptr!=nullptr)
			m_ptr->add_ref();
	}

	operator bool() const {
		// tu musi byc podmiana 
		// !node bo teraz dziala tak ze jak node == nullptr to nullptr == nullptr i zwraca true
		// warunek if(!node) bedzie prawdziwy
		return m_ptr != nullptr;
	}

	T* operator->() const {
		return m_ptr;
	}

	T* get_ptr() const { return m_ptr; }

	ReferencePtr<T>& operator=(T* ptr) {
		if (m_ptr == ptr)
			return *this;

		if (m_ptr != nullptr)
			m_ptr->release();

		m_ptr = ptr;

		if (ptr != nullptr)
			m_ptr->add_ref();

		return *this;
	}
	
	ReferencePtr<T>& operator=(const ReferencePtr<T>& other) {
		if (m_ptr == other.m_ptr)
			return *this;

		if (m_ptr != nullptr)
			m_ptr->release();

		m_ptr = other.m_ptr;

		if (m_ptr != nullptr)
			m_ptr->add_ref();

		return *this;
	}

	ReferencePtr(nullptr_t) {
		m_ptr = nullptr;
	}

	ReferencePtr(const ReferencePtr<T>& other){
		m_ptr = other.m_ptr;
		if(m_ptr!=nullptr)
			m_ptr->add_ref();
	}

	~ReferencePtr() {
		if (m_ptr != nullptr)
			m_ptr->release();
	}

	//AssignmentNode
	template <class U>
	ReferencePtr<U> cast() const {
		U *new_ptr = static_cast<U*>(m_ptr);
		return { new_ptr };
	}

};