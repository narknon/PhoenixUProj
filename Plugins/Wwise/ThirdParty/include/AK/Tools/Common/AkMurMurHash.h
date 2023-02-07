/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the
"Apache License"); you may not use this file except in compliance with the
Apache License. You may obtain a copy of the Apache License at
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

Version: v2021.1.9  Build: 7847
Copyright (c) 2006-2022 Audiokinetic Inc.
*******************************************************************************/

#ifndef _AKMURMURHASH_H_
#define _AKMURMURHASH_H_

#include <AK/SoundEngine/Common/AkTypes.h>
#include <AK/Tools/Common/AkPlatformFuncs.h>

// https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp

#define MURMUR3_SEED	( 0x41545731 )
#define MURMUR3_C1		( 0xcc9e2d51 )
#define MURMUR3_C2		( 0x1b873593 )
#define MURMUR3_C3		( 0xe6546b64 )

AkForceInline AkUInt32 AkHashMurMurMix32( AkUInt32 uValue )
{
	uValue ^= uValue >> 16;
	uValue *= 0x85ebca6b;
	uValue ^= uValue >> 13;
	uValue *= 0xc2b2ae35;
	uValue ^= uValue >> 16;
	return uValue;
}

AkForceInline AkUInt64 AkHashMurMurMix64( AkUInt64 uValue ) {
	uValue ^= uValue >> 33;
	uValue *= 0xff51afd7ed558ccd;
	uValue ^= uValue >> 33;
	uValue *= 0xc4ceb9fe1a85ec53;
	uValue ^= uValue >> 33;
	return uValue;
}

AkForceInline void AkHashMurMur32( AkUInt32* pHash, const void* pData, size_t uSize ) {
	AkUInt32 uH1 = MURMUR3_SEED;
	AkUInt8* pBytes = ( AkUInt8* )pData;
	AkUInt32 uNumBlocks = ( AkUInt32 )( uSize / 4 );
	AkUInt32* pBlocks = ( AkUInt32* )( pBytes + ( uNumBlocks * 4 ) );
	for ( AkInt32 i = -( AkInt32 )uNumBlocks; i; ++i ) {
		AkUInt32 uK1 = *( AkUInt32* )( pBlocks + i );
		uK1 *= MURMUR3_C1;
		uK1 = AK::ROTL32( uK1, 15 );
		uK1 *= MURMUR3_C2;
		uH1 ^= uK1;
		uH1 = AK::ROTL32( uH1, 13 );
		uH1 = uH1 * 5 + MURMUR3_C3;
	}
	AkUInt8* pBytesTail = ( AkUInt8* )( pBytes + ( uNumBlocks * 4 ) );
	AkUInt32 uK1 = 0;
	switch ( uSize & 3 ) {
	case 3: uK1 ^= pBytesTail[ 2 ] << 16;
	case 2: uK1 ^= pBytesTail[ 1 ] << 8;
	case 1: uK1 ^= pBytesTail[ 0 ];
			uK1 *= MURMUR3_C1;
			uK1 = AK::ROTL32( uK1, 15 );
			uK1 *= MURMUR3_C2;
			uH1 ^= uK1;
	}
	uH1 ^= uSize;
	uH1 = AkHashMurMurMix32( uH1 );
	*pHash = uH1;
}

#endif // _AKMURMURHASH_H_
