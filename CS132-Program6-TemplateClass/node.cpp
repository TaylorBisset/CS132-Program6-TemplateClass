template <typename T>
Node<T>::Node() : next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::Node(TBString num) : data(num), next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::Node(TBString newData) : data(newData), next(nullptr), prev(nullptr) {}