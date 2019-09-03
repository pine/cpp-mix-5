#include "SkCanvas.h"
#include "SkColor.h"
#include "SkImage.h"
#include "SkPaint.h"
#include "SkSurface.h"
#include "SkTextUtils.h"

const int W = 800;
const int H = 400;
const char* FNAME = "example.png";

int main() {
    // Make canvas
    sk_sp<SkSurface> surface = SkSurface::MakeRasterN32Premul(W, H);
    SkCanvas *canvas = surface->getCanvas();

    // Draw rect
    SkPaint paint1;
    paint1.setStyle(SkPaint::kFill_Style);
    paint1.setAntiAlias(true);
    paint1.setColor(SK_ColorRED);

    SkRect rect = SkRect::MakeXYWH(40, 40, 200, 120);
    canvas->drawRect(rect, paint1);

    // Draw text
    SkPaint paint2;
    paint2.setStyle(SkPaint::kFill_Style);
    paint2.setAntiAlias(true);
    paint2.setColor(SK_ColorBLUE);

    sk_sp<SkTypeface> typeface = SkTypeface::MakeFromName("Helavetica", SkFontStyle());
    SkFont font;
    font.setTypeface(typeface);
    font.setSize(100);
    SkTextUtils::DrawString(canvas, "C++ MIX #5", 50, 300, font, paint2);

    // Output
    sk_sp<SkImage> image(surface->makeImageSnapshot());
    sk_sp<SkData> data(image->encodeToData(SkEncodedImageFormat::kPNG, 100));
    SkFILEWStream fh(FNAME);
    fh.write(data->data(), data->size());

    return 0;
}
