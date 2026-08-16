# Design and Implementation of SiC MOSFET Based Three-Phase 3-Level NPC Converter

**Undergraduate Project**  
**Department of Electrical Engineering, IIT Kanpur**

---

## 📌 Project Overview
This project focuses on the **design, simulation, and hardware implementation** of a **SiC MOSFET-based Three-Phase Three-Level Neutral Point Clamped (NPC) Converter** intended for **medium-power applications** such as traction drives and motor drive systems.

The proposed converter achieves **high efficiency, reduced switching losses, lower dv/dt stress, and improved waveform quality** compared to conventional two-level inverters.

---

## 🎯 Objectives
- Design a **compact, robust, and high-frequency** 3-Level NPC converter
- Implement **SiC MOSFETs** for reduced switching and conduction losses
- Develop **gate driver and sensing circuits** with proper isolation
- Validate performance through **MATLAB/Simulink and LTspice simulations**
- Build and test a **6.6 kW hardware prototype**

---

## ⚙️ Converter Specifications
| Parameter | Value |
|---------|------|
| Topology | Three-Phase, Three-Level NPC |
| Rated Power | 6.6 kW |
| DC Link Voltage | 700 V |
| Output Voltage | 415 V AC |
| Switching Frequency | 100 kHz |
| Power Devices | SiC MOSFET (Toshiba TW083Z65C) |

---

## 🧠 Methodology
- **Literature Survey** on multilevel converters for traction and EV applications  
- **MATLAB/Simulink Modeling** of NPC converter fed induction motor drive  
- **LTspice Simulation** of:
  - Gate driver circuits  
  - DC & AC voltage sensing circuits  
  - Current sensing circuits  
- **Loss Calculations**:
  - Conduction loss  
  - Switching loss  
- **Thermal Design**:
  - Heat sink selection using thermal resistance modeling  
- **Hardware Implementation** with compact PCB layout and reduced parasitics  

---

## 🧪 Tools & Software Used
- MATLAB / Simulink  
- LTspice  
- KiCad  
- Code Composer Studio (CCS)  
- DSP Controller (TI TMDSCNCD28379D)  

---

## 🧩 Repository Structure
- `MATLAB_Simulink/` → Converter & IM drive models  
- `LTspice/` → Gate driver & sensor simulations  
- `Hardware/` → PCB schematics, layouts & prototype images  
- `Firmware/` → Control and PWM generation code  
- `Documentation/` → Detailed project report  

---

## 📊 Key Outcomes
- Successful design of **6.6 kW SiC-based NPC converter**
- Validated **dynamic performance and control strategy**
- Reduced switching losses and improved efficiency
- Compact and modular hardware implementation

---

## 🔭 Future Scope
- Closed-loop experimental validation with vector control  
- Extension to **higher power and voltage levels**
- Integration with **EV chargers and traction systems**
- Implementation of **SVPWM and advanced balancing algorithms**

---

## 👨‍🏫 Project Supervisor
**Prof. Piyush Kant**  
Department of Electrical Engineering  
Indian Institute of Technology Kanpur  

---

## 📅 Project Duration
March 2025 – April 2026

---

## 📜 License
This project is intended for **academic and research purposes only.
