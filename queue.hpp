#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  int data;
  int prioritas;
  Element * next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
 ElementPtr<T> Head;
 ElementPtr<T> Tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> baris;
  baris.Head=nullptr;
  baris.Tail=nullptr;
  return baris;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> baru=nullptr;
  baru=new Element<T>;
  baru->data=value;
  baru->prioritas=priority;
  baru->next=nullptr;
  ElementPtr<T> prev=nullptr;
  ElementPtr<T>help=q.Head;
  if(IsEmpty(q)){
    q.Head=baru;
    q.Tail=baru;
  }else{
     while (help->next != NULL &&help->prioritas >=priority) {
        prev = help;
        help = help->next;
    }if(help==q.Tail&&help->prioritas>priority){
      help->next=baru;
      q.Tail=baru;
    }else if(help==q.Head&&help->prioritas<priority){
      baru->next=help;
      q.Head=baru;
    }else if(help->prioritas==priority){
      baru->next=help->next;
      help->next=baru;
    }
      else {
            baru->next = help;
            prev->next = baru;
        }
    }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.Head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> delElement;
 if(IsEmpty(q)){
    delElement=nullptr;
 }else if(q.Head->next==nullptr){
   delElement=q.Head;
   q.Head=nullptr;
   q.Tail=nullptr;
 }else{
   delElement=q.Head;
   q.Head=q.Head->next;
   delElement->next=nullptr;
 }
}
template <typename T>
bool IsEmpty(Queue<T> q) {
  if(q.Head==nullptr && q.Tail==nullptr){
    return true;
  }else{
  return false;
  }
}
}  // namespace priority_queue

}  // namespace strukdat
