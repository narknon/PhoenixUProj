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

// AkCommonDefs.h

/// \file 
/// AudioLib common defines, enums, and structs.


#ifndef _AK_COMMON_DEFS_H_
#define _AK_COMMON_DEFS_H_

#include <AK/SoundEngine/Common/AkSpeakerConfig.h>
#include <AK/SoundEngine/Common/AkSpeakerVolumes.h>
#include <AK/SoundEngine/Common/IAkPluginMemAlloc.h>
#include <AK/Tools/Common/AkArray.h>
#include <AK/Tools/Common/AkString.h>

//-----------------------------------------------------------------------------
// AUDIO DATA FORMAT
//-----------------------------------------------------------------------------

// Audio data format.
// ------------------------------------------------

const AkDataTypeID		AK_INT				= 0;		///< Integer data type (uchar, short, and so on)
const AkDataTypeID		AK_FLOAT			= 1;		///< Float data type

const AkDataInterleaveID AK_INTERLEAVED		= 0;		///< Interleaved data
const AkDataInterleaveID AK_NONINTERLEAVED	= 1;		///< Non-interleaved data

// Native format currently the same on all supported platforms, may become platform specific in the future
const AkUInt32 AK_LE_NATIVE_BITSPERSAMPLE  = 32;					///< Native number of bits per sample.
const AkUInt32 AK_LE_NATIVE_SAMPLETYPE = AK_FLOAT;					///< Native data type.
const AkUInt32 AK_LE_NATIVE_INTERLEAVE = AK_NONINTERLEAVED;			///< Native interleaved setting.

/// Defines the parameters of an audio buffer format.
struct AkAudioFormat
{
	AkUInt32	uSampleRate;		///< Number of samples per second

	AkChannelConfig channelConfig;	///< Channel configuration.

	AkUInt32	uBitsPerSample	:6; ///< Number of bits per sample.
	AkUInt32	uBlockAlign		:10;///< Number of bytes per sample frame. (For example a 5.1 PCM 16bit should have a uBlockAlign equal to 6(5.1 channels)*2(16 bits per sample) = 12.
	AkUInt32	uTypeID			:2; ///< Data type ID (AkDataTypeID). 
	AkUInt32	uInterleaveID	:1; ///< Interleave ID (AkDataInterleaveID). 
	
	/// Get the number of channels.
	/// \return The number of channels
	AkForceInline AkUInt32 GetNumChannels() const
	{
		return channelConfig.uNumChannels;
	}

	/// Query if LFE channel is present.
	/// \return True when LFE channel is present
	AkForceInline bool HasLFE() const
	{ 
		return channelConfig.HasLFE(); 
	}

	/// Query if center channel is present.
	/// Note that mono configurations have one channel which is arbitrary set to AK_SPEAKER_FRONT_CENTER,
	/// so HasCenter() returns true for mono signals.
	/// \return True when center channel is present and configuration has more than 2 channels.
	AkForceInline bool HasCenter() const
	{ 
		return channelConfig.HasCenter(); 
	}

	/// Get the number of bits per sample.
	/// \return The number of bits per sample
	AkForceInline AkUInt32 GetBitsPerSample()	const						
	{ 
		return uBitsPerSample;
	}

	/// Get the block alignment.
	/// \return The block alignment
	AkForceInline AkUInt32 GetBlockAlign() const
	{
		return uBlockAlign;
	}

	/// Get the data sample format (Float or Integer).
	/// \return The data sample format
	AkForceInline AkUInt32 GetTypeID() const
	{
		return uTypeID;
	}

	/// Get the interleaved type.
	/// \return The interleaved type
	AkForceInline AkUInt32 GetInterleaveID() const
	{
		return uInterleaveID;
	}

