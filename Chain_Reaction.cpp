class Student{
    public:
        int Score[5][6];
        int UpdateRecord[5][6];
        Color UpdateColor[5][6];
        int nextRecord[5][6];
        Color nextColor[5][6];

        Color counter(Color inputColor);

        bool valid(int x, int y);

        int surroundAlly(int x, int y, int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor);

        int surroundCritical(int x, int y, int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, Color counterColor);
        
        int surroundEnemy(int x, int y, int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, Color counterColor);

        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor);

        int moveAttemp(int x, int y, int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, Color counterColor);

        void updateBoard(int Max[5][6], Color inputColor);

        void explode(int x, int y, int Record[5][6], Color color[5][6], Color inputColor);

        int evaluate(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, Color counterColor);

        bool isWin(Color color[5][6], Color inputColor);

        bool isLose(Color color[5][6], Color inputColor);

        // Any Code You Want to Add
        int getX(){
            // Your Code
            return x;
        }
        int getY(){
            // Your Code
            return y;
        }
    private:
        int x;
        int y;
    };

Color Student::counter(Color inputColor) {
    if(inputColor == Blue) return Red;
    else return Blue;
}

bool Student::valid(int x, int y) {
    return (x >= 0 && x < 5 && y >= 0 && y < 6);
}

int Student::surroundCritical(int x, int y, int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, Color counterColor) {
    int sum = 0;
    if(valid(x - 1, y)) {
        if(color[x - 1][y] == counterColor && Record[x - 1][y] == (Max[x - 1][y] - 1) ) sum++;
    }
    if(valid(x + 1, y)) {
        if(color[x + 1][y] == counterColor && Record[x + 1][y] == (Max[x + 1][y] - 1) ) sum++;
    }
    if(valid(x, y - 1)) {
        if(color[x][y - 1] == counterColor && Record[x][y - 1] == (Max[x][y - 1] - 1) ) sum++;
    }
    if(valid(x, y + 1)) {
        if(color[x][y + 1] == counterColor && Record[x][y + 1] == (Max[x][y + 1] - 1) ) sum++;
    }

    return sum;
}

int Student::surroundEnemy(int x, int y, int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, Color counterColor) {
    int score = 0;
    if(valid(x - 1, y)) {
        if(color[x - 1][y] == counterColor) {
            if(Max[x - 1][y] - Record[x - 1][y]  == Max[x][y] - Record[x][y]) score += 5;
        }
    }
    if(valid(x + 1, y)) {
        if(color[x + 1][y] == counterColor) {
            if(Max[x + 1][y] - Record[x + 1][y]  == Max[x][y] - Record[x][y]) score += 5;
        }
    }
    if(valid(x, y - 1)) {
        if(color[x][y - 1] == counterColor) {
            if(Max[x][y - 1] - Record[x][y - 1]  == Max[x][y] - Record[x][y]) score += 5;
        }
    }
    if(valid(x, y + 1)) {
        if(color[x][y + 1] == counterColor) {
            if(Max[x][y + 1] - Record[x][y + 1]  == Max[x][y] - Record[x][y]) score += 5;
        }
    }

    return score;
}

int Student::surroundAlly(int x, int y, int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor) {
    int sum = 0;
    if(valid(x - 1, y)) {
        if(color[x - 1][y] == inputColor) sum += Record[x - 1][y];
    }
    if(valid(x + 1, y)) {
        if(color[x + 1][y] == inputColor) sum += Record[x + 1][y];
    }
    if(valid(x, y - 1)) {
        if(color[x][y - 1] == inputColor) sum += Record[x][y - 1];
    }
    if(valid(x, y + 1)) {
        if(color[x][y + 1] == inputColor) sum += Record[x][y + 1];
    }

    return sum;
}

void Student::makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
    Color counterColor = counter(inputColor);
    int sum;
    int maxScore = -1000;
    int max_x = x, max_y = y;
    // Your Code
    for(int i = 0; i<5; i++) {
        for(int j = 0; j<6; j++) {
            Score[i][j] = 0;
            if(color[i][j] == inputColor) {
                Score[i][j] = moveAttemp(i, j, Record, Max, color, inputColor, counterColor);
                if(Record[i][j] == (Max[i][j] - 1) ) {
                    sum = surroundCritical(i, j, Record, Max, color, inputColor, counterColor);
                    Score[i][j] += 50*sum;
                }
            sum = surroundEnemy(i, j, Record, Max, color, inputColor, counterColor);
            Score[i][j] += 5 * sum;
            } else if(color[i][j] == White) {
                Score[i][j] = moveAttemp(i, j, Record, Max, color, inputColor, counterColor);
            }

            if(Score[i][j] > maxScore) {
                maxScore = Score[i][j];
                max_x = i;
                max_y = j;
            }
        }
    }
    x = max_x;
    y = max_y;
}

