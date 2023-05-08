<h2>Razor Engine</h2>
<small>Occam LLC.</small>
<hr/>

<h3>Setup Instructions</h3>
<h4>Windows:</h4>

- Install vcpkg
```command
cd DIRECTORY_FOR_VCPKG
git clone https://github.com/Microsoft/vcpkg.git
cd ./vcpkg
.\vcpkg\bootstrap-vcpkg.bat
vcpkg integrate install
```
- Install Vulkan SDK: https://vulkan.lunarg.com/sdk/home#windows
- Install GLFW Library: 
```command
.\vcpkg install glfw3:x86-windows glfw3:x64-windows
```
- Install Vulkan Library:
```command 
vckpg install vulkan:x86-windows vulkan:x64-windows
```