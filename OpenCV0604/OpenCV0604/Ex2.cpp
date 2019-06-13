#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

	/// ������� : Chapter 03, 04(SparseMat ����), 05(�����ð��� ����� ���븸), 06, 08, 10(�����ð��� ����� ���븸)
	// �� �Լ��� ����, ���뵵, Ư¡(����, ������ ��) �˾Ƶα�. 

void onMouse(int event, int x, int y, int flags, void* userData);
void onChange(int value, void* userData);
void onMouse_tr(int event, int x, int y, int flags, void* userData);
void onMouse_image(int event, int x, int y, int flags, void* userData);
void print_matInfo(string name, Mat m);
void put_string(Mat& frame, string text, Point pt, int value);
void bgr2hsi(Mat img, Mat& hsi);
void filter(Mat img, Mat& dst, Mat mask);
void homogenOp(Mat img, Mat& dst, int mask_size);
void differOp(Mat img, Mat& dst, int mask_size);
void differential(Mat image, Mat& dst, float data1[], float data2[]);

string title = "Ʈ���� �̺�Ʈ"; 
string title_image = "Event_Drawing";
string bar_name = "��⺯��";
Mat image;

int main() {

	/// ������ ���� - namedWindow()
	/* void cv::namedWindow	(	const String & 	winname,
								int 			flags = WINDOW_AUTOSIZE 
							)	
		- flags 
		  WINDOW_AUTOSIZE:	������ â ũ�� ����Ұ�
		  WINDOW_NORMAL:	������ â ũ�� ���氡��

	 * void cv::moveWindow	(	const String & 	winname,
								int 			x,
								int 			y
							)

	 * void cv::imshow	(	const String & 	winname,
							InputArray 		mat
						)
	 
	 */
	//Mat image1(300, 400, CV_8U, Scalar(255));
	//string title1 = "white window";
	//namedWindow(title1, WINDOW_AUTOSIZE);
	//moveWindow(title1, 100, 200);
	//imshow(title1, image1);

	//Mat image2(300, 400, CV_8U, Scalar(100));
	//string title2 = "gray window";
	//namedWindow(title2, WINDOW_NORMAL);	
	//moveWindow(title2, 300, 200);
	//imshow(title2, image2);

	//waitKey();	// default�� 0
	//destroyAllWindows();


	/// Ű���� �̺�Ʈ
	/*  int cv::waitKey(int delay = 0) : 0-9, Aa-Zz �ܿ� Ű�ڵ带 ���޾ƿ�
		- delay: ms����. 0 is the special value that means "forever".

	*	int waitKeyEx(int delay = 0) : Ű �̺�Ʈ�߻��� �ش�Ű �� ��ȯ
	*
	*/
	//Mat image(200, 300, CV_8U, Scalar(255));
	//namedWindow("Ű���� �̺�Ʈ", WINDOW_AUTOSIZE);
	//imshow("Ű���� �̺�Ʈ", image);

	//while (1) {
	//	int key = waitKeyEx(20);
	//	if (key == 27) // ESC
	//		break;
	//	switch (key) {
	//	case 'a': cout << "a �Է�" << endl;
	//		break;
	//	case 'b': cout << "b �Է�" << endl;
	//		break;
	//	case 0x41: cout << "A �Է�" << endl;
	//		break;
	//	case 66: cout << "B �Է�" << endl;
	//		break;
	//	case 2424832: cout << "����ȭ��ǥ �Է�" << endl;
	//		break;
	//	case 2490368: cout << "����ȭ��ǥ �Է�" << endl;
	//		break;
	//	case 2555904: cout << "������ȭ��ǥ �Է�" << endl;
	//		break;
	//	case 2621440: cout << "�Ʒ���ȭ��ǥ �Է�" << endl;
	//		break;
	//	default:
	//		break;
	//	}
	//}


	/// ���콺 �̺�Ʈ - setMouseCallback()
	/* void cv::setMouseCallback	(	const String & 	winname,
										MouseCallback 	onMouse,	
										void * 	userdata = 0 
									)	
			- onMouse�� Ÿ��: MouseCallback 
			- typedef void (* cv::MouseCallback)(int event, int x, int y, int flags, void* userData) 
				=> �Լ�������				event	: �̺�Ʈ ����(���)
											x, y	: �̺�Ʈ �߻����� ���콺 ��ǥ
											flags	: shift�� ���� �����ٴ����� �ɼ��� ������ �� ����ϴ� ����
											userData: �̺�Ʈ�ڵ鷯�� �ѱ�� ���� ������
	*/	
	//// Mat image(200, 300, CV_8U, Scalar(255));
	//Mat image(200, 300, CV_8U);
	//image.setTo(255);			

	//imshow("���콺�̺�Ʈ1", image);
	//imshow("���콺�̺�Ʈ2", image);
	//int a = 10;

	//setMouseCallback("���콺�̺�Ʈ1", onMouse, &a);
	//waitKeyEx();


	/// Ʈ���� �̺�Ʈ  - createTrackbar() 
	/* int cv::createTrackbar	(	const String &		trackbarname,				// Ʈ���ٸ�
									const String &		winname,					// Ʈ���ٸ� �� �������	
									int * 				value,						// Ʈ������ �ʱⰪ
									int 				count,						// Ʈ������ �ִ밪
									TrackbarCallback 	onChange = 0,				// Ʈ���� �޼ҵ�
									void * 				userdata = 0				// Ʈ���ٷ� �ѱ� ����ڵ�����
								)
	 * typedef void(* cv::TrackbarCallback) (	int		pos,						// �̺�Ʈ �߻��� Ʈ������ ��(��ġ)
												void *	userdata					
											)

	*/
	image = Mat(300, 500, CV_8UC1, Scalar(120));
	namedWindow(title, WINDOW_AUTOSIZE);

	// Trackbar Ex. #1
	int value = 130;
	createTrackbar("��Ⱚ", title, &value, 255, onChange);

	// Trackbar Ex. #2
	createTrackbar(bar_name, title, &value, 255, onChange);
	setMouseCallback(title, onMouse_tr, 0);

	imshow(title, image);
	waitKey();


	/// Drawing - �׸��׸���
	/*	line(), rectangle() ��
	*
	*/
	//Scalar blue(255, 0, 0), red(0, 0, 255), green(0, 255, 0);			// openCV������ BGR������ ����
	//Scalar white(255, 255, 255), yellow(0, 255, 255);
	//
	//Mat image(400, 600, CV_8UC3, white);
	//Point pt1(50, 130), pt2(200, 300), pt3(300, 150), pt4(400, 50);
	//Rect rect(pt3, Size(200, 150));

	//// line(image, ��ǥ��1, ��ǥ��2, ����, �β�, LineType, shift��)
	////		- LineType : FILLED, LINE_4, LINE_8, LINE_AA
	////		- shift :	1�̸� ���� 1/2ȿ�� => �̵�
	//line(image, pt1, pt2, red);
	//line(image, pt3, pt4, green, 2, LINE_AA);
	//line(image, pt3, pt4, green, 3, LINE_8, 1);

	//// rectangle
	////		- 
	//rectangle(image, rect, blue, 2);
	//rectangle(image, rect, blue, FILLED, LINE_4, 1);
	//rectangle(image, pt1, pt2, red, 3);

	//imshow("���� �簢��", image);
	//waitKey();


	/// Drawing - ���ڳֱ� 
	/* putText() :
	*		- ��Ʈ���� image�� �����Ű�� ��
	*
	*/
	//Scalar olive(128, 128, 0), violet(221, 160, 221), brown(42, 42, 165);
	//Point pt1(20, 100), pt2(20, 200), pt3(20, 250);

	//Mat image(300, 500, CV_8UC3, Scalar(255, 255, 255));

	//
	//putText(image, "SIMPLEX", Point(20, 30), FONT_HERSHEY_SIMPLEX, 1, brown);		// ��Ʈ���� image�� SIMPLEX��� ���ڸ� �� -> ��, image�� ���� ����� ��!
	//putText(image, "DUPLEX", pt1, FONT_HERSHEY_DUPLEX, 2, olive);
	//putText(image, "TRIPLEX", pt2, FONT_HERSHEY_TRIPLEX, 1, violet);
	//putText(image, "ITALIC", pt3, FONT_HERSHEY_PLAIN | FONT_ITALIC, 2, violet);

	//imshow("putText", image);
	//waitKey();


	/// Drawing - putText() Ex2.
	/* putText(InputOutputArray 	img,
				const String&		text,
				Point 				org,
				int 				fontFace,
				double 				fontScale,
				Scalar 				color,
				int 				thickness = 1,
				int 				lineType = LINE_8,
				bool 				bottomLeftOrigin = false
				)
	*/
	//Scalar orange(0, 165, 255), blue(255, 0, 0), magenta(255, 0, 255);
	//Mat image(300, 500, CV_8UC3, Scalar(255, 255, 255));

	//Point center = (Point)image.size() / 2;
	//Point pt1(70, 50), pt2(350, 220);

	//circle(image, center, 100, blue);
	//circle(image, pt1, 80, orange, 2);
	//circle(image, pt2, 60, magenta, -1);

	//int font = FONT_HERSHEY_COMPLEX;
	//putText(image, "center_blue", center, font, 1.2, blue);
	//putText(image, "pt1_orange", pt1, font, 0.8, orange);
	//putText(image, "pt2_magenta", pt2 + Point(2, 2), font, 0.5, Scalar(0, 0, 0), 2);
	//putText(image, "pt2_magenta", pt2, font, 0.5, magenta, 1);

	//imshow("��", image);
	//waitKey();



	/// Drawing - RotateRect()
	//Mat image(300, 500, CV_8UC1, Scalar(255));
	//Point2f center(250, 150), pts[4];
	//Size2f size(300, 100);

	//RotatedRect rot_rect(center, size, 20);

	//Rect bound_rect = rot_rect.boundingRect();
	//rectangle(image, bound_rect, Scalar(0), 1);
	//circle(image, rot_rect.center, 1, Scalar(0), 2);
	//rot_rect.points(pts); // order: bl, tl, tr, br
	//for (int i = 0; i < 4; i++) {
	//	circle(image, pts[i], 4, Scalar(0), 1);
	//	line(image, pts[i], pts[(i + 1) % 4], Scalar(0), 2);
	//}

	//imshow("RotatedRect", image);
	//waitKey();



	/// Drawing - ellipse()
	/* void cv::ellipse	(	InputOutputArray 	img,
							Point 				center,
							Size 				axes,
							double 				angle,
							double				startAngle,
							double				endAngle,
							const Scalar & 		color,
							int 				thickness = 1,
							int 				lineType = LINE_8,
							int 				shift = 0
						)
	 *
	 */
	//Scalar orange(0, 165, 255), blue(255, 0, 0), magenta(255, 0, 255);
	//Mat image(300, 700, CV_8UC3, Scalar(255, 255, 255));

	//Point pt1(120, 150), pt2(550, 150);
	//circle(image, pt1, 1, Scalar(0), 1);
	//circle(image, pt2, 1, Scalar(0), 1);

	//// size(100, 60) : ���μ��� ������ 
	//// 0������ 360������ orange �׸��� & 30������ 270������ blue �׸��� 
	//ellipse(image, pt1, Size(100, 60), 0, 0, 360, orange, 2);
	//ellipse(image, pt1, Size(100, 60), 0, 30, 270, blue, 4);

	//// Ÿ����ü�� �ޱ��� 30���� ���� �׸���,
	//ellipse(image, pt2, Size(100, 60), 30, 0, 360, orange, 2);

	//// start < end : �ð�������� �׸���,
	//// start > end : �ݽð�������� �׸�.
	//ellipse(image, pt2, Size(100, 60), 30, -30, 160, blue, 4);
	/*ellipse(image, pt2, Size(100, 60), 30, 330, 160, blue, 4);*/

	//imshow("Ÿ��", image);
	//waitKey();



	/// Drawing - onMouse
	//image = Mat(300, 500, CV_8UC1, Scalar(255));
	//imshow(title, image);
	//setMouseCallback(title, onMouse_image, 0);

	//waitKey();


	/// �̹��� ÷���ϱ� #1
	//// ������Ʈ����(OpenCV0604)�� ��Ʈ���丮(.vcsproj�� �ִ� ��)�� images.jpg �����س��� ��� �Է��ϱ�
	////String filename = "image/images.jpg";	// ��鿹��
	//String filename = "image/maxresdefault.jpg";	// �÷�����

	//// ���� filename�� ���(IMREAD_GRAYSCALE)���� �о���̰ڴ�
	//Mat gray2gray = imread(filename, IMREAD_GRAYSCALE);		// IMREAD_UNCHANGED �ᵵ ������. �̰��� �����״�θ� �������� ��
	//Mat gray2color = imread(filename, IMREAD_COLOR);
	//// mat��ü�� data���� => mat��ü�� ���� gray2gray�� ����Ű�� �ǵ����Ͱ� ������ �� ���� null�� �ǰ�, ������ non-null
	//CV_Assert(gray2gray.data && gray2color.data);

	//// Rect => left, top, width, height 
	//Rect roi(100, 100, 1, 1);	// �ᱹ ȭ�� 1���� �ǹ�
	//cout << "��� ��ǥ(100, 100)�� ȭ�Ұ�" << endl;
	//cout << "gray2gray" << gray2gray(roi) << endl;
	//cout << "gray2color" << gray2color(roi) << endl;

	//print_matInfo("gray2gray", gray2gray);
	//print_matInfo("gray2color", gray2color);
	//imshow("gray2gray", gray2gray);
	//imshow("gray2color", gray2color);
	//waitKey();


	/// �̹��� ÷���ϱ� #2
	//string filename1 = "image/example_16.tif";
	//string filename2 = "image/example_32.tif";

	//Mat color2unchanged1 = imread(filename1, IMREAD_UNCHANGED);
	//Mat color2unchanged2 = imread(filename2, IMREAD_UNCHANGED);

	///*CV_ASSERT(color2unchanged1.data && color2unchanged2.data);*/
	//CV_Assert(color2unchanged1.data);
	//CV_Assert(color2unchanged2.data);	

	//Rect roi(100, 100, 1, 1);
	//cout << "16/32��Ʈ �����ǥ(100, 100) ȭ�Ұ�" << endl;
	//// 16U -> unsigned short. 0~2^15-1
	//cout << "color2unchanged1" << color2unchanged1(roi) << endl;	// color2unchanged1[30144, 33472, 33536]
	//// 32F -> 0�� ������ 1�� ���. 0�� 1������ ���� ȭ�鿡 �Ѹ��� 255�� ������ �Ѹ�
	//cout << "color2unchanged2" << color2unchanged2(roi) << endl;	// color2unchanged2[0.59128636]

	//print_matInfo("color2unchanged1", color2unchanged1);		// depth(2) channels(3) -> �ڷ���: CV_16UC3
	//print_matInfo("color2unchanged2", color2unchanged2);		// depth(5) channels(1) -> �ڷ���: CV_32FC1

	//imshow("color2unchanged1", color2unchanged1);
	//imshow("color2unchanged2", color2unchanged2);
	//waitKey();



	/// �̹��� �����ϱ� - imwrite()
	//// imwrite() => �� ù���ڷ� ���ϸ��� ���µ�, �� ���ϸ� ����� Ȯ���ڴ�� ������ �����.
	//Mat image = imread("image/maxresdefault.jpg", IMREAD_COLOR);
	//CV_Assert(image.data);

	//vector<int> params_jpg, params_png;

	//// �׸�->��->... ������ ����
	//// jpeg�� ȭ���� 50���� ����
	//params_jpg.push_back(IMWRITE_JPEG_QUALITY);
	//params_jpg.push_back(50);

	//// �׸�->��->... ������ ����
	//// png�� ����� = 9�� ����(����Ʈ=3)
	//params_png.push_back(IMWRITE_PNG_COMPRESSION);
	//params_png.push_back(9);

	//imwrite("image/write_test1.jpg", image);
	//imwrite("image/write_test2.jpg", image, params_jpg);
	//		   
	//imwrite("image/write_test.png", image, params_png);
	//imwrite("image/write_test.bmp", image);



	/// �̹��� ��ȯ�ϱ� - convertTo()
	//// ������ �°� �� ��ȯ�������
	//Mat img8 = imread("image/maxresdefault.jpg", IMREAD_COLOR);
	//CV_Assert(img8.data);

	//Mat img16, img32;
	//// 65535: ȭ�ҽ�����(16bits), 32F�� 0~1�̹Ƿ� ���� ����
	//img8.convertTo(img16, CV_16U, 65535 / 255.0);
	//img8.convertTo(img32, CV_32F, 1 / 255.0f);

	//Rect roi(10, 10, 3, 3);
	//cout << "img8 ����� �Ϻ� " << endl << img8(roi) << endl << endl;
	//cout << "img16 ����� �Ϻ� " << endl << img16(roi) << endl << endl;
	//cout << "img32 ����� �Ϻ� " << endl << img32(roi) << endl << endl;

	//imwrite("image/write_test_16.tif", img16);
	//imwrite("image/write_test_32.tif", img32);

	//imshow("img16", img16);
	//imshow("img32", img32);
	//waitKey();



	/// ���� ���� - VideoCapture()
	//// - ī�޶��ִ� ��ǻ�Ϳ��� Ȯ�ΰ���(��Ʈ�� ��)	
	//VideoCapture capture(0);		// ����Ǿ� �ִ� ù��° ī�޶���ġ -> ������ �̹� ����Ǿ��ִ� ī�޶� �ǹ�
	//if (!capture.isOpened()) {
	//	cout << "ī�޶� ������� �ʾҽ��ϴ�." << endl;
	//	exit(1);
	//}

	//cout << "�ʺ� " << capture.get(CAP_PROP_FRAME_WIDTH) << endl;
	//cout << "���� " << capture.get(CAP_PROP_FRAME_HEIGHT) << endl;
	//cout << "���� " << capture.get(CAP_PROP_EXPOSURE) << endl;
	//cout << "��� " << capture.get(CAP_PROP_BRIGHTNESS) << endl;

	//while (true) {
	//	Mat frame;
	//	capture.read(frame);

	//	put_string(frame, "EXPOS: ", Point(10, 40), capture.get(CAP_PROP_EXPOSURE));
	//	imshow("ī�޶� ����", frame);
	//	if (waitKey(30) >= 0) break;
	//}



	/// ���� ���� - VideoCapture() #2 
	//VideoCapture capture;
	//capture.open("image/video-sample.avi");
	//CV_Assert(capture.isOpened());

	//double fps = capture.get(CV_CAP_PROP_FPS);
	//int delay = 1000 / fps;
	//int frame_cnt = 0;
	//Mat frame;

	//while (capture.read(frame)) {
	//	if (waitKey(delay) >= 0) break;

	//	frame_cnt = capture.get(CV_CAP_PROP_POS_FRAMES);	// ������ �����ӹ�ȣ�� �Ѿ��
	//	if (frame_cnt < 100)
	//		;
	//	else if (frame_cnt < 200)
	//		frame -= Scalar(0, 0, 100);	// Red 100 ����
	//	else if (frame_cnt < 300)
	//		frame += Scalar(100, 0, 0);	// Blue 100 ����
	//	else if (frame_cnt < 400)
	//		frame = frame * 1.5;	// ��� 1.5��
	//	else if (frame_cnt < 500)
	//		frame = frame * 0.5;	// ��� 0.5��

	//	put_string(frame, "frame_cnt", Point(20, 50), frame_cnt);
	//	imshow("������", frame);
	//}



	/// xml, yxml ������ ����
	// �����͸� �̹����� ������ �ƴ�, xml, yxml�� �����ϴ� ���
	// ������ ������ 1) DICTIONARY ��� - key:value �������� ���� 2) Sequence ��� - key(v1, v2, v3,...)
	//FileStorage fs("file/test.xml", FileStorage::WRITE);
	//string name = "ȫ�浿";
	//// key - value ������ �ֱ� 
	//fs << "name" << name;
	//fs << "age" << 21;
	//fs << "address" << "Chosun";

	//// SequenceŸ�� => []�� ����Ͽ� ���־��ֱ�
	//fs << "picture" << "[" << "pic1.jpg" << "pic2.jpg" << "pic3.jpg" << "]";

	//// DictionaryŸ�� => {}�� ����Ͽ� ���־��ֱ� 
	//fs << "score" << "{";
	//fs << "math" << 100;
	//fs << "Java" << 90;
	//fs << "C" << 95 << "}";
	////fs << "C++" << 95 << "}";			// error. '+'�� xml�� ��������� tag������ �� �� ���⶧��.

	//// vector�� ���� �� ����
	//int data[] = { 1, 2, 3, 4, 5,6 };
	//vector<int> vec(data, data + sizeof(data) / sizeof(int));
	//fs << "vector" << vec;

	//// matrix�� ���� �� ����
	//Mat m(2, 3, CV_32S, data);
	//fs << "Mat" << m;

	//// point, rect�� ���� �� ����
	//Point2d pt(10.5, 200);
	//Rect rect(pt, Size(100, 200));
	//fs << "Point" << pt;
	//fs << "Rect" << rect;

	//fs.release();


	/// xml, yxml ������ �б�
	//FileStorage fs("file/test.xml", FileStorage::READ);
	//CV_Assert(fs.isOpened());

	//string name, address, picture;
	//int age;
	//// �Ϲ� ������ �о���� - �Ϲ��ڷ��� ����
	//fs["address"] >> address;
	//fs["name"] >> name;
	//fs["age"] >> age;

	//cout << "address " << address << endl;
	//cout << "name " << name << endl;
	//cout << "age " << age << endl;

	//// ������, �� �ڷ�(���) �о���� - FileNode��ü
	//FileNode node_pic = fs["picture"];
	//FileNode node_score = fs["score"];

	//try {
	//	if (node_pic.type() != FileNode::SEQ)
	//		CV_Error(Error::StsError, "��������尡 �ƴմϴ�.");
	//	if (!node_score.isMap())
	//		CV_Error(Error::StsError, "���γ�尡 �ƴմϴ�.");
	//}
	//catch (Exception& e) {
	//	exit(1);
	//}

	//// ��������� �б� => []�� �ε���
	//cout << "[picture] ";
	//cout << (string)node_pic[0] << ", ";
	//cout << (string)node_pic[1] << ", ";
	//cout << (string)node_pic[2] << endl << endl;

	//// �ʳ�� �б� => []�� k-v �ҷ�����
	//cout << "[score] ";
	//cout << "math " << (int)node_score["math"];
	//cout << "Java " << (int)node_score["Java"];
	//cout << "C " << (int)node_score["C"] << endl << endl;

	//Point pt;
	//Rect rect;
	//Mat mat;
	//vector<int> vec;
	//fs["vector"] >> vec;
	//fs["Point"] >> pt;
	//fs["Rect"] >> rect;
	//fs["Mat"] >> mat;

	//cout << "[vec] = " << ((Mat)vec).t() << endl;
	//cout << "[pt] = " << pt << endl;
	//cout << "[rect] = " << rect << endl;
	//cout << "[mat] = " << endl << mat << endl;

	//fs.release();


	/// xml�� �̹��� �ҷ����� �Լ� ����ϱ�(���, ǥ������)
	//FileStorage fs_read("file/test.xml", FileStorage::READ);
	//CV_Assert(fs_read.isOpened());

	//FileNode node_pic = fs_read["picture"];
	//vector<Mat> images;
	//for (int i = 0; i < node_pic.size(); i++) {
	//	Mat tmp = imread("image/" + (string)node_pic[i], IMREAD_UNCHANGED);
	//	CV_Assert(tmp.data);
	//	images.push_back(tmp);
	//	imshow(node_pic[i], images[i]);
	//}

	//FileStorage fs_write("file/result.xml", FileStorage::WRITE);
	//CV_Assert(fs_write.isOpened());

	//vector<double> mean, dev;
	//for (int i = 0; i < images.size(); i++) {
	//	string pic_name = ((string)node_pic[i]).substr(0, 3);
	//	
	//	//meanStdDev: OpenCV���� �����ϴ�, ȭ�Ұ��� ��հ� ǥ�������� ���ͷ� ��ȯ�Ͽ� �����ϴ� �Լ�
	//	meanStdDev(images[i], mean, dev);
	//	fs_write << pic_name + "_mean" << "[";
	//	for (int j = 0; j < mean.size(); j++)
	//		fs_write << mean[j];
	//	fs_write << "]";
	//	fs_write << pic_name + "_dev" << dev;
	//}

	//waitKey();
	//fs_read.release();
	//fs_write.release();


	/// �̹��� ������ - ���� repeat(), ��ġ transpose(), ���� flip() 
	/* void cv::repeat	(	InputArray 	src,		// readonly => ��� �ڷ����� ���� �� �ִ� arrayŸ���� �ü� ����
							int 	ny,				// vertical�� ��� �����ϴ���
							int 	nx,				// horizontal�� ��� �����ϴ���
							OutputArray 	dst		// read&writable => ��� �ڷ����� ���� �� �ִ� arrayŸ���� �ü� ����
						)

	* void cv::flip	(	InputArray 	src,
						OutputArray 	dst,
						int 	flipCode			// 0: x����� ����, 1: y����� ����, (����):�������� ����
					)
	*/
	//Mat image = imread("image/bn1.jpg", IMREAD_COLOR);
	//CV_Assert(image.data);

	//Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
	//flip(image, x_axis, 0);		// 0 => x����� �ø�
	//flip(image, y_axis, 1);		// 1 => y��(���)���� �ø�
	//flip(image, xy_axis, -1);	// ���� => �������� �ø�
	//

	//// repaet : �������ֱ�
	//repeat(image, 1, 2, rep_img);
	//// transpose : ��ġ��� ������ֱ�
	//transpose(image, trans_img);

	//imshow("image", image);
	//imshow("x_axis", x_axis);
	//imshow("y_axis", y_axis);
	//imshow("xy_axis", xy_axis);
	//imshow("rep_img", rep_img);
	//imshow("trans_img", trans_img);
	//waitKey();


	/// ä�� - ��ġ�� merge(), ���� split() 
	// ����ä�� 3�� ch0, ch1, ch2
	//Mat ch0(3, 4, CV_8U, Scalar(10));
	//Mat ch1(3, 4, CV_8U, Scalar(20));
	//Mat ch2(3, 4, CV_8U, Scalar(30));

	//// 1ä�� 3���� ���ļ� 3ä�� 1�� �����
	//Mat bgr_arr[] = { ch0, ch1, ch2 };
	//Mat bgr_merge;
	//merge(bgr_arr, 3, bgr_merge);
	//// 3ä�� 1���� 1ä�� 3���� �����ϱ�
	//vector<Mat> bgr_split;
	//split(bgr_merge, bgr_split);

	//cout << "[ch0] = " << endl << ch0 << endl;
	//cout << "[ch1] = " << endl << ch1 << endl;
	//cout << "[ch2] = " << endl << ch2 << endl << endl;

	//cout << "[bgr_merge] = " << endl << bgr_merge << endl << endl;
	//cout << "[bgr_split[0]] = " << endl << bgr_split[0] << endl << endl;
	//cout << "[bgr_split[1]] = " << endl << bgr_split[1] << endl << endl;
	//cout << "[bgr_split[2]] = " << endl << bgr_split[2] << endl << endl;


	/// ���� �̹��� �и��غ���
	//Mat image = imread("image/bn1.jpg", IMREAD_COLOR);
	//CV_Assert(image.data);

	//Mat bgr[3];
	//split(image, bgr);

	//imshow("image", image);
	//imshow("blue channel", bgr[0]);
	//imshow("green channel", bgr[1]);
	//imshow("red channel", bgr[2]);
	//waitKey();


	/// ��ä�ο��� ����ä�� Ư���ؼ� �̱� - mixChannels()
	/* void cv::mixChannels	(	const Mat * 	src,		// ���� mat �ҽ� => ������. ��, �������� �迭�� �ü� ����(�׷��� �ؿ� �������)
								size_t			nsrcs,		// �ҽ��� �� mat ����
								Mat *			dst,		// ������� mat
								size_t			ndsts,		// ���mat�� ������ �׸񰳼�
								const int * 	fromTo,		// �̰��� ������� mix.  => ������ �ҽ�-Ÿ��-�ҽ�-Ÿ��... ������ ����
								size_t			npairs		// ä�ν� ����(�ҽ�-Ÿ�� ��)
							)
	 **/
	//Mat ch0(3, 4, CV_8U, Scalar(10));
	//Mat ch1(3, 4, CV_8U, Scalar(20));
	//Mat ch2(3, 4, CV_8U, Scalar(30));
	//Mat ch_012;		// 3ä�� matrix

	//vector<Mat> vec_012;
	//vec_012.push_back(ch0);
	//vec_012.push_back(ch1);
	//vec_012.push_back(ch2);
	//merge(vec_012, ch_012);
	//
	//Mat ch_13(ch_012.size(), CV_8UC2);	// ch_012�� ���� ������, 2ä��¥���� ��������,
	//Mat ch_2(ch_012.size(), CV_8UC1);   // 1ä��¥�� �� �� PARK
	//Mat out[] = { ch_13, ch_2 };

	//// *Ÿ�� out�� => ch_13�� ù��°ä�� + ch_13�� �ι�°ä��, ch_2(�� ù��°ä��) => �̷��� ������ \
	//   �ҽ�(ch_012)�� 0��° ä��(ch0, 10)�� Ÿ��(out)�� 0��° ä��(ch_13�� ù��°ä��)��, \
	//   �ҽ�(ch_012)�� 2��° ä��(ch2, 30)�� Ÿ��(out)�� 1��° ä��(ch_13�� �ι�°ä��)��, \
	//   �ҽ�(ch_012)�� 1��° ä��(ch1, 20)�� Ÿ��(out)�� 2��° ä��(ch_2)�� �ֱ�	 
	//int from_to[] = { 0, 0, 2, 1, 1, 2};
	//mixChannels(&ch_012, 1, out, 2, from_to, 3);

	//cout << "[ch_012] = " << endl << ch_012 << endl << endl;
	//cout << "[ch_13] = " << endl << ch_13 << endl;
	//cout << "[ch_2] = " << endl << ch_2 << endl;


	/// Matrix ��� - add(), sub(), divide(), mask
	//Mat m1(3, 6, CV_8UC1, Scalar(10));
	//Mat m2(3, 6, CV_8UC1, Scalar(50));

	//Mat m_add1, m_add2, m_sub, m_div1, m_div2;
	//Mat mask(m1.size(), CV_8UC1, Scalar(0));		// Mat mask(3, 6, CV_8UC1, Scalar(0));

	//Rect rect(Point(3, 0), Size(3, 3));
	//mask(rect).setTo(1);

	//add(m1, m2, m_add1);
	//// mask�ʵ� ä���ָ�, mask�� ���� 0�� �κ��� ������
	//add(m1, m2, m_add2, mask);

	//divide(m1, m2, m_div1);
	//m1.convertTo(m1, CV_32F);
	//m2.convertTo(m2, CV_32F);
	//divide(m1, m2, m_div2);

	//cout << "[m1] = " << endl << m1 << endl;
	//cout << "[m2] = " << endl << m2 << endl;
	//cout << "[mask] = " << endl << mask << endl << endl;

	//cout << "[m_add1] = " << endl << m_add1 << endl;
	//cout << "[m_add2] = " << endl << m_add2 << endl;
	//cout << "[m_div1] = " << endl << m_div1 << endl;
	//cout << "[m_div2] = " << endl << m_div2 << endl;



	/// matrix ��� - exp(), log(), sqrt(), pow()
	//vector<float> v1, v_exp, v_log;
	//Matx<float, 1, 5> m1(1, 2, 3, 5, 10);
	//Mat m_exp, m_sqrt, m_pow;
	//v1.push_back(1);
	//v1.push_back(2);
	//v1.push_back(3);

	//exp(v1, v_exp);	// e^1, e^2, e^3
	//exp(m1, m_exp);	
	//log(m1, v_log);	// 
	//sqrt(m1, m_sqrt);
	//pow(m1, 3, m_pow);

	//cout << "[m1] = " << m1 << endl << endl;
	//cout << "[v_exp] = " << ((Mat)v_exp).reshape(1, 1) << endl;
	//cout << "[m_exp] = " << m_exp << endl;
	//cout << "[v_log] = " << ((Mat)v_log).reshape(1, 1) << endl;
	//cout << "[m_sqrt] = " << m_sqrt << endl;
	//cout << "[m_pow] = " << m_pow << endl;



	/// �Ÿ� �� ���� ��� - magnitude(), phase(), cartToPolar(), polarToCart()
	//float data1[] = { 1, 2, 3, 5, 10 };
	//float data2[] = { 2, 5, 7, 2, 9 };
	//vector<float> x_vec(data1, data1 + sizeof(data1) / sizeof(float));
	//vector<float> y_vec(data2, data2 + sizeof(data2) / sizeof(float));

	//vector<float> v_mag, v_ang;
	//magnitude(x_vec, y_vec, v_mag);		// �Ÿ����
	//phase(x_vec, y_vec, v_ang, true);	// ���� ���(true: degree, flase: radian) => ����Ʈ�� false(radian)

	//Mat m_mag, m_ang, x_mat, y_mat;
	//// �� magnitude(), phase() �� �ѹ��� ���ִ� ���� cartToPolar()
	//cartToPolar(x_vec, y_vec, m_mag, m_ang);
	//// 
	//polarToCart(m_mag, m_ang, x_mat, y_mat, false); // ���⵵ ����Ʈ�� false(radian)

	//cout << "[x_vec] = " << ((Mat)x_vec).reshape(1, 1) << endl;
	//cout << "[y_vec] = " << ((Mat)y_vec).reshape(1, 1) << endl;
	//cout << "[v_mag] = " << ((Mat)v_mag).reshape(1, 1) << endl;
	//cout << "[v_ang] = " << ((Mat)v_ang).reshape(1, 1) << endl;

	//cout << "[m_mag] = " << m_mag << endl;
	//cout << "[m_ang] = " << m_ang << endl;
	//cout << "[x_mat] = " << x_mat << endl;
	//cout << "[y_mat] = " << y_mat << endl;



	/// ��Ʈ���� - bitwise_or(), 
	//Mat image1(300, 300, CV_8U, Scalar(0));
	//Mat image2(300, 300, CV_8U, Scalar(0));
	//Mat image3, image4, image5, image6;

	//Point center = image1.size() / 2;
	//circle(image1, center, 100, Scalar(100), -1);
	//rectangle(image2, Point(0, 0), Point(150, 300), Scalar(100), -1);

	//bitwise_or(image1, image2, image3);
	//bitwise_and(image1, image2, image4);
	//bitwise_xor(image1, image2, image5);
	//bitwise_not(image1, image6);

	//imshow("image1", image1);
	//imshow("image2", image2);
	//imshow("image3", image3);
	//imshow("image4", image4);
	//imshow("image5", image5);
	//imshow("image6", image6);
	//waitKey();



	/// �̹��� ���� - threshold() 
	/* double cv::threshold	(	InputArray 		src,
								OutputArray 	dst,
								double 			thresh,		// �̰��� �ȳ����� 0, ������ maxval������ ����
								double			maxval,
								int 			type
								)
	 *
	 *
	 */
	//Mat image = imread("image/bn3.jpg", IMREAD_COLOR);
	//Mat logo = imread("image/logo.jpg", IMREAD_COLOR);
	//Mat logo_th, masks[5], background, foreground, dst;
	//CV_Assert(image.data && logo.data);

	//// logo_th : 70�� ��������, ������ 0 ũ�� 255�� ����(THRESH_BINARY) => threshold, �� 0�ƴϸ�255������ �̺��Ѱ�
	//threshold(logo, logo_th, 70, 255, THRESH_BINARY);
	//split(logo_th, masks); // => masks[0] : b, masks[1] : g, masks[2] : r // masks[3]�� masks[4]�� �������

	//bitwise_or(masks[0], masks[1], masks[3]);
	//bitwise_or(masks[2], masks[3], masks[3]);			// masks[3] : bgr�� or���� => 3ä���� ��� ��ħ
	//bitwise_not(masks[3], masks[4]);					// masks[4] : masks[3]�� ���� => �ΰ�� ��� ������ ������

	//Point center1 = image.size() / 2;
	//Point center2 = logo.size() / 2;
	//Point start = center1 - center2;
	//Rect roi(start, logo.size());	

	//bitwise_and(logo, logo, foreground, masks[3]);
	//bitwise_and(image(roi), image(roi), background, masks[4]);

	//add(background, foreground, dst);
	//dst.copyTo(image(roi));

	//imshow("background", background);
	//imshow("foreground", foreground);
	//imshow("dst", dst);
	//imshow("image", image);
	//waitKey();


	/// 
	//uchar data[] = { 10, 200,   5,   7,   9,
	//				 15,  35,  60,  80, 170,
	//				 100,  2,  55,  37,  70 };
	//Mat m1(3, 5, CV_8U, data);
	//Mat m2(3, 5, CV_8U, Scalar(50));
	//Mat m_min, m_max;
	//double minVal, maxVal;
	//int minIdx[2] = {}, maxIdx[2] = {};
	//Point minLoc, maxLoc;


	//min(m1, 30, m_min);
	//max(m1, m2, m_max);
	//minMaxIdx(m1, &minVal, &maxVal, minIdx, maxIdx);
	//minMaxLoc(m1, 0, 0, &minLoc, &maxLoc);

	//cout << "[m1] = " << endl << m1 << endl;
	//cout << "[m_min] = " << endl << m_min << endl;
	//cout << "[m_max] = " << endl << m_max << endl << endl;

	//cout << "m1 ��� ���� �ּҰ�: " << minVal << endl;
	//cout << "m1 ��� ���� �ּҰ� ��ǥ:  " << minIdx[1] << ", " << minIdx[0] << endl;

	//cout << "m1 ��� ���� �ִ밪: " << maxVal << endl;
	//cout << "m1 ��� ���� �ִ밪 ��ǥ:  " << maxIdx[1] << ", " << maxIdx[0] << endl;

	//cout << "m1 ��� ���� �ּҰ� ��ǥ: " << minLoc << endl;
	//cout << "m1 ��� ���� �ִ밪 ��ǥ: " << maxLoc << endl;



	/// �̹��� ȭ�� �����ϱ�(������ ��ο� ���� �ʿ�)
	//Mat image = imread("image/minMax.jpg", IMREAD_GRAYSCALE);
	//double minVal, maxVal;
	//minMaxIdx(image, &minVal, &maxVal);

	//double ratio = (maxVal - minVal) / 255.0;
	//Mat dst = (image - minVal) / ratio*2;

	//cout << "�ּҰ� = " << minVal << endl;
	//cout << "�ִ밪 = " << maxVal << endl;

	//imshow("image", image);
	//imshow("dst", dst);
	//waitKey();


	/// ��� �������� - gemm()
	/* void cv::gemm	(	InputArray 	src1,
							InputArray 	src2,
							double 		alpha,
							InputArray 	src3,
							double 		beta,
							OutputArray dst,
							int 		flags = 0		// GEMM_1_T : src1�� ��ġ��ķ� �ٲ㼭 ���꿡 ������Ŵ
														// GEMM_2_T : src2�� ��ġ��ķ� �ٲ㼭 ���꿡 ������
						)
	 */
	//Matx23f	src1(1, 2, 3, 4, 5, 1);
	//Matx23f	src2(5, 4, 2, 3, 2, 1);
	//Matx32f	src3(5, 4, 2, 3, 2, 1);
	//Mat dst1, dst2, dst3;
	//double alpha = 1.0, beta = 1.0;

	//gemm(src1, src2, alpha, Mat(), beta, dst1, GEMM_1_T);		// Mat() : �� matrix
	//// dst1 = alpha*(src1)(src2) + beta*Mat();
	//gemm(src1, src2, alpha, noArray(), beta, dst2, GEMM_2_T);	// noArray()�� �� matrix�� �ǹ�.
	//gemm(src1, src3, alpha, noArray(), beta, dst3);

	//cout << "[src1] = " << endl << src1 << endl;
	//cout << "[src2] = " << endl << src2 << endl;
	//cout << "[src3] = " << endl << src3 << endl << endl;

	//cout << "[dst1] = " << endl << dst1 << endl;
	//cout << "[dst2] = " << endl << dst2 << endl;
	//cout << "[dst3] = " << endl << dst3 << endl;



	/// ��ǥ��ȯ - transform()
	/* void cv::transform  ( InputArray		src,
							 OutputArray	dst,
							 InputArray		m
							)
	 * void cv::line	   ( InputOutputArray 	img,
							 Point				pt1,
							 Point 				pt2,
							 const Scalar & 	color,
							 int				thickness = 1,
							 int 				lineType = LINE_8,
							 int				shift = 0
						   )
	 */
	//vector<Point> rect_pt1, rect_pt2;
	//rect_pt1.push_back(Point(200, 50));
	//rect_pt1.push_back(Point(400, 50));
	//rect_pt1.push_back(Point(400, 250));
	//rect_pt1.push_back(Point(200, 250));

	//float theta = 20 * CV_PI / 180;		// degree�� radian���� ��ȯ�ϴ� ����
	//Matx22f m(cos(theta), -sin(theta), sin(theta), cos(theta));
	//transform(rect_pt1, rect_pt2, m);	// m�� �������� ��Ʈ������ ��ȯ

	//Mat image(400, 500, CV_8UC3, Scalar(255, 255, 255));

	//for (int i = 0; i < 4; i++) {
	//	line(image, rect_pt1[i], rect_pt1[(i + 1) % 4], Scalar(0, 0, 0));
	//	line(image, rect_pt2[i], rect_pt2[(i + 1) % 4], Scalar(255, 0, 0));
	//	cout << "rect_pt1[" << to_string(i) + "] = " << rect_pt1[i] << "\t";
	//	cout << "rect_pt2[" << to_string(i) + "] = " << rect_pt2[i] << endl;
	//}

	//imshow("image", image);
	//waitKey();


	/// ����ó�� #1.
	// ����ó�� - ȭ��ó��, ����ó��, ������ó��(���¸� �̵�, ����) ��
	//Mat image1(50, 512, CV_8UC1, Scalar(0));
	//Mat image2(50, 512, CV_8UC1, Scalar(0));

	//for (int i = 0; i < image1.rows; i++) {
	//	for (int j = 0; j < image1.cols; j++) {
	//		image1.at<uchar>(i, j) = j / 2;			// �� ȭ�Ҹ��� ������ => ���������� ����
	//		image2.at<uchar>(i, j) = (j / 20) * 10;	// �������� Ư�������� ���� => �������� ����
	//	}
	//}

	//imshow("image1", image1);
	//imshow("image2", image2);
	//waitKey();


	/// ����ó�� - ��ο� �κа� �Ͼ�κ��� ��踦 ã�� roi�� ��� ȭ��Ȯ��
	//Mat image = imread("image/images.jpg", IMREAD_GRAYSCALE);
	//if (image.empty()) {		// cv_assert(image.data);
	//	cout << "���� �б� ����" << endl;
	//	exit(1);
	//}

	//Rect roi(50, 50, 20, 15);
	//Mat roi_img = image(roi);
	//cout << "[roi_img] = " << endl;
	//for (int i = 0; i < roi_img.rows; i++) {
	//	for (int j = 0; j < roi_img.cols; j++) {
	//		cout.width(5);
	//		cout << (int)roi_img.at<uchar>(i, j);
	//	}
	//	cout << endl;
	//}

	//rectangle(image, roi, Scalar(255), 1);
	//imshow("image", image);
	//waitKey();


	/// �̹��� �ռ� - saturate_cast Ȯ�� #1
	//Mat image = imread("image/images.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(!image.empty());

	//Mat dst1 = image + 100;		// �ܼ� ��� ���������� saturate_cast�� �Ͼ�� ����
	//Mat dst2 = image - 100;
	//Mat dst3 = 255 - image;

	//Mat dst4(image.size(), image.type());
	//Mat dst5(image.size(), image.type());
	//for (int i = 0; i < image.rows; i++) {
	//	for (int j = 0; j < image.cols; j++) {
	//		/*dst4.at<uchar>(i, j) = saturate_cast<uchar>(image.at<uchar>(i, j) + 100);*/
	//		dst4.at<uchar>(i, j) = image.at<uchar>(i, j) + 100;		// �����÷ο찡 �߻��ϸ� saturate_cast�� ���� ���� �����Ǳ⶧��
	//		dst5.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);
	//	}
	//}
	//imshow("Original", image);
	//imshow("dst1 - ���",  dst1);
	//imshow("dst2 - ��Ӱ�", dst2);
	//imshow("dst3 - ����", dst3);
	//imshow("dst4 - ���2", dst4);
	//imshow("dst5 - ����2", dst5);
	//waitKey();



	/// ����� �̿��� ���� �ռ� - saturate_cast Ȯ�� #2
	/* �ΰ��� ��� �� ����� saturate_cast�� ���� 255�� �Ѿ�� ���� ��� ������� ��Ÿ��
	 * �� ������ �ռ��� ����� ������� ����. �̸� �ذ��ϴ� ����� ������ ����
	 * 1) dst(y, x) = image(y, x) *0.5 + image2(y, x) *0.5
	 * 2) dst(y, x) = image1(y,) * alpha + image2(y, x) * (1-alpha)
	 * 3) dst(y, x) = image1(y, x) * alpha + image2(y, x) * beta
	 *
	 * void cv::addWeighted	(	InputArray 	src1,
								double 	alpha,
								InputArray 	src2,
								double 	beta,
`								double 	gamma,
								OutputArray 	dst,
								int 	dtype = -1 
							)	
	 */
	//Mat image1 = imread("image/add1.jpg", IMREAD_GRAYSCALE);
	//Mat image2 = imread("image/add2.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(!(image1.empty() || image2.empty()));

	//double alpha = 0.6, beta = 0.7;
	//Mat add_img1 = image1 + image2;
	//Mat add_img2 = image1 * 0.5 + image2 * 0.5;
	//Mat add_img3 = image1 * alpha + image2 * (1 - alpha);
	//
	//// alpha * image1 + beta * image2 => add_img4 with (gamma = 0, �����ϰ�) 
	//Mat add_img4;	
	//addWeighted(image1, alpha, image2, beta, 0, add_img4);

	//imshow("image1", image1);		// ��ü������ saturate_cast�ż� ���� ���
	//imshow("add_img1", add_img1);
	//imshow("add_img2", add_img2);
	//imshow("add_img3", add_img3);
	//imshow("add_img4", add_img4);
	//waitKey();


	/// �̹��� ó�� - ��ϴ�� contrast
	//Mat image = imread("image/menu2.jpg", IMREAD_COLOR);

	//// ���1. 
	//Mat dst1 = image * 0.5;		// contrast ����
	//Mat dst2 = image * 2.0;		// contrast ����

	//// ���2. -> ���1�� �ϸ� �� ��ĥ�� ������ �κ��� �־ ��հ��� �̿��Ͽ� ������ ���.
	//Scalar avg = mean(image) / 2.0;
	//Mat dst3 = image * 0.5 + avg[0];
	//Mat dst4 = image * 2.0 + avg[0];

	//imshow("image", image);
	//imshow("dst1-��񰨼�", dst1);
	//imshow("dst2-�������", dst2);
	//imshow("dst3-��񰨼�2", dst3);
	//imshow("dst4-�������2", dst4);
	//waitKey();


	/// �÷����� - color system�� ��� ������ 3���� ��ǥ�� ǥ���� ��
	// Color System(Color Model) -  (RGB, CMY(K), HSV, LAB, UYV ��)
	/* 1) RGB �÷����� 
		- �⺻ �÷�����
		- ����Ϳ��� �÷��� ǥ���ϱ� ���� ���(�� ���÷��̿�, Ƽ��, ����� ��)
		- ���� �����(���� ������� ��������), 
		- ����ȥ��(��ĥ���� �����)

	   2) CMY(K) �÷����� - Cyan(R�� ����), Magenta(G�� ����), Yellow(B�� ����)
		- �μ��⸦ �̿��� ���̿� ����ϱ� ���� �÷�����
		- ���� �����(���� ������� ��������), 
		- ����ȥ��(��ĥ���� ��ο���)
		** ����ͷ� ����(RGB)�� �����ͷ� ��� ����(CMY) => RGB���� CMY�� ��ȯ�ؾ���(�������� ��ȯ)
		
							 <*  RGB, CMY ��ȣ��ȯ  *>
						C = 255 - R	     =>		R = 255 - C
						M = 255 - G		 =>		G = 255 - M
						Y = 255 - B		 =>		B = 255 - Y
		- ���� ������� ��� ���ص� ��ũ�� �Ҽ��� ���� �������� ������ �������� ��������� ����. 
		  �̷��� ������ ���� �������� �߰��� CMYK�÷������� �Ϲ������� �����

		** CMY to CMYK
		black = min(Cyan, Magenta, Yellow)
		-> Cyan = Cyan - black
		-> Magenta = Magenta - black
		-> Yellow = Yellow - black

		3) HSI �÷�����
		- ����(Hue), ä��(Saturation), ��(Intensity)
		- �ΰ��� ������ �÷������� �����ϴ� ����� ������� ������ �÷�����

		4) ��Ÿ �÷�����
		- YCrCb, YUV, YUV420, BayerRGB, La*b*
	*/

	/// ȭ��ó�� - RGB���� CMY�� 
	//Mat BGR_img = imread("image/color_model.jpg", IMREAD_COLOR);
	//CV_Assert(BGR_img.data);

	//Scalar white(255, 255, 255);
	//Mat CMY_img = white - BGR_img;		// CMY = 255 - BGR (��������)
	//Mat CMY_arr[3];
	//split(CMY_img, CMY_arr);

	//// CMY color �״�θ� ����Ϳ����� ��� ������ ����غ���
	//imshow("BGR_img", BGR_img);
	//imshow("CMY_img", CMY_img);
	//imshow("Yellow", CMY_arr[0]);
	//imshow("Meganta", CMY_arr[1]);
	//imshow("Cyan", CMY_arr[2]);
	//waitKey();


	/// ȭ�� ó�� - RGB���� CMYK��
	//Mat BGR_img = imread("image/color_model.jpg", IMREAD_COLOR);
	//CV_Assert(BGR_img.data);

	//Scalar white(255, 255, 255);
	//Mat CMY_img = white - BGR_img;		// CMY = 255 - BGR (��������)
	//Mat CMY_arr[3];
	//split(CMY_img, CMY_arr);

	//Mat black;
	//min(CMY_arr[0], CMY_arr[1], black);
	//min(black, CMY_arr[2], black);
	//
	//CMY_arr[0] = CMY_arr[0] - black;
	//CMY_arr[1] = CMY_arr[1] - black;
	//CMY_arr[2] = CMY_arr[2] - black;
	//
	//imshow("black", black);
	//imshow("Yellow", CMY_arr[0]);
	//imshow("Meganta", CMY_arr[1]);
	//imshow("Cyan", CMY_arr[2]);
	//waitKey();


	///	ȭ�� ó��
	/* void cv::cvtColor (	InputArray 		src,
							OutputArray 	dst,
							int 			code,
							int 			dstCn = 0 
						 )
	 *
	 */
	//Mat BGR_img = imread("image/color_space.jpg", IMREAD_COLOR);
	//CV_Assert(BGR_img.data);

	//Mat HSI_img, HSV_img, hsi[3], hsv[3];

	//bgr2hsi(BGR_img, HSI_img);
	//// cvtColor : �츮�� ���� bgr2hsi�� ������ �ϵ��� OpenCV���� �̸� �����س��� �Լ� 
	//cvtColor(BGR_img, HSV_img, CV_BGR2HSV);
	//split(HSI_img, hsi);
	//split(HSV_img, hsv);

	//imshow("BGR_img", BGR_img);
	//imshow("Hue", hsi[0]);
	//imshow("Saturation", hsi[1]);
	//imshow("Intensity", hsi[2]);
	//imshow("OpenCV_Hue", hsv[0]);
	//imshow("OpenCV_Saturation", hsv[1]);
	//imshow("OpenCV_Value", hsv[2]);
	//waitKey();



	/// ����(domain) ó�� - Convolution 
	/* 
	 - spatial domain, area based processing
	 ������ ȭ��ó���� ȭ�Ұ� ������ ���ѿ��� ����
	 area based processing�� mask�� ������� ������ ���� �������.

	 # ����ũ��� ����ó��
		 ����ũ ���� ���Ұ��� ���� ������ �ִ� �Է� ������ ȭ�Ұ����� �����ǰ� ���Ͽ� ���ȭ�Ұ��� ���.
		 �̷��� ó���� �ϴ� ������ ��� ���ȭ�Ұ��� ���� �̵��ϸ鼭 �����ϴ� ���� Convolution�̶� ��. 
		 �̶� �Է¿��� �������� �� ����ũ�� Ŀ��(kernel), ������(window), �ʴ�(filter) ���� ���ε� ����.
		 ����ó�� �� -> ����, �������� �� -> Ŀ�� �� ���� �� (���翡�� �� �ο� ȥ��Ǿ�����)
		 -> ������ Ư�� ȭ�Ҹ� �����Ͽ� �ֺ� 9���� ȭ�ҵ��� �Բ� ����ũ�� ����Ͽ� ��� ȭ�Ұ����� �� -> �̰��� ��� ȭ�ҿ� ���� �����ϴ� ���� convolution

	 1) ����(blurring)
		 - ������ ��� �����ϸ鼭 �ణ �帮�� ó���ϴ� ��� -> ����
		 - ��ü������ �ε巯�� ������ ���� ����
		 => ���󿡼� ȭ�Ұ��� �ް��ϰ� ���ϴ� �κе��� ���ҽ��� ���������� ���ϰ� �ϴ� ��.
		 => ���⿡ ���Ǵ� mask�� �Ϲ������� 1/n ����(n�� mask�� ȭ�Ҽ�, �� 1/n * ȭ�Ҽ� = 1�� �Ǿ�� ��) 
			�� ���� 1�� ������, ��ü��Ⱚ�� �����ϰ� �Ǵ¼�.

	 2) ������(sharpening)

	 3) Edge ����
		 ����ó������ Edge�� ���� : ȭ�Ұ��� �ް��ϰ� ���ϴ� �κ�
		 - ���� ������
			3-1) ���п���: �̿��ϴ� ȭ���� ������ Ư�� �Ӱ谪 �̻��� ���� ã��
			3-2) 1�� �Ǵ� 2�� �̺� ����ũ �̿�
				-> �̺�: ȭ�Ұ��� �ް��ϰ� ���ϴ� ����(= Edge) -> ���Ⱑ ū �� -> �̺а��� ū ��
				<1��> Roberts, Prewitt, Sobel �� 
				<2��> ���ö�þ�, LoG(���ö�þ� of ����þ�), DoG(Difference of ����þ�) ���
			3-3) ���� ������ ���: �� ȭ�Ұ� �ڽ��� �ֺ� 9���� ȭ�ҵ�� ������ �� �� �ִ밪�� �����Ͽ� �ش� ȭ���� ������ ���� 
				-> Edge�� 0(���)���� ��ȯ�Ǵ� ���� �̿��Ͽ� Edge�� ����(���� �ܼ��� Edge ������)
				-> ȭ�Ҵ� ���� 8�� ����. ���������� ������ ����ǹǷ� ���ð��� ���� �ҿ�� 
			3-4) �������ڱ��
				-> ȭ�Ҵ� ���� 4�� ���� ���翬������ ���ð��� �����ɸ��� ������ �������ִ� ���
				
	 *
	 */

	/// ���� ó�� - ���� & ������
	//Mat	image = imread("image/menu3.jpg", IMREAD_GRAYSCALE);	
	//CV_Assert(image.data);

	//imshow("image", image);

	//// blurring
	//float data_blur[] = { 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f,
	//					  1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f,
	//					  1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f,
	//					  1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 
	//					  1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f,  1 / 40.f, 1 / 40.f };

	//Mat mask(5, 8, CV_32F, data_blur);			// data�� 1/9.f�� �����ϰ�, mask(3, 3, CV_32F, data)�� �� ������ �� �帮�� ����
	//Mat blur, sharpen1, sharpen2;	
	//filter(image, blur, mask);
	//blur.convertTo(blur, CV_8U);	
	//imshow("blur", blur);

	//// sharpening
	//float data_sharp1[] = { 0, -1,  0,
	//					   -1,  5, -1,
	//					    0, -1,  0 };
	//Mat mask_sh1(3, 3, CV_32F, data_sharp1);
	//filter(image, sharpen1, mask_sh1);
	//sharpen1.convertTo(sharpen1, CV_8U);
	//imshow("sharpen1", sharpen1);


	//float data_sharp2[] = { -1, -1, -1,
	//						-1, 9, -1,
	//						-1, -1, -1 };
	//Mat mask_sh2(3, 3, CV_32F, data_sharp2);
	//filter(image, sharpen2, mask_sh2);			// filter3D(image, sharpen2, mask_sh2); �� ����	
	//sharpen2.convertTo(sharpen2, CV_8U);
	//imshow("sharpen2", sharpen2);	

	//waitKey();


	
	/// ���� ó�� - Edge ����	(���� ������ ���, homogenOp())
	/*Mat image = imread("image/bn1.jpg", IMREAD_GRAYSCALE);
	CV_Assert(image.data);

	Mat edge;
	homogenOp(image, edge, 3);			// �ȼ��� 8�� �������

	imshow("image", image);
	imshow("edge", edge);
	waitKey();*/


	/// ���� ó�� - Edge ����(�� ������ ���, differOp())
	//Mat image = imread("image/bn1.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(image.data);

	//Mat edge;
	//differOp(image, edge, 3);			// homogenOp()�� ����� ����������, �ӵ��� ������(����Ƚ���� �پ��)
	//									// �ȼ��� 4�� �������
	//imshow("image", image);
	//imshow("edge", edge);
	//waitKey();


	/// ���� ó�� - Edge ����(�̺� ����ũ �̿�) 
	/* �̺�: ȭ�Ұ��� �ް��ϰ� ���ϴ� ����(= Edge) -> ���Ⱑ ū �� -> �̺а��� ū ��
	   Gx = f(x+1, y) - f(x, y) => (x, y)�������� x�������� Edge => �� ���� �������� (x,y)������ -1, (x+1, y)������ 1 �ִ� mask������
	   Gy = f(x, y+1) - f(x, y) => (x, y)�������� y�������� Edge => �� ���� �������� (x,y)������ -1, (x, y+1)������ 1 �ִ� mask������
	 */ 


	/// ���� ó�� - Edge ����(1���̺�) #1. Roberts
	//Mat image = imread("image/images.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(image.data);
	//
	//float data1[] = { -1, 0, 0,		// ��Edge ���� ���� ����ũ
	//				   0, 1, 0,
	//				   0, 0, 0 };

	//float data2[] = { 0, 0, -1,		// ��Edge ���� ���� ����ũ 
	//                  0, 1,  0,
	//			      0, 0,  0 };

	//Mat dst;
	//differential(image, dst, data1, data2);		// �� �ȿ��� magnitude()�� ��,�� ����ũ ��ħ

	//imshow("image", image);
	//imshow("Roberts", dst);
	//waitKey();
	

	/// ���� ó�� - Edge ����(1���̺�) #2. Prewitt
	//Mat image = imread("image/images.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(image.data);

	//float data1[] = { -1, 0, 1,		// ��Edge ���� ���� ����ũ
	//				   -1, 0, 1,
	//				   -1, 0, 1 };

	//float data2[] = { -1, -1, -1,		// ��Edge ���� ���� ����ũ 
	//				  0, 0,  0,
	//				  1, 1,  1 };

	//Mat dst;
	//differential(image, dst, data1, data2);		// �� �ȿ��� magnitude()�� ��,�� ����ũ ��ħ

	//imshow("image", image);
	//imshow("Prewitt", dst);
	//waitKey();


	/// ���� ó�� - Edge ����(1���̺�) #3. Sobel 
	// ���� ���� �Ϲ������� ����ϴ� ������
	/* �׷��� OpenCV ��ü���� Sobel()�� �����ϱ⵵ ��.
		void cv::Sobel	(	InputArray 		src,
							OutputArray 	dst,
							int 			ddepth,
							int 			dx,
							int 			dy,
							int 			ksize = 3,
							double			scale = 1,
							double 			delta = 0,
							int 			borderType = BORDER_DEFAULT 
						)	
	*/
	//Mat image = imread("image/bn3.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(image.data);

	//float data1[] = { -1, -2, -1,		// ��Edge ���� ���� ����ũ
	//				   0,  0,  0,
	//				   1,  2,  1 };

	//float data2[] = { 1,  0, -1,		// ��Edge ���� ���� ����ũ 
	//				  2,  0, -2,
	//				  1,  0, -1 };

	//Mat dst, dst3, dst4, dst5;
	//differential(image, dst, data1, data2);		// �� �ȿ��� magnitude()�� ��,�� ����ũ ��ħ

	//// OpenCV ���� Sobel()
	//Sobel(image, dst3, CV_32F, 1, 0);
	//Sobel(image, dst4, CV_32F, 0, 1);
	//magnitude(dst3, dst4, dst5);
	//dst5.convertTo(dst5, CV_8U);
	//convertScaleAbs(dst3, dst3);
	//convertScaleAbs(dst4, dst4);

	//imshow("image", image);
	//imshow("Sobel", dst);

	//imshow("dst3-OpenCV���� ��������ũ", dst3);
	//imshow("dst4-OpenCV���� ���򸶽�ũ", dst4);
	//imshow("dst5-OpenCV���� Sobel", dst5);
	//waitKey();


	/// ��������(Morphology)
	/* ������(Shape)
		1) ħ�Ŀ���(Erosion operation)
			��ü�� ũ��� ���(ħ��)�Ǵµ� ����� Ȯ���
			- Salt noise : ������� �� ������ ������
			- Papper noise : �Ͼ� ������ � ������ ������
			���� �� ���� ũ���� ���� ���� ȿ���� ���⵵ �Ѵ�(�� ����� �׻� ��� ���� ����ȿ���� ���°� �ƴϴ�)
			�⺻������ binary image(CV_8U => 0/255, CV_32f => 0/1)�� ���ȴ�

			ħ�Ŀ����� ���� mask�� ������ => 1���̻� ����ġ: 0, ��� ��ġ: 0	=> 1�� �Ǳ� �����(ħ��)

			<�Է¿���>	<3x3 ħ�� ����ũ>  =>  <��¿���>
			0 1 1 1 0		0 1 0			0 0
			0 1 1 1 0		1 1 1 
			1 1 1 0 1		0 1 0
			0 1 1 1 1 
			0 0 1 1 1 
			
			*����ũ ����� ������
			- 1�� �κи� ���꿡 �����Ѵ�(����ũ���� 0�κκ��� �Է¿����� �ش�ȭ�ҿ� �������� ����ġ���� ������ ����� ���Խ�Ű�� �ʾƾ���)
			- ��) �Է¿����� (0,0)ȭ�ҿ� ���� mask ���ﶧ 
					- (0,0)ȭ�ҿ� mask�� center�� ���߰� 
					- mask������ ��ġ�� �κ� �� mask���� 1�� �κи� ���꿡 ������Ų��
					- �� mask���� 1�� �κе��� �Է¿��󿡼��� 1�̸� 1, �ϳ��� �ƴϸ� 0���� (0,0)�� ä��� => ħ��(1�� �Ǳ� �����)
				<�Է¿���> <mask>	->	<���>
				 0 1		1 1			
				 0 1		1 0 

		2) ��â����(Dilation operation)
			��ü�� ũ��� ��â, ����� ���
			��ü ���ο� �� ������ ä����

			��â������ ���� mask�� ������ =>  1���̻� ��ġ: 1, ��� ����ġ: 0	=> 1�� �Ǳ� ����(��â)	

		3) ����, ���� ����
			3-1) ���� ����(Opening operation)
					ħ�� ���� => ��â ����
					ħ�� �������δ� ��ü�� ���, ���κ��� �̼��� ������ �����ϴ� �뵵�� ����ϰ�,
					��â �������� ���� ũ��� ���ͽ�Ű�� ���ҷ� �����
			3-2) ���� ����(Closing operation)
					��â ���� => ħ�� ����
					��â �������� ��ü�� Ȯ��, ��ü ���� �� ������ ä���,
					ħ�� �������� ���� ũ��� ���ͽ�Ŵ

	 */
	
	/// Morphology - ħ�Ŀ���
	//Mat image = imread("image/erosion.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(image.data);

	//Mat th_img, dst;
	//threshold(image, th_img, 128, 255, THRESH_BINARY);			// ���� binary image�� ������� for Morphology

	//uchar data[] = { 0, 1, 0, 
	//				   1, 1, 1, 
	//				   0, 1, 0 };
	//Mat mask(3, 3, CV_8UC1, data);
	//morphologyEx(th_img, dst, MORPH_ERODE, mask);

	//imshow("image", image);
	//imshow("���� ����", th_img);
	//imshow("Erosion", dst);
	//waitKey(0);


	/// Morphology - ��â����
	//Mat image = imread("image/bn3.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(image.data);

	//Mat th_img, dst;
	//threshold(image, th_img, 128, 255, THRESH_BINARY);			// ���� binary image�� ������� for Morphology

	//Matx <uchar, 3, 3> mask;		// ���� Mat mask ����� �Ͱ� ����
	//mask << 0, 1, 0,
	//	    1, 1, 1, 
	//	    0, 1, 0;

	//morphologyEx(th_img, dst, MORPH_DILATE, mask);

	//imshow("image", image);
	//imshow("���� ����", th_img);
	//imshow("Dilation", dst);
	//waitKey(0);


	return 0;
}

