//
// Created by nawfa on 9/15/2026.
//

# pragma once

# include <iostream>
#include "List.h"

template <typename T>

class ArrayList : public List<T>
{
public:
    void addFront(T* value) override
    {
        if (size_ >= CAPACITY)
        {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i)
        {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }
    void addAnywhere(int position, T* value) override
    {

        if (size_ >= CAPACITY)
        {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        if (size_ == 0 && position == 0)
        {
            data_[0] = value;
            ++size_;
            return;
        }
        if (position >= size_ || position < 0)
        {
            std::cout << "Position out of range." << std::endl;
            return;
        }

        for (int i = size_; i > position; --i)
        {
            data_[i] = data_[i - 1];
        }
        data_[position] = value;
        ++size_;
    }

    void deleteFront() override
    {
        if (size_ == 0)
        {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i)
        {
            data_[i] = data_[i + 1];
        }
        --size_;
    }
    void deleteAnywhere(int position) override
    {
        if (size_ == 0)
        {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        if (position > size_ -1 || position < 0)
        {
            std::cout << "Position out of range." << std::endl;
            return;
        }
        delete data_[position];
        for (int i = position; i < size_ - 1; ++i)
        {
            data_[i] = data_[i + 1];
        }
        --size_;

    }

    void reverse()
    {
        if (size_ == 0)
        {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        int j = size_ - 1;
        for (int i = 0; i < size_ / 2; ++i)
        {
            T* temp_ = data_[i];
            data_[i] = data_[j];
            data_[j] = temp_;
            j--;

        }

    }

    bool search(T* value) const override
    {
        for (int i = 0; i < size_; ++i)
        {
            if (*data_[i] == *value) return true;
        }
        return false;
    }

    void print() const override
    {
        for (int i = 0; i < size_; ++i)
        {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }

    void concat(List<T>* other) override
    {
        ArrayList* array = dynamic_cast<ArrayList*>(other);
        if (array == nullptr)
        {
            std::cout << "Mismatch in type." << std::endl;
            return;
        }
        int total_size_ = size_ + array->size_;
        if (size_ + array->size_ > CAPACITY) {
            std::cout << "Can't concat these two lists (too many items)." << std::endl;
            return;
        }
        int j = 0;
        for (int i = 0; i < array->size_ ; ++i)
        {
            data_[size_ + j] = array->data_[j];
            j++;
        }
        size_ = total_size_;

        array->size_ = 0;
    }

    ~ArrayList() override
    {
        for (int i = 0; i < size_; ++i)
        {
            delete data_[i];
        }
    }


private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};



