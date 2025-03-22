#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>

void encrypt_transposition(FILE *in, FILE *out) {
    char buffer[1000];
    int len = 0;
    int c;
    while ((c = fgetc(in)) != EOF) {
        buffer[len++] = c;
    }
    buffer[len] = '\0';

    // Calculate middle
    int mid = (len + 1) / 2; // divide

    // Write second half first
    for (int i = mid; i < len; i++) {
        fputc(buffer[i], out);
    }
    // Write first half second
    for (int i = 0; i < mid; i++) {
        fputc(buffer[i], out);
    }
}

void decrypt_transposition(FILE *in, FILE *out) {
    char buffer[1000];
    int len = 0;
    int c;
    while ((c = fgetc(in)) != EOF) {
        buffer[len++] = c;
    }
    buffer[len] = '\0';

    // Calculate middle
    int mid = (len + 1) / 2;
    int first_half_len = len - mid;

    // Write the second half (original first half) first
    for (int i = first_half_len; i < len; i++) {
        fputc(buffer[i], out);
    }
    // Write the first half (original second half) second
    for (int i = 0; i < first_half_len; i++) {
        fputc(buffer[i], out);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5 || strcmp(argv[3], "-o") != 0) {
        printf("Usage: %s {-e|-d} input_file -o output_file\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];       // -e or -d
    char *input_file = argv[2]; // Input file naem
    char *output_file = argv[4]; // Output file naem

    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    if (!in || !out) {
        printf("Error opening files: %s or %s\n", input_file, output_file);
        return 1;
    }

    if (strcmp(mode, "-e") == 0) {
        encrypt_transposition(in, out);
    } else if (strcmp(mode, "-d") == 0) {
        decrypt_transposition(in, out);
    } else {
        printf("Error: Use -e for encryption or -d for decryption\n");
        fclose(in);
        fclose(out);
        return 1;
    }

    fclose(in);
    fclose(out);
    printf("Transposition complete. Check %s\n", output_file);
    return 0;
}