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
      "includePath": ["${workspaceFolder}/**",
        "/usr/local/include",
        "/Library/Developer/CommandLineTools/usr/include/c++/v1",
        "/Library/Developer/CommandLineTools/usr/lib/clang/12.0.0/include",
        "/Library/Developer/CommandLineTools/usr/include",
        "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include"],
      "defines": [],
      "macFrameworkPath": [
        "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
      ],
      "compilerPath": "/usr/bin/clang",
      "cStandard": "c11",
      "cppStandard": "c++17",
      "intelliSenseMode": "clang-x64"
    }
  ],
  "version": 4
}
```

- Debug 配置文件
  .vscode/launch.json

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "clang++ - Build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": true,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "lldb",
      "preLaunchTask": "clang++ build active file"
    }
  ]
}
```

.vscode/settings.json

```json
{
    "c-cpp-compile-run.cpp-compiler": "/usr/bin/clang++",
    "c-cpp-compile-run.c-flags": "-std=c11",
    "c-cpp-compile-run.cpp-flags": "-std=c++17 -stdlib=libc++",
    "C_Cpp.errorSquiggles": "Disabled",
  "editor.formatOnSave": true,
  "editor.defaultFormatter": "esbenp.prettier-vscode",
  "editor.codeActionsOnSave": ["source.fixAll.format", "source.fixAll.eslint"],
  "[cpp]": {
    "editor.defaultFormatter": "ms-vscode.cpptools"
  }
}
```
