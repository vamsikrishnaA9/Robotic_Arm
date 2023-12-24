

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">


  <h1 align="center">3 DOF Robotic Arm</h1>


</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
     <ul>
      <li><a href="#Nema 17">NEMA 17</a></li>
      <li><a href="#A4988">A4988</a></li>
       <li><a href="#Iinverse Kinematics">Inverse Kinematics</a></li>
      <li><a href="#prerequisites">Prerequisites</a></li>
      <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
   
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](https://example.com) 


Welcome to 3-DOF Robotic Arm project!. This repository houses all the software design files, documentaion and PCB files for the Robotic Arm.
This Robitic Arm is equipped with 3 rotational joints providing adaptability and flexibility in moving 3-D space.This project includes Mechanical CAD design source files were originally forked from the repository 
maintained by `Florin Tobler`, which can be found at [https://github.com/ftobler/robotArm](https://github.com/ftobler/robotArm).

This robot was developed using NEMA 17 stepper motors and 3D printed with PLA plastic. The Maximum height can go up to `250mm` and the Maximum length can reach `200mm` horizontally. Due to the nature of the PLA material, the Robot can bear a 250gms payload.
Different sets of bearings and screws are used for smooth joint movements.
Implemented inverse kinematics to calculate all the robot joints and made the stepper motors rotate according to the joint angles.

This project was built using embedded C. 





<!-- GETTING STARTED -->
## Getting Started

## NEMA 17  
It is the most commonly used stepper motor sized in various applications including 3D printers various CNC machines and Robotic arms. NEMA 17 has a standard frame size of 1.7 inches. The motor is a Bipolar (4-wire) configuration. NEMA 17 motors typically have a step angle of 1.8 degrees per step. To make one revolution it takes 200 steps to complete and make it suitable for high-precision applications. 
## A4988
It is the specific motor driver, especially for NEMA 17 motors. The driver has a maximum current limit of 2A. A4988 driver has micro-stepping features which are essential in operating the NEMA 17 in high precision.<br>
`Full Mode		200 steps` <br>
`Half Mode		400 steps` <br>
`1/4 Mode		800 steps`  <br>
`1/8 Mode		1600 steps` <br>
`1/16 Mode		3200 steps`.

## Inverse Kinematics
Inverse kinematics is a mathematical approach used in robotics to determine the joint configurations required to position a robotic arm or end-effector at a specific location and orientation in three-dimensional space.
![Arm geometery][Kinematics_diagram]


### Prerequisites

`Software - Keil u vision` <br> 
`Hardware - STM32F1 microcontroller` <br> 
            &emsp;&emsp;&emsp;&emsp;&emsp; `A4988 Motor drivers` <br> 
            &emsp;&emsp;&emsp;&emsp;&emsp; `NEMA 17 Stepper motors` <br> 
            &emsp;&emsp;&emsp;&emsp;&emsp; `Power supply (0-30V)`

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/vamsikrishnaA9/Robotic_Arm.git
   ```
2. Connect the circuit as specified.

<!-- USAGE EXAMPLES -->
## Usage

_1. double *inv_KE(double X3, double Y3, double Z3)_ <br> 
This function solves the inverse kinematics for the given coordinates `X3, Y3, Z3` and returns the pointer of 3 joint angles. <br>

_2. void Robot_target(double* Out)_ <br> 
This function sets the target coordinates based on the previous position of the Arm robot. <br> 

_3. void Robot_move(double angle, int type)_ <br> 
This function rotates the stepper motors at the desired angle.



<!-- CONTRIBUTING -->
## Contributing

Contributions are what makes the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request




<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.



<!-- CONTACT -->
## Contact

Vamsi Krishna - [vamsi.vk1596@gmail.com](vamsi.vk1596@gmail.com) 

Project Link: [https://github.com/vamsikrishnaA9/Robotic_Arm](https://github.com/vamsikrishnaA9/Robotic_Arm)



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/vamsikrishnaA9/Robotic_Arm/graphs/contributors
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/vamsikrishnaA9/Robotic_Arm/blob/main/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/vamsikrishna112/
[product-screenshot]: /Image.jpeg
[Kinematics_diagram]: /Arm_geometry.jpeg

