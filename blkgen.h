#ifndef __BLKGEN_H__
#define __BLKGEN_H__
#include <fstream>
#include <sstream>
#include <iostream>
#include "Block.h"
#include "PRNG.h"
class BLK_select {
	BLKTYPE result;
        PRNG *p;
        std::ifstream *infile;

	public: 
                BLK_select();
                ~BLK_select();
		std::string generator(int level);
		void set_result(BLKTYPE x);
		BLKTYPE get_result();
                void resetPRNseed(uint32_t s);
                void setInfile(std::ifstream *inputf){ infile = inputf;};
};


#endif
