	int n, o, t, h, min;	// 양의 정수 n, 각각 일,십,백의 자릿수, 최솟값 min
	scanf("%d", &n);	// n 입력받기
	o = n % 10;	// 일의 자릿수 구하기
	t = n / 10 % 10;	// 십의 자릿수 구하기
	h = n / 100;	// 백의 자릿수 구하기
	min = (o < t) ? o : t;	// o와 t 비교하여 작은 값 min에 저장
	min = (h < min) ? h : min;	// h와 min 비교하여 작은 값 min에 저장
	printf("%d", min);	// 최솟값 출력
