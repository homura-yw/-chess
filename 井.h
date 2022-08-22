#define xx
#ifdef xx
void putPiece(char qipan[][3]) {
	void Copy(char qipan[][3], char Qipan[][3]);
	int stepin(char qipan[][3], int cnt, int step, int W);

	int cnt = 0;
	for (int I = 0; I < 3; I++) {
		for (int i = 0; i < 3; i++) {
			if (qipan[I][i] == '_') cnt++;
		}
	}
	char Qipan[3][3] = { 0 };
	double gailv[9] = { 0 };
	int top = 0;
	for (int I = 0; I < 3; I++) {
		for (int i = 0; i < 3; i++) {
			if (qipan[I][i] == '_') {
				Copy(qipan, Qipan);
				Qipan[I][i] = 'O';
				double X_win = stepin(Qipan, cnt - 1, 1, 1);
				double O_win = stepin(Qipan, cnt - 1, 1, 2);
				double ping = stepin(Qipan, cnt - 1, 1, 0);
				gailv[top++] = (ping + O_win) / (ping + O_win + X_win);
			}
		}
	}
	double max = 0;
	int num = 0;
	for (int i = 0; i < top; i++) {
		if (gailv[i] >= max) {
			max = gailv[i];
			num = i;
		}
	}
	int count = 0;
	for (int I = 0; I < 3; I++) {
		for (int i = 0; i < 3; i++) {
			if (qipan[I][i] == '_') {
				count++;
			}
			if (count == num + 1) {
				qipan[I][i] = 'O';
				return;
			}
		}
	}
}

int whowin(char qipan[][3]) {
	int X = 1, O = 2;
	int ping = 0;
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[1][1] == 'X')return X;
	if (qipan[2][0] == qipan[1][1] && qipan[1][1] == qipan[0][2] && qipan[1][1] == 'X')return X;

	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[1][1] == 'O')return O;
	if (qipan[2][0] == qipan[1][1] && qipan[1][1] == qipan[0][2] && qipan[1][1] == 'O')return O;

	for (int i = 0; i < 3; i++) {
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][1] == 'X') return X;
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[1][i] == 'X') return X;

		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][1] == 'O') return O;
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[1][i] == 'O') return O;
	}

	return ping;

}

void Copy(char qipan[][3], char Qipan[][3]) {

	for (int I = 0; I < 3; I++) {

		for (int i = 0; i < 3; i++) {

			Qipan[I][i] = qipan[I][i];
		}
	}
	return;
}

bool isnotInline(char qipan[][3]) {
	for (int i = 0; i < 3; i++) {
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][1] != '_') return false;
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[1][i] != '_') return false;
	}
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[1][1] != '_')return false;
	if (qipan[2][0] == qipan[1][1] && qipan[1][1] == qipan[0][2] && qipan[1][1] != '_')return false;
	return true;
}

void set(char* site, int step) {

	if (step % 2) {

		*site = 'X';
	}
	else {
		*site = 'O';

	}
	return;
}

int stepin(char qipan[][3], int cnt, int step, int W) {
	bool isnotInline(char qipan[][3]);
	int whowin(char qipan[][3]);
	void Copy(char qipan[][3], char Qipan[][3]);
	void set(char* site, int step);

	if (whowin(qipan) != 0) {
		if (whowin(qipan) == W) return 1;
		else return 0;
	}

	if (cnt == 1) {

		int right = 1;
		int wrong = 0;

		char Qipan[3][3];
		Copy(qipan, Qipan);
		char* p;
		for (int I = 0; I < 3; I++) {

			for (int i = 0; i < 3; i++) {
				if (Qipan[I][i] == '_') {
					p = &Qipan[I][i];
					set(p, step);
					goto end;
				}
			}
		}
	end:
		if (W == whowin(Qipan)) {

			return right;

		}
		else return wrong;

	}

	

	int sum = 0;
	for (int J = 0; J < cnt; J++) {
		char QiPan[3][3];
		Copy(qipan, QiPan);

		int j = 0;
		char* p;
		for (int I = 0; I < 3; I++) {

			for (int i = 0; i < 3; i++) {
				if (QiPan[I][i] == '_') {
					p = &QiPan[I][i];
					j++;
					if (j > J) {
						set(p, step);
						goto END;
					}
				}
			}
		}
	END:
		sum += stepin(QiPan, cnt - 1, step + 1, W);
	}
	return sum;
}
#endif 
