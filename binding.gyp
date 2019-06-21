{
    "targets": [
        {
            "target_name": "lexactivator",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "sources": ["lib/main.cpp"],
            'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
            'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
            'libraries': ["-Wl,-rpath,. -L../ -lLexActivator"],
            'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS']
        }
    ]
}
