# mac-vscode-cpp-dev-learn-demo

mac vscode c++ development and learn demo

## clang 开发环境安装

```shell
xcode-select --install
```

## vscode 环境变量

${file}  文件全路径包括扩展名
${fileDirname} 文件目录名称
${fileBasenameNoExtension}  基础文件名不包含扩展名
${workspaceFolder} 工作目录

## c++配置文件

- vscode c++开发运行配置文件

.vscode/c_cpp_properties.json

```json
{
  "configurations": [
    {
      "name": "Mac",
      "includePath": [
        "${workspaceFolder}/**",
        "/usr/local/include",
        "/Library/Developer/CommandLineTools/usr/include/c++/v1",
        "/Library/Developer/CommandLineTools/usr/lib/clang/12.0.0/include",
        "/Library/Developer/CommandLineTools/usr/include",
        "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include"
      ],
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

## Coder Runner 插件自定义配置

code --> preferences-->settings --> extenssion--> Run Code Configuration

Edit in Settings.json

```json
 // 将编译后的文件统一存放于项目根目录的bin文件夹中
    "c": "cd $dir && mkdir -p $workspaceRoot/bin  && gcc -std=c11 $fileName -o $workspaceRoot/bin/$fileNameWithoutExt && $workspaceRoot/bin/$fileNameWithoutExt",
    "cpp": "cd $dir && mkdir -p $workspaceRoot/bin && clang++ -std=c++17 -stdlib=libc++ -g $fileName -o $workspaceRoot/bin/$fileNameWithoutExt && $workspaceRoot/bin/$fileNameWithoutExt",
```

注意: code runner 默认的 g++ 不支持 lambda ,不支持 auto 关键字, 不支持使用{}初始化容器(如: vector<int> v{1,2,7,9} ), 不支持增强 for 循环 等等....

解决方法: 将 g++更换为 clang++ -std=c++17 -stdlib=libc+

## 注释自定义插件

Generate Doxygen Comments in VS Code
doxdocgen

在 settings.json 文件中增加

```json
  "doxdocgen.generic.authorEmail": "tekintian@gmail.com",
  "doxdocgen.generic.authorName": "TekinTian",
  "doxdocgen.generic.useGitUserEmail": true,
  "doxdocgen.generic.useGitUserName": true,
  "doxdocgen.file.copyrightTag": [
    "@copyright (C){year}  Tekin.cn All Right Reserved."
  ]
```

- Config options 配置项目
```json

  // The prefix that is used for each comment line except for first and last.
  "doxdocgen.c.commentPrefix": " * ",

  // Smart text snippet for factory methods/functions.
  "doxdocgen.c.factoryMethodText": "Create a {name} object",

  // The first line of the comment that gets generated. If empty it won't get generated at all.
  "doxdocgen.c.firstLine": "/**",

  // Smart text snippet for getters.
  "doxdocgen.c.getterText": "Get the {name} object",

  // The last line of the comment that gets generated. If empty it won't get generated at all.
  "doxdocgen.c.lastLine": " */",

  // Smart text snippet for setters.
  "doxdocgen.c.setterText": "Set the {name} object",

  // Doxygen comment trigger. This character sequence triggers generation of Doxygen comments.
  "doxdocgen.c.triggerSequence": "/**",

  // Smart text snippet for constructors.
  "doxdocgen.cpp.ctorText": "Construct a new {name} object",

  // Smart text snippet for destructors.
  "doxdocgen.cpp.dtorText": "Destroy the {name} object",

  // The template of the template parameter Doxygen line(s) that are generated. If empty it won't get generated at all.
  "doxdocgen.cpp.tparamTemplate": "@tparam {param} ",

  // File copyright documentation tag.  Array of strings will be converted to one line per element.  Can template {year}.
  "doxdocgen.file.copyrightTag": [
    "@copyright Copyright (c) {year}"
  ],

  // Additional file documentation.  Array of strings will be converted to one line per element.  Can template {year}, {date}, {author}, and {email}.
  "doxdocgen.file.customTag": [],

  // The order to use for the file comment. Values can be used multiple times. Valid values are shown in default setting.
  "doxdocgen.file.fileOrder": [
    "file",
    "author",
    "brief",
    "version",
    "date",
    "empty",
    "copyright",
    "empty",
    "custom"
  ],

  // The template for the file parameter in Doxygen.
  "doxdocgen.file.fileTemplate": "@file {name}",

  // Version number for the file.
  "doxdocgen.file.versionTag": "@version 0.1",

  // Set the e-mail address of the author.  Replaces {email}.
  "doxdocgen.generic.authorEmail": "you@domain.com",

  // Set the name of the author.  Replaces {author}.
  "doxdocgen.generic.authorName": "your name",

  // Set the style of the author tag and your name.  Can template {author} and {email}.
  "doxdocgen.generic.authorTag": "@author {author} ({email})",

  // If this is enabled a bool return value will be split into true and false return param.
  "doxdocgen.generic.boolReturnsTrueFalse": true,

  // The template of the brief Doxygen line that is generated. If empty it won't get generated at all.
  "doxdocgen.generic.briefTemplate": "@brief {text}",

  // The format to use for the date.
  "doxdocgen.generic.dateFormat": "YYYY-MM-DD",

  // The template for the date parameter in Doxygen.
  "doxdocgen.generic.dateTemplate": "@date {date}",

  // Decide if you want to get smart text for certain commands.
  "doxdocgen.generic.generateSmartText": true,

  // Whether include type information at return.
  "doxdocgen.generic.includeTypeAtReturn": true,

  // How many lines the plugin should look for to find the end of the declaration. Please be aware that setting this value too low could improve the speed of comment generation by a very slim margin but the plugin also may not correctly detect all declarations or definitions anymore.
  "doxdocgen.generic.linesToGet": 20,

  // The order to use for the comment generation. Values can be used multiple times. Valid values are shown in default setting.
  "doxdocgen.generic.order": [
    "brief",
    "empty",
    "tparam",
    "param",
    "return",
    "custom"
  ],

  // Custom tags to be added to the generic order. One tag per line will be added. You have to specify the prefix yourself.
  "doxdocgen.generic.customTags": [],

  // The template of the param Doxygen line(s) that are generated. If empty it won't get generated at all.
  "doxdocgen.generic.paramTemplate": "@param {param} ",

  // The template of the return Doxygen line that is generated. If empty it won't get generated at all.
  "doxdocgen.generic.returnTemplate": "@return {type} ",

  // Decide if the values put into {name} should be split according to their casing.
  "doxdocgen.generic.splitCasingSmartText": true,

  // Array of keywords that should be removed from the input prior to parsing.
  "doxdocgen.generic.filteredKeywords": [],

  // Substitute {author} with git config --get user.name.
  "doxdocgen.generic.useGitUserName": false,

  // Substitute {email} with git config --get user.email.
  "doxdocgen.generic.useGitUserEmail": false
```
