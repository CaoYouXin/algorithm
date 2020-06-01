package algorithm.string;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

/**
 * StringConvTest
 */
public class StringConvTest {

    @Test
    public void testAtoi() {
        assertEquals(3, this.atoi("3"));
        assertEquals(3, this.atoi("+3"));
        assertEquals(-3, this.atoi("-3"));
        try {
            this.atoi("-2147483649");
        } catch (Exception exp) {
            assertEquals("the number is too small", exp.getMessage());
        }
        try {
            this.atoi("+2147483648");
        } catch (Exception exp) {
            assertEquals("the number is too big", exp.getMessage());
        }
    }

    public int atoi(String str) {
        char[] chars = str.toCharArray();
        int idx = 0;

        while (chars[idx] == ' ') {
            idx++;
        }

        int flag = chars[idx] == '-' ? -1 : 1;
        if (chars[idx] == '-' || chars[idx] == '+') {
            idx++;
        }

        int n = 0;
        while (idx < chars.length) {
            int c = chars[idx++] - '0';
            if (flag > 0) {
                if (n > Integer.MAX_VALUE / 10 || n == Integer.MAX_VALUE / 10 && c > Integer.MAX_VALUE % 10) {
                    throw new RuntimeException("the number is too big");
                }
            } else {
                if (n > -((long) Integer.MIN_VALUE) / 10
                        || n == -((long) Integer.MIN_VALUE) / 10 && c > -((long) Integer.MIN_VALUE) % 10) {
                    throw new RuntimeException("the number is too small");
                }
            }
            n = n * 10 + c;
        }

        return flag * n;
    }

}
