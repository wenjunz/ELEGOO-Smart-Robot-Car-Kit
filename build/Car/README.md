# About

## Getting Started

### Installation

1. Go to Releases:

      <img src="/assets/first.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" />

2. Download the leatest Release:

    <img src="/assets/second.png"
    alt="Markdown Monster icon"
    style="float: left; margin-right: 10px;" />

3. Go to Arduino IDE and there go to Sketch:

    <img src="/assets/third.png" alt="Markdown Monster icon" style="float: left; margin-right: 10px;" />

4. Select Include Library, then Include from ZIP file and Select the ZIP archive that you've downloaded from the repo:

  <img src="/assets/forth.png"
  alt="Markdown Monster icon"
  style="float: left; margin-right: 10px;" />

### Include Library

1. Go to Arduino IDE and there go to Sketch:

    <img src="/assets/third.png" alt="Markdown Monster icon" style="float: left; margin-right: 10px;" />

2. Select Include Library, then select Car:

  <img src="/assets/forth.png"
  alt="Markdown Monster icon"
  style="float: left; margin-right: 10px;" />

3. Now it should look like this:

  <img src="/assets/fifth.png"
  alt="Markdown Monster icon"
  style="float: left; margin-right: 10px;" />

### First Steps

### First Commands

| **Command** | **Explenation** |
|:---:|---|
| car.init() | This argument is needed in every code. It is to initialize the the library.  In the brackets you can put the version of your robot. The default version is 3. |
| car.forward()<br>  car.backward()<br>  car.left()<br>  car.right()<br>  car.stop() | These arguments explain themself. Into the brackets you can put a number between 1 and 256 for the speed. The default speed is 255. |
| car.forwardT() <br>   car.backwardT() <br>   car.leftT() <br>   car.rightT() | The arguments function just like the others but you have to put the time and the speed into the brackets. <br> With a syntax like this: <br> ``` car.forwardT(SPEED, TIME); ``` <br>You can choose a number between 1 and 255.  |
| car.getDistance() | This is a function to get the distance from the Ultrasonic sensor. It returns it as an Integer. |

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request
