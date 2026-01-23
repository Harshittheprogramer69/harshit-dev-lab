#include <iostream>
#include <vector>
#include <string>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "qrlib/qrcodegen.hpp"

using namespace std;
using qrcodegen::QrCode;

int main() {
    string data;
    cout << "Enter text or URL: ";
    getline(cin, data);

    QrCode qr = QrCode::encodeText(data.c_str(), QrCode::Ecc::MEDIUM);

    int scale = 10;
    int border = 4;
    int size = qr.getSize();
    int imgSize = (size + border * 2) * scale;

    vector<unsigned char> image(imgSize * imgSize, 255);

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (qr.getModule(x, y)) {
                for (int dy = 0; dy < scale; dy++) {
                    for (int dx = 0; dx < scale; dx++) {
                        int px = (x + border) * scale + dx;
                        int py = (y + border) * scale + dy;
                        image[py * imgSize + px] = 0;
                    }
                }
            }
        }
    }

    string filename = "outputs/qr.png";
    stbi_write_png(filename.c_str(), imgSize, imgSize, 1, image.data(), imgSize);

    cout << "PNG QR code saved as " << filename << endl;
    return 0;
}
