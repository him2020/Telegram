// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#pragma once

#include <stdlib.h>
#include <string>
#include "flags.h"
#include "assertion.h"

using uchar = unsigned char;

namespace tl {
namespace details {

struct zero_flags_helper {
};

struct LengthCounter {
	uint32_t length = 0;
};

} // namespace details

template <typename Accumulator>
struct Writer;

template <typename Prime>
struct Reader;

template <>
struct Writer<details::LengthCounter> final {
	static void PutBytes(details::LengthCounter &to, const void *bytes, uint32_t count) {
		constexpr auto kPrime = sizeof(uint32_t);
		const auto primes = (count / kPrime) + (count % kPrime ? 1 : 0);
		to.length += primes * kPrime;
	}
	static void Put(details::LengthCounter &to, uint32_t value) {
		to.length += sizeof(uint32_t);
	}
};

template <
	typename T,
	typename = decltype(
		std::declval<T>().write(std::declval<details::LengthCounter&>()))>
uint32_t count_length(const T &value) {
	auto counter = details::LengthCounter();
	value.write(counter);
	return counter.length;
}

enum {
	id_int = 0xa8509bda,
	id_long = 0x22076cba,
	id_int128 = 0x4bb5362b,
	id_int256 = 0x929c32f,
	id_double = 0x2210c154,
	id_string = 0xb5286e24,
	id_vector = 0x1cb5c415,

	id_bytes = id_string,
	id_flags = id_int,
};

class int_type {
public:
	int32_t v = 0;

	int_type() = default;

	uint32_t type() const {
		return id_int;
	}
	template <typename Prime>
	bool read(const Prime *&from, const Prime *end, uint32_t cons = id_int) {
		if (!Reader<Prime>::Has(1, from, end) || cons != id_int) {
			return false;
		}
		v = static_cast<int32_t>(Reader<Prime>::Get(from, end));
		return true;
	}
	template <typename Accumulator>
	void write(Accumulator &to) const {
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(v));
	}

private:
	explicit int_type(int32_t val) : v(val) {
	}

	friend int_type make_int(int32_t v);
};
inline int_type make_int(int32_t v) {
	return int_type(v);
}

template <typename Flags>
class flags_type {
public:
	Flags v = 0;
	static_assert(
		sizeof(Flags) == sizeof(int32_t),
		"flags_type are allowed only wrapping int32_t flag types!");

	flags_type() = default;
	flags_type(details::zero_flags_helper helper) {
	}

	uint32_t type() const {
		return id_flags;
	}
	template <typename Prime>
	bool read(const Prime *&from, const Prime *end, uint32_t cons = id_flags) {
		if (!Reader<Prime>::Has(1, from, end) || cons != id_flags) {
			return false;
		}
		v = Flags::from_raw(static_cast<typename Flags::Type>(Reader<Prime>::Get(from, end)));
		return true;
	}
	template <typename Accumulator>
	void write(Accumulator &to) const {
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(v.value()));
	}

private:
	explicit flags_type(Flags val) : v(val) {
	}

	template <typename T>
	friend flags_type<base::flags<T>> make_flags(base::flags<T> v);

	template <typename T, typename>
	friend flags_type<base::flags<T>> make_flags(T v);

};

template <typename T>
inline flags_type<base::flags<T>> make_flags(base::flags<T> v) {
	return flags_type<base::flags<T>>(v);
}

template <typename T, typename = std::enable_if_t<!std::is_same<T, int>::value>>
inline flags_type<base::flags<T>> make_flags(T v) {
	return flags_type<base::flags<T>>(v);
}

inline details::zero_flags_helper make_flags(void(details::zero_flags_helper::*)()) {
	return details::zero_flags_helper();
}

inline bool operator==(const int_type &a, const int_type &b) {
	return a.v == b.v;
}
inline bool operator!=(const int_type &a, const int_type &b) {
	return a.v != b.v;
}

class long_type {
public:
	uint64_t v = 0;

	long_type() = default;

	uint32_t type() const {
		return id_long;
	}
	template <typename Prime>
	bool read(const Prime *&from, const Prime *end, uint32_t cons = id_long) {
		if (!Reader<Prime>::Has(2, from, end) || cons != id_long) {
			return false;
		}
		v = static_cast<uint64_t>(Reader<Prime>::Get(from, end));
		v |= static_cast<uint64_t>(Reader<Prime>::Get(from, end)) << 32;
		return true;
	}
	template <typename Accumulator>
	void write(Accumulator &to) const {
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(v & 0xFFFFFFFFULL));
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(v >> 32));
	}

