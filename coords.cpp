#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    int x1, z1, x2, z2;
    const float PI = 3.141592F;

    if (argc == 1) {
        printf("\nMINECRAFT ANGLE CALCULATOR:\n");

        // read from std in
        int ctr = 0;
        while (cin >> x1 >> z1 >> x2 >> z2) {
            if (cin.eof()) break;

            float a = atan((x1 - x2) / (double) (z2 - z1));

            if ((z2 - z1) < 0)
                a += PI;
            a *= 180 / PI;

            if (a < 270 && a > 180)
                a -= 360;

            printf("Path #%d: (%7d, %7d) to (%7d, %7d) at %.2f \n", ctr++, x1, z1, x2, z2, a);
        }
        cout << endl;

    } else if (argc == 5) {
        // read from args
        x1 = stoi(argv[1]);
        z1 = stoi(argv[2]);
        x2 = stoi(argv[3]);
        z2 = stoi(argv[4]);

        printf("\nMINECRAFT ANGLE CALCULATOR:\n");
        printf("\nPoint #1\n(%7d, %7d)\n", x1, z1);
        printf("Point #2\n(%7d, %7d)\n\n", x2, z2);

        float a = atan((x1 - x2) / (double) (z2 - z1));

        if ((z2 - z1) < 0)
            a += PI;
        a *= 180 / PI;

        if (a < 270 && a > 180)
            a -= 360;

        printf("Angle: %.2f\n\n", a);

    } else {
        cerr << "Two usages:\n" <<
                "./coords < input.txt\n" <<
                "./coords x1 z1 x2 z2";
        exit(1);
    }
}