
//#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>	// ������ �Լ� ������
using namespace cv;
using namespace std;

void print_matInfo(String m_name, Mat m);
void print_vectorInfo(string v_name, vector<int> v);
void print_locateROI(String str, Mat m);
void print_matInfo2(String name, Mat m);


int main() {

	/// 2���� ��ǥ - Point ��ü
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

	// ��Į���: x, y ��ο� ��������.
	Point2f pt9 = pt6 * 3.14f;
	Point2d pt10 = (pt3 + (Point2d)pt6) * 10;

	cout << "pt8 = " << pt8.x << ", " << pt8.y << endl;		// 192, 325
	cout << "[pt9] = " << pt9 << endl;						// [0, 1.256]
	cout << (pt2 == pt6) << endl;								// 0
	
	// ���� 
	// 2������ǥ�̹Ƿ� 2�������ͷ� ���� �������.
	// x1*x2 + y1*y2
	cout << "pt7�� pt8�� ����: " << pt8.dot(pt7) << endl;		// 243




	///* 3���� *///
	//Point3_<int> pt1(100, 200, 300);
	//Point3_<float> pt2(92.3f, 125.23f, 250.f);
	//Point3f pt3(0.3f, 0.f, 15.7f);
	//Point3d pt4(0.25, 0.6, 33.3);

	//Point3i pt5 = pt1 + (Point3i)pt2;
	//Point3f pt6 = pt2 * 3.14f;	// ��Į���
	//Point3d pt7 = ((Point3d)pt3 + pt4) * 10.f;

	//cout << "�κ���(pt4, pt7)�� ���� " << pt4.dot(pt7) << endl;			// 16322
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
	//cout << "sz1�� ���� = " << sz1.area() << endl;			// 20000
	//cout << "[sz7] = " << sz7 << endl;					// 292 x 225
	//cout << "[sz8] = " << sz8 << endl;					
	//cout << "[sz9] = " << sz9 << endl;					



	///* Rect *///
	//Size2d sz(100.5, 60.0);
	//Point2f pt1(20.f, 30.f), pt2(100.f, 200.f);

	//// ������1. left, top, width, height (����)
	// Rect_<int> rect1(10, 10, 30, 50);
	//// ������2. Point2f(left, top), Point2f(right, bottom)
	// Rect_<float> rect2(pt1, pt2);
	// Rect_<double> rect3(Point2d(20.5, 10), sz);

	//// Rect�� Point ���ϱ� 
	//// rect4��, rect1�� pt1��ǥ����ŭ "�̵�"��Ų ����!
	// Rect rect4 = rect1 + (Point)pt1;
	// Rect2f rect5 = rect2 + (Size2f)sz;

	//// &����: �� rect������ ������ �κ��� ����(rect)�� ����
	//// |����: �� rect������ �����ϴ� ��ü����(rect)�� ���� -> �̶�, ������ ��ü��� ��ü�� �ƴ�, �� ������ �����ϴ� Rect�������� ����
	// Rect2d rect6 = rect1 & (Rect)rect2;

	// cout << "rect3 = " << rect3.x << ", " << rect3.y << " => " << rect3.width << "x" << rect3.height << endl;	// 20.5, 10, 100.5x60
	//// tl() : topleft
	//// br() : bottomright
	//cout << "rect4 = " << rect4.tl() << " " << rect4.br() << endl;	// [30, 40] [60, 90]
	//cout << "rect5 ũ�� = " << rect5.size() << endl;					// [180.5 x 230]
	//cout << "[rect6] = " << rect6 << endl;							// [20 x 30 from (20, 30]

	///* Vec *///
	// �ʱ�ȭ ���� ���� 0���� �Ҵ�����.
	// typedef Vec<int, 2> Vec2i				... n = 2, 3, 4, 6, 8
	//Vec<int, 2> v1(5, 12);
	//Vec<double, 3> v2(40, 130.7, 125.6);

	//// typedef Vec<uchar, 2> Vec2b;		// b(byte <- unsigned char)
	//Vec2b v3(10, 20);

	//// typedef Vec<float, 6> Vec6f;
	//Vec6f v4(40.f, 230.25f, 525.6f);	// float 6����¥�� ����. �ʱ�ȭ���� ���� 0���� �Ҵ�

	//// typedef Vec<int, 3> Vec3i;
	//Vec3i v5(200, 230, 250);

	//Vec3d v6 = v2 + (Vec3d)v5;		
	//Vec2b v7 = (Vec2b)v1 + v3;
	//Vec6f v8 = v4 * 20.0f;

	//Point pt1 = v1 + (Vec2i)v7;
	//Point3_<int> pt2 = (Vec3i)v2;

	//cout << "[v3] = " << v3 << endl;			// [10, 20]
	//cout << "[v7] = " << v7 << endl;			// [15, 32]
	//cout << "[v3 * v7] = " << v3.mul(v7) << endl;	// [150, 255]		// 8bit���� �����÷ο�(0���� 255�̻�)�Ǹ� saturation arithmatic(�Ѿ�� 0, 255�� �����ϴ� ��)�� �����Ѵ�
	//cout << "v8[0] = " << v8[0] << endl;			// 800
	//cout << "v8[1] = " << v8[1] << endl;			// 4605
	//cout << "v8[2] = " << v8[2] << endl;			// 10512
	//cout << "v8[3] = " << v8[3] << endl;			// 0
	//cout << "[v2] = " << v2 << endl;			// [40, 130.7, 125.6]
	//cout << "[pt2] = " << pt2 << endl;			// [40, 131, 126]
	//cout << "[v4] = " << v4 << endl;			// [40, 230.25, 525.6, 0, 0, 0]



	///* Scalar */// 
	// Scalar_<_Tp> : Vect<_Tp, 4>�� ���� ������ Ŭ����(���� ���� ����ϱ� ����)
	// Blue, Green, Red, Alpha ���� �����ϱ� ���� �뵵 (*alpha�� ������ �����ϴ� ��)
	// typedef Scalar_<double> Scalar;
	// ���� ��� �������� ������ 0���� �ʱ�ȭ
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


	/////* ��� Matx													
	//// �������, �����, ��ġ���
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



	///* ������� Mat *///
	// �ʱ�ȭ�������� ���� �����Ⱚ�� ���´�. (�ڵ� 0�Ҵ� X)
	// ������1: Mat(int row, int cols, int type) => type�� CV_XX�κ��� depth��� �Ѵ�.
	/* type
	* CV_8U		uchar	0
	*
	*/
	// ������2: Mat(int row, int cols, int ytpe, const Scalar& s) => s:����� �ʱⰪ
	//float data[] = { 1.2f, 2.3f, 3.2f, 4.5f, 5.f, 6.5f };
	//Mat m1(2, 3, CV_8U);
	//const int sizes[][2] = { {2, 3}, {2, 3}, {2, 3} };
	///*Mat(3, sizes, CV_8U, Scalar(300, 50, 40));*/
	//Mat m2(2, 3, CV_8U, Scalar(300));		// 300���� �ʱ�ȭ�Ϸ��� ����, CV_8U�� overflow�ż� maximum���� 255�� �ʱ�ȭ��.
	//Mat m3(2, 3, CV_16S, Scalar(300));		// Scalar(300) => Scalar(300, 0, 0, 0)�ε� m3�� 2x3, �� 1ä���̱� ������ �� ���� 300���θ� ä����
	//Mat m4(2, 3, CV_32F, data);

	//Size sz(2, 3);
	//Mat m5(Size(2, 3), CV_64F);
	//Mat m6(sz, CV_32F, data);

	//// CV_8UC1 => CV_8Uä���� 1�� => one ä��
	//Mat m7 = Mat::ones(3, 5, CV_8UC1);			// �̰ɷ� 0���� �ʱ�ȭ�ϸ�, �����Ⱚ ������ �� ����
	//Mat m8 = Mat::zeros(3, 5, CV_8UC1);
	//Mat m9 = Mat::eye(3, 5, CV_8UC1);			// eye: ������ķ� ����
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

	//// Mat_�� Mat�� ��ӹ޾� ���ǵ� Ŭ����.
	//Mat_<int> m1(2, 4);
	//Mat_<uchar> m2(3, 4, 100);
	//Mat_<short> m3(4, 5, c);

	//m1 << 1, 2, 3, 4, 5, 6;
	//// Mat_Ÿ���� ��ü�� MatŸ���� �����Ͱ� ����Ű�� �ִ� ��(������)
	//// m4�� ����� "���"�̰�, ���� �����ʹ� ���� ����. ����Ű�� ����)
	//// main���α׷��� ����Ǹ� ���������� m4�� ������µ� �� ���� �ǵ����ʹ� ���� ó��������?
	//// m4�� �Ҹ�Ǹ鼭 �ڽ��� �Ҹ��ڸ� ȣ���ϰ�, �� �Ҹ��ڳ����� �ǵ����͸� free()��
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

	//// m1 : 4x3 ä���� 3�� �ִ� �� -> CV_32F"C3"
	//Mat m1(4, 3, CV_32FC3);
	//cout << "���� �� = " << m1.dims << endl;			// 2	
	//cout << "�� �� = " << m1.rows << endl;			// 4
	//cout << "�� �� = " << m1.cols << endl;			// 3
	//// size() => width * height�̶� 4x3�̸� 3x4�� ����
	//cout << "���ũ�� = " << m1.size() << endl << endl;	// 3x4

	//cout << "��ü���Ұ��� = " << m1.total() << endl;		// 12

	//// "�ѿ���"��, 3���� ä�� �󿡼� ������ ��ǥ�� �ش��ϴ� ��θ� �ǹ��Ѵ�.
	//// ��, �� ä�� ������ �ϳ��� ���Ұ� 4bytes(CV_32F)�̰� �̰� �� ���Ҵ� 3ä�� �������Ƿ� 12
	//cout << "�� ������ ũ�� = " << m1.elemSize() << endl;		// 12
	//cout << "ä�δ� �� ������ ũ�� = " << m1.elemSize1() << endl << endl;		// 4 (=> 32FC3)

	//cout << "Ÿ�� = " << m1.type() << endl;		// 21
	//cout << "((m1.channels() - 1) << 3) = " << ((m1.channels() - 1) << 3) << endl;	// 16

	//// ���� "Ÿ��"������ 21�� ������ ���� => Ÿ�� = ä�μ� n + ���̰� d(���� d�� nä�ΰ� ������)
	//cout << "Ÿ��(ä�μ� (3bit) | ����(3bit)) = " << ((m1.channels() - 1) << 3) + m1.depth() << endl;		 // 21
	//
	//// ���� => CV_32F => 5
	//cout << "���� = " << m1.depth() << endl;		// 5

	//cout << "ä�� =" << m1.channels() << endl;		// 3

	//// step: �� row�� �ҿ�Ǵ� ����Ʈ�� => �� row : ((4x3) (4x3) (4x3))
	//cout << "step =" << m1.step << endl;			// 36
	//cout << "step1()=" << m1.step1() << endl;		// 9


	///* 06.05 *///
	//Mat m1(2, 3, CV_8U, 2);
	//Mat m2(2, 3, CV_8U, Scalar(10));

	//Mat m3 = m1 + m2;		// ��ĳ��� ����
	//Mat m4 = m2 - 6;
	//Mat m5 = m1;			// Mat��ü�� �����ͺ���. �� ������ �ּҸ� ����Ű�� ��

	//cout << "[m1] =" << endl << m1 << endl;
	//cout << "[m2] =" << endl << m2 << endl;
	//cout << "[m3] =" << endl << m3 << endl;
	//cout << "[m4] =" << endl << m4 << endl;

	//cout << "[m1] =" << endl << m1 << endl;
	//cout << "[m5] =" << endl << m5 << endl;
	//m5 = 100;									
	//cout << "[m1] =" << endl << m1 << endl;
	//cout << "[m5] =" << endl << m5 << endl;	

	//// ����Ʈ������(cpp)
	//// ������ �޸𸮸� ���� �����Ͱ� ����Ű�� ���� ��, ���� ���۷����ϰ� �ִ� ������ ���� ����
	//// �� ���� 0�� �ɶ� �����θ� �Ҹ��Ű���� ����. 


	/////* Mat : resize() */// 
	//Mat m = (Mat_<uchar>(2, 4) << 1, 2, 3, 4, 5, 6, 7, 8);
	//cout << "m = " << endl << m << endl << endl;

	//m.resize(1);						
	//cout << "m.resize(1) = " << endl << m << endl;	
	//m.resize(3);						// ���� ���� ����Ʈ��(�����Ⱚ)���� ä���
	//cout << "m.resize(3); = " << endl << m << endl;
	//m.resize(5, Scalar(50));			// ���� ���� 50���� ä���
	//cout << "m.resize(5) = " << endl << m << endl;


	///* Mat : reshape *///
	//// �����͸� �߶󳻰ų� ���̴°� �ƴ϶� ��縸 �ٽ� ¥�� ��
	//// ���� ��, �� ��� ��ü ���� ���� �¾ƾ���
	//// Row�� ����.
	//Mat m1(2, 6, CV_8U);
	//Mat m2 = m1.reshape(2);
	//Mat m3 = m1.reshape(3, 2); // ä���� 3�� row�� 2��

	//print_matInfo("m1(2, 6)", m1);
	//print_matInfo("m2 = m1.reshape(2)", m2);
	//print_matInfo("m3 = m1.reshape(3, 2)", m3);

	//m1.create(3, 5, CV_16S);
	//print_matInfo("m1.create(3, 5, CV_16S)", m1);


	///* Mat : clone(), copyTo(), convertTo() *///
	//// ���� ����(����� �����ϴ°� �ƴ϶�, �ǵ����͸� �����ؿ���)
	//// �ε��Ҽ���(����/����)???
	//double data[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.9, 9.9, 10, 11, 12 };		// 8.8�̸� 8.8000000000 ����
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
	//Mat m1 = Mat::eye(10, 10, CV_32FC1);	// eye: ������� 
	//cout << "Element (3, 3) is " << m1.at<float>(3, 3) << endl << endl;

	//Mat m2 = Mat::eye(10, 10, CV_32FC2);	// ��ä�� ������� => �Ǿ�ä�θ� �밢������ 1 ä������, �� �������� 0���� ����
	//// at<Vec2f> : �� ä�ο��� ���� ���� �ִ�(3, 3) �ֵ��� ��� �ϳ��� ���͸� ����� �ű⿡ �ε����� ����
	//cout << "Element (3, 3) is (" << m2.at<Vec2f>(3, 3)[0] << ", " << m2.at<Vec2f>(3, 3)[1] << ")" << endl << endl;
	//
	//// m3: ���� ������ float�� ���Ҽ�(complex>�� 10x10 
	//Mat m3 = Mat::eye(10, 10, traits::Type<Complex<float>>::value);
	//// re: �Ǽ�, im: ���
	//cout << "Element (3, 3) is (" << m3.at<Complexf>(3, 3).re << " + " << m3.at<Complexf>(3, 3).im << "i)" << endl << endl;

	//cout << "=======================================================================" << endl;
	//int sz[3] = { 4, 4, 4 };
	//Mat m4(3, sz, CV_32FC3);	// ũ�Ⱑ 4x4x4�� 3���� �迭�ε�, �ϳ��� ��Ұ� 3ä�η� �̷���� ���(...)
	//randu(m4, -1.0f, 1.0f);		// -1.0 ~ 1,0 ������ ������ m4 ä���

	//// Error: 3�������ʹ� << ���� �����ε��� ����� �� ���� �ߴ�. 
	////cout << "m4 = " << endl << m4 << endl;		

	//float max = 0.0f;
	//// ä���� 3���ϱ� Vec3f�� �ް�, �� ������ ��ȸ�ؾ��ϴϱ� iterator �����. 
	//// it : 4x4x4 �迭�� �� ��Ҹ� ����Ŵ(�� ��Ҵ� ������ ä���� ������ ���� => (*it)[0], (*it)[1], (*it)[2] 
	//MatConstIterator_<Vec3f> it = m4.begin<Vec3f>();
	//float len2;

	//// �������κ��� ���� �� �Ÿ��� ������ ���ϱ�
	//while (it != m4.end<Vec3f>()) {
	//	cout << (*it)[0] << ", " << (*it)[1] << ", " << (*it)[2] << endl;
	//	// �������κ����� �Ÿ� = sqrt(x^2, y^2, z^2);
	//	len2 = (*it)[0] * (*it)[0] + (*it)[1] * (*it)[1] + (*it)[2] * (*it)[2];
	//	if (len2 > max) max = len2;
	//	it++;
	//}

	//cout << "max = " << max << endl;

	///* Vector�� ���� *///
	//vector<Point> v1;
	//v1.push_back(Point(10, 20));
	//v1.push_back(Point(20, 30));
	//v1.push_back(Point(50, 60));

	//vector<float> v2(3, 9.25);
	//Size arr_size[] = { Size(2, 2), Size(3, 3), Size(4, 4) };
	//int arr_int[] = { 10,20, 30, 40 ,50 };

	//// v3�� arr_size, arr_size + sizeof(arr_size) / sizeof(Size) -1 �� ������ �ʱ�ȭ
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
	//// => ���ʿ� 100�� "insert"���� ��ÿ� 2�� ���Ҵ��� �� ��.
	//// �߰��� �� 1�� �ƴ� 2�� ���Ҵ��ϵ��� �����Ǿ�����(ȿ����)

	//v1.clear();
	//print_vectorInfo("v1, clearf()", v1);


	///* reserve *///
	//vector<double> v1, v2;
	//v1.reserve(100000);

	//double start_time = clock();
	//for (int i = 0; i < v1.capacity(); i++)
	//	v1.push_back(i);
	//printf("reserve() ��� %5.2f ms\n", (clock() - start_time));

	//start_time = clock();
	//for (int i = 0; i < v1.capacity(); i++)
	//	v2.push_back(i);
	//printf("reserve() �̻�� %5.2f ms\n", (clock() - start_time));


	///* range *///
	// Range(int start, int end)
	// start <= �� < end
	// int size() : sub sequence�� ũ�� ��ȯ
	// bool empty() 
	// Range all() : ��ü �������� Ragne�� ��ȯ
	// Range Ŭ������ ������ �����ϰ� MatŬ������ () ������ �Լ��� ���ؼ� ����� �����ϸ�, 
	// �θ������ Ư���κ��� < ���� > �ϴ� ����� ������ �� �ִ�.
	//Range r1(0, 3), r2(3, 7);
	//int data[]{ 10, 11, 12, 13, 14, 15, 16,
	//			20, 21, 22, 23, 24, 25, 26,
	//			30, 31, 32, 33, 34, 35, 36,
	//			40, 41, 42, 43, 44, 45, 46 };

	//Mat m1, m2;
	//m1 = Mat(5, 7, CV_32S, data);
	//m2 = m1(r1, r2);		// m2�� m1�� �Ϻκ��� "����"
	//Mat m3 = m1(r1, r1);

	//cout << "m1 = " << endl << m1 << endl << endl;
	//cout << "m2 = " << endl << m2 << endl << endl;
	//cout << "m3 = " << endl << m3 << endl << endl;

	//// ROI: Regin Of interested.
	//// pt: ������ġ(�θ����)
	//print_locateROI("m2", m2);
	//print_locateROI("m3", m3);

	//// ��ġ����: top, bottom, left, right
	//m2.adjustROI(-1, 1, 2, -1);
	//m3.adjustROI(0, -1, -2, 2);

	//cout << endl << "< ���ɿ��� ���� �� >" << endl;
	//print_locateROI("m2", m2);
	//print_locateROI("m3", m3);
	//cout << endl;
	//cout << "���� m2 = " << endl << m2 << endl;
	//cout << "���� m3 = " << endl << m3 << endl;


	//cout << "m1�� 2�� �� = " << m1.row(2) << endl;
	//cout << "m1�� 1�� �� = " << endl << m1.col(1) << endl;
	//cout << "m1�� 0~2�� ��� = " << endl << m1.rowRange(r1) << endl << endl;

	//cout << "m1 = " << endl << m1 << endl << endl;
	///*cout << "m2(0~2��, 3~6�� ����) = " << endl << endl;*/

	//cout << "m1 = " << endl << m1 << endl << endl;
	//cout << "m2 = " << endl << m2 << endl << endl;
	//m1.at<int>(0, 4) = 3;			// m2�� m1�� "����"�ϱ� ������ ���� ����ȴ�.
	//m2.setTo(50);
	//cout << "m1 = " << endl << m1 << endl << endl;
	//cout << "m2 = " << endl << m2 << endl << endl;



	///* Mat�� �߰�, ���� *///
	//Mat m1, m2, m3;
	//Mat m4 = Mat::zeros(2, 6, CV_8UC1);
	//Mat add1(2, 3, CV_8UC1, Scalar(100));
	//Mat add2 = (Mat)Mat::eye(4, 3, CV_8UC1);

	//m1.push_back(100);		// ����� "�߰�"�� �⺻������ row������ �߰���
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

	//m1.pop_back(1);			// ����� "����"�� row������ �����
	//m2.pop_back(2);
	//m3.pop_back(3);
	//cout << "m1" << endl << m1 << endl;
	//cout << "m2" << endl << m2 << endl;
	//cout << "m3" << endl << m3 << endl;
	//cout << "m4" << endl << m4 << endl;


	///* Mat::release() *///
	// Mat::release() �޼ҵ�� ��ĵ����Ϳ� ���õ� ����ī���͸� ���ҽ�Ŵ
	// ����ī���Ͱ� 0�� �Ǹ� ����� �ǵ����͸� �����ϰ�, ��ĵ����Ϳ� ����ī������ �����͸� ��� NULL�� �����Ͽ� �޸𸮸� ����.
	// �Ϲ������� Mat Ŭ������ �Ҹ���(destructor())�� ���� �ڵ����� ȣ��Ǳ� ������ ��������� ȣ���ϴ� ���� �幰��.
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


	///* ��İ� ���� */// 
	/* cross()	: ����
	* dot()	: ����
	* inv()	: �����
	* mul()	: ����Ŀ��Ұ�����
	* t()		: ��ġ
	*
	*/
	//float data[] = { 1, 0, 2,
	//				-3, 2, 6,
	//				-1, -2, 3 };

	//Mat m1(3, 3, CV_32F, data);
	//Mat m2(Matx13f(6, 30, 8));
	//Mat m2_t = m2.t();		// => m2(Matx31f(6, 30, 8)������ m2_t() = m2.t() ����� �� (��ġ��� �Ẽ���� �� �ڵ�)

	//Mat m1_inv = m1.inv(DECOMP_LU);		// decomp_lu => decomptypes 
	//Mat x = m1_inv * m2_t;

	//cout << "m1 = " << m1 << endl << endl;
	//cout << "m1_inv = " << m1_inv << endl << endl;
	//cout << "m2_t = " << m2_t << endl << endl;
	//cout << "x1, x2, x3 = " << x.t() << endl << endl;


	///* Mat::saturate_cast<_Tp>() *///
	// 1. saturate_cast<_Tp>()
	// ���������� �÷� ������ȯ, ���/���� ����, ������, ������ ���� �پ��� ���������� 8bit ������ �Ѿ ���� ����
	// �̷��� ����� �������� 8bit�� �����ϱ� ���� ��ȭ���(saturation arithmetics) ������ ���
	// - �������� 8bit ���� �ʰ� �� 0�Ǵ� 255 �� ����� ������ ����
	// - OpenCV�� ��Ŀ��꿡 ���� ��ȭ��� ������ ���
	// - �⺻ �ڷ����� ���ؼ��� ��ȭ����� �����ϵ��� saturate_cast<_Tp>() ���ø��޼ҵ带 ����

	// uchar => 0 ~ 255
	//Matx<uchar, 2, 2> m1;			
	//Matx<ushort, 2, 2> m2;

	//m1(0, 0) = -50;			// 206(-50�� unsigned char���� �ִٺ��� ����� ��)
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
	//		// CV_Error(��������, msg��)
	//		// CV_Error_(��������, string format)
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
	cout << "[" << m_name << "���]" << endl;
	cout << " ä�� �� = " << m.channels() << endl;
	cout << " �� x �� = " << m.rows << " X " << m.cols << endl << endl;
}

void print_vectorInfo(string v_name, vector<int> v) {
	cout << "[" << v_name << "] = ";
	if (v.empty())
		cout << "���Ͱ� ������ϴ�." << endl;
	else
		cout << (Mat(v)).reshape(1, 1) << endl;

	cout << "[" << v_name << "]" << ".size() = " << v.size() << endl;
}

void print_locateROI(String str, Mat m) {
	Size size;
	Point pt;	// ������ġ(�θ����)
	m.locateROI(size, pt);

	// size() => width X height
	cout << "�θ�ũ�� " << size << ", " << "[" << str << "] = " << m.size() << " from " << pt << endl;
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

	cout << name << " ũ��  " << m.size() << ", " << " �ڷ��� " << mat_type << "C" << m.channels() << endl;
	cout << m << endl << endl;
}