private:
	explicit long_type(uint64_t val) : v(val) {
	}

	friend long_type make_long(uint64_t v);
};
inline long_type make_long(uint64_t v) {
	return long_type(v);
}

inline bool operator==(const long_type &a, const long_type &b) {
	return a.v == b.v;
}
inline bool operator!=(const long_type &a, const long_type &b) {
	return a.v != b.v;
}

class int64_type {
public:
	int64_t v = 0;

	int64_type() = default;

	uint32_t type() const {
		return id_long;
	}
	template <typename Prime>
	bool read(const Prime *&from, const Prime *end, uint32_t cons = id_long) {
		if (!Reader<Prime>::Has(2, from, end) || cons != id_long) {
			return false;
		}
		auto data = static_cast<uint64_t>(Reader<Prime>::Get(from, end));
		data |= static_cast<uint64_t>(Reader<Prime>::Get(from, end)) << 32;
		v = static_cast<int64_t>(data);
		return true;
	}
	template <typename Accumulator>
	void write(Accumulator &to) const {
		const auto data = static_cast<uint64_t>(v);
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(data & 0xFFFFFFFFULL));
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(data >> 32));
	}

private:
	explicit int64_type(int64_t val) : v(val) {
	}

	friend int64_type make_int64(int64_t v);
};
inline int64_type make_int64(int64_t v) {
	return int64_type(v);
}

inline bool operator==(const int64_type &a, const int64_type &b) {
	return a.v == b.v;
}
inline bool operator!=(const int64_type &a, const int64_type &b) {
	return a.v != b.v;
}

class int128_type {
public:
	uint64_t l = 0;
	uint64_t h = 0;

	int128_type() = default;

	uint32_t type() const {
		return id_int128;
	}
	template <typename Prime>
	bool read(const Prime *&from, const Prime *end, uint32_t cons = id_int128) {
		if (!Reader<Prime>::Has(4, from, end) || cons != id_int128) {
			return false;
		}
		l = static_cast<uint64_t>(Reader<Prime>::Get(from, end));
		l |= static_cast<uint64_t>(Reader<Prime>::Get(from, end)) << 32;
		h = static_cast<uint64_t>(Reader<Prime>::Get(from, end));
		h |= static_cast<uint64_t>(Reader<Prime>::Get(from, end)) << 32;
		return true;
	}
	template <typename Accumulator>
	void write(Accumulator &to) const {
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(l & 0xFFFFFFFFULL));
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(l >> 32));
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(h & 0xFFFFFFFFULL));
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(h >> 32));
	}

private:
	explicit int128_type(uint64_t low, uint64_t high) : l(low), h(high) {
	}

	friend int128_type make_int128(uint64_t l, uint64_t h);
};
inline int128_type make_int128(uint64_t l, uint64_t h) {
	return int128_type(l, h);
}

inline bool operator==(const int128_type &a, const int128_type &b) {
	return a.l == b.l && a.h == b.h;
}
inline bool operator!=(const int128_type &a, const int128_type &b) {
	return a.l != b.l || a.h != b.h;
}

class int256_type {
public:
	int128_type l;
	int128_type h;

	int256_type() = default;

	uint32_t type() const {
		return id_int256;
	}
	template <typename Prime>
	bool read(const Prime *&from, const Prime *end, uint32_t cons = id_int256) {
		if (cons != id_int256) {
			return false;
		}
		return l.read(from, end) && h.read(from, end);
	}
	template <typename Accumulator>
	void write(Accumulator &to) const {
		l.write(to);
		h.write(to);
	}

private:
	explicit int256_type(int128_type low, int128_type high) : l(low), h(high) {
	}

	friend int256_type make_int256(const int128_type &l, const int128_type &h);
};
inline int256_type make_int256(const int128_type &l, const int128_type &h) {
	return int256_type(l, h);
}

inline bool operator==(const int256_type &a, const int256_type &b) {
	return a.l == b.l && a.h == b.h;
}
inline bool operator!=(const int256_type &a, const int256_type &b) {
	return a.l != b.l || a.h != b.h;
}

class double_type {
public:
	double v = 0.;

	double_type() = default;

