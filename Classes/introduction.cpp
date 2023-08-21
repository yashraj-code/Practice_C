class Rectangle 
{

private:
    int length;
    int width;

public:
    void setLength(int l) 
		{length = l;}
    void setWidth(int w) 
		{width = w;}
    int area() 
		{return length * width;}
};
