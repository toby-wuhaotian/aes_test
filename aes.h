#pragma once
#ifndef AES_H
#define AES_H

#include <vector>
#include <cstdint>

class AesEncryption
{
public:
	AesEncryption(const std::vector<uint8_t>& key);
	std::vector<uint8_t> encrypt(const std::vector<uint8_t>& plaintext);

private:
	void keyExpansion(const std::vector<uint8_t>& key);
	void subBytes(std::vector<uint8_t>& state);
	void shiftRows(std::vector<uint8_t>& state);
	void mixColumns(std::vector<uint8_t>& state);
	uint8_t gfmultby02(uint8_t b);
	uint8_t gfmultby03(uint8_t b);
	uint8_t gfmultby09(uint8_t b);
	uint8_t gfmultby0b(uint8_t b);
	uint8_t gfmultby0d(uint8_t b);
	uint8_t gfmultby0e(uint8_t b);

	std::vector<uint8_t> m_key;
	int m_nk;
	int m_nr;
};

#endif