	uint32_t type() const {
		return id_double;
	}
	template <typename Prime>
	bool read(const Prime *&from, const Prime *end, uint32_t cons = id_double) {
		if (!Reader<Prime>::Has(2, from, end) || cons != id_double) {
			return false;
		}
		uint64_t nonaliased = static_cast<uint64_t>(Reader<Prime>::Get(from, end));
		nonaliased |= static_cast<uint64_t>(Reader<Prime>::Get(from, end)) << 32;
		static_assert(sizeof(v) == sizeof(nonaliased));
		std::memcpy(&v, &nonaliased, sizeof(v));
		return true;
	}
	template <typename Accumulator>
	void write(Accumulator &to) const {
		uint64_t nonaliased;
		static_assert(sizeof(v) == sizeof(nonaliased));
		std::memcpy(&nonaliased, &v, sizeof(v));
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(nonaliased & 0xFFFFFFFFULL));
		Writer<Accumulator>::Put(to, static_cast<uint32_t>(nonaliased >> 32));
	}

private:
	explicit double_type(double val) : v(val) {
	}

	friend double_type make_double(double v);
};
inline double_type make_double(double v) {
	return double_type(v);
}

inline bool operator==(const double_type &a, const double_type &b) {
	return a.v == b.v;
}
inline bool operator!=(const double_type &a, const double_type &b) {
	return a.v != b.v;
}

class string_type;
using bytes_type = string_type;

class string_type {
public:
	string_type() = default;

	uint32_t type() const {
		return id_string;
	}
	template <typename Prime>
	bool read(const Prime *&from, const Prime *end, uint32_t cons = id_string) {
		if (!Reader<Prime>::Has(1, from, end) || cons != id_string) {
			return false;
		}
		const auto first = Reader<Prime>::Get(from, end);
		const auto last = (first & 0xFFU);
		if (last > 254) {
			return false;
		} else if (last == 0) {
			v = "";
		} else if (last == 1) {
			v.resize(1);
			v[0] = static_cast<char>((first >> 8) & 0xFFU);
		} else if (last == 2) {
			v.resize(2);
			v[0] = static_cast<char>((first >> 8) & 0xFFU);
			v[1] = static_cast<char>((first >> 16) & 0xFFU);
		} else if (last < 254) {
			v.resize(last);
			const auto remaining = last - 3;
			if (!Reader<Prime>::HasBytes(remaining, from, end)) {
				return false;
			}
			v[0] = static_cast<char>((first >> 8) & 0xFFU);
			v[1] = static_cast<char>((first >> 16) & 0xFFU);
			v[2] = static_cast<char>((first >> 24) & 0xFFU);
			Reader<Prime>::GetBytes((void*)(v.data() + 3), remaining, from, end);
		} else {
			const auto length = (first >> 8);
			if (!Reader<Prime>::HasBytes(length, from, end)) {
				return false;
			}
			v.resize(length);
			Reader<Prime>::GetBytes((void*)v.data(), length, from, end);
		}
		return true;
	}
	template <typename Accumulator>
	void write(Accumulator &to) const {
		Expects(v.size() < 0x1000000);

		const auto size = uint32_t(v.size());
		if (size == 0) {
			Writer<Accumulator>::Put(to, size);
		} else if (size == 1) {
			Writer<Accumulator>::Put(to, size
				| (static_cast<uint32_t>(static_cast<uchar>(v[0])) << 8));
		} else if (size == 2) {
			Writer<Accumulator>::Put(to, size
				| (static_cast<uint32_t>(static_cast<uchar>(v[0])) << 8)
				| (static_cast<uint32_t>(static_cast<uchar>(v[1])) << 16));
		} else if (size < 254) {
			Writer<Accumulator>::Put(to, size
				| (static_cast<uint32_t>(static_cast<uchar>(v[0])) << 8)
				| (static_cast<uint32_t>(static_cast<uchar>(v[1])) << 16)
				| (static_cast<uint32_t>(static_cast<uchar>(v[2])) << 24));
			Writer<Accumulator>::PutBytes(to, v.data() + 3, size - 3);
		} else {
			const auto encoded = (size << 8) | 254U;
			Writer<Accumulator>::Put(to, encoded);
			Writer<Accumulator>::PutBytes(to, v.data(), size);
		}
	}

	std::string v;

private:
	explicit string_type(std::string &&data) : v(std::move(data)) {
	}

	friend string_type make_string(const std::string &v);
	friend string_type make_string(std::string &&v);
	friend string_type make_string(const char *v);
	friend string_type make_string();

	friend bytes_type make_bytes(const std::string &v);
	friend bytes_type make_bytes(std::string &&v);
	friend bytes_type make_bytes();

};

