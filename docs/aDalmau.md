[HOME](index.md)

**Role:** Programmer

**Name:** Ausiàs Dalmau Roig

**Contact:**

  [Linkedin](https://www.linkedin.com/in/ausias-dalmau-roig-005bb3a3/)
  
  [GitHub](https://github.com/auusi9)
  
  Mail: ausiasdalmauroig@gmail.com

**My Job:**

I started working in the engine fixing some bugs, improving some features and adding new ones. From VS3, we needed to start developing a UI system. And that was my primary job. I developed all the UI system: rendering, components and behaviours. Once that was done, I started making the specific menus of the game using our scripting system.

Later when UI was more advanced than gameplay, I've been asked to help in that scrum to be able to reach our goals. So, I helped developing the Evil spirit behaviour and improving the camera.

Finally, I returned to UI to finish the menus and add more cool functionality.

**What i’ve done:**

-  Texture changing on Inspector
    - With this feature you can change the texture of any mesh, in the inspector.

![texture changing](https://lh3.googleusercontent.com/rLVeXjP6KX7ygB9QFgHf4ciD1iP_42fq0Fde-1PSyIM4lJgjNjTV3NqUa4w4PpvdQTccJYKCd_nSem1bW4r5X-7XlFn-1ktQLrB0QssjqxD7Vzq6tcFDK-SRnTTV3AcvYIHRXpVhcLY)

-  UI System
    - Canvas component:
        - Canvas manages the UI of the scene.
        - Focus and organizes the rendering order.
    - Rect Component:
        - Handles the position of the UI element of the scene.
    - Image Component:
        - Texture.
        - Color.
        - Alpha/Blend.
    - Button Component:
        - Texture.
        - Color.
        - Alpha/Blend.
        - OnPress function that handles.
    - Grid Component:
        - Grid organizes in a grid form several elements.
        
 -  Camera improvements:
    - Bullet physics made the car go crazy, and the camera was going crazy as well.
        - Fixed the camera to not go crazy, and to follow the car smoothly till he comes back to normal.
    - Smoothed a bit the camera when turning.
    
 -  Evil spirit item:
    - Main features:
      - Reverse control.
      - Debuf to lower the max speed and the acceleration.
    - Second player defense:
      - Second player can remove the evil spirit earlier pressing LT and RT continuosly.