#pragma once
#include <stdexcept>

// Resembles a optional field.
template<typename T> class Maybe {
	T* value;
public:
	Maybe() : value(nullptr) {}
	Maybe(const T& t) : value(new T(t)){}
	Maybe(const Maybe& copy) :
		value(copy.value == nullptr?
			nullptr : new T(*(copy.value))) {}

	Maybe(Maybe&& _) : value(_.value) {
		_.value = nullptr; // Transfer ownership.
	}

	~Maybe() {
		if(value) delete value;
	}

	inline const T* get(){
		return value;
	};

	inline const T& operator*() {
		return *value;
	}

	bool operator!() {
		return value == nullptr;
	}
};