	/// Set all parameters of the audio format structure.
	/// Channels are specified by channel mask (standard configs).
	void SetAll(
		AkUInt32    in_uSampleRate,		///< Number of samples per second
		AkChannelConfig in_channelConfig,	///< Channel configuration
		AkUInt32    in_uBitsPerSample,	///< Number of bits per sample
		AkUInt32    in_uBlockAlign,		///< Block alignment
		AkUInt32    in_uTypeID,			///< Data sample format (Float or Integer)
		AkUInt32    in_uInterleaveID	///< Interleaved type
		)
	{
		uSampleRate		= in_uSampleRate;
		channelConfig	= in_channelConfig;
		uBitsPerSample	= in_uBitsPerSample;
		uBlockAlign		= in_uBlockAlign;
		uTypeID			= in_uTypeID;
		uInterleaveID	= in_uInterleaveID;
	}

	AkForceInline bool operator==(const AkAudioFormat & in_other) const
	{
		return uSampleRate == in_other.uSampleRate 
			&& channelConfig == in_other.channelConfig
			&& uBitsPerSample == in_other.uBitsPerSample
			&& uBlockAlign == in_other.uBlockAlign
			&& uTypeID == in_other.uTypeID
			&& uInterleaveID == in_other.uInterleaveID;
	}

	AkForceInline bool operator!=(const AkAudioFormat & in_other) const
	{
		return uSampleRate != in_other.uSampleRate
			|| channelConfig != in_other.channelConfig
			|| uBitsPerSample != in_other.uBitsPerSample
			|| uBlockAlign != in_other.uBlockAlign
			|| uTypeID != in_other.uTypeID
			|| uInterleaveID != in_other.uInterleaveID;
	}
};

typedef AkUInt8(*AkChannelMappingFunc)(const AkChannelConfig &config, AkUInt8 idx);

enum AkSourceChannelOrdering
{
	SourceChannelOrdering_Standard = 0, // SMPTE L-R-C-LFE-RL-RR-RC-SL-SR-HL-HR-HC-HRL-HRR-HRC-T
	// or ACN ordering + SN3D norm

	SourceChannelOrdering_Film,	// L/C/R/Ls/Rs/Lfe
	SourceChannelOrdering_FuMa
};

#define AK_MAKE_CHANNELCONFIGOVERRIDE(_config,_order)	((AkInt64)_config.Serialize()|((AkInt64)_order<<32))
#define AK_GET_CHANNELCONFIGOVERRIDE_CONFIG(_over)		(_over&UINT_MAX)
#define AK_GET_CHANNELCONFIGOVERRIDE_ORDERING(_over)	((AkSourceChannelOrdering)(_over>>32))

// Build a 32 bit class identifier based on the Plug-in type,
// CompanyID and PluginID.
//
// Parameters:
//   - in_pluginType: A value from enum AkPluginType (4 bits)
//   - in_companyID: CompanyID as defined in the Plug-in's XML file (12 bits)
//			* 0-63: Reserved for Audiokinetic
//			* 64-255: Reserved for clients' in-house Plug-ins
//			* 256-4095: Assigned by Audiokinetic to third-party plug-in developers
//   - in_pluginID: PluginID as defined in the Plug-in's XML file (16 bits)
//			* 0-32767: Set freely by the Plug-in developer
#define AKMAKECLASSID( in_pluginType, in_companyID, in_pluginID ) \
	( (in_pluginType) + ( (in_companyID) << 4 ) + ( (in_pluginID) << ( 4 + 12 ) ) )

#define AKGETPLUGINTYPEFROMCLASSID( in_classID ) ( (in_classID) & AkPluginTypeMask )
#define AKGETCOMPANYIDFROMCLASSID( in_classID ) ( ( (in_classID) & 0x0000FFF0 ) >> 4 )
#define AKGETPLUGINIDFROMCLASSID( in_classID ) ( ( (in_classID) & 0xFFFF0000 ) >> ( 4 + 12 ) )

#define CODECID_FROM_PLUGINID AKGETPLUGINIDFROMCLASSID


namespace AK
{
	/// Interface to retrieve metering information about a buffer.
	class IAkMetering
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkMetering(){}

	public:

