#ifndef __OPTIONAL_OBJECT_H__
#define __OPTIONAL_OBJECT_H__

template<typename T>
class OptionalObject
{
private:
    T *item;

private:
    OptionalObject(T *_item);

public:
    static OptionalObject create(T *item);
    static OptionalObject createNull(); 
    bool isPresent();
    bool isNull();
    T *get();
};

#endif  //__OPTIONAL_OBJECT_H__

template<typename T>
OptionalObject<T>::OptionalObject(T *_item) :
                   item(_item)
{
}

template<typename T>
inline OptionalObject<T> OptionalObject<T>::create(T *item) 
{
    OptionalObject<T> optional = OptionalObject<T>(item);
    return optional;
}

template<typename T>
inline OptionalObject<T> OptionalObject<T>::createNull() 
{
    OptionalObject<T> optional = OptionalObject<T>(nullptr);
    return optional;
}

template<typename T>
inline bool OptionalObject<T>::isPresent() 
{
    return (this->item != nullptr);
}

template<typename T>
inline bool OptionalObject<T>::isNull() 
{
    return (this->item == nullptr);
}

template<typename T>
inline T *OptionalObject<T>::get() 
{
    return this->item;
}