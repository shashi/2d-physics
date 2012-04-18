Physics simulation
==================
- System: a collection of bodies and forces
    methods: nextFrame()
    attributes: bodies, forces
- Joint: a joint between two bodies
    types: glue, hinge
- Force: a force vector

- Transform: a transformation matrix

- Body: an object with some mass
    - Line: a 1-D line, like a rod
    - Shape: a 2-D shape
        methods: momentofinertia(), draw(), interactWith(Shape)
        attributes: density, youngs, friction, layer
        - Polygon: a polygon
            - Square
            - Rectangle