inline string_type make_string(const std::string &v) {
	return string_type(std::string(v.data(), v.size()));
}

inline string_type make_string(std::string &&v) {
	return string_type(std::move(v));
}

inline string_type make_string(const char *v) {
	return string_type(std::string(v, strlen(v)));
}
inline string_type make_string() {
	return string_type(std::string());
}
inline bytes_type make_bytes(const std::string &v) {
	return bytes_type(std::string(v));
}
inline bytes_type make_bytes(std::string &&v) {
	return bytes_type(std::move(v));
}
inline bytes_type make_bytes() {
	return bytes_type(std::string());
}

inline bool operator==(const string_type &a, const string_type &b) {
	return a.v == b.v;
}
inline bool operator!=(const string_type &a, const string_type &b) {
	return a.v != b.v;
}

template <typename T>
class vector_type {
public:
	vector_type() = default;

	uint32_t type() const {
		return id_vector;
	}
	template <typename Prime>
	bool read(const Prime *&from, const Prime *end, uint32_t cons = id_vector) {
		if (!Reader<Prime>::Has(1, from, end) || cons != id_vector) {
			return false;
		}
		auto count = Reader<Prime>::Get(from, end);

		auto vector = std::vector<T>(count, T());
		for (auto &item : vector) {
			if (!item.read(from, end)) {
				return false;
			}
		}
		v = std::move(vector);
		return true;
	}
	template <typename Accumulator>
	void write(Accumulator &to) const {
		Writer<Accumulator>::Put(to, static_cast<int32_t>(v.size()));
		for (const auto &item : v) {
			item.write(to);
		}
	}

	std::vector<T> v;

private:
	explicit vector_type(std::vector<T> &&data) : v(std::move(data)) {
	}

	template <typename U>
	friend vector_type<U> make_vector(uint32_t count);
	template <typename U>
	friend vector_type<U> make_vector(uint32_t count, const U &value);
	template <typename U>
	friend vector_type<U> make_vector(const std::vector<U> &v);
	template <typename U>
	friend vector_type<U> make_vector(std::vector<U> &&v);
	template <typename U>
	friend vector_type<U> make_vector();

};
template <typename T>
inline vector_type<T> make_vector(uint32_t count) {
	return vector_type<T>(std::vector<T>(count));
}
template <typename T>
inline vector_type<T> make_vector(uint32_t count, const T &value) {
	return vector_type<T>(std::vector<T>(count, value));
}
template <typename T>
inline vector_type<T> make_vector(const std::vector<T> &v) {
	return vector_type<T>(std::vector<T>(v));
}
template <typename T>
inline vector_type<T> make_vector(std::vector<T> &&v) {
	return vector_type<T>(std::move(v));
}
template <typename T>
inline vector_type<T> make_vector() {
	return vector_type<T>();
}

template <typename T>
inline bool operator==(const vector_type<T> &a, const vector_type<T> &b) {
	return a.c_vector().v == b.c_vector().v;
}
template <typename T>
inline bool operator!=(const vector_type<T> &a, const vector_type<T> &b) {
	return a.c_vector().v != b.c_vector().v;
}

namespace details {

template <typename Type>
struct repeat_helper {
	using type = Type;
};
template <typename Type>
using repeat = typename repeat_helper<Type>::type;

struct inner_helper {
	static void Check(...);
	template <typename Type, typename Result = decltype(std::declval<Type>().v)>
	static Result Check(const Type&);

	template <typename Type>
	using type = std::decay_t<decltype(Check(std::declval<Type>()))>;
};

} // namespace details

template <typename T>
class conditional {
public:
	conditional() = default;
	conditional(const T *value) : _value(value) {
	}

	operator const T*() const {
		return _value;
	}
	const T *operator->() const {
		Expects(_value != nullptr);

		return _value;
	}
	const T &operator*() const {
		Expects(_value != nullptr);

		return *_value;
	}

	template <
		typename Inner = details::inner_helper::type<T>,
		typename = std::enable_if_t<!std::is_same_v<Inner, void>>>
	Inner value_or(details::repeat<Inner> fallback) const {
		return _value ? _value->v : fallback;
	}

	template <
		typename Inner = details::inner_helper::type<T>,
		typename = std::enable_if_t<!std::is_same_v<Inner, void>>>
	Inner value_or_empty() const {
		return _value ? _value->v : Inner();
	}

private:
	const T *_value = nullptr;

};

} // namespace tl
