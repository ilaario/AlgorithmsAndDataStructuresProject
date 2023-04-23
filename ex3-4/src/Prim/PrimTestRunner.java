package Prim;

import org.junit.runner.*;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class PrimTestRunner {
    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(PrimTest.class);

        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }

        System.out.println(result.wasSuccessful());
    }
}
