# 현재 진행도

## 2차원
- [X] 삼각형, 점 벡터 구현
- [X] 두 벡터의 외적 구하기 
- [X] 한 점이 삼각형 내부에 있는지 판별(세 변의 외적의 부호가 같은지 판별)
- [ ] 점이 변 위에 있는 경우
## 3차원      



# 보고서

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
기본적으로 삼각형과 점의 벡터값을 받을 class를 제일 먼저 설계후,

	//덧셈(+ 연산자의 의미를 각 벡터값을 덧셈하는 것으로 정의.)
	// ex) : A(1,2) + B(3,4) -> return A(4,6)

	Vec operator+(const Vec& v) const {
		return { x + v.x, y + v.y };
	}

	//뺄셈(- 연산자의 의미를 뺄셈하는 것으로 정의.)
	Vec operator-(const Vec& v) const {
		return { x - v.x, y - v.y };
	}

벡터의 x값, y값 끼리 계산하는 함수도 추가하였음.

	//외적(x1 * y2 - y1 * x2)
	double cross(const Vec& v) const {
		return x * v.y - y * v.x;
	}
};

추가로 가장 중요한 외적 구하는 식도 구성했으나, 아직 3차원 z값을 고려하지는 않아 식이 간단함.

//벡터 class 3개를 받아 삼각형 ABC의 각 점으로 이름변환.  
class Triangle {
public:
	Vec A, B, C;
	//생성자
	Triangle(const Vec& A, const Vec& B, const Vec& C)
		: A(A), B(B), C(C) {
	}

그 후 위 class에서 생성한 점 3개의 벡터를 입력받아 삼각형으로 묶어서 가독성을 향상.

	//외적을 구할 변 생성
	bool contain(const Vec& P) const {
		Vec AB = B - A;
		Vec BC = C - B;
		Vec CA = A - C;

		Vec AP = P - A;
		Vec BP = P - B;
		Vec CP = P - C;

외적을 구할 변들인, 삼각형의 변과 삼각형의 각 점과 점P의 크기를 생성함.

		//외적 구하기(외적 구할때 벡터의 시작점은 같게 구성해야함.)
		double c1 = AB.cross(AP);
		double c2 = BC.cross(BP);
		double c3 = CA.cross(CP);

		//세 외적의 부호가 전부 같으면 1, 다르면 0 출력.
		return (c1 >= 0 && c2 >= 0 && c3 >= 0) ||
			(c1 <= 0 && c2 <= 0 && c3 <= 0);
	}
};

시작점이 같은 변끼리 외적후, 그 값의 부호가 전부 같으면 1, 하나라도 다르면 0을 출력하게 함.

