
#include "F28x_Project.h"
#include "math.h"

void ConfigureADC(void)
{
    EALLOW;
//
//    DevCfgRegs.SOFTPRES13.bit.ADC_A=1;
//    DevCfgRegs.SOFTPRES13.bit.ADC_B=1;
//    DevCfgRegs.SOFTPRES13.bit.ADC_C=1;
//    DevCfgRegs.SOFTPRES13.bit.ADC_D=1;
//    DevCfgRegs.SOFTPRES13.bit.ADC_A=0;
//    DevCfgRegs.SOFTPRES13.bit.ADC_B=0;
//    DevCfgRegs.SOFTPRES13.bit.ADC_C=0;
//    DevCfgRegs.SOFTPRES13.bit.ADC_D=0;


    // ADC-A
    AdcaRegs.ADCCTL2.bit.PRESCALE = 6;          // Set ADCCLK divider to /4
    AdcaRegs.ADCCTL2.bit.RESOLUTION =  0;       // 12-bit resolution
    AdcaRegs.ADCCTL2.bit.SIGNALMODE = 0;        // Single-ended channel conversions (12-bit mode only)
    AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1;       // Set pulse positions to late
    AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1;          // Power up the ADC

    // ADC-B
    AdcbRegs.ADCCTL2.bit.PRESCALE = 6;          // Set ADCCLK divider to /4
    AdcbRegs.ADCCTL2.bit.RESOLUTION =  0;       // 12-bit resolution RESOLUTION_12BIT;
    AdcbRegs.ADCCTL2.bit.SIGNALMODE = 0;        // Single-ended channel conversions (12-bit mode only)
    AdcbRegs.ADCCTL1.bit.INTPULSEPOS = 1;       // Set pulse positions to late
    AdcbRegs.ADCCTL1.bit.ADCPWDNZ = 1;          // Power up the ADC

    // ADC-C
    AdccRegs.ADCCTL2.bit.PRESCALE = 6;          // Set ADCCLK divider to /4
    AdccRegs.ADCCTL2.bit.RESOLUTION =  0;       // 12-bit resolution RESOLUTION_12BIT;
    AdccRegs.ADCCTL2.bit.SIGNALMODE = 0;        // Single-ended channel conversions (12-bit mode only)
    AdccRegs.ADCCTL1.bit.INTPULSEPOS = 1;       // Set pulse positions to late
    AdccRegs.ADCCTL1.bit.ADCPWDNZ = 1;          // Power up the ADC

    // ADC-D
    AdcdRegs.ADCCTL2.bit.PRESCALE = 6;          // Set ADCCLK divider to /4
    AdcdRegs.ADCCTL2.bit.RESOLUTION =  0;       // 12-bit resolution RESOLUTION_12BIT;
    AdcdRegs.ADCCTL2.bit.SIGNALMODE = 0;        // Single-ended channel conversions (12-bit mode only)
    AdcdRegs.ADCCTL1.bit.INTPULSEPOS = 1;       // Set pulse positions to late
    AdcdRegs.ADCCTL1.bit.ADCPWDNZ = 1;          // Power up the ADC


    DELAY_US(1000);                    // Delay for 1ms to allow ADC time to power up
    EDIS;
}

void SetupADCEpwm(void)
{

    // Select the channels to convert and end of conversion flag
    EALLOW;

    //--- ADCA1 interrupt configuration
    AdcaRegs.ADCINTSEL1N2.bit.INT1CONT = 1;     // Interrupt pulses regardless of flag state
    AdcaRegs.ADCINTSEL1N2.bit.INT1E = 1;        // Enable the interrupt in the ADC
    AdcaRegs.ADCINTSEL1N2.bit.INT1SEL = 3;      // EOC3 triggers the interrupt

    //IOUT_A
    AdcaRegs.ADCSOC5CTL.bit.CHSEL = 5;          // SOC0 will convert pin A5
    AdcaRegs.ADCSOC5CTL.bit.ACQPS = 20;         // Sample window is 100 SYSCLK cycles
    AdcaRegs.ADCSOC5CTL.bit.TRIGSEL = 2;        // Trigger on ePWM2 SOCA/C

    //IOUT_B
    AdcaRegs.ADCSOC15CTL.bit.CHSEL = 15;          // SOC0 will convert pin A15
    AdcaRegs.ADCSOC15CTL.bit.ACQPS = 20;         // Sample window is 100 SYSCLK cycles
    AdcaRegs.ADCSOC15CTL.bit.TRIGSEL = 2;        // Trigger on ePWM2 SOCA/C

    //IOUT_C
    AdccRegs.ADCSOC2CTL.bit.CHSEL = 2;          // SOC3 will convert pin C2
    AdccRegs.ADCSOC2CTL.bit.ACQPS = 20;         // Sample window is 100 SYSCLK cycles
    AdccRegs.ADCSOC2CTL.bit.TRIGSEL = 2;        // Trigger on ePWM2 SOCA/C

    //VDC_DSP
    AdccRegs.ADCSOC4CTL.bit.CHSEL = 4;          // SOC0 will convert pin C4
    AdccRegs.ADCSOC4CTL.bit.ACQPS = 20;         // Sample window is 100 SYSCLK cycles
    AdccRegs.ADCSOC4CTL.bit.TRIGSEL = 2;        // Trigger on ePWM2 SOCA/C

    //V_sen_A
    AdcbRegs.ADCSOC5CTL.bit.CHSEL = 5;          // SOC3 will convert pin B5
    AdcbRegs.ADCSOC5CTL.bit.ACQPS = 20;         // Sample window is 100 SYSCLK cycles
    AdcbRegs.ADCSOC5CTL.bit.TRIGSEL = 2;        // Trigger on ePWM2 SOCA/C

    //V_sen_B
    AdcdRegs.ADCSOC1CTL.bit.CHSEL = 1;          // SOC3 will convert pin D1
    AdcdRegs.ADCSOC1CTL.bit.ACQPS = 20;         // Sample window is 100 SYSCLK cycles
    AdcdRegs.ADCSOC1CTL.bit.TRIGSEL = 2;        // Trigger on ePWM2 SOCA/C

    //V_sen_C
    AdcdRegs.ADCSOC2CTL.bit.CHSEL = 2;          // SOC3 will convert pin D2
    AdcdRegs.ADCSOC2CTL.bit.ACQPS = 20;         // Sample window is 100 SYSCLK cycles
    AdcdRegs.ADCSOC2CTL.bit.TRIGSEL = 2;        // Trigger on ePWM2 SOCA/C

    //V_DC_BOT
    AdccRegs.ADCSOC5CTL.bit.CHSEL = 5;          // SOC3 will convert pin C5
    AdccRegs.ADCSOC5CTL.bit.ACQPS = 20;         // Sample window is 100 SYSCLK cycles
    AdccRegs.ADCSOC5CTL.bit.TRIGSEL = 2;        // Trigger on ePWM2 SOCA/C


    EDIS;

}
