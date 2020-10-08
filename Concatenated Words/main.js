class Trie {
  constructor() {
    this.isWordEnding = false;
    this.children = [];
  }

  add(node, word, cursor) {
    if (cursor == word.length) {
      node.isWordEnding = true;
      return;
    }

    const position = charToIndex(word[cursor]);
    if (!node.children[position]) {
      node.children[position] = new Trie();
    }
    this.add(node.children[position], word, cursor + 1);
  }

  contains(node, word, cursor) {
    if (cursor == word.length) {
      return node.isWordEnding;
    }

    const position = charToIndex(word[cursor]);
    if (!node.children[position]) {
      return false;
    }
    return this.contains(node.children[position], word, cursor + 1);
  }
}

function charToIndex(c) {
  return c.charCodeAt(0) - "a".charCodeAt(0);
}

let t;

function solve(word, cursor, count) {
  if (word.length == cursor) {
    return count >= 2;
  }

  let node = t;

  for (let i = cursor; i < word.length; i++) {
    const nextIndex = charToIndex(word[i]);
    const nextNode = node.children[nextIndex];

    if (!nextNode) {
      return false;
    }

    node = nextNode;

    if (node.isWordEnding) {
      if (solve(word, i + 1, count + 1)) {
        return true;
      }
    }
  }
}

var findAllConcatenatedWordsInADict = function (words) {
  t = new Trie();
  const solution = [];
  for (const word of words) {
    t.add(t, word, 0);
  }

  for (const word of words) {
    if (solve(word, 0, 0)) {
      solution.push(word);
    }
  }
  return solution;
};

const solution = findAllConcatenatedWordsInADict([
  "cat",
  "cats",
  "catsdogcats",
  "dog",
  "dogcatsdog",
  "hippopotamuses",
  "rat",
  "ratcatdogcat",
]);
