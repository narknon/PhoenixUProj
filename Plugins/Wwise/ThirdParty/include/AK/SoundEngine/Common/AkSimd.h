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

// AkSimd.h

/// \file 
/// Simd definitions.

#ifndef _AK_SIMD_H_
#define _AK_SIMD_H_

#include <AK/SoundEngine/Common/AkTypes.h>

// Platform-specific section.
//----------------------------------------------------------------------------------------------------

#if defined( AK_WIN ) || defined( AK_XBOX )
	
	#include <AK/SoundEngine/Platforms/Windows/AkSimd.h>

#elif defined( AK_APPLE )

	#include <TargetConditionals.h>
	#if TARGET_OS_IPHONE
		#include <AK/SoundEngine/Platforms/iOS/AkSimd.h>
	#else
		#include <AK/SoundEngine/Platforms/Mac/AkSimd.h>
	#endif

#elif defined( AK_ANDROID )

	#include <AK/SoundEngine/Platforms/Android/AkSimd.h>

#elif defined( AK_PS4 )

	#include <AK/SoundEngine/Platforms/PS4/AkSimd.h>
	
#elif defined( AK_PS5 )

	#include <AK/SoundEngine/Platforms/PS5/AkSimd.h>

#elif defined( AK_LINUX )

	#include <AK/SoundEngine/Platforms/Linux/AkSimd.h>

#elif defined( AK_EMSCRIPTEN )

	#include <AK/SoundEngine/Platforms/Emscripten/AkSimd.h>

#elif defined( AK_QNX )

	#include <AK/SoundEngine/Platforms/QNX/AkSimd.h>

#elif defined( AK_NX )

	#include <AK/SoundEngine/Platforms/NX/AkSimd.h>

#else
	#error Unsupported platform, or platform-specific SIMD not defined
#endif

#ifndef AKSIMD_ASSERTFLUSHZEROMODE
	#define AKSIMD_ASSERTFLUSHZEROMODE
#endif

#ifndef AKSIMD_DECLARE_V4F32_TYPE
	#define AKSIMD_DECLARE_V4F32_TYPE AKSIMD_V4F32
#endif

#ifndef AKSIMD_DECLARE_V4I32_TYPE
	#define AKSIMD_DECLARE_V4I32_TYPE AKSIMD_V4I32
#endif

#ifndef AKSIMD_DECLARE_V4F32
	#define AKSIMD_DECLARE_V4F32( _x, _a, _b, _c, _d ) AKSIMD_DECLARE_V4F32_TYPE _x = { _a, _b, _c, _d }
#endif

#ifndef AKSIMD_DECLARE_V4I32
	#define AKSIMD_DECLARE_V4I32( _x, _a, _b, _c, _d ) AKSIMD_DECLARE_V4I32_TYPE _x = { _a, _b, _c, _d }
#endif

#ifndef AKSIMD_SETELEMENT_V4F32
	#define AKSIMD_SETELEMENT_V4F32( __vName__, __num__, __value__ ) ( AKSIMD_GETELEMENT_V4F32( __vName__, __num__ ) = (__value__) )
#endif

/// Rotate four vectors. After rotation:
///  A[3:0] = D[0] C[0] B[0] A[0]
///  B[3:0] = D[1] C[1] B[1] A[1]
///  C[3:0] = D[2] C[2] B[2] A[2]
///  D[3:0] = D[3] C[3] B[3] A[3]
AkForceInline void AKSIMD_TRANSPOSE4X4_V4F32(AKSIMD_V4F32 &A, AKSIMD_V4F32 &B, AKSIMD_V4F32 &C, AKSIMD_V4F32 &D)
{
	AKSIMD_V4F32 tmp1, tmp2, tmp3, tmp4;		
	tmp1 = AKSIMD_MOVELH_V4F32(A, B);
	tmp2 = AKSIMD_MOVEHL_V4F32(B, A);
	tmp3 = AKSIMD_MOVELH_V4F32(C, D);
	tmp4 = AKSIMD_MOVEHL_V4F32(D, C);

	A = AKSIMD_SHUFFLE_V4F32(tmp1, tmp3, AKSIMD_SHUFFLE(2, 0, 2, 0));
	B = AKSIMD_SHUFFLE_V4F32(tmp1, tmp3, AKSIMD_SHUFFLE(3, 1, 3, 1));
	C = AKSIMD_SHUFFLE_V4F32(tmp2, tmp4, AKSIMD_SHUFFLE(2, 0, 2, 0));
	D = AKSIMD_SHUFFLE_V4F32(tmp2, tmp4, AKSIMD_SHUFFLE(3, 1, 3, 1));
}

#endif  //_AK_DATA_TYPES_H_
