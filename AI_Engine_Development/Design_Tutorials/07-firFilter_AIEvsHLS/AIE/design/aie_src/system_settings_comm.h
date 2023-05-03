/*
Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
SPDX-License-Identifier: X11
*/

// FIR Coefficients Taps:  64 Impulse Response Area:  16383.0
//

#if N_FIR_TAPS == 15
   #define FIR_COEF_VALUES  { 255, 511, 767, 1023, 1279, 1535, 1791, 2047 }

#elif N_FIR_TAPS == 64
   #define FIR_COEF_VALUES  { 15, 31, 46, 62, 77, 93, 108, 124, 139, 155, 170, 186, 201, 217, 232, 248, 263, 279, 294, 310, 325, 341, 356, 372, 387, 403, 418, 434, 449, 465, 480, 496 }

#elif N_FIR_TAPS == 129
   #define FIR_COEF_VALUES  { 3, 7, 11, 15, 19, 23, 27, 31, 34, 38, 42, 46, 50, 54, 58, 62, 65, 69, 73, 77, 81, 85, 89, 93, 96, 100, 104, 108, 112, 116, 120, 124, 127, 131, 135, 139, 143, 147, 151, 155, 158, 162, 166, 170, 174, 178, 182, 186, 190, 193, 197, 201, 205, 209, 213, 217, 221, 224, 228, 232, 236, 240, 244, 248, 252 }

#elif N_FIR_TAPS == 240
   #define FIR_COEF_VALUES  { 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 31, 32, 33, 34, 36, 37, 38, 39, 40, 41, 42, 44, 45, 46, 47, 48, 49, 50, 51, 53, 54, 55, 56, 57, 58, 59, 60, 62, 63, 64, 65, 66, 67, 68, 69, 71, 72, 73, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 85, 86, 88, 89, 90, 91, 92, 93, 94, 95, 97, 98, 99, 100, 101, 102, 103, 104, 106, 107, 108, 109, 110, 111, 112, 113, 115, 116, 117, 118, 119, 120, 121, 122, 124, 125, 126, 127, 128, 129, 130, 132, 133, 134, 135 }

#endif
