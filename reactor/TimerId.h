// excerpts from http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef TIMERID_H
#define TIMERID_H

#include"Timer.h"

class Timer;

///
/// An opaque identifier, for canceling Timer.
///
class TimerId 
{
 public:
  explicit TimerId(Timer* timer)
    : value_(timer)
  {
  }

  // default copy-ctor, dtor and assignment are okay

 private:
  Timer* value_;
};



#endif  // MUDUO_NET_TIMERID_H
