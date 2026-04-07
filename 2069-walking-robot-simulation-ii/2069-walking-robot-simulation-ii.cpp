class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 0; // 0=East, 1=North, 2=West, 3=South
    int perimeter;

    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h - 2);
    }

    void step(int num) {
        num %= perimeter;
        if(num == 0) num = perimeter;

        while(num--) {
            if(dir == 0) { // East
                if(x + 1 < w) x++;
                else { dir = 1; y++; }
            }
            else if(dir == 1) { // North
                if(y + 1 < h) y++;
                else { dir = 2; x--; }
            }
            else if(dir == 2) { // West
                if(x - 1 >= 0) x--;
                else { dir = 3; y--; }
            }
            else { // South
                if(y - 1 >= 0) y--;
                else { dir = 0; x++; }
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if(dir == 0) return "East";
        if(dir == 1) return "North";
        if(dir == 2) return "West";
        return "South";
    }
};