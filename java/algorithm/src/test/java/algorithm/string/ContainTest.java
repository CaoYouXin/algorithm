package algorithm.string;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import org.junit.Test;

/**
 * ContainTest
 */
public class ContainTest {

    @Test
    public void testContain() {
        assertTrue(contain("ABCD", "ABC"));
        assertFalse(contain("ABCD", "ADG"));
    }

    private boolean contain(String big, String small) {
        int bitMap = 0;
        char[] bigChars = big.toCharArray();
        for (int i = 0; i < bigChars.length; i++) {
            bitMap |= 1 << (bigChars[i] - 'A');
        }
        char[] smallChars = small.toCharArray();
        for (int i = 0; i < smallChars.length; i++) {
            if ((bitMap & (1 << (smallChars[i] - 'A'))) == 0) {
                return false;
            }
        }
        return true;
    }

    @Test
    public void testDictSearchForBrother() {
        List<String> dict = new ArrayList<>();
        Collections.addAll(dict, "abc", "acb", "aba", "adg");
        assertArrayEquals(new String[] { "abc", "acb" }, this.search(dict, "abc").toArray(new String[0]));
    }

    private List<String> search(List<String> dict, String word) {
        List<String> results = new ArrayList<>();
        WordSnapshot snapshot = new WordSnapshot(word);
        dict.forEach(w -> {
            if (snapshot.compare(w)) {
                results.add(w);
            }
        });
        return results;
    }

    class WordSnapshot {
        static final int SIZE = 26;

        private int[] snapshot;

        public WordSnapshot(String word) {
            this.snapshot = this.parse(word);
        }

        private int[] parse(String word) {
            int[] snapshot = new int[WordSnapshot.SIZE];
            for (int i = 0; i < word.length(); i++) {
                snapshot[word.charAt(i) - 'a']++;
            }
            return snapshot;
        }

        public boolean compare(String word) {
            // copy a snapshot
            int[] copy = new int[WordSnapshot.SIZE];
            for (int i = 0; i < WordSnapshot.SIZE; i++) {
                copy[i] = this.snapshot[i];
            }

            // reduce the copy of a snapshot
            for (int i = 0; i < word.length(); i++) {
                int j = word.charAt(i) - 'a';
                copy[j]--;
                if (copy[j] < 0) {
                    return false;
                }
            }

            // check what the copy left
            for (int i = 0; i < WordSnapshot.SIZE; i++) {
                if (copy[i] > 0) {
                    return false;
                }
            }

            // all pass, this is a brother
            return true;
        }
    }

}
