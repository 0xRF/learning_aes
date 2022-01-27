#pragma once

#include <stdint.h>
#include <stddef.h>

// Stages of AES
// KeyExpansion
//
// Initial Round
//	Add RoundKeys
//
// Do The Rounds (amount determined by the key size)
//	Sub Bytes
//	Shift Rows
//	MixColoumns
//	AddRoundKey
//	Repeat
//
// Final Round
//	Sub Bytes
//	Shift Rows
//	AddRoundKey

// nothing else should be
typedef struct AlgInfo_t {
  int KeySize;
  int BlockSize;
  int Nb;
  int Nk;
  int Nr;
} AlgInfo;

/// Encrypt Rijndael, lengths are in bytes not bits
/// \param message
/// \param key
/// \param messageLength
/// \param keySize
/// \param blockSize
/// \return
uint8_t *encrypt_rijndael(char *message, char *key, int messageLength,
                          int keySize, int blockSize);
uint32_t* KeyExpansion(const uint8_t* originalKey, AlgInfo info);



void AddRoundKey(uint32_t* state, const uint32_t* roundKey, AlgInfo info);
void Round(uint32_t* state, uint32_t* roundKey, size_t index, AlgInfo info);
void FinalRound(uint32_t* state, uint32_t* roundKey, AlgInfo info);

void SubByte (uint8_t* bytes, size_t count);
uint32_t RotByte(uint32_t word);
//uint8_t Rcon(uint32_t index);

void ShiftRow(uint32_t* state, AlgInfo info);
void MixColumn(uint32_t* state, AlgInfo info);