void onMouse(int event, int x, int y, int flags, void* userData) {
	switch (event) {
	case EVENT_LBUTTONDOWN :
		cout << "���콺 ���ʹ�ư ������--" << *(int*)userData << endl;
		break;
	case EVENT_RBUTTONDOWN:
		cout << "���콺 �����ʹ�ư ������--" << endl;
		break;
	case EVENT_RBUTTONUP:
		cout << "���콺 �����ʹ�ư ����--" << endl;
		break;
	case EVENT_LBUTTONDBLCLK:
		cout << "���콺 ���ʹ�ư ����Ŭ��" << endl;
		break;
	}
}
	
void onChange(int value, void* userData) {
	int add_value = value - 130;
	cout << "�߰� ȭ�Ұ�" << add_value << endl;

	Mat tmp = image + add_value;
	imshow(title, tmp);
}

void onMouse_tr(int event, int x, int y, int flags, void* userData) {
	if (event == EVENT_RBUTTONDOWN)
		image += 10;
		/*add(image, 10, image);	*/	
	else if (event == EVENT_LBUTTONDOWN)
		subtract(image, 10, image);
	setTrackbarPos(bar_name, title, image.at<uchar>(0, 0));
	imshow(title, image);
}

void onMouse_image(int event, int x, int y, int flags, void* userData) {
	static Point pt(-1, -1);
	switch (event) {
	case EVENT_LBUTTONDOWN:
		if (pt.x < 0) pt = Point(x, y);
		else {
			rectangle(image, pt, Point(x, y), Scalar(50), 2);
			imshow(title, image);
			pt = Point(-1, -1);
		}
		break;
	case EVENT_RBUTTONDOWN:
		if (pt.x < 0) pt = Point(x, y);
		else {
			Point2d pt2 = pt - Point(x, y);
			int radius = (int)sqrt(pt2.x * pt2.x + pt2.y * pt2.y);
			circle(image, pt, radius, Scalar(150), 2);
			imshow(title, image);
			pt = Point(-1, -1);
		}
		break;
	}
}

