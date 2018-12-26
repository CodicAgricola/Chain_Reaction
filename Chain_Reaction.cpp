class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            // Your Code
            if(moveCorner(Record, Max, color, inputColor)) return;
            if(moveEdge(Record, Max, color, inputColor)) return;
            if(addCell(Record, Max, color, inputColor)) return;
            if(moveCell(Record, Max, color, inputColor)) return;
            if(addEdge(Record, Max, color, inputColor)) return;
            if(addCorner(Record, Max, color, inputColor)) return;
            return;
        }
        bool moveCorner(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor) {
    if(color[0][0] == White) {
        x = 0;
        y = 0;
        return true;
    } else if(color[0][5] == White) {
        x = 0;
        y = 5;
        return true;
    } else if(color[4][5] == White) {
        x = 4;
        y = 5;
        return true;
    } else if(color[4][0] == White) {
        x = 4;
        y = 0;
        return true;
    } else return false;
}

bool addCorner(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor) {
    if(color[0][0] == White || color[0][0] == inputColor) {
        x = 0;
        y = 0;
        return true;
    } else if(color[0][5] == White || color[0][5] == inputColor) {
        x = 0;
        y = 5;
        return true;
    } else if(color[4][5] == White || color[4][5] == inputColor) {
        x = 4;
        y = 5;
        return true;
    } else if(color[4][0] == White || color[4][0] == inputColor) {
        x = 4;
        y = 0;
        return true;
    } else return false;
}

bool moveEdge(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor) {
    for(int i = 1; i<5; i++) {
        if(color[0][i] == White) {
            x = 0;
            y = i;
            return true;
        } else if(color[4][i] == White) {
            x = 4;
            y = i;
            return true;
        }
    }
    for(int i = 1; i<4; i++) {
        if(color[i][0] == White) {
            x = i;
            y = 0;
            return true;
        } else if(color[i][4] == White) {
            x = i;
            y = 4;
            return true;
        }
    }
    return false;
}

bool addEdge(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor) {
    for(int i = 1; i<5; i++) {
        if(color[0][i] == White || color[0][i] == inputColor) {
            x = 0;
            y = i;
            return true;
        } else if(color[4][i] == White || color[4][i] == inputColor) {
            x = 4;
            y = i;
            return true;
        }
    }
    for(int i = 1; i<4; i++) {
        if(color[i][0] == White || color[i][0] == inputColor) {
            x = i;
            y = 0;
            return true;
        } else if(color[i][4] == White || color[i][4] == inputColor) {
            x = i;
            y = 4;
            return true;
        }
    }
    return false;
}

bool moveCell(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor) {
    for(int i = 1; i<4; i++) {
        for(int j = 1; j<5; j++) {
            if(color[i][j] == White) {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}

bool addCell(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor) {
    for(int i = 1; i<4; i++) {
        for(int j = 1; j<5; j++) {
            if(color[i][j] == White || color[i][j] == inputColor) {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}
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

