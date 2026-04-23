#include <algorithm>
#include <cstring>
#include <vector>

class str
{
private:
	char* data;
	size_t size;
	
	void allocate_and_copy(const char* s) {
		if (s == nullptr) {
			size = 0;
			data = new char[1];
			data[0] = '\0';
		} else {
			size = std::strlen(s);
			data = new char[size + 1];
			std::strcpy(data, s);
		}
	}

public:
	str() : data(new char[1]), size(0) {
		data[0] = '\0';
	}
	
	str(const char &c) : size(1) {
		data = new char[2];
		data[0] = c;
		data[1] = '\0';
	}

	str(const char *&& s_) {
		allocate_and_copy(s_);
	}

	str &operator=(const char *&& s_) {
		delete[] data;
		allocate_and_copy(s_);
		return *this;
	}

	str(const str &other) : size(other.size) {
		data = new char[size + 1];
		std::strcpy(data, other.data);
	}

	str &operator=(const str &other) {
		if (this != &other) {
			delete[] data;
			size = other.size;
			data = new char[size + 1];
			std::strcpy(data, other.data);
		}
		return *this;
	}

	char &operator[](size_t pos) {
		return data[pos];
	}

	size_t len() const {
		return size;
	}

	str join(const std::vector<str> &strs) const {
		if (strs.empty()) {
			return str();
		}
		
		// Calculate total length needed
		size_t total_len = 0;
		for (size_t i = 0; i < strs.size(); ++i) {
			total_len += strs[i].len();
			if (i < strs.size() - 1) {
				total_len += len();  // Add separator length
			}
		}
		
		// Create result string
		str result;
		delete[] result.data;
		result.size = total_len;
		result.data = new char[total_len + 1];
		
		char* ptr = result.data;
		for (size_t i = 0; i < strs.size(); ++i) {
			// Copy string
			std::strcpy(ptr, strs[i].data);
			ptr += strs[i].len();
			
			// Add separator if not the last string
			if (i < strs.size() - 1) {
				std::strcpy(ptr, data);
				ptr += len();
			}
		}
		
		result.data[total_len] = '\0';
		return result;
	}

	str slice(size_t l, size_t r) const {
		// Clamp r to size if it's too large
		if (r > size) {
			r = size;
		}
		
		// Handle invalid range
		if (l >= r) {
			return str();
		}
		
		// Create substring
		size_t substr_len = r - l;
		str result;
		delete[] result.data;
		result.size = substr_len;
		result.data = new char[substr_len + 1];
		
		std::strncpy(result.data, data + l, substr_len);
		result.data[substr_len] = '\0';
		
		return result;
	}

	~str() {
		delete[] data;
	}
};