void print_matInfo(string name, Mat m) {
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

	cout << name << " ũ��  ";
	cout << format(": depth(%d) channels(%d) -> �ڷ���: ", m.depth(), m.channels());
	cout << mat_type << "C" << m.channels() << endl;
}

void put_string(Mat& frame, string text, Point pt, int value) {
	text += to_string(value);
	Point shade = pt + Point(2, 2);
	int font = FONT_HERSHEY_SIMPLEX;
	putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);
	putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);
}

void bgr2hsi(Mat img, Mat& hsi) {
	hsi = Mat(img.size(), CV_32FC3);
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			float B = img.at<Vec3b>(i, j)[0];
			float G = img.at<Vec3b>(i, j)[1];
			float R = img.at<Vec3b>(i, j)[2];
			
			float s = 1 - 3 * min(R, min(G, B)) / (R + G + B);
			float v = (R + G + B) / 3.0f;

			float tmp1 = ((R - G) + (R - B)) * 0.5f;
			float tmp2 = sqrt((R - G) + (R - B) + (G - B) * (G - B));
			float angle = acos(tmp1 / tmp2) * (180.f / CV_PI);
			float h = (B <= G) ? angle : 360 - angle;

			hsi.at<Vec3f>(i, j) = Vec3f(h / 2, s * 255, v);
		}
	}
	hsi.convertTo(hsi, CV_8U);
}

