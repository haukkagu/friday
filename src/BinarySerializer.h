#pragma once

#include <cstdio>
#include <vector>
#include <string>

class BinarySerializer {
public:
  enum Mode { Read, Write };
private:
  FILE* m_file;
  Mode m_mode;
  bool m_closed;
public:
  BinarySerializer(std::string file_path, Mode mode);
  ~BinarySerializer();

  inline bool isClosed() { return m_closed; }

  void close();

  template<typename T>
  void append(T& element) {
    switch(m_mode) {
      case Mode::Read:
        readElement(element);
        break;
      case Mode::Write:
        writeElement(element);
        break;
    }
  }

  template<typename T>
  void extend(std::vector<T>& list) {
    switch(m_mode) {
      case Mode::Read:
        readList(list);
        break;
      case Mode::Write:
        writeList(list);
        break;
    }
  }

private:
  template<typename T>
  void readElement(T& element) {
    fread(&element, sizeof(T), 1, m_file);
  }

  template<typename T>
  void writeElement(const T& element)  {
    fwrite(&element, sizeof(T), 1, m_file);
  }

  template<typename T>
  void readList(std::vector<T>& list) {
    size_t length;
    readElement(length);

    list = std::vector<T>(length);
    for (size_t i = 0; i < length; i++) {
      readElement(list[i]);
    }
  }

  template<typename T>
  void writeList(const std::vector<T>& list) {
    size_t length = list.size();
    writeElement(length);

    for (size_t i = 0; i < length; i++) {
      writeElement(list[i]);
    }
  }
};
