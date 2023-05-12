package Graph;
import org.junit.runner.*;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;


public class GraphJUnitRunner{
    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(GraphJUnitTest.class);
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }
        System.out.println("Test result: " + result.wasSuccessful());
    }
}