void filter(Mat img, Mat& dst, Mat mask) {
	dst = Mat(img.size(), CV_32F, Scalar(0));
	Point h_m = mask.size() / 2;
	for (int i = h_m.y; i < img.rows - h_m.y; i++) {
		for (int j = h_m.x; j < img.cols - h_m.x; j++) {
			float sum = 0; 
			for (int k = 0; k < mask.rows; k++) {
				for (int t = 0; t < mask.cols; t++) {
					int y = i + k - h_m.y;
					int x = j + t - h_m.x;
					sum += mask.at<float>(k, t) * img.at<uchar>(y, x);
				}
			}
			dst.at<float>(i, j) = sum;
		}
	}
}

void homogenOp(Mat img, Mat& dst, int mask_size) {
	dst = Mat(img.size(), CV_8U, Scalar(0));
	Point h_m(mask_size / 2, mask_size / 2);
	for (int i = h_m.y; i < img.rows - h_m.y; i++) {
		for (int j = h_m.x; j < img.cols - h_m.x; j++) {
			float max = 0;
			for (int k = 0; k < mask_size; k++) {
				for (int t = 0; t < mask_size; t++) {
					int y = i + k - h_m.y;
					int x = j + t - h_m.x;
					float diff = abs(img.at<uchar>(i, j) - img.at<uchar>(y, x));
					if (diff > max) 
						max = diff;
				}
			}
			dst.at<uchar>(i, j) = max;
		}
	}
}

