
#include "F28x_Project.h"
#include "math.h"

void Setup_QEP1(void)
{
    EQep1Regs.QUPRD = 1000000;                // Unit Timer for 100Hz at 200 MHz
                                              // SYSCLKOUT
    EQep1Regs.QDECCTL.bit.QSRC = 00;      // QEP quadrature count mode
    EQep1Regs.QDECCTL.bit.XCR = 00;        // 2x Resolution, Count both rising and falling edges
    EQep1Regs.QEPCTL.bit.FREE_SOFT = 2;
    EQep1Regs.QEPCTL.bit.PCRM = 01;       // PCRM=00 mode - QPOSCNT reset on
                                              // index event
    EQep1Regs.QEPCTL.bit.UTE = 1;         // Unit Timeout Enable
    EQep1Regs.QEPCTL.bit.QCLM = 1;        // Latch on unit time out
   // EQep1Regs.QPOSMAX = 0xffffffff;
    EQep1Regs.QPOSMAX = 4095;
    EQep1Regs.QEPCTL.bit.QPEN = 1;        // QEP enable
    EQep1Regs.QEPCTL.bit.IEL = 0;
    EQep1Regs.QCAPCTL.bit.UPPS = 5;       // 1/32 for unit position
    EQep1Regs.QCAPCTL.bit.CCPS = 6;       // 1/64 for CAP clock
    EQep1Regs.QCAPCTL.bit.CEN = 1;        // QEP Capture Enable
 }
