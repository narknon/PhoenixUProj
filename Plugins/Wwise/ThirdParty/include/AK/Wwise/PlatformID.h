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

/// \file
/// Unique identifiers for platforms in the Wwise authoring application.

#ifndef AK_WWISE_PLATFORMID_H
#define AK_WWISE_PLATFORMID_H

#if defined( _MSC_VER )
	#define AK_ID_DECLARE extern const _declspec( selectany )
#else
	#define AK_ID_DECLARE extern const __attribute__( ( weak ) )
#endif

struct BasePlatformID
{
	BasePlatformID():guid( GUID_NULL ){}

	// The Create function is a functionnal replacement for the BasePlatformID() constructor taking a GUID in parameters.
	// This is to avoid situations where someone would pass a GUID instead of a BasePlatformID in a function call while migrating, which would
	// compile but would lead the user into serious errors.
	static BasePlatformID Create( const GUID& in_BasePlatformID  )
	{
		BasePlatformID ret;
		ret.guid = in_BasePlatformID;
		return ret;
	}

	static BasePlatformID Empty()
	{
		return BasePlatformID::Create(GUID_NULL);
	}

	bool IsNull() const
	{
		return (guid == GUID_NULL) ? true : false;
	}

	bool operator == ( const BasePlatformID& in_rOther ) const
	{
		return (in_rOther.guid == guid)? true : false;
	}
	bool operator != ( const BasePlatformID& in_rOther ) const
	{
		return (in_rOther.guid != guid)? true : false;
	}
	GUID guid;

	struct GUIDLessNative
	{
		bool operator()( const BasePlatformID& in_rLeft, const BasePlatformID& in_rRight ) const
		{
			return ( ::memcmp( &in_rLeft, &in_rRight, sizeof(BasePlatformID) ) < 0 );
		}
	};
};

namespace PlatformID
{
    // {6E0CB257-C6C8-4c5c-8366-2740DFC441EB}
    AK_ID_DECLARE GUID Windows_unsafeguid = { 0x6E0CB257, 0xC6C8, 0x4c5c, { 0x83, 0x66, 0x27, 0x40, 0xDF, 0xC4, 0x41, 0xEB } };
	AK_ID_DECLARE BasePlatformID Windows = BasePlatformID::Create( Windows_unsafeguid );

	// {9C6217D5-DD11-4795-87C1-6CE02853C540}
	AK_ID_DECLARE GUID Mac_unsafeguid = { 0x9c6217d5, 0xdd11, 0x4795, { 0x87, 0xc1, 0x6c, 0xe0, 0x28, 0x53, 0xc5, 0x40 } };
	AK_ID_DECLARE BasePlatformID Mac = BasePlatformID::Create( Mac_unsafeguid );
	
	// {3AF9B9B6-6EF1-47E9-B5FE-E30C9E602C77}
	AK_ID_DECLARE GUID PS4_unsafeguid = { 0x3af9b9b6, 0x6ef1, 0x47e9, { 0xb5, 0xfe, 0xe3, 0xc, 0x9e, 0x60, 0x2c, 0x77 } };
	AK_ID_DECLARE BasePlatformID PS4 = BasePlatformID::Create( PS4_unsafeguid );

	// {662A5E67-9D35-48DA-B6A8-B77C7F1D84E0}
	AK_ID_DECLARE GUID PS5_unsafeguid = { 0x662a5e67, 0x9d35, 0x48da, { 0xb6, 0xa8, 0xb7, 0x7c, 0x7f, 0x1d, 0x84, 0xe0 } };
	AK_ID_DECLARE BasePlatformID PS5 = BasePlatformID::Create(PS5_unsafeguid);

	// {ECE03DB4-F948-462d-B2BB-A9173012B1F8}
	AK_ID_DECLARE GUID iOS_unsafeguid = { 0xece03db4, 0xf948, 0x462d, { 0xb2, 0xbb, 0xa9, 0x17, 0x30, 0x12, 0xb1, 0xf8 } };
	AK_ID_DECLARE BasePlatformID iOS = BasePlatformID::Create( iOS_unsafeguid );

	// {a2d401de-b8b6-4feb-8142-137c34d507CA}
	AK_ID_DECLARE GUID Android_unsafeguid = { 0xa2d401de, 0xb8b6, 0x4feb, { 0x81, 0x42, 0x13, 0x7c, 0x34, 0xd5, 0x07, 0xCA } };
	AK_ID_DECLARE BasePlatformID Android = BasePlatformID::Create( Android_unsafeguid );

	// {B131584B-9961-4bb5-9C58-A3E9ABFFBBF6}
	AK_ID_DECLARE GUID XboxOne_unsafeguid = { 0xb131584b, 0x9961, 0x4bb5, { 0x9c, 0x58, 0xa3, 0xe9, 0xab, 0xff, 0xbb, 0xf6 } };
	AK_ID_DECLARE BasePlatformID XboxOne = BasePlatformID::Create( XboxOne_unsafeguid );

	// {BD0BDF13-3125-454f-8BFD-319537169F81}
	AK_ID_DECLARE GUID Linux_unsafeguid = { 0xbd0bdf13, 0x3125, 0x454f, { 0x8b, 0xfd, 0x31, 0x95, 0x37, 0x16, 0x9f, 0x81 } };
	AK_ID_DECLARE BasePlatformID Linux = BasePlatformID::Create( Linux_unsafeguid );

	// {EBDCC377-12EE-4FFE-A545-8588F83CAC94}
	AK_ID_DECLARE GUID Stadia_unsafeguid = { 0xebdcc377, 0x12ee, 0x4ffe, { 0xa5, 0x45, 0x85, 0x88, 0xf8, 0x3c, 0xac, 0x94 } };
	AK_ID_DECLARE BasePlatformID Stadia = BasePlatformID::Create(Stadia_unsafeguid);

	// {874F26D2-416D-4698-BFB6-3427CAFCFF9C}
	AK_ID_DECLARE GUID NintendoNX_unsafeguid = { 0x874f26d2, 0x416d, 0x4698, { 0xbf, 0xb6, 0x34, 0x27, 0xca, 0xfc, 0xff, 0x9c } };
	AK_ID_DECLARE BasePlatformID NintendoNX = BasePlatformID::Create(NintendoNX_unsafeguid);

	// {639AD233-23F2-4c0f-9127-79F44C15E1DA}
	AK_ID_DECLARE GUID Emscripten_unsafeguid = { 0x639ad233, 0x23f2, 0x4c0f, { 0x91, 0x27, 0x79, 0xf4, 0x4c, 0x15, 0xe1, 0xdA } };
	AK_ID_DECLARE BasePlatformID Emscripten = BasePlatformID::Create(Emscripten_unsafeguid);

	//{26352fc0-7716-4f97-8daf-3665ec2bb501}
	AK_ID_DECLARE GUID XboxSeriesX_unsafeguid = { 0x26352fc0, 0x7716, 0x4f97, { 0x8d, 0xaf, 0x36, 0x65, 0xec, 0x2b, 0xb5, 0x01 } };
	AK_ID_DECLARE BasePlatformID XboxSeriesX = BasePlatformID::Create(XboxSeriesX_unsafeguid);

	/// Returns true if the given platform has Big Endian byte ordering. 
	inline bool IsPlatformBigEndian( const BasePlatformID & )
	{
		return false; // No currently supported platforms are Big Endian.
	}

	//This helper is used for platforms that are most probably on a ARM CPU (Android being possible on x86).  
	//This is currently used to switch between Vorbis encoding algorithms, for optimisation purposes.
	inline bool PlatformMaybeARM(const BasePlatformID & in_guidPlatform)
	{
		return in_guidPlatform == PlatformID::NintendoNX
			|| in_guidPlatform == PlatformID::Android
			|| in_guidPlatform == PlatformID::iOS;			
	}
}

#endif // AK_WWISE_PLATFORMID_H
