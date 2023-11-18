"""
Sends alternating 1's and 0's over to the USB CDC device
in order to toggle the status LED.
"""

import os
import sys
import time
import serial
import serial.tools.list_ports
from serial.serialutil import SerialException
import logging

from time import time


class Posit:
    """Implements the behaviour of a Posit controller.

    Sends commands according to the dataframe provided
    over to the Posit hardware.
    """
    
    def __init__(self, address='SERIAL'):
        self.address = address
        
        logging.basicConfig(filename='example.log', filemode='w', encoding='utf-8', level=logging.DEBUG)

        self.logger = logging.getLogger(__name__)

        self.logger.debug('Searching for USB COM devices . . .')
        ports = serial.tools.list_ports.comports(include_links=False)
        for port in ports:
            self.logger.debug(f'Found device : {port.device}')

            self.serial = serial.Serial(port.device)
            if (self.serial.isOpen()):
                self.logger.debug(f'Closing previously open port : {port.device}')
                self.serial.flushInput()
                self.serial.flushOutput()
                self.serial.close()

        try:
            self.serial = serial.Serial(port.device, 115200, timeout=1.0)
            self.serial.open()
            self.serial.flushInput()
            self.serial.flushOutput()
        
        except SerialException as se:
            self.logger.warning(f'Could not open device {port.device} : {se.errno}')
       

        # self.logger.debug(f'Connected to {self.serial.name}.')

        # self.logger.log(f'Started the Posit controller on {port.device} with the ID : [{self.address}]')


    def set_status_led(self):
        self.serial.write(b'1')

    def reset_status_led(self):
        self.serial.write(b'0')

    def toggle_status_led(self, period : float):
        """
        :brief : Toggles the status led on the board using the time period defined by the user.

        :param period (float): The period of the signal.

        :returns : None
        """
        self.set_status_led()
        time.sleep(period)
        self.reset_status_led()
        time.sleep(period)


def main():
    obj = Posit('SOME_ADDR')
    # obj.toggle_status_led(1.0)


if __name__ == '__main__':
    main()