int Student::moveAttemp(int x, int y, int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, Color counterColor) {
    int score;
    for(int i = 0; i<5; i++) {
        for(int j = 0; j<6; j++) {
            UpdateRecord[i][j] = Record[i][j];
            UpdateColor[i][j] = color[i][j];
        }
    }
    if(UpdateColor[x][y] == inputColor) {
        UpdateRecord[x][y]++;
        if(UpdateRecord[x][y] == Max[x][y]) updateBoard(Max, inputColor);
    } else if(UpdateColor[x][y] == White) {
        UpdateColor[x][y] = inputColor;
        UpdateRecord[x][y]++;
    }

    score = evaluate(UpdateRecord, Max, UpdateColor, inputColor, counterColor);

    return score;
}

void Student::updateBoard(int Max[5][6], Color inputColor) {
    bool flag = false;
    
    for(int i = 0; i<5; i++) {
        for(int j = 0; j<6; j++) {
            nextRecord[i][j] = UpdateRecord[i][j];
            nextColor[i][j] = UpdateColor[i][j];
        }
    }

    for(int i = 0; i<5; i++) {
        for(int j = 0; j<6; j++) {
            if(UpdateRecord[i][j] >= Max[i][j] && UpdateColor[i][j] != Black) {
                explode(i, j, nextRecord, nextColor, inputColor);
                flag = true;
            }
        }
    }

    if(flag) {
        for(int i = 0; i<5; i++) {
            for(int j = 0; j<6; j++) {
                UpdateRecord[i][j] = nextRecord[i][j];
                UpdateColor[i][j] = nextColor[i][j];
            }
        }
        updateBoard(Max, inputColor);
    }
}

void Student::explode(int x, int y, int Record[5][6], Color color[5][6], Color inputColor) {
    color[x][y] = Black;
    if(valid(x - 1, y)) { 
        if(color[x - 1][y] != Black) {
            color[x - 1][y] = inputColor;
            Record[x - 1][y]++;
        }
    }
    if(valid(x + 1, y)) {
        if(color[x + 1][y] != Black) {
            color[x + 1][y] = inputColor;
            Record[x + 1][y]++;
        }
    }
    if(valid(x, y - 1)) {
        if(color[x][y - 1] != Black) {
            color[x][y - 1] = inputColor;
            Record[x][y - 1]++;
        }
    }
    if(valid(x, y + 1)) {
        if(color[x][y + 1] != Black) {
            color[x][y + 1] = inputColor;
            Record[x][y + 1]++;
        }
    }
}

int Student::evaluate(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, Color counterColor) {
    if(isWin(color, inputColor)) return 10000;
    if(isLose(color, inputColor)) return -10000;
    int score = 0;
    int sum;
    for(int i = 0; i<5; i++) {
        for(int j = 0; j<6; j++) {
            if(color[i][j] == inputColor) {
                sum = surroundCritical(i, j, Record, Max, color, inputColor, counterColor);
                
                if(sum != 0) score -= ( sum*(5 - Max[i][j]) );
                else if(Max[i][j] != 4) score += (5 - Max[i][j]);

                if(sum == 0 && (Record[i][j] == Max[i][j] - 1) ) score += 2;
                
                score++;
            } else {
                if(color[i][j] == White) {
                    sum = surroundAlly(i, j, Record, Max, color, inputColor);
                    score += sum;
                }
                sum = surroundCritical(i, j, Record, Max, color, counterColor, inputColor);
                if(color[i][j] == counterColor) {
                    if(Record[i][j] == Max[i][j] - 1) score -= 5*sum;
                    else {
                        if(sum != 0) score += 2*Record[i][j];
                    }
                } else {
                    if(sum != 0) score += 2*Record[i][j];
                }
            }
        }
    }

    return score;
}

bool Student::isWin(Color color[5][6], Color inputColor) {
    Color counterColor = counter(inputColor);
    for(int i = 0; i<5; i++) {
        for(int j = 0; j<6; j++) {
            if(color[i][j] == White) return false;
            else if(color[i][j] == counterColor) return false;
        }
    }
    return true;
}

bool Student::isLose(Color color[5][6], Color inputColor) {
    for(int i = 0; i<5; i++) {
        for(int j = 0; j<6; j++) {
            if(color[i][j] == White) return false;
            else if(color[i][j] == inputColor) return false;
        }
    }
    return true;
}



