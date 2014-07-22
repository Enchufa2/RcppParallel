#ifndef __RCPP_PARALLEL_RVECTOR__
#define __RCPP_PARALLEL_RVECTOR__

namespace RcppParallel {

template <typename T>
class RVector {

public:   
   typedef T* iterator;
   typedef const T* const_iterator;

   template <typename Source>
   inline explicit RVector(const Source& source) 
      : begin_(source.begin()),
        end_(source.begin() + source.length())

   {
   }

   inline RVector(std::size_t begin, std::size_t end) 
      : begin_(begin), end_(end)
   {   
   }
   
   inline RVector(const RVector& other) 
      : begin_(other.begin_), end_(other.end_)
   {   
   }
   
   inline RVector& operator=(const RVector& rhs) {
      begin_ = rhs.begin_;
      end_ = rhs.end_;
      return *this;
   }
   
   inline iterator begin() { return begin_; }
   inline iterator end() { return end_; }
   
   inline const_iterator begin() const { return begin_; }
   inline const_iterator end() const { return end_; }
   
   inline std::size_t length() const { return end_ - begin_; }
   
   inline T& operator[](std::size_t i) {
     return *(begin_ + i);
   }
   
   inline const T& operator[](std::size_t i) const {
     return *(begin_ + i);
   }
   
private:
   T* begin_;
   T* end_;  
};

} // namespace RcppParallel

#endif // __RCPP_PARALLEL_RVECTOR__