package algorithm.string;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import org.junit.Test;

/**
 * ReverseTest
 */
public class RotateTest {

    @Test
    public void testStringRotate() {
        assertEquals("cdefab", this.rotate("abcdef", 2));
    }

    /**
     *
     * @param str
     * @param m:  move head to tail m times
     * @return
     */
    private String rotate(String str, int m) {
        m %= str.length();
        char[] chars = str.toCharArray();
        this.reverse(chars, 0, m);
        this.reverse(chars, m, chars.length);
        this.reverse(chars, 0, chars.length);
        return new String(chars);
    }

    private void reverse(char[] chars, int start, int end) {
        for (int i = start, j = end - 1; i < j; i++, j--) {
            char c = chars[i];
            chars[i] = chars[j];
            chars[j] = c;
        }
    }

    @Test
    public void testListReverse() {
        List<Integer> list1 = new ArrayList<>(6);
        Collections.addAll(list1, 1, 2, 3, 4, 5, 6);
        List<Integer> list2 = new ArrayList<>(6);
        Collections.addAll(list2, 2, 1, 6, 5, 4, 3);
        assertTrue(this.checkList(this.reverse(list1, 2), list2));
    }

    private boolean checkList(List<Integer> list1, List<Integer> list2) {
        if (list1.size() != list2.size())
            return false;
        for (int i = 0; i < list1.size(); i++) {
            if (list1.get(i) != list2.get(i)) {
                return false;
            }
        }
        return true;
    }

    private List<Integer> reverse(List<Integer> list, int m) {
        for (int i = 0, j = m - 1; i < j; i++, j--) {
            Integer temp = list.get(i);
            list.set(i, list.get(j));
            list.set(j, temp);
        }
        for (int i = m, j = list.size() - 1; i < j; i++, j--) {
            Integer temp = list.get(i);
            list.set(i, list.get(j));
            list.set(j, temp);
        }
        return list;
    }

    @Test
    public void testReverseSentence() {
        assertEquals(this.reverseSentence("I am a student. "), " student. a am I");
    }

    private String reverseSentence(String sentence) {
        char[] chars = sentence.toCharArray();
        int start = 0;
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == ' ') {
                this.reverse(chars, start, i);
                start = i + 1;
            }
        }
        this.reverse(chars, start, chars.length);
        this.reverse(chars, 0, chars.length);
        return new String(chars);
    }

}
