//
// Created by aknight on 9/8/19.
//

#ifndef EX03_LINKEDLIST_LIST_H
#define EX03_LINKEDLIST_LIST_H

#include <cstdlib>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

template<typename Ty>
class list {
    struct node {
        node(const Ty &data): _data(data), _prev(nullptr), _next(nullptr) {}
        node(const Ty& data, node *prev, node* next): _data(data), _prev(prev), _next(next) {}
        Ty _data;
        node *_next;
        node *_prev;
    };

    node *_head = nullptr;
    node *_tail = nullptr;
    size_t _size;

private:
    class iterator {
    public:
        node *_current;
    public:
        explicit iterator(node *link): _current(link) {}

        const Ty& operator *() { return _current->_data; }
        iterator& operator ++() { _current = _current->_next; return *this; }
        iterator operator ++(int) {
            node *old_current = _current;
            _current = _current->_next;
            return iterator(old_current);
        }
        iterator& operator --() { _current = _current->_prev; return *this; }
        iterator operator --(int) {
            node *old_current = _current;
            _current = _current->_prev;
            return iterator(old_current);
        }

        bool operator ==(const iterator &rhs) const {
            return _current == rhs._current;
        }

        bool operator !=(const iterator &rhs) const {
            return !(*this == rhs);
        }
    };

public:
    explicit list(): _size(0) {}
    explicit list(size_t n): _size(0) { for (size_t i = 0; i < n; i++) push_back(Ty()); }
    list(size_t n, const Ty &val): _size(0) { for (size_t i = 0; i < n; i++) push_back(val); }
    list(const list &x) {}
    list(list &&x) noexcept: _head(x._head), _tail(x._tail), _size(x._size) {}

    iterator begin()  { return iterator(_head);   }
    iterator end()    { return iterator(nullptr); }

    bool empty() const { return size() == 0; }
    size_t size() const { return _size; }

    const Ty& front() const { return _head->_data; }
    const Ty& back()  const { return _tail->_data; }

    // Student implement
    void push_front(const Ty& val) {
        if (_head == nullptr) {
            _head = _tail = new node(val);
            _size++;
            return;
        }
        insert(begin(), val);
    }

    // Student implement
    void pop_front() {
        erase(begin());
    }

    // Student implement
    void push_back(const Ty& val) {
        if (_tail == nullptr) {
            _tail = _head = new node(val);
            _size++;
            return;
        }
        insert(end(), val);
    }

    // Student implement
    void pop_back() {
        erase(iterator(_tail));
    }

    // Student implement
    iterator insert(iterator it, const Ty &val) {
        node *new_node;
        if (it._current == nullptr) {
            it._current = new_node = new node(val, _tail, nullptr);
            _tail = new_node;
        } else new_node = new node(val, it._current->_prev, it._current);

        if (it._current->_prev != nullptr) it._current->_prev->_next = new_node;
        else _head = new_node;

        if (it._current != new_node) it._current->_prev = new_node;
        _size++;

        return _head == new_node ? --it : it;
    }

    // Student implement
    iterator erase(iterator it) {
        if (it._current == _head) {
            _head = it._current->_next;
            if ( _head != nullptr) {
                _head->_prev = nullptr;
            }
        }
        if (it._current == _tail) {
            _tail = it._current->_prev;
            if (_tail != nullptr) {
                _tail->_next = nullptr;
            }
        }
        if (it._current->_prev != nullptr) it._current->_prev->_next = it._current->_next;
        if (it._current->_next != nullptr) it._current->_next->_prev = it._current->_prev;

        node* old_node = it._current;
        it++;

        delete old_node;
        _size--;

        return it;
    }

    // Student implement
    iterator erase(iterator first, iterator last) {
        for (iterator it = first; it != last; it++) {
            erase(it);
        }
        return last;
    }

    // Student implement
    void clear() {
        erase(begin(), end());
    }
};

}}}}
#endif //EX03_LINKEDLIST_LIST_H
