#include <iostream>
using namespace std;

//벡터를 저장 및 계산할 class.
class Vec {
public:
	double x;
	double y;

	//기본 생성자
	Vec() {}
	//생성자
	Vec(double x, double y) : x(x), y(y) {}

	//변수 초기화 함수
	void input() {
		cin >> x >> y;
	}

	//덧셈(+ 연산자의 의미를 각 벡터값을 덧셈하는 것으로 정의.)
	// ex) : A(1,2) + B(3,4) -> return A(4,6)

	Vec operator+(const Vec& v) const {
		return { x + v.x, y + v.y };
	}

	//뺄셈(- 연산자의 의미를 뺄셈하는 것으로 정의.)
	Vec operator-(const Vec& v) const {
		return { x - v.x, y - v.y };
	}

	//외적(x1 * y2 - y1 * x2)
	double cross(const Vec& v) const {
		return x * v.y - y * v.x;
	}
};

//벡터 class 3개를 받아 삼각형 ABC의 각 점으로 이름변환.  
class Triangle {
public:
	Vec A, B, C;
	//생성자
	Triangle(const Vec& A, const Vec& B, const Vec& C)
		: A(A), B(B), C(C) {
	}

	//외적을 구할 변 생성
	bool contain(const Vec& P) const {
		Vec AB = B - A;
		Vec BC = C - B;
		Vec CA = A - C;

		Vec AP = P - A;
		Vec BP = P - B;
		Vec CP = P - C;

		//외적 구하기(외적 구할때 벡터의 시작점은 같게 구성해야함.)
		double c1 = AB.cross(AP);
		double c2 = BC.cross(BP);
		double c3 = CA.cross(CP);

		//세 외적의 부호가 전부 같으면 1, 다르면 0 출력.
		return (c1 >= 0 && c2 >= 0 && c3 >= 0) ||
			(c1 <= 0 && c2 <= 0 && c3 <= 0);
	}
};

int main() {

	//벡터 A, B, C, P 선언 & 값 입력
	Vec A, B, C, P;
	cout << "삼각형 ABC의 x,y 값을 입력하시오.(공백으로 x,y 구분 & 엔터로 A, B, C 순차입력) : ";
	A.input();
	B.input();
	C.input();
	cout << "점 P의 x,y값을 입력하시오.(조건 동일.) : ";
	//점 P 값 입력
	P.input();


	Triangle tri(A, B, C);
	if (tri.contain(P)) cout << "점 P는 삼각형 내부에 있음." << endl;
	else cout << "점 P는 삼각형 외부에 있음." << endl;

	return 0;
}