
#include "str.hpp"
#include &lt;iostream&gt;

// This main function is required for the compilation process
// but doesn't need to do anything specific since we're just
// providing a header file implementation
int main() {
    // Create some test instances to ensure all methods are properly defined
    str s1;
    str s2('a');
    str s3("hello");
    s3 = "world";
    str s4 = s3;
    s4 = s2;
    
    // Access elements
    char c = s3[0];
    
    // Get length
    size_t len = s3.len();
    
    // Test join
    std::vector&lt;str&gt; vec = {str("1"), str("2"), str("3")};
    str separator(",");
    str joined = separator.join(vec);
    
    // Test slice
    str sliced = s3.slice(0, 3);
    
    return 0;
}
