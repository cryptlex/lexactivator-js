{
    "targets": [
        {
            "target_name": "lexactivator",
            "sources": ["src/main.cpp"],
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
            'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
            'libraries': ["-Wl,-rpath,<!(node -p 'process.cwd()') -L<!(node -p 'process.cwd()') -lLexActivator"],
            'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS'],
            'xcode_settings': {
                'CLANG_CXX_LIBRARY': 'libc++',
                'MACOSX_DEPLOYMENT_TARGET': '10.7'
            },
        }
    ]
}
