#ifndef __PRNG_H__
#define __PRNG_H__

class PRNG {
     uint32_t seed_;
	 public:
			PRNG(uint32_t s=362436069){
			seed_ = s;
			}
			void seed(uint32_t s){
			seed_ = s;
			}
			uint32_t operator()(){
			seed_ = 36969 * (seed_ & 65535) + (seed_ >> 16);
			return seed_;
			}
			uint32_t operator()(uint32_t u){
			return operator()()%(u+1);
			}
			uint32_t operator()(uint32_t l, uint32_t u){
			return operator()(u-1) +l;
			}
};

#endif