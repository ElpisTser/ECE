#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>

int abs(int a) {
    return (a >= 0) ? a : -a;
}

class Polynomial {
protected:
    class Term {
    protected:
        int exponent;
        int coefficient;
        Term* next;
        Term(int exp, int coeff, Term* n) : exponent(exp), coefficient(coeff), next(n) {}
        friend class Polynomial;  
        friend std::ostream& operator << (std::ostream& out, const Polynomial &p);
        friend Polynomial operator +(const Polynomial& p, const Polynomial& q);
        friend Polynomial operator *(const Polynomial& p, const Polynomial& q);
    };

    Term* termsList;
public:
    Polynomial() : termsList(nullptr) {}
    Polynomial(const Polynomial& p) {
        Term* q = p.termsList;

        if (q == nullptr) {
            termsList = nullptr;
            return;
        }
        
        termsList = new Term(q->exponent, q->coefficient, nullptr);
        Term* currTerm = termsList;
        q = q->next;

        while (q != nullptr) {
            currTerm->next = new Term(q->exponent, q->coefficient, nullptr);
            currTerm = currTerm->next;
            q = q->next;
        }
    }
    
    ~Polynomial() {
        Term* current = termsList;
        while (current != nullptr) {
            Term* temp = current->next;
            delete current;
            current = temp;
    }
    }

    Polynomial & operator = (const Polynomial& p) {
        if (this == &p) return *this;

        Term* current = termsList;
        while (current != nullptr) {
            Term* temp = current->next;
            delete current;
            current = temp;
        }

        Term* q = p.termsList;

        if (q == nullptr) {
            termsList = nullptr;
            return *this;
        }
        
        termsList = new Term(q->exponent, q->coefficient, nullptr);
        Term* currTerm = termsList;
        q = q->next;

        while (q != nullptr) {
            currTerm->next = new Term(q->exponent, q->coefficient, nullptr);
            currTerm = currTerm->next;
            q = q->next;
        }

        return *this;
    }

    void addTerm(int expon, int coeff) {
        if (coeff == 0) 
            throw std::logic_error("Tried to add term with coefficient 0");

        Term* newTerm = new Term(expon, coeff, nullptr);

        if (termsList == nullptr) {
            termsList = newTerm;
            return;
        }

        Term* currTerm = termsList;

        if (termsList->exponent == expon) {
            int newCoeff = coeff + termsList->coefficient;

            if (newCoeff == 0) {
                termsList = termsList->next;
                delete currTerm;
                delete newTerm;
                return;
            }

            termsList->coefficient = newCoeff;
            delete newTerm;
            return;
        }


        if (expon > termsList->exponent) {
            termsList = newTerm;
            newTerm->next = currTerm;
            return;
        }


        Term* prevTerm = termsList;

        while (currTerm->next != nullptr) {
            if (currTerm->exponent == expon) {
                int newCoeff = currTerm->coefficient + coeff;

                if (newCoeff == 0) {
                    prevTerm->next = currTerm->next;
                    delete currTerm;
                    delete newTerm;
                    return;
                }

                currTerm->coefficient = newCoeff;
                delete newTerm;
                return;
            }

            Term* nextTerm = currTerm->next;

            if (expon > nextTerm->exponent) {
                currTerm->next = newTerm;
                newTerm->next = nextTerm;
                return;
            }

            prevTerm = currTerm;
            currTerm = nextTerm;    
        }

        if (currTerm->exponent == expon) {
                int newCoeff = currTerm->coefficient + coeff;

                if (newCoeff == 0) {
                    if (currTerm == termsList) {
                        termsList = nullptr;
                    } else {
                        prevTerm->next = currTerm->next;
                    }
                    delete currTerm;
                    delete newTerm;
                    return;
                }

                currTerm->coefficient = newCoeff;
                delete newTerm;
                return;
        }
        currTerm->next = newTerm;
    }

