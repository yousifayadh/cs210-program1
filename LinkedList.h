//
// Created by nawfa on 9/17/2026.
//

#pragma once
#include "Node.h"
#include "List.h"

template <typename T>
class LinkedList : public List<T>
{
public:
    LinkedList() : head_(nullptr) {}

    void addFront(T *value) override
    {
        Node<T>* fresh = new Node<T>(value);
        fresh -> next = head_;
        head_ = fresh;
        size_++;
    }

    void addAnywhere(int position, T* value) override
    {
        Node<T>* current = head_;
        for (int i = 0; i < position; ++i)
        {
            current = current->next;
        }
        Node<T>* newNode = new Node<T>(value);

        newNode -> next = current -> next;
        current -> next = newNode;
        size_++;
    }
    void deleteFront() override
    {
        if (head_ == nullptr)
        {
            std::cout <<"LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_ -> next;
        delete doomed -> data;
        delete doomed;
        size_--;
    }
    void deleteAnywhere(int position) override
    {
        if (size_ == 0)
        {
            std::cout <<"LinkedList is empty." << std::endl;
            return;
        }
        else if (position < 0 || position > size_ - 1)
        {
            std::cout <<"Position out of bounds." << std::endl;
            return;
        }
        Node<T>* current = head_;
        Node<T>* doomed = current->next;

        for (int i = 0; i < position; ++i)
        {
            current = current->next;
            doomed = doomed -> next;
        }

        current->next = doomed -> next;
        delete doomed -> data;
        delete doomed;
        size_--;
    }

    void reverse ()
    {
        Node<T>* current = head_;
        Node<T>* prev = nullptr;

        while (current != nullptr)
        {
            Node<T>* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head_ = prev;
    }
    bool search(T* value) const override
    {
        Node<T>* current = head_;
        while (current != nullptr)
        {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }
    void print() const override
    {
        Node<T>* current = head_;
        while (current != nullptr)
        {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }
    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }
private:
    Node<T>* head_;
    int size_ = 0;
};
