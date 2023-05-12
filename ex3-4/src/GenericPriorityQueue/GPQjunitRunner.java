package GenericPriorityQueue;
import org.junit.runner.*;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;


public class GPQjunitRunner {
    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(GPQjunitTest.class);
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }
        System.out.println("Test result: " + result.wasSuccessful());
    }
}