    double evaluate(double x) {
        if (termsList == nullptr)
            throw std::logic_error("Can't evaluate a polynomial with 0 terms");

        Term* currTerm = termsList;
        double result = 0;

        while (currTerm != nullptr) {
            result += currTerm->coefficient * pow(x, currTerm->exponent);
            currTerm = currTerm->next;
        }

        return result;
    };

    friend Polynomial operator +(const Polynomial& p, const Polynomial& q) {
        Term* termsP = p.termsList;
        Term* termsQ = q.termsList;

        Polynomial newPol;
        Term* termsNew = newPol.termsList;

        while (termsP != nullptr && termsQ != nullptr) {
            if (termsP->exponent > termsQ->exponent) {
                Term* temp = new Term(termsP->exponent, termsP->coefficient, nullptr);
                
                if (newPol.termsList == nullptr) {
                    newPol.termsList = temp;
                    termsNew = temp;
                } else {
                    termsNew->next = temp;
                    termsNew = termsNew->next;
                }
                termsP = termsP->next;
            } else if (termsP->exponent < termsQ->exponent) {

                Term* temp = new Term(termsQ->exponent, termsQ->coefficient, nullptr);

                if (newPol.termsList == nullptr) {
                    newPol.termsList = temp;
                    termsNew = temp;
                } else {
                    termsNew->next= temp;
                    termsNew = termsNew->next;
                }
                termsQ = termsQ->next;
            } else { // Term where P and Q have the same exponent
                int newCoef = termsP->coefficient + termsQ-> coefficient;
                if (newCoef !=  0) {
                    Term* temp = new Term(termsP->exponent, newCoef, nullptr);

                    if (newPol.termsList == nullptr) {
                        newPol.termsList = temp;
                        termsNew = temp;
                    } else {
                        termsNew-> next = temp;
                        termsNew = termsNew->next;
                    }
                }
                termsP = termsP->next;
                termsQ = termsQ->next;
            }
        }

        while (termsP != nullptr) {
            Term* temp = new Term(termsP->exponent, termsP->coefficient, nullptr);
            if (newPol.termsList == nullptr) {
                newPol.termsList = temp;
                termsNew = temp;
            } else {
                termsNew->next = temp;
                termsNew = termsNew->next;
            }
            termsP = termsP->next;
        }

        while (termsQ != nullptr) {
            Term* temp = new Term(termsQ->exponent, termsQ->coefficient, nullptr);
            if (newPol.termsList == nullptr) {
                newPol.termsList = temp;
                termsNew = temp;
            } else {
                termsNew->next = temp;
                termsNew = termsNew->next;
            }
            termsQ = termsQ->next;
        }

        return newPol;
    }
    
    friend Polynomial operator *(const Polynomial& p, const Polynomial& q) {
        Polynomial newPol;

        Term* termsP = p.termsList;
    
        while (termsP != nullptr) {
            Polynomial tempPol;

            Term* termsQ = q.termsList;
            while (termsQ != nullptr) {
                tempPol.addTerm((termsP->exponent + termsQ->exponent), (termsP->coefficient * termsQ->coefficient));
                termsQ = termsQ->next;
            }
            
            newPol = newPol + tempPol;
            termsP = termsP->next;
        }

        return newPol;
    }

    friend std::ostream& operator << (std::ostream& out, const Polynomial &p) {
        Term* currTerm = p.termsList;

        if (currTerm == nullptr) return out;
        if (currTerm->coefficient < 0) out << " - ";

        while (currTerm != nullptr) {
            if ((abs(currTerm->coefficient) != 1) || (currTerm->exponent == 0)) out << abs(currTerm->coefficient);

            if (currTerm->exponent != 0) {
                if (currTerm->exponent == 1) out << 'x';
                else out << "x^" << currTerm->exponent;
            }

            Term* nextTerm = currTerm->next;
            if (nextTerm != nullptr ) {
                if (nextTerm->coefficient > 0 ) out << " + ";
                else out << " - ";
            }

            currTerm = nextTerm;
        }

        return out;
    }
};


#endif