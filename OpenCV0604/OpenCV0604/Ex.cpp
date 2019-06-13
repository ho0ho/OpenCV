
//#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>	// 웬만한 함수 다있음
using namespace cv;
using namespace std;

void print_matInfo(String m_name, Mat m);
void print_vectorInfo(string v_name, vector<int> v);
void print_locateROI(String str, Mat m);
void print_matInfo2(String name, Mat m);


int main() {

	/// 2차원 좌표 - Point 객체
	/*
		typedef Point_<int> Point2i
			- typedef Point2i Point
		typedef Point_<float> Point2f
		typedef Point_<double> Point2d
	*/
	Point_<int> pt1(100, 200);
	Point_<float> pt2(92.3f, 125.23f);
	Point_<double> pt3(100.2, 300.9);

	Point2i pt4(120, 69);									
	Point2f pt5(0.3f, 0.f), pt6(0.f, 0.4f);
	Point2d pt7(0.25, 0.6);

	Point pt8 = pt1 + (Point)pt2;				

	// 스칼라곱: x, y 모두에 곱해진다.
	Point2f pt9 = pt6 * 3.14f;
	Point2d pt10 = (pt3 + (Point2d)pt6) * 10;

	cout << "pt8 = " << pt8.x << ", " << pt8.y << endl;		// 192, 325
	cout << "[pt9] = " << pt9 << endl;						// [0, 1.256]
	cout << (pt2 == pt6) << endl;								// 0
	
	// 내적 
	// 2차원좌표이므로 2차원벡터로 보고 내적계산.
	// x1*x2 + y1*y2
	cout << "pt7과 pt8의 내적: " << pt8.dot(pt7) << endl;		// 243




	///* 3차원 *///
	//Point3_<int> pt1(100, 200, 300);
	//Point3_<float> pt2(92.3f, 125.23f, 250.f);
	//Point3f pt3(0.3f, 0.f, 15.7f);
	//Point3d pt4(0.25, 0.6, 33.3);

	//Point3i pt5 = pt1 + (Point3i)pt2;
	//Point3f pt6 = pt2 * 3.14f;	// 스칼라곱
	//Point3d pt7 = ((Point3d)pt3 + pt4) * 10.f;

	//cout << "두벡터(pt4, pt7)의 내적 " << pt4.dot(pt7) << endl;			// 16322
	//cout << "pt5 =" << pt5.x << endl;			// 192
	//cout << "[pt6] = " << pt6 << endl;			// 289.822, 393.222, 785
	//cout << "[pt7] = " << pt6 << endl;			// 289.822, 393.222, 785




	///* Size (Width, Height) *///
	//Size_<int> sz1(100, 200);
	//Size_<float> sz2(192.3f, 25.3f);
	//Size_<double> sz3(100.2, 30.9);

	//Size sz4(120, 69);
	//Size2f sz5(0.3f, 0.f);
	//Size2d sz6(0.25, 0.6);

	//Point2d pt1(0.25, 0.6);
	//Size2i sz7 = sz1 + (Size2i)sz2;
	//Size2d sz8 = sz3 - (Size2d)sz4;
	//Size2f sz9 = sz5 + (Size2f)pt1;

	//cout << "sz1.width, sz1.height = " << sz1.width << ", " << sz1.height << endl;			// 100, 200	
	//cout << "sz1의 넓이 = " << sz1.area() << endl;			// 20000
	//cout << "[sz7] = " << sz7 << endl;					// 292 x 225
	//cout << "[sz8] = " << sz8 << endl;					
	//cout << "[sz9] = " << sz9 << endl;					



	///* Rect *///
	//Size2d sz(100.5, 60.0);
	//Point2f pt1(20.f, 30.f), pt2(100.f, 200.f);

	//// 생성자1. left, top, width, height (주의)
	// Rect_<int> rect1(10, 10, 30, 50);
	//// 생성자2. Point2f(left, top), Point2f(right, bottom)
	// Rect_<float> rect2(pt1, pt2);
	// Rect_<double> rect3(Point2d(20.5, 10), sz);

	//// Rect에 Point 더하기 
	//// rect4는, rect1을 pt1좌표값만큼 "이동"시킨 영역!
	// Rect rect4 = rect1 + (Point)pt1;
	// Rect2f rect5 = rect2 + (Size2f)sz;

	//// &연산: 두 rect영역의 겹쳐진 부분의 영역(rect)을 리턴
	//// |연산: 두 rect영역을 포함하는 전체영역(rect)을 리턴 -> 이때, 합쳐진 전체모양 자체가 아닌, 두 영역을 포함하는 Rect영역으로 리턴
	// Rect2d rect6 = rect1 & (Rect)rect2;

	// cout << "rect3 = " << rect3.x << ", " << rect3.y << " => " << rect3.width << "x" << rect3.height << endl;	// 20.5, 10, 100.5x60
	//// tl() : topleft
	//// br() : bottomright
	//cout << "rect4 = " << rect4.tl() << " " << rect4.br() << endl;	// [30, 40] [60, 90]
	//cout << "rect5 크기 = " << rect5.size() << endl;					// [180.5 x 230]
	//cout << "[rect6] = " << rect6 << endl;							// [20 x 30 from (20, 30]

	///* Vec *///
	// 초기화 없는 값은 0으로 할당해줌.
	// typedef Vec<int, 2> Vec2i				... n = 2, 3, 4, 6, 8
	//Vec<int, 2> v1(5, 12);
	//Vec<double, 3> v2(40, 130.7, 125.6);

	//// typedef Vec<uchar, 2> Vec2b;		// b(byte <- unsigned char)
	//Vec2b v3(10, 20);

	//// typedef Vec<float, 6> Vec6f;
	//Vec6f v4(40.f, 230.25f, 525.6f);	// float 6차원짜리 벡터. 초기화없는 값은 0으로 할당

	//// typedef Vec<int, 3> Vec3i;
	//Vec3i v5(200, 230, 250);

	//Vec3d v6 = v2 + (Vec3d)v5;		
	//Vec2b v7 = (Vec2b)v1 + v3;
	//Vec6f v8 = v4 * 20.0f;

	//Point pt1 = v1 + (Vec2i)v7;
	//Point3_<int> pt2 = (Vec3i)v2;

	//cout << "[v3] = " << v3 << endl;			// [10, 20]
	//cout << "[v7] = " << v7 << endl;			// [15, 32]
	//cout << "[v3 * v7] = " << v3.mul(v7) << endl;	// [150, 255]		// 8bit에서 오버플로우(0이하 255이상)되면 saturation arithmatic(넘어가면 0, 255로 세팅하는 것)을 수행한다
	//cout << "v8[0] = " << v8[0] << endl;			// 800
	//cout << "v8[1] = " << v8[1] << endl;			// 4605
	//cout << "v8[2] = " << v8[2] << endl;			// 10512
	//cout << "v8[3] = " << v8[3] << endl;			// 0
	//cout << "[v2] = " << v2 << endl;			// [40, 130.7, 125.6]
	//cout << "[pt2] = " << pt2 << endl;			// [40, 131, 126]
	//cout << "[v4] = " << v4 << endl;			// [40, 230.25, 525.6, 0, 0, 0]



	///* Scalar */// 
	// Scalar_<_Tp> : Vect<_Tp, 4>를 따로 정의한 클래스(가장 많이 사용하기 때문)
	// Blue, Green, Red, Alpha 값을 저장하기 위한 용도 (*alpha는 투명도를 설정하는 값)
	// typedef Scalar_<double> Scalar;
	// 값을 모두 지정하지 않으면 0으로 초기화
	Scalar_<uchar> red(0, 0, 255);		// 0 0 255 0
	Scalar_<int> blue(255, 0, 0);		// 255 0 0 0
	Scalar_<double> color1(500);		// 500 0 0 0
	Scalar_<float> color2(100.f, 200.f, 125.9f);	// 100 200 125.9 0

	Vec3d green(0, 0, 300.5);		 // 0 0 300.5 0
	Scalar green1 = color1 + (Scalar)green;		// 500 0 300.5 0
	Scalar green2 = color2 + (Scalar_<float>)green;		// 100 200 426.4 0

	cout << "blue = " << blue[0] << ", " << blue[1] << ", " << blue[2] << endl;		// 255, 0, 0
	cout << "red = " << red << endl;					// 0 0 255 0
	cout << "green = " << green << endl << endl;		// 0 0 300.5
	cout << "(Scalar)green = " << (Scalar)green << endl;	// 0 0 300.5 0
	cout << "green1 = " << green1 << endl;					// 500 0 300.5 0
	cout << "green2 = " << green2 << endl;					// 100 200 426.4 0


	/////* 행렬 Matx													
	//// 단위행렬, 역행렬, 전치행렬
	//// 
	//Matx<int, 3, 3> m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	//Matx<float, 2, 3> m2(1, 2, 3, 4, 5, 6);
	//Matx<double, 3, 5 > m3(3, 4, 5, 7);

	//Matx23d m4(3, 4, 5, 6, 7, 8);
	//Matx34d m5(1, 2, 3, 10, 11, 12, 13, 14, 15);
	//Matx66f m6(1, 2, 3, 4, 5, 6, 7, 8, 9);

	//cout << "m5(0, 0) = " << m5(0, 0) << endl;			// 1
	//cout << "m5(1, 0) = " << m5(1, 0) << endl;			// 11
	//cout << "m6(0, 1) = " << m6(0, 1) << endl;		// 2
	//cout << "m6(1, 3) = " << m6(1,3) << endl;			// 0

	//cout << "[m1] = " << endl << m1 << endl;				
	//cout << "[m2] = " << endl << m2 << endl;
	//cout << "[m3] = " << endl << m3 << endl;
	//cout << "[m4] = " << endl << m4 << endl;
	//cout << "[m5] = " << endl << m5 << endl;
	//cout << "[m6] = " << endl << m6 << endl;



	///* 대형행렬 Mat *///
	// 초기화하지않은 값은 쓰레기값이 들어온다. (자동 0할당 X)
	// 생성자1: Mat(int row, int cols, int type) => type의 CV_XX부분을 depth라고 한다.
	/* type
	* CV_8U		uchar	0
	*
	*/
	// 생성자2: Mat(int row, int cols, int ytpe, const Scalar& s) => s:행렬의 초기값
	//float data[] = { 1.2f, 2.3f, 3.2f, 4.5f, 5.f, 6.5f };
	//Mat m1(2, 3, CV_8U);
	//const int sizes[][2] = { {2, 3}, {2, 3}, {2, 3} };
	///*Mat(3, sizes, CV_8U, Scalar(300, 50, 40));*/
	//Mat m2(2, 3, CV_8U, Scalar(300));		// 300으로 초기화하려고 보니, CV_8U라 overflow돼서 maximum값인 255로 초기화됨.
	//Mat m3(2, 3, CV_16S, Scalar(300));		// Scalar(300) => Scalar(300, 0, 0, 0)인데 m3가 2x3, 즉 1채널이기 때문에 맨 앞의 300으로만 채워짐
	//Mat m4(2, 3, CV_32F, data);

	//Size sz(2, 3);
	//Mat m5(Size(2, 3), CV_64F);
	//Mat m6(sz, CV_32F, data);

	//// CV_8UC1 => CV_8U채널이 1개 => one 채널
	//Mat m7 = Mat::ones(3, 5, CV_8UC1);			// 이걸로 0으로 초기화하면, 쓰레기값 방지할 수 있음
	//Mat m8 = Mat::zeros(3, 5, CV_8UC1);
	//Mat m9 = Mat::eye(3, 5, CV_8UC1);			// eye: 단위행렬로 만듦
	//
	//cout << "[m1] =" << endl << m1 << endl;		
	//cout << "[m2] =" << endl << m2 << endl;
	//cout << "[m3] =" << endl << m3 << endl;
	//cout << "[m4] =" << endl << m4 << endl;
	//cout << "[m5] =" << endl << m5 << endl;
	//cout << "[m6] =" << endl << m6 << endl;
	//cout << "[m7] =" << endl << m7 << endl;
	//cout << "[m8] =" << endl << m8 << endl;
	//cout << "[m9] =" << endl << m9 << endl;


	//double a = 32.12345678, b = 2.7;
	//short c = 400;
	//float d = 10.f, e = 11.f, f = 13.f;

	//// Mat_은 Mat을 상속받아 정의된 클래스.
	//Mat_<int> m1(2, 4);
	//Mat_<uchar> m2(3, 4, 100);
	//Mat_<short> m3(4, 5, c);

	//m1 << 1, 2, 3, 4, 5, 6;
	//// Mat_타입의 객체를 Mat타입의 포인터가 가리키고 있는 것(다형성)
	//// m4는 행렬의 "헤더"이고, 실제 데이터는 따로 있음. 가리키고 있음)
	//// main프로그램이 종료되면 지역변수인 m4는 사라지는데 힙 속의 실데이터는 누가 처리해주지?
	//// m4가 소멸되면서 자신의 소멸자를 호출하고, 그 소멸자내에서 실데이터를 free()함
	//Mat m4 = (Mat_<double>(2, 3) << 1, 2, 3, 4, 5, 6);
	//Mat m5 = (Mat_<float>(2, 3) << a, b, c, d, e, f);

	//cout << "[m1] =" << endl << m1 << endl;
	//cout << "[m2] =" << endl << m2 << endl;
	//cout << "[m3] =" << endl << m3 << endl;
	//cout << "[m4] =" << endl << m4 << endl;
	//cout << "[m5] =" << endl << m5 << endl;



	/*
	* #define CV_8U   0
	* #define CV_8S   1
	* #define CV_16U  2
	* #define CV_16S  3
	* #define CV_32S  4
	* #define CV_32F  5
	* #define CV_64F  6
	* #define CV_USRTYPE1 7
	*/

	//// m1 : 4x3 채널이 3개 있는 것 -> CV_32F"C3"
	//Mat m1(4, 3, CV_32FC3);
	//cout << "차원 수 = " << m1.dims << endl;			// 2	
	//cout << "행 수 = " << m1.rows << endl;			// 4
	//cout << "열 수 = " << m1.cols << endl;			// 3
	//// size() => width * height이라서 4x3이면 3x4로 나옴
	//cout << "행렬크기 = " << m1.size() << endl << endl;	// 3x4

	//cout << "전체원소개수 = " << m1.total() << endl;		// 12

	//// "한원소"란, 3개의 채널 상에서 동일한 좌표에 해당하는 모두를 의미한다.
	//// 즉, 한 채널 내에서 하나의 원소가 4bytes(CV_32F)이고 이게 각 원소당 3채널 겹쳐지므로 12
	//cout << "한 원소의 크기 = " << m1.elemSize() << endl;		// 12
	//cout << "채널당 한 원소의 크기 = " << m1.elemSize1() << endl << endl;		// 4 (=> 32FC3)

	//cout << "타입 = " << m1.type() << endl;		// 21
	//cout << "((m1.channels() - 1) << 3) = " << ((m1.channels() - 1) << 3) << endl;	// 16

	//// 위에 "타입"값으로 21이 나오는 이유 => 타입 = 채널수 n + 깊이값 d(깊이 d가 n채널개 겹쳐짐)
	//cout << "타입(채널수 (3bit) | 깊이(3bit)) = " << ((m1.channels() - 1) << 3) + m1.depth() << endl;		 // 21
	//
	//// 깊이 => CV_32F => 5
	//cout << "깊이 = " << m1.depth() << endl;		// 5

	//cout << "채널 =" << m1.channels() << endl;		// 3

	//// step: 한 row에 소요되는 바이트수 => 각 row : ((4x3) (4x3) (4x3))
	//cout << "step =" << m1.step << endl;			// 36
	//cout << "step1()=" << m1.step1() << endl;		// 9


	///* 06.05 *///
	//Mat m1(2, 3, CV_8U, 2);
	//Mat m2(2, 3, CV_8U, Scalar(10));

	//Mat m3 = m1 + m2;		// 행렬끼리 연산
	//Mat m4 = m2 - 6;
	//Mat m5 = m1;			// Mat객체는 포인터변수. 즉 동일한 주소를 가리키는 셈

	//cout << "[m1] =" << endl << m1 << endl;
	//cout << "[m2] =" << endl << m2 << endl;
	//cout << "[m3] =" << endl << m3 << endl;
	//cout << "[m4] =" << endl << m4 << endl;

	//cout << "[m1] =" << endl << m1 << endl;
	//cout << "[m5] =" << endl << m5 << endl;
	//m5 = 100;									
	//cout << "[m1] =" << endl << m1 << endl;
	//cout << "[m5] =" << endl << m5 << endl;	

	//// 스마트포인터(cpp)
	//// 동일한 메모리를 여러 포인터가 가리키고 있을 때, 나를 레퍼런스하고 있는 개수를 세고 있음
	//// 이 수가 0이 될때 스스로를 소멸시키도록 구현. 


	/////* Mat : resize() */// 
	//Mat m = (Mat_<uchar>(2, 4) << 1, 2, 3, 4, 5, 6, 7, 8);
	//cout << "m = " << endl << m << endl << endl;

	//m.resize(1);						
	//cout << "m.resize(1) = " << endl << m << endl;	
	//m.resize(3);						// 남은 공간 디폴트값(쓰레기값)으로 채우기
	//cout << "m.resize(3); = " << endl << m << endl;
	//m.resize(5, Scalar(50));			// 남은 공간 50으로 채우기
	//cout << "m.resize(5) = " << endl << m << endl;


	///* Mat : reshape *///
	//// 데이터를 잘라내거나 붙이는게 아니라 모양만 다시 짜는 것
	//// 변경 전, 후 행렬 전체 원소 수가 맞아야함
	//// Row가 기준.
	//Mat m1(2, 6, CV_8U);
	//Mat m2 = m1.reshape(2);
	//Mat m3 = m1.reshape(3, 2); // 채널은 3개 row는 2개

	//print_matInfo("m1(2, 6)", m1);
	//print_matInfo("m2 = m1.reshape(2)", m2);
	//print_matInfo("m3 = m1.reshape(3, 2)", m3);

	//m1.create(3, 5, CV_16S);
	//print_matInfo("m1.create(3, 5, CV_16S)", m1);


	///* Mat : clone(), copyTo(), convertTo() *///
	//// 깊은 복사(헤더만 복사하는게 아니라, 실데이터를 복사해오기)
	//// 부동소수점(지수/가수)???
	//double data[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.9, 9.9, 10, 11, 12 };		// 8.8이면 8.8000000000 나옴
	//Mat m1(3, 4, CV_64F, data);
	//Mat m2 = m1.clone();
	//Mat m3, m4;
	//m1.copyTo(m3);
	//m1.convertTo(m4, CV_8U);

	//cout << "m1 = " << endl << m1 << endl;
	//cout << "m2 = " << endl << m2 << endl;
	//cout << "m3 = " << endl << m3 << endl;
	//cout << "m4 = " << endl << m4 << endl;


	///* Mat : *///
	//Mat m1 = Mat::eye(10, 10, CV_32FC1);	// eye: 단위행렬 
	//cout << "Element (3, 3) is " << m1.at<float>(3, 3) << endl << endl;

	//Mat m2 = Mat::eye(10, 10, CV_32FC2);	// 다채널 단위행렬 => 맨앞채널만 대각선으로 1 채워지고, 뒤 나머지는 0으로 만듦
	//// at<Vec2f> : 각 채널에서 같은 위상에 있는(3, 3) 애들을 모아 하나의 벡터를 만들고 거기에 인덱스로 접근
	//cout << "Element (3, 3) is (" << m2.at<Vec2f>(3, 3)[0] << ", " << m2.at<Vec2f>(3, 3)[1] << ")" << endl << endl;
	//
	//// m3: 안의 내용은 float형 복소수(complex>가 10x10 
	//Mat m3 = Mat::eye(10, 10, traits::Type<Complex<float>>::value);
	//// re: 실수, im: 허수
	//cout << "Element (3, 3) is (" << m3.at<Complexf>(3, 3).re << " + " << m3.at<Complexf>(3, 3).im << "i)" << endl << endl;

	//cout << "=======================================================================" << endl;
	//int sz[3] = { 4, 4, 4 };
	//Mat m4(3, sz, CV_32FC3);	// 크기가 4x4x4인 3차원 배열인데, 하나의 요소가 3채널로 이루어진 모양(...)
	//randu(m4, -1.0f, 1.0f);		// -1.0 ~ 1,0 사이의 난수로 m4 채우기

	//// Error: 3차원부터는 << 연산 오버로딩을 사용할 수 없게 했다. 
	////cout << "m4 = " << endl << m4 << endl;		

	//float max = 0.0f;
	//// 채널이 3개니까 Vec3f로 받고, 각 차원을 순회해야하니까 iterator 사용함. 
	//// it : 4x4x4 배열의 한 요소를 가리킴(이 요소는 세개의 채널을 가지고 있음 => (*it)[0], (*it)[1], (*it)[2] 
	//MatConstIterator_<Vec3f> it = m4.begin<Vec3f>();
	//float len2;

	//// 원점으로부터 가장 먼 거리의 제곱값 구하기
	//while (it != m4.end<Vec3f>()) {
	//	cout << (*it)[0] << ", " << (*it)[1] << ", " << (*it)[2] << endl;
	//	// 원점으로부터의 거리 = sqrt(x^2, y^2, z^2);
	//	len2 = (*it)[0] * (*it)[0] + (*it)[1] * (*it)[1] + (*it)[2] * (*it)[2];
	//	if (len2 > max) max = len2;
	//	it++;
	//}

	//cout << "max = " << max << endl;

	///* Vector와 결합 *///
	//vector<Point> v1;
	//v1.push_back(Point(10, 20));
	//v1.push_back(Point(20, 30));
	//v1.push_back(Point(50, 60));

	//vector<float> v2(3, 9.25);
	//Size arr_size[] = { Size(2, 2), Size(3, 3), Size(4, 4) };
	//int arr_int[] = { 10,20, 30, 40 ,50 };

	//// v3를 arr_size, arr_size + sizeof(arr_size) / sizeof(Size) -1 로 데이터 초기화
	//vector<Size> v3(arr_size, arr_size + sizeof(arr_size) / sizeof(Size));
	//vector<int> v4(arr_int + 2, arr_int + sizeof(arr_int) / sizeof(int));

	//cout << "v1 = " << (Mat)v1 << endl << endl;
	//cout << "v2 = " << ((Mat)v2).reshape(1, 1) << endl << endl;
	//cout << "v3 = " << ((Mat)v3).reshape(1, 1) << endl << endl;
	//cout << "v4 = " << ((Mat)v4).reshape(1, 1) << endl << endl;


	///* *///
	//int arr[] = { 10, 20, 30, 40, 50 };
	//vector<int> v1(arr + 2, arr + sizeof(arr) / sizeof(int));
	//print_vectorInfo("v1", v1);
	//	
	//v1.insert(v1.begin() + 2, 100);
	//print_vectorInfo("v1, insert(2)", v1);
	//cout << ".capacity() = " << v1.capacity() << endl << endl;
	//
	//v1.erase(v1.begin() + 3);
	//print_vectorInfo("v1, erase(3)", v1);			// size = 3
	//cout << ".capacity() = " << v1.capacity() << endl << endl;		// capacity = 4
	//// => 애초에 100을 "insert"했을 당시에 2씩 재할당이 된 것.
	//// 추가할 때 1이 아닌 2씩 재할당하도록 구현되어있음(효율성)

	//v1.clear();
	//print_vectorInfo("v1, clearf()", v1);


	///* reserve *///
	//vector<double> v1, v2;
	//v1.reserve(100000);

	//double start_time = clock();
	//for (int i = 0; i < v1.capacity(); i++)
	//	v1.push_back(i);
	//printf("reserve() 사용 %5.2f ms\n", (clock() - start_time));

	//start_time = clock();
	//for (int i = 0; i < v1.capacity(); i++)
	//	v2.push_back(i);
	//printf("reserve() 미사용 %5.2f ms\n", (clock() - start_time));


	///* range *///
	// Range(int start, int end)
	// start <= 값 < end
	// int size() : sub sequence의 크기 반환
	// bool empty() 
	// Range all() : 전체 시퀀스가 Ragne를 반환
	// Range 클래스로 범위를 지정하고 Mat클래스의 () 연산자 함수를 통해서 행렬을 참조하면, 
	// 부모행렬의 특정부분을 < 공유 > 하는 행렬을 생성할 수 있다.
	//Range r1(0, 3), r2(3, 7);
	//int data[]{ 10, 11, 12, 13, 14, 15, 16,
	//			20, 21, 22, 23, 24, 25, 26,
	//			30, 31, 32, 33, 34, 35, 36,
	//			40, 41, 42, 43, 44, 45, 46 };

	//Mat m1, m2;
	//m1 = Mat(5, 7, CV_32S, data);
	//m2 = m1(r1, r2);		// m2는 m1의 일부분을 "공유"
	//Mat m3 = m1(r1, r1);

	//cout << "m1 = " << endl << m1 << endl << endl;
	//cout << "m2 = " << endl << m2 << endl << endl;
	//cout << "m3 = " << endl << m3 << endl << endl;

	//// ROI: Regin Of interested.
	//// pt: 시작위치(부모기준)
	//print_locateROI("m2", m2);
	//print_locateROI("m3", m3);

	//// 위치조정: top, bottom, left, right
	//m2.adjustROI(-1, 1, 2, -1);
	//m3.adjustROI(0, -1, -2, 2);

	//cout << endl << "< 관심영역 변경 후 >" << endl;
	//print_locateROI("m2", m2);
	//print_locateROI("m3", m3);
	//cout << endl;
	//cout << "변경 m2 = " << endl << m2 << endl;
	//cout << "변경 m3 = " << endl << m3 << endl;


	//cout << "m1의 2번 행 = " << m1.row(2) << endl;
	//cout << "m1의 1번 열 = " << endl << m1.col(1) << endl;
	//cout << "m1의 0~2행 모두 = " << endl << m1.rowRange(r1) << endl << endl;

	//cout << "m1 = " << endl << m1 << endl << endl;
	///*cout << "m2(0~2행, 3~6열 참조) = " << endl << endl;*/

	//cout << "m1 = " << endl << m1 << endl << endl;
	//cout << "m2 = " << endl << m2 << endl << endl;
	//m1.at<int>(0, 4) = 3;			// m2는 m1을 "공유"하기 때문에 같이 변경된다.
	//m2.setTo(50);
	//cout << "m1 = " << endl << m1 << endl << endl;
	//cout << "m2 = " << endl << m2 << endl << endl;



	///* Mat의 추가, 삭제 *///
	//Mat m1, m2, m3;
	//Mat m4 = Mat::zeros(2, 6, CV_8UC1);
	//Mat add1(2, 3, CV_8UC1, Scalar(100));
	//Mat add2 = (Mat)Mat::eye(4, 3, CV_8UC1);

	//m1.push_back(100);		// 행렬의 "추가"는 기본적으로 row단위로 추가됨
	//m1.push_back(200);

	//m2.push_back(300);
	//m2.push_back(300);
	//
	//m3.push_back(add1);
	//m3.push_back(add2);

	//cout << "m1" << endl << m1 << endl;
	//cout << "m2" << endl << m2 << endl;
	//cout << "m3" << endl << m3 << endl;
	//cout << "m4" << endl << m4 << endl;

	//m4.push_back(add1.reshape(1, 1));
	//m4.push_back(add2.reshape(1, 2));

	//print_matInfo2("m1", m1);
	//print_matInfo2("m2", m2);
	//print_matInfo2("m3", m3);
	//print_matInfo2("m4", m4);

	//m1.pop_back(1);			// 행렬의 "삭제"도 row단위로 수행됨
	//m2.pop_back(2);
	//m3.pop_back(3);
	//cout << "m1" << endl << m1 << endl;
	//cout << "m2" << endl << m2 << endl;
	//cout << "m3" << endl << m3 << endl;
	//cout << "m4" << endl << m4 << endl;


	///* Mat::release() *///
	// Mat::release() 메소드는 행렬데이터와 관련된 참조카운터를 감소시킴
	// 참조카운터가 0이 되면 행렬의 실데이터를 해제하고, 행렬데이터와 참조카운터의 포인터를 모두 NULL로 설정하여 메모리를 해제.
	// 일반적으로 Mat 클래스의 소멸자(destructor())에 의해 자동으로 호출되기 때문에 명시적으로 호출하는 경우는 드물다.
	//Mat m1(2, 6, CV_8UC1, Scalar(100));
	//Mat m2(3, 3, CV_32S);
	//Range r1(0, 2), r2(0, 2);
	//Mat m3 = m1(r1, r2);

	//print_matInfo2("m1", m1);
	//print_matInfo2("m2", m2);
	//print_matInfo2("m3", m3);

	//m2.release();
	//m3.release();
	//print_matInfo2("m2", m2);
	//print_matInfo2("m3", m3);

	//print_matInfo2("m1", m1);
	//m1.release();
	//print_matInfo2("m1", m1);


	///* 행렬간 연산 */// 
	/* cross()	: 외적
	* dot()	: 내적
	* inv()	: 역행렬
	* mul()	: 두행렬원소간곱셈
	* t()		: 전치
	*
	*/
	//float data[] = { 1, 0, 2,
	//				-3, 2, 6,
	//				-1, -2, 3 };

	//Mat m1(3, 3, CV_32F, data);
	//Mat m2(Matx13f(6, 30, 8));
	//Mat m2_t = m2.t();		// => m2(Matx31f(6, 30, 8)했으면 m2_t() = m2.t() 없었어도 됨 (전치행렬 써볼려고 한 코드)

	//Mat m1_inv = m1.inv(DECOMP_LU);		// decomp_lu => decomptypes 
	//Mat x = m1_inv * m2_t;

	//cout << "m1 = " << m1 << endl << endl;
	//cout << "m1_inv = " << m1_inv << endl << endl;
	//cout << "m2_t = " << m2_t << endl << endl;
	//cout << "x1, x2, x3 = " << x.t() << endl << endl;


	///* Mat::saturate_cast<_Tp>() *///
	// 1. saturate_cast<_Tp>()
	// 영상데이터의 컬러 공간변환, 밝기/대조 조정, 샤프닝, 보간법 등의 다양한 연산결과들은 8bit 범위를 넘어갈 수도 있음
	// 이러한 결과를 오류없이 8bit로 수용하기 위해 포화산술(saturation arithmetics) 연산을 사용
	// - 연산결과가 8bit 범위 초과 시 0또는 255 중 가까운 값으로 저장
	// - OpenCV는 행렬연산에 대해 포화산술 연산을 사용
	// - 기본 자료형에 대해서는 포화산술이 가능하도록 saturate_cast<_Tp>() 템플릿메소드를 제공

	// uchar => 0 ~ 255
	//Matx<uchar, 2, 2> m1;			
	//Matx<ushort, 2, 2> m2;

	//m1(0, 0) = -50;			// 206(-50을 unsigned char형에 넣다보니 생기는 값)
	//m1(0, 1) = 300;			// 4
	//m1(1, 0) = saturate_cast<uchar>(-50);
	//m1(1, 1) = saturate_cast<uchar>(300);

	//m2(0, 0) = -50;
	//m2(0, 1) = 80000;
	//m2(1, 0) = saturate_cast<unsigned short>(-50);
	//m2(1, 1) = saturate_cast<unsigned short>(80000);

	//cout << "m1 = " << endl << m1 << endl;
	//cout << "m2 = " << endl << m2 << endl;


	///* Exception *///
	// CV_Error(), CV_Error_()
	//String msg1 = "a is one";
	//String msg2 = "a is two";
	//String msg3 = "a is three";
	//int a;

	//while (true) {
	//	cout << "input a : ";
	//	cin >> a;

	//	try {
	//		// CV_Error(에러종류, msg값)
	//		// CV_Error_(에러종류, string format)
	//		if (a == 0) CV_Error(Error::StsDivByZero, "a is zero");
	//		if (a == 1) CV_Error(Error::StsBadSize, msg1);
	//		if (a == 2) CV_Error_(Error::StsOutOfRange, ("%s : %d", msg2.c_str(), a));
	//		if (a == 3) CV_Error_(Error::StsBadArg, (msg3.c_str(), a));
	//		CV_Assert(a != 4);		// Debugging
	//	}
	//	catch (cv::Exception & e) {
	//		cout << "Exception code (" << e.code << "):" << e.what();
	//		cout << endl;
	//		if (e.code == Error::StsAssert) break;
	//	}
	//}
	//

	return 0;
}

