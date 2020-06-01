package algorithm.string;

import static org.junit.Assert.assertTrue;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.junit.Test;

public class StrConvFromDoubleTest {

    private final static double GAP = 0.01;
    private final static StringConvTest Util = new StringConvTest();

    @Test
    public void test() {
        check("0.0", 0.0);
        check("1", 1.0);
        check("-1", -1.0);
        check("0.1", 0.1);
        check("-0.1", -0.1);
        check("1.1", 1.1);
        check("-1.1", -1.1);
        check("1.1e10", 1.1e10);
        check("1.1e-10", 1.1e-10);
        check("-1.1e10", -1.1e10);
        check("-1.1e-10", -1.1e-10);
    }

    private void check(String str, double num) {
        double res = this.atod(str);
        System.out.println(res);
        assertTrue("atod(" + str + ") != " + num, Math.abs(res - num) < StrConvFromDoubleTest.GAP);
    }

    private double atold(String str) {
        double d = 1.0;
        for (int i = 0; i < str.length(); i++)
            d *= 10;
        System.out.println("atold" + Util.atoi(str) + '\t' + d + '\t' + (Util.atoi(str) / d));
        return Util.atoi(str) / d;
    }

    private double atod(String str) {
        Pattern pattern = Pattern.compile("^(-?)(\\d*)(\\.?)(\\d*)(e?)(-?\\d*)$");
        Matcher matcher = pattern.matcher(str);
        if (matcher.find()) {
            for (int i = 1; i <= 5; i++) {
                System.out.print('\'' + matcher.group(i) + "'\t");
            }
            System.out.println();

            double res = Util.atoi(matcher.group(2));
            System.out.println(matcher.group(3).equals("."));
            if (matcher.group(3).equals("."))
                res += atold(matcher.group(4));
            System.out.println(matcher.group(1).equals("-"));
            if (matcher.group(1).equals("-"))
                res *= -1;

            System.out.println(matcher.group(5).equals("e"));
            if (matcher.group(5).equals("e")) {
                int e = Util.atoi(matcher.group(6));
                return res * Math.pow(10, e);
            }

            return res;
        }
        return 0;// Double.parseDouble(str);
    }

}
