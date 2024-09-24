# STM32F411_BareMetal
# Bare Metal Programming on STM32

This repository contains examples and code for **bare-metal programming** on STM32 microcontrollers. Bare-metal programming involves direct manipulation of the microcontroller's registers without an operating system or complex abstraction layers, providing full control over the hardware.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [License](#license)

## Overview

In this project, we explore how to program STM32 microcontrollers from the ground up, using low-level register access. This approach gives us control over peripherals such as GPIO, UART, ADC, and more, without relying on higher-level libraries like HAL (Hardware Abstraction Layer) or CMSIS (Cortex Microcontroller Software Interface Standard).

This is ideal for learning the fundamentals of embedded systems and understanding how hardware operates at the register level.

## Features
- Bare-metal code for STM32 microcontrollers
- Basic examples:
  - Blinking an LED using GPIO
  - UART communication
  - ADC configuration

## Requirements

To compile and run the code in this repository, you'll need the following tools:

- **STM32CubeIDE** (recommended) 
- **STM32CubeMX** (optional) 
- An STM32 microcontroller (e.g., STM32F4, STM32F3, STM32G4, etc.).
  
## Project Structure

```bash
├── Src/                    # Source files
│   ├── main.c              # Main program entry point
│   ├── libarary.c          # Configuration functions
│
├── Inc/                    # Header files
│   ├── main.h              # Main header
│   ├── libarary.h          # Header
│
├── startup/                # Startup and linker script
│   ├── startup_stm32f4xx.s # Startup assembly code
│   └── linker.ld           # Linker script (memory mapping)
│
├── Makefile                # Makefile for building the project
├── README.md               # Project documentation
└── LICENSE                 # License file
├── Documents               # Refer to Reference Manual and Datasheet