		/// Get peak of each channel in this frame.
		/// Depending on when this function is called, you may get metering data computed in the previous frame only. In order to force recomputing of
		/// meter values, pass in_bForceCompute=true.
		/// \return Vector of linear peak levels, corresponding to each channel. NULL if AK_EnableBusMeter_Peak is not set (see IAkMixerPluginContext::SetMeteringFlags() or AK::SoundEngine::RegisterBusMeteringCallback()).
		virtual AK::SpeakerVolumes::ConstVectorPtr GetPeak() = 0;

		/// Get true peak of each channel (as defined by ITU-R BS.1770) in this frame.
		/// Depending on when this function is called, you may get metering data computed in the previous frame only. 
		/// \return Vector of linear true peak levels, corresponding to each channel. NULL if AK_EnableBusMeter_TruePeak is not set (see IAkMixerPluginContext::SetMeteringFlags() or AK::SoundEngine::RegisterBusMeteringCallback()).
		virtual AK::SpeakerVolumes::ConstVectorPtr GetTruePeak() = 0;

		/// Get the RMS value of each channel in this frame.
		/// Depending on when this function is called, you may get metering data computed in the previous frame only. In order to force recomputing of
		/// meter values, pass in_bForceCompute=true.
		/// \return Vector of linear rms levels, corresponding to each channel. NULL if AK_EnableBusMeter_RMS is not set (see IAkMixerPluginContext::SetMeteringFlags() or AK::SoundEngine::RegisterBusMeteringCallback()).
		virtual AK::SpeakerVolumes::ConstVectorPtr GetRMS() = 0;
		
		/// Get the mean k-weighted power value in this frame, used to compute loudness (as defined by ITU-R BS.1770).
		/// Depending on when this function is called, you may get metering data computed in the previous frame only.
		/// \return Total linear k-weighted power of all channels. 0 if AK_EnableBusMeter_KPower is not set (see IAkMixerPluginContext::SetMeteringFlags() or AK::SoundEngine::RegisterBusMeteringCallback()).
		virtual AkReal32 GetKWeightedPower() = 0;
	};
}

// 3D Audio Object.
// ------------------------------------------------

/// Default listener transform.
#define AK_DEFAULT_LISTENER_POSITION_X (0.0f)				// at coordinate system's origin
#define AK_DEFAULT_LISTENER_POSITION_Y (0.0f)
#define AK_DEFAULT_LISTENER_POSITION_Z (0.0f)
#define AK_DEFAULT_LISTENER_FRONT_X    (0.0f)				// looking toward Z,
#define AK_DEFAULT_LISTENER_FRONT_Y    (0.0f)
#define AK_DEFAULT_LISTENER_FRONT_Z    (1.0f)
#define AK_DEFAULT_TOP_X               (0.0f)				// top towards Y
#define AK_DEFAULT_TOP_Y               (1.0f)
#define AK_DEFAULT_TOP_Z               (0.0f)


/// 3D data needed for 3D spatialization. 
/// Undergoes transformations based on emitter-listener placement.
struct Ak3dData
{
	Ak3dData()
		: spread(1.f)
		, focus(1.f)
		, uEmitterChannelMask(0xffff)
	{
		xform.Set(AK_DEFAULT_LISTENER_POSITION_X, AK_DEFAULT_LISTENER_POSITION_Y, AK_DEFAULT_LISTENER_POSITION_Z, AK_DEFAULT_LISTENER_FRONT_X, AK_DEFAULT_LISTENER_FRONT_Y, AK_DEFAULT_LISTENER_FRONT_Z, AK_DEFAULT_TOP_X, AK_DEFAULT_TOP_Y, AK_DEFAULT_TOP_Z);
	}

	AkTransform xform;								///< Object position / orientation.
	AkReal32 spread;								///< Spread [0,1]
	AkReal32 focus;									///< Focus [0,1]
	AkChannelMask uEmitterChannelMask;				///< Emitter channel mask. With 3D spatialization, zeroed channels should be dropped.
};

