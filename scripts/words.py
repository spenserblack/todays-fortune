#!/usr/bin/env python3
import os
from collections.abc import Iterable
from typing import TextIO

if __name__ != "__main__":
    raise NotImplementedError("Usage as a library")

ROOT = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
SRC = os.path.join(ROOT, "./src")
WORDS = os.path.join(ROOT, "./words")
SNIPPETS = os.path.join(ROOT, "snippets")

def open_word_list(name: str):
    """
    Opens a file in read-only mode. The name doesn't need the ``.txt`` extension.
    """
    global WORDS
    return open(os.path.join(WORDS, f"{name}.txt"), "r")

def write_array(fp: TextIO, ident: str, list_name: str):
    fp.write("const char *")
    fp.write(ident)
    fp.write("[] = {")
    with open_word_list(list_name) as word_list:
        words = (f'"{line.strip()}"' for line in word_list)
        implementation.write(", ".join(words))
    fp.write("};\n")

with open(os.path.join(SRC, "words.c"), "w") as implementation:
    implementation.write("/** GENERATED - DO NOT EDIT **/\n\n")

    with open(os.path.join(SNIPPETS, "words/head.c"), "r") as head:
        implementation.write(head.read())

    write_array(implementation, "nouns", "nouns")
    write_array(implementation, "verbs", "verbs")
    write_array(implementation, "adjectives", "adjectives")

    with open(os.path.join(SNIPPETS, "words/tail.c"), "r") as tail:
        implementation.write(tail.read())
