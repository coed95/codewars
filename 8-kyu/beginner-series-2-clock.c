#define MS 1000

int past(int h, int m, int s) {
    return (h * 60 * 60 * MS) + (m * 60 * MS) + (s * MS);
}