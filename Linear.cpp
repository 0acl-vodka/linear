#include <iostream>
using namespace std;

//벡터 클래스
class Vec {
public:
	double x = 0;
	double y = 0;

	//생성자
	Vec() {}
	Vec(double x, double y) : x(x), y(y) {}

	//변수 초기화
	void input() {
		cin >> x >> y;
	}

	//덧셈
	Vec operator+(const Vec& v) const {
		return { x + v.x, y + v.y };
	}

	//뺼셈
	Vec operator-(const Vec& v) const {
		return { x - v.x, y - v.y };
	}

	//외적
	double cross(const Vec& v) const {
		return x * v.y - y * v.x;
	}
};


//벡터 3개를 삼각형 ABC의 벡터로 적용. 
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

		//외적 구하기
		double c1 = AB.cross(AP);
		double c2 = BC.cross(BP);
		double c3 = CA.cross(CP);

		//세 외적의 부호가 전부 같은지 확인
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