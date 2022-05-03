#ifndef _MATRIX_H_
#define _MATRIX_H_
//#include <vector>

template< typename T>

class Matrix{

    public:
        int row_num;
        int col_num;
        std::vector< std::vector<T>> matrix;
        
        Matrix(int row,int col);
        
        Matrix( const std::vector<std::vector<T>>& matrix_): matrix(matrix_){ //object létrejött eddigre 
        //std::cout<<"inside constructor"<<'\n';
        }
        
        void PrintMatrix() const{
            for (int i = 0; i< matrix.size(); i++ ){
                        std::cout << '\n';
                        
                        for (int j = 0; j< matrix[i].size(); j++ ){
                            std::cout << matrix[i][j] << ' ';
                        
                        }   
                    }
        }
        
        Matrix<T> mul (T C){
            std::vector <std::vector <T>> res_matrix;
            res_matrix = matrix;
            for (int i = 0; i< matrix.size(); i++ ){
                //std::cout << '\n';
                for (int j = 0; j< matrix[i].size(); j++ ){
                    res_matrix[i][j] *= C;
                }
            }
            Matrix result = Matrix(res_matrix);
            return result;
        }

        Matrix<T> mul (Matrix<T> other_matrix){

            std::vector< std::vector<T> > result_matrix;
            if (matrix[0].size() == other_matrix.matrix.size()){
                    //std::cout<< "Size: " << matrix[0].size() << "\n";
                }
                else{
                    std::cout<< "Dimnension mismatch."<< "\n";
                }
                for (int sori = 0; sori< matrix.size(); sori++ ){
                    std::vector <int> temp;
                    int tempsum = 0;
                    for (int oszlopi = 0; oszlopi< other_matrix.matrix[0].size(); oszlopi++ ){
                        tempsum = 0;
                        for (int adder = 0; adder < matrix[0].size(); adder++){
                            tempsum += matrix[sori][adder] * other_matrix.matrix[adder][oszlopi];
                        }
                        temp.push_back(tempsum);
                    }
                    result_matrix.push_back(temp);
                    temp.clear();
                }
                return Matrix(result_matrix);
            }

};   
template< typename T>
Matrix<T> operator*(Matrix<T> left, T num){
    return left.mul(num);   
}

template< typename T>
Matrix<T> operator*(T num, Matrix<T> right){
    return right.mul(num);
}
template< typename T>
Matrix<T> operator*(Matrix<T> left, Matrix<T> right){
    return left.mul(right);
}
template< typename T>
bool operator==(Matrix<T> left, Matrix<T> right){
    return (left.matrix == right.matrix);
}
template< typename T>
bool operator!=(Matrix<T> left, Matrix<T> right){
    return (left.matrix != right.matrix);
}
template< typename T>
bool operator*=(Matrix<T> left, Matrix<T> right){
    return (left.matrix == right.matrix);
}

#endif