void differOp(Mat img, Mat& dst, int mask_size) {
	dst = Mat(img.size(), CV_8U, Scalar(0));
	Point h_m(mask_size / 2, mask_size / 2);
	int mask_length = mask_size * mask_size;
	for (int i = h_m.y; i < img.rows - h_m.y; i++) {
		for (int j = h_m.x; j < img.cols - h_m.x; j++) {
			vector<uchar> mask(mask_length, 0);
			for (int k = 0, s = 0; k < mask_size; k++) {
				for (int t = 0; t < mask_size; t++, s++) {
					int y = i + k - h_m.y;
					int x = j + t - h_m.x;
					mask[s] = img.at<uchar>(y, x);
				}
			}
			uchar max = 0;
			for (int k = 0; k < mask_length / 2; k++) {
				int start = mask[k];
				int end = mask[mask_length - k - 1];

				uchar diff = abs(start - end);
				if (diff > max) max = diff;
			}

			dst.at<uchar>(i, j) = max;
		}
	}
}

void differential(Mat image, Mat& dst, float data1[], float data2[]) {
	Mat dst1, dst2;
	Mat mask1(3, 3, CV_32F, data1);
	Mat mask2(3, 3, CV_32F, data2);

	filter2D(image, dst1, CV_32F, mask1);
	filter2D(image, dst2, CV_32F, mask2);

	magnitude(dst1, dst2, dst);		// magnitude����: �Ÿ����ϱ� ����(sqrt(dst1^2, dst2^2))


	///* convertScaleAbs() 
	/*     1) abs() ���� 
		   2) ���� alpha*dst1 + beta(alpha, beta�� �μ��� ����,alpha = 1, beta = 0�� ����Ʈ)
		   3) CV_8U�� ����
	 */

	//dst1 = abs(dst1);
	//dst1.convertTo(dst1, CV_8U);
	convertScaleAbs(dst1, dst1);		 

	//dst2 = abs(dst2);
	//dst2.convertTo(dst2, CV_8U);
	convertScaleAbs(dst2, dst2);		

	dst.convertTo(dst, CV_8U);			

	imshow("��Edge ���� ����", dst1);
	imshow("��Edge ���� ����", dst2);
}