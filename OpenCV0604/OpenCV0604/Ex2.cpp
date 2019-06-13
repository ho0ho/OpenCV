#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

	/// 시험범위 : Chapter 03, 04(SparseMat 제외), 05(수업시간에 언급한 내용만), 06, 08, 10(수업시간에 언급한 내용만)
	// 각 함수의 사용법, 사용용도, 특징(단점, 개선점 등) 알아두기. 

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

string title = "트랙바 이벤트"; 
string title_image = "Event_Drawing";
string bar_name = "밝기변경";
Mat image;

int main() {

	/// 윈도우 설정 - namedWindow()
	/* void cv::namedWindow	(	const String & 	winname,
								int 			flags = WINDOW_AUTOSIZE 
							)	
		- flags 
		  WINDOW_AUTOSIZE:	윈도우 창 크기 변경불가
		  WINDOW_NORMAL:	윈도우 창 크기 변경가능

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

	//waitKey();	// default는 0
	//destroyAllWindows();


	/// 키보드 이벤트
	/*  int cv::waitKey(int delay = 0) : 0-9, Aa-Zz 외엔 키코드를 못받아옴
		- delay: ms단위. 0 is the special value that means "forever".

	*	int waitKeyEx(int delay = 0) : 키 이벤트발생시 해당키 값 반환
	*
	*/
	//Mat image(200, 300, CV_8U, Scalar(255));
	//namedWindow("키보드 이벤트", WINDOW_AUTOSIZE);
	//imshow("키보드 이벤트", image);

	//while (1) {
	//	int key = waitKeyEx(20);
	//	if (key == 27) // ESC
	//		break;
	//	switch (key) {
	//	case 'a': cout << "a 입력" << endl;
	//		break;
	//	case 'b': cout << "b 입력" << endl;
	//		break;
	//	case 0x41: cout << "A 입력" << endl;
	//		break;
	//	case 66: cout << "B 입력" << endl;
	//		break;
	//	case 2424832: cout << "왼쪽화살표 입력" << endl;
	//		break;
	//	case 2490368: cout << "위쪽화살표 입력" << endl;
	//		break;
	//	case 2555904: cout << "오른쪽화살표 입력" << endl;
	//		break;
	//	case 2621440: cout << "아래쪽화살표 입력" << endl;
	//		break;
	//	default:
	//		break;
	//	}
	//}


	/// 마우스 이벤트 - setMouseCallback()
	/* void cv::setMouseCallback	(	const String & 	winname,
										MouseCallback 	onMouse,	
										void * 	userdata = 0 
									)	
			- onMouse의 타입: MouseCallback 
			- typedef void (* cv::MouseCallback)(int event, int x, int y, int flags, void* userData) 
				=> 함수포인터				event	: 이벤트 종류(상수)
											x, y	: 이벤트 발생시의 마우스 좌표
											flags	: shift를 같이 눌렀다던가의 옵션을 지정할 때 사용하는 변수
											userData: 이벤트핸들러에 넘기고 싶은 데이터
	*/	
	//// Mat image(200, 300, CV_8U, Scalar(255));
	//Mat image(200, 300, CV_8U);
	//image.setTo(255);			

	//imshow("마우스이벤트1", image);
	//imshow("마우스이벤트2", image);
	//int a = 10;

	//setMouseCallback("마우스이벤트1", onMouse, &a);
	//waitKeyEx();


	/// 트랙바 이벤트  - createTrackbar() 
	/* int cv::createTrackbar	(	const String &		trackbarname,				// 트랙바명
									const String &		winname,					// 트랙바를 걸 윈도우명	
									int * 				value,						// 트랙바의 초기값
									int 				count,						// 트랙바의 최대값
									TrackbarCallback 	onChange = 0,				// 트랙바 메소드
									void * 				userdata = 0				// 트랙바로 넘길 사용자데이터
								)
	 * typedef void(* cv::TrackbarCallback) (	int		pos,						// 이벤트 발생시 트랙바의 값(위치)
												void *	userdata					
											)

	*/
	image = Mat(300, 500, CV_8UC1, Scalar(120));
	namedWindow(title, WINDOW_AUTOSIZE);

	// Trackbar Ex. #1
	int value = 130;
	createTrackbar("밝기값", title, &value, 255, onChange);

	// Trackbar Ex. #2
	createTrackbar(bar_name, title, &value, 255, onChange);
	setMouseCallback(title, onMouse_tr, 0);

	imshow(title, image);
	waitKey();


	/// Drawing - 그림그리기
	/*	line(), rectangle() 등
	*
	*/
	//Scalar blue(255, 0, 0), red(0, 0, 255), green(0, 255, 0);			// openCV에서는 BGR순서로 말함
	//Scalar white(255, 255, 255), yellow(0, 255, 255);
	//
	//Mat image(400, 600, CV_8UC3, white);
	//Point pt1(50, 130), pt2(200, 300), pt3(300, 150), pt4(400, 50);
	//Rect rect(pt3, Size(200, 150));

	//// line(image, 좌표값1, 좌표값2, 색깔, 두께, LineType, shift값)
	////		- LineType : FILLED, LINE_4, LINE_8, LINE_AA
	////		- shift :	1이면 값에 1/2효과 => 이동
	//line(image, pt1, pt2, red);
	//line(image, pt3, pt4, green, 2, LINE_AA);
	//line(image, pt3, pt4, green, 3, LINE_8, 1);

	//// rectangle
	////		- 
	//rectangle(image, rect, blue, 2);
	//rectangle(image, rect, blue, FILLED, LINE_4, 1);
	//rectangle(image, pt1, pt2, red, 3);

	//imshow("직선 사각형", image);
	//waitKey();


	/// Drawing - 글자넣기 
	/* putText() :
	*		- 매트릭스 image을 변경시키게 됨
	*
	*/
	//Scalar olive(128, 128, 0), violet(221, 160, 221), brown(42, 42, 165);
	//Point pt1(20, 100), pt2(20, 200), pt3(20, 250);

	//Mat image(300, 500, CV_8UC3, Scalar(255, 255, 255));

	//
	//putText(image, "SIMPLEX", Point(20, 30), FONT_HERSHEY_SIMPLEX, 1, brown);		// 매트릭스 image에 SIMPLEX라는 글자를 씀 -> 즉, image의 값이 변경된 것!
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

	//imshow("원", image);
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

	//// size(100, 60) : 가로세로 반지름 
	//// 0도부터 360도까지 orange 그리기 & 30도부터 270도까지 blue 그리기 
	//ellipse(image, pt1, Size(100, 60), 0, 0, 360, orange, 2);
	//ellipse(image, pt1, Size(100, 60), 0, 30, 270, blue, 4);

	//// 타원자체의 앵글을 30도로 기울게 그리고,
	//ellipse(image, pt2, Size(100, 60), 30, 0, 360, orange, 2);

	//// start < end : 시계방향으로 그리고,
	//// start > end : 반시계방향으로 그림.
	//ellipse(image, pt2, Size(100, 60), 30, -30, 160, blue, 4);
	/*ellipse(image, pt2, Size(100, 60), 30, 330, 160, blue, 4);*/

	//imshow("타원", image);
	//waitKey();



	/// Drawing - onMouse
	//image = Mat(300, 500, CV_8UC1, Scalar(255));
	//imshow(title, image);
	//setMouseCallback(title, onMouse_image, 0);

	//waitKey();


	/// 이미지 첨부하기 #1
	//// 프로젝트파일(OpenCV0604)의 루트디렉토리(.vcsproj이 있는 곳)에 images.jpg 세팅해놓고 경로 입력하기
	////String filename = "image/images.jpg";	// 흑백예제
	//String filename = "image/maxresdefault.jpg";	// 컬러예제

	//// 파일 filename을 흑백(IMREAD_GRAYSCALE)으로 읽어들이겠다
	//Mat gray2gray = imread(filename, IMREAD_GRAYSCALE);		// IMREAD_UNCHANGED 써도 동일함. 이것은 사진그대로를 가져오는 것
	//Mat gray2color = imread(filename, IMREAD_COLOR);
	//// mat객체의 data변수 => mat객체의 변수 gray2gray가 가리키는 실데이터가 없으면 이 값은 null이 되고, 있으면 non-null
	//CV_Assert(gray2gray.data && gray2color.data);

	//// Rect => left, top, width, height 
	//Rect roi(100, 100, 1, 1);	// 결국 화소 1개를 의미
	//cout << "행렬 좌표(100, 100)의 화소값" << endl;
	//cout << "gray2gray" << gray2gray(roi) << endl;
	//cout << "gray2color" << gray2color(roi) << endl;

	//print_matInfo("gray2gray", gray2gray);
	//print_matInfo("gray2color", gray2color);
	//imshow("gray2gray", gray2gray);
	//imshow("gray2color", gray2color);
	//waitKey();


	/// 이미지 첨부하기 #2
	//string filename1 = "image/example_16.tif";
	//string filename2 = "image/example_32.tif";

	//Mat color2unchanged1 = imread(filename1, IMREAD_UNCHANGED);
	//Mat color2unchanged2 = imread(filename2, IMREAD_UNCHANGED);

	///*CV_ASSERT(color2unchanged1.data && color2unchanged2.data);*/
	//CV_Assert(color2unchanged1.data);
	//CV_Assert(color2unchanged2.data);	

	//Rect roi(100, 100, 1, 1);
	//cout << "16/32비트 행렬좌표(100, 100) 화소값" << endl;
	//// 16U -> unsigned short. 0~2^15-1
	//cout << "color2unchanged1" << color2unchanged1(roi) << endl;	// color2unchanged1[30144, 33472, 33536]
	//// 32F -> 0이 검은색 1이 흰색. 0과 1사이의 값을 화면에 뿌릴땐 255로 나눠서 뿌림
	//cout << "color2unchanged2" << color2unchanged2(roi) << endl;	// color2unchanged2[0.59128636]

	//print_matInfo("color2unchanged1", color2unchanged1);		// depth(2) channels(3) -> 자료형: CV_16UC3
	//print_matInfo("color2unchanged2", color2unchanged2);		// depth(5) channels(1) -> 자료형: CV_32FC1

	//imshow("color2unchanged1", color2unchanged1);
	//imshow("color2unchanged2", color2unchanged2);
	//waitKey();



	/// 이미지 저장하기 - imwrite()
	//// imwrite() => 맨 첫인자로 파일명이 들어가는데, 이 파일명에 선언된 확장자대로 파일을 만든다.
	//Mat image = imread("image/maxresdefault.jpg", IMREAD_COLOR);
	//CV_Assert(image.data);

	//vector<int> params_jpg, params_png;

	//// 항목->값->... 순으로 세팅
	//// jpeg의 화질을 50으로 세팅
	//params_jpg.push_back(IMWRITE_JPEG_QUALITY);
	//params_jpg.push_back(50);

	//// 항목->값->... 순으로 세팅
	//// png의 압축률 = 9로 세팅(디폴트=3)
	//params_png.push_back(IMWRITE_PNG_COMPRESSION);
	//params_png.push_back(9);

	//imwrite("image/write_test1.jpg", image);
	//imwrite("image/write_test2.jpg", image, params_jpg);
	//		   
	//imwrite("image/write_test.png", image, params_png);
	//imwrite("image/write_test.bmp", image);



	/// 이미지 변환하기 - convertTo()
	//// 영역에 맞게 값 변환해줘야함
	//Mat img8 = imread("image/maxresdefault.jpg", IMREAD_COLOR);
	//CV_Assert(img8.data);

	//Mat img16, img32;
	//// 65535: 화소스케일(16bits), 32F는 0~1이므로 값을 분할
	//img8.convertTo(img16, CV_16U, 65535 / 255.0);
	//img8.convertTo(img32, CV_32F, 1 / 255.0f);

	//Rect roi(10, 10, 3, 3);
	//cout << "img8 행렬의 일부 " << endl << img8(roi) << endl << endl;
	//cout << "img16 행렬의 일부 " << endl << img16(roi) << endl << endl;
	//cout << "img32 행렬의 일부 " << endl << img32(roi) << endl << endl;

	//imwrite("image/write_test_16.tif", img16);
	//imwrite("image/write_test_32.tif", img32);

	//imshow("img16", img16);
	//imshow("img32", img32);
	//waitKey();



	/// 비디오 연결 - VideoCapture()
	//// - 카메라있는 컴퓨터에서 확인가능(노트북 등)	
	//VideoCapture capture(0);		// 연결되어 있는 첫번째 카메라장치 -> 보통은 이미 내장되어있는 카메라를 의미
	//if (!capture.isOpened()) {
	//	cout << "카메라가 연결되지 않았습니다." << endl;
	//	exit(1);
	//}

	//cout << "너비 " << capture.get(CAP_PROP_FRAME_WIDTH) << endl;
	//cout << "높이 " << capture.get(CAP_PROP_FRAME_HEIGHT) << endl;
	//cout << "노출 " << capture.get(CAP_PROP_EXPOSURE) << endl;
	//cout << "밝기 " << capture.get(CAP_PROP_BRIGHTNESS) << endl;

	//while (true) {
	//	Mat frame;
	//	capture.read(frame);

	//	put_string(frame, "EXPOS: ", Point(10, 40), capture.get(CAP_PROP_EXPOSURE));
	//	imshow("카메라 영상", frame);
	//	if (waitKey(30) >= 0) break;
	//}



	/// 비디오 연결 - VideoCapture() #2 
	//VideoCapture capture;
	//capture.open("image/video-sample.avi");
	//CV_Assert(capture.isOpened());

	//double fps = capture.get(CV_CAP_PROP_FPS);
	//int delay = 1000 / fps;
	//int frame_cnt = 0;
	//Mat frame;

	//while (capture.read(frame)) {
	//	if (waitKey(delay) >= 0) break;

	//	frame_cnt = capture.get(CV_CAP_PROP_POS_FRAMES);	// 현재의 프레임번호가 넘어옴
	//	if (frame_cnt < 100)
	//		;
	//	else if (frame_cnt < 200)
	//		frame -= Scalar(0, 0, 100);	// Red 100 감소
	//	else if (frame_cnt < 300)
	//		frame += Scalar(100, 0, 0);	// Blue 100 증가
	//	else if (frame_cnt < 400)
	//		frame = frame * 1.5;	// 밝기 1.5배
	//	else if (frame_cnt < 500)
	//		frame = frame * 0.5;	// 밝기 0.5배

	//	put_string(frame, "frame_cnt", Point(20, 50), frame_cnt);
	//	imshow("동영상", frame);
	//}



	/// xml, yxml 데이터 쓰기
	// 데이터를 이미지나 영상이 아닌, xml, yxml로 저장하는 방법
	// 데이터 저장방법 1) DICTIONARY 방법 - key:value 대응으로 저장 2) Sequence 방법 - key(v1, v2, v3,...)
	//FileStorage fs("file/test.xml", FileStorage::WRITE);
	//string name = "홍길동";
	//// key - value 순으로 넣기 
	//fs << "name" << name;
	//fs << "age" << 21;
	//fs << "address" << "Chosun";

	//// Sequence타입 => []를 명시하여 값넣어주기
	//fs << "picture" << "[" << "pic1.jpg" << "pic2.jpg" << "pic3.jpg" << "]";

	//// Dictionary타입 => {}를 명시하여 값넣어주기 
	//fs << "score" << "{";
	//fs << "math" << 100;
	//fs << "Java" << 90;
	//fs << "C" << 95 << "}";
	////fs << "C++" << 95 << "}";			// error. '+'는 xml로 만들어질때 tag값으로 들어갈 수 없기때문.

	//// vector도 넣을 수 있음
	//int data[] = { 1, 2, 3, 4, 5,6 };
	//vector<int> vec(data, data + sizeof(data) / sizeof(int));
	//fs << "vector" << vec;

	//// matrix도 넣을 수 있음
	//Mat m(2, 3, CV_32S, data);
	//fs << "Mat" << m;

	//// point, rect도 넣을 수 있음
	//Point2d pt(10.5, 200);
	//Rect rect(pt, Size(100, 200));
	//fs << "Point" << pt;
	//fs << "Rect" << rect;

	//fs.release();


	/// xml, yxml 데이터 읽기
	//FileStorage fs("file/test.xml", FileStorage::READ);
	//CV_Assert(fs.isOpened());

	//string name, address, picture;
	//int age;
	//// 일반 데이터 읽어오기 - 일반자료형 변수
	//fs["address"] >> address;
	//fs["name"] >> name;
	//fs["age"] >> age;

	//cout << "address " << address << endl;
	//cout << "name " << name << endl;
	//cout << "age " << age << endl;

	//// 시퀀스, 맵 자료(노드) 읽어오기 - FileNode객체
	//FileNode node_pic = fs["picture"];
	//FileNode node_score = fs["score"];

	//try {
	//	if (node_pic.type() != FileNode::SEQ)
	//		CV_Error(Error::StsError, "시퀸스노드가 아닙니다.");
	//	if (!node_score.isMap())
	//		CV_Error(Error::StsError, "매핑노드가 아닙니다.");
	//}
	//catch (Exception& e) {
	//	exit(1);
	//}

	//// 시퀀스노드 읽기 => []로 인덱싱
	//cout << "[picture] ";
	//cout << (string)node_pic[0] << ", ";
	//cout << (string)node_pic[1] << ", ";
	//cout << (string)node_pic[2] << endl << endl;

	//// 맵노드 읽기 => []로 k-v 불러오기
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


	/// xml로 이미지 불러오고 함수 사용하기(평균, 표준편차)
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
	//	//meanStdDev: OpenCV에서 제공하는, 화소값의 평균과 표준편차를 벡터로 변환하여 리턴하는 함수
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


	/// 이미지 갖고놀기 - 복제 repeat(), 전치 transpose(), 반전 flip() 
	/* void cv::repeat	(	InputArray 	src,		// readonly => 모든 자료형을 담을 수 있는 array타입이 올수 있음
							int 	ny,				// vertical로 몇번 복제하느냐
							int 	nx,				// horizontal로 몇번 복제하느냐
							OutputArray 	dst		// read&writable => 모든 자료형을 담을 수 있는 array타입이 올수 있음
						)

	* void cv::flip	(	InputArray 	src,
						OutputArray 	dst,
						int 	flipCode			// 0: x축기준 반전, 1: y축기준 반전, (음수):원전기준 반전
					)
	*/
	//Mat image = imread("image/bn1.jpg", IMREAD_COLOR);
	//CV_Assert(image.data);

	//Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
	//flip(image, x_axis, 0);		// 0 => x축기준 플립
	//flip(image, y_axis, 1);		// 1 => y축(양수)기준 플립
	//flip(image, xy_axis, -1);	// 음수 => 원점기준 플립
	//

	//// repaet : 복제해주기
	//repeat(image, 1, 2, rep_img);
	//// transpose : 전치행렬 만들어주기
	//transpose(image, trans_img);

	//imshow("image", image);
	//imshow("x_axis", x_axis);
	//imshow("y_axis", y_axis);
	//imshow("xy_axis", xy_axis);
	//imshow("rep_img", rep_img);
	//imshow("trans_img", trans_img);
	//waitKey();


	/// 채널 - 합치기 merge(), 분할 split() 
	// 단일채널 3개 ch0, ch1, ch2
	//Mat ch0(3, 4, CV_8U, Scalar(10));
	//Mat ch1(3, 4, CV_8U, Scalar(20));
	//Mat ch2(3, 4, CV_8U, Scalar(30));

	//// 1채널 3개를 합쳐서 3채널 1개 만들기
	//Mat bgr_arr[] = { ch0, ch1, ch2 };
	//Mat bgr_merge;
	//merge(bgr_arr, 3, bgr_merge);
	//// 3채널 1개를 1채널 3개로 분할하기
	//vector<Mat> bgr_split;
	//split(bgr_merge, bgr_split);

	//cout << "[ch0] = " << endl << ch0 << endl;
	//cout << "[ch1] = " << endl << ch1 << endl;
	//cout << "[ch2] = " << endl << ch2 << endl << endl;

	//cout << "[bgr_merge] = " << endl << bgr_merge << endl << endl;
	//cout << "[bgr_split[0]] = " << endl << bgr_split[0] << endl << endl;
	//cout << "[bgr_split[1]] = " << endl << bgr_split[1] << endl << endl;
	//cout << "[bgr_split[2]] = " << endl << bgr_split[2] << endl << endl;


	/// 실제 이미지 분리해보기
	//Mat image = imread("image/bn1.jpg", IMREAD_COLOR);
	//CV_Assert(image.data);

	//Mat bgr[3];
	//split(image, bgr);

	//imshow("image", image);
	//imshow("blue channel", bgr[0]);
	//imshow("green channel", bgr[1]);
	//imshow("red channel", bgr[2]);
	//waitKey();


	/// 다채널에서 임의채널 특정해서 뽑기 - mixChannels()
	/* void cv::mixChannels	(	const Mat * 	src,		// 뽑을 mat 소스 => 포인터. 즉, 여러개의 배열이 올수 있음(그래서 밑에 개수명시)
								size_t			nsrcs,		// 소스로 쓸 mat 개수
								Mat *			dst,		// 결과받을 mat
								size_t			ndsts,		// 결과mat가 가지는 항목개수
								const int * 	fromTo,		// 이것을 기반으로 mix.  => 순서는 소스-타겟-소스-타겟... 순으로 구성
								size_t			npairs		// 채널쌍 개수(소스-타겟 쌍)
							)
	 **/
	//Mat ch0(3, 4, CV_8U, Scalar(10));
	//Mat ch1(3, 4, CV_8U, Scalar(20));
	//Mat ch2(3, 4, CV_8U, Scalar(30));
	//Mat ch_012;		// 3채널 matrix

	//vector<Mat> vec_012;
	//vec_012.push_back(ch0);
	//vec_012.push_back(ch1);
	//vec_012.push_back(ch2);
	//merge(vec_012, ch_012);
	//
	//Mat ch_13(ch_012.size(), CV_8UC2);	// ch_012와 같은 사이즈, 2채널짜리로 만들어놓고,
	//Mat ch_2(ch_012.size(), CV_8UC1);   // 1채널짜리 선 애 PARK
	//Mat out[] = { ch_13, ch_2 };

	//// *타겟 out은 => ch_13의 첫번째채널 + ch_13의 두번째채널, ch_2(의 첫번째채널) => 이렇게 구성됨 \
	//   소스(ch_012)의 0번째 채널(ch0, 10)을 타겟(out)의 0번째 채널(ch_13의 첫번째채널)에, \
	//   소스(ch_012)의 2번째 채널(ch2, 30)을 타겟(out)의 1번째 채널(ch_13의 두번째채널)에, \
	//   소스(ch_012)의 1번째 채널(ch1, 20)을 타겟(out)의 2번째 채널(ch_2)에 넣기	 
	//int from_to[] = { 0, 0, 2, 1, 1, 2};
	//mixChannels(&ch_012, 1, out, 2, from_to, 3);

	//cout << "[ch_012] = " << endl << ch_012 << endl << endl;
	//cout << "[ch_13] = " << endl << ch_13 << endl;
	//cout << "[ch_2] = " << endl << ch_2 << endl;


	/// Matrix 계산 - add(), sub(), divide(), mask
	//Mat m1(3, 6, CV_8UC1, Scalar(10));
	//Mat m2(3, 6, CV_8UC1, Scalar(50));

	//Mat m_add1, m_add2, m_sub, m_div1, m_div2;
	//Mat mask(m1.size(), CV_8UC1, Scalar(0));		// Mat mask(3, 6, CV_8UC1, Scalar(0));

	//Rect rect(Point(3, 0), Size(3, 3));
	//mask(rect).setTo(1);

	//add(m1, m2, m_add1);
	//// mask필드 채워주면, mask의 값이 0인 부분을 계산안함
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



	/// matrix 계산 - exp(), log(), sqrt(), pow()
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



	/// 거리 및 각도 계산 - magnitude(), phase(), cartToPolar(), polarToCart()
	//float data1[] = { 1, 2, 3, 5, 10 };
	//float data2[] = { 2, 5, 7, 2, 9 };
	//vector<float> x_vec(data1, data1 + sizeof(data1) / sizeof(float));
	//vector<float> y_vec(data2, data2 + sizeof(data2) / sizeof(float));

	//vector<float> v_mag, v_ang;
	//magnitude(x_vec, y_vec, v_mag);		// 거리계산
	//phase(x_vec, y_vec, v_ang, true);	// 각도 계산(true: degree, flase: radian) => 디폴트는 false(radian)

	//Mat m_mag, m_ang, x_mat, y_mat;
	//// 위 magnitude(), phase() 를 한번에 해주는 연산 cartToPolar()
	//cartToPolar(x_vec, y_vec, m_mag, m_ang);
	//// 
	//polarToCart(m_mag, m_ang, x_mat, y_mat, false); // 여기도 디폴트는 false(radian)

	//cout << "[x_vec] = " << ((Mat)x_vec).reshape(1, 1) << endl;
	//cout << "[y_vec] = " << ((Mat)y_vec).reshape(1, 1) << endl;
	//cout << "[v_mag] = " << ((Mat)v_mag).reshape(1, 1) << endl;
	//cout << "[v_ang] = " << ((Mat)v_ang).reshape(1, 1) << endl;

	//cout << "[m_mag] = " << m_mag << endl;
	//cout << "[m_ang] = " << m_ang << endl;
	//cout << "[x_mat] = " << x_mat << endl;
	//cout << "[y_mat] = " << y_mat << endl;



	/// 비트연산 - bitwise_or(), 
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



	/// 이미지 연산 - threshold() 
	/* double cv::threshold	(	InputArray 		src,
								OutputArray 	dst,
								double 			thresh,		// 이값을 안넘으면 0, 넘으면 maxval값으로 설정
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

	//// logo_th : 70을 기준으로, 작으면 0 크면 255로 설정(THRESH_BINARY) => threshold, 즉 0아니면255값으로 이분한것
	//threshold(logo, logo_th, 70, 255, THRESH_BINARY);
	//split(logo_th, masks); // => masks[0] : b, masks[1] : g, masks[2] : r // masks[3]과 masks[4]는 비어있음

	//bitwise_or(masks[0], masks[1], masks[3]);
	//bitwise_or(masks[2], masks[3], masks[3]);			// masks[3] : bgr의 or연산 => 3채널을 모두 합침
	//bitwise_not(masks[3], masks[4]);					// masks[4] : masks[3]의 반전 => 로고는 흰색 바탕은 검은색

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

	//cout << "m1 행렬 원소 최소값: " << minVal << endl;
	//cout << "m1 행렬 원소 최소값 좌표:  " << minIdx[1] << ", " << minIdx[0] << endl;

	//cout << "m1 행렬 원소 최대값: " << maxVal << endl;
	//cout << "m1 행렬 원소 최대값 좌표:  " << maxIdx[1] << ", " << maxIdx[0] << endl;

	//cout << "m1 행렬 원소 최소값 좌표: " << minLoc << endl;
	//cout << "m1 행렬 원소 최대값 좌표: " << maxLoc << endl;



	/// 이미지 화질 개선하기(적당히 어두운 사진 필요)
	//Mat image = imread("image/minMax.jpg", IMREAD_GRAYSCALE);
	//double minVal, maxVal;
	//minMaxIdx(image, &minVal, &maxVal);

	//double ratio = (maxVal - minVal) / 255.0;
	//Mat dst = (image - minVal) / ratio*2;

	//cout << "최소값 = " << minVal << endl;
	//cout << "최대값 = " << maxVal << endl;

	//imshow("image", image);
	//imshow("dst", dst);
	//waitKey();


	/// 행렬 곱셈연산 - gemm()
	/* void cv::gemm	(	InputArray 	src1,
							InputArray 	src2,
							double 		alpha,
							InputArray 	src3,
							double 		beta,
							OutputArray dst,
							int 		flags = 0		// GEMM_1_T : src1을 전치행렬로 바꿔서 연산에 참여시킴
														// GEMM_2_T : src2를 전치행렬로 바꿔서 연산에 참여시
						)
	 */
	//Matx23f	src1(1, 2, 3, 4, 5, 1);
	//Matx23f	src2(5, 4, 2, 3, 2, 1);
	//Matx32f	src3(5, 4, 2, 3, 2, 1);
	//Mat dst1, dst2, dst3;
	//double alpha = 1.0, beta = 1.0;

	//gemm(src1, src2, alpha, Mat(), beta, dst1, GEMM_1_T);		// Mat() : 빈 matrix
	//// dst1 = alpha*(src1)(src2) + beta*Mat();
	//gemm(src1, src2, alpha, noArray(), beta, dst2, GEMM_2_T);	// noArray()도 빈 matrix를 의미.
	//gemm(src1, src3, alpha, noArray(), beta, dst3);

	//cout << "[src1] = " << endl << src1 << endl;
	//cout << "[src2] = " << endl << src2 << endl;
	//cout << "[src3] = " << endl << src3 << endl << endl;

	//cout << "[dst1] = " << endl << dst1 << endl;
	//cout << "[dst2] = " << endl << dst2 << endl;
	//cout << "[dst3] = " << endl << dst3 << endl;



	/// 좌표변환 - transform()
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

	//float theta = 20 * CV_PI / 180;		// degree를 radian으로 변환하는 공식
	//Matx22f m(cos(theta), -sin(theta), sin(theta), cos(theta));
	//transform(rect_pt1, rect_pt2, m);	// m을 기준으로 매트릭스를 변환

	//Mat image(400, 500, CV_8UC3, Scalar(255, 255, 255));

	//for (int i = 0; i < 4; i++) {
	//	line(image, rect_pt1[i], rect_pt1[(i + 1) % 4], Scalar(0, 0, 0));
	//	line(image, rect_pt2[i], rect_pt2[(i + 1) % 4], Scalar(255, 0, 0));
	//	cout << "rect_pt1[" << to_string(i) + "] = " << rect_pt1[i] << "\t";
	//	cout << "rect_pt2[" << to_string(i) + "] = " << rect_pt2[i] << endl;
	//}

	//imshow("image", image);
	//waitKey();


	/// 영상처리 #1.
	// 영상처리 - 화소처리, 영역처리, 기하학처리(형태를 이동, 변형) 등
	//Mat image1(50, 512, CV_8UC1, Scalar(0));
	//Mat image2(50, 512, CV_8UC1, Scalar(0));

	//for (int i = 0; i < image1.rows; i++) {
	//	for (int j = 0; j < image1.cols; j++) {
	//		image1.at<uchar>(i, j) = j / 2;			// 각 화소마다 값변형 => 연속적으로 변형
	//		image2.at<uchar>(i, j) = (j / 20) * 10;	// 구간별로 특정값으로 변형 => 구간별로 변형
	//	}
	//}

	//imshow("image1", image1);
	//imshow("image2", image2);
	//waitKey();


	/// 영상처리 - 어두운 부분과 하얀부분의 경계를 찾아 roi로 잡고 화소확인
	//Mat image = imread("image/images.jpg", IMREAD_GRAYSCALE);
	//if (image.empty()) {		// cv_assert(image.data);
	//	cout << "영상 읽기 실패" << endl;
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


	/// 이미지 합성 - saturate_cast 확인 #1
	//Mat image = imread("image/images.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(!image.empty());

	//Mat dst1 = image + 100;		// 단순 행렬 덧셈에서는 saturate_cast가 일어나지 않음
	//Mat dst2 = image - 100;
	//Mat dst3 = 255 - image;

	//Mat dst4(image.size(), image.type());
	//Mat dst5(image.size(), image.type());
	//for (int i = 0; i < image.rows; i++) {
	//	for (int j = 0; j < image.cols; j++) {
	//		/*dst4.at<uchar>(i, j) = saturate_cast<uchar>(image.at<uchar>(i, j) + 100);*/
	//		dst4.at<uchar>(i, j) = image.at<uchar>(i, j) + 100;		// 오버플로우가 발생하면 saturate_cast에 의해 값이 조정되기때문
	//		dst5.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);
	//	}
	//}
	//imshow("Original", image);
	//imshow("dst1 - 밝게",  dst1);
	//imshow("dst2 - 어둡게", dst2);
	//imshow("dst3 - 반전", dst3);
	//imshow("dst4 - 밝게2", dst4);
	//imshow("dst5 - 반전2", dst5);
	//waitKey();



	/// 행렬을 이용한 영상 합성 - saturate_cast 확인 #2
	/* 두개의 행렬 합 연산시 saturate_cast로 인해 255를 넘어서는 값은 모두 흰색으로 나타남
	 * 이 때문에 합성이 제대로 수행되지 않음. 이를 해결하는 방법은 다음과 가은
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
	//// alpha * image1 + beta * image2 => add_img4 with (gamma = 0, 스케일값) 
	//Mat add_img4;	
	//addWeighted(image1, alpha, image2, beta, 0, add_img4);

	//imshow("image1", image1);		// 자체적으로 saturate_cast돼서 나온 결과
	//imshow("add_img1", add_img1);
	//imshow("add_img2", add_img2);
	//imshow("add_img3", add_img3);
	//imshow("add_img4", add_img4);
	//waitKey();


	/// 이미지 처리 - 명암대비 contrast
	//Mat image = imread("image/menu2.jpg", IMREAD_COLOR);

	//// 방법1. 
	//Mat dst1 = image * 0.5;		// contrast 감소
	//Mat dst2 = image * 2.0;		// contrast 증가

	//// 방법2. -> 방법1로 하면 좀 거칠게 나오는 부분이 있어서 평균값을 이용하여 개선한 방법.
	//Scalar avg = mean(image) / 2.0;
	//Mat dst3 = image * 0.5 + avg[0];
	//Mat dst4 = image * 2.0 + avg[0];

	//imshow("image", image);
	//imshow("dst1-대비감소", dst1);
	//imshow("dst2-대비증가", dst2);
	//imshow("dst3-대비감소2", dst3);
	//imshow("dst4-대비증가2", dst4);
	//waitKey();


	/// 컬러공간 - color system의 모든 색들을 3차원 좌표로 표현한 것
	// Color System(Color Model) -  (RGB, CMY(K), HSV, LAB, UYV 등)
	/* 1) RGB 컬러공간 
		- 기본 컬러공간
		- 모니터에서 컬러를 표시하기 위해 사용(즉 디스플레이용, 티비, 모니터 등)
		- 빛의 삼원색(색의 삼원색과 보색관계), 
		- 가산혼합(합칠수록 밝아짐)

	   2) CMY(K) 컬러공간 - Cyan(R의 보색), Magenta(G의 보색), Yellow(B의 보색)
		- 인쇄기기를 이용해 종이에 출력하기 위한 컬러공간
		- 색의 삼원색(빛의 삼원색과 보색관계), 
		- 감산혼합(합칠수록 어두워짐)
		** 모니터로 본것(RGB)을 프린터로 찍고 싶음(CMY) => RGB에서 CMY로 변환해야함(보색으로 변환)
		
							 <*  RGB, CMY 상호변환  *>
						C = 255 - R	     =>		R = 255 - C
						M = 255 - G		 =>		G = 255 - M
						Y = 255 - B		 =>		B = 255 - Y
		- 색의 삼원색을 모두 합해도 잉크의 불순물 등의 영향으로 순수한 검은색이 만들어지지 않음. 
		  이러한 이유로 순수 검은색을 추가한 CMYK컬러공간을 일반적으로 사용함

		** CMY to CMYK
		black = min(Cyan, Magenta, Yellow)
		-> Cyan = Cyan - black
		-> Magenta = Magenta - black
		-> Yellow = Yellow - black

		3) HSI 컬러공간
		- 색상(Hue), 채도(Saturation), 명도(Intensity)
		- 인간의 눈에서 컬러정보를 인지하는 방법을 기반으로 구성된 컬러공간

		4) 기타 컬러공간
		- YCrCb, YUV, YUV420, BayerRGB, La*b*
	*/

	/// 화소처리 - RGB에서 CMY로 
	//Mat BGR_img = imread("image/color_model.jpg", IMREAD_COLOR);
	//CV_Assert(BGR_img.data);

	//Scalar white(255, 255, 255);
	//Mat CMY_img = white - BGR_img;		// CMY = 255 - BGR (보색관계)
	//Mat CMY_arr[3];
	//split(CMY_img, CMY_arr);

	//// CMY color 그대로를 모니터에서는 어떻게 보일지 출력해보기
	//imshow("BGR_img", BGR_img);
	//imshow("CMY_img", CMY_img);
	//imshow("Yellow", CMY_arr[0]);
	//imshow("Meganta", CMY_arr[1]);
	//imshow("Cyan", CMY_arr[2]);
	//waitKey();


	/// 화소 처리 - RGB에서 CMYK로
	//Mat BGR_img = imread("image/color_model.jpg", IMREAD_COLOR);
	//CV_Assert(BGR_img.data);

	//Scalar white(255, 255, 255);
	//Mat CMY_img = white - BGR_img;		// CMY = 255 - BGR (보색관계)
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


	///	화소 처리
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
	//// cvtColor : 우리가 만든 bgr2hsi의 역할을 하도록 OpenCV에서 미리 구현해놓은 함수 
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



	/// 영역(domain) 처리 - Convolution 
	/* 
	 - spatial domain, area based processing
	 기존의 화소처리는 화소값 각각에 대한연산 수행
	 area based processing는 mask를 기반으로 영역에 대한 연산수행.

	 # 마스크기반 영역처리
		 마스크 내의 원소값과 공간 영역에 있는 입력 영상의 화소값들을 대응되게 곱하여 출력화소값을 계산.
		 이러한 처리를 하는 과정을 모든 출력화소값에 대해 이동하면서 수행하는 것을 Convolution이라 함. 
		 이때 입력영상에 곱해지는 이 마스크는 커널(kernel), 윈도우(window), 필더(filter) 등의 용어로도 사용됨.
		 영상처리 쪽 -> 필터, 순수수학 쪽 -> 커널 용어를 많이 씀 (교재에는 이 두용어가 혼재되어있음)
		 -> 각각의 특정 화소를 포함하여 주변 9개의 화소들을 함께 마스크와 계산하여 가운데 화소값으로 줌 -> 이것을 모든 화소에 대해 수행하는 것이 convolution

	 1) 블러링(blurring)
		 - 영상을 밝게 수정하면서 약간 흐리게 처리하는 기법 -> 포샵
		 - 전체적으로 부드러운 느낌이 나게 만듦
		 => 영상에서 화소값이 급격하게 변하는 부분들을 감소시켜 점진적으로 변하게 하는 것.
		 => 여기에 사용되는 mask는 일반적으로 1/n 형식(n은 mask의 화소수, 즉 1/n * 화소수 = 1이 되어야 함) 
			이 값이 1이 넘으면, 전체밝기값이 증가하게 되는셈.

	 2) 샤프닝(sharpening)

	 3) Edge 검출
		 영상처리에서 Edge의 정의 : 화소값이 급격하게 변하는 부분
		 - 엣지 검출방법
			3-1) 차분연산: 이웃하는 화소의 차분이 특정 임계값 이상인 지점 찾기
			3-2) 1차 또는 2차 미분 마스크 이용
				-> 미분: 화소값이 급격하게 변하는 지점(= Edge) -> 기울기가 큰 곳 -> 미분값이 큰 곳
				<1차> Roberts, Prewitt, Sobel 등 
				<2차> 라플라시안, LoG(라플라시안 of 가우시안), DoG(Difference of 가우시안) 기법
			3-3) 유사 연산자 기법: 각 화소가 자신의 주변 9개의 화소들과 감산한 값 중 최대값을 결정하여 해당 화소의 값으로 결정 
				-> Edge만 0(흰색)으로 변환되는 것을 이용하여 Edge를 검출(가장 단순한 Edge 검출방법)
				-> 화소당 뺄셈 8번 수행. 뺄셈연산이 여러번 수행되므로 계산시간이 많이 소요됨 
			3-4) 차연산자기법
				-> 화소당 뺄셈 4번 수행 유사연산자의 계산시간이 오래걸리는 단점을 보안해주는 방법
				
	 *
	 */

	/// 영역 처리 - 블러링 & 샤프닝
	//Mat	image = imread("image/menu3.jpg", IMREAD_GRAYSCALE);	
	//CV_Assert(image.data);

	//imshow("image", image);

	//// blurring
	//float data_blur[] = { 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f,
	//					  1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f,
	//					  1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f,
	//					  1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 
	//					  1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f, 1 / 40.f,  1 / 40.f, 1 / 40.f };

	//Mat mask(5, 8, CV_32F, data_blur);			// data를 1/9.f로 세팅하고, mask(3, 3, CV_32F, data)로 할 때보다 더 흐리게 나옴
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
	//filter(image, sharpen2, mask_sh2);			// filter3D(image, sharpen2, mask_sh2); 와 동일	
	//sharpen2.convertTo(sharpen2, CV_8U);
	//imshow("sharpen2", sharpen2);	

	//waitKey();


	
	/// 영역 처리 - Edge 검출	(유사 연산자 기법, homogenOp())
	/*Mat image = imread("image/bn1.jpg", IMREAD_GRAYSCALE);
	CV_Assert(image.data);

	Mat edge;
	homogenOp(image, edge, 3);			// 픽셀당 8번 연산수행

	imshow("image", image);
	imshow("edge", edge);
	waitKey();*/


	/// 영역 처리 - Edge 검출(차 연산자 기법, differOp())
	//Mat image = imread("image/bn1.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(image.data);

	//Mat edge;
	//differOp(image, edge, 3);			// homogenOp()와 결과는 유사하지만, 속도는 빨라짐(연산횟수가 줄어듦)
	//									// 픽셀당 4번 연산수행
	//imshow("image", image);
	//imshow("edge", edge);
	//waitKey();


	/// 영역 처리 - Edge 검출(미분 마스크 이용) 
	/* 미분: 화소값이 급격하게 변하는 지점(= Edge) -> 기울기가 큰 곳 -> 미분값이 큰 곳
	   Gx = f(x+1, y) - f(x, y) => (x, y)지점에서 x축으로의 Edge => 이 식이 나오려면 (x,y)지점엔 -1, (x+1, y)지점엔 1 있는 mask여야함
	   Gy = f(x, y+1) - f(x, y) => (x, y)지점에서 y축으로의 Edge => 이 식이 나오려면 (x,y)지점엔 -1, (x, y+1)지점엔 1 있는 mask여야함
	 */ 


	/// 영역 처리 - Edge 검출(1차미분) #1. Roberts
	//Mat image = imread("image/images.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(image.data);
	//
	//float data1[] = { -1, 0, 0,		// 행Edge 위주 검출 마스크
	//				   0, 1, 0,
	//				   0, 0, 0 };

	//float data2[] = { 0, 0, -1,		// 열Edge 위주 검출 마스크 
	//                  0, 1,  0,
	//			      0, 0,  0 };

	//Mat dst;
	//differential(image, dst, data1, data2);		// 이 안에서 magnitude()로 행,열 마스크 합침

	//imshow("image", image);
	//imshow("Roberts", dst);
	//waitKey();
	

	/// 영역 처리 - Edge 검출(1차미분) #2. Prewitt
	//Mat image = imread("image/images.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(image.data);

	//float data1[] = { -1, 0, 1,		// 행Edge 위주 검출 마스크
	//				   -1, 0, 1,
	//				   -1, 0, 1 };

	//float data2[] = { -1, -1, -1,		// 열Edge 위주 검출 마스크 
	//				  0, 0,  0,
	//				  1, 1,  1 };

	//Mat dst;
	//differential(image, dst, data1, data2);		// 이 안에서 magnitude()로 행,열 마스크 합침

	//imshow("image", image);
	//imshow("Prewitt", dst);
	//waitKey();


	/// 영역 처리 - Edge 검출(1차미분) #3. Sobel 
	// 가장 많이 일반적으로 사용하는 검출방식
	/* 그래서 OpenCV 자체에서 Sobel()를 제공하기도 함.
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

	//float data1[] = { -1, -2, -1,		// 행Edge 위주 검출 마스크
	//				   0,  0,  0,
	//				   1,  2,  1 };

	//float data2[] = { 1,  0, -1,		// 열Edge 위주 검출 마스크 
	//				  2,  0, -2,
	//				  1,  0, -1 };

	//Mat dst, dst3, dst4, dst5;
	//differential(image, dst, data1, data2);		// 이 안에서 magnitude()로 행,열 마스크 합침

	//// OpenCV 제공 Sobel()
	//Sobel(image, dst3, CV_32F, 1, 0);
	//Sobel(image, dst4, CV_32F, 0, 1);
	//magnitude(dst3, dst4, dst5);
	//dst5.convertTo(dst5, CV_8U);
	//convertScaleAbs(dst3, dst3);
	//convertScaleAbs(dst4, dst4);

	//imshow("image", image);
	//imshow("Sobel", dst);

	//imshow("dst3-OpenCV제공 수직마스크", dst3);
	//imshow("dst4-OpenCV제공 수평마스크", dst4);
	//imshow("dst5-OpenCV제공 Sobel", dst5);
	//waitKey();


	/// 모폴로지(Morphology)
	/* 형태학(Shape)
		1) 침식연산(Erosion operation)
			객체의 크기는 축소(침식)되는데 배경은 확대됨
			- Salt noise : 까만바탕에 흰 잡음이 쩜쩜쩜
			- Papper noise : 하얀 바탕에 까만 잡음이 쩜쩜쩜
			영상 내 작은 크기의 잡음 제거 효과를 내기도 한다(이 방법이 항상 모든 잡음 제거효과를 내는건 아니다)
			기본적으로 binary image(CV_8U => 0/255, CV_32f => 0/1)에 사용된다

			침식연산을 위한 mask의 연산방식 => 1개이상 불일치: 0, 모두 일치: 0	=> 1이 되기 어려움(침식)

			<입력영상>	<3x3 침식 마스크>  =>  <출력영상>
			0 1 1 1 0		0 1 0			0 0
			0 1 1 1 0		1 1 1 
			1 1 1 0 1		0 1 0
			0 1 1 1 1 
			0 0 1 1 1 
			
			*마스크 연산시 주의점
			- 1인 부분만 연산에 참여한다(마스크에서 0인부분이 입력영상의 해당화소와 비교했을때 불일치더라도 연산의 결과로 포함시키지 않아야함)
			- 예) 입력영상의 (0,0)화소에 대해 mask 씌울때 
					- (0,0)화소에 mask의 center를 맞추고 
					- mask영역에 겹치는 부분 중 mask값에 1인 부분만 연산에 참여시킨다
					- 즉 mask값이 1인 부분들이 입력영상에서도 1이면 1, 하나라도 아니면 0으로 (0,0)을 채운다 => 침식(1이 되기 어려움)
				<입력영상> <mask>	->	<출력>
				 0 1		1 1			
				 0 1		1 0 

		2) 팽창연산(Dilation operation)
			객체의 크기는 팽창, 배경은 춧고
			객체 내부에 빈 공간이 채워짐

			팽창연산을 위한 mask의 연산방식 =>  1개이상 일치: 1, 모두 불일치: 0	=> 1이 되기 쉬움(팽창)	

		3) 열림, 닫힘 연삼
			3-1) 열림 연산(Opening operation)
					침식 연산 => 팽창 연산
					침식 연산으로는 객체는 축소, 배경부분의 미세한 잡음을 제거하는 용도로 사용하고,
					팽창 연산으로 원래 크기로 복귀시키는 역할로 사용함
			3-2) 닫힘 연산(Closing operation)
					팽창 연산 => 침식 연산
					팽창 연산으로 객체는 확장, 객체 내부 빈 공간을 채우고,
					침식 연산으로 원래 크기로 복귀시킴

	 */
	
	/// Morphology - 침식연산
	//Mat image = imread("image/erosion.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(image.data);

	//Mat th_img, dst;
	//threshold(image, th_img, 128, 255, THRESH_BINARY);			// 먼저 binary image로 만들어줌 for Morphology

	//uchar data[] = { 0, 1, 0, 
	//				   1, 1, 1, 
	//				   0, 1, 0 };
	//Mat mask(3, 3, CV_8UC1, data);
	//morphologyEx(th_img, dst, MORPH_ERODE, mask);

	//imshow("image", image);
	//imshow("이진 영상", th_img);
	//imshow("Erosion", dst);
	//waitKey(0);


	/// Morphology - 팽창연산
	//Mat image = imread("image/bn3.jpg", IMREAD_GRAYSCALE);
	//CV_Assert(image.data);

	//Mat th_img, dst;
	//threshold(image, th_img, 128, 255, THRESH_BINARY);			// 먼저 binary image로 만들어줌 for Morphology

	//Matx <uchar, 3, 3> mask;		// 위의 Mat mask 만드는 것과 동일
	//mask << 0, 1, 0,
	//	    1, 1, 1, 
	//	    0, 1, 0;

	//morphologyEx(th_img, dst, MORPH_DILATE, mask);

	//imshow("image", image);
	//imshow("이진 영상", th_img);
	//imshow("Dilation", dst);
	//waitKey(0);


	return 0;
}

