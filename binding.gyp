{
    "targets": [
        {
            "target_name": "lexactivator",
            "sources": [
                "src/main.cpp"
            ],
            "cflags!": [
                "-fno-exceptions"
            ],
            "cflags_cc!": [
                "-fno-exceptions"
            ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            "dependencies": [
                "<!(node -p \"require('node-addon-api').gyp\")"
            ],
            'variables': {
                'ssl_dependencies%' : "<!(node -p \"require('detect-libc').isNonGlibcLinux ? '' : '-lssl3 -lnss3 -lnspr4'\")",
            },
            "conditions": [
                [
                    "OS == 'linux'",
                    {
                        "libraries": [
                            "-Wl,-Bstatic  -L<(module_root_dir) -lLexActivator -Wl,-Bdynamic -lpthread <(ssl_dependencies)"
                        ]
                    }
                ],
                [
                    "OS == 'mac'",
                    {
                        "libraries": [
                            "-Wl -L<(module_root_dir) -lLexActivator -framework CoreFoundation -framework SystemConfiguration -framework Security"
                        ]
                    }
                ],
                [
                    "OS == 'win'",
                    {
                        "libraries": [
                            "<(module_root_dir)/LexActivator.lib"
                        ],
                        "copies": [
                            {
                                "files": [
                                    "<(module_root_dir)/LexActivator.dll"
                                ],
                                "destination": "<(module_path)"
                            }
                        ]
                    }
                ]
            ],
            "defines": [
                "NAPI_DISABLE_CPP_EXCEPTIONS",
                "NAPI_VERSION=<(napi_build_version)"
            ],
            "xcode_settings": {
                "CLANG_CXX_LIBRARY": "libc++",
                "MACOSX_DEPLOYMENT_TARGET": "10.7"
            }
        },
        {
            "target_name": "action_after_build",
            "type": "none",
            "dependencies": [
                "<(module_name)"
            ],
            "copies": [
                {
                    "files": [
                        "<(PRODUCT_DIR)/<(module_name).node"
                    ],
                    "destination": "<(module_path)"
                }
            ]
        }
    ]
}