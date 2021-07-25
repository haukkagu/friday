#include "Utils.h"
#include "BinarySerializer.h"

FRIDAY_PLATFORM_PATHSTR toFileMode(BinarySerializer::Mode mode) {
  switch(mode) {
    case BinarySerializer::Mode::Write:
      return FRIDAY_PLATFORM_CCHARPTR("wb");
      break;
    case BinarySerializer::Mode::Read:
      return FRIDAY_PLATFORM_CCHARPTR("rb");
      break;
  }

  return FRIDAY_PLATFORM_CCHARPTR("");
}

BinarySerializer::BinarySerializer(FRIDAY_PLATFORM_PATHSTR file_path, BinarySerializer::Mode mode) : m_closed(false), m_mode(mode) {
  #ifdef FRIDAY_LINUX
	m_file = fopen(file_path.c_str(), toFileMode(mode).c_str());
  #elif FRIDAY_WINDOWS
	m_file = _wfopen(file_path.c_str(), toFileMode(mode).c_str());
  #endif

  if (m_file == nullptr) m_closed = true;
}

BinarySerializer::~BinarySerializer() {
  close();
}

void BinarySerializer::close() {
  if (!m_closed) {
    fclose(m_file);
    m_closed = true;
  }
}

template<>
void BinarySerializer::readElement(std::string& str) {
  size_t length;
  readElement(length);

  str = std::string(length, '\0');
  fread(&str[0], sizeof(char), length, m_file);
}

template<>
void BinarySerializer::writeElement(const std::string& str)  {
  size_t length = str.length();
  writeElement(length);

  fwrite(&str[0], sizeof(char), length, m_file);
}
