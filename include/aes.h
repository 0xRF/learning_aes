#pragma once

#include <stdint.h>
#include <stddef.h>


uint8_t *Encrpyt(char *message, char *key, int messageLength);
uint32_t* KeyExpansion(const uint8_t* originalKey);
void AddRoundKey(uint32_t* state, const uint32_t* roundKey);
void Round(uint32_t* state, uint32_t* roundKey);
void FinalRound(uint32_t* state, uint32_t* roundKey);
void InitialRound(uint32_t* state, uint32_t* roundKey);
void SubByte (uint8_t* bytes, size_t count);
uint32_t RotByte(uint32_t word);
void ShiftRow(uint32_t* state);
void MixColumn(uint32_t* state);