# ThreeJS

### Introduction

To actually be able to display anything with three.js, we need three things: scene, camera and renderer, so that we can render the scene with camera.

- Scenes allow you to set up what and where is to be rendered by three.js. This is where you place objects, lights and cameras.

- PerspectiveCamera : This projection mode is designed to mimic the way the human eye sees. It is the most common projection mode used for rendering a 3D scene.

```
PerspectiveCamera( fov : Number, aspect : Number, near : Number, far : Number )
fov — Camera frustum vertical field of view.
aspect — Camera frustum aspect ratio.
near — Camera frustum near plane.
far — Camera frustum far plane.
```

FOV is the extent of the scene that is seen on the display at any given moment. The value is in degrees.

The second one is the aspect ratio. You almost always want to use the width of the element divided by the height, or you'll get the same result as when you play old movies on a widescreen TV - the image looks squished.

In 3D computer graphics, the view frustum (also called viewing frustum) is the region of space in the modeled world that may appear on the screen; it is the field of view of a perspective virtual camera system.

- WebGLRenderer : The WebGL renderer displays our beautifully crafted scenes using WebGL.

<img src="https://en.wikipedia.org/wiki/File:ViewFrustum.svg">
