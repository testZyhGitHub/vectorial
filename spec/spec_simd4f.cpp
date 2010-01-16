#include "spec_helper.h"
#include <iostream>
using vectorial::simd4f;

const float epsilon = 0.00001f;

describe(simd4f, "sanity") {
    it("has simd-type") {
        std::cout << "Using simd: " << VECTORIAL_SIMD_TYPE << std::endl;
    }
}

describe(simd4f, "arithmetics with other simd4f") {
    
    
    it("should component-wise add") {
        simd4f a(1,2,3,4);
        simd4f b(2,3,4,5);
        
        simd4f x = a + b;
        
        // octave: [1,2,3,4] + [2,3,4,5]
        should_be_equal_simd4f(x, simd4f(3.000000, 5.000000, 7.000000, 9.000000), epsilon );
        
    }
    
    it("should component-wise multiply") {
        simd4f a(1,2,3,4);
        simd4f b(2,3,4,5);
        
        simd4f x = a * b;
        
        // octave: [1,2,3,4] .* [2,3,4,5]
        should_be_equal_simd4f(x, simd4f(2.000000, 6.000000, 12.000000, 20.000000), epsilon );
    }
     
}

describe(simd4f, "arithmetics with other scalar") {

    it("should add") {
        simd4f a(1,2,3,4);
        float b = 2.2f;
        
        simd4f x = a + b;
        
        // octave: [1,2,3,4] + 2.2
        should_be_equal_simd4f(x, simd4f(3.200000, 4.200000, 5.200000, 6.200000), epsilon );
        
    }
    
    it("should multiply") {
        simd4f a(1,2,3,4);
        float b = 2.2f;
        
        simd4f x = a * b;
        
        // octave: [1,2,3,4] .* 2.2
        should_be_equal_simd4f(x, simd4f(2.200000, 4.400000, 6.600000, 8.800000), epsilon );
    }

}
