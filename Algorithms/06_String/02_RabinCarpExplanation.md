```
Text:  abcdabcbabcd
Pattern:   abcd

```

### Solution Explanation:

1. **Initialization**:

   - Initialize the text and pattern.
   - Calculate hash value of pattern and initial window of text.

2. **Preprocessing**:

   - Compute the rolling hash coefficient `h`.

3. **Searching**:
   - Slide the pattern over the text.
   - Compare hash values of pattern and current window.
   - If hash values match, do a character-by-character comparison to confirm the match.

### Step-by-Step Solution:

#### Initialization:

- Text: abcdabcbabcd
- Pattern: abcd

#### Preprocessing:

- Calculate `h`:

  - `d` is 256 (size of the alphabet).
  - `q` is 101 (a prime number).

  ```
  h = (256^3) % 101 = 531441 % 101 = 95
  ```

#### Searching:

1. Calculate initial hash values for pattern and first window of text:

   - Pattern hash: `p = (256^0 * 'a' + 256^1 * 'b' + 256^2 * 'c' + 256^3 * 'd') % 101 = (97 + 98*256 + 99*256^2 + 100*256^3) % 101 = 15400977 % 101 = 20`
   - Text window hash: `t = (256^0 * 'a' + 256^1 * 'b' + 256^2 * 'c' + 256^3 * 'd') % 101 = (97 + 98*256 + 99*256^2 + 100*256^3) % 101 = 15400977 % 101 = 20`

2. Compare hashes, they match. Perform character-by-character comparison, they match too. Print index 0.

3. Slide the window one position to the right:

   - Remove 'a' from the hash value.
   - Add 'a' from the next position.
   - Calculate new hash value for text window:
     ```
     t = ((20 - 97 * 95) * 256 + 101) % 101 = ((20 - 97 * 95) * 256 + 97) % 101 = ((20 - 9260) * 256 + 97) % 101 = (-9240 * 256 + 97) % 101 = (-2365440 + 97) % 101 = 49
     ```

4. Compare hashes, they don't match.

5. Slide the window again and repeat the process.

### Final Output:

```
Pattern found at index 0
```

This demonstrates how the Rabin-Karp algorithm efficiently searches for a pattern within a text using hashing. It's particularly useful for multiple pattern searches within a single text.
