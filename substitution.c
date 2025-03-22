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

void encrypt_substitution(FILE *in, FILE *out) {
    int c;
    const int shift = 1; // Default shift of 1
    while ((c = fgetc(in)) != EOF) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = base + (c - base + shift) % 26;
        }
        fputc(c, out);
    }
}

void decrypt_substitution(FILE *in, FILE *out) {
    int c;
    const int shift = 1; // Default shift of 1
    while ((c = fgetc(in)) != EOF) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = base + (c - base - shift + 26) % 26;
        }
        fputc(c, out);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5 || strcmp(argv[3], "-o") != 0) {
        printf("Usage: %s {-e|-d} input_file -o output_file\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];       // -e or -d
    char *input_file = argv[2]; // Input file name
    char *output_file = argv[4]; // Output file name

    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    if (!in || !out) {
        printf("Error opening files: %s or %s\n", input_file, output_file);
        return 1;
    }

    if (strcmp(mode, "-e") == 0) {
        encrypt_substitution(in, out);
    } else if (strcmp(mode, "-d") == 0) {
        decrypt_substitution(in, out);
    } else {
        printf("Error: Use -e for encryption or -d for decryption\n");
        fclose(in);
        fclose(out);
        return 1;
    }

    fclose(in);
    fclose(out);
    printf("Substitution complete. Check %s\n", output_file);
    return 0;
}