void print_matInfo(String m_name, Mat m) {
	cout << "[" << m_name << "행렬]" << endl;
	cout << " 채널 수 = " << m.channels() << endl;
	cout << " 행 x 열 = " << m.rows << " X " << m.cols << endl << endl;
}

void print_vectorInfo(string v_name, vector<int> v) {
	cout << "[" << v_name << "] = ";
	if (v.empty())
		cout << "벡터가 비었습니다." << endl;
	else
		cout << (Mat(v)).reshape(1, 1) << endl;

	cout << "[" << v_name << "]" << ".size() = " << v.size() << endl;
}

void print_locateROI(String str, Mat m) {
	Size size;
	Point pt;	// 시작위치(부모기준)
	m.locateROI(size, pt);

	// size() => width X height
	cout << "부모크기 " << size << ", " << "[" << str << "] = " << m.size() << " from " << pt << endl;
}


void print_matInfo2(String name, Mat m) {
	String mat_type;
	if (m.depth() == CV_8U)
		mat_type = "CV_8U";
	else if (m.depth() == CV_8S)
		mat_type = "CV_8S";
	else if (m.depth() == CV_16U)
		mat_type = "CV_16U";
	else if (m.depth() == CV_16S)
		mat_type = "CV_16S";
	else if (m.depth() == CV_32S)
		mat_type = "CV_32S";
	else if (m.depth() == CV_32F)
		mat_type = "CV_32F";
	else if (m.depth() == CV_64F)
		mat_type = "CV_64F";

	cout << name << " 크기  " << m.size() << ", " << " 자료형 " << mat_type << "C" << m.channels() << endl;
	cout << m << endl << endl;
}