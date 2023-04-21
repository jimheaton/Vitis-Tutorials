/*********************************************************************
Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
SPDX-License-Identifier: X11
**********************************************************************/

#ifndef __C1A_H__
  #define __C1A_H__

  // SIMD matrix of coefficients for IIR filter stage 1
  alignas(16) const float C1a[96] = {

    -5.55759643132462066716926e-01,	// Ky0_ym2
    -8.11245049836881282345757e-01,	// Ky1_ym2
    -8.75309557700034823746194e-01,	// Ky2_ym2
    -8.26836352468100721502253e-01,	// Ky3_ym2
    -7.20475311378760530089949e-01,	// Ky4_ym2
    -5.92159034454994515073167e-01,	// Ky5_ym2
    -4.63966316167404635439908e-01,	// Ky6_ym2
    -3.48155791053268326429304e-01,	// Ky7_ym2

    +1.45970485597768706576005e+00,	// Ky0_ym1
    +1.57497862343237815530017e+00,	// Ky1_ym1
    +1.48775889484841394860837e+00,	// Ky2_ym1
    +1.29637932563419222553591e+00,	// Ky3_ym1
    +1.06549484434920893605181e+00,	// Ky4_ym1
    +8.34832686936969547986109e-01,	// Ky5_ym1
    +6.26450292595800095618586e-01,	// Ky6_ym1
    +4.50466217963327697493270e-01,	// Ky7_ym1

    +2.77946847237095367999515e-02,	// Ky0_xm2
    +4.05720362615676483075688e-02,	// Ky1_xm2
    +4.37760342848849959285218e-02,	// Ky2_xm2
    +4.13517894272061939386909e-02,	// Ky3_xm2
    +3.60324546383375549085670e-02,	// Ky4_xm2
    +2.96150932734242262889257e-02,	// Ky5_xm2
    +2.32039113304603750176369e-02,	// Ky6_xm2
    +1.74119883777758555076787e-02,	// Ky7_xm2

    +4.04654177073559273569714e-02,	// Ky0_xm1
    +8.68622514503024634180406e-02,	// Ky1_xm1
    +1.04304204138915265764886e-01,	// Ky2_xm1
    +1.03978819412760284390806e-01,	// Ky3_xm1
    +9.38103203461741752544611e-02,	// Ky4_xm1
    +7.91481485799624823185283e-02,	// Ky5_xm1
    +6.33969466660830038851060e-02,	// Ky6_xm1
    +4.85534840932447669947791e-02,	// Ky7_xm1

    +2.77946847237095367999515e-02,	// Ky0_x0
    +8.10374539689235756645402e-02,	// Ky1_x0
    +1.30638285735187459346562e-01,	// Ky2_x0
    +1.45655993566121466642471e-01,	// Ky3_x0
    +1.40011274051097839299374e-01,	// Ky4_x0
    +1.23425413619598398073940e-01,	// Ky5_x0
    +1.02352059910422857336165e-01,	// Ky6_x0
    +8.08089350438588593927847e-02,	// Ky7_x0

    +0.00000000000000000000000e+00,	// Ky0_x1
    +2.77946847237095367999515e-02,	// Ky1_x1
    +8.10374539689235756645402e-02,	// Ky2_x1
    +1.30638285735187459346562e-01,	// Ky3_x1
    +1.45655993566121466642471e-01,	// Ky4_x1
    +1.40011274051097839299374e-01,	// Ky5_x1
    +1.23425413619598398073940e-01,	// Ky6_x1
    +1.02352059910422857336165e-01,	// Ky7_x1

    +0.00000000000000000000000e+00,	// Ky0_x2
    +0.00000000000000000000000e+00,	// Ky1_x2
    +2.77946847237095367999515e-02,	// Ky2_x2
    +8.10374539689235756645402e-02,	// Ky3_x2
    +1.30638285735187459346562e-01,	// Ky4_x2
    +1.45655993566121466642471e-01,	// Ky5_x2
    +1.40011274051097839299374e-01,	// Ky6_x2
    +1.23425413619598398073940e-01,	// Ky7_x2

    +0.00000000000000000000000e+00,	// Ky0_x3
    +0.00000000000000000000000e+00,	// Ky1_x3
    +0.00000000000000000000000e+00,	// Ky2_x3
    +2.77946847237095367999515e-02,	// Ky3_x3
    +8.10374539689235756645402e-02,	// Ky4_x3
    +1.30638285735187459346562e-01,	// Ky5_x3
    +1.45655993566121466642471e-01,	// Ky6_x3
    +1.40011274051097839299374e-01,	// Ky7_x3

    +0.00000000000000000000000e+00,	// Ky0_x4
    +0.00000000000000000000000e+00,	// Ky1_x4
    +0.00000000000000000000000e+00,	// Ky2_x4
    +0.00000000000000000000000e+00,	// Ky3_x4
    +2.77946847237095367999515e-02,	// Ky4_x4
    +8.10374539689235756645402e-02,	// Ky5_x4
    +1.30638285735187459346562e-01,	// Ky6_x4
    +1.45655993566121466642471e-01,	// Ky7_x4

    +0.00000000000000000000000e+00,	// Ky0_x5
    +0.00000000000000000000000e+00,	// Ky1_x5
    +0.00000000000000000000000e+00,	// Ky2_x5
    +0.00000000000000000000000e+00,	// Ky3_x5
    +0.00000000000000000000000e+00,	// Ky4_x5
    +2.77946847237095367999515e-02,	// Ky5_x5
    +8.10374539689235756645402e-02,	// Ky6_x5
    +1.30638285735187459346562e-01,	// Ky7_x5

    +0.00000000000000000000000e+00,	// Ky0_x6
    +0.00000000000000000000000e+00,	// Ky1_x6
    +0.00000000000000000000000e+00,	// Ky2_x6
    +0.00000000000000000000000e+00,	// Ky3_x6
    +0.00000000000000000000000e+00,	// Ky4_x6
    +0.00000000000000000000000e+00,	// Ky5_x6
    +2.77946847237095367999515e-02,	// Ky6_x6
    +8.10374539689235756645402e-02,	// Ky7_x6

    +0.00000000000000000000000e+00,	// Ky0_x7
    +0.00000000000000000000000e+00,	// Ky1_x7
    +0.00000000000000000000000e+00,	// Ky2_x7
    +0.00000000000000000000000e+00,	// Ky3_x7
    +0.00000000000000000000000e+00,	// Ky4_x7
    +0.00000000000000000000000e+00,	// Ky5_x7
    +0.00000000000000000000000e+00,	// Ky6_x7
    +2.77946847237095367999515e-02	// Ky7_x7

  };

#endif // __C1A_H__
