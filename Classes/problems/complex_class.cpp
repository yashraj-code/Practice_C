class ComplexNumbers
{
    int real;
    int imaginary;

    //Parameterized Constructor
    public:
        ComplexNumbers(int real, int imaginary)
        {
            this->real=real;
            this->imaginary=imaginary;
        }

        void plus(ComplexNumbers c)
        {
            // when we will pass c1.plus(c2), then c2->c and this will have pointer to c1
            int real = this->real  + c.real;
            int imaginary = this->imaginary + c.imaginary;
            
            // changing c1 value, we don't want any other variable
            this->real = real;
            this->imaginary=imaginary;
        }

        void multiply(ComplexNumbers c)
        {
            //(a^2-b^2)
            int real = (this->real * c.real) - (this->imaginary * c.imaginary);
            //a1b2+b1a2
            int imaginary = (this->real * c.imaginary) + (this->imaginary * c.real);
            this->real = real;
            this->imaginary = imaginary;
        }

        void print()
        {
            cout<<this->real << " + " << "i" <<this->imaginary<<endl;
        }

};