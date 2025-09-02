const char* get_random_noun() {
  const unsigned int size = sizeof(nouns) / sizeof(char*);
  const unsigned int index = rand() % size;
  return nouns[index];
}

const char* get_random_verb() {
  const unsigned int size = sizeof(verbs) / sizeof(char*);
  const unsigned int index = rand() % size;
  return verbs[index];
}

const char* get_random_adjective() {
  const unsigned int size = sizeof(adjectives) / sizeof(char*);
  const unsigned int index = rand() % size;
  return adjectives[index];
}
