// In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. 
// The order of the alphabet is some permutation of lowercase letters.
// Given a sequence of words written in the alien language, and the order of the alphabet, return true if and 
// only if the given words are sorted lexicographically in this alien language.

function isAlienSorted(words, order) {
    // Create a mapping of each character in the alien language to its index in the given order
    const orderMap = {};
    for (let i = 0; i < order.length; i++) {
        orderMap[order[i]] = i;
    }

    // Helper function to compare two words based on the alien language order
    function compare(word1, word2) {
        const len = Math.min(word1.length, word2.length);
        for (let i = 0; i < len; i++) {
            const char1 = word1[i];
            const char2 = word2[i];
            
            // If the characters are different, compare their positions in the alien order
            if (char1 !== char2) {
                return orderMap[char1] < orderMap[char2];
            }
        }
        // If one word is a prefix of the other, the shorter word should come first
        return word1.length <= word2.length;
    }

    // Compare each pair of adjacent words
    for (let i = 0; i < words.length - 1; i++) {
        if (!compare(words[i], words[i + 1])) {
            return false;
        }
    }

    return true;
}

const words = ["aello", "leetcode"];
const order = "hlabcdefgijkmnopqrstuvwxyz";
const isSorted = isAlienSorted(words, order);  

if (isSorted) {
    console.log('the words are sorted');
} else {
    console.log('the words areN\'T sorted');
}

