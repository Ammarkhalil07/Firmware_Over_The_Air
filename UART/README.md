# UART (Universal Asynchronous Receiver/Transmitter)

A communication protocol used for serial communication between devices. Raspberry Pi 4 also supports UART communication, allowing it to exchange data with other devices serially.

These UARTs are available via the GPIO pins.

|       UART      |     GPIO PIN (Tx,Rx)    |     Type     |
|-----------------|-------------------------|--------------|
| UART0           | (14,15)                 | PL011        |
| UART1           | (14,15)                 | mini UART    |
| UART2           | (0,1)                   | PL011        |
| UART3           | (4,5)                   | PL011        |
| UART4           | (8,9)                   | PL011        |
| UART5           | (12,13)                 | PL011        |

- uart2 uses GPIO0/1 which are reserved1 and possibly impact on normal Raspbian functionality.

- uart3 uses GPIO4/5 which is OK, although GPIO4 is commonly used for other purposes.

- uart4 uses GPIO8/9 which are used for SPI0.

- uart5 uses GPIO12/13 which conflict with the default pin allocation of gpio-fan (although this can be changed).

- In our project, we will use `UART3`.

- If additional UARTs are enabled they will appear as `/dev/ttyAMAn`. The first will be /dev/ttyAMA1 and increment if additional UART are enabled.

## Primary UART

On the Raspberry Pi, one UART is selected to be present on GPIO 14 (transmit) and 15 (receive) - this is the primary UART. By default, this will also be the UART on which a Linux console may be present.

## Secondry UART

The secondary UART is not normally present on the GPIO connector. By default, the secondary UART is connected to the Bluetooth side of the combined wireless LAN/Bluetooth controller, on models which contain this controller.

## Raspberrypi4 Primary and Secondry UART

- By default:

    Primary -> UART1

    Secondry -> UART0

- We can make the primary UART to be UART0 to benefit from the fully functional UART0 instead of mini UART1 by disabling the Bluetooth module.

## Enable a desired UART module 

- Here, we built our image using Yocto project. Yocto project can use dts files from linux repo. to build the raspberrypi dtb files.

- We have two methods to enable the desired UART module:

    1. Modify the dts file itself.

        - dts files are located in the build directory of the yocto project:

            ```bash
            cd ~/poky/build/tmp/work-shared/raspberrypi4-64/kernel-source/arch/arm/boot/dts
            ```
            1. You will find `bcm2711.dtsi` file. This file contains the configuration of most of bcm2711 chipset peripherals.

            2. in `soc` section, you will find `uart3: serial@7e201600`.

            3. In this section, you will find `status` field which is disabled by default.

            4. Change the `status` field to "okay" in order to enable the uart3 module.

            5. Compile the raspberrypi kernel `bitbake linux-raspberrypi -c compile -f;bitbake linux-raspberrypi`.

            6. build your image `bitabke <your-image-name>` and burn it using `dd` command into your SD card.

    2. Append the desired UART module dts overlay.

        - dts overlays are located in the build directory of the yocto project:

            ```bash
            cd ~/poky/build/tmp/work-shared/raspberrypi4-64/kernel-source/arch/arm/boot/dts/overlays
            ```
            1. You will find `uart3-overlay.dts`.

            2. add `KERNEL_DEVICETREE_append = "overlays/uart3.dtbo` to local.conf file.

            3. Compile the raspberrypi kernel `bitbake linux-raspberrypi -c compile -f;bitbake linux-raspberrypi`.

            4. build your image `bitabke <your-image-name>` and burn it using `dd` command into your SD card.

- According to our approach, that UART3 will be the main function to update the firmware of the connected device, we will modify the dts file itself
        
- After powering on your raspberrypi4, you can find the uart3 device node under `/dev`:

    ```bash
    ls /dev/tty*
    ```
- UART device nodes named as ttyAMAn, where n is the order of the UART module not it's number.

- In our case, we have UART0 with dev node `ttyAMA0` and UART3 with dev node `ttyAMA1`.

- It is ttyAMA1 not ttyAMA3 as this number indicates the the order in which the kernel detects the module. So, UART0 is detected firstly, then UART3 and so on for any another additional UART module.

- To confirm that the dev node matches the enabled UART module:

    ```bash
    stty < /dev/ttyAMA1
    ```
    - This will print some info about the device which matches this dev node. One of the important detail is `serial`.

    - If the `serial` output of `stty` command matches the serial in the `bcm2711.dtsi` file for uart3. Then this is the right dev node. 