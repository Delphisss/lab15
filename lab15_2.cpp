#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}
//เขียนเพิ่ม
void showMatrix(const bool a[][N]){ //จะแสดงผลของอาร์เรย์ B ซึ่งเป็นอาร์เรย์ที่เก็บค่า true หรือ false ตามว่าค่านั้นเป็น local maxima หรือไม่
	for(int i=0;i<N;i++){ 
		for(int j=0;j<N;j++){
			cout << a[i][j] ;
			if(j!=N-1) cout << " ";
		}
		cout << endl;
	}
}

void inputMatrix(double a[][N]){ //รับค่าของจากผู้ใช้แล้วเก็บไว้ในอาร์เรย์ 2 มิติ A ซึ่งประกอบไปด้วย N x N ช่อง
	for(int i=0;i<N;i++){ //ฟังก์ชั่นจะใช้ for loop สองชั้น เพื่อรับค่าจากผู้ใช้ ค่าที่รับเข้ามาจะเก็บไว้ใน matrix A ตามตำแหน่ง [i][j]
		cout << "Row "<< i+1 <<": ";
		for(int j=0;j<N;j++){
		    cin >> a[i][j] ;
		}
	}
}

void findLocalMax(const double a[][N], bool b[][N]){ //ส่วนตรงนี้จะค้นหาค่า local maxima ในอาร์เรย์ A และเก็บผลลัพธ์ไว้ในอาร์เรย์ B ซึ่งเป็นอาร์เรย์ที่เก็บค่า true หรือ false ตามว่าค่านั้นเป็น local maxima หรือไม่ 
	for(int i=0;i<N;i++){ //ถ้าเป็น true คือ local maxima แต่ถ้าเป็น false คือไม่ใช่ local maxima
		for(int j=0;j<N;j++){
			if(i==0||i==N-1||j==0||j==N-1){
				b[i][j] =0; //ค่าสมาชิกที่ขอบบน, ขอบล่าง, ขอบซ้ายและขอบขวาของ B จะมีค่าเท่ากับ 0 เสมอ
			}
			else if(a[i][j]>= a[i-1][j] && a[i][j]>= a[i+1][j] && a[i][j]>= a[i][j+1] && a[i][j]>= a[i][j-1]){
				b[i][j]=1; //ค่าสมาชิกตรงพิกัดอื่น ๆ ของ B จะมีค่าเท่ากับ true เมื่อค่าของ A ตรงพิกัดนั้น มีค่ามากกว่าหรือเท่ากับ ค่าในพิกัดที่ติดกัน 4 จุด
			}else b[i][j] =0; //นอกจากนั้นให้เป็น 0
		}
	}
}	
//ใน for loop ที่ i = 0 และ i = N-1 และ j = 0 และ j = N-1 จะเซ็ต B[i][j] เป็น false เนื่องจากขอบเขตของ matrix ไม่สามารถเป็นจุดสูงสุดได้
//ใน for loop อื่นๆ จะใช้ if statement เพื่อตรวจสอบว่า A[i][j] มีค่ามากกว่า A[i-1][j] และ A[i+1][j] และ A[i][j-1] และ A[i][j+1] หากเป็นจริง จะเซ็ต B[i][j] เป็น true หากไม่เป็นจริง จะเซ็ตเป็น false

//Kong >W<