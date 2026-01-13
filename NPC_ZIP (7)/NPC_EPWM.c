

#include "F28x_Project.h"
#include "math.h"

extern float TBPRD;

void InitEPwm1Example()
{
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
    ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 0;
    EDIS;

    SyncSocRegs.SYNCSELECT.bit.EPWM4SYNCIN = 0;

    //C1, C3
    EPwm1Regs.TBCTR = 0x0000;                         // Clear timer counter
    EPwm1Regs.TBPRD = TBPRD;                          // Set timer period
    EPwm1Regs.TBPHS.bit.TBPHS = 0x0000;

    EPwm1Regs.TBCTL.bit.SYNCOSEL = 1;      // allows to pass through

    EPwm1Regs.TBCTL.bit.CTRMODE = 2;                  // 0=up counter, 1= down counter, 2=up-down counter, 3= disable
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;           // Disable phase loading
    EPwm1Regs.TBCTL.bit.CLKDIV = 0;
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 0;                       //001: /2 (default on reset)

    // Setup shadowing
    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;     // Load on Zero
    EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    EPwm1Regs.AQCTLA.all = 0;
    EPwm1Regs.AQCTLA.bit.CAU =  AQ_CLEAR;                // Set(2) PWM1A on event A, up count
    EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;             // Clear(1) PWM1A on event A,down count
//    EPwm1Regs.AQCTLB.bit.CBU = AQ_SET;              // Set PWM1B on event B, up count
//    EPwm1Regs.AQCTLB.bit.CBD =  AQ_CLEAR;                // Clear PWM1B on event B, down count

    EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm1Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm1Regs.DBRED.bit.DBRED = 40;
    EPwm1Regs.DBFED.bit.DBFED = 40;

    //C2,C4
    EPwm2Regs.TBPRD = TBPRD;                          // Set timer period
    EPwm2Regs.TBCTR = 0x0000;                         // Clear timer counter
    EPwm2Regs.TBPHS.bit.TBPHS = 0x0000;

    EPwm2Regs.TBCTL.bit.SYNCOSEL = 0;     // allows to pass through

    EPwm2Regs.TBCTL.bit.CTRMODE = 2;                  // 0=up counter, 1= down counter, 2=up-down counter, 3= disable
    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;           // Disable phase loading
    EPwm2Regs.TBCTL.bit.CLKDIV = 0;
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = 0;

    // Setup shadowing
    EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;     // Load on Zero
    EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    EPwm2Regs.AQCTLA.all = 0;
    EPwm2Regs.AQCTLA.bit.CAU =  AQ_CLEAR;                // Set PWM2A on event A, up count
    EPwm2Regs.AQCTLA.bit.CAD = AQ_SET;              // Clear PWM2A on event A,down count
//    EPwm2Regs.AQCTLB.bit.CBU = AQ_SET;              // Set PWM2B on event B, up count
//    EPwm2Regs.AQCTLB.bit.CBD =  AQ_CLEAR;                // Clear PWM2B on event B, down count

    EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm2Regs.DBRED.bit.DBRED = 40;
    EPwm2Regs.DBFED.bit.DBFED = 40;

    //A1, A3
    EPwm3Regs.TBPRD = TBPRD;                          // Set timer period
    EPwm3Regs.TBCTR = 0x0000;                         // Clear timer counter
    EPwm3Regs.TBPHS.bit.TBPHS = 0x0000;

    EPwm3Regs.TBCTL.bit.SYNCOSEL = 0;     // allows to pass through

    EPwm3Regs.TBCTL.bit.CTRMODE = 2;                  // 0=up counter, 1= down counter, 2=up-down counter, 3= disable
    EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;           // Disable phase loading
    EPwm3Regs.TBCTL.bit.CLKDIV = 0;
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = 0;

    // Setup shadowing
    EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;     // Load on Zero
    EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    EPwm3Regs.AQCTLA.all = 0;
    EPwm3Regs.AQCTLA.bit.CAU =  AQ_CLEAR;                // Set PWM3A on event A, up count
    EPwm3Regs.AQCTLA.bit.CAD = AQ_SET;              // Clear PWM3A on event A,down count
//    EPwm3Regs.AQCTLB.bit.CBU = AQ_SET;              // Set PWM3B on event B, up count
//    EPwm3Regs.AQCTLB.bit.CBD =  AQ_CLEAR;                // Clear PWM3B on event B, down count

    EPwm3Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm3Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm3Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm3Regs.DBRED.bit.DBRED = 40;
    EPwm3Regs.DBFED.bit.DBFED = 40;

    //A2, A4
    EPwm4Regs.TBCTR = 0x0000;                         // Clear timer counter
    EPwm4Regs.TBPRD = TBPRD;                          // Set timer period
    EPwm4Regs.TBPHS.bit.TBPHS = 0x0000;

    EPwm4Regs.TBCTL.bit.SYNCOSEL = 0;      // allows to pass through

    EPwm4Regs.TBCTL.bit.CTRMODE = 2;                  // 0=up counter, 1= down counter, 2=up-down counter, 3= disable
    EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE;           // Disable phase loading
    EPwm4Regs.TBCTL.bit.CLKDIV = 0;
    EPwm4Regs.TBCTL.bit.HSPCLKDIV = 0;                       //001: /2 (default on reset)

    // Setup shadowing
    EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm4Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;     // Load on Zero
    EPwm4Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    EPwm4Regs.AQCTLA.all = 0;
    EPwm4Regs.AQCTLA.bit.CAU =  AQ_CLEAR;                // Set(2) PWM4A on event A, up count
    EPwm4Regs.AQCTLA.bit.CAD = AQ_SET;             // Clear(1) PWM4A on event A,down count
//    EPwm4Regs.AQCTLB.bit.CBU = AQ_SET;              // Set PWM4B on event B, up count
//    EPwm4Regs.AQCTLB.bit.CBD =  AQ_CLEAR;                // Clear PWM4B on event B, down count

    EPwm4Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm4Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm4Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm4Regs.DBRED.bit.DBRED = 40;
    EPwm4Regs.DBFED.bit.DBFED = 40;

    //B1, B3
    EPwm5Regs.TBCTR = 0x0000;                         // Clear timer counter
    EPwm5Regs.TBPRD = TBPRD;                          // Set timer period
    EPwm5Regs.TBPHS.bit.TBPHS = 0x0000;

    EPwm5Regs.TBCTL.bit.SYNCOSEL = 0;      // allows to pass through

    EPwm5Regs.TBCTL.bit.CTRMODE = 2;                  // 0=up counter, 1= down counter, 2=up-down counter, 3= disable
    EPwm5Regs.TBCTL.bit.PHSEN = TB_DISABLE;           // Disable phase loading
    EPwm5Regs.TBCTL.bit.CLKDIV = 0;
    EPwm5Regs.TBCTL.bit.HSPCLKDIV = 0;                       //001: /2 (default on reset)

    // Setup shadowing
    EPwm5Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm5Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm5Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;     // Load on Zero
    EPwm5Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    EPwm5Regs.AQCTLA.all = 0;
    EPwm5Regs.AQCTLA.bit.CAU =  AQ_CLEAR;                // Set(2) PWM5A on event A, up count
    EPwm5Regs.AQCTLA.bit.CAD = AQ_SET;             // Clear(1) PWM5A on event A,down count
//    EPwm5Regs.AQCTLB.bit.CBU = AQ_SET;              // Set PWM5B on event B, up count
//    EPwm5Regs.AQCTLB.bit.CBD =  AQ_CLEAR;                // Clear PWM5B on event B, down count

    EPwm5Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm5Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm5Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm5Regs.DBRED.bit.DBRED = 40;
    EPwm5Regs.DBFED.bit.DBFED = 40;

    //B2,B4
    EPwm6Regs.TBCTR = 0x0000;                         // Clear timer counter
    EPwm6Regs.TBPRD = TBPRD;                          // Set timer period
    EPwm6Regs.TBPHS.bit.TBPHS = 0x0000;

    EPwm6Regs.TBCTL.bit.SYNCOSEL = 0;      // allows to pass through
    EPwm6Regs.TBCTL.bit.CTRMODE = 2;                  // 0=up counter, 1= down counter, 2=up-down counter, 3= disable
    EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;           // Disable phase loading
    EPwm6Regs.TBCTL.bit.CLKDIV = 0;
    EPwm6Regs.TBCTL.bit.HSPCLKDIV = 0;                       //001: /2 (default on reset)

    // Setup shadowing
    EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm6Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;     // Load on Zero
    EPwm6Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    EPwm6Regs.AQCTLA.all = 0;
    EPwm6Regs.AQCTLA.bit.CAU =  AQ_CLEAR;                // Set(2) PWM6A on event A, up count
    EPwm6Regs.AQCTLA.bit.CAD = AQ_SET;             // Clear(1) PWM6A on event A,down count
//    EPwm6Regs.AQCTLB.bit.CBU = AQ_SET;              // Set PWM6B on event B, up count
//    EPwm6Regs.AQCTLB.bit.CBD =  AQ_CLEAR;                // Clear PWM6B on event B, down count

    EPwm6Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm6Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm6Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm6Regs.DBRED.bit.DBRED = 40;
    EPwm6Regs.DBFED.bit.DBFED = 40;

    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;             // synchronize all the time base modules
    EDIS;
}


