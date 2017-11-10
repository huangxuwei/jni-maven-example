package com.github.projects.demoproc;

import com.github.projects.utils.JavaUtils;

public class DemoProc {
    static {
        JavaUtils.loadLibrary("libexample.so");
    }

    public static native void initialize();
    public static native String commit(String filepath);
}

