#include "polynomial.hpp"
 
int main() {
    std::cout << "=== Polynomial Class Test ===" << std::endl;
 
    // Test 1: Create and display polynomials
    std::cout << "\n--- Test 1: Creating Polynomials ---" << std::endl;
    Polynomial p1;
    p1.addTerm(3, 2);   // 2x^3
    p1.addTerm(2, -3);  // -3x^2
    p1.addTerm(1, 5);   // 5x
    p1.addTerm(0, 1);   // +1
 
    std::cout << "p1 = " << p1 << std::endl;
 
    Polynomial p2;
    p2.addTerm(2, 1);   // x^2
    p2.addTerm(1, 2);   // 2x
    p2.addTerm(0, 3);   // +3
 
    std::cout << "p2 = " << p2 << std::endl;
 
    // Test 2: Copy Constructor
    std::cout << "\n--- Test 2: Copy Constructor ---" << std::endl;
    Polynomial p1_copy(p1);
    std::cout << "p1_copy = " << p1_copy << std::endl;
 
    // Test 3: Assignment Operator
    std::cout << "\n--- Test 3: Assignment Operator ---" << std::endl;
    Polynomial p3 = p2;
    std::cout << "p3 = p2 = " << p3 << std::endl;
 
    // Test 4: Addition
    std::cout << "\n--- Test 4: Addition (p1 + p2) ---" << std::endl;
    Polynomial p_sum = p1 + p2;
    std::cout << "p1 + p2 = " << p_sum << std::endl;
 
    // Test 5: Multiplication
    std::cout << "\n--- Test 5: Multiplication (p1 * p2) ---" << std::endl;
    // p1 = 2x^3 - 3x^2 + 5x + 1
    // p2 = x^2 + 2x + 3
    // Expected: 2x^5 + 4x^4 + 6x^3 - 3x^4 - 6x^3 - 9x^2 + 5x^3 + 10x^2 + 15x + x^2 + 2x + 3
    //         = 2x^5 + x^4 + 5x^3 + 2x^2 + 17x + 3
    Polynomial p_prod = p1 * p2;
    std::cout << "p1 * p2 = " << p_prod << std::endl;
 
    // Test 6: Evaluate
    std::cout << "\n--- Test 6: Evaluate ---" << std::endl;
    double x_val = 2.0;
    std::cout << "p1 evaluated at x=" << x_val << " = " << p1.evaluate(x_val) << std::endl;
    // Manual: 2(2^3) - 3(2^2) + 5(2) + 1 = 16 - 12 + 10 + 1 = 15
 
    // Test 7: Adding terms that cancel out
    std::cout << "\n--- Test 7: Adding Terms (cancellation) ---" << std::endl;
    Polynomial p4;
    p4.addTerm(2, 5);   // 5x^2
    p4.addTerm(1, 3);   // 3x
    std::cout << "p4 before: " << p4 << std::endl;
 
    p4.addTerm(2, -5);  // -5x^2 (should cancel)
    std::cout << "p4 after adding -5x^2: " << p4 << std::endl;
 
    // Test 8: Empty polynomial
    std::cout << "\n--- Test 8: Empty Polynomial ---" << std::endl;
    Polynomial empty;
    std::cout << "empty = " << empty << std::endl;
 
    // Test 9: Single term polynomial
    std::cout << "\n--- Test 9: Single Term Polynomial ---" << std::endl;
    Polynomial single;
    single.addTerm(5, 7);  // 7x^5
    std::cout << "single = " << single << std::endl;
    std::cout << "single * p2 = " << (single * p2) << std::endl;
 
    // Test 10: Error handling
    std::cout << "\n--- Test 10: Error Handling ---" << std::endl;
    try {
        Polynomial error_test;
        error_test.addTerm(2, 0);  // Should throw
    } catch (const std::logic_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }
 
    try {
        Polynomial error_test2;
        error_test2.evaluate(2.0);  // Empty polynomial, should throw
    } catch (const std::logic_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }
 
    std::cout << "\n=== All Tests Complete ===" << std::endl;
    return 0;
}