void onMouse(int event, int x, int y, int flags, void* userData) {
	switch (event) {
	case EVENT_LBUTTONDOWN :
		cout << "마우스 왼쪽버튼 누르기--" << *(int*)userData << endl;
		break;
	case EVENT_RBUTTONDOWN:
		cout << "마우스 오른쪽버튼 누르기--" << endl;
		break;
	case EVENT_RBUTTONUP:
		cout << "마우스 오른쪽버튼 떼기--" << endl;
		break;
	case EVENT_LBUTTONDBLCLK:
		cout << "마우스 왼쪽버튼 더블클릭" << endl;
		break;
	}
}
	
void onChange(int value, void* userData) {
	int add_value = value - 130;
	cout << "추가 화소값" << add_value << endl;

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

	cout << name << " 크기  ";
	cout << format(": depth(%d) channels(%d) -> 자료형: ", m.depth(), m.channels());
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

	magnitude(dst1, dst2, dst);		// magnitude연산: 거리구하기 연산(sqrt(dst1^2, dst2^2))


	///* convertScaleAbs() 
	/*     1) abs() 적용 
		   2) 수식 alpha*dst1 + beta(alpha, beta를 인수로 넣음,alpha = 1, beta = 0이 디폴트)
		   3) CV_8U로 설정
	 */

	//dst1 = abs(dst1);
	//dst1.convertTo(dst1, CV_8U);
	convertScaleAbs(dst1, dst1);		 

	//dst2 = abs(dst2);
	//dst2.convertTo(dst2, CV_8U);
	convertScaleAbs(dst2, dst2);		

	dst.convertTo(dst, CV_8U);			

	imshow("행Edge 위주 검출", dst1);
	imshow("열Edge 위주 검출", dst2);
}