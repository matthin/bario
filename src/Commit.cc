#include "Commit.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

namespace ba {

Commit::Commit(const std::vector<Contrast> contrasts)
  : contrasts(contrasts), id(generateID()) {}

std::string Commit::generateID() const noexcept {
  std::string preHashedMessage;
  for (const auto contrast : contrasts) {
    preHashedMessage += contrast.modifiedText;
  }

  unsigned char hashedMessage[SHA256_DIGEST_LENGTH];
  SHA256(
    reinterpret_cast<const unsigned char*>(preHashedMessage.c_str()),
    preHashedMessage.length(), hashedMessage
  );

  std::ostringstream decodedHash;
  for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
    decodedHash << std::hex << std::setw(2) << std::setfill('0')
                << static_cast<int>(hashedMessage[i]);
  }
  return decodedHash.str();
}

} // namespace ba

