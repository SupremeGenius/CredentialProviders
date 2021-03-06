#pragma once
#include "common_defs.h"
class HMacSha1 :
	public IMac
{
private:
	int						HASH_LEN = 32;
	int						DERIVED_KEY_LEN = 60;
	int						ITERATION_COUNT = 12000;
	BCRYPT_ALG_HANDLE		hAlg = NULL;
	BCRYPT_HASH_HANDLE		hHash = NULL;
	PBYTE                   pbHashObject = NULL;
	void Cleanup();
public:
	HMacSha1();
	~HMacSha1();

	NTSTATUS Hash(PUCHAR message, ULONG size, PUCHAR hmacKey, ULONG hmacKeyLen, PUCHAR hash);
	NTSTATUS DeriveKey(PUCHAR password, int passLen, PUCHAR key, ULONG keyLen);
};

