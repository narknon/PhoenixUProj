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
/// Reverb parameter estimation.

#pragma once

#include <AK/SoundEngine/Common/AkTypes.h>
#include <AK/SpatialAudio/Common/AkSpatialAudio.h>
#include <AK/SoundEngine/Common/AkVirtualAcoustics.h>

namespace AK {
namespace SpatialAudio {

/// Audiokinetic reverb estimation namespace
namespace ReverbEstimation
{
	////////////////////////////////////////////////////////////////////////
	/// @name Reverb estimation. 
	/// These functions can be used to estimate the reverb parameters of a physical environment, using its volume and surface area
	//@{

	/// This is used to estimate the line of best fit through the absorption values of an Acoustic Texture.
	/// This value is what's known as the HFDamping.
	/// return Gradient of line of best fit through y = mx + c.
	float CalculateSlope(const AkAcousticTexture& texture)
	{
		// constants for the mean and standard deviation of the acoustic texture indices 0,1,2,3
		const float meanX = 1.5f;
		const float sdX = 1.11803399;

		const int N = 4;
		float meanY = (texture.fAbsorptionLow + texture.fAbsorptionMidLow + texture.fAbsorptionMidHigh + texture.fAbsorptionHigh) / (float)N;
		float absorptions[4] = { texture.fAbsorptionLow, texture.fAbsorptionMidLow, texture.fAbsorptionMidHigh, texture.fAbsorptionHigh };
		float sdY = 0.0f;
		float meanDiffDotProd = 0.0f;
		for (int i = 0; i < N; ++i)
		{
			const float yMeanDiff = absorptions[i] - meanY;
			const float xMeanDiff = (float)i - meanX;
			meanDiffDotProd += yMeanDiff * xMeanDiff;
			sdY += yMeanDiff * yMeanDiff;
		}
		if (sdY == 0.0f)
			return 0.0f;
		sdY = sqrtf(sdY / (float)N);
		const float correlationCoeff = (1.0f / (N - 1.0f)) * (meanDiffDotProd / (sdY * sdX));
		return correlationCoeff * (sdY / sdX);
	}

	/// Calculate average absorption values using each of the textures in in_textures, weighted by their corresponding surface area.
	void GetAverageAbsorptionValues(AkAcousticTexture* in_textures, float* in_surfaceAreas, int in_numTextures, AkAcousticTexture& out_average)
	{
		float surfaceArea = 0.0f;
		float totalSurfaceArea = 0.0f;
		out_average.fAbsorptionLow = 0.0f;
		out_average.fAbsorptionMidLow = 0.0f;
		out_average.fAbsorptionMidHigh = 0.0f;
		out_average.fAbsorptionHigh = 0.0f;
		for (int textureIndex = 0; textureIndex < in_numTextures; ++textureIndex)
		{
			AkAcousticTexture& texture = in_textures[textureIndex];
			surfaceArea = in_surfaceAreas[textureIndex];
			out_average.fAbsorptionLow += texture.fAbsorptionLow * surfaceArea;
			out_average.fAbsorptionMidLow += texture.fAbsorptionMidLow * surfaceArea;
			out_average.fAbsorptionMidHigh += texture.fAbsorptionMidHigh * surfaceArea;
			out_average.fAbsorptionHigh += texture.fAbsorptionHigh * surfaceArea;
			totalSurfaceArea += surfaceArea;
		}
		AKASSERT(totalSurfaceArea > 0.0f);
		out_average.fAbsorptionLow = out_average.fAbsorptionLow / totalSurfaceArea;
		out_average.fAbsorptionMidLow = out_average.fAbsorptionMidLow / totalSurfaceArea;
		out_average.fAbsorptionMidHigh = out_average.fAbsorptionMidHigh / totalSurfaceArea;
		out_average.fAbsorptionHigh = out_average.fAbsorptionHigh / totalSurfaceArea;
	}

