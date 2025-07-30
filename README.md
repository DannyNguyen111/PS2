# PS2
Hexaflake


This C++ project uses SFML to render a Hexaflake fractal by recursively drawing pointy-topped hexagons with customizable side length and recursion depth via command-line arguments. The program draws filled hexagons at the deepest recursion level and outlined hexagons at higher levels, all using a consistent color. Each recursion subdivides a hexagon into a center and six smaller surrounding hexagons, scaled to one-third the parent’s side length. Although the position formulas were based on the homework assignment’s hexagon geometry (using height calculated as length * sqrt(3)), I had to adjust scaling factors and offsets—such as multiplying vertical distances by about 1.18—to get the correct, visually pleasing arrangement of hexagons. The program includes input validation and framerate limiting for smooth rendering in a real-time SFML window.


<img width="798" height="838" alt="screenshot" src="https://github.com/user-attachments/assets/e6274769-3d52-42d0-9042-3e9493dac724" />
