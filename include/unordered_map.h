//
// Created by aknight on 11/23/19.
//

#ifndef EX05_HASHTABLE_UNORDERED_MAP_H
#define EX05_HASHTABLE_UNORDERED_MAP_H

#include <utility>
#include <vector>
#include <glob.h>
#include <algorithm>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {
    template <typename Key, typename Val>
    class unordered_map {
        std::pair<Key, Val> **_buckets;
        size_t _size;
        size_t _capacity;

    public:
        class iterator {
            friend unordered_map<Key, Val>;
            std::pair<Key, Val> **_current;
            std::pair<Key, Val> **_end;

        public:
            iterator(std::pair<Key, Val> **pair, std::pair<Key, Val> **end): _current(pair), _end(end) {}

            std::pair<Key, Val> &operator *() { return **_current; }
            iterator &operator ++() {
                while(*(++_current) != nullptr && _current != _end);
                return *this;
            }

            iterator &operator ++(int) {
                iterator old = *this;
                while(*(++_current) != nullptr && _current != _end);
                return old;
            }

            bool operator ==(const iterator &other) {
                return _current == other._current;
            }

            bool operator !=(const iterator &other) {
                return _current != other._current;
            }
        };

    public:
        unordered_map(): _buckets(new std::pair<Key, Val>*[2]), _size(0), _capacity(2) {
            for (size_t i = 0; i < 2; i++) {
                _buckets[i] = nullptr;
            }
        }
        unordered_map(const unordered_map &other): _buckets(new std::pair<Key, Val>*[other._capacity]), _size(other._size), _capacity(other._capacity) {
            for (auto curr = _buckets, other_curr = other._buckets; other_curr != other_curr + other._capacity; curr++, other_curr++) {
                *curr = *other_curr;
            }
        }

    public:
        iterator begin() const {
            return iterator(_buckets, _buckets + _capacity);
        }

        iterator end() const {
            return iterator(_buckets + _capacity, _buckets + _capacity);
        }

    public:
        Val &at(const Key &key) {
            return *this[key];
        }

        Val &operator [](const Key &key) {
            auto where = _find(key);
            if (where <= _capacity && _buckets[where] == nullptr) {
                _size++;
                if (load_factor() >= max_load_factor()) {
                    rehash(_capacity + 1);
                    _size++;
                    where = _find(key);
                }
                _buckets[where] = new std::pair<Key, Val>();
                *_buckets[where] = std::make_pair(key, Val());
            }
            return _buckets[where]->second;
        }

        size_t _find(const Key &key) const {
            size_t hash = hash_function()(key);
            size_t bucket = hash % _capacity;
            for (int i = 0;
                   _buckets + bucket       != end()._current  &&
                   _buckets[bucket]        != nullptr &&
                   _buckets[bucket]->first != key; i++) {
                // Resolve collision
                bucket = (hash + i) % _capacity;
            }
            return bucket;
        }

        iterator find(const Key &key) {
            auto where = _find(key);
            return iterator(_buckets + where, end());
        }

        size_t count(const Key &key) {
            iterator pair = find(key);
            return pair != end() ? 1 : 0;
        }

    public:
        size_t erase(const Key &key) {
            iterator pair = find(key);
            if (pair == end()) return 0;

            size_t bucket = std::distance(_buckets, pair._current);
            delete _buckets[bucket];
            _buckets[bucket] = nullptr;
            return 1;
        }

        void clear() {
            for (size_t i = 0; i < _capacity; i++) {
                if (_buckets[i] != nullptr) {
                    delete _buckets[i];
                    _buckets[i] = nullptr;
                }
            }
            _size = 0;
            _capacity = 0;
        }

        size_t size() const {
            return _size;
        }

        bool empty() const {
            return size() == 0;
        }

        size_t bucket_count () const {
            return _capacity;
        }

        size_t bucket_max_count () const {
            return UINT64_MAX;
        }

        size_t bucket_size(size_t n) const {
            return _buckets[n] != nullptr ? 1 : 0;
        }

        size_t bucket(const Key *key) const {
            iterator pair = find(key);
            return std::distance(_buckets, pair._current);
        }

        double load_factor() const {
            return 1.0 * size() / _capacity;
        }

        double max_load_factor() const {
            return 0.75;
        }

        static constexpr size_t _BUCKET_SIZES[] = {2, 5, 11, 23, 47, 97, 197, 299};
        void rehash(size_t n) {
            if (_capacity > n) return;

            size_t new_idx = 0;
            for (; new_idx < 8 && _BUCKET_SIZES[new_idx] < n; new_idx++);
            size_t capacity = _capacity;
            std::pair<Key, Val> **old_buckets = _buckets;

            _capacity = _BUCKET_SIZES[new_idx];
            _size = 0;
            _buckets = new std::pair<Key, Val>*[_capacity];
            for (int i = 0; i < _capacity; i++) {
                _buckets[i] = nullptr;
            }

            for (auto curr = old_buckets; curr < old_buckets + capacity; curr++) {
                if (*curr != nullptr) {
                    (*this)[(*curr)->first] = (*curr)->second;
                }
            }
            delete old_buckets;
        }

        void reserve(size_t n) {
            if (bucket_count() * load_factor() < n) {
                rehash(n);
            }
        }

        std::hash<Key> hash_function() const {
            return std::hash<Key>();
        }
    };
}}}}
#endif //EX05_HASHTABLE_UNORDERED_MAP_H