/// Positioning data inherited from sound structures and mix busses.
struct AkBehavioralPositioningData
{
	AkBehavioralPositioningData()
		: center(1.f)
		, panLR(0.f)
		, panBF(0.f)
		, panDU(0.f)
		, panSpatMix(1.f)
		, spatMode(AK_SpatializationMode_None)
		, panType(AK_DirectSpeakerAssignment)
		, enableHeightSpread(true)
	{}

	AkReal32 center;								///< Center percentage [0,1]
	AkReal32 panLR;									///< Pan left-right [-1,1]
	AkReal32 panBF;									///< Pan back-front [-1,1]
	AkReal32 panDU;									///< Pan down-up [-1,1]
	AkReal32 panSpatMix;							///< Panning vs 3D spatialization mix ([0,1], 1 being 100% spatialized).
	Ak3DSpatializationMode spatMode;				///< 3D spatialization mode.
	AkSpeakerPanningType panType;					///< Speaker panning type.
	bool enableHeightSpread;						///< When true, audio objects 3D spatialized onto a planar channel configuration will be given a minimum spread value based on their elevation angle, equal to sin(elevation)**2.
};

/// Positioning data of 3D audio objects.
struct AkPositioningData
{
	Ak3dData threeD;								///< 3D data used for 3D spatialization.
	AkBehavioralPositioningData behavioral;			///< Positioning data inherited from sound structures and mix busses.
};

// Forward defines
namespace AK
{
	class IAkPluginParam;
}

/// An audio object refers to an audio signal with some attached metadata going through the sound engine pipeline.
/// The AkAudioObject struct encapsulates the metadata part. The signal itself is contained in a separate AkAudioBuffer instance.
struct AkAudioObject
{
	/// Constructor
	AkAudioObject()
		:key(AK_INVALID_AUDIO_OBJECT_ID)
		,cumulativeGain(1.f, 1.f)
		,instigatorID(AK_INVALID_PIPELINE_ID)
	{}

	/// Destructor
	~AkAudioObject()
	{
		arCustomMetadata.Term();
		objectName.Term();
	}

	AkAudioObjectID key;			///< Unique ID, local to a given bus.

	AkPositioningData positioning;	///< Positioning data for deferred 3D rendering.
	AkRamp cumulativeGain;			///< Cumulative ramping gain to apply when mixing down to speaker bed or final endpoint

	/// Custom object metadata.
	struct CustomMetadata
	{
		AkPluginID pluginID;		///< Full plugin ID (including company ID and plugin type. See AKMAKECLASSID macro.
		AK::IAkPluginParam* pParam;	///< Custom, pluggable medata.
		AkUniqueID contextID;		///< (Profiling) ID of the sound or bus from which the custom metadata was fetched.
	};
	typedef AkArray<CustomMetadata, const CustomMetadata&, AkPluginArrayAllocator> ArrayCustomMetadata; ///< Array type for carrying custom metadata.
	ArrayCustomMetadata arCustomMetadata;	///< Array of custom metadata, gathered from visited objects.

	AkPipelineID instigatorID;		///< Profiling ID of the node from which the object stems (typically the voice, instance of an actor-mixer).

	typedef AkString<AkPluginArrayAllocator, char> String;	///< String type for use in 3D audio objects.
	String objectName;				///< Name string of the object, to appear in the object profiler. This is normally used by out-of-place object processors for naming their output objects. Built-in sound engine structures don't use it.

	/// Copy object metadata (everything but the key) from another object.
	void CopyContents(
		const AkAudioObject& in_src	///< Object from which metadata is copied.
	)
	{
		positioning = in_src.positioning;
		cumulativeGain = in_src.cumulativeGain;
		arCustomMetadata.Copy(in_src.arCustomMetadata);
		instigatorID = in_src.instigatorID;
		objectName = in_src.objectName;	// AkString performs a shallow copy when it can, like here.
	}

	void SetCustomMetadata(CustomMetadata* in_aCustomMetadata, AkUInt32 in_uLength)
	{
		if (arCustomMetadata.Resize(in_uLength))
		{
			for (int i = 0; i < (int)in_uLength; ++i)
			{
				arCustomMetadata[i] = in_aCustomMetadata[i];
			}
		}
	}

