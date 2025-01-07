#include <stdio.h>

int main() {
    FILE *file = fopen("file.txt", "a"); // فتح الملف في وضع "الإضافة" (append)

    // التحقق إذا كان الملف مفتوحًا بنجاح
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // إضافة جملة إلى الملف
    fprintf(file, "Hello\n");

    // إغلاق الملف بعد الكتابة
    fclose(file);

    printf("done\n");
    return 0;
}
