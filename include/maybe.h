#pragma once
#include <stdexcept>

// Resembles a optional field.
template<typename T> class Maybe {
	T* value;
public:
	Maybe() : value(nullptr) {}
	Maybe(const T& t) : value(new T(t)){}
	Maybe(const Maybe& copy) : value(copy.value){
		// You can't make a deep copy of Maybe,
		// however you can shift copy it.
        throw std::logic_error();
	}

	Maybe(Maybe&& _) : value(_.value) {
		_.value = nullptr; // Transfer ownership.
	}

	virtual ~Maybe() {
		if(value) delete value;
	}

	virtual const T* get(){
		return value;
	};

	inline const T& operator*() {
        return *value;
	}
};