	/// Transfer function for transfer move policies.
	void Transfer(
		AkAudioObject& in_from	///< Object from which data is transferred.
	)
	{
		key = in_from.key;
		positioning = in_from.positioning;
		cumulativeGain = in_from.cumulativeGain;
		arCustomMetadata.Transfer(in_from.arCustomMetadata);
		instigatorID = in_from.instigatorID;
		objectName.Transfer(in_from.objectName);
	}

	/// Object processors may give an explicit name to objects. 
	/// \return AK_Success if the string was allocated successfully, AK_InsufficientMemory otherwise.
	AKRESULT SetName(
		AK::IAkPluginMemAlloc* in_pAllocator,	///< Memory allocator.
		const char* in_szName					///< Null-terminated string to allocate and store on this object.
	)
	{
		objectName.Init(in_pAllocator);
		objectName = in_szName;
		return objectName.AllocCopy();
	}

	/// Reset object state in preparation for next frame.
	void ResetState()
	{
		arCustomMetadata.Term(); // Reset custom metadata in preparation for next frame.
		objectName.ClearReference(); // Clear reference to string in preparation for next frame.
	}
};

/// Structure containing information about system-level support for 3D audio.
/// "3D Audio" refers to a system's ability to position sound sources in a virtual 3D space, pan them accordingly on a range of physical speakers, and produce a binaural mix where appropriate.
/// We prefer "3D Audio" to "Spatial" to avoid ambiguity with spatial audio, which typically involves sound propagation and environment effects.
struct Ak3DAudioSinkCapabilities
{
	AkChannelConfig channelConfig;                 /// Channel configuration of the main mix.
	AkUInt32        uMaxSystemAudioObjects;        /// Maximum number of System Audio Objects that can be active concurrently. A value of zero indicates the system does not support this feature.
	AkUInt32        uAvailableSystemAudioObjects;  /// How many System Audio Objects can currently be sent to the sink. This value can change at runtime depending on what is playing. Can never be higher than uMaxSystemAudioObjects.
	bool            bPassthrough;                  /// Separate  pass-through mix is supported.
	bool            bMultiChannelObjects;          /// Can handle multi-channel objects
};

/// Enum of the possible object destinations when reaching a 3D audio-capable sink
enum class AkAudioObjectDestination
{
	eDefault = 0,            // The destination will be chosen based on the audio object's metadata and channel configuration
	eMainMix = 1,            // The audio object will be mixed to the sink's main mix
	ePassthrough = 2,        // The audio object will be mixed to the sink's passthrough mix
	eSystemAudioObject = 3   // The audio object will not be mixed; it will be sent separately to the system's 3D audio endpoint
};

// Audio buffer.
// ------------------------------------------------

/// Native sample type. 
/// \remarks Sample values produced by insert effects must use this type.
/// \remarks Source plug-ins can produce samples of other types (specified through 
/// according fields of AkAudioFormat, at initial handshaking), but these will be 
/// format converted internally into the native format.
/// \sa
/// - \ref iaksourceeffect_init
/// - \ref iakmonadiceffect_init
typedef AkReal32 AkSampleType;	///< Audio sample data type (32 bit floating point)

/// Audio buffer structure including the address of an audio buffer, the number of valid frames inside, 
/// and the maximum number of frames the audio buffer can hold.
/// \sa
/// - \ref fx_audiobuffer_struct
class AkAudioBuffer
{
public:

	/// Constructor.
	AkAudioBuffer() 
	{ 
		Clear(); 
	}

	/// Clear data pointer.
	AkForceInline void ClearData()
	{
		pData = NULL;
		uValidFrames = 0;
	}

	/// Clear members.
	AkForceInline void Clear()
	{
		ClearData();
		uMaxFrames          = 0;
		eState              = AK_DataNeeded;
	}
	
