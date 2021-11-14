#include "Buffer.h"
#include "SocketsOps.h"

#include <errno.h>
#include <memory.h>
#include <sys/uio.h>
const char Buffer::kCRLF[] = "\r\n";
template<typename To, typename From>
inline To implicit_cast(From const &f) {
    return f;
}
ssize_t Buffer::readFd(int fd, int* savedErrno)
{
  char extrabuf[65536];//栈上空间
  struct iovec vec[2];
  const size_t writable = writeableBytes();
  vec[0].iov_base = begin()+writerIndex_;//Buffer
  vec[0].iov_len = writable;
  vec[1].iov_base = extrabuf;//stack
  vec[1].iov_len = sizeof extrabuf;
  const ssize_t n = readv(fd, vec, 2);
  if (n < 0) {
    *savedErrno = errno;
  } else if (implicit_cast<size_t>(n) <= writable) {//如果Buffer可以直接读入，就直接读
    writerIndex_ += n;
  } else {//如果数据过大则先读到栈上，接着添加到Buffer的后面
    writerIndex_ = buffer_.size();
    append(extrabuf, n - writable);
  }
  return n;
}
