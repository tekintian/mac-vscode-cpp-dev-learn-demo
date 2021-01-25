# mac-vscode-cpp-dev-learn-demo

mac vscode c++ development and learn demo

## c++配置文件

- vscode c++开发运行配置文件

.vscode/c_cpp_properties.json

```json
{
  "configurations": [
    {
      "name": "Mac",
      "includePath": ["${workspaceFolder}/**"],
      "defines": [],
      "macFrameworkPath": [],
      "compilerPath": "/usr/bin/g++",
      "cStandard": "c11",
      "cppStandard": "c++17",
      "intelliSenseMode": "macos-gcc-x64"
    }
  ],
  "version": 4
}
```

- Debug 配置文件
  .vscode/launch.json

```json
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "name": "g++ - Build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "MIMode": "lldb",
      "preLaunchTask": "C/C++: g++ build active file"
    }
  ]
}
```

.vscode/settings.json

```json
{
  "files.associations": {
    "iostream": "cpp",
    "iosfwd": "cpp",
    "ostream": "cpp",
    "exception": "cpp"
  },
  "editor.formatOnSave": true,
  "editor.defaultFormatter": "esbenp.prettier-vscode",
  "editor.codeActionsOnSave": ["source.fixAll.format", "source.fixAll.eslint"],
  "[cpp]": {
    "editor.defaultFormatter": "ms-vscode.cpptools"
  }
}
```
