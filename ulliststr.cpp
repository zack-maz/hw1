
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}





void ULListStr::push_back(const std::string& val)
{
  size_++;
  if (tail_ == NULL)
  {
    tail_ = new Item();
    tail_->val[0] = val;
    tail_->first = 0;
    tail_->last = 0;
    head_ = tail_;
  }
  else if (tail_->last == ARRSIZE)
  {
    Item* temp = new Item();
    temp->first = 0;
    temp->last = 0;
    temp->val[0] = val;

    tail_->next = temp;
    temp->prev = tail_;
    tail_ = temp;
  }
  else
  {
    tail_->val[tail_->last] = val;
  }
  tail_->last++;
}

void ULListStr::push_front(const std::string& val)
{
  size_++;
  if (head_ == NULL)
  {
    head_ = new Item();
    head_->val[ARRSIZE-1] = val;
    head_->first = 10;
    head_->last = 10;
    tail_ = head_;
  }
  else if (head_->first == 0)
  {
    Item* temp = new Item();
    temp->first = 10;
    temp->last = 10;
    temp->val[ARRSIZE-1] = val;

    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
  }
  else
  {
    head_->val[head_->first-1] = val;
  }
  head_->first--;
}







void ULListStr::pop_back()
{
  if (tail_ == NULL)
  {
    return;
  }
  size_--;
  if (tail_->last == tail_->first + 1)
  {
    Item* temp = tail_;
    tail_ = temp->prev;
    if (tail_ != NULL) tail_->next = NULL;
    else head_ = NULL;

    delete temp;
  }
  else
  {
    tail_->last--;
  }
}

void ULListStr::pop_front()
{
   if (head_ == NULL)
  {
    return;
  }
  size_--;
  if (head_->last == head_->first + 1)
  {
    Item* temp = head_;
    head_ = temp->next;
    if (head_ != NULL) head_->prev = NULL;
    else tail_ = NULL;

    delete temp;
  }
  else
  {
    head_->first++;
  }
}






std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}



std::string* ULListStr::getValAtLoc(size_t loc) const
{
  size_t width = 0;
  Item* current = head_;

  while (loc >= 0)
  {
    width = current->last - current->first;

    if (loc < width)
    {
      return &current->val[current->first + loc];
    }
    //cycle through sizes of node until we're in the right item node
    loc -= width;
    current = current->next;
  }

  return NULL;
}