	/// \name Channel queries.
	//@{
	/// Get the number of channels.
	AkForceInline AkUInt32 NumChannels() const
	{
		return channelConfig.uNumChannels;
	}

	/// Returns true if there is an LFE channel present.
	AkForceInline bool HasLFE() const
	{ 
		return channelConfig.HasLFE(); 
	}

	AkForceInline AkChannelConfig GetChannelConfig() const { return channelConfig; }

	//@}

	/// \name Interleaved interface
	//@{
	/// Get address of data: to be used with interleaved buffers only.
	/// \remarks Only source plugins can output interleaved data. This is determined at 
	/// initial handshaking.
	/// \sa 
	/// - \ref fx_audiobuffer_struct
	AkForceInline void * GetInterleavedData()
	{ 
		return pData; 
	}

	/// Attach interleaved data. Allocation is performed outside.
	inline void AttachInterleavedData( void * in_pData, AkUInt16 in_uMaxFrames, AkUInt16 in_uValidFrames )
	{ 
		pData = in_pData; 
		uMaxFrames = in_uMaxFrames; 
		uValidFrames = in_uValidFrames; 
		AKASSERT(channelConfig.IsValid());
	}
	/// Attach interleaved data with a new channel config. Allocation is performed outside.
	inline void AttachInterleavedData( void * in_pData, AkUInt16 in_uMaxFrames, AkUInt16 in_uValidFrames, AkChannelConfig in_channelConfig )
	{ 
		pData = in_pData; 
		uMaxFrames = in_uMaxFrames; 
		uValidFrames = in_uValidFrames; 
		channelConfig = in_channelConfig; 
	}
	//@}

	/// \name Deinterleaved interface
	//@{

	/// Check if buffer has samples attached to it.
	AkForceInline bool HasData() const
	{
		return ( NULL != pData ); 
	}

	/// Convert a channel, identified by a single channel bit, to a buffer index used in GetChannel() below, for a given channel config.
	/// Standard indexing follows channel bit order (see AkSpeakerConfig.h). Pipeline/buffer indexing is the same but the LFE is moved to the end.
	static inline AkUInt32 StandardToPipelineIndex( 
		AkChannelConfig in_channelConfig,		///< Channel configuration.
		AkUInt32		in_uChannelIdx			///< Channel index in standard ordering to be converted to pipeline ordering.
		)
	{
		if ( in_channelConfig.HasLFE() )
		{
			AKASSERT( in_channelConfig.eConfigType == AK_ChannelConfigType_Standard );	// in_channelConfig.HasLFE() would not have returned true otherwise.
			AKASSERT( AK::GetNumNonZeroBits( in_channelConfig.uChannelMask ) );
			AkUInt32 uIdxLFE = AK::GetNumNonZeroBits( ( AK_SPEAKER_LOW_FREQUENCY - 1 ) & in_channelConfig.uChannelMask );
			if ( in_uChannelIdx == uIdxLFE )
				return in_channelConfig.uNumChannels - 1;
			else if ( in_uChannelIdx > uIdxLFE )
				return in_uChannelIdx - 1;
		}

		return in_uChannelIdx;
	}

	/// Get the buffer of the ith channel. 
	/// Access to channel data is most optimal through this method. Use whenever the
	/// speaker configuration is known, or when an operation must be made independently
	/// for each channel.
	/// \remarks When using a standard configuration, use ChannelMaskToBufferIndex() to convert channel bits to buffer indices.
	/// \return Address of the buffer of the ith channel.
	/// \sa
	/// - \ref fx_audiobuffer_struct
	/// - \ref fx_audiobuffer_struct_channels
	inline AkSampleType * GetChannel(
		AkUInt32 in_uIndex		///< Channel index [0,NumChannels()-1]
		)
	{
		AKASSERT( in_uIndex < NumChannels() );
		return (AkSampleType*)((AkUInt8*)(pData) + ( in_uIndex * sizeof(AkSampleType) * MaxFrames() ));
	}

