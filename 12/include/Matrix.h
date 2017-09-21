/*
* created by David 9/29/2014
* class Matrix
* implements 'matrix' using 2d pointer array
* --everything in header b/c of template usage
*/
#include <iostream>
#include <stdlib.h>

template<class T>
class Matrix{
	public:
	    //constructors, destructor
		Matrix(int row=3, int col=3);
		~Matrix();
		Matrix(const Matrix<T> &other);

		//operators
        bool operator==(const Matrix<T>& rhs);
        bool operator!=(const Matrix<T>& rhs);
		Matrix<T>& operator=(const Matrix<T>& rhs);
		Matrix<T>& operator+(const Matrix<T>& rhs);
		Matrix<T>& operator-(const Matrix<T>& rhs);
		Matrix<T>& operator-();
		Matrix<T>& operator+=(const T& t);
		Matrix<T>& operator-=(const T& t);
		Matrix<T>& operator++();
		Matrix<T>& operator++(int);
		Matrix<T>& operator--();
		Matrix<T>& operator--(int);
		T& operator()(int row, int col);
		T& operator()(int row, int col) const;
        std::istream& operator>>(std::istream &in);

		//member functions
		int getRows() const;
		int getCols() const;
		int getSize() const;
		void setRows(int rowsIn);
		void setCols(int colsIn);
		void place(const T &t, int row, int col);
		void print() const;
		void setAllValues(const T &t);
	private:
		unsigned int rows;
		unsigned int cols;
		T **matrix;
};

        //non-member functions
        template<class T>
        void transpose(Matrix<T> &m);

///////////////////////////////////
//constructors and deconstructors//
///////////////////////////////////
//constructor. Overloaded row row, col = 3
template<class T>
Matrix<T>::Matrix(int row, int col)
{
	if(row < 1 || col < 1) exit(1);
	rows =row;
	cols = col;
	matrix = new T *[rows];
	for(int i=0;i<rows;i++){
		matrix[i] = new T[cols];
	}
}
//copy constructor
template<class T>
Matrix<T>::Matrix(const Matrix<T> &other)
{
	rows =other.rows;
	cols = other.cols;
	matrix = new T *[rows];
	for(int i=0;i<rows;i++){
		matrix[i] = new T[cols];
	}
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] = other.matrix[i][j];
}
//deconstructor
template<class T>
Matrix<T>::~Matrix()
{
	for(int i=0;i<rows;i++)
		delete matrix[i];
	delete [] matrix;
	matrix = NULL;
}

/////////////
//operators//
/////////////

// = operator where 'matrix1 = matrix2'
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{
    if(this==&rhs) return(*this);

    //clear current matrix
	for(int i=0;i<rows;i++)
		delete matrix[i];
	delete [] matrix;

	//get same sizes
	rows = rhs.rows;
	cols = rhs.cols;
    matrix = new T *[rows];
    for(int i=0;i<rhs.rows;i++)
        matrix[i] = new T [cols];

    //set as same values
    for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] = rhs.matrix[i][j];
    return(*this);
}
//subtraction matrix 'matrix1 - matrix2'
template<class T>
Matrix<T>& Matrix<T>::operator-(const Matrix<T>& rhs)
{
    if(rows!=rhs.rows || cols!=rhs.cols) exit(1);
    for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] -= rhs.matrix[i][j];
    return(*this);
}
//negation operator '-matrix1'
template<class T>
Matrix<T>& Matrix<T>::operator-()
{
    for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] *= -1;
    return(*this);
}
//addition operator 'matrix 1 + matrix 2'
template<class T>
Matrix<T>& Matrix<T>::operator+(const Matrix<T>& rhs)
{
    if(rows!=rhs.rows || cols!=rhs.cols) exit(1);
    for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] = rhs.matrix[i][j];
    return(*this);
}
//+= operator. adds n to all values of matrix 'matrix1 += 3'
template<class T>
Matrix<T>& Matrix<T>::operator+=(const T& t)
{
    for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] += t;
    return(*this);
}
//-= operator subtracts n from all values of matrix 'matrix -= 1'
template<class T>
Matrix<T>& Matrix<T>::operator-=(const T& t)
{
    for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] -= t;
    return(*this);
}
//compares all elements of matrix and returns true if all are the same
template<class T>
bool Matrix<T>::operator==(const Matrix<T>& rhs)
{
    if(rows!=rhs.rows || cols!=rhs.cols) exit(1);
    for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
			if(matrix[i][j] != rhs.matrix[i][j]) return false;
    return true;
    }
}
//compares all elements of matrix and returns false if all are not the same
template<class T>
bool Matrix<T>::operator!=(const Matrix<T>& rhs)
{
    if(rows!=rhs.rows || cols!=rhs.cols) exit(1);
    for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
			if(matrix[i][j] == rhs.matrix[i][j]) return false;
    return true;
    }
}
//adds 1 to all elements in list
template<class T>
Matrix<T>& Matrix<T>::operator++()
{
    for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] += 1;
    return(*this);
}
//adds one for all elements in list
template<class T>
Matrix<T>& Matrix<T>::operator++(int)
{
    for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] += 1;
    return(*this);
}
//subtracts 1 for all elements in list
template<class T>
Matrix<T>& Matrix<T>::operator--()
{
    for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] -= 1;
    return(*this);
}
//subtracts 1 for all elements in list
template<class T>
Matrix<T>& Matrix<T>::operator--(int)
{
    for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] -= 1;
    return(*this);
}
//gets element from matrix 'matrix(1,2) returns lvalue element in row 1, col 2
template<class T>
T& Matrix<T>::operator()(int row, int col) const
{
    if(row > rows-1 || col > cols-1 || row < 0 || col < 0){
        std::cout << "index row: " <<row <<", col: "<< col <<" ,is not in range row: "<<rows <<" col: " <<cols<< std::endl;
        exit(1);
    }
    return matrix[row][col];
}
//gets element from matrix 'matrix(1,2) returns rvalue element in row 1,col 2
template<class T>
T& Matrix<T>::operator()(int row, int col)
{
    if(row > rows-1 || col > cols-1 || row < 0 || col < 0){
        std::cout << "index row: " <<row <<", col: "<< col <<" ,is not in range row: "<<rows <<" col: " <<cols<< std::endl;
        exit(1);
    }
    return matrix[row][col];
}


template<class T>
std::istream& Matrix<T>::operator >> (std::istream &in)
{
    int temp,i,j;
    for(i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            std::cout<< "enter values for "<< i+1 << ", " <<j+1 <<std::endl;
            in>>temp;
            matrix[i,j]=temp;
    return in;
}

////////////////////
//member functions//
////////////////////

template<class T>
int Matrix<T>::getRows() const {return rows;}
template<class T>
int Matrix<T>::getCols() const {return cols;}
template<class T>
int Matrix<T>::getSize() const {return (rows * cols);}
template<class T>
void Matrix<T>::setRows(int rowsIn) {rows = rowsIn;}
template<class T>
void Matrix<T>::setCols(int colsIn) {cols = colsIn;}

//adds element t to matrix in specified row + col. 'matrix1.place('test',1,1)
template<class T>
void Matrix<T>::place(const T &t, int row, int col)
{
    if(row > rows || col > cols || row < 1 || col < 1){
        std::cout << "index row: " <<row <<", col: "<< col <<" ,is not in range of matrix."<< std::endl;
        exit(1);
    }
    matrix [row-1][col-1] = t;
}
//prints all values of matrix
template<class T>
void Matrix<T>::print() const
{
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            std::cout<< matrix[i][j] << ' ';
        std::cout << std::endl;
    }
}
//sets all values to specified value t
template<class T>
void Matrix<T>::setAllValues(const T &t)
{
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                matrix[i][j] = t;
}

////////////////////////
//non-member functions//
////////////////////////

//flips all elements of matrix on a diagonal axis
/*  matrix1.transpose()
*
*   0 9 3         0 3 8
*   3 1 6  ====>  9 1 7
*   8 7 3         3 6 3
*/
template<class T>
void transpose(Matrix<T> &m)
{
    Matrix<T> temp(m.getCols(), m.getRows());
    int rows = m.getRows();
    int cols = m.getCols();

    //set temp values
    for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
            temp.place(m(i,j),j+1,i+1);
    m = temp;
}

