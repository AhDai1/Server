// excerpts from http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (giantchen at gmail dot com)

#ifndef MUTEX_H
#define MUTEX_H

#include "../thread/Thread.h"

#include <boost/noncopyable.hpp>
#include <assert.h>
#include <pthread.h>



class MutexLock : boost::noncopyable
{
 public:
  MutexLock()
    : holder_(0)
  {
    pthread_mutex_init(&mutex_, NULL);
  }

  ~MutexLock()
  {
    assert(holder_ == 0);
    pthread_mutex_destroy(&mutex_);
  }

  bool isLockedByThisThread()
  {
    return holder_ == CurrentThread::tid();
  }

  void assertLocked()
  {
    assert(isLockedByThisThread());
  }

  // internal usage

  void lock()
  {
    pthread_mutex_lock(&mutex_);
    holder_ =CurrentThread::tid();
  }

  void unlock()
  {
    holder_ = 0;
    pthread_mutex_unlock(&mutex_);
  }

  pthread_mutex_t* getPthreadMutex() /* non-const */
  {
    return &mutex_;
  }

 private:

  pthread_mutex_t mutex_;
  pid_t holder_;
};

class MutexLockGuard : boost::noncopyable
{
 public:
  explicit MutexLockGuard(MutexLock& mutex) : mutex_(mutex)
  {
    mutex_.lock();
  }

  ~MutexLockGuard()
  {
    mutex_.unlock();
  }

 private:

  MutexLock& mutex_;
};



// Prevent misuse like:
// MutexLockGuard(mutex_);
// A tempory object doesn't hold the lock for long!
#define MutexLockGuard(x) error "Missing guard object name"

#endif  // MUDUO_BASE_MUTEX_H