	/// Get the buffer of the LFE.
	/// \return Address of the buffer of the LFE. Null if there is no LFE channel.
	/// \sa
	/// - \ref fx_audiobuffer_struct_channels
	inline AkSampleType * GetLFE()
	{
		if ( channelConfig.uChannelMask & AK_SPEAKER_LOW_FREQUENCY )
			return GetChannel( NumChannels()-1 );
		
		return (AkSampleType*)0;
	}

	/// Can be used to transform an incomplete into a complete buffer with valid data.
	/// The invalid frames are made valid (zeroed out) for all channels and the validFrames count will be made equal to uMaxFrames.
	void ZeroPadToMaxFrames()
	{
		AKASSERT(pData != nullptr || MaxFrames() == 0);
		// The following members MUST be copied locally due to multi-core calls to this function.
		const AkUInt32 uNumChannels = NumChannels();
		const AkUInt32 uNumCurrentFrames = AkMin(uValidFrames, MaxFrames());
		const AkUInt32 uNumZeroFrames = MaxFrames() - uNumCurrentFrames;
		if ( uNumZeroFrames )
		{
			AKASSERT(pData != nullptr);
			for ( AkUInt32 i = 0; i < uNumChannels; ++i )
			{
				AKPLATFORM::AkMemSet( GetChannel(i) + uNumCurrentFrames, 0, uNumZeroFrames * sizeof(AkSampleType) );
			}
			uValidFrames = MaxFrames();
		}
	}

	/// Attach deinterleaved data where channels are contiguous in memory. Allocation is performed outside.
	AkForceInline void AttachContiguousDeinterleavedData( void * in_pData, AkUInt16 in_uMaxFrames, AkUInt16 in_uValidFrames, AkChannelConfig in_channelConfig )
	{ 
		AttachInterleavedData( in_pData, in_uMaxFrames, in_uValidFrames, in_channelConfig );
	}
	/// Detach deinterleaved data where channels are contiguous in memory. The address of the buffer is returned and fields are cleared.
	AkForceInline void * DetachContiguousDeinterleavedData()
	{
		uMaxFrames = 0; 
		uValidFrames = 0; 
		channelConfig.Clear();
		void * pDataOld = pData;
		pData = NULL;
		return pDataOld;
	}

	bool CheckValidSamples();	

	//@}

	void RelocateMedia( AkUInt8* in_pNewMedia,  AkUInt8* in_pOldMedia )
	{
		AkUIntPtr uMemoryOffset = (AkUIntPtr)in_pNewMedia - (AkUIntPtr)in_pOldMedia;
		pData = (void*) (((AkUIntPtr)pData) + uMemoryOffset);
	}

	/// Access to the number of sample frames the buffer can hold.
	/// \return Number of sample frames the buffer can hold.
	AkForceInline AkUInt16 MaxFrames() const { return uMaxFrames; }

protected:
	void *			pData;				///< Start of the audio buffer.
	AkChannelConfig	channelConfig;		///< Channel config.

public:	
	AKRESULT		eState;				///< Execution status

protected:	
	AkUInt16		uMaxFrames;			///< Number of sample frames the buffer can hold. Access through AkAudioBuffer::MaxFrames().

public:
	AkUInt16        uValidFrames;       ///< Number of valid sample frames in the audio buffer
};

/// A collection of audio objects. Encapsulates the audio data and metadata of each audio object in separate arrays.
struct AkAudioObjects
{
	AkAudioObjects(AkUInt32 in_uNumObjects = 0, AkAudioBuffer** in_ppObjectBuffers = nullptr, AkAudioObject** in_ppObjects = nullptr)
		: uNumObjects(in_uNumObjects)
		, ppObjectBuffers(in_ppObjectBuffers)
		, ppObjects(in_ppObjects)
	{}

	AkUInt32 uNumObjects;				///< Number of audio objects.
	AkAudioBuffer** ppObjectBuffers;	///< Array of pointers to audio object buffers.
	AkAudioObject** ppObjects;		///< Array of pointers to audio objects.
};

#endif // _AK_COMMON_DEFS_H_