	/// Estimate the time taken (in seconds) for the sound reverberation in a physical environment to decay by 60 dB.
	/// This is estimated using the Sabine equation. The T60 decay time can be used to drive the decay parameter of a reverb effect.
	AK_EXTERNAPIFUNC(AKRESULT, EstimateT60Decay)(
		AkReal32 in_volumeCubicMeters,				///< The volume (in cubic meters) of the physical environment. 0 volume or negative volume will give a decay estimate of 0.
		AkReal32 in_surfaceAreaSquaredMeters,		///< The surface area (in squared meters) of the physical environment. Must be >= AK_SA_MIN_ENVIRONMENT_SURFACE_AREA
		AkReal32 in_environmentAverageAbsorption,	///< The average absorption amount of the surfaces in the environment. Must be between AK_SA_MIN_ENVIRONMENT_ABSORPTION and 1.
		AkReal32& out_decayEstimate					///< Returns the time taken (in seconds) for the reverberation to decay bu 60 dB.
		)
	{
		if (in_volumeCubicMeters <= 0.0f)
		{
			out_decayEstimate = 0.0f;
			return AKRESULT::AK_Success;
		}
		if (in_surfaceAreaSquaredMeters < AK_SA_MIN_ENVIRONMENT_SURFACE_AREA)
		{
			AKASSERT(false && "AK::SpatialAudio::ReverbEstimation::EstimateT60Decay: Invalid surface area. in_SurfaceAreaSquaredMeters Must be >= AK_SA_MIN_ENVIRONMENT_SURFACE_AREA");
			return AKRESULT::AK_Fail;
		}
		if (in_environmentAverageAbsorption < AK_SA_MIN_ENVIRONMENT_ABSORPTION || in_environmentAverageAbsorption > 1.0f)
		{
			AKASSERT(false && "AK::SpatialAudio::ReverbEstimation::EstimateT60Decay: Invalid absorption value. in_EnvironmentAverageAbsorption Must be between AK_SA_MIN_ENVIRONMENT_ABSORPTION and 1");
			return AKRESULT::AK_Fail;
		}
		// The Sabine equation.
		out_decayEstimate = (0.161f * in_volumeCubicMeters) / (in_surfaceAreaSquaredMeters * in_environmentAverageAbsorption);
		return AKRESULT::AK_Success;
	}

	/// Estimate the time taken (in milliseconds) for the first reflection to reach the listener.
	/// This assumes the emitter and listener are both positioned in the centre of the environment.
	AK_EXTERNAPIFUNC(AKRESULT, EstimateTimeToFirstReflection)(
		AkVector in_environmentExtentMeters,	///< Defines the dimensions of the environment (in meters) relative to the center; all components must be positive numbers.
		AkReal32& out_timeToFirstReflectionMs,	///< Returns the time taken (in milliseconds) for the first reflection to reach the listener.
		AkReal32 in_speedOfSound = 343.0f		///< Defaults to 343.0 - the speed of sound in dry air. Must be > 0.
		)
	{
		if (in_speedOfSound <= 0.0f)
		{
			AKASSERT(false && "AK::SpatialAudio::ReverbEstimation::EstimateTimeToFirstReflection: Invalid speed of sound. in_speedOfSound must be greater than 0.");
			return AKRESULT::AK_Fail;
		}
		if (in_environmentExtentMeters.X < 0.0f || in_environmentExtentMeters.Y < 0.0f || in_environmentExtentMeters.Z < 0.0f)
		{
			AKASSERT(false && "AK::SpatialAudio::ReverbEstimation::EstimateTimeToFirstReflection: Invalid extent. All components must be positive numbers.");
			return AKRESULT::AK_Fail;
		}
		const float minDimension = AkMin(AkMin(in_environmentExtentMeters.X, in_environmentExtentMeters.Y), in_environmentExtentMeters.Z);
		out_timeToFirstReflectionMs = minDimension / in_speedOfSound;
		return AKRESULT::AK_Success;
	}

	/// Estimate the high frequency damping from a collection of AkAcousticTextures and corresponding surface areas. 
	/// The high frequency damping is a measure of how much high frequencies are dampened compared to low frequencies. > 0 indicates more high frequency damping than low frequency damping. < 0 indicates more low frequency damping than high frequency damping. 0 indicates uniform damping.
	/// The average absorption values are calculated using each of the textures in the collection, weighted by their corresponding surface area.
	/// The HFDamping is then calculated as the line-of-best-fit through the average absorption values.
	AK_EXTERNAPIFUNC(AKRESULT, EstimateHFDamping)(
		AkAcousticTexture* in_textures,	///< A collection of AkAcousticTexture structs from which to calculate the average high frequency damping.
		float* in_surfaceAreas,			///< Surface area values for each of the textures in in_textures.
		int in_numTextures,				///< The number of textures in in_textures (and the number of surface area values in in_surfaceAreas).
		AkReal32& out_hfDamping			///< Returns the high frequency damping value. > 0 indicates more high frequency damping than low frequency damping. < 0 indicates more low frequency damping than high frequency damping. 0 indicates uniform damping.
		)
	{
		if (in_textures == nullptr || in_surfaceAreas == nullptr || in_numTextures == 0)
		{
			out_hfDamping = 0.0f;
			return AK_Success;
		}
		AkAcousticTexture averageAbsorptionValues;
		GetAverageAbsorptionValues(in_textures, in_surfaceAreas, in_numTextures, averageAbsorptionValues);
		out_hfDamping = CalculateSlope(averageAbsorptionValues);
		return AK_Success;
	}

	//@}
}
}
}