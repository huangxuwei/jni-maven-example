package com.github.projects.demoproc;

import org.junit.Test;
import com.github.projects.demoproc.DemoProc;

public class DemoProcTest {
    @Test
    public void testDemoProc() {
        DemoProc.initialize();
        String res = DemoProc.commit("Hello");
        System.out.println(res + '